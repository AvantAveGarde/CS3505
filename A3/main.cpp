#include "trie.h"
#include <iostream>

int main(){
  Trie testTrie = Trie();
  testTrie.addWord("Ryougi");
  testTrie.addWord("RyougiShiki");
  testTrie.addWord("Rubedo");
  testTrie.addWord("RandomWord");
  testTrie.addWord("Shiki");
  testTrie.addWord("Shinsekai");

  Trie testTrie2 = testTrie;


  //Trie testTrie3 = Trie(testTrie);

  //std::cout << "Is Ryougi a valid word? " << testTrie.isWord("Ryougi") << std::endl;
  //std::cout << "Is Shiki a valid word? " << testTrie.isWord("Shiki") << std::endl;
  //std::cout << "Is Shiki a valid word? " << testTrie.isWord("Shiki") << std::endl;

  std::cout << "Is RyougiShiki a valid word? " << testTrie.isWord("RyougiShiki") << std::endl;
  std::cout << "Is RyougiShiki (2) a valid word? " << testTrie2.isWord("RyougiShiki") << std::endl;

  //std::cout << "Is Reddit a valid word? " << testTrie.isWord("Reddit") << std::endl;
  //std::cout << "Is RyougiShiki a valid word? " << testTrie.isWord("RyougiShiki") << std::endl;
  std::vector<std::string> testArray = testTrie.allWordsStartingWithPrefix('s');

  for(int i = 0; i < testArray.size(); i++){
    std::cout << testArray[i] << std::endl;
  }

  return 0;
}
