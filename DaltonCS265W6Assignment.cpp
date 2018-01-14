/******************
 * Deric Dalton
 * G00129003
 * CS265
 * Week 6 Assignment
 *
 * ***************
 * PROGRAM NOTES:*
 * ***************
 *
 * a. Use of unsigned int because the number can't get into the negative.  This
 * allows for large numbers to be worked with.
 *
 * b. Methods perform all operations as per assignment requirements
 *
 * **************
 * REQUIREMENTS:*
 * **************
 *
 * 1. Menu driven
 *    menu()
 *    choices()
 *    numMach()
 *
 * 2. Random number generator to generate a two digit positive integer
 *    randNum()
 *
 * 3. Double the number
 *    numDoub()
 *
 * 4. Reverse the digits of the number
 *    numRev()
 *
 * 5. Raise the number to the power of 2, 3 or 4
 *    numRaise()
 *
 * 6. Sum the digits of the number
 *    numSumDigi()
 *
 * 7. After performing an operation if the number is less than 10, add 10 to the
 *    number
 *    ckNum()
 *
 * 8. If the number is a two digit number, them raise the first digit to the
 *    power of the second digit
 *    smaNum()
 *
 * 9. If the number is a three digit number, and the last digit is less than or
 *    equal to 4, them raise the first two digits to the power of the last digit
 *    lgNum()
 *
 * 10.After each opeartion, determine if the number is prime
 *    isPrime()
 *
 * 11.No global variables
 */


#include <iostream>
#include <ctime> //for time and seed of random num generator
#include <stdlib.h> //random number generation

///////////////////
/* METHOD PROTOS */
///////////////////
void menu() ;
void choices(char) ;
char getChar() ;
int getInt() ;
void numMach() ;
unsigned int randNum() ;
unsigned int numDoub(unsigned int) ;
unsigned int numRev(unsigned int) ;
unsigned int numRaise(unsigned int, int) ;
unsigned int numSumDigi(unsigned int) ;
unsigned int ckNum(unsigned int) ;
unsigned int numScrambler(unsigned int) ;
unsigned int smaNum(unsigned int) ;
unsigned int lgNum(unsigned int) ;
bool isPrime(unsigned int) ;
void numPrnt(unsigned int) ;
void primePrnt(unsigned int, bool) ;

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

/* MAIN MENU */
void menu()
{
	/* Initialize the random number seed now
	 * using ctime */
	std::srand (std::time(0)) ;
	char c ;
	choices(1) ;

	while(true)
	{
		choices(2) ;
		choices(3) ;

		c = getChar() ;
		switch(c)
		{
			case 'y':
			case 'Y':	numMach() ;
					continue ;

			case 'q':
			case 'Q':	choices(4) ;
					break ;

			default:	choices(5) ;
					continue ;
		}
	break ;
	}
}

/* MENU CHOICES AND TEXT */
void choices(char c)
{
	switch (c)
	{
		case 1:
		{
			std::cout << "\nWelcome to NUMBER MACHINE\n" ;
			break ;
		}

		case 2:
		{
			std::cout << "\n\nMAIN MENU\n" ;
			break ;
		}

		case 3:
		{
			std::cout << "Press 'Y' to continue or press 'Q' to quit.\n" << std::endl ;
			break ;
		}

		case 4:
		{
			std::cout << "\nExiting\n" << std::endl ;
			break ;
		}

		case 5:
		{
			std::cout << "\nI'm sorry, that's not a valid choice.\nPlease try again.\n" ;
			break ;
		}

		case 6:
		{
			std::cout << "\nSelect one of the following options:\n"
				  << "(1) Generate a new random number\n"
				  << "(2) Double the number\n"
				  << "(3) Reverse digits in number\n"
				  << "(4) Raise the number to the power of 2, 3 or 4\n"
				  << "(5) Sum the digits of the number\n"
				  << "(6) Scramble the number\n"
				  << "(0) To quit to main menu\n"
				  << "NOTE: After each operation, NUMBER MACHINE will check the number's value.\n"
				  << "If it is less than 10, NUMBER MACHINE will add 10 to the number.\n"
				  << std::endl ;
			break ;
		}

		case 7:
		{
			std::cout << "\nWould you like to raise the number by the"
				  << " power of 2, 3 or 4?\n"
				  << "Please enter the power and press <enter>\n"
				  << std::endl ;
			break ;
		}

		case 8:
		{
			std::cout << "Please enter an integer value."
				  << " Either 2, 3 or 4\n"
				  << "Press <enter> to continue.\n"
				  << std::endl ;
			break ;
		}
	}
}





// ********* //
// GET INPUT //
// ********* //

/* SIMPLE GETCHAR METHOD */
char getChar()
{
	char c ;
	std::cin >> c ;
	std::cin.clear() ;
	std::cout << std::endl ;
	return c ;
}

/* GET INT FOR USER DEFINED EXPONENT FOR numRaise()  */
int getInt()
{
	int i ;

	do
	{
		std::cin >> i ;
		if (std::cin.fail())
		{
			choices(5) ;
			choices(8) ;
			std::cin.clear() ;
			std::cin.ignore(100, '\n') ;
		}

		if (!(i >= 2 && i <= 4))
		{
			choices(5) ;
			choices(8) ;
			std::cin.clear() ;
			std::cin.ignore(100, '\n') ;
		}
	}while (std::cin.fail() || (!(i >= 2 && i <= 4))) ;
	std::cin.clear() ;
	return i ;
}





// ******************************* //
// SUB MENU FOR THE NUMBER MACHINE //
// ******************************* //

/* NUMBER MACHINE METHOD */
/* This is where the user does his number manipulation -- with the number
 * machine!*/
void numMach()
{
	char c ;
	unsigned int num ;
	bool prime ;

	do
	{
		choices(6) ;
		c = getChar() ;
		switch(c)
		{
			case '1':
			{
				std::cout << "* GETTING RANDOM NUMBER *\n\n" ;
				num = randNum() ;
				num = ckNum(num) ;
				numPrnt(num) ;
				primePrnt(num, prime) ;
				continue ;
			}

			case '2':
			{
				std::cout << "* DOUBLING NUMBER *\n\n" ;
				num = numDoub(num) ;
				num = ckNum(num) ;
				numPrnt(num) ;
				primePrnt(num, prime) ;
				continue ;
			}

			case '3':
			{
				std::cout << "* REVERSAL OF DIGITS IN NUMBER*\n"
					  << "\n" ;
				num = numRev(num) ;
				num = ckNum(num) ;
				numPrnt(num) ;
				primePrnt(num, prime) ;
				continue ;
			}

			case '4':
			{
				std::cout << "* RAISING NUMBER WITH EXPONENT"
					  << "*\n\n" ;
				choices(7) ;
				int i = getInt() ;
				num = numRaise(num, i) ;
				num = ckNum(num) ;
				numPrnt(num) ;
				primePrnt(num, prime) ;
				continue ;
			}

			case '5':
			{
				std::cout << "* SUMMING DIGITS OF NUMBER *\n\n" ;
				num = numSumDigi(num) ;
				num = ckNum(num) ;
				numPrnt(num) ;
				primePrnt(num, prime) ;
				continue ;
			}

			case '6':
			{
				std::cout << "* SCRAMBLING NUMBER *\n\n" ;
				num = numScrambler(num) ;
				num = ckNum(num) ;
				numPrnt(num) ;
				primePrnt(num, prime) ;
				continue ;
			}

			case '0':
			{
				choices(4) ;
				break ;
			}

			default:
			{
				choices(5) ;
				continue ;
			}
		}
	}while (c != '0') ;
}





// *********************** //
// RANDOM NUMBER GENERATOR //
// *********************** //

/* GENERATE RANDOM NUMBER FOR THE NUMBER MACHINE */
unsigned int randNum()
{
	unsigned int ran = std::rand() % 90 + 10 ;
	return ran ;
}





// ****************** //
// OPERATIONS METHODS //
// ****************** //

/* DOUBLE THE NUMBER */
unsigned int numDoub(unsigned int i)
{
	return i*2 ;
}





/* REVERSE THE DIGITS IN THE NUMBER */
/* I tried converting the number to a string first and concat-ing the end() of
 * the string to a new string, but learning how to do this with the math
 * was much more exiting.  Reading on the WWW, and learning how to work
 * with division was more mature in my opinion.
 * Working through the procedure of mod and div and building a string
 * then passing it as an arg for std::stoi() was much more understandable
 * I think. The hardest thing about building this method was the condition for the while
 * loop and the order that I had to process the integer. */
unsigned int numRev(unsigned int i)
{
	unsigned int k ;
	std::string s ;

	while (i != 0)
	{
		k = i % 10 ;
		s += std::to_string(k);
		i /= 10 ;
	}
	unsigned int revNum = std::stoi(s) ;
	return revNum ;
}





/* RAISE THE NUMBER TO USER SELECTED POWER */
unsigned int numRaise(unsigned int i, int j)
{
	unsigned int raisedNum = i ;

	for (int p = 2; p <= j; ++p)
	{
		raisedNum *= i ;
	}
	return raisedNum ;
}





/* SUM THE DIGITS OF THE NUMBER */
unsigned int numSumDigi(unsigned int i)
{
	unsigned int t, u = 0;
	std::string temp ;
	std::string s = std::to_string(i) ;
	for (unsigned int m = 0; m < s.length(); ++m)
	{
		temp = s.at(m) ;
		t = stoi(temp) ;
		u += t ;
	}
	return u ;
}





/* CHECK TO SEE IF THE NUMBER IS LESS 10, IF SO, ADD 10 */
unsigned int ckNum(unsigned int i)
{
	std::cout << "* NUMBER CHECK : " ;
	if (i < 10)
	{
		std::cout << "Number is " << i << " and is less than 10, adding another 10.\n" 
			  << std::endl ;
		i += 10 ;
		return i ;
	}
	else
	{
		std::cout << "Number is " << i << " and is equal to or greater than 10, number "
			  << "remains the same.\n" 
			  << std::endl ;
		return i ;
	}
}





/* CHECKS THE SIZE OF THE NUMBER AND THEN SCRAMBLES */
/* Methods smaNum(int) and lgNum(int) are called
 * based on length of number */
unsigned int numScrambler(unsigned int i)
{
	// cast i as a string to operate on the length of the number
	std::string s = std::to_string(i) ;

	int tempInt ;
	unsigned int n ;

	if (s.length() == 3 )
	{
		// save third digit as a string then cast as int to test
		std::string temp(s.substr(2, 1)) ;
		tempInt = std::stoi(temp) ;

		// if tempInt is 0 or 1, it won't change the number
		if (tempInt <= 4 && tempInt > 1)
		{
			n = lgNum(i) ;
			return n ;
		}
		else
		{
			std::cout << "** Number is 3 digits long, however, it"
				  << "didn't meet the three digit scramble requirements."
				  << " **\n\n" ;
			return i ;
		}
	}

	else if (s.length() == 2)
	{
		// save second digit as a string then cast as int to test
		std::string temp(s.substr(1, 1)) ;
		tempInt = std::stoi(temp) ;

		// if tempInt is 0 or 1, it won't change the number
		if (tempInt > 1)
		{
			n = smaNum(i) ;
			return n ;
		}
		else
		{
			std::cout << "** Number is 2 digits long, however, it "
				  << "didn't meet the two digit scramble requirements. "
				  << "** \n\n" ;
			return i ;
		}
	}

	else
	{
		std::cout << "** Number doesn't meet scramble requirements. **"
			  << "\n\n" ;
		return i ;
	}
}

/* SCRAMBLER IF NUMBER IS 2 DIGITS LONG */
/* I wrestled with how to do this.
 * I ended up doing it in a most procedural and neanderthalic manner. */
unsigned int smaNum(unsigned int i)
{
	/* cast the param from smaNum() as a string  */
	std::string s = std::to_string(i) ;

	/* numeric vars */
	unsigned int base, raisedNum, scrambledNum ;
	int exponent ;

	/* string vars */
	std::string subStr0(s.substr(0, 1)) ;
	std::string subStr1(s.substr(1, 1)) ;
	std::string newNumber ;

	/* build params for numRaise() */
	base = stoi(subStr0) ;
	exponent = stoi(subStr1) ;
	raisedNum = numRaise(base, exponent) ;

	/* build the scrambledNum */
	newNumber += std::to_string(raisedNum) ;
	newNumber += std::to_string(exponent) ;
	scrambledNum = stoi(newNumber) ;

	return scrambledNum ;
}

/* SCRAMBLER IF NUMBER IS 3 DIGITS LONG */
/* Follows the same process as smaNum() just adds another step due to the third
 * digit */
unsigned int lgNum(unsigned int i)
{
	/* cast the param from lgNum() as a string  */
	std::string s = std::to_string(i) ;

	/* numeric vars  */
	unsigned int base1, base2, raisedNum1, raisedNum2, scrambledNum ;
	int exponent ;

	/* string vars */
	std::string subStr0(s.substr(0, 1)) ;
	std::string subStr1(s.substr(1, 1)) ;
	std::string subStr2(s.substr(2, 1)) ;
	std::string newNumber ;

	/* build params for numRaise() */
	base1 = stoi(subStr0) ;
	base2 = stoi(subStr1) ;
	exponent = stoi(subStr2) ;
	raisedNum1 = numRaise(base1, exponent) ;
	raisedNum2 = numRaise(base2, exponent) ;

	/* build the scrambledNum() */
	newNumber += std::to_string(raisedNum1) ;
	newNumber += std::to_string(raisedNum2) ;
	newNumber += std::to_string(exponent) ;
	scrambledNum = stoi(newNumber) ;

	return scrambledNum ;
}





/* CHECK TO SEE IF NUMBER IS PRIME */
bool isPrime(unsigned int n)
{
	int count = 0 ;
	bool prime = false ;

	/* Since prime numbers are only div by themselves and one, when
 	 * n % i = 0  the counter will increment.  When n == i the counter
 	 * is checked and if i == 2, it is prime.
 	 * Logic was found on C++ beginner . com  This was a hard one for me to
 	 * figure out.
 	 * I started off loading an array of all prime numbers, but it was very
 	 * complex.  I coldn't figure out the logic and I conulted the
 	 * duckduckgo oracle and this was the nicest open source
 	 * one that I could find. */
	for(int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			count++ ;
		}
	}

	if(count == 2)
	{
		prime = true ;
		return prime ;
	}

	else
	{
		return prime ;
	}
}





// ************* //
// PRINT METHODS //
// ************* //

/* PRINT NUMBER METHOD */
void numPrnt(unsigned int i)
{
	std::cout << "* WORKING NUMBER is: " << i << " *\n" << std::endl ;
}

/* CHECK AND PRINT PRIME  */
/* This method calls isPrime(), a bool is returned. */
void primePrnt(unsigned int i, bool b)
{
	std::string temp = std::to_string(i) ;
	int numLen = (temp.size() + 2 ) ;

	std::string s ;

	if (isPrime(i))
		s = "YES" ;
	else
		s = "NO" ;
	std::cout << "* PRIME CHECK: is " << std::to_string(i) + " prime? " << s << " *" << std::endl ;
}
