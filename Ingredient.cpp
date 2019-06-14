#include "Ingredient.hpp"

Ingredient::Ingredient() {				// used to create the head of the list
	this->quantityOfIngredient = 0;
	this->ingredientName = "";
	this->unitOfMeasure = "";
	this->quantityOfIngredientAdjusted = 0;

	this->next = NULL;
	this->prev = NULL;
}

Ingredient::Ingredient(double ingredientQty, string ingredName, string unit) {
	this->quantityOfIngredient = ingredientQty;
	this->ingredientName = ingredName;
	this->unitOfMeasure = unit;
	this->quantityOfIngredientAdjusted = 0;		// will be assigned after calculation

	this->next = NULL;
	this->prev = NULL;
}

double Ingredient::getQuantity() {
	return quantityOfIngredient;
}

void Ingredient::setQuantityAdjusted(double newQuantity) {
	this->quantityOfIngredientAdjusted = newQuantity;
}

double Ingredient::getQuantityAdjusted() {
	return quantityOfIngredientAdjusted;
}

string Ingredient::getUnits() {
	return unitOfMeasure;
}


string Ingredient::getIngredientName() {
	return ingredientName;
}


Ingredient* Ingredient::getNext() {
	return next;
}

void Ingredient::setNext(Ingredient* newNode) {
	this->next = newNode;
}

Ingredient* Ingredient::getPrev() {
	return prev;
}

void Ingredient::setPrev(Ingredient* newNode) {
	this->prev = newNode;
}