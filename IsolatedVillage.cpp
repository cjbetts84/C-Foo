/*IsolatedVillage.cpp
"Problem 10 - The Most Isolated Village"

In this problem we want to find the village that is farthest
from its closet neighbor. Consider the following distance
matrix that would be placed into a file. Note that many one-
way roads exists and the dinstances between towns are not the
same in each direction.

4
V001 0 10 8 15
V002 10 0 7 22
V003 10 9 0 23
V004 15 22 23 0

The first line in the file contains the number of villages. In
our example, we have four villages. The next four lines gives
information for each village. The first entry is the name of the
village. The remaining entries represent the distance this
village is from its neighbors. In our example, V001 is 10 miles
away from V002, 8 miles from V003, and 15 miles from V004. The
0 entry represents the distance from a village to itself. In
our example, we would comput that V004 is the most isolated
village. It is 15 miles from it's closest neighbor, V001.

Write a program that will read in a file with the format
specified above. Computer for each village how far it is to its
closest neighbor. Also display which is the most isolated village.

Sample Output-
Village   Distance to Closest Neighbor
V001      8
V002      7
V003      9
V004      15
Village V004 is the most isolated village, being 15 miles
from its closest neighbor.

YOUR PROGRAM MAY NOT USE ARRAYS, LISTS, OR SIMILAR DATA STRUCTURES.
You may only read the input file once in your program.
You may not use any disk storage.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void){
	string line = "", chomp = "", thisVillage = "", isolatedVillage = "";
	int villageMin = -1, isolatedMax = -1, distInRow = 0;
	bool nameFlag = true;

	ifstream file;
	file.open("Village2.txt");

	if (file.is_open()){
		cout << "Successfully opened file." << endl;

		getline(file, line);
		int numLines = stoi(line);
		cout << "There are " << numLines << " villages." << endl;

		cout << "Village\tDistance to closest Neighbor" << endl;
		for (int row = 0; row < numLines; row++){
			getline(file, line);
			for (int c = 0; c < line.length(); c++){
				if (line[c] != ' '){	//Compose chomp
					chomp += line[c];
				}
				else{					//Use chomp
					if (nameFlag){			//First chomp is a village name
						thisVillage = chomp;
						chomp = "";
						nameFlag = false;
						cout << thisVillage << "\t";
					}
					else{					//Other chomps in line are distance
						if (distInRow != row){	//Don't compare village to itself
							if (villageMin > stoi(chomp) || villageMin == -1){
								villageMin = stoi(chomp);
							}
						}
						chomp = "";
						distInRow++;
					}
				}
			}
			//Final chomp
			if (distInRow != row){
				if (villageMin > stoi(chomp) || villageMin == -1){
					villageMin = stoi(chomp);
				}
			}

			//Output for row 
			cout << villageMin << endl;
			
			//Compare for being most-isolated
			if ((villageMin > isolatedMax) || (isolatedMax == -1)){
				isolatedMax = villageMin;
				isolatedVillage = thisVillage;
			}

			//Reset testing values
			villageMin = -1;
			nameFlag = true;	
			chomp = "";
			distInRow = 0;
		}//End for(row)

		//Output final result
		cout << "The most isolated village is " << isolatedVillage << ", being " << isolatedMax << "mi from its closest neighbor." << endl;
		file.close();
		cout << "Closed file." << endl;
	}
	else{
		cout << "Error opening file." << endl;
	}

	return 0;
}//end main(void)
