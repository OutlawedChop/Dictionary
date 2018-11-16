#include <iostream>
#include <fstream>
#include <ctime>
#include "Dictionary.h"
using namespace std;


int main(){
	ifstream fin1("file1.txt");
	ifstream fin2("file2.txt");
	Dictionary dict1;
	Dictionary dict2;
	clock_t t0 = clock();

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
	
	clock_t t1 = clock();
	cout << "time: " << (double)(t1 - t0) / CLOCKS_PER_SEC << endl;


	system("pause");
	return 0;
}