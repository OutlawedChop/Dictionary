#ifndef DICTIONARY_ITEM
#define DICTIONARY_ITEM
#include <iostream>
#include <string>

using namespace std;
#pragma once
class DictionaryItem {
private:
	int value;
	string key;
public:
	DictionaryItem();
	DictionaryItem(int value, string key);
	int& getValue();
	string& getKey();
	void setValue(int value);
	void setKey(string key);
};

ostream& operator<<(ostream& os, DictionaryItem item);
#endif;