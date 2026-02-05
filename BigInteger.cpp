/*
==========================================================
Name: Anurag Prashant Umale                              =
Student Id: 1887255                                      =
E-mail: aumale@ucsc.edu                                  =
File: BigInteger.cpp (Implementation of BigInteger ADT)  =
Class: CSE 101 Spring 2023                               =
==========================================================
*/

#include "BigInteger.h" // including the BigInteger Header file

const int POWER = 9;                 // decalring the the POWER as constant 9
const ListElement BASE = 1000000000; // Decalring the const ListElement as BASE 1 billion

BigInteger::BigInteger()
{
    signum = 0;      // singum is set to the value 0
    digits = List(); // digints is set to the list
}

BigInteger::BigInteger(ListElement x)
{
    if (x < 0) // checkcing if x is less than 0
    {
        signum = -1; // setting the sign of number 1
    }
    else if (x > 0) // chceking if x greater than 0
    {
        signum = 1; // sign of the number is set to positive
    }
    else // else
    {
        signum = 0; // signum is set to 0
    }
    ListElement absoulte_value = (x < 0) ? x * -1 : x; // if x is less than 0 the x times -1 is taken else x is assigend to absolute_value
    while (absoulte_value > 0)                         // while absoulte_value is greater than 0
    {
        digits.insertAfter(absoulte_value % BASE); // digits are added with modulo with BASE
        absoulte_value /= BASE;                    // abosulte_value is divided by BASE value and stored in absolute_value
    }
    digits.moveFront(); // list cursor is moved front of the list
}

BigInteger::BigInteger(std::string s)
{
    if (s.size() == 0)
    {                                                                         // chcking if the size of the string is greater than 0
        throw std::invalid_argument("BigInteger: Constructor: empty string"); // throwing the invalid_argument error
    }
    signum = s[0] == '-' ? -1 : 1; // setting the signum value based on the sign in front of the number
    if (s[0] == '+' || s[0] == '-')
    {                    // checing if the first character of the string is + or -
        s = s.substr(1); // s is set to the substing starting from index 1 till end
    }

    if (s.size() > 0)
    {                     // chcking if the size of the sub string is greater than 0
        for (char &c : s) // for each character c in the substring s
        {
            if (!isdigit(c))
            {                                                                               // checking if the each character c is not a digit
                throw std::invalid_argument("BigInteger: Constructor: non-numeric string"); // thrwoing the exception of the invalid argument and error messsage
            }
        }
    }
    else
    {                                                                               // else
        throw std::invalid_argument("BigInteger: Constructor: non-numeric string"); // throwing the exception of the non-numeric string
    }
    int position = s.length() % POWER; // Positon is calculated by length of the substring modulo the POWER
    if (position)
    {                                                     // if it position has some value
        digits.insertBefore(stol(s.substr(0, position))); // inserting before the string from 0 till position type casted into long
    }
    for (position = s.length() % POWER; position < (int)s.length(); position += POWER) // looping from the length of the string mod power till the length of the string
    {
        digits.insertBefore(stol(s.substr(position, POWER))); // inserting the digit from the position till the power
    }
}

BigInteger::BigInteger(const BigInteger &N)
{
    this->signum = N.signum; // this pointer's signum is set to N's signum
    this->digits = N.digits; // this pointer's digits is set to N's digits
}

int BigInteger::sign() const
{
    return this->signum; // this pointer's signum is returned
}

int BigInteger::compare(const BigInteger &N) const
{
    if (this->signum != N.signum)
    {                                            // checling if the signum of both numbers are not equal
        return this->signum > N.signum ? 1 : -1; // returing 1 if this pointer's signum is greater than the N's signum else -1
    }
    else if (this->signum == 0)
    {             // chcking if this pointer's sign is 0
        return 0; // 0 is returned
    }
    List tempdigits = this->digits; /// Temp list for this pointer's digits
    List tempn = N.digits;          // temp list for N's digits

    int cmp = 0;                               // setting the compare to 0
    if (tempdigits.length() != tempn.length()) // checking if both the list length are not equal equal
    {
        if (tempdigits.length() > tempn.length())
        {            // checkig if the length of this pointer's digit is greater tha N's digits length
            cmp = 1; // cmp is set to 1
        }
        else
        {             // else
            cmp = -1; // cmp is set to -1
        }
    }
    else // else
    {
        tempdigits.moveFront();                                         // moving front in the this poineter's digits
        tempn.moveFront();                                              // moving front in the N's digits
        while (tempdigits.position() < tempdigits.length() && cmp == 0) // while the position of the cursor is less the the length of this pointer's digits and cmp is 0
        {
            if (tempdigits.peekNext() > tempn.peekNext())
            {            // chcking if peekNext of the tempdigit is greater than tempn peeknext digits
                cmp = 1; // cmp is set to 1
            }
            else if (tempdigits.peekNext() < tempn.peekNext())
            {             // chcking if peekNext of the tempdigit is less than tempn peeknext digits
                cmp = -1; // cmp is set to 1
            }
            else
            {            // else
                cmp = 0; // cmp is set to 0
            }
            tempdigits.moveNext(); // moving next in list
            tempn.moveNext();      // moving next in list
        }
    }
    if (this->signum == 1)
    {               // checking if this pointer's sign is 1
        return cmp; // return cmp
    }
    else
    {
        return -cmp; // return -cmp
    }
}

void scalarMultList(List &L, ListElement m)
{
    L.moveFront(); // moving front in the list
    while (L.position() < L.length())
    {                                 // checking if the cursor postion of the list is less than the length of the list
        L.setAfter(L.peekNext() * m); // multiplying each element of the list by m
        L.moveNext();                 // moving next in list
    }
}

void negateList(List &L)
{
    scalarMultList(L, -1); // calling the scalar mult function
}

// Got help from George in the section Monday Date: May 22 2023 3:00pm - 5:00pm	BE 109
void sumList(List &S, List A, List B, int sgn)
{
    S.clear();                                   // clearing the list
    scalarMultList(B, sgn);                      // multiplying the List B by the sgn
    A.moveBack();                                // moving back in the list
    B.moveBack();                                // moving back in the list
    while (A.position() > 0 || B.position() > 0) // checking if the position of cursor list A or position of cursor list B is greater than 0
    {
        ListElement element_1 = 0; // setting the list element to be 0
        ListElement element_2 = 0; // setting the list element to be 0
        if (A.position() > 0)
        {                             // Position of the cursor is greater than 0
            element_1 = A.peekPrev(); // element is set to the preovious element
        }
        else
        {                  // else
            element_1 = 0; // element is set to 0
        }
        if (B.position() > 0)
        {
            element_2 = B.peekPrev(); // element is set to the previous element in the list
        }
        else
        {
            element_2 = 0; // element is set to 0
        }
        S.insertAfter(element_1 + element_2); // adding the element_1 and element_2 and inserting in the list S
        if (A.position() > 0)
        {                 // checking if the position of cursor is greater than 0
            A.movePrev(); // moving previous in list
        }
        if (B.position() > 0)
        {                 // checking if the position of cursor is greater than 0
            B.movePrev(); // moving previous in the list
        }
    }
    S.moveFront();                           // moving front in the list
    while (S.front() == 0 && S.length() > 1) // checking if the front value of the list is 0 and length of the list is greater than 1
    {
        S.eraseAfter(); // earase after the cursor value
    }
}

// Got help from George in the section Monday Date: May 22 2023 3:00pm - 5:00pm	BE 109
int normalizeList(List &L)
{
    if (L.front() == 0)
    {             // checking if the front value of the list is equal to 0
        return 0; // returning 0
    }
    int sign_val = 1;  // setting the sign value to 1
    if (L.front() < 0) // if the front is less than 0
    {
        sign_val = -1; // sign value is set to -1
        negateList(L); // list is negated
    }
    L.moveBack();          // moving back in the list
    int carry = 0;         // setting the carry to 0
    ListElement value = 0; // setting the value to 0

    while (L.position() > 0) // while the position of the cursor is greater than 0
    {
        value = L.peekPrev() + carry; // value is set to the list previous element and carry is added to it
        carry = 0;                    // carry is set to 0
        if (value < 0)                // checking if the value is less than 0
        {
            carry = -1;    // setting the carry value to -1
            value += BASE; // cvalue is added with the BASE
        }
        L.setBefore(value % BASE); // setting the list element by value mod BASE
        carry += value / BASE;     // carry is added with the value of value divided by BASE
        L.movePrev();              // moving previous in the list
    }
    if (carry > 0) // checking if hec arry is less than 0
    {
        L.moveFront();        // moving front in the list
        L.insertAfter(carry); // insetting after the carry
    }
    return sign_val; /// returning the sign value
}

void shiftList(List &L, int p)
{
    L.moveBack();               // moving back in the list
    for (int i = 0; i < p; i++) // looping from 0 to the value p
    {
        L.insertAfter(0); // inserting 0 after in the list
    }
}

void BigInteger::makeZero()
{
    signum = 0;     // setting the sign to 0
    digits.clear(); // clearing the list
}

void BigInteger::negate()
{
    signum *= -1; // multiplying hte sign value to -1
}

BigInteger BigInteger::add(const BigInteger &N) const
{
    BigInteger sum;              // creating a variable of type BigInteger sum
    BigInteger tempthis = *this; // creating temp variable for this
    BigInteger tempn = N;        // creating temp variable for N
    int sign = 1;                // setting the sign to 1
    if (this->signum == -1)
    {                                // checking if this pointer's sign is equal -1
        negateList(tempthis.digits); // negating the this pointer's list
    }
    if (N.signum == -1)
    {              // Checking if the sign of N is equal to -1
        sign = -1; // setting the sign to -1
    }
    sumList(sum.digits, tempthis.digits, tempn.digits, sign); // summing the digits

    sum.signum = normalizeList(sum.digits); // sign of the number is stored by return value of normalizeList
    if (normalizeList(sum.digits) == -1)
    {                           // checking if the normalize list return value is negative
        negateList(sum.digits); // negating the list
    }

    return sum; // returning the sum
}

BigInteger BigInteger::sub(const BigInteger &N) const
{

    BigInteger ntemp = N;         // setting the temp variable to N
    negateList(ntemp.digits);     // negating the list
    BigInteger diff = add(ntemp); // calling add function on this and temp
    return diff;                  // returning the number
}

// Got help from George in the section Monday Date: May 22 2023 3:00pm - 5:00pm	BE 109
BigInteger BigInteger::mult(const BigInteger &N) const
{
    BigInteger prod; // decalring prod for storing the value
    if (this->signum == 0 || N.signum == 0)
    {                // checking if this pointer's sign or N's sign are equal to 0
        return prod; // returning the number
    }
    List sum;              // sum list is created
    List Ntemp = N.digits; // temp list is created and N's digits are stored
    int shift = 0;
    while (Ntemp.position() > 0) // while the N's position is greater than 0
    {
        List temp = this->digits;               // temp list is created and this pointer's digit are stored
        scalarMultList(temp, Ntemp.peekPrev()); // scalarmultlist is called ad temp list and N's temp list is getting the previous element
        shiftList(temp, shift);                 // shifting the list by the iterator
        List sumtemp = sum;                     // setting the sum's temp list to sum
        sumList(sum, sumtemp, temp, 1);         // summing the list and sign is set to 1
        normalizeList(sum);                     // normalizing the list
        ++shift;
        Ntemp.movePrev();
    }

    prod.digits = sum; // setting the prod to sum
    if (this->signum == N.signum)
    {                    // checking if the sign of both numbers are equal
        prod.signum = 1; // sign of prod is set to 1
    }
    else
    {                     // else
        prod.signum = -1; // sign of prod is set to -1
    }
    return prod; // prod is returned
}
// Got help from Amaan in the section Tuesday Date: May 23 2023 11:45pm - 1:00pm BE 109
std::string BigInteger::to_string()
{
    if (this->signum == 0)
    {               // checking if the sign of the this's pointer is equal to 0
        return "0"; // returning 0
    }
    std::string s = (this->signum == -1) ? "-" : "";   // if the sign of this pointer is equal to -1 then - sign is as a string is stored else empty string
    digits.moveFront();                                // Moving front in the digits
    while (digits.front() == 0 && digits.length() > 1) // looping while the front of the of the list is 0 and length is greater than 2
    {
        digits.eraseAfter(); // erasing after the cursor digits
    }
    digits.moveFront();                         // moving front in the digits list
    while (digits.position() < digits.length()) // while the length of digit list is greater than the position of the cursior in the list
    {
        std::string d = std::to_string(digits.peekNext());                         // rresursive call n the function and digits's next value is passed in the list
        std::string m = "";                                                        // empty string is decalred
        while ((int)m.length() + (int)d.length() < POWER && digits.position() > 0) // while the sum of length of both string is less than power and the List's cursor is greater than 0
        {
            m += '0'; // m string is appended with 0
        }
        s += m + d;        // s is appended wth m + d concat. string value
        digits.moveNext(); // moving next in the list
    }
    return s; // returning the stirng
}

std::ostream &operator<<(std::ostream &stream, BigInteger N)
{
    return stream << N.to_string(); // writing the n to the stream in string
}

bool operator==(const BigInteger &A, const BigInteger &B)
{
    return A.compare(B) == 0; // comapring A and B and check if the function return value is equal to 0
}

bool operator<(const BigInteger &A, const BigInteger &B)
{
    return A.compare(B) < 0; // comapring A and B and check if the function return value is less than to 0
}

bool operator<=(const BigInteger &A, const BigInteger &B)
{
    return A.compare(B) <= 0; // comapring A and B and check if the function return value is less than or equal to 0
}

bool operator>(const BigInteger &A, const BigInteger &B)
{
    return A.compare(B) > 0; // comapring A and B and check if the function return value is greater than to 0
}

bool operator>=(const BigInteger &A, const BigInteger &B)
{
    return A.compare(B) >= 0; // comapring A and B and check if the function return value is greater than equal to 0
}

BigInteger operator+(const BigInteger &A, const BigInteger &B)
{
    return A.add(B); // Adding A and B
}

BigInteger operator+=(BigInteger &A, const BigInteger &B)
{
    A = A.add(B); // Add A and B and re assigning the value to A
    return A;     // returning A
}

BigInteger operator-(const BigInteger &A, const BigInteger &B)
{
    return A.sub(B); // subtract A and B
}

BigInteger operator-=(BigInteger &A, const BigInteger &B)
{
    A = A.sub(B); // Subtract A and B and re assigning the value to A
    return A;     // returning A
}

BigInteger operator*(const BigInteger &A, const BigInteger &B)
{
    return A.mult(B); // Multiply A and B
}

BigInteger operator*=(BigInteger &A, const BigInteger &B)
{
    A = A.mult(B); // Multip;y A and B and re assigning the value to A
    return A;      // returning A
}