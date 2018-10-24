#ifndef DICTIONARY
#define DICTIONARY
#include <string>
#include <iostream>

using namespace std;
#define ARR_LEN 10

class Dictionary {
private:
	int arr_len;
	int count;
	int *emount;
	string *key;
public:
	Dictionary();
	int getCount();
	int* getEmountArr();
	int getEmount(int index);
	string getWord(int index);
	void setEmount(int value, int index);
	void setWord(string word, int index);
	string* getKeysArr();
	void extendSpace();
	int& operator[](string word);
	void addElement(string word, int value);
	void addElement(string word);
	int findIndex(string word);
	bool isExist(string word);
	bool addWorld(string word);
	void sortDictionary();
};

bool isRemoveSymbol(char symbol);
string checkWordSigns(string &word);
string checkWordCase(string &word);
void printDictionaryElement(Dictionary d, int i);
void printDictionary(Dictionary d, int number);
void readDictionatyFromFile(ifstream& fin, Dictionary &d);
bool ifsimilar(Dictionary &d1, Dictionary &d2, int n);

#endif