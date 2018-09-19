#include <iostream>

//-fsanitize=undefined -warning codes for stack
//-fsanitize=address -warning codes for heap
int main(){
  int* val = new int(4);
  int* same_mem = val;

  std::cout << *val << *same_mem << std::endl;
  delete val;

  delete same_mem;
}
