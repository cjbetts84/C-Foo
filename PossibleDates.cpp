/*PossibleDates.cpp
"Problem 5 - Possible Dates"

Dates frequently are written in the form nn/nn/nn, where nn represents a two digit
number. The values for the month, day and year can occur in any order. However,
sometimes the values given in a particular input can be used to limit the possible
dates represented. For exampl, 02/03/57 represents either February 3 or March 2 in
a year ending in 57. 

Write a program which takes a string in the format nn/nn/nn and outputs all the 
possible legal dates between January 1, 1951 and December 31, 2050 that it could
represent.

Sample Data-
Date Entered: 05/18/27
Possible dates between 1/1/1951 and 12/31/2050:
	May 18, 2027
	May 27, 2018

You must accept the input format specified (nn/nn/nn).
If the input does not describe a legal date, output a message stating so.
A particular date may only appear once in the output list for a given input.

The dates must contain the name of the month, the day of the month (one or two
digit) and the year (four digit). These should be separated by one space with a
comma after the day.

For this exercise, a year is a leap year if and only if it is divisible by four.
*/

#include <iostream>
#include <string>
using namespace std;

void dateInWords(int month, int day, int year);

int main(void){

	string userInput = "";
	int first, second, third = 0;

	//Get user input
	cout << "Enter a date: ";
	getline(cin, userInput);

	//Parse out the 2-digit pairs
	first = stoi(userInput.substr(0, 2));
	second = stoi(userInput.substr(3, 2));
	third = stoi(userInput.substr(6, 2));

	//Rule out duplicates
	
	//Notify of no valid dates

	//Display dates
	

	return 0;
}//end main()


void dateInWords(int month, int day, int year){	
	//Modify year for 1951 through 2050
	if (year >= 100)
		year == -1; //put year into error state
	else if(year <= 50)
		year += 2000;
	else
		year += 1900;

	if (year != -1){//only if valid year
		switch (month){
		case 1:
			if (day <= 31)
				cout << "January " << day << ", " << year << endl;
				break;
		case 2:
			if (year / 4 == 0 && day <= 29)
				cout << "February " << day << ", " << year << endl;
			else if (day <= 28)
				cout << "February " << day << ", " << year << endl;
			break;
		case 3:
			if (day <= 31)
				cout << "March " << day << ", " << year << endl;
			break;
		case 4:
			if (day <= 30)
				cout << "April " << day << ", " << year << endl;
			break;
		case 5:
			if (day <= 31)
				cout << "May " << day << ", " << year << endl;
			break;
		case 6:
			if (day <= 30)
				cout << "June " << day << ", " << year << endl;
			break;
		case 7:
			if (day <= 31)
				cout << "July " << day << ", " << year << endl;
			break;
		case 8:
			if (day <= 31)
				cout << "August " << day << ", " << year << endl;
			break;
		case 9:
			if (day <= 30)
				cout << "September " << day << ", " << year << endl;
			break;
		case 10:
			if (day <= 31)
				cout << "October " << day << ", " << year << endl;
			break;
		case 11:
			if (day <= 30)
				cout << "November " << day << ", " << year << endl;
			break;
		case 12:
			if (day <= 31)
				cout << "December " << day << ", " << year << endl;
			break;
		}//end switch(month)
	}//end if(year != -1)
}//end dateInWords()
