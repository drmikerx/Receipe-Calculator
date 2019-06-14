#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ofstream;

#include "Ingredient.hpp"

#include <string>
using std::string;


void printList(Ingredient* headNode, bool printingAdjusted) {
	Ingredient* nodeToPrint = headNode;			// now points to head node

	while (nodeToPrint->getNext() != NULL) {
		nodeToPrint = nodeToPrint->getNext();
		cout << "Ingredient name is..." << nodeToPrint->getIngredientName() << endl;
		if (printingAdjusted == false) {
			cout << "Original amount of this ingredient to use is..." << nodeToPrint->getQuantity() << endl;
		}

		else if (printingAdjusted == true) {
			cout << "New ADJUSTED amount of this ingredient to use is..." << nodeToPrint->getQuantityAdjusted() << endl;
		}
		cout << "Measured in units..." << nodeToPrint->getUnits() << endl;
		cout << endl;
	}
}


void addNewNode(Ingredient* headNode, Ingredient* newNode) {
	Ingredient* locationToAdd = headNode;

	while (locationToAdd->getNext() != NULL) {
		locationToAdd = locationToAdd->getNext();
	}

	// locationToAdd now points to the previous last node of the linked list

	locationToAdd->setNext(newNode);
	newNode->setPrev(locationToAdd);
	newNode->setNext(NULL);
}


void deleteList(Ingredient* headNode) {
	Ingredient* garbage = headNode;
	Ingredient* scanner = headNode;

	while (garbage != NULL) {
		scanner = scanner->getNext();
		delete garbage;
		garbage = scanner;
	}
}


void calculateNewQuantities(Ingredient* headNode, double oldPeopleCount, double newPeopleCount) {
	Ingredient* nodeToAdjust = headNode;

	double adjustmentFactor = oldPeopleCount / newPeopleCount;

	while (nodeToAdjust->getNext() != NULL) {
		nodeToAdjust = nodeToAdjust->getNext();
		nodeToAdjust->setQuantityAdjusted(nodeToAdjust->getQuantity() / adjustmentFactor);	// new = original/adj factor
	}

	// new quantites are stored within their respective link node
}

void sendDataToNewFile(Ingredient* headNode, double newPeopleCount) {
	ofstream fileOut;

	fileOut.open("C:\\Users\\Michael\\Desktop\\SampleReceipeAdjusted.txt");

	if (fileOut.is_open()) {

		fileOut << "Your receipe adjusted to now serve " << newPeopleCount << " people:\n" << endl;

		Ingredient* nodeToSend = headNode;

		while (nodeToSend->getNext() != NULL) {
			nodeToSend = nodeToSend->getNext();
			fileOut << nodeToSend->getQuantityAdjusted() << " " << nodeToSend->getUnits() << " " <<
				nodeToSend->getIngredientName() << endl;
		}

		fileOut.close();
	}

	else {

		cout << "There was a problem creating that file!" << endl;
	}
}