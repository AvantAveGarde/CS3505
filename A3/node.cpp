#include "node.h"
#include <stdio.h>
#include <iostream>

Node::Node(bool i_endOfWord){
  isValidWord = i_endOfWord;
  for(int i=0; i < 26; i++){
    children[i] = nullptr;
  }
}
void Node::setValid(){
  isValidWord = true;
}
void Node::setInvalid(){
  isValidWord = false;
}
bool Node::getValid(){
  return isValidWord;
}

Node::Node(){
  for(int i=0; i < 25; i++){
    children[i] = nullptr;
  }
}
Node::Node(const Node& i_Node){
  for(int i=0; i < 25; i++){
    children[i] = nullptr;
    children[i] = new Node(*((i_Node).children[i]));
  }
}
Node& Node::operator=(Node i_Node){
  for(int i=0; i < 25; i++){
    std::swap(children[i], ((i_Node).children[i]));
  }
  return *this;
}
Node::~Node(){

}
