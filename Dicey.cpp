/*Dicey.cpp
"Problem 9 - Dicey"

To make board games like Monopoly more interesting, we've invented
many-sided dice. That is while a normal die can roll 1 through 6,
we've got dice that can roll 1 or 2, 1 through 3, 1 through 4, etc.
(Ignore how we've managed to make such dice). As usual, the total of
the dice is what counts. In addition, we always use three dice. We
only sell the dice in sets which have all the same number of sides.
So when games are played, all the dice have the same number of sides.
Notice if we use three of the five-sided dice, the possible totals
are 3, 4, 5, ..., 15.

Write a program which when given the number of sides on the dice,
gives the probability of each total as a fraction.

Sample-
Input: The number of faces on each die? 4
Output:
Rolling a 3 has a probability of 1/64
Rolling a 4 has a probability of 3/64
Rolling a 5 has a probability of 6/64
Rolling a 6 has a probability of 10/64
Rolling a 7 has a probability of 12/64
Rolling a 8 has a probability of 12/64
Rolling a 9 has a probability of 10/64
Rolling a 10 has a probability of 6/64
Rolling a 11 has a probability of 3/64
Rolling a 12 has a probability of 1/64
*/

#include <iostream>
#include <math.h>
using namespace std;

int choose(int n, int k);
int probability(int dice, int faces, int sum);

int main(void){

	int faces = 0;
	int numDice = 3;
	int maxRoll;
	int totalCombinations;

	cout << "How many faces per die: ";
	cin >> faces;

	maxRoll = 3 * faces;
	totalCombinations = pow(faces, numDice);

	cout << "Rolling " << numDice << "d" << faces << "." << endl;
	
	cout << "The likelihood of rolling ..." << endl;
	for (int i = numDice; i <= maxRoll; i++){
		cout << "\t" << i << ": " << probability(numDice, faces, i) <<"/" << totalCombinations << endl;
	}
	
	return 0;
}

int choose(int n, int k){
	if (n == k || k == 0){
		return 1;
	}

	return choose(n - 1, k - 1) + choose(n - 1, k);
}

int probability(int dice, int faces, int sum){
	int p = (int)((sum - dice) / faces);
	int count = 0;

	int k = 0;
	do{
		count += pow(-1, k) * choose(dice, k) * choose((sum - faces * k - 1), (dice - 1));
		k++;
	}while (k <= p);

	return count;
}
