/********************
 * Deric Dalton
 * G00129003
 * CS265
 * Week 4 Assignment
 ********************/

#include <iostream>
#include <string>
#include <algorithm> // ::transform


////////////////////
/* FUNCTION DECLS */
////////////////////
void menu() ;
void phoneNumber() ;
std::string getNum() ;
std::string makeUpper(std::string) ;
std::string toNumber(std::string) ;
std::string trimNumber(std::string) ;
std::string addHyphen(std::string) ;


//////////////////
/*  MAIN METHOD */
//////////////////
int main(void)
{
	menu() ;
	return 0 ;
}


////////////////////////////////////////////////////
/* PROGRAM TERMINATES WHEN THIS METHOD IS EXITED  */
////////////////////////////////////////////////////
void menu()
{
	char c ;
	while (true)
	{
		std::cout << "Welcome to \"Make a Number\"" << std::endl ;
		std::cout << "Please selct 'Y' to continue, 'Q' to quit." << std::endl ;
		std::cin >> c ;
		switch (c)
		{
			case 'y':
			case 'Y':	phoneNumber() ;
						continue ;

			case 'q':
			case 'Q':	std::cout << "Thank you for using the program.\n" ;
						std::cout << "Good bye!\n" << std::endl ;
						break ;

			default:	std::cout << "I'm sorry, that's not a valid choice!\n" ;
						std::cout << "Please try again!\n" << std::endl ;
						continue ;
		}
	break ;
	}
}


///////////////////////////////////////////////////////////
/* PHONE NUMBER CALLS OTHER METHODS TO BUILD THE NUMBER  */
///////////////////////////////////////////////////////////
void phoneNumber()
{
	std::string ph_num = getNum() ;

	ph_num = makeUpper(ph_num) ;

	ph_num = toNumber(ph_num) ;

	ph_num = trimNumber(ph_num) ;

	ph_num = addHyphen(ph_num) ;

	std::cout << "\n\nYour phone number is: " << ph_num << "\n" << std::endl ;
}


/////////////////////
/* GET THE PHRASE  */
/////////////////////
std::string getNum()
{
	std::string s ;
	std::cin.ignore() ;  /* ignores default value 
							of s so that it can 
							be collected by the user. */
	
	int sLength = 0 ; // will control the loop validating s size
	do
	{
		std::cout << "Please type the phrase you want as a telephone number.\n" ;
		std::cout << "Phrase must be at least 7 chars long.\n" ;
		std::cout << "Spaces, special chars and puncuation will not count.\n" ;
		std::getline(std::cin, s) ;
		
		/* The following for loop will count only alpha/numeric 
		   chars all other chats will not be handled.  
		   This is to ensure that the min length of acceptable 
		   chars is at least 7 chars long  */
		for (std::string::size_type i = 0; i <s.size(); ++i)
		{
				if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
				{	
					sLength++ ;
					continue ;
				}
				else if (s[i] >= '0' && s[i] <= '9')
				{
					sLength++ ;
					continue ;
				}
		}
		
		/* If the length of s is un 7, the user will be reminded of min length  */
		if (sLength < 7)
		{
			std::cout << "\n!!! Your phrase must be at least 7 chars long !!!\n" ;
			sLength = 0 ;
		}

	} while (!(sLength >= 7)) ;  /* will continue to 
									prompt for input 
									until min length 
									is reached */

	std::cout << "Thank you, processing your number..." << std::endl ;
	
	return s ;
}


/////////////////////////
/* TOLOWER THE PHRASE  */
/////////////////////////
std::string makeUpper(std::string str)
{
	std::string s = str ;
	/* shift case to lower for easier processing
	   Lower since it is assumed that there will 
	   be less uppers to make lower */
	std::transform(s.begin(), s.end(), s.begin(), ::tolower) ;
	
	return s ;	
}


////////////////////////////////
/* CONVERT PHRASE TO NUMBERS  */
////////////////////////////////
std::string toNumber(std::string str)
{
	std::string s = str ;
	std::string strNum ; /* string to be built 
							with the following 
							for loop */

	// less typing using a for and nested if than a switch
	for (std::string::size_type i = 0; i < str.size(); ++i)
	{
		if (s[i] >= 'a' && s[i] <= 'c')
		{
			strNum += "2" ;
			continue ;
		}
		if (s[i] >= 'd' && s[i] <= 'f')
		{
			strNum += "3" ;
			continue ;
		}
		if (s[i] >= 'g' && s[i] <= 'i')
		{
			strNum += "4" ;
			continue ;
		}
		if (s[i] >= 'j' && s[i] <= 'l')
		{
			strNum += "5" ;
			continue ;
		}
		if (s[i] >= 'm' && s[i] <= 'o')
		{		
			strNum += "6" ;
			continue ;
		}
		if (s[i] >= 'p' && s[i] <= 's')
		{
			strNum += "7" ;
			continue ;
		}
		if (s[i] >= 't' && s[i] <= 'v')
		{
			strNum += "8" ;
			continue ;
		}
		if (s[i] >= 'w' && s[i] <= 'z')
		{
			strNum += "9" ;
			continue ;
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			strNum += s[i] ;
			continue ;
		}
		else
			continue ;
	}
	return strNum ;  /* this string was 
						built from the 
						above for loop */
}


////////////////////////////////////////
/* TRIM PHRASE TO SEVEN NUMBERS LONG  */
////////////////////////////////////////
std::string trimNumber(std::string str)
{
	std::string s = str ;
	
	// trimming the phrase down to 7 chars
	while (s.size() > 7)
		s.pop_back() ;
	
	return s ;
}


/////////////////////////////////////////
/* ADD THE HYPHEN TO TELEPHONE NUMBER  */
/////////////////////////////////////////
std::string addHyphen(std::string str)
{
	// insert at index 3, 1 char '-'
	std::string s = str ;
	s.insert(3, 1, '-') ;
	
	return s ;
}
