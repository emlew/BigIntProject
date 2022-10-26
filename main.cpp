/*
This is the main program file. Its purpose is to
test all the methods in the bigint class; that is
all it needs to do.

Name: Emily Lewis
Date: 10/2/2022
*/

#include <iostream>
#include <string>
#include "bigint.h"

using namespace std;

int main( ) {
    // Test 1 - tests default constructor and print
    bigint x;
    
    cout << "Should print 0" << endl;
    x.print( );


    // Test 2 - adds in int constructor
    bigint y( 42 );

    cout << "Should print 42" << endl;
    y.print( );
    
    // Test 3 - tests the int set method
    x.set( 12345 );

    cout << "Should print 12345" << endl;
    x.print( );

    // Test 4 - tests the string constructor
    bigint z( "174" );

    cout << "Should print 174" << endl;
    z.print( );

    // Test 5 - tests the string set method
    x.set( "2725");

    cout << "Should print 2725" << endl;
    x.print( );

    // Test 6 - tests the bigint set method
    x.set( y );

    cout << "Should print 42" << endl;
    x.print( );

    // Test 7 - tests the increment method in 3 ways
    z.increment( );

    cout << "Should print 175" << endl;
    z.print( );

    z.set( 199 );
    z.increment( );

    cout << "Should print 200" << endl;
    z.print( );

    z.set( "999");
    z.increment( );

    cout<< "Should print 1000"  <<  endl;
    z.print( );

    // Test 8 - tests the add method
    x.add( 4 );

    cout << "Shoud print 46" << endl;
    x.print( );

    x.add( 15 );

    cout << "Should print 61" << endl;
    x.print( );

    x.add( 152 );

    cout << "Should print 213" << endl;
    x.print( );

    // Test 9 - tests the multiply method
    x.multiply( 2 );

    cout << "Should print 426" << endl;
    x.print( );

    x.multiply( 914 );

    cout << "Should print 389364" << endl;
    x.print( );
  
    // Destructor will get called when program
    // is complete. Can't explicitly call it.
}
