#include <iostream>
#include <math.h>


///////////////
/* FUNCTIONS */
///////////////
void menu() ;
void instructions() ;
void calc() ;
void resultPrinter(int, int, char, long long int) ;

//////////
/* MAIN */
//////////
int main(void)
{
		menu() ;	
		return 0 ;
}

void menu()
{
		std::cout << "WELCOME TO TERMICALC!" << std::endl ;
		std::cout << "I will take your two numbers and operator and perform"\
				  << " the math for you, it's that simple!" << std::endl ;
		while (true)
		{
				char c = ' ' ;
				std::cout << "Press Y to calculate, Q to quit: " ;
				std::cin >> c ;
				switch (c) 
				{
					case 'y':
					case 'Y':		instructions() ;
									calc() ;
									continue ;

					case 'q':
					case 'Q':		std::cout << "Okay, hate to see you leave!"\
									<< "\nGoodbye!\n" << std::endl ;
									break ;

					default :		std::cout << "I'm sorry, "\
								    << c << " is not a valid menu option.\n" ;
									continue ;
				}
		break ;
		}
}

void instructions()
{
		std::cout << "\nThe following operads are valid:\n" ;
		std::cout << "+ is addition\n" ;
		std::cout << "- is subtraction\n" ;
		std::cout << "* is multiplication\n" ;
		std::cout << "/ is division\n" ;
		std::cout << "\% is modulus division (find the remainder)\n" ;
		std::cout << "^ is exponent\n" << std::endl ;

}

void calc()
{
		int n1, n2 ;
	    long long int result ;
		char c ;

		std::cout << "Please give me your first number: " ;
		std::cin >> n1 ;
		std::cout << "Please give me your operator: " ;
		std::cin >> c ;
		std::cout << "Pleae give me your second number: " ;
		std::cin >> n2 ;
		
		switch (c) 
		{
				case '+':		result = (n1 + n2) ;
								resultPrinter(n1, n2, c, result) ;
								break ;

				case '-':		result = (n1 - n2) ;
								resultPrinter(n1, n2, c, result) ;
								break ;

				case '*':		result = (n1 * n2) ;
								resultPrinter(n1, n2, c, result) ;
								break ;

				case '/':		if ((n2 > 0) || (n2 < 0)) 
								{
										result = (n1 / n2) ;
										resultPrinter(n1, n2, c, result) ;
								}
								else
								{
										std::cout << "ERROR.  Can't divide"\
												  << " by zero!"\
												  << std::endl << std::endl ;
								}
								break ;

				case '%':		if ((n2 > 0) || (n2 < 0))
								{
										result = (n1 % n2) ;
										resultPrinter(n1, n2, c, result) ;
								}
								else
								{
										std::cout << "ERROR. Mod 0 is undefined.";
										std::cout << std::endl << std::endl ;
								}
								break ;

				case '^':		result = pow(n1, n2) ;
								resultPrinter(n1, n2, c, result) ;
								break ;

				default:		std::cout << "I'm sorry, that's not a"\
										  << " valid operand." << std::endl ;
								std::cout << "Please try again!\n" << std::endl ;
		}
	

		n1, n2 = 0 ;
		result = 0 ;
		c = ' ' ;

}

void resultPrinter(int x, int y, char ch, long long int re)
{
		int n1 = x ;
		int n2 = y ;
		char c = ch ;
		long long int r = re ;

		std::cout << n1 << " " << c << " " << n2 << " = " << r << "\n\n" ;
}
