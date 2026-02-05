/*
=============================
Name: Anurag Prashant Umale =
Student Id: 1887255         =
E-mail: aumale@ucsc.edu     =
File: Arithmetic.cpp        =
Class: CSE 101 Spring 2023  =
=============================
*/
#include <fstream>
#include "BigInteger.h"


int main(int argc, char *argv[])
{

    std::ifstream infile; // setting the ifstream for input file
    std::ofstream outfile; // setting the ofstream to outfile

    if (argc != 3) // checking if three arguments are passed into the function
    {
        std::cerr << "Usage: " << argv[0] << " <input file> <output file>" << std::endl; // Printing the standard error messsgae
        return (EXIT_FAILURE); // returning failure
    }

    infile.open(argv[1]); // opening the infile
    if (!infile.is_open()) // checking if the file is opened correctly or not
    {
        std::cerr << "Unable to open file " << argv[1] << std::endl; // Printing the standard error messsgae
        return (EXIT_FAILURE);  // returning failure
    } 

    outfile.open(argv[2]); // opening the outfile
    if (!outfile.is_open()) // checking if the file is opened correctly or not
    {
        std::cerr << "Unable to open file " << argv[2] << std::endl; // Printing the standard error messsgae
        return (EXIT_FAILURE); // returning failure
    }

    std::string big_string_1; // cretating first variable for string the first number
    std::string big_string_2; // cretating first variable for string the second number
    infile >> big_string_1 >> big_string_2;

    BigInteger big_number_1(big_string_1); // converting the first number into BigInteger and string digits in List format
    BigInteger big_number_2(big_string_2); // converting the first number into BigInteger and string digits in List format
    const BigInteger big_three("3"); // creating the constant of BigInteger 3
    const BigInteger big_two("2"); // creating the constant of BigInteger 2
    const BigInteger big_nine("9"); // creating the constant of BigInteger 9
    const BigInteger big_sixteen ("16"); // creating the constant of BigInteger 16


    outfile << big_number_1 << std::endl << std::endl; // printing the number 1
    outfile << big_number_2 << std::endl << std::endl; // printing the number 2
    outfile << big_number_1 + big_number_2 << std::endl << std::endl; // printing the sum of those numbers
    outfile << big_number_1 - big_number_2 << std::endl << std::endl; // printing the differnece of those numbers
    outfile << big_number_1 - big_number_1 << std::endl << std::endl; // Subtracting big number from itself
    outfile << (big_number_1.mult(big_three) -  big_number_2.mult(big_two)) << std::endl << std::endl; // 3 * number 1 + 2 * number 2
    outfile << big_number_1 * big_number_2 << std::endl << std::endl; // printing the product of those numbers
    outfile << big_number_1 * big_number_1 << std::endl << std::endl; // printing the product of same numbers 
    outfile << big_number_2 * big_number_2 << std::endl << std::endl; // printing product of same numbers 
    outfile << (big_nine * big_number_1 * big_number_1 * big_number_1 * big_number_1 + big_sixteen * big_number_2 * big_number_2 * big_number_2 * big_number_2 * big_number_2 ) << std::endl; // 9 * 4 * number 1 + 16 * 5 * number 2

    infile.close(); // closing the infile
    outfile.close(); // closing the outfile

    return (EXIT_SUCCESS); // returning success
}