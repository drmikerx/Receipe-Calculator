#include "Ingredient.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <string>
using std::string;
//using std::getline;

#include <vector>
using std::vector;

void addNewNode(Ingredient* headNode, Ingredient* newNode);
void printList(Ingredient* headNode, bool printingAdjusted);
void deleteList(Ingredient* headNode);
void calculateNewQuantities(Ingredient* headNode, double oldPeopleCount, double newPeopleCount);
void sendDataToNewFile(Ingredient* headNode, double newPeopleCount);

int main() {

	ifstream fileIn;

	string quantityOfIngredient;		// needs to be converted to int for the node!!!
	double quantityOfIngredientAsNumber;
	string unitOfMeasure;
	string ingredientName;
	double numberOfPeopleOriginal;
	double numberOfPeopleNew;
	double differenceFactor;
	char printToFileResponse;
	bool askForResponseAgain = true;	// for input validation for print to new file question

	Ingredient* headNode = new Ingredient();

	fileIn.open("");	// INSERT FILENAME HERE

	if (fileIn.is_open()) {
		cout << "The file is ready to be processed!" << endl;
		cout << "Press enter to continue...";
		cin.get();
		while (!fileIn.eof()) {					// keep reading in data until end of file
			std::getline(fileIn, quantityOfIngredient, ' ');	// delimeter is a space
			std::getline(fileIn, unitOfMeasure, ' ');		// delimeter is a space
			std::getline(fileIn, ingredientName, '\n');		// read the rest of the line

			quantityOfIngredientAsNumber = std::stod(quantityOfIngredient);

			Ingredient* nodeToAdd = new Ingredient(quantityOfIngredientAsNumber, ingredientName, unitOfMeasure);

			addNewNode(headNode, nodeToAdd);
		}

		cout << "The file was processed and its data is displayed below:\n" << endl;

		printList(headNode, false);		// original print so no adjusted amounts displayed yet

		cout << "\nNow, how many people does this original receipe serve?  ";
		cin >> numberOfPeopleOriginal;
		cout << "Ok, and how many do you want to serve with the new receipe?  ";
		cin >> numberOfPeopleNew;
		calculateNewQuantities(headNode, numberOfPeopleOriginal, numberOfPeopleNew);
		cout << "Excellent, your adjusted receipie is displayed below:\n" << endl;

		printList(headNode, true);		// will now print the adjusted amount dialog

		fileIn.close();

		// input validation

		while (askForResponseAgain == true) {
			cout << "Would you like to save this information to a new file? (Y/N)  ";
			cin >> printToFileResponse;

			if (printToFileResponse == 'Y' || printToFileResponse == 'N' ||
				printToFileResponse == 'y' || printToFileResponse == 'n')
			{
				askForResponseAgain = false;
			}

			else {
				cout << "Invalid input please type either Y or N" << endl;
			}
		}

		if (printToFileResponse == 'Y' || printToFileResponse == 'y') {		// send all data to a new file
			sendDataToNewFile(headNode, numberOfPeopleNew);
		}

		else {
			cout << "Goodbye!" << endl;
		}

		deleteList(headNode);			// prevent memory leaks
	}

	else {
		cout << "Unable to open file!" << endl;		// data could not be read in from original file
	}

	return 1;
}
