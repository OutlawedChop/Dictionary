#include <iostream>
#include <fstream>
#include "Dictionary.h"
using namespace std;


int main(){
	ifstream fin1("file1.txt");
	ifstream fin2("file2.txt");
	Dictionary dict1;
	Dictionary dict2;

	readDictionatyFromFile(fin1, dict1);
	readDictionatyFromFile(fin2, dict2);
	
	dict1.sortDictionary();
	dict2.sortDictionary();

	cout << "----------------First Dictionary-----------------" << endl;
	printDictionary(dict1, 10);
	cout << "-------------------------------------------------\n" << endl;

	cout << "----------------Second Dictionary----------------" << endl;
	printDictionary(dict2, 10);
	cout << "-------------------------------------------------\n" << endl;

	if (ifsimilar(dict1, dict2, 10)) {
		cout << "<<<<<<<<<<<<<< Files are similar! >>>>>>>>>>>>>>" << endl;
	}
	else {
		cout << "<<<<<<<<<<<<< Files are't similar! >>>>>>>>>>>>>" << endl;
	}
	
	
	system("pause");
	return 0;
}