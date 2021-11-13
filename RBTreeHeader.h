#include <iostream>
#include <string>
using namespace std;

//nodeStruct
struct nodeStruct {
	int data = 0, colorofNode = 0;
	nodeStruct *parentNode = nullptr, *leftNode = nullptr, *rightNode = nullptr;
};

typedef nodeStruct *nodePtr;

//RedBlackTreeClass
class RedBlackTreeClass {
private:
	//Member variables
	nodePtr rootNode, nullPtr;

public:
	//Constructor
	RedBlackTreeClass();

	//Member function declarations
	void balanceRedBlackTree(nodePtr node);
	void displayRedBlackTreeNodes(nodePtr root, string indent, bool last);
	void leftRotate(nodePtr node);
	void rightRotate(nodePtr node);
	void insertNode(int key);
	void displayFinalizedRedBlackTree();

};
