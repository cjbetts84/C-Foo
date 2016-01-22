/* Anagrams.cpp
"Problem 7 - Anagrams"

An anagram is a word or phrase that can be created from a second word
or phrase by rearranging the letters. For example STEP is an anagram
of PEST. Another way of stating this is that two phrases are anagrams
of one another if they consist of exactly the same letters while
ignoring spaces.

Write a program which accepts two phrases and reports whether they are
anagrams. Your program needs to accept a pair of phrases and output a
message indicating if the words or phrases are anagrams. Upper and
lowercase letters are considered equivalent for this problem. Only
letters (A to Z) are considered in determining if two phrases are anagrams.

Sample-
Input / Input - Output
HAT  /  Cat - Not anagrams
dormitory / dirty room - anagrams
POLL / Pool - not anagrams
*/

#include <iostream>
#include <string>
using namespace std;

int main(void){

	string userInput1, userInput2 = "";	//User will enter two phrases to compare
	int alphabet1[26], alphabet2[26];	//To count all the A, count all the B...
	int asciiVal = 0;					//65 = A, 66 = B, ..., 90 = Z
	bool anagramFlag = true;			//Assume phrases are equivalent until proven false
	
	//Preset both alphabet arrays to all-zero values
	for (int i = 0; i < 26; i++){
		alphabet1[i] = 0;
		alphabet2[i] = 0;
	}//end for

	//Get user inputs
	cout << "What's your first input phrase: ";
	getline(cin, userInput1);

	cout << "What's your second input phrase: ";
	getline(cin, userInput2);

	//Turn all characters to uppercase, and count appropriately
	for (int i = 0; i < userInput1.length(); i++){
		userInput1.at(i) = toupper(userInput1.at(i));
		//Only care about characters 65-90, A-Z
		if (userInput1.at(i) >= 65 && userInput1.at(i) <= 90){
			asciiVal = userInput1.at(i) - 65;	//0=A, 1=B, ..., 25=Z
			alphabet1[asciiVal]++;
		}//end if
	}//end for

	for (int i = 0; i < userInput2.length(); i++){
		userInput2.at(i) = toupper(userInput2.at(i));
		//Only care about characters 65-90, A-Z
		if (userInput2.at(i) >= 65 && userInput2.at(i) <= 90){
			asciiVal = userInput2.at(i) - 65;	//0=A, 1=B, ..., 25=Z
			alphabet2[asciiVal]++;
		}
	}//end for

	//Compare our two alphabet counters
	for (int i = 0; i < 26; i++){
		if (alphabet1[i] != alphabet2[i]){
			anagramFlag = false;
			break;
		}//end if
	}//end for

	cout << "You entered the phrases: " << userInput1 << " and " << userInput2 << "." << endl;

	if (anagramFlag == true)
		cout << "These phrases are anagrams." << endl;
	else
		cout << "These phrases are NOT anagrams." << endl;

	return 0;
}//end main(void)
