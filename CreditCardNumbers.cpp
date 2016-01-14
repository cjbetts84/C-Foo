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

For example, consider the credit card number 5562 2343 8874 1059. 
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
four numbers.Your program must accept this input format.

Sample:
Input : 556 234 887 105
Output : 5562 2343 8874 1059
*/
