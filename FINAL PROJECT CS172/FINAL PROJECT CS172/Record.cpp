#include "Record.h"
	
Record::Record(){
	month = 4;
	day = 6; 

}
Record::Record(int newmonth, int newday){
	month = newmonth;
	day = newday;	
}

char Record::getwinOrLoss(){
	return winLoss;
}

	
