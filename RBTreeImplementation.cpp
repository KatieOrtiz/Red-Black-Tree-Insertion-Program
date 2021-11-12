//Katie Ortiz - Homework #3 - CS 236 - 3/24/2021
#include "RBTreeHeader.h"

//Implementation of the RedBlackTreeClass constructor
RedBlackTreeClass::RedBlackTreeClass() {
	nullPtr = new nodeStruct;
	nullPtr->colorofNode = 0;
	nullPtr->leftNode = nullptr;
	nullPtr->rightNode = nullptr;
	rootNode = nullPtr;
}

//Implementation of insertNode function. This function takes a value for the node and inserts the node into the Red-Black Tree
void RedBlackTreeClass::insertNode(int nodeValue) {
	cout << nodeValue << " "; //Printing a space between the nodes

	nodePtr node = new nodeStruct; 
	node->parentNode = nullptr;
	node->data = nodeValue;
	node->leftNode = nullPtr;
	node->rightNode = nullPtr;
	node->colorofNode = 1; //The color of the node is assigned to red
	nodePtr temp1 = nullptr;
	nodePtr temp2 = this->rootNode;

	while (temp2 != nullPtr) { //If the temp2 node is not assigned to nullPtr then assign temp2 to temp1
		
		temp1 = temp2;

		if (node->data < temp2->data) { //If the value in the node is less than the value in temp2, assign temp2 to the left
			temp2 = temp2->leftNode;
		}

		else { //Else, assign temp2 to the right
			temp2 = temp2->rightNode;
		}
	}

	node->parentNode = temp1;

	if (temp1 == nullptr) { //If the parentNode is null, assign the node to the root
		rootNode = node;
	}

	else if (node->data < temp1->data) { //If the value in the node is less than the value in the temp1 node, then assign node to the left
		temp1->leftNode = node;
	}

	else {
		temp1->rightNode = node; //If the value in the node is greater than the value in the temp1 node, then assign node to the right
	}

	if (node->parentNode == nullptr) { //If the parentNode is null, set the color of this node to black
		node->colorofNode = 0;
		return;
	}

	if (node->parentNode->parentNode == nullptr) { 
		return; //Returns if the comparison comes back to be true 
	}

	//Balances tree after node insertion 
	balanceRedBlackTree(node);
}


//Implementation of balanceNodes function. This function will balance out the nodes inserted into the tree, rotate the nodes, and assign the correct color to the node
void RedBlackTreeClass::balanceRedBlackTree(nodePtr node) {
	nodePtr temp;
	while (node->parentNode->colorofNode == 1) {

		if (node->parentNode == node->parentNode->parentNode->rightNode) {
			temp = node->parentNode->parentNode->leftNode;

			if (temp->colorofNode == 1) { 
				temp->colorofNode = 0; //Assigns the color black to temp
				node->parentNode->colorofNode = 0; //Assigns the color black to the parent node
				node->parentNode->parentNode->colorofNode = 1; //Assigns the color red to the grandfather node
				node = node->parentNode->parentNode;
			}

			else {

				if (node == node->parentNode->leftNode) {
					node = node->parentNode;
					rightRotate(node); //Will call the rightRotate function and pass the node to the function to avoid conflict
				}
				node->parentNode->colorofNode = 0; //Assigns the color black to the parent node
				node->parentNode->parentNode->colorofNode = 1; //Assigns the color red to the grandfather node
				leftRotate(node->parentNode->parentNode); //Will call the leftRotate function and pass the node of node-->parentNode-->parentNode to the function to avoid conflict
			}
		}

		else {
			temp = node->parentNode->parentNode->rightNode; 

			if (temp->colorofNode == 1) {
				temp->colorofNode = 0; //Assigns the color black to temp
				node->parentNode->colorofNode = 0; //Assigns the color black to the parent node
				node->parentNode->parentNode->colorofNode = 1; //Assigns the color red to the grandfather node
				node = node->parentNode->parentNode;
			}

			else {

				if (node == node->parentNode->rightNode) {
					node = node->parentNode;
					leftRotate(node); //Will call the leftRotate function and pass the node of node to the function to avoid conflict
				}

				node->parentNode->colorofNode = 0; //Assigns the color black to the parent node
				node->parentNode->parentNode->colorofNode = 1; //Assigns the color red to the grandfather node
				rightRotate(node->parentNode->parentNode);  //Will call the rightRotate function and pass the node of node-->parentNode-->parentNode to the function to avoid conflict
			}
		}
		if (node == rootNode) {
			break; //Will leave the function immediately if the node is the root node
		}
	}
	rootNode->colorofNode = 0; //The root node is assigned to the color black

	//It is expected that the result of this function will have the nodes in the correct place and colored correctly
}


//Implementation of leftRotate function. This function will balance the nodes that need to be rotated to the left. 
void RedBlackTreeClass::leftRotate(nodePtr node) {
	nodePtr temp = node->rightNode;
	node->rightNode = temp->leftNode;

	if (temp->leftNode != nullPtr) { //If the leftNode is not assigned to the nullPtr, then assign the leftNode-->parentNode to node
		temp->leftNode->parentNode = node;
	}

	temp->parentNode = node->parentNode;

	if (node->parentNode == nullptr) { //If the parentNode is assigned to the nullPtr, then assign the rootNode to temp
		this->rootNode = temp;
	}

	else if (node == node->parentNode->leftNode) { //If the node is assigned to parentNode-->lefttNode, then assign the node-->parentNode-->leftNode to temp
		node->parentNode->leftNode = temp;
	}

	else { //Else, assign the node-->parentNode-->rightNode to temp
		node->parentNode->rightNode = temp;
	}

	temp->leftNode = node;
	node->parentNode = temp;

	//It is expected that the result of this function will have the nodes correctly rotated to the left
}


//Implementation of rightRotate function. This function will balance the nodes that need to be rotated to the right. 
void RedBlackTreeClass::rightRotate(nodePtr node) {
	nodePtr temp = node->leftNode;
	node->leftNode = temp->rightNode;

	if (temp->rightNode != nullPtr) { //If the rightNode is not assigned to the nullPtr, then assign the rightNode->parentNode to node
		temp->rightNode->parentNode = node;
	}

	temp->parentNode = node->parentNode;

	if (node->parentNode == nullptr) { //If the parentNode is assigned to the nullPtr, then assign the rootNode to temp
		this->rootNode = temp;
	}

	else if (node == node->parentNode->rightNode) { //If the node is assigned to parentNode-->rightNode, then assign the node-->parentNode-->rightNode to temp
		node->parentNode->rightNode = temp;
	}

	else { //Else, assign the node-->parentNode-->leftNode to temp
		node->parentNode->leftNode = temp;
	}

	temp->rightNode = node;
	node->parentNode = temp;

	//It is expected that the result of this function will have the nodes correctly rotated to the right
}



//Implementation of displayRedBlackTreeNodes function. This function will add the printed characters to distinguish which nodes are red or black. It also adds the dashes and lines as shown in the sample output
void RedBlackTreeClass::displayRedBlackTreeNodes(nodePtr root, string indentCharacter, bool lastNode) { 
	
	if (root != nullPtr) {
		cout << indentCharacter; 
		if (root == rootNode) {
			cout << "Root----"; //Prints Root---- and this shows which node is the root 
			
		}
	 else if (lastNode) {

			cout << "R----"; //The node is on the right and this printed R---- will show this at the beginning of the right nodes
			indentCharacter += " ";
		}

		else {
			cout << "L----";  //The node is on the left and this printed L---- will show this at the beginning of the left nodes
			indentCharacter += "| "; //Adds the lines as show in the sample output
		}

		string sColor = root->colorofNode ? "RED" : "BLACK"; //Compares the value of the colorofNode and prints out either Red or Black
		cout << root->data << "(" << sColor << ")" << "\n";
		displayRedBlackTreeNodes(root->leftNode, indentCharacter, false); //Passes the node on the left and sets the value of the lastNode to false
		displayRedBlackTreeNodes(root->rightNode, indentCharacter, true); //Passes the node on the right and sets the value of the lastNode to true
	}

	//It is expected that the result of this function will print out the correct colors for the nodes, correct formatting, and correct nodes for each part of the tree
}

//Implementation of displayFinalizedRedBlackTree. This function will call the displayRedBlackTreeNodes function as long as it is on the rootNode
void RedBlackTreeClass::displayFinalizedRedBlackTree() {

	if (rootNode) {
		displayRedBlackTreeNodes(this->rootNode, "", true); //Passes the pointer to the rootNode to displayRedBlackTreeNodes function and sets the lastNode value to true
	}

	//It is expected that the result of this function will finish printing out the Red-Black Tree with the correct nodes, colors for the nodes, and the formatting
}




