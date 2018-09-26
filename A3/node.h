#ifndef NODE_H
#define NODE_H

class Node{
public:
  Node* children[26];
  bool isValidWord;

  Node();
  Node(bool i_isValidWord);

  Node(const Node& i_Node);
  Node& operator=(Node i_Node);
  ~Node();

  void setValid();
  void setInvalid();
  bool getValid();
};

#endif
