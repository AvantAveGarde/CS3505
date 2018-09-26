#include <stdio.h>
#include <iostream>

// Nasty global because we haven't talked static yet
int counter = 0;

// Make a binary tree class
class BT {
    BT* left;
    BT* right;
    int val;

public:
    BT() {
    	left = right = nullptr; // A node starts with empty branches
	    val = counter++; // get a unique value
    }

    BT( const BT& other) {
        val = other.val;

        // These need to be set to something. Preset to null, then give real value
        left = right = nullptr;
        if (other.left)
            left = new BT(*(other.left));
        if (other.right)
            right = new BT(*(other.right));
    }

    ~BT() {
        printf("deleting val %d\n",val);
        delete left;
        delete right;
    }

    BT& operator=(BT other) {
        std::swap(val, other.val);
        std::swap(left, other.left);
        std::swap(right, other.right);
        return *this;
    }

    void addLeft() {
	left = new BT();
    }

    void addRight() {
	right = new BT();
    }

    void printTree() {
	if(left)
	    left->printTree();
	printf("%d\n", val);
	if(right)
	    right->printTree();

    }
};

int main() {
    BT root;
    root.addLeft();
    root.addRight();
    root.printTree();

    BT copy(root);

}
