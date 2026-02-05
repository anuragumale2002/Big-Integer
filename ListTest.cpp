/*
============================================
Name: Anurag Prashant Umale                =
Student Id: 1887255                        =
E-mail: aumale@ucsc.edu                    =
File: ListTest.cpp (testing of List ADT)   =
Class: CSE 101 Spring 2023                 =
============================================
*/
#include <iostream> // including iostream lib
#include <string> // including the string lib
#include <stdexcept> // including the stdexecpt lib
#include "List.h" // including the header file

using namespace std;

int main()
{

   List list1; // creating list
   list1.insertBefore(10); // inserting the element
   list1.insertAfter(20); // inserting the element
   list1.insertBefore(30); // inserting the element
   list1.moveFront(); // moving front in list
   cout << "List 1: " << list1 << endl; // printing the list
   cout << "Position of the Cursor:" << list1.position() << endl; // postion of the cursor
   cout << "Length of the list:" << list1.length() << endl; // length of the list
   list1.eraseAfter(); // erasing afters
   cout << "List 1: " << list1 << endl; // printing the list
   cout << "Position of the Cursor:" << list1.position() << endl; // postion of the cursor
   cout << "Length of the list:" << list1.length() << endl; // length of the list
   list1.moveBack(); // moving back in list
   list1.eraseBefore(); // erasing the previous element
   cout << "List 1: " << list1 << endl; // printing the list
   cout << "Position of the Cursor:" << list1.position() << endl; // postion of the cursor
   cout << "Length of the list:" << list1.length() << endl; // length of the list

   List list2; // creating the second list
   for (int i = 0; i < 10; i++) // looping 10 times
   {
      list2.insertBefore(i * i * i); // inseting the elements
   }
   cout << "List 2: " << list2 << endl; // printing the second list
   list2.moveFront(); // moving front in the list
   for (int i = 0; i < 10; i++) // looping 10 times
   {
      cout << "FindNext(" << i * i * i << "): " << list2.findNext(i * i * i) << endl; // finding the elements in list
   }

   List list3; // creating list
   List list4; // creating list
   for (int i = 0; i < 5; i++)
   {
      list3.insertAfter(i); // inserting the element in list
      list4.insertBefore(i * i); // inseting the element in list
   }
   cout << "List 3: " << list3 << endl; // printing the list 3
   cout << "List 4: " << list4 << endl; // printing the list 4
   List list5 = list3.concat(list4); // creating list 5 which is list 3 + list 4
   cout << "List 5: " << list5 << endl; // printing list 5
   List list6; // creating the list 6
   for (int i = 0; i < 5; i++) // looping 5 times
   {
      list6.insertBefore(i); // inseting the element in list
      list6.insertAfter(i); // inserting the element in list
   }
   cout << "List 6 before cleanup: " << list6 << endl; // printing the list
   list6.cleanup(); // cleaning up the list
   cout << "List 6 after cleanup: " << list6 << endl; // printing the list
   list6.clear(); // clearing the list
   cout << "List 6 after clear: " << list6 << endl; // printing the list

   return (EXIT_SUCCESS); // returning success
}
