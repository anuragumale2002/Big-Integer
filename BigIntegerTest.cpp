/*
=======================================================
Name: Anurag Prashant Umale                           =
Student Id: 1887255                                   =
E-mail: aumale@ucsc.edu                               =
File: BigIntegerTest.cpp (Testing of BigInteger ADT)  =
Class: CSE 101 Spring 2023                            =
=======================================================
*/
#include<iostream>
#include<string>
#include<stdexcept>
#include"BigInteger.h"

using namespace std;

int main(){

   string str_num_1 = "8324832470823402384092834092840298409284";
   string str_num_2 = "-4329849238438738473843";
   string str_num_3 = "-42342343243525987765544566789";
   string str_num_4 = "9999888776655444";
   string str_num_5 = "-919191919929292929393939383837373636262";
   string str_num_6 = "9000000000800007777565433";

   BigInteger A = BigInteger(str_num_1);
   BigInteger B = BigInteger(str_num_2);
   BigInteger C = BigInteger(str_num_3);
   BigInteger D = BigInteger(str_num_4);
   BigInteger E = BigInteger(str_num_5);
   BigInteger F = BigInteger(str_num_6);

   cout << "A :" << A << endl;
   cout << endl;
   cout << "B :" << B << endl;
   cout << endl;
   cout << "C :" << C << endl;
   cout << endl;
   cout << "D :" << D << endl;
   cout << endl;
   cout << "E :" << E << endl;
   cout << endl;
   cout << "F :" << F << endl;
   cout << endl;
   BigInteger sum = A + B;
   cout << "Sum =  A + B: " << sum << endl;
   cout << endl;
   BigInteger diff = C - D;
   cout << "Difference = C - D: " << diff << endl;
   cout << endl;
   BigInteger prod = E * F;
   cout << "Product = E * F: " << prod << endl;
   cout << endl;

   cout << "(A == F) = " << ((A==F)?"True":"False") << endl;
   cout << "(Sum < Difference)  = " << ((sum<diff)? "True":"False") << endl;
   cout << "(Product <= E) = " << ((prod<=E)?"True":"False") << endl;
   cout << "(E > B)  = " << ((E>B)? "True":"False") << endl;
   cout << "(A >= F) = " << ((A>=F)?"True":"False") << endl << endl;

   const BigInteger big_two = BigInteger("2");
   const BigInteger big_five = BigInteger("5");
   const BigInteger big_hundred = BigInteger(100);
   BigInteger added_twos = BigInteger("0");
   BigInteger subtracted_fives = big_five;
   BigInteger product_hundreds = BigInteger("1");
   cout << endl;


   cout<< "BigInteger Two: " << big_two << endl;
   cout<< "BigInteger Five: " << big_five << endl;
   cout<< "BigInteger Hundred: " << big_hundred << endl;

   cout << endl;

   for(int i = 0; i < 5; i++){
      added_twos += big_two;
      subtracted_fives -= big_five;
      product_hundreds *= big_hundred;
   }

   cout<< "Adding BigInteger Two 5 times to iteself: " << added_twos << endl;
   cout<< "Subtracting BigInteger Five 5 times from itself: " << subtracted_fives << endl;
   cout<< "Multiplying BigInteger Hundred 5 times to itself: " << product_hundreds << endl;
   cout << endl;

   cout << "Sign of Sum: " << sum.sign() << endl;
   sum.negate();
   cout << "Negating the Sum: " << sum << endl;
   cout << "Sign of Sum: " << sum.sign() << endl;
   prod.makeZero();
   cout << "Product Value after making it Zero: " << prod << endl;

   try{
      BigInteger J = BigInteger("");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption 1" << endl;
   }
   try{
      BigInteger J = BigInteger("+");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption 2" << endl;
   }
   try{
      BigInteger J = BigInteger("12329837492387492837492$4982379487293847");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption 3" << endl;
   }
   try{
      BigInteger J = BigInteger("5298374902837409+82734098729287349827398");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption 4" << endl;
   }

   cout << endl;

   return EXIT_SUCCESS;
}
