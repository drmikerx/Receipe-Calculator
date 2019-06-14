#ifndef INGREDIENT
#define INGREDIENT

#include <string>
using std::string;

class Ingredient {

private:
	double quantityOfIngredient;
	double quantityOfIngredientAdjusted;
	string unitOfMeasure;
	string ingredientName;

	Ingredient* next;
	Ingredient* prev;

public:

	Ingredient();						// used to create list head
	Ingredient(double, string, string);
	double getQuantity();
	void setQuantityAdjusted(double);
	double getQuantityAdjusted();
	string getUnits();
	string getIngredientName();
	Ingredient* getNext();
	void setNext(Ingredient*);
	Ingredient* getPrev();
	void setPrev(Ingredient*);
};




#endif