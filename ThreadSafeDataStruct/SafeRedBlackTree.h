#include <atomic>
#include <memory>
#include <tuple>

template < typename key, typename value >
class RedBlackTree  //: public std::enable_shared_from_this< RedBlackTree >
{
  public:
    class node
    {
      public:
        node();
        node( const node& val );
        node( node&& val );
        node& operator=( const node& val );
        node& operator=( node&& val );
        ~node();
        auto operator<=>( const node&& ) const;

      private:
        std::shared_ptr< node > m_Left;
        std::shared_ptr< node > m_Right;
        std::weak_ptr< node >   m_Parent;
        value                   m_Value;
        key                     m_Key;
    };

    class iterator
    {
      public:
        iterator();
        iterator( const std::shared_ptr< node >&& );
        iterator( const iterator& );
        iterator( iterator&& );
        iterator& operator=( const iterator& );
        iterator& operator=( iterator&& );
        ~iterator();
        iterator                  operator++( int );
        iterator&                 operator++();
        bool                      operator==( const iterator&& ) const noexcept;
        bool                      operator!=( const iterator&& ) const noexcept;
        std::pair< key&, value& > operator*();

      private:
        std::weak_ptr< node > m_NowNode;
    };

  public:
    RedBlackTree();
    ~RedBlackTree();
    void     insert( std::pair< key, value > value );
    value&   operator[]( const key&& key );
    iterator find( const key&& key );
    iterator begin();
    iterator end();
    void     clear();
    void     eraser( const iterator& iter );
    size_t   size();

  private:
    /*
    m_root：
            左孩子永远指向最小值
            右孩子永远指向最大值
            父节点永远指向头结点
     */
    struct MemberData
    {
        std::atomic_size_t m_Size;       //节点数
        node               m_Root;       //根节点
        std::atomic_size_t m_UseNumber;  //有多少线程正在访问
        std::atomic_bool   m_IsUsable;   //当前对象是否可用
        MemberDat( /* args */ );
        MemberData( const MemberData& );
        MemberData( MemberData&& );
        MemberData& operator=( const MemberData& );
        MemberData& operator=( MemberData&& );
        ~MemberDat();
    };

    std::unique_ptr< MemberData > m_Data;
};

template < typename key, typename value >
inline RedBlackTree< key, value >::node::node()
{
    m_Left   = nullptr;
    m_Right  = nullptr;
    m_Parent = nullptr;
}

template < typename key, typename value >
inline RedBlackTree< key, value >::node::node( const node& val )
{
    m_Key    = val.m_key;
    m_Value  = val.m_Value;
    m_Left   = val.m_Left;
    m_Right  = val.m_Right;
    m_Parent = val.m_Parent;
}

template < typename key, typename value >
inline RedBlackTree< key, value >::node::node( node&& val )
{
    std::swap( m_Left, val.m_Left );
    std::swap( m_Right, val.m_Right );
    std::swap( m_Parent, val.m_Parent );
    std::swap( m_Value, val.m_Value );
    std::swap( m_key, val.m_key );
}

template < typename key, typename value >
inline RedBlackTree< key, value >::node& RedBlackTree< key, value >::node::operator=( const node& val )
{
    m_key    = val.m_key;
    m_Value  = val.m_Value;
    m_Left   = val.m_Left;
    m_Right  = val.m_Right;
    m_Parent = val.m_Parent;
    return *this;
}

template < typename key, typename value >
inline RedBlackTree< key, value >::node& RedBlackTree< key, value >::node::operator=( node&& val )
{
    std::swap( m_Left, val.m_Left );
    std::swap( m_Right, val.m_Right );
    std::swap( m_Parent, val.m_Parent );
    std::swap( m_Value, val.m_Value );
    std::swap( m_key, val.m_key );
    return *this;
}

template < typename key, typename value >
inline RedBlackTree< key, value >::node::~node()
{
}

template < typename key, typename value >
inline auto RedBlackTree< key, value >::node::operator<=>( const node&& val ) const
{
    return m_key <=> val.m_key;
}

template < typename key, typename value >
inline RedBlackTree< key, value >::RedBlackTree()
{
    m_Data = std::make_unique< MemberData >();
}

template < typename key, typename value >
inline RedBlackTree< key, value >::~RedBlackTree()
{
}

template < typename key, typename value >
inline void RedBlackTree< key, value >::insert( std::pair< key, value > value )
{
}

template < typename key, typename value >
inline value& RedBlackTree< key, value >::operator[]( const key&& key )
{
}

template < typename key, typename value >
inline RedBlackTree< key, value >::iterator RedBlackTree< key, value >::find( const key&& key )
{
    return iterator();
}

template < typename key, typename value >
inline RedBlackTree< key, value >::iterator RedBlackTree< key, value >::begin()
{
    return iterator( m_Data->m_Root.m_Left );
}

template < typename key, typename value >
inline RedBlackTree< key, value >::iterator RedBlackTree< key, value >::end()
{
    return iterator( m_Data->m_Root.m_Right );
}

template < typename key, typename value >
inline void RedBlackTree< key, value >::clear()
{
    m_Data.swap( std::make_unique< MemberData >() );
}

template < typename key, typename value >
inline void RedBlackTree< key, value >::eraser( const iterator& iter )
{
}

template < typename key, typename value >
inline size_t RedBlackTree< key, value >::size()
{
    return m_data->GetSize();
}

template < typename key, typename value >
inline RedBlackTree< key, value >::iterator::iterator()
{
}

template < typename key, typename value >
inline RedBlackTree< key, value >::iterator::iterator( const iterator& )
{
}

template < typename key, typename value >
inline RedBlackTree< key, value >::iterator::iterator( iterator&& )
{
}

template < typename key, typename value >
inline RedBlackTree< key, value >::iterator& RedBlackTree< key, value >::iterator::operator=( const iterator& )
{
}

template < typename key, typename value >
inline RedBlackTree< key, value >::iterator& RedBlackTree< key, value >::iterator::operator=( iterator&& )
{
}

template < typename key, typename value >
inline RedBlackTree< key, value >::iterator::~iterator()
{
}

template < typename key, typename value >
inline RedBlackTree< key, value >::iterator RedBlackTree< key, value >::iterator::operator++( int )
{
    iterator result( *this );
    ++( *this );
    return result;
}

template < typename key, typename value >
inline RedBlackTree< key, value >::iterator& RedBlackTree< key, value >::iterator::operator++()
{
}

template < typename key, typename value >
inline bool RedBlackTree< key, value >::iterator::operator==( const iterator&& val ) const noexcept
{
    return m_NowNode == val.m_NowNode;
}

template < typename key, typename value >
inline bool RedBlackTree< key, value >::iterator::operator!=( const iterator&& val ) const noexcept
{
    return m_NowNode != val.m_NowNode;
}

template < typename key, typename value >
inline std::pair< key&, value& > RedBlackTree< key, value >::iterator::operator*()
{
    return std::pair< key&, value& >( m_NowNode->m_key, m_NowNode->m_Value );
}