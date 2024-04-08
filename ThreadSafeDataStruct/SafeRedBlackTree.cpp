#include "SafeRedBlackTree.h"

node::node(/* args */)
{
    m_left = nullptr;
    m_right = nullptr;
}

node::node(const node &value)
{
    m_left = value.m_left;
    m_right = value.m_right;
    m_data = value.m_data;
}

node::~node()
{
}

RedBlackTree::RedBlackTree()
{
}

RedBlackTree::~RedBlackTree()
{
}
