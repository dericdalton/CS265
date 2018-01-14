#include <iostream>
#include <cmath> //std::sqrt from c stdlib

/////////////////
/* MAIN METHOD */
/////////////////
int main(void)
{
	/* PART A  */
	int firstNum, secondNum, control, sum ;
	float sqSum ;
	char ch ;

	std::cout << "Please give me two integers.\n"
		  << "Your first integer must be less that the second."
		  << std::endl ;
	std::cin >> firstNum ;
	std::cin >> secondNum ;
	std::cout << std::endl ;
	while (!(firstNum < secondNum))
	{
		std::cout << "Your first integer is not less than the second.\n"
			  << "Please try again.\n"
			  << "Please give me two integers.\n"
			  << "The first integer must be less than the second.\n" ;
		std::cin >> firstNum ;
		std::cin >> secondNum ;
		std::cout << std::endl ;
	}

	/* PART B */
	std::cout << "Printing all odds between the first and second integer.\n" ;
	control = firstNum ;
	while (control <= secondNum)
	{
		if (control % 2 != 0)
			std::cout << control << "\n" ;
		control++ ;
	}
	std::cout << std::endl ;

	/* PART C */
	std::cout << "Printing the sum of all evens between the first and second integer.\n" ;
	sum = 0;
	while (true)
	{
		for (int i = firstNum; i <= secondNum; ++i)
		{
			if (i % 2 == 0)
				sum += i ;
		}
		std::cout << "Sum: " << sum << "\n" << std::endl ;
		break ;
	}

	/* PART D */
	std::cout << "Printing the square root of all ints from 1 to 10.\n" ;
	control = 1 ;
	while (control <= 10)
	{
		std::cout << "Square root of " << control << " is " 
			  << std::sqrt(control) << "\n" ;
		control++ ;
	}
	std::cout << std::endl ;

	/* PART E */
	std::cout << "Printing the sum of all odd numbers squared between "
		  << "the first and second integers.\n" ;
	control = firstNum ;
	sqSum = 0 ;
	while (control <= secondNum)
	{
		if (control % 2 != 0)
			sqSum += (sqrt(control)) ;
		control ++ ;
	}
	std::cout << "The sum of the square roots of the odds is: " << sqSum << std::endl ;

	/* PART F */
	std::cout << "Printing all capital letters, from A to Z.\n" ;
	ch = 65 ;
	while (ch <= 90)
	{
		std::cout << ch << std::endl ;
		ch++ ;
	}
	std::cout << std::endl ;
}
