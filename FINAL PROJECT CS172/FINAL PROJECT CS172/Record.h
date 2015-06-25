#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
using namespace std; 

class Record{
public:
	int month;
	int day;
	
	char winLoss;

	Record(); 
	Record(int newmonth, int newday);

	char getwinOrLoss();

};
#endif