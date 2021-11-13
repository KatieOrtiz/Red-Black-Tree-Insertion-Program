#include "RBTreeHeader.h"

//Main function
int main() {
	char answer;
	int nodeValue, selection;
	RedBlackTreeClass redBlackTree;

	 do{
		 //Menu that is displayed to the user 
		cout << "***Welcome!*** \n\nPlease select either 1 or 2 from the menu below: \n";
		cout << "1) Insert a single integer into the tree. \n";
		cout << "2) Generate a balanced Red-Black Tree with the following integers: 9, 18, 7, 14, 17, 45, 26, 35, 50, 2, 1, 60\n";
		cin >> selection;

		switch (selection) {
		//Menu 1 selection that allows the user to insert a single integer into the tree.
		case 1:
			cout << "Enter the integer to be added to the Red-Black Tree: \n";
			cin >> nodeValue;
			cout << "\nInserting nodes into an empty Red-Black Tree.\n";
			redBlackTree.insertNode(nodeValue);

			cout << "\n\nFinal balanced Red-Black Tree: \n\n";

			//Calling the function to print out the Red-Black Tree
			redBlackTree.displayFinalizedRedBlackTree();
			break;

		//Menu 2 selection that inserts the integers from the sample output from the assignment into the Red-Black Tree and displays the final balanced Red-Black Tree
		case 2:
			cout << "The following integers will be added to the Red-Black Tree: 9, 18, 7, 14, 17, 45, 26, 35, 50, 2, 1, 60 \n";
			cout << "After the integers are added to the Red-Black Tree, the final balanced Red-Black Tree will be displayed. \n";
			cout << "Inserting nodes into an empty Red-Black Tree.\n";

			redBlackTree.insertNode(9);
			redBlackTree.insertNode(18);
			redBlackTree.insertNode(7);
			redBlackTree.insertNode(14);
			redBlackTree.insertNode(17);
			redBlackTree.insertNode(45);
			redBlackTree.insertNode(26);
			redBlackTree.insertNode(35);
			redBlackTree.insertNode(50);
			redBlackTree.insertNode(2);
			redBlackTree.insertNode(1);
			redBlackTree.insertNode(60);

			cout << "\n\nFinal balanced Red-Black Tree: \n\n";

			//Calling the function to print out the Red-Black Tree
			redBlackTree.displayFinalizedRedBlackTree();
		}
		//Asks the user if they would like to display the menu again and they will have the choice to add more integers to the Red-Black Tree
		cout << "\nWould you like to display the menu again? (Enter a 'Y' or 'y' if you would like to display the menu again. If you would like to exit, enter any other letter or number) \n";
		cin >> answer;

	 } while (answer == 'y' || answer == 'Y');
	
	 cout << "\nGoodbye!\n";
	 system("pause");
}
