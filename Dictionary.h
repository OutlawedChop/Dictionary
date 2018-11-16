#ifndef DICTIONARY
#define DICTIONARY
#include <string>
#include <iostream>
#include "DictionaryItem.h"

using namespace std;
#define ARR_LEN 10

#pragma once
class Dictionary {
private:
	int arr_len;
	int count;
	DictionaryItem *item_box;
public:
	Dictionary();
	int& getCount();
	DictionaryItem& getDictItem(int index) const;
	string& getKey(int index) const;
	void extendSpace();
	int& operator[](string word);
	void addElement(string word, int value);
	void addElement(string word);
	int findIndex(string word);
	bool isExist(string word);
	bool addWorld(string word);
	void sortDictionary();
};

string checkWordSigns(string &word);
string checkWordCase(string &word);
void printDictionary(Dictionary& d, int number);
void readDictionatyFromFile(ifstream& fin, Dictionary &d);
bool isRemoveSymbol(const char &symbol);
bool ifsimilar(Dictionary &d1, Dictionary &d2, int n);

#endif