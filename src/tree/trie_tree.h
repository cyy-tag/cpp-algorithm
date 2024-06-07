#pargma once
#include <unordered_map>
#include <string>

using namespace std;
/* 固定数组实现前缀树/字典树 */
class TrieTree
{
private:
  bool is_end_;
  TrieTree* nexts[26];
public:
  TrieTree():is_end_(false), nexts() {}

  //插入单词
  void insert(string word) {
    TrieTree * cur = this;
    for(char c : word) {
      if(!cur->nexts[c - 'a'])
        cur->nexts[c - 'a'] = new TrieTree();
      cur = cur->nexts[c - 'a'];
    }
    cur->is_end_ = true;
  }

  //查找单词是否存在
  bool contains(string word) {
    TrieTree * cur = this;
    for(char c : word) {
      if(!cur->nexts[c - 'a'])
        return false;
    }
    return cur->is_end_;
  }
};
