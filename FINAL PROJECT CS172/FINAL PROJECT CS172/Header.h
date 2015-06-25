#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std; 

class Player
{
public:
	string fname;
	string lname;
	string newfname;
	string newlname;
	int number; 

	double battingavg; 

	string position;
	
	Player();
	Player(string newfname, string newlname, double newbattingavg, string newposition, int newnumber);
	
	string getFirstName();
	string getLastName();
	double getBattingAvg();
	string getPosition();
	int getNumber(); 
};
#endif