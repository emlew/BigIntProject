/*
The bigint class is used to represent positive 
integers. It can represent any integer 0 or 
larger, with an arbitrary number of digits.

Name: Emily Lewis
Date: 10/2/2022

*/

#include <string>
using namespace std;


// The node struct defines the node used in
// our linked list to store the digits of
// the bigint.

struct node {
    public:
        int data;
        node* next;
};

class bigint {
    private:
        // Represents the first node in the
        // linked list. In this code, that
        // node represents the final digit
        // in the number - the number is 
        // stored backwards. This pointer 
        // should never be NULL at the end
        // of a method call!
        node* head;


    public:
        // The default constructor creates
        // the bigint so that it has a value of 0.
        bigint( );

        // This constructor creates the bigint
        // so that it represents the value of n.
        bigint( int n );

        // This constructor creates the bigint
        // so that it represents the value of n.
        // We assume that the string n is a string
        // that represents an integer.
        bigint( string n );

        // The destructor destroys the entire
        // linked list (meaning delete all the 
        // nodes). This is the only method that can
        // have head equal to NULL at the end.
        ~bigint( );

        // All of the set methods change the
        // value of the bigint to represent n. Note
        // that this bigint will have a value in it
        // already, so it will destroy the old list and 
        // construct a new one rather than to try to
        // modify the existing list.
        void set( int n );

        void set( string n );

        void set( const bigint &n );

        // This method increases the value
        // stored in the bigint by 1.
        void increment( );

        // This method increases the value
        // stored in the bigint by n.
        void add( int n );

        // This method sets the value of the 
        // bigint to be equal to its current
        // value multiplied by n.
        void multiply( int n );

        // This prints the value represented
        // by the bigint. All digits are on
        // a single line, and it moves to the
        // next line when it is done printing.
        void print( );

        // This method allows for printing the value
        // recursively since it takes a parameter.
        void printRecursive( node* head );

        // This method works in conjunction with the 
        // constructors for bigint and other methods. 
        // It works by creating a new node with data
        // n and adding that node to the beginning 
        // of the list.
        void addDigit( int n, node* &head );

};
