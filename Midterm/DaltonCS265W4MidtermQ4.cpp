/********************************
 * Deric Dalton
 * G00129003
 * CS265
 * Week 4 - Midterm - Question 4
 *******************************/

#include <iostream>
#include <vector> //std::vector - dynamic, unlike arrays
#include <string>
#include <numeric> //std::accumulate - really nice function!

//////////////
/* METHODS  */
//////////////
void menu() ;
void sumMach() ;
void printNums(char, int) ;

/////////////////
/* MAIN METHOD */
/////////////////
int main(void)
{
	std::cout << "\n\nWELCOME TO SUM MACHINE!" << std::endl ;
	menu() ;

	return 0 ;
}

/////////////////
/* MENU METHOD */
/////////////////
void menu()
{
	char c ;
	while (true)
	{
		std::cout << "If you would like to continue, please press 'Y'\n"
			  << "If you'd like to quit, please press 'Q'" << std::endl ;

		std::cin >> c ;

		switch (c)
		{
			case 'y':
			case 'Y':	sumMach() ;
					continue ;

			case 'q':
			case 'Q':	std::cout << "Thanks for using SUM "
						  << "MACHINE.\nWe will see "
						  << "you again sometime soon!"
						  << std::endl << std::endl ;
					break ;

			default:	std::cout << "That isn't valid input.\n"
						  << "Please enter a 'Y' or 'Q'"
						  << std::endl << std::endl ;
					continue ;
		}
	break ;
	}

}

////////////////////////////
/* METHOD TO GET THE INTS */
////////////////////////////
void sumMach()
{
	std::vector<int> evens, odds ;
	int evenSum, oddSum ;
	int i = -1 ;

	std::cout << "Please enter an integer and then press <enter>.\n"
		  << "When finshed, enter 0 (zero) and press <enter>." << std::endl ;

	while (i != 0)
	{
		std::cin >> i ;
		// still learning how to properly handle input validation
		// segmentation faults can happen still
		// especially if an int hasn't been writen yet.
		if (std::cin.fail())
		{
			std::cin.clear() ;
			std::cin.ignore(256, '\n') ; //purge the buffer
			std::cout << "I'm sorry, that's not an integer!\n"
				  << "Please enter an integer: " ;
			continue ;
		}
		else
		{
			if (i % 2 == 0)
				evens.push_back(i) ;
			else
				odds.push_back(i) ;
		}
	}

	/* SUM UP EVENS AND ODDS                           */
	/* int = std::accumulate(first, last, intial value */
	evenSum =  std::accumulate(evens.begin(), evens.end(), 0) ;
	oddSum = std::accumulate(odds.begin(), odds.end(), 0) ;

	/* PRINT THE VECTORS AND PROVIDE SOME STATS */
	for (int i = 0; i < evens.size(); ++i)
		printNums('0', evens[i]) ;
	printNums('2', evens.size()) ;
	printNums('4', evenSum) ;

	for (int i = 0; i < odds.size(); ++i)
		printNums('1', odds[i]) ;
	printNums('3', odds.size()) ;
	printNums('5', oddSum) ;
}

////////////////////////////////////////////////////
/* PRINT METHOD                                   */
/* pram char -- directs what print method to use  */
/* 0, 2, 4 -- even integer print methods          */
/* 1, 3, 5 -- odd integer print methods           */
////////////////////////////////////////////////////
void printNums(char ch, int in)
{
	char c = ch ;
	int i = in ;
	switch (c)
	{
		case '0':	std::cout << "Even integer: " << i << std::endl ;
				break ;

		case '1':	std::cout << "Odd integer: " << i << std::endl ;
				break ;

		case '2':	std::cout << "Total number of even integers entered: "
					  << i << std::endl ;
				break ;

		case '3':	std::cout << "Total number of odd integers entered: "
					  << i << std::endl ;
				break ;

		case '4':	std::cout << "Sum of all evens: " << i << "\n" << std::endl ;
				break ;

		case '5':	std::cout << "Sum of all odds: " << i << "\n" << std::endl ;
				break ;
	}
}
