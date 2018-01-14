/*
 * Deric Dalton
 * G00129003
 * CS265
 * Week 1 Assignment
 */

// #include statement:  this statment will include the input/output stream
// objects of the standard C++ library.
#include <iostream>

// Instead of: using namespace std ;
// declare what is being used from the namespace.
// cin allows user to give input.  Ex: std::cin >> foo ; would take user input
// and save to var foo
using std::cin ;

// cout outputs to the console.
using std::cout ;

// endl will end the line.  Another way is to use "\n".
using std::endl ;

// main method for the program
int main()
{
    // ***DECLARE THE VARIABLES
    // declare (4) integer variables
    // This can be done with one line because they are all the same type.
    // If a var was to be initialzed with a value, all the vars after it
    // would need to be initialized with a value as well.
    int num1, num2, num3, average ;

    //assign num1 the value of 125
    num1 = 125 ;

    // assign num 2 the value of 28
    num2 = 28 ;

    // Assign num3 the value of -25.  If this was an unsigned int, a negative
    // value would not be allowed.
    num3 = -25 ;

    // ***DO THE CALCULATIONS

    // declared the int sum to hold the sum of all three ints.
    int sum = num1 + num2 + num3 ;

    // average is the sum / the number of ints. / is the division operator.
    average = sum / 3 ;

    // ***OUTPUT BELOW!

    // Title of the program coming to a terminal near you...
    cout << "\n*** THREE INTS AND AN AVERAGE ***\n\n" ;

    // cout will print to screen the string of chars, and typecase char 49.
    // This is the number 1 (ASCII 49 is the char 1).  Print a space, equal and
    // space and end the line.
    cout << "Variable: num" << (char)49 << " = " << num1 << endl ;

    // cout will print to screen the string of chars. Typecasting the char and
    // showing how a char has a numerical value with some math. Next, a space equal
    // and space followed by an end of line.
    cout << "Variable: num" << (char)('R' - 32) << " = " << num2 << endl ;

    // cout will print to screen the string of chars, the var num3 and end the line
    cout << "Variable: num3 = " << num3 << endl ;

    // The preferred way of doing things!
    // cout will print to screen the string of chars, the var average and end
    // the line with endl from the namespace std.
    cout << "Variable: average = " << average << endl ;

    // ***THE GOODBYE MESSAGE.
    cout << "\n*** END OF PROGRAM.  EXITING TO SYSTEM ***\n" ;

    // the return statement returns an int value.  0 will return control from
    // the program the system
    return 0;
}
