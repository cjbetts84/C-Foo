/*CreditCardNumbers.cpp
"Problem 6 - Credit Card Numbers"

Credit card numbers are normally devised with extra information which is used
to help ensure the validity of numbers.Suppose a credit card company identifies
its cards with four, three-digit numbers. The actual card has four, four-digit
numbers where each of the original three-digit numbers has an extra digit
added so that the following properties hold.

(Rule 1) The first four-digit number is divisible by three.
(Rule 2) The sum of the first two four-digit numbers is divisible by five.
(Rule 3).The sum of the first three four-digit numbers is divisible by 7.
(Rule 4) The sum of all four of the four-digit numbers is divisible by 9.

For example, consider the credit card number 5562 2343 8874 1059:
Note that 5562 is divisible by 3 (Rule 1), 5562 + 2343 = 7905 is divisible
by 5 (Rule 2), 5562 + 2343 + 8874 = 16779 is divisible by 7 (Rule 3), and
5562 + 2343 + 8874 + 1059 = 17838 is divisible by 9 (Rule 4). The actual
identification given to the credit card company would be 556 234 887 105.
These 16 digits would be considered valid by the four rules listed above.

Write a program which accept an identification number consisting of four,
three-digit numbers and returns a valid credit card number which conforms to the
four rules given above and also implements the following restrictions.

(Rule 5) The digit added at the end of the first 3-digit number must be 2, 7, or 9.
(Rule 6) The digit added at the end of the second 3-digit number must be 3, 4, 5, 6, or 7.
(Rule 7) The digit added at the end of the third 3-digit number must be 1, 3, 4, 5, 6, 7, or 9.
(Rule 8) The digit added at the end of the fourth 3-digit number must be 1, 2, 3, 4, 5, 6, 7, 8, or 9.

The credit card number is entered on one line with blank spaces separating the
four numbers. Your program must accept this input format.

Sample:
Input : 556 234 887 105
Output : 5562 2343 8874 1059
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool firstBlock(int& first, int& second, int& third, int& fourth);
bool secondBlock(int& first, int& second, int& third, int& fourth);
bool thirdBlock(int& first, int& second, int& third, int& fourth);
bool fourthBlock(int& first, int& second, int& third, int& fourth);

int main(void){

	string inputCode = "";
	int first, second, third, fourth = 0;

	//Get user input
	cout << "Identification Number: ";
	getline(cin, inputCode);

	//Chomp out the 3-digit sets
	first = stoi(inputCode.substr(0, 3));
	second = stoi(inputCode.substr(4, 3));
	third = stoi(inputCode.substr(8, 3));
	fourth = stoi(inputCode.substr(12, 3));

	//Turn the 3-digits into 4-digits
	first *= 10;
	second *= 10;
	third *= 10;
	fourth *= 10;

	if (firstBlock(first, second, third, fourth)){
		cout << setfill('0') << setw(4) << first << " " << setfill('0') << setw(4) << second << +" "
			<< setfill('0') << setw(4) << third << +" " << setfill('0') << setw(4) << fourth << endl;
	}
	else
		cout << "Bad input. No valid number to generate." << endl;

	return 0;
}//end main(void)

/*Attempts to find a digit (2, 7, 9) which makes the first 4-digit block
divisible by 3. Returns true if this rule holds and if all subsequent calls 
also return true. Returns false if the first block is not divisible by 3, 
or if all subsequent combinations also fail. */
bool firstBlock(int& first, int& second, int& third, int& fourth){

	//Attempt 1st block ending in 2, 7, 9, with subsequent 2nd block
	if ((first + 2) % 3 == 0){
		first += 2;
		if(secondBlock(first, second, third, fourth))
			return true;
		first -= 2;
	}
	else if ((first + 7) % 3 == 0){
		first += 7;
		if (secondBlock(first, second, third, fourth))
			return true;
		first -= 7;
	}
	else if ((first + 9) % 3 == 0){
		first += 9;
		if (secondBlock(first, second, third, fourth))
			return true;
		first -= 9;
	}
	else{ //Report failure
		return false;
	}//end if

}//end firstBlock(int&, int&, int&, int&)

/*Attempts to find a final digit (3-7) in the 2nd block which allows the 
sum of the 1st and 2nd 4-digit blocks to be divisible by 5. Returns true 
if these rules hold, and if subsequent calls return true; otherwise the 
return is false.*/
bool secondBlock(int& first, int& second, int& third, int& fourth){

	//Try 2nd ending in 3-7, with subsequent 3rd block
	for (int i = 3; i <= 7; i++){
		if (((second + i) + first) % 5 == 0){
			second += i;
			if (thirdBlock(first, second, third, fourth)){
				return true;
			}
			second -= i;
		}
	}

	//Report failure
	return false;

}//end secondBlock(int&, int&, int&, int&)

/*Attempts to find a final digit (1, 3-7, 9) in the 3rd block which 
allows the sum of the first three 4-digit blocks to be divisible by
7. Returns true if these rules hold and if the subsequent calls also
return true; otherwise the return is false.*/
bool thirdBlock(int& first, int& second, int& third, int& fourth){
	int sum = first + second;

	//Try 3rd ending in 1 with subsequent 4th block
	if (((third + 1) + sum) % 7 == 0){
		third += 1;
		if (fourthBlock(first, second, third, fourth)){
			return true;
		}
		third -= 1;
	}
	
	//Try combinations of 3rd ending in 3-7 with subsequent 4th block
	for (int i = 3; i <= 7; i++){
		if (((third + i) + sum) % 7 == 0){
			third += i;
			if (fourthBlock(first, second, third, fourth)){
				return true;
			}
			third -= i;
		}
	}

	//Try 3rd ending in 9 with subsequent 4th block.
	if (((third + 9) + sum) % 7 == 0){
		third += 9;
		if (fourthBlock(first, second, third, fourth)){
			return true;
		}
		third -= 9;
	}

	//Report failures
	return false;

}//end thirdBlock(int&, int&, int&, int&)

/*Attempts to find a valid final digit (1-9) for the fourth block of 
4-digit numbers such that the sum of all four 4-digit blocks is 
divisible by 9. Returns true if these rules hold; otherwise it returns
false.*/
bool fourthBlock(int& first, int& second, int& third, int& fourth){
	
	int sum = first + second + third;
	
	//Attempt all values of fourth block
	for (int i = 1; i <= 9; i++){
		if (((fourth + i) + sum) % 9 == 0){
			fourth += i;
			return true;
		}
	}

	//Report failure
	return false;

}//end fourthBlock(int& int&, int&, int&)
