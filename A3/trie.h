#ifndef TRIE_H
#define TRIE_H
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include "node.h"

class Trie{
  std::vector<std::string> wordArray;
  Node root;

  bool searchTrieForWord(std::string i_word, Node* i_node, int i_letterIndex);
  void insertToTrie(std::string i_word, Node* i_node, int i_letterIndex);
  std::vector<std::string> searchAllWordsWithPrefix(const char i_letter, Node* i_node, std::string i_builtWord);

public:
  void addWord(std::string word);
  bool isWord(std::string i_word);
  char nthLetter(int n);

  std::vector<std::string> allWordsStartingWithPrefix(const char i_letter);


  Trie();

  //Rule of Three, Constructor, Copy Constructor & Destructor
  //Copy Constructor - Copies wordArray and the root node
  Trie(const Trie& i_Trie);

  //Assignment Constructor, using copy swap idiom, returns a reference to the
  //now swapped Trie object.
  Trie& operator=(Trie i_Trie);

  ~Trie();
};

#endif
