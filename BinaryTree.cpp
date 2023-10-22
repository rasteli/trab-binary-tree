// Gabriel Rasteli - 2136428

#include <iostream>
#include <string>
#include <iomanip>
#include "BinaryTree.h"

BinaryTree::BinaryTree() {
  root = NULL;
}

// BinaryTree::~BinaryTree() {
//   Clear(root);    
// }

void BinaryTree::Insert(std::string x1, std::string x2, std::string x3) {
  TreeNode *left_node, *right_node;

  CreateNode(x2, left_node);
  CreateNode(x3, right_node);
  
  if (root == NULL) {
    root = new TreeNode;
    root->entry = x1;

    root->leftNode = left_node;
    root->rightNode = right_node;

    return;
  }

  TreeNode *p;
  Search(x1, root, p);

  p->leftNode = left_node;
  p->rightNode = right_node;
}

bool BinaryTree::Search(std::string x) {
  TreeNode *p;
  return Search(x, root, p);
}

bool BinaryTree::Search(std::string x, TreeNode *r, TreeNode *&p) {
  if (r == NULL) return false;
  
  if (x == r->entry) {
    p = r;
    return true;
  }

  if (Search(x, r->leftNode, p)) return true;

  return Search(x, r->rightNode, p);
}

int BinaryTree::Nodes() {
  return Nodes(root);
}

int BinaryTree::Nodes(TreeNode *r) {
  if (r == NULL) return 0;

  return 1 + Nodes(r->leftNode) + Nodes(r->rightNode);
}

int BinaryTree::Leaves() {
  return Leaves(root);
}

int BinaryTree::Leaves(TreeNode *r) {
  if (r == NULL) return 0;
  if (r->leftNode == NULL && r->rightNode == NULL) return 1;

  return Leaves(r->leftNode) + Leaves(r->rightNode);
}

void BinaryTree::Print(){
  Print(root, 0);
}

void BinaryTree::Print(TreeNode *&t, int s){
  if (t != NULL){
    Print(t->rightNode, s + 3);

    for(int i = 1; i <= s; i++)
      std::cout << ' ';

    std::cout << std::setw(6) << t->entry << '\n';
    Print(t->leftNode, s + 3);
  }
}

void BinaryTree::CreateNode(std::string x, TreeNode *&node) {
  if (x == EmptyKey) {
    node = NULL; 
  } else {
    node = new TreeNode;
    node->entry = x;
    node->leftNode = node->rightNode = NULL;
  }
}

void BinaryTree::Data() {
  Data(root);
}

void BinaryTree::Data(TreeNode *&r) {
  if (r == NULL) return;

  int children = 0;
  std::string type = "F";

  if (r->leftNode != NULL) {
    children++;
    type = "E";
  }

  if (r->rightNode != NULL) {
    children++;
    type = children == 1 ? "D" : "ED";
  }

  std::cout << r->entry << ' ' << children << ' ' << type << '\n';

  Data(r->leftNode);
  Data(r->rightNode);
}
