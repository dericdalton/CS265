/**
  * Deric Dalton
  * G00129003
  * CS265 Progging in C++
  * Week 2 Assignment
  *
  */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
	// I loaded all vars at top since they're all global
	// and there are no methods.  Thought it would be easier
	// to read
	
	// vars for files
	std::ifstream inFile;
	std::ofstream outFile;
	
	// vars to hold istream read
	std::string fName;
	std::string lName;
	std::string dpt;
	float gross;
	float bonus;
	float tax;
	float dist;
	float trvlTime;
	int cupsSold;
	float cupCost;
	
	// vars from istream read processing
	std::string fullName ;
	float netPay ;
	float taxes ;
	float grossPay ;
	float avgSpeed ;
	float sales ;

	/**
	  * OPEN FILE:  inFILE
	  *
	  */

	// open the file, pre-processed data (inData.txt)
	inFile.open("inData.txt");

	std::cout << "Attempting to open file:" << std::endl ;
	
	// Check that inData.txt exists, if not, handle it
	// kind of silly since the file name is hardcoded.
	// However, if the file was fatfingered into the 
	// code itself, this simple method will tell the user
	// what happened.  Basic error hand.
	if (!inFile)
	{
		std::cout << "Unable to open file.\n";
		std::cout << "File either doesn't exist or wrong name.";
		std::cout << std::endl;
		exit(1);  //will exit program
	}

	std::cout << "File opened a-okay!" << std::endl ;

	std::cout << "\nReading the file..........\n" ;
	
	//read inFile and save each word to the variables
	inFile >> fName ;
	inFile >> lName ;
	inFile >> dpt ;
	inFile >> gross ;
	inFile >> bonus ;
	inFile >> tax ;
	inFile >> dist ;
	inFile >> trvlTime ;
	inFile >> cupsSold ;
	inFile >> cupCost;
	
	std::cout << "Read complete!\n\nProcessing the data, please be patient." << std::endl ;

	// process the numbers
	fullName = fName + " " + lName ;
	grossPay = ((gross * (bonus / 100)) + gross) ;
	taxes = grossPay * (tax / 100) ;
	netPay = grossPay - taxes ; 
	
	avgSpeed = dist / trvlTime ;
	
	sales = cupsSold * cupCost ;
	
	std::cout << "\nProcessing complete.\n\nOpening outFile.\n"  ;
	std::cout << "If it doesn't exist, I will create it.\n" ;
	
	/**
	  *  OPEN FILE: outFILE
	  *
	  */
	
	// open outFile
	// I waited until now to open it, it wasn't needed until now
	// post-processed data (outData.txt) Note: outFile will be created
	outFile.open("outData.txt");

	std::cout << "Job completed.\n\nWriting data to outFile." << std::endl ;

	// write lines to file
	outFile << std::setprecision(2) << std::fixed ; // set precision of floats for outFile
	outFile << "Name: " << fullName << ", Department: " << dpt << "\n" ;
	outFile << "Monthly Gross Salary: $" << gross << ", Monthly Bonus: " << bonus << "%,\n" \
		   << "Taxes: " << tax << "%\nPaycheck: $" << netPay << "\n\n" ;
	outFile << "Distance Traveled: " << dist << " miles, Traveling Time: " << trvlTime << " hours\n" \
		   "Average Speed: " << avgSpeed << " miles per hour\n" ;
	outFile << "Number of Coffee Cups Sold: " << cupsSold << ", Cost: $" << cupCost<< " per cup\n" \
		   << "Sales Amount = $" << sales << "\n" ;
	outFile << std::endl ;

	std::cout << "\noutFile written! Colosing files." << std::endl ; 
	// close the files:
	inFile.close() ;
	outFile.close() ;
	std::cout << "\nBoth open files closed.  Exiting.  Goobye!\n\n" ;

	return 0;
}
