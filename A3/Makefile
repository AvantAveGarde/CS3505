FLAGS = -Wall -fsanitize=undefined

output.o: trie.o node.o main.o
	g++ main.o trie.o node.o -o testOutput

main.o: main.cpp
	g++ -c -g main.cpp

node.o: node.h node.cpp
	g++ -c -g node.cpp

trie.o: trie.h trie.cpp
	g++ -c -g trie.cpp

clean:
	rm *.o
