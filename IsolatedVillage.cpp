/*IsolatedVillage.cpp
"Problem 10 - The Most Isolated Village"

In this problem we want to find the village that is farthest
from its closet neighbor. Consider the following distance 
matrix that would be placed into a file. Note that many one-
way roads exists and the dinstances between towns are not the 
same in each direction.

4
V001  0   10  8   15
V002  10  0   7   22
V003  10  9   0   23
V004  15  22  23  0

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
