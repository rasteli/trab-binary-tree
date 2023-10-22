// Gabriel Rasteli - 2136428

#include <string>

#ifndef BINARYTREE_H
#define BINARYTREE_H

const std::string EmptyKey = "X";

class BinaryTree {
  private:
    struct TreeNode {
      std::string entry;
      TreeNode *leftNode, *rightNode;
    };
    TreeNode *root;

    bool Search(std::string x, TreeNode *r, TreeNode *&p);
    void Clear(TreeNode *r);
    void Print(TreeNode *&t, int s);
    void CreateNode(std::string x, TreeNode *&node);
    int Nodes(TreeNode *r);
    int Leaves(TreeNode *r);
    void Data(TreeNode *&r);

  public:
    BinaryTree();
    // ~BinaryTree();
    void Insert(std::string x1, std::string x2, std::string x3);
    bool Search(std::string x);
    void Clear();
    void Print();
    int Nodes();
    int Leaves();
    void Data();
};

#endif