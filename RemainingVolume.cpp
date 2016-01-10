/*Problem2.cpp
Contractors like to dig rectangular holes to place the circular basins described 
in problem 1 ("Concrete needed.."). After they know how much concrete is needed, they also need to know 
how high the concrete will fill the area around the basin. The figure out how 
much volume is in one vertical foot of their square hole, then subtract off the 
volume taken by one vertical foot of their circular fiberglass basin. This is the 
volume of concrete that will fill on vertical foot of space around the basin.

Write a program that given the length and width of a rectangular hole and the 
vertical height of the basin will display how many cubic yards of concrete to order 
and how high that much concrete will fill the hole outside of the basin. Round to
three decimal places.

The area of a circle with radius r is Area = 3.14159r^2. (We are letting pi = 3.14159).
*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

const double PI = 3.14159;

double volumeOfCylinder(double r, double h);
double volumeOfCube(double l, double w, double h);

int main(void){

	double length, width, height;
	cout << "What is the lenght of the hole in feet? ";
	cin >> length;

	cout << "What is the width of the hole in feet? ";
	cin >> width;

	cout << "What is the height of the basin in feet? ";
	cin >> height;

	double volumeOfHole = volumeOfCube(length, width, height);
	double volumeOfBasin = volumeOfCylinder(2, height);
	double concreteNeeded = height * 8.5;
	double remainingVolume = volumeOfHole - volumeOfBasin;

	cout << "You need to order " << fixed << setprecision(3) << concreteNeeded / 27 << " cubic yards of concrete,\n" 
		<< " which will take " << concreteNeeded / remainingVolume * height << " feet of height on the basin." << endl;

	return 0;
}//end main(void)

double volumeOfCylinder(double r, double h){
	return PI * r * r * h;
}//end volumeOfCylinder(double, double)

double volumeOfCube(double l, double w, double h){
	return l * h * w;
}//end volumeOfCube(double, double, double)
