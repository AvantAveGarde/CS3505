#include "trie.h"
#include "node.h"

#include <stdio.h>
#include <iostream>


//Helper methods for the defined functions. Converts string / char cases
//to upper to get consistent results.
void Trie::addWord(std::string i_word){
  for (auto & c: i_word) c = toupper(c);
  insertToTrie(i_word, &root, 0);
}
bool Trie::isWord(std::string i_word){
  for (auto & c: i_word) c = toupper(c);
  return searchTrieForWord(i_word, &root, 0);
}

std::vector<std::string> Trie::allWordsStartingWithPrefix(const char i_letter){
  char upperCaseLetter = toupper(i_letter);
  Node* prefixChildOfRoot = root.children[upperCaseLetter - 65];
  return searchAllWordsWithPrefix(upperCaseLetter, prefixChildOfRoot, std::string(1, i_letter));
}

void Trie::insertToTrie(std::string i_word, Node* i_node, int i_letterIndex = 0){
  //Break Case
  if(i_letterIndex < i_word.length()){
    //Index maps to our i_node's children which are node pointers.
    int nodeArrayIndex = (int)i_word[i_letterIndex] - 65;
    //If at the end of a word, set letter to true
    if((*i_node).children[nodeArrayIndex] == 0){
      if(i_letterIndex == i_word.length() - 1){
        Node* newNode = new Node(true);
        (*i_node).children[nodeArrayIndex] = newNode;
        //std::cout << "(New) (True) " << i_word[i_letterIndex] << ":" << (*i_node).children[nodeArrayIndex] << std::endl;
      }
      else{
        Node* newNode = new Node(false);
        (*i_node).children[nodeArrayIndex] = newNode;
        //std::cout << "(New) "  << nodeArrayIndex << ": "<< i_word[i_letterIndex] << ":" << (*i_node).children[nodeArrayIndex] << std::endl;
        insertToTrie(i_word, newNode, i_letterIndex + 1);
      }
    }
    else{
      Node* newNode = (*i_node).children[nodeArrayIndex];
      //std::cout << "(Old)" << i_word[i_letterIndex] << ":" << (*i_node).children[nodeArrayIndex] << std::endl;
      insertToTrie(i_word, newNode, i_letterIndex + 1);
    }
  }
}

bool Trie::searchTrieForWord(std::string i_word, Node* i_node, int i_letterIndex = 0){
  if(i_letterIndex < i_word.length()){
    //Index maps to our i_node's children which are node pointers.
    int nodeArrayIndex = (int)i_word[i_letterIndex] - 65;
    if((*i_node).children[nodeArrayIndex] != 0){
      //If at the end of a word, set letter to true
      if(i_letterIndex == i_word.length() - 1){
        bool validWord = (*((*i_node).children[nodeArrayIndex])).getValid();
        //std::cout << i_letterIndex << " is a :" << validWord << std::endl;
        return validWord;
      }
      else{
        Node* nextNode = (*i_node).children[nodeArrayIndex];
        //std::cout << "(New) " << i_word[i_letterIndex] << ":" << (*i_node).children[nodeArrayIndex] << std::endl;
        return searchTrieForWord(i_word, nextNode, i_letterIndex + 1);
      }
    }
    else{
      return false;
    }
  }
}

std::vector<std::string> Trie::searchAllWordsWithPrefix(const char i_letter, Node* i_node, std::string i_builtWord){
  for(int i = 0; i < 25; i++){
    //std::cout << i << ": " << (*i_node).children[i] << std::endl;
    if((*i_node).children[i] != 0){
      i_builtWord += nthLetter(i + 1);
      //std::cout << "Our word so far is: " << i_builtWord << std::endl;
      if ((*((*i_node).children[i])).getValid()){
        std::cout << "Valid word added it is: " << i_builtWord << std::endl;
        wordArray.push_back(i_builtWord);
      }
      searchAllWordsWithPrefix(i_letter, (*i_node).children[i], i_builtWord);
      i_builtWord.pop_back();
    }
  }
  i_builtWord.pop_back();
  //std::cout << "Backing up, our word is: " << i_builtWord << std::endl;
  if(i_builtWord.empty()){
    return wordArray;
  }
  else{
    return wordArray;
  }
}

char Trie::nthLetter(int n){
  return "abcdefghijklmnopqrstuvwxyz"[n-1];
}

Trie::Trie(){
  root = Node();
}

//Rule of Three, Constructor, Copy Constructor & Destructor

//Copy Constructor - Copies wordArray and the root node
Trie::Trie(const Trie& i_Trie){
  root = Node(i_Trie.root);
}
Trie& Trie::operator=(Trie i_Trie){
  root = Node(i_Trie.root);
}
Trie::~Trie(){;

}
