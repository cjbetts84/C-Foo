/* ReversePolish.cpp

"Problem 8 - Reverse Polish Notation

In reverse polish notation (RPN or post-fix notation), the operators are listed
after the numbers. No parentheses are required since the order of operation
evaluation is determined by the placement of the operators. The operation is
performed on the two nearest complete expressions to the left of the operator.

For example the RPN expression "2 5 3 - * 4 /" can only be interpreted as
(2*(5-3))/4, and therefore evaluates to 1. The RPN expression "2 5 3 4 - * /"
must be interpreted as 2/(5*(3-4)), and would evaluate to -0.4000.

Write a program to evaluation RPN expressions. The answer may not be an integer.
Round off the answer to display the first four digits to the right of the
decimal point.

Sample-
Input: 3 3 / 5 + 7 *
Output 42 (Or 42.0000)

Additional note-
In the example "2 5 3 - * 4 /", we have as input a 2, followed by a 5, followed
by a 3. Now we reach the subtraction operator in the sequence of symbols. Since
the last two operands we parsed were a 5 and a 3, we preform the operation 5-3.
This gives a result of 2, which replaces the "5 3 -" sequence of symbols. Now
our current set of operands are 2 and 2. The next operator is a "*", so we
computer 2*2, and place the 4 as the only operand we currently have available
to us. We parse the next symbol, which is a "4" to give us two operands. We parse
the division symbol next and computer 4/4 which is 1. Since we have no more
symbols, the answer is 1.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(void){
	string userInput, chomp = "";
	double output = 0.0;
	double operands[26];
	int counter = 0;

	for (int i = 0; i < 26; i++){
		operands[i] = 0;
	}

	cout << "Input string: ";
	getline(cin, userInput);

	//Chomp userInput
	for (int i = 0; i < userInput.length(); i++){
		//Pop the last two operands
		switch (userInput[i]){
			case ' ':
				if (chomp != ""){
					operands[counter++] = stoi(chomp);
					chomp = "";
				}
				break;
			case '+': output = (operands[counter - 2] + operands[counter - 1]); 
				operands[--counter] = 0;
				operands[counter - 1] = output;
				output = 0.0;
				break;
			case '-': output = (operands[counter - 2] - operands[counter - 1]);
				operands[--counter] = 0;
				operands[counter - 1] = output;
				output = 0.0;
				break;
			case '*': output = (operands[counter - 2] * operands[counter - 1]);
				operands[--counter] = 0;
				operands[counter - 1] = output;
				output = 0.0;
				break;
			case '/': output = (operands[counter - 2] / operands[counter - 1]);
				operands[--counter] = 0;
				operands[counter - 1] = output;
				output = 0.0; 
				break;
			default: 				
				chomp += userInput[i];
				break;
		}
	}

	cout << userInput << " evaluates to: " << fixed << setprecision(4) << operands[0] << endl;

	return 0;
}//end main(void)
