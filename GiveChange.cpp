/* Problem # - Giving Change
Write a program that calculates the most efficient change to be given when 
supplied two string representing the total cost and amount given. For this
problem, assume that input will always have a dollar sign, and there will 
always be some amount of change due.
*/

#include <iostream> //cout, cin
#include <string>	//stod
#include <iomanip>	//setprecision
using namespace std;

int main(void){

	string total_s, paid_s = "";
	double total_d, paid_d, change = 0.0;
	int twenty, ten, five, one, quarter, dime, nickel = 0;

	cout << "What's the total? ";
	getline(cin, total_s);

	cout << "What was paid? ";
	getline(cin, paid_s);

	total_d = stod(total_s.substr(1, total_s.length()));
	paid_d = stod(paid_s.substr(1, paid_s.length()));
	change = paid_d - total_d;

	cout << "Total: " << setprecision(2) << fixed << total_d << "\tPaid: " << setprecision(2) << fixed << paid_d << endl;
	cout << "Change due: " << setprecision(2) << fixed << change << endl;

	twenty = change / 20;
	change -= 20 * twenty;
	if (twenty != 0)
		cout << "\t" << twenty << " twenties" << endl;

	ten = change / 10;
	change -= 10 * ten;
	if (ten != 0)
		cout << "\t" << ten << " tens" << endl;

	five = change / 5;
	change -= 5 * five;
	if (five != 0)
		cout << "\t" << five << " fives" << endl;

	one = change / 1;
	change -= one;
	if (one != 0)
		cout << "\t" << one << " ones" << endl;

	quarter = change / .25;
	change -= .25 * quarter;
	if (quarter != 0)
		cout << "\t" << quarter << " quarters" << endl;

	dime = change / .1;
	change -= .1 * dime;
	if (dime != 0)
		cout << "\t" << dime << " dimes" << endl;

	nickel = change / .05;
	change -= .05 * nickel;
	if (nickel != 0)
		cout << "\t" << nickel << " nickels" << endl;

	if (change != 0)
		cout << "\t" << (int)(change * 100) << " pennies" << endl;

	return 0;
}//end main(void)
