#include <iostream>
#include"investment.h"

using namespace std;

// Fuction to return a string with a certain amount of the same character.
string nCharString(int t_length, char t_character) { //Parameter: length, (Number of times character is repeated) / Parameter character (Character to be repeated).
	string returnString;						 //String to be returned.
	for (int i = 0; i < t_length; i++) {			 //Loop 'length' amount of times.  
		returnString += t_character;				 //Adding the 'character' to 'returnString' each time.
	}
	return returnString;						 //Return 'returnString'.

}

//Function to get input from the user returning a new Investment object.
Investment getDataInput() {
	// Initalize needed variables for this function.
	double initialInvestmentAmount = 0;
	double monthlyDeposit = 0;
	double annualIntrest = 0.0001;
	int numberOfYears = 1;
	char continueChar;

	cout << nCharString(36, '*') << endl;
	cout << nCharString(12, '*') << " Data Input " << nCharString(12, '*') << endl; // Calls nCharString() function to print out special characters for formatting purposes.

	cout << "Initial Investment Amount:  $";	// Start inputs of each needed value
	cin >> initialInvestmentAmount;

	cout << "Monthly Deposit:  $";
	cin >> monthlyDeposit;

	cout << "Annual Interest:  %";
	cin >> annualIntrest;

	cout << "Number of years:  ";
	cin >> numberOfYears;						// Ends input of each needed value.

	cout << "Press any key to continue . . ." << endl;
	cin >> continueChar;	// Have user enter any key to continue. 

	if (initialInvestmentAmount < 0 || monthlyDeposit < 0 || annualIntrest < 0.0001 || numberOfYears < 1) { // If any of the inputed values are negative values make them re-enter the values.
		system("CLS");
		cout << "MUST NOT ENTER ANY NEGATIVE INPUTS!!" << endl;
		getDataInput();
	}
	return Investment(initialInvestmentAmount, monthlyDeposit, annualIntrest, numberOfYears);	// Return new Investment object if values are not negative. 
}

//Function to print the calculated data.
void printEnteredDataChart(Investment t_currentUser) {
	cout << endl;
	if (t_currentUser.getMonthlyDeposit() != 0.0) {	// Check if the private monthly deposit variable is not equal to zero.
		cout << "Balance and Interest With Additional Monthly Deposits" << endl;	// Start of printing data for interest with monthly deposits.
		cout << nCharString(57, '=') << endl;
		cout << "Year	  Year End Balance	 Year End Earned Interest" << endl;
		cout << nCharString(57, '-') << endl;
		cout <<endl << "Final Balance: $" << t_currentUser.balanceWithMonthlyDeposit() << endl << endl; // End of printing data for interest with monthly deposits. Also print Final Balance. 
		return;	// If this loop was run, this function is finished so return. 
	}
	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;	// If loop was not run. Start of printing data for interest without monthly deposits.
	cout << nCharString(57, '=') << endl;
	cout << "Year	  Year End Balance	 Year End Earned Interest" << endl;
	cout << nCharString(57, '-') << endl;
	cout << endl << "Final Balance: $" << t_currentUser.balanceWithMonthlyDeposit() << endl << endl; // End of printing data for interest without monthly deposits. Also print Final Balance. 
}

// Function to have user enter 'y' or 'Y' after program finishes to see if they would like to continue using the program. 
void whileOpen() {
	char input = 'y';	// Initiliaze input variable with 'y'.
	while (input == 'y' || input == 'Y') {	// Loop until the input is not 'y' or 'Y'.
		printEnteredDataChart(getDataInput());	// Call function to print calculated data, with a paramater calling getting data input which returns a Investment object.  
		cout << "Would you like to use this program again?" << endl << "Enter 'Y' for yes! If no enter any other character!  ";	// See if user wants to keep using program or not. 
		cin >> input;
		system("CLS");	// Clear screen if they continue.
	}
}

//Main method
int main() {	
	whileOpen();	// Call function to start program loop. 
	return 0;
}

/*
	Naming Conventions:
	"t_" in front of variable means it is a paramater in the function.
	"m_" in front of a variable means it is a private variable of an object
*/