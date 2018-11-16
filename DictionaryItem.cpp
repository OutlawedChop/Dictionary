#include <iostream>
#include <string>
#include <fstream>
#include "DictionaryItem.h"

using namespace std;

DictionaryItem::DictionaryItem() : DictionaryItem(0, "") {};
DictionaryItem::DictionaryItem(int value, string key) {
	this->value = value;
	this->key = key;
}
int& DictionaryItem::getValue() {
	return value;
}
string& DictionaryItem::getKey() {
	return key;
}
void DictionaryItem::setValue(int value) {
	this->value = value;
}
void DictionaryItem::setKey(string key) {
	this->key = key;
}
ostream& operator<<(ostream& os, DictionaryItem item) {
	cout << "\"" << item.getKey() << "\"   : " << item.getValue() << endl;
	return os;
}