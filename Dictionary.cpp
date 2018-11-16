#include <iostream>
#include <string>
#include <fstream>
#include "Dictionary.h"
#include "DictionaryItem.h"

using namespace std;

Dictionary::Dictionary()
{
	arr_len = ARR_LEN;
	count = 0;
	item_box = new DictionaryItem[ARR_LEN];
}

int& Dictionary::getCount() {
	return count;
}
DictionaryItem& Dictionary::getDictItem(int index) const {
	//if (index > count) {
	//	return "";
	//}
	return item_box[index];
}
string& Dictionary::getKey(int index) const {
	return item_box[index].getKey();
}
void Dictionary::extendSpace() {
	DictionaryItem *temp = new DictionaryItem[arr_len * 2];
	string *temps = new string[arr_len];
	for (int i = 0; i < arr_len; i++) {
		temp[i] = item_box[i];
	}
	delete[] item_box;

	item_box = temp;
	arr_len *=  2;
}
void Dictionary::addElement(string word, int value) {
	if (count > arr_len) {
		extendSpace();
	}
	item_box[count] = DictionaryItem(value, word);
	count++;
}
void Dictionary::addElement(string word) {
	if (count > arr_len - 1) {
		extendSpace();
	}
	item_box[count] = DictionaryItem(0, word);
	count++;
}
bool Dictionary::isExist(string word) {
	for (int i = 0; i < count; i++) {
		if (item_box[i].getKey() == word) {
			return 1;
		}
	}
	return 0;
}
bool Dictionary::addWorld(string word) {
	if (isExist(word)) {
		return 0;
	}
	else {
		item_box[count].setKey(word);
		count++;
		return 1;
	}
}
int Dictionary::findIndex(string word) {
	for (int i = 0; i < count; i++) {
		if (item_box[i].getKey() == word) {
			return i;
		}
	}
	return 0;
}
void Dictionary::sortDictionary() {
	DictionaryItem temp;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (item_box[j].getValue() < item_box[j + 1].getValue()) {
				
				temp = item_box[j];
				item_box[j] = item_box[j + 1];
				item_box[j + 1] = temp;
			}
		}
	}
}
int& Dictionary::operator[](string word)
{
	if (isExist(word)) {
		return item_box[findIndex(word)].getValue();
	}
	else {
		addElement(word);
		return item_box[count - 1].getValue();
	}
}

void printDictionary(Dictionary &d, int number) {
	if (number == -1) {
		number = d.getCount();
	}
	for (int i = 0; i < d.getCount(); i++) {
		cout << d.getDictItem(i);
		if (i > number - 2) {
			break;
		}
	}
}
bool isRemoveSymbol(const char &symbol) {
	char symbols[23] = { '.', ',', ':',';','!','?','-','_', ']', '[', ')', '(', '{', '}', '#', '~', '%', '$', '*', '+', '\'', '/', '\"',};
	if ((char)symbol >= 48 && (char)symbol <= 57) {
		return true;
	}
	for (int i = 0; i < 23; i++) {
		if (symbol == symbols[i])
		{
			return true;
		}
	}
	return false;
}
string checkWordSigns(string &word) {
	for (int i = 0; i < word.length(); i++) {
		if (isRemoveSymbol(word[i])) {
			if (i == 0) {
				word = word.substr(1, word.length());
			}
			else if (i == word.length() - 1) {
				word = word.substr(0, word.length() - 1);
			}
			else {word = word.substr(0 , i) + word.substr(i + 1, word.length());
			}
			i--;
		}
	}
	return word;
}
string checkWordCase(string &word) {
	for (int i = 0; i < word.length(); i++) {
		if (!(int(word[i]) >= -1 && int(word[i]) <= 255)) {
			word[i] = ' ';
			continue;
		}
		if (isupper((char)word[i])) {
			word[i] = char((int)word[i] + 32);
		}

	}
	return word;
}
void readDictionatyFromFile(ifstream& fin, Dictionary &d) {
	string temp;
	while (fin >> temp) {
		temp = checkWordCase(temp);
		temp = checkWordSigns(temp);
		if (temp == "") { continue; }
		d[temp] += 1;
	}
	fin.close();
}
bool ifsimilar(Dictionary &d1, Dictionary &d2, int n) {
	int min = d1.getCount() < d2.getCount() 
		? d1.getCount() : d2.getCount();
	if (n > min) { n = min; }


	bool b = false;
	for (int i = 0; i < n; i++) {
		bool b = false;
		for (int j = 0; j < n; j++) {
			if (d1.getKey(j) == d2.getKey(j)) {
				b = true;
				break;
			}
			else {
				if (j == n - 1) {
					b = false;
					break;
				}
				continue;
			}
		}
		if (b == true) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}