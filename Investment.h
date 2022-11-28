#ifndef Airgead_Banking_App_Investment_h
#define Airgead_Banking_App_Investment_h

// Header file for the object "Investment".
class Investment {
	public:
		// Constructor
		Investment(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears);

		// Functions
		double calculateBalanceWithoutMonthlyDeposit();
		double balanceWithMonthlyDeposit();
		void printDetails(int t_year, double t_yearEndBalance, double t_interestEarned);

		//Getter (Only need to see if monthly deposit is above 0)
		double getMonthlyDeposit();

	private:
		// Variables in object
		double m_initialInvestment;
		double m_monthlyDeposit;
		double m_interestRate;
		int m_numberOfYears;
};
#endif // Airgead_Banking_App_Investment_h

/*
	Naming Conventions:
	"t_" in front of variable means it is a paramater in the function.
	"m_" in front of a variable means it is a private variable of an object
*/