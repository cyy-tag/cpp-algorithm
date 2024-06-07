#include <vector>
#include <string>
#include <gtest/gtest.h>
//trie tree
#include "trie_tree.h"

class TreeTest : public testing::Test {
protected:
  void SetUp() override {

  }
};

TEST_F(TreeTest, Trie) {
  std::vector<std::string> words{"word", "lett", "cool"};
  TrieTree tree;
  for(string& word : words) {
    
  }
}
