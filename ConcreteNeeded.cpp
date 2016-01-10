/*ConcreteNeeded.cpp
"Problem 1 - Concrete needed to hold down a fiberglass basin."

A local contractor needs to place a four-foot diameter fiberglass basin into the 
ground to collect rain water. These basins are very light and will actually push 
out of the ground when they are empty. Contractors pour cement around the basin 
to hold it in the ground. Testing has indicated that it takes 8.5 cubic feet of 
concrete per vertical foot of a four-foor diameter basin to hold it in the ground. 
This means a 10 foot tall basin will need 85 cubic feet of concrete to hold it in 
the ground. Concrete is sold by the cubic yard, so contractors must convert cubic 
feet to cubic yards.

Write a program that accepts the height of a fiberglass basin and displays the 
cubic yards of concrete that the contractor must use to hold that basin in the 
ground. The height of the basin will be an integer. Round output to three points.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(void){

	int height = 0;
	cout << "How many feet tall is the fiberglass basin?";
	cin >> height;

	cout << "You need " << fixed << setprecision(3) << (height  * 8.5) / 27 << " cubic yards of concrete." << endl;

	return 0;
}//end main(void)
