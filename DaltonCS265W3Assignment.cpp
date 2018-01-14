/*******************
  *
  * Deric Dalton
  * G00129003
  * CS265
  * Week 3
  *
  */

#include <iostream>
#include <iomanip>
#include <string>

/********************
  *
  *  CLASSES 
  *
  */

class Customer {
		std::string fName ;
		std::string lName ;
		std::string fullName ;
		unsigned int acctNum ;
	public:
		/* Setters  */
		void set_name (std::string x, std::string y) {
			fName = x ;
			lName = y ;
			fullName = fName + " " + lName ;
		}
		void set_acctNum (unsigned int x) {
			acctNum = x ;
		}
		/* Getters  */
		std::string ret_fullName () {
			return fullName ;
		}
		unsigned int ret_acctNum () {
			return acctNum ;
		}
} cust;

class StdBill { /* all functions are inline  */
		const float STDSVC = 10.00 ;
		const float RATE = 00.20 ;
		const float FREEMIN = 50.00 ;
		float mins ;
		float billedMins ;
		float subTotal ;
		float total ;
	public:
		/* Setter  */
		void set_mins (float f) {
			mins = f ;
			if (mins <= FREEMIN)
					billedMins = 0 ;
			else
					billedMins = (mins - FREEMIN) ;
		}
		/* Getters  */
		float minsBilled () {
			return mins ;
		}
		float ret_mins () {
			return mins ;
		}
		float ret_billedMins () {
			return billedMins ;
		}
		float ret_STDSVC () {
			return STDSVC ;
		}
		float ret_RATE () {
			return RATE ;
		}
		float ret_FREEMIN () {
			return FREEMIN ;
		}
		/***
		 Calculate the bill and don't charge
		 by the min if mins are below or equal
	     to the FREEMINS of the plan.	
		 */
		float totalBill () {
			if (mins <= FREEMIN){
					total = STDSVC ;
					return total ;
			}
			else {
				billedMins = (mins - FREEMIN) ;
				subTotal = (billedMins * RATE) ;
				total = (subTotal + STDSVC) ;
				return total ;
			}
		}

} standard;

class PremBill { /* all functions are inline  */
		const float PREMSVC = 25.00 ;
		const float DAYRATE = 00.10 ;
		const float NIGHTRATE = 00.05 ;
		const float DAYFREE = 75.00 ;
		const float NIGHTFREE = 100.00 ;
		float dayMins ;
		float nightMins ;
		float billedDay ;
		float billedNight ;
		float subTotDay ;
		float subTotNight ;
		float total ;
	public:
		/* Setter  */
		void set_mins (float x, float y) {
			dayMins = x ;
			nightMins = y ;
			if (dayMins <= DAYFREE)
					billedDay = 0 ;
			else
					billedDay = (dayMins - DAYFREE) ;
			if (nightMins <= NIGHTFREE)
					billedNight = 0;
			else
					billedNight = (nightMins - NIGHTFREE) ;
		}
		/* Getters  */
		float ret_dayMins () {
			return dayMins ;
		}
		float ret_nightMins () {
			return nightMins ;
		}
		float ret_billedDay () {
			return billedDay ;
		}
		float ret_billedNight () {
			return billedNight ;
		}
		float ret_PREMSVC () {
			return PREMSVC ;
		}
		float ret_DAYRATE () {
			return DAYRATE ;
		}
		float ret_NIGHTRATE () {
			return NIGHTRATE ;
		}
		float ret_DAYFREE () {
			return DAYFREE ;
		}
		float ret_NIGHTFREE () {
			return NIGHTFREE ;
		}
		/***
		 Calculate the bill and don't charge
		 by the min if mins are below or equal
	     to the FREEMINS of the plan.	
		 */	
		float totalBill () {
			if (dayMins <= DAYFREE)
			{
				subTotDay = 0.0 ;
			}
			else {
				billedDay = (dayMins - DAYFREE) ;
				subTotDay = (billedDay * DAYRATE) ;
			}
			if (nightMins <= NIGHTFREE) {
				subTotDay = 0.0 ;
			}
			else {
				billedNight = (nightMins - NIGHTFREE) ;
				subTotNight = (billedNight * NIGHTRATE) ;
			}
			total = (subTotDay + subTotNight + PREMSVC) ;
			return total ;
		}
} prem;

class StdInvoice {
		std::string stars = std::string(20, '*') ;
		std::string stars2 = std::string(53, '*') ;
		std::string line1 = "\n\nInvoice for: " ;
		std::string line2 = "Account number: " ;
		std::string line3 = "Account type: Standard Account\n$10 a month.\n" 
							"First 50  mins free, rate .20cents per min.\n" ;
		std::string line4 = "Minutes used: " ;
		std::string line5 = "Total amount due: $" ;
	public:
		void print_invoice () {
			std::cout << std::fixed << std::setprecision(2) ;
			std::cout << "\n\n\n" << stars2 << "\n" ;
			std::cout << stars << " THE INVOICE " << stars << "\n" ;
			std::cout << stars2 ;		
			std::cout << line1 << cust.ret_fullName() << std::endl ;
			std::cout << line2 << cust.ret_acctNum() << std::endl ;
			std::cout << line3 << std::endl ;
			std::cout << line4 << standard.ret_mins() 
					  << " Billed minutes: " 
					  << standard.ret_billedMins() << std::endl ;
			std::cout << line5 << standard.totalBill() << std::endl ;
			std::cout << "\n" << stars2 << "\n" << stars2 << "\n\n\n" << std::endl ;	
		}
} sInvoice;

class PremInvoice {
		std::string stars = std::string(25, '*') ;
		std::string stars2 = std::string(63, '*') ;
		std::string line1 = "\n\nInvoice for: " ;
		std::string line2 = "Account number: " ;
		std::string line3 = "Account type: Premium Account\n$25 a month.\n"
	                        "First 75 daytime mins free, daytime rate .10cents per min.\n"
                            "First 100 nighttime mins free, nighttime rate .05cents per min.\n" ;
	    std::string line4 = "Daytime minutes: " ;
		std::string line5 = "Nighttime minutes: " ;
		std::string line6 = "Total amount due: $" ;

	public:
		void print_invoice () {
			std::cout << std::fixed << std::setprecision(2) ;
			std::cout << "\n\n\n" << stars2 << "\n" ;
			std::cout << stars << " THE INVOICE " << stars << "\n" ;
			std::cout << stars2 ;
			std::cout << line1 << cust.ret_fullName() << std::endl ;
			std::cout << line2 << cust.ret_acctNum() << std::endl ;
			std::cout << line3 << std::endl ;
			std::cout << line4 << prem.ret_dayMins() << " Billed day minutes: "
					  << prem.ret_billedDay() << std::endl ;
			std::cout << line5 << prem.ret_nightMins() << " Billed night minutes: " 
					  << prem.ret_billedNight() << std::endl ;
			std::cout << line6 << prem.totalBill() << std::endl ;
			std::cout << "\n" << stars2 << "\n" << stars2 << "\n\n\n" << std::endl ;		
		}
} pInvoice;

/********************
  *
  *  METHOD PROTOS 
  *
  */

void menu() ;
void instructions() ;
void makeStandard() ;
void makePremium() ;

/********************
  *
  *  MAIN METHOD 
  *
  */

int main(void)
{
	menu() ;
	return 0 ;
}

/********************
  *
  *  METHOD DEFS 
  *
  */

void menu() { 
/* char for switch statement to control menu  */
char c = ' ' ;

	while (true) {
		instructions() ;
		std::cin >> c ;
		switch (c) {
			case 's':
			case 'S':	makeStandard() ;
						continue ;
			case 'p':
			case 'P':	makePremium() ;
						continue ;
			case 'q':
			case 'Q':	std::cout << "Thank you for using this program.  Goodbye!\n" ;
						break ;

			default:	std::cout << "I'm sorry, " << c << " isn't a valid choice.\n" ;
						std::cout << "Please try again!\n\n" ;
						continue ;
		}
	break ;
	}
}


void instructions () {
	std::string stars = std::string(24, '*') ;
	std::string menuBar = stars + " THE MENU " + stars + "\n" ;
	std::string line1 = "Please enter your choice from the following menu options:\n" ;
	std::string line2 = "Enter 's' for standard account\n" ;
	std::string line3 = "Enter 'p' for premium account\n" ;
	std::string line4 = "Enter 'q' to quit\n" ;

	std::cout << menuBar << std::endl ;
	std::cout << line1 << std::endl ;
	std::cout << line2 << std::endl ;
	std::cout << line3 << std::endl ;
	std::cout << line4 << std::endl ;
	std::cout << menuBar << std::endl ;	
}

void makeStandard () {
	std::string s1, s2 ;
	unsigned int ui ;
	float f ;

	std::cout << "Please enter your first and last name: " ;
	std::cin >> s1 ;
    std::cin >>	s2 ;
	std::cout << "Please enter your account number: " ;
	std::cin >> ui ;
	std::cout << "\nThank you, " << s1 << " " << s2 << "." ;
	std::cout << "\nPlease enter in your minutes for this billing cycle: " ;
	std::cin >> f ;
	
	cust.set_name(s1, s2) ;
	cust.set_acctNum(ui) ;
	standard.set_mins(f) ;
	sInvoice.print_invoice() ;
}

void makePremium () {
	std::string s1, s2 ;
	unsigned int ui ;
	float f1, f2 ;

	std::cout << "Please enter your first and last name: " ;
	std::cin >> s1 ;
	std::cin >>	s2 ;
	std::cout << "Please enter your account number: " ;
	std::cin >> ui ;
	std::cout << "\nThank you, " << s1 << " " << s2 << "." ;
	std::cout << "\nPlease enter in your day minutes for this billing cycle: " ;
	std::cin >> f1 ;
	std::cout << "\nPlease enter in your night minutes for this billing cycle: " ;
	std::cin >> f2 ;
	
	cust.set_name(s1, s2) ;
	cust.set_acctNum(ui) ;
	prem.set_mins(f1, f2) ;
	pInvoice.print_invoice() ;
}

