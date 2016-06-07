#ifndef BINARYTREE_H
#define BINARYTREE_H

// This class defines an extremely simple BinaryTree class - specifically a node that can be strug together
// with other nodes to create a tree

template <typename T>
struct BinaryTreeNode
{
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    T* data;
};

#endif /* BINARYTREE_H */
