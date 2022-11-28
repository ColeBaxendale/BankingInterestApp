#include "Investment.h"
#include <iostream>
#include <iomanip>

using namespace std;

//C++ File for the object "Investment".
//Constructor for the object "Investment".
Investment::Investment(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears){ // Can only create object with values for the four parameters no need for a default constructor. 
    this-> m_initialInvestment = t_initialInvestment;
    this-> m_monthlyDeposit = t_monthlyDeposit;
    this-> m_monthlyDeposit = t_monthlyDeposit;
    this-> m_interestRate = t_interestRate;
    this-> m_numberOfYears = t_numberOfYears;
    // Set the object's private values to the parameter values.
}

// Function to calculate the balance without monthly deposits.
double Investment::calculateBalanceWithoutMonthlyDeposit(){ // Return double value, this value is the final balance.
    double balance = m_initialInvestment; // Initialize balance to the initital investment private variable. 
    for (int yearIndex = 1; yearIndex <= m_numberOfYears; yearIndex++) {    // For loop to index through the amount of years inputted by user, starting at one.
        double interestEarnedThisYear = 0;  // Reset year's earned intrest after each year is calculated.
        for (int month = 1; month <= 12; month++) { // For loop to loop through all twelve months of the year so we can compound intreset monthly.
            double monthlyInt = balance * ((m_interestRate / 100.0) / 12);  // Calculate the interest for the current month.
            interestEarnedThisYear += monthlyInt;   // Add each month to the years interest earned variable.
            balance += monthlyInt;  // Add each month's interest to the user's balance. 
        }
        printDetails(yearIndex, balance, interestEarnedThisYear);   // Call function to print the current years information calculated. 
    }
    return balance;  // Return the final balance. 
}

// Function to calculate the balance with monthly deposits.
double Investment::balanceWithMonthlyDeposit(){ // Return double value, this value is the final balance.
    double balance = m_initialInvestment;   // Initialize balance to the initital investment private variable. 
    for (int yearIndex = 1; yearIndex <= m_numberOfYears; yearIndex++) {    // For loop to index through the amount of years inputted by user, starting at one.
        double interestEarnedThisYear = 0;  // Reset year's earned intrest after each year is calculated.
        for (int month = 1; month <= 12; month++) { // For loop to loop through all twelve months of the year so we can compound intreset monthly.
            double monthlyInt = balance * ((m_interestRate / 100.0) / 12);  // Calculate the interest for the current month.
            interestEarnedThisYear += monthlyInt;   // Add each month to the years interest earned variable.
            balance += monthlyInt + m_monthlyDeposit;   // Add each month's interest to the user's balance along with adding in the private monthly deposit variable.
        }
        printDetails(yearIndex, balance, interestEarnedThisYear);   // Call function to print the current years information calculated.
    }
    return balance;  // Return the final balance.
}

// Function to print the details of each year's values.
void Investment::printDetails(int t_year, double t_yearEndBalance, double t_interestEarned){    // Have three paramaters of the information needed to be printed.
    // Some if / else if / else statements to help format the final values better. 
    if(t_year < 10 && t_yearEndBalance < 1000)
        cout << t_year << "            $" << setprecision(2) << fixed << t_yearEndBalance << "                   $" << setprecision(2) << fixed << t_interestEarned << endl;
    else if(t_yearEndBalance > 1000 && t_year < 10)
        cout << t_year << "            $" << setprecision(2) << fixed << t_yearEndBalance << "                  $" << setprecision(2) << fixed << t_interestEarned << endl;
    else if(t_yearEndBalance < 1000 && t_year >= 10)
        cout << t_year << "           $" << setprecision(2) << fixed << t_yearEndBalance << "                   $" << setprecision(2) << fixed << t_interestEarned << endl;
    else
        cout << t_year << "           $" << setprecision(2) << fixed << t_yearEndBalance << "                  $" << setprecision(2) << fixed << t_interestEarned << endl;
}

// Getter function to return the private monthly deposits variable. 
double Investment::getMonthlyDeposit(){
    return  m_monthlyDeposit;
}

/*
    Naming Conventions:
    "t_" in front of variable means it is a paramater in the function.
    "m_" in front of a variable means it is a private variable of an object
*/
