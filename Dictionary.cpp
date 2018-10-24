#include <iostream>
#include <string>
#include <fstream>
#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary()
{
	arr_len = ARR_LEN;
	count = 0;
	emount = new int[arr_len];
	key = new string[arr_len];
}

int Dictionary::getCount() {
	return count;
}
int* Dictionary::getEmountArr() {
	return emount;
}
string* Dictionary::getKeysArr() {
	return key;
}
int Dictionary::getEmount(int index) {
	if (index > count) {
		return 0;
	}
	return emount[index];
}
string Dictionary::getWord(int index) {
	if (index > count) {
		return "";
	}
	return key[index];
}
void Dictionary::setEmount(int value, int index) {
	emount[index] = value;
}
void Dictionary::setWord(string word, int index) {
	key[index] = word;
}

void Dictionary::extendSpace() {
	int *tempi = new int[arr_len + 10];
	string *temps = new string[arr_len + 10];
	for (int i = 0; i < arr_len; i++) {
		tempi[i] = emount[i];
		temps[i] = key[i];
	}
	delete[] emount;
	delete[] key;

	emount = tempi;
	key = temps;
	arr_len += 10;
}
void Dictionary::addElement(string word, int value) {
	if (count > arr_len) {
		extendSpace();
	}
	key[count] = word;
	emount[count] = value;
	count++;
}
void Dictionary::addElement(string word) {
	if (count > arr_len - 1) {
		extendSpace();
	}
	key[count] = word;
	emount[count] = 0;
	count++;
}
bool Dictionary::isExist(string word) {
	for (int i = 0; i < count; i++) {
		if (key[i] == word) {
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
		key[count] = word;
		count++;
		return 1;
	}
}
int Dictionary::findIndex(string word) {
	for (int i = 0; i < count; i++) {
		if (key[i] == word) {
			return i;
		}
	}
	return 0;
}
void Dictionary::sortDictionary() {
	int tempi;
	string temps;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (getEmount(j) < getEmount(j + 1)) {
				tempi = getEmount(j);
				setEmount(getEmount(j + 1), j);
				setEmount(tempi, j + 1);

				temps = getWord(j);
				setWord(getWord(j + 1), j);
				setWord(temps, j + 1);
			}
		}
	}
}
int& Dictionary::operator[](string word)
{
	if (isExist(word)) {
		return emount[findIndex(word)];
	}
	else {
		addElement(word);
		return emount[count - 1];
	}
}

void printDictionaryElement(Dictionary d, int i) {
	cout << "\"" << d.getKeysArr()[i] << "\"   : " << d.getEmountArr()[i] << endl;
}
void printDictionary(Dictionary d, int number) {
	if (number == -1) {
		number = d.getCount();
	}
	for (int i = 0; i < d.getCount(); i++) {
		printDictionaryElement(d, i);
		if (i > number - 2) {
			break;
		}
	}
}

bool isRemoveSymbol(char symbol) {
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
			if (d1.getWord(i) == d2.getWord(j)) {
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

