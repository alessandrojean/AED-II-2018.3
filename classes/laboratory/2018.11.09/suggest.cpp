#include <stdio.h>
#include <stdlib.h>
#include "tn_trie.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main () {
  tn_trie_node* root = new_node();

  string line;
  ifstream file("url02.txt");
  while (file >> line)
    insert(root, line);

  string query;
  cout << "Digite uma URL: ";
  cin >> query;

  tn_suggest(root, query);
}
