#include <iostream>
#include <iomanip>

/////////////////
/* METHOD DECL */
/////////////////
float coins (int x, int y, int z) ;

/////////////////
/* MAIN METHOD */
/////////////////
int main(void) 
{
			
		int q, d, n ;
		float total ;

		std::cout << "HI! WELCOME TO COIN CALCULATOR!!\n\n" ;
		std::cout << "Please tell me how many quarters you have: " ;
	    std::cin >> q ;
		std::cout<< "Please tell me how many dimes you have: " ;
		std::cin >> d ;
		std::cout << "And now, tell me how many nickels you have: " ;
		std::cin >> n ;
		std::cout << "I'll add them up for you, with math!\n\n" ;

		total = coins(q, d, n) ;
		
		std::cout << std::fixed << std::setprecision(2) ;
		std::cout << "Your total is: $" << total << std::endl ;		
}

/////////////////////
/* COIN CALCULATOR */
/////////////////////
float coins(int x, int y, int z)
{
		const float QTR = 0.25 ;
		const float DIM = 0.10 ;
		const float NIC = 0.05 ;

		float total, qSubTot, dSubTot, nSubTot ;
		int q = x ;
		int d = y ;
		int n = z ;	

		qSubTot = (x * QTR) ;
		dSubTot = (y * DIM) ;
		nSubTot = (z * NIC) ;
		total = (qSubTot + dSubTot + nSubTot) ;

		return total ;
}

