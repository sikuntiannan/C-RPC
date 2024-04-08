struct node {
    node();
    node(const node &);
    ~node();
    node *m_left;
    node *m_right;
    int m_data;
};

class RedBlackTree
{
public:
    RedBlackTree();
    ~RedBlackTree();

private:
    node *m_root;
};
