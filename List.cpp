/*
============================================
Name: Anurag Prashant Umale                =
Student Id: 1887255                        =
E-mail: aumale@ucsc.edu                    =
File: List.cpp (Implementation of List ADT)=
Class: CSE 101 Spring 2023                 =
============================================
*/

#include "List.h" // including the list header file


// Constructor for the node in the list
List::Node::Node(ListElement x) 
{
    data = x; // setting the data to data
    next = nullptr; // setting the next pointer to null pointer
    prev = nullptr; // setting the prev pointer to null pointer
}

// constructor for the List
List::List()
{
    frontDummy = new Node(-1); // dynamically allocating memory for node for frontDummy
    backDummy = new Node(1); // dynamically allocating memory for node for backDummy
    frontDummy->next = backDummy; // setting the frontDummy's next pointer to backDummy
    backDummy->prev = frontDummy; // setting the backDummy's prev pointer to frontDummy
    beforeCursor = frontDummy; // setting the beforeCursor to the frontDummy
    afterCursor = backDummy; // setting the afterCursor to the backDummy
    pos_cursor = 0; // setting the pos_cursor to 0
    num_elements = 0; // setting the number of elements to 0
}

// copy constructor for the List
List::List(const List &L)
{
    frontDummy = new Node(-1); // dynamically allocating memory for node for frontDummy
    backDummy = new Node(1); // dynamically allocating memory for node for backDummy
    frontDummy->next = backDummy; // setting the frontDummy's next pointer to backDummy
    backDummy->prev = frontDummy; // setting the backDummy's prev pointer to frontDummy
    beforeCursor = frontDummy; // setting the beforeCursor to the frontDummy
    afterCursor = backDummy; // setting the afterCursor to the backDummy
    pos_cursor = 0; // setting the pos_cursor to 0
    num_elements = 0; // setting the number of elements to 0

    Node *N = L.frontDummy->next; // setting the N to the parameter's dummy's next pointer
    while (N != L.backDummy) // while N is not equal to the pararmeter's backDummy pointer
    {
        this->insertBefore(N->data); // data is added to the newly created list from the paramter's list
        N = N->next; // N is assigned by the N's next pointer
    }
}

// destructor for the List
List::~List() 
{
    this->clear(); // calling the clear function in the
    delete frontDummy; // freeing the frontDummy's allocated memory
    delete backDummy; // freeing the backDummy's allocated memory
}

// Access Function
int List::length() const
{
    return num_elements; // returning the number of elements in the list
}

ListElement List::front() const
{
    if (length() <= 0) // checking if length of the list is less than or equal to 0
    {
        throw std::length_error("1. List Error.\n2. ListElement List::front() const.\n3. Calling Function on Empty List.\n"); // throwing the error and error message
    }
    return frontDummy->next->data; // returning the frontDummy's next pointer's data
}

ListElement List::back() const
{
    if (length() <= 0) // checking if length of the list is less than or equal to 0
    {
        throw std::length_error("1. List Error.\n2. ListElement List::back() const.\n3. Calling Function on Empty List.\n"); // throwing the error and error message
    }
    return backDummy->prev->data; // returning the backDummy's next pointer's data
}

int List::position() const
{
    return pos_cursor; // returning the pos_cursor value
}

ListElement List::peekNext() const
{

    if (position() == length()) // checking if the postion of the cursor is equal to the length of the list
    {
        throw std::range_error("1. List Error.\n2. ListElement List::peekNext() const.\n3. Cursor at back.\n"); // throwing the error and error message
    }
    if (position() > length()) // checking if position is greater than the length of the list
    {
        throw std::range_error("1. List Error.\n2. List:ListElement List::peekNext() const.\n3. Cursor at front\n"); // throwing the error and error message
    }
    return afterCursor->data; // returning the afterCursor's data
}

ListElement List::peekPrev() const
{

    if (position() == 0) // checking if the postion of the cursor is equal to 0
    {
        throw std::range_error("1. List Error.\n2. ListElement List::peekPrev() const.\n3. Cursor at back.\n"); // throwing the error and error message
    }
    if (position() < 0) // checking if the position of the cursor is less than 0
    {
        throw std::range_error("1. List Error.\n2. ListElement List::peekPrev() const.\n3. Cursor at front.\n"); // throwing the error and error message
    }
    return beforeCursor->data; // returning the beforeCursor's data
}

void List::clear()
{
    moveFront(); // moving front in the list
    while (length() > 0) // while the length of the list is greater than 0
    {
        eraseAfter(); // calling the eraseAfter function and delete the elements in the list
    }
}

void List::moveFront()
{
    beforeCursor = frontDummy; // setting the beforeCursor to the forntDummy
    afterCursor = frontDummy->next; // setting the afterCursor to the frontDummy's next pointer
    pos_cursor = 0; // pos_cursor is set to 0
}

void List::moveBack()
{
    beforeCursor = backDummy->prev; // before cursror is set to backDummy's previous pointer
    afterCursor = backDummy; // afterCursor is set to backDummy
    pos_cursor = length(); // setting the pos_cursor to the length of the list
}

ListElement List::moveNext()
{

    if (position() == length()) // checking if the postion of the cursor is equal to the length of the list
    {
        throw std::range_error("1. List Error.\n2. ListElement List::moveNext().\n3. Cursor at back.\n"); // throwing the error and error message
    }
    if (position() > length()) // checking if position is greater than the length of the list
    {
        throw std::range_error("1. List Error.\n2. ListElement List::moveNext().\n3. Cursor at front\n"); // throwing the error and error message
    }
    beforeCursor = afterCursor; // setting the beforeCursor to afterCursor
    afterCursor = afterCursor->next; // afterCursor is set to afterCursor's next pointer
    pos_cursor++; // pos_cursor is incremented by 1
    return beforeCursor->data; // returning the beforeCursor's 
}

ListElement List::movePrev()
{

    if (position() == 0) // checking if the postion of the cursor is equal to 0
    {
        throw std::range_error("1. List Error.\n2. ListElement List::movePrev().\n3. Cursor at front\n"); // throwing the error and error message
    }
    if (position() < 0) // checking if the position of the cursor is less than 0
    {
        throw std::range_error("1. List Error.\n2. ListElement List::movePrev().\n3. Cursor at back.\n"); // throwing the error and error message
    }
    afterCursor = beforeCursor; // afterCursor is set to beforeCursor
    beforeCursor = beforeCursor->prev; // beforeCursor is set to beforeCursor's previous pointer
    pos_cursor--; // pos_cursor is decremented
    return afterCursor->data; // afterCursor's data is returned
}

void List::insertAfter(ListElement x)
{
    Node *N = new Node(x); // creating the node for the data
    N->prev = beforeCursor; // setting the new node's previous pointer to beforeCursor
    N->next = afterCursor; // setting the new node's next pointer to afterCursor
    beforeCursor->next = N; // beforeCursor's next pointer is set to new node
    afterCursor->prev = N; // afterCursor's previous node is set to new node
    afterCursor = N; //`afterCursor is set to new node
    num_elements++; // number of elements is incremented by 1
}

void List::insertBefore(ListElement x)
{
    Node *N = new Node(x); // creating the node for the data
    N->prev = beforeCursor; // setting the new node's previous pointer to beforeCursor
    N->next = afterCursor; // setting the new node's next pointer to afterCursor
    beforeCursor->next = N; // beforeCursor's next pointer is set to new node
    afterCursor->prev = N; // afterCursor's previous is set to new node
    beforeCursor = N; // beforeCursor is set to new node
    pos_cursor++; // pos_cursor is incremented by 1
    num_elements++; // number of elements is incremeanted by 1
}

void List::setAfter(ListElement x)
{

    if (position() == length()) // checking if the postion of the cursor is equal to the length of the list
    {
        throw std::range_error("1. List Error.\n2. void List::setAfter(ListElement x).\n3. Cursor at back.\n"); // throwing the error and error message
    }
    if (position() > length()) // checking if position is greater than the length of the list
    {
        throw std::range_error("1. List Error.\n2. void List::setAfter(ListElement x).\n3. Cursor at front\n"); // throwing the error and error message
    } 
    afterCursor->data = x; // afterCursor's data is set to x
}

void List::setBefore(ListElement x)
{

    if (position() == 0) // checking if the postion of the cursor is equal to 0
    {
        throw std::range_error("1. List Error.\n2. void List::setBefore(ListElement x).\n3. Cursor at front\n"); // throwing the error and error message
    }
    if (position() < 0) // checking if the position of the cursor is less than 0
    {
        throw std::range_error("1. List Error.\n2. void List::setBefore(ListElement x).\n3. Cursor at back.\n"); // throwing the error and error message
    }
    beforeCursor->data = x; // beforeCursor's data is set to x
}

void List::eraseAfter()
{

    if (position() == length()) // checking if the postion of the cursor is equal to the length of the list
    {
        throw std::range_error("1. List Error.\n2. void List::eraseAfter().\n3. Cursor at back.\n"); // throwing the error and error message
    }
    if (position() > length()) // checking if position is greater than the length of the list
    {
        throw std::range_error("1. List Error.\n2. void List::eraseAfter().\n3. Cursor at front\n"); // throwing the error and error message
    }
    Node *N = afterCursor; // setting a new node to afterCursor
    beforeCursor->next = N->next; // beforeCursor's next pointer is set to new nodes next pointer
    afterCursor->next->prev = beforeCursor; // afterCursor's next's previous pointer is set to beforeCursor
    afterCursor = N->next; // afterCursor is set to new node's next pointer
    delete N; // deleting the new node
    num_elements--; // decremementing hte number of elements by 1
}

void List::eraseBefore()
{

    if (position() == 0) // checking if the postion of the cursor is equal to 0
    {
        throw std::range_error("1. List Error.\n2. void List::eraseBefore().\n3. Cursor at front\n"); // throwing the error and error message
    }
    if (position() < 0) // checking if the position of the cursor is less than 0
    {
        throw std::range_error("1. List Error.\n2. void List::eraseBefore().\n3. Cursor at back.\n"); // throwing the error and error message
    }
    Node *N = beforeCursor; // node pointer is set to beforeCursor
    afterCursor->prev = N->prev; // afterCursor's previous pointer is set to node's previous pointer
    afterCursor->prev->next = afterCursor; // afterCursor's previous's next pointer is set to afterCursor
    beforeCursor = N->prev; // beforeCursor is set to node's previous pointer
    delete N; // deleting the node
    num_elements--; // number of elements is decremented by 1
    pos_cursor--; // pos_cursor is decremented by 1
}

int List::findNext(ListElement x)
{
    while (position() < length()) // while the position of the cursor is less than the length of the list
    {
        if (peekNext() == x) // checking if the next is equal to x
        {
            moveNext(); // moving next in list
            return position(); // returning the position of the element found
        }
        moveNext(); // moving next in list
    }
    return -1; // returning -1 on not finding the element
}

int List::findPrev(ListElement x)
{
    while (position() > 0) // while the position is greater than 0
    {
        if (peekPrev() == x) // checking if the previous element is equal to the x
        {
            movePrev(); // moving back in list
            return position(); // retuning the position of the previous element
        }
        movePrev(); // moving back in the list
    }
    return -1; // returning -1 if the element is not found
}

void List::cleanup()
{
    int current_pos = 0; // setting thr current position to 0
    Node *current_node = frontDummy->next; // setting the current node to frontDummy's next pointer
    while (current_node != backDummy) // while the current_node is not equal to backDummy
    {
        int compare_pos = current_pos + 1; // compare position is set to current position plus 1
        Node *compare_node = current_node->next; // comapre node is set to current node's next pointer
        while (compare_node != backDummy) // while the compare_node is not equal to backDummy
        {
            Node *prev_node = compare_node->prev; // setting a new previous node pointer to compare node's previous pointer
            if (compare_node->data == current_node->data) // checking if the compare 
            {
                if (compare_node == beforeCursor) // comapring if the comapre_node equal to beforeCursor
                {
                    eraseBefore(); // erase the data before in list
                    compare_node = prev_node; // setting the comapre_code to prev_node
                }
                else if (compare_node == afterCursor) // else checking if comapre_node equal to afterCursor
                {
                    eraseAfter(); // erase the data after in the list
                    compare_node = prev_node; // setting the comapre_code to prev_node
                }
                else // else
                {
                    Node *temp = compare_node; // setting the temp node pointer to compare_node
                    compare_node = compare_node->prev; // setting the compare_node to comapre_node's previous pointer
                    temp->prev->next = temp->next; // setting the temp's previous next to temp's next pointer
                    temp->next->prev = temp->prev; // setting the temp's next previous to temp's previous pointer
                    delete temp; // freeing the temp pointer
                    num_elements--; // decrementing the number of elements
                    if (compare_pos <= position()) // checking if the the compare_pos is less than or equal to position
                    {
                        pos_cursor--; // decrementing the pos_cursor
                    }
                }
            }
            compare_node = compare_node->next; // compare_node is set to comapre_node's next pointer
            compare_pos++; // compare_pos is increamneted by 1
        }
        current_node = current_node->next; // current_node is set to current_node's next pointer
        current_pos++; // current_pos is increamneted by 1
    }
}

List List::concat(const List &L) const
{
    List M = List(); // creating new list
    for (Node *n1 = frontDummy->next; n1 != backDummy; n1 = n1->next) // loop from frontDummy's next node till backDummy
    {
        M.insertBefore(n1->data); // adding the data in the newlist
    }
    for (Node *n2 = L.frontDummy->next; n2 != L.backDummy; n2 = n2->next) // loop from list's from frontDummy's next node till backDummy
    {
        M.insertBefore(n2->data); // adding the data in the new list
    }
    M.moveFront(); // moving front in the list
    return M; // returning the new list
}

std::string List::to_string() const
{
    std::string s = "("; // creating a standard staring 
    for (Node *N = frontDummy->next; N != backDummy; N = N->next) // looping from frontDummy's next node till backDummy
    {
        s += std::to_string(N->data) + (N != backDummy->prev ? ", " : ")"); // printing data and printing , if node is not backDummy's previous pointer else ) is printed
    }
    return s; // string is returned
}

bool List::equals(const List &R) const
{
    if (length() != R.length()) // checkng if the list's length are equal
    {
        return false; // returning false
    }
    for (Node *N = frontDummy->next, *M = R.frontDummy->next; N != backDummy; N = N->next, M = M->next) // Looping from frontDummy's next ponter to backDummy
    {
        if (N->data != M->data) // checking if data is equal in the list
        {
            return false; // returning false
        }
    }
    return true; // returning true
}

std::ostream &operator<<(std::ostream &stream, const List &L)
{
    return stream << L.List::to_string(); // returning the list string printed in the stream
}

bool operator==(const List &A, const List &B)
{
    return A.List::equals(B); // returning the boolean value if the list's are equal
}

List &List::operator=(const List &L)
{
    if (this != &L) // checking if this pointer is equal to the L
    {
        List temp = L; // temp List is set to L
        std::swap(frontDummy, temp.frontDummy); // swapping the frontDummy value to temp's frontDummy
        std::swap(backDummy, temp.backDummy); // swapping the backDummy value to temp's backDummy
        std::swap(beforeCursor, temp.beforeCursor); // swapping beforeCursor to temp's beforeCursor
        std::swap(afterCursor, temp.afterCursor); // swapping afterCursor to temp's afterCursor
        std::swap(pos_cursor, temp.pos_cursor); // swapping pos_cursor to temp's pos_cursor
        std::swap(num_elements, temp.num_elements); // swapping num_elements to temp's num_elements
    }
    return *this; // returning the pointer to list
}