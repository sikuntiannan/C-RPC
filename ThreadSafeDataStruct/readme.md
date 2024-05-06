### 线程安全的数据结构
- 红黑树（map，set）
- 数组（array、vector）
- 链表（list）

### 红黑树
线程安全的红黑树保证什么？
    可重入成员函数。
问题：
- 析构时成员函数调用安全。
    - 析构等待成员函数调用结束，拒绝之后的成员函数调用。
- 置空时（clear），遍历（迭代器持有），插入，查找等操作的语义/执行正确性
  - 遍历：
    - 时忽然遇到迭代器失效;但实际并不是失效，因为遍历的容器它就是在那一瞬间被遍历完了，虽然之后它又有类新元素，但从顺序上来说，你先完成遍历，之后它才加入。
    - 插入：
      - 发生在清理前，被清理掉是正常的。发生在清理后，没被清理掉是正常的。
    - 查找：
      - 仅保证在查找这个动作正常执行，是否能找到取决于查找和置空的实际执行顺序，以及树中是否真有这个节点。
    - 修改：
      - 修改这个动作依旧会执行，节点是否存在并不影响修改这个动作的执行。

综上，线程安全的红黑树，更大程度是保证并发执行时的稳定性，开发人员依旧需要关心使用时可能会导致的问题，因为其他线程也有控制权，导致的混乱。

- 节点
  ``` c++
    template < typename key, typename value >
    class node
    {
        std::shared_ptr< node >   m_Left;
        std::shared_ptr< node > m_Right;
        std::weak_ptr< node > m_Parent;
        value                   m_Value;
        key                     m_Key;
    }
- 迭代器
  ``` c++
    template < typename key, typename value >
    class iterator
    {
        std::weak_ptr< node > m_NowNode;
    }
- 成员变量结构体
  ``` c++
    template < typename key, typename value >
    class node;
    template < typename key, typename value >
    struct MemberData
    {
        std::atomic_size_t m_Size;       //节点数
        node               m_Root;       //根节点
        std::atomic_size_t m_UseNumber;  //有多少线程正在访问
        std::atomic_bool   m_IsUsable;   //当前对象是否可用
    }
- 红黑树
  ``` c++
    template < typename key, typename value >
    struct MemberData
    template < typename key, typename value >
    class RedBlackTree  
    {
        std::unique_ptr< MemberData > m_Data;
    }

树结构：
m_Root.m_Left指向最左节点
m_Root.m_Right指向最右节点
m_Root.m_Parent指向树的根节点
迭代器：
影响迭代器的操作有：
插入导致树调整
    并不影响继续访问下一个或者上一个节点，但树调整这个行为是阻塞的。
置空
    当前节点消失，无效操作。
删除导致当前节点消失

迭代器存储weak_ptr<node>,可以避免节点无法释放，并发时总是可以立刻得知当前节点失效。当前迭代器无效有两种情况