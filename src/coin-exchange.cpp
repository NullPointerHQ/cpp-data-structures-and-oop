/* Program Objective: This program will request an amount of money from the user, and then return that same amount in the smallest amount of coins possible
program uses standard US currency therefore the only coins available are 0.25, 0.10, 0.05, 0.01. No dollar or half dollar coins are considered here.*/

//Preprocessor Directives
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){

	//Variable Declarations Block
	const int QUARTERS = 25, DIMES = 10, NICKELS = 5, PENNIES = 1; //Required CONST variables, hold the value of each coin denomination
	int display_quarters = 0, display_dimes = 0, display_nickels = 0, display_pennies = 0;//Display Variables that hold coin quantities
	double monetary_amount = 0;//Given by the user to the system and is the transaction amount
	

	//Gathering the dollar amount from the user.
	cout << "Hello user! today we are going to convert a monetary amount into the minimum amount of coins.\n";
	cout << "Please input a dollar amount, ensuring that you seperate the dollars and cents with a decimal point.\n";
	cout << "$";

	cin >> monetary_amount;//scanf for money amount
	

	//Error Handling, prevents the user from giving too much money or non existent amounts
	if (monetary_amount > 100 || monetary_amount < 0.01) {
		cout << "Invalid Operation detected!\nAmount entered is too much or a negative value\n" << "Terminating Program!";
		exit(1);//Aborts Prog.
	}

	//cout << "Quantity Entered:" << monetary_amount << endl;//Displays entered amount, exists for deubug purposes, disabled to show actual prog. function
	
	int monetary_amount_in_cents = monetary_amount * 100; //Gathers value given by user and converts it to cents
	
	//Coin Conversion Calculations
	//Coin quantities are det. by dividing the total amounts of cents by the value of each coin and then dividing the remaining cents and taking the 
	// remainder
	
	//QUARTERS
	display_quarters = monetary_amount_in_cents / QUARTERS;//Calculates the # of Quarters to give
	monetary_amount_in_cents = monetary_amount_in_cents % QUARTERS;//Gathers the amount of coins remaining
	
	//DIMES
	display_dimes = monetary_amount_in_cents / DIMES;//Calculates the # of the coin denomination
	monetary_amount_in_cents = monetary_amount_in_cents % DIMES;//Gathers the amount of coins remaining
	
	//NICKELS
	display_nickels = monetary_amount_in_cents / NICKELS;//Calculates the # of the coin denomination
	monetary_amount_in_cents = monetary_amount_in_cents % NICKELS;//Gathers the amount of coins remaining
	
	//PENNIES
	display_pennies = monetary_amount_in_cents / PENNIES;//Calculates the # of the coin denomination

	//Calculating Total from the amounts of coins that will be retunred to the user
	int value_check = (display_quarters * QUARTERS) + (display_dimes * DIMES) + (display_nickels * NICKELS) + (display_pennies * PENNIES); 
	monetary_amount_in_cents = monetary_amount * 100;//Recalculating original total cents
	
	//Disabled to minimize burden to user, meant for debug.
	//cout << "Value Check Value: " << value_check <<"monetary amount in cents: " << monetary_amount_in_cents << endl;

	//Checks if values match
	if (value_check != monetary_amount_in_cents)
	{
		display_pennies++;
	}
	
	cout << "Coin conversion successful!\n" << "Original Amount: " << monetary_amount << endl << "Please expect your payout in the following amounts : \n";

	//Coin Count Display Block
	cout << "Quarters:" << display_quarters << endl;
	cout << "Dimes:" << display_dimes << endl;
	cout << "Nickels:" << display_nickels << endl;
	cout << "Pennies:" << display_pennies << endl;

	return 0;
}
