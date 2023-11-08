// Gabriel Rasteli - 2136428

#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTree.h"

int main() {
  BinaryTree t;
  std::string root, left_node, right_node;
  std::ifstream file("test/exemplo1.tree", std::ios::in);

  while (file >> root >> left_node >> right_node) {
    if (root != EmptyKey)
      t.Insert(root, left_node, right_node);
  }

  t.Data();
  std::cout << t.Nodes() << ' ' << t.Leaves() << '\n';

  return 0;
}
