#include <atomic>
#include <memory>
#include <tuple>

template < typename key, typename value >
class RedBlackTree
{
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
        std::shared_ptr< node > m_left;
        std::shared_ptr< node > m_right;
        std::shared_ptr< node > m_parent;
        value                   m_value;
        key                     m_key;
    };

    class iterator
    {
      public:
        iterator();
        iterator( const iterator& );
        iterator( iterator&& );
        iterator& operator=( const iterator& );
        iterator& operator=( iterator&& );
        ~iterator();
        iterator&                 operator++( int );
        iterator&                 operator++();
        bool                      operator==( const iterator&& ) const noexcept;
        bool                      operator!=( const iterator&& ) const noexcept;
        std::pair< key&, value& > operator*();

      private:
        std::shared_ptr< node > m_NowNode;
    };

  public:
    RedBlackTree();
    ~RedBlackTree();
    void     insert( std::pair< key, value > value );
    value&   operator[]( const key&& key );
    iterator find( const key&& key );
    iterator begin();
    iterator end();
    void     eraser( const iterator& );
    void     clear();
    size_t   size();

  private:
    /*
    m_root：
            左孩子永远指向最小值
            右孩子永远指向最大值
            父节点永远指向头结点
     */
    std::unique_ptr< node > m_root;
    std::atomic_size_t      m_size;
};

template < typename key, typename value >
inline RedBlackTree< key, value >::node::node()
{
    m_left   = nullptr;
    m_right  = nullptr;
    m_parent = nullptr;
}

template < typename key, typename value >
inline RedBlackTree< key, value >::node::node( const node& val )
{
    m_key    = val.m_key;
    m_value  = val.m_value;
    m_left   = val.m_left;
    m_right  = val.m_right;
    m_parent = val.m_parent;
}

template < typename key, typename value >
inline RedBlackTree< key, value >::node::node( node&& val )
{
    std::swap( m_left, val.m_left );
    std::swap( m_right, val.m_right );
    std::swap( m_parent, val.m_parent );
    std::swap( m_value, val.m_value );
    std::swap( m_key, val.m_key );
}

template < typename key, typename value >
inline RedBlackTree< key, value >::node& RedBlackTree< key, value >::node::operator=( const node& val )
{
    m_key    = val.m_key;
    m_value  = val.m_value;
    m_left   = val.m_left;
    m_right  = val.m_right;
    m_parent = val.m_parent;
    return *this;
}

template < typename key, typename value >
inline RedBlackTree< key, value >::node& RedBlackTree< key, value >::node::operator=( node&& val )
{
    std::swap( m_left, val.m_left );
    std::swap( m_right, val.m_right );
    std::swap( m_parent, val.m_parent );
    std::swap( m_value, val.m_value );
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
    m_size = 0;
    m_root = std::make_unique< node >();
}

template < typename key, typename value >
inline RedBlackTree< key, value >::~RedBlackTree()
{
    clear();
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
    return iterator();
}

template < typename key, typename value >
inline RedBlackTree< key, value >::iterator RedBlackTree< key, value >::end()
{
    return iterator();
}

template < typename key, typename value >
inline void RedBlackTree< key, value >::eraser( const iterator& )
{
}

template < typename key, typename value >
inline void RedBlackTree< key, value >::clear()
{
}

template < typename key, typename value >
inline size_t RedBlackTree< key, value >::size()
{
    return size_t();
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
inline RedBlackTree< key, value >::iterator& RedBlackTree< key, value >::iterator::operator++( int )
{
}

template < typename key, typename value >
inline RedBlackTree< key, value >::iterator& RedBlackTree< key, value >::iterator::operator++()
{
    // TODO: 在此处插入 return 语句
}

template < typename key, typename value >
inline bool RedBlackTree< key, value >::iterator::operator==( const iterator&& ) const noexcept
{
    return false;
}

template < typename key, typename value >
inline bool RedBlackTree< key, value >::iterator::operator!=( const iterator&& ) const noexcept
{
    return false;
}

template < typename key, typename value >
inline std::pair< key&, value& > RedBlackTree< key, value >::iterator::operator*()
{
    return std::pair< key&, value& >();
}
