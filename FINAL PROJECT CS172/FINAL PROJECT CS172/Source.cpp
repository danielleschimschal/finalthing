#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Header.h"
#include "Record.h"

using namespace std;

void option1();  // function to add to batting order
void option2();  // function to add someone to roster
void option3();  // function to view player's stats
void option4();	 // function to add a win or a loss to a team's record

int main(){

	cout << "!!MARINER'S BASEBALL!!" << endl; 
	cout << "Pick one: " << endl;
	cout << "1. Add player to batting order" << endl;
	cout << "2. Add player to roster" << endl;		// was going to be add or remove but i could not figure out how to remove them
	cout << "3. View player's statistics" << endl;
	cout << "4. Add win or loss to team's record" << endl << endl; 

	int input;
	cout << "Enter the number of your choice: ";
	cin >> input; 
	cout << endl; 
	if (input == 1){
		option1(); 
	}
	else if (input == 2){
		option2();
	}
	else if (input == 3){
		option3();
	}
	else if (input == 4){
		option4();
	}
	else
		cout << "You entered an invalid number" << endl; 
}

void option1(){
	ifstream playerstats;
	string firstname;
	string lastname;
	string fname, lname, position;
	int number; 
	double battingavg;
	int i = 0;
	playerstats.open("C:\\Users\\dschi_000\\Desktop\\playerstats.txt"); // open file containing players statistics

	if (!playerstats)
		cout << "The file containing the players' stats does not exist\n"; // if the file can't be found will cout message indicating that

	playerstats.close(); 

	ofstream battingorder;
	battingorder.open("C:\\Users\\dschi_000\\Desktop\\battingorder.txt");

	battingorder << left << setw(4) << "#" << setw(10) << "First: " << setw(14) << "Last: " << setw(14) << "Batting Avg: " << endl;	// formats list
	
	cout << "Enter a name to add to the batting order. If the name is not on the roster then it will not show up on the batting order" << endl << endl; 

	do{
		cout << "Who do you want to add to the batting order? ";
		cin >> fname >> lname;
		
		playerstats.open("C:\\Users\\dschi_000\\Desktop\\playerstats.txt");	// opens roster to take names from for batting order

		while (playerstats >> firstname >> lastname >> battingavg >> position >> number){
			if (firstname == fname && lastname == lname){
				battingorder << left << setw(4) << i + 1 << setw(10) << fname << setw(14) << lname << setw(14) << battingavg << endl; // writes names and batting averages to other file
			}
		}
		playerstats.close();
		i++; 
		
	} while (i < 9);  // puts 9 people on batting order
}

void option2(){
	ifstream playerstats;
	ofstream newroster;

	string fname, lname, position, f1name, l1name, p1osition, f2name, l2name;
	double battingavg, b1attingavg;
	int n1umber, number;
	char ans;

	newroster.open("C:\\Users\\dschi_000\\Desktop\\newroster.txt");
		do{
			cout << "What is the player's name? ";		//creates new player to add to roster
			cin >> f1name >> l1name;
			cout << "What is their batting average? ";
			cin >> b1attingavg;
			cout << "What position do they play? ";
			cin >> p1osition;
			cout << "What number are they? ";
			cin >> n1umber; 

			Player p1(f1name, l1name, b1attingavg, p1osition, n1umber);		// identifies this player using classes
			newroster << left << setw(10) << "First: " << setw(14) << "Last: " << setw(14) << "Batting Avg: " << setw(10) << "Position: " << setw(10) << "Number: " << endl; 

			// use classes to write information about player to newroster file
			newroster << left << setw(10) << p1.getFirstName() << setw(14) << p1.getLastName() << setw(14) << p1.getBattingAvg() << setw(10) << p1.getPosition() << setw(10) << p1.getNumber() << endl;

			playerstats.open("C:\\Users\\dschi_000\\Desktop\\playerstats.txt");

			// reads information from playerstats file and writes it to the newroster file. uses iomanip to organize information
			while (!playerstats.eof()){
				playerstats >> fname >> lname >> battingavg >> position >> number;
				newroster << left << setw(10) << fname << setw(14) << lname << setw(14) << battingavg << setw(10) << position << setw(10) << number << endl;
			}
			cout << "You added a player to the roster. Do you want to add another? (Y or N) ";
			cin >> ans;

		} while (ans == tolower('Y'));	// will continue adding people to the roster until you say 'n' 
	}

	

void option3(){
	string fname;
	string lname;
	char answer;

	string firstname;
	string lastname;
	double battingavg;
	string position;
	int number; 

	ifstream playerstats; 

	do{
		cout << "Whose stats do you want to view? ";
		cin >> fname >> lname;							// identifies specific player
		cout << endl; 
		playerstats.open("C:\\Users\\dschi_000\\Desktop\\playerstats.txt");	// opens file to find player

			while (playerstats >> firstname >> lastname >> battingavg >> position >> number){
				
				if (firstname == fname && lastname == lname){
					cout << left << setw(10) << "First: " << setw(14) << "Last: " << setw(14) << "Batting Avg: " << setw(10) << "Position: " << setw(10) << "Number: " << endl; 
					cout << left << setw(10) << fname << setw(14) << lname << setw(14) << battingavg << setw(10) << position << setw(10) << number << endl << endl;	// outputs chosen player's stats
				}
			}
			playerstats.close();

			cout << "Do you want to see the stats for another player? (Y or N) ";
			cin >> answer;

			cout << endl;
	} while (answer == tolower('Y'));		//continues to output new player's stats until you say you don't want to see anymore 
}

void option4(){

	//// for this I was really going to try to use a class to get this all to work
	//// but I couldn't quite figure out how to make the class fit in this section of code so I set one up 
	//// but I wasn't sure how to include it in the actual program.

	int num; 
	int numberOfWins = 33;
	int numberOfLosses = 39;  /// these are how many wins and losses there are as of june 24

	int month;
	int day;

	int month1, day1;
	char winOrLoss1;	// distinguishes between month and day in games file and month and day that user is cin-ing

	char ans;			// used with if statement to distinguish between win and loss
	char winOrLoss;		// char used to say win or loss
	char answer;		// used to keep do while loop going

	ifstream games;
	games.open("C:\\Users\\dschi_000\\Desktop\\games.txt");
	games >> month1 >> day1 >> winOrLoss1;						//assigns names to information in games file
	ofstream record;
	record.open("C:\\Users\\dschi_000\\Desktop\\record.txt");

	record << left << setw(10) << "Month" << setw(10) << "Day" << setw(10) << "Win or Loss" << endl;	// formats record file

		do{
			cout << "Enter month (April - October or 4 - 10): ";
			cin >> month;
			cout << "Enter date: ";
			cin >> day;
			cout << "Did the Mariners win? (Y or N) ";
			cin >> ans;
			if (ans == tolower('Y')){		//if mariner's win number of wins is increased and the new game is added in a new file (record.txt)
				numberOfWins++;
				winOrLoss = 'W';
				record << left << setw(10) << month << setw(10) << day << setw(10) << winOrLoss << endl;
			}
			else{
				numberOfLosses++;				// if mariner's lose number of losses is increased and that game is also added in the file
				winOrLoss = 'L';
				record << left << setw(10) << month << setw(10) << day << setw(10) << winOrLoss << endl;
			}
			cout << "The number of wins for the Mariner's season so far is: " << numberOfWins << endl;	// couts current number of wins and losses
			cout << "The number of losses for the Mariner's season so far is: " << numberOfLosses << endl;

			cout << "Do you want to add another win or loss to their record? (Y or N) ";
			cin >> answer;																		// keep loop going? add another WIN?
		} while (answer == tolower('Y')); 
	
	}


