#include "Header.h"

Player::Player(){
	fname = "Felix";
	lname = "Hernandez";
	battingavg = .000;
}

Player::Player(string newfname, string newlname, double newbattingavg, string newposition, int newnumber){
	fname = newfname;
	lname = newlname;
	battingavg = newbattingavg;
	position = newposition; 
	number = newnumber; 
} 

string Player::getFirstName(){
	return fname;
}

string Player::getLastName(){
	return lname;
}

double Player::getBattingAvg(){
	return battingavg;
}

string Player::getPosition(){
	return position;
}

int Player::getNumber(){
	return number; 
}