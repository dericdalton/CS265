/******************
 * Deric Dalton
 * G00129003
 * CS265
 * Week 5
 *
 */

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

///////////////////
/* METHOD DECLS  */
///////////////////
void menu() ;
void subMenu() ;
void choices(char) ;
char getChar() ;
std::string milTm() ;
std::string stdTm() ;
void dispTm(std::string) ;

/////////////////
/* MAIN METHOD */
/////////////////
int main(void)
{
	menu() ;

	return 0 ;
}

/////////////////
/* METHOD DEFS */
/////////////////

/* MENU DEFINITION */
void menu()
{
	char c ;

	std::cout << "Welcome to Time Machine!\n" ;

	while (true)
	{
		choices(1) ;
		c = getChar() ;
		switch (c)
		{
			case 'y':
			case 'Y':	subMenu() ;
					continue ;

			case 'q':
			case 'Q':	std::cout << "Exiting!\n"
						  << std::endl ;
					break ;

			default:	choices(2) ;
					continue ;
		}
	break ;
	}
}

/* SUBMENU DEFINITION */
void subMenu()
{
	char c ;
	std::string str ;

	while (true)
	{
		choices(3) ;
		c = getChar() ;

		switch(c)
		{
			case 'm':
			case 'M':	str  = milTm() ;
					dispTm(str) ;
					continue ;

			case 's':
			case 'S':	str = stdTm() ;
					dispTm(str) ;
					continue ;

			case 'q':
			case 'Q':	std::cout << "Exiting to main menu.\n" ;
					break ;

			default:	choices(2) ;
					continue ;
		}
	break ;
	}
}

/* INSTRUCTIONS FOR MENU */
/* Switch statement for printing menu/choices for user */
void choices(char c)
{
	switch(c)
	{
		case 1:		std::cout << "\nMAIN MENU\n"
					  << "Please press 'Y' to continue.\n"
		  			  << "Or, press 'Q' to quit.\n"
					  << std::endl ;
				break ;

		case 2:		std::cout << "I'm sorry, that's not a "
					  << "valid choice.\n" ;
				break ;

		case 3:		std::cout << "Please select from the "
					  << "following options:\n"
		  			  << "For military time (24 "
					  << "hour format) press 'M'\n"
		 			  << "For standard time (12 "
					  << "hour am/pm format) press 'S'\n"
					  << "To quit press 'Q'.\n"
		  			  << std::endl ;
				break ;

	}
}

/* GET CHAR */
/* Simply get a char and then return it */
char getChar()
{
	char c ;
	std::cin >> c ;
	
	return c ;
}

/* MIL TIME */
/* http://ld2012.scusa.lsu.edu/cppreference/w/cpp/chrono/c/strftime.html  */
/* Reference for using strftime - this allowed me to save time as a string */
std::string milTm()
{
	char tmAsStr[100] ;
	std::time_t t = std::time(NULL) ;
	if (std::strftime(tmAsStr, 100, "Time is: %R%n%n", std::localtime(&t)))
		
	return tmAsStr ;
}

/* STD TIME */
/* http://ld2012.scusa.lsu.edu/cppreference/w/cpp/chrono/c/strftime.html  */
/* Reference for using strftime - this allowed me to save time as a string */
std::string stdTm()
{
	char tmAsStr[100] ;
	std::time_t t = std::time(NULL) ;
	if (std::strftime(tmAsStr, 100, "Time is: %r%n%n", std::localtime(&t)))

	return tmAsStr ;
}

/* DISPLAY TIME */
/* String passed to this method is from std::strftime in mil/std time methods  */
void dispTm(std::string str)
{
	std::string s = str ;
	std::cout << s ;
}
