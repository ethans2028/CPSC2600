// NAME: Ethan Sue
// FILE: hw3.cpp
// DESCRIPTION: Tests IntSet class

#include <iostream>
using namespace std;
#include "intSet.h"

int main()
{
  

  // HW 3 Tests

  cout << "HW 3 provided tests: \n" << endl << endl;
  
  // 1a)
  
  IntSet A;

  // add all even numbers within the univ. domain to the set
  for (int x = 2; x <= 10; x+=2)
    A.addElement(x);

  // 1b)

  IntSet B;

  // add all numbers divisible by 3 within the univ. domain to the set
  for (int x = 1; x <= 10; x++) {
    if (!(x%3)) // if x is divisible by 3, add it to the set
      B.addElement(x);
  }
  
  // 1c)

  IntSet C;

  // add the values: 1,2,3,6,9 to the set
  C.addElement(1);
  C.addElement(2);
  C.addElement(4);
  C.addElement(6);
  C.addElement(9);

  
  // 2a)
  
  IntSet D;
  D = A.complement(); // to avoid operator overload, use union to make D
                      // equal to the complement of A
  
  // 2b)
  
  IntSet E;
  E = A.unions(B);

  // 2c)

  IntSet F;
  F = B.intersect(C);
  
  // 2d)

  IntSet G;
  G = A.difference(B);

  // 2e)

  IntSet H;
  H = B.unions(A.intersect(C));

  // 2f)

  IntSet I;
  I = A.unions(B);
  I = I.difference(C);


  // 3)

  // print A
  cout << "A: ";
  A.printBit();
  cout << endl;

  // print B
  cout << "B: ";
  B.printBit();
  cout << endl;

  // print C
  cout << "C: ";
  C.printBit();
  cout << endl;


  // 4)

  // print D
  cout << "D: ";
  D.printSet();
  cout << endl;

  // print E
  cout << "E: ";
  E.printSet();
  cout << endl;

  // print F
  cout << "F: ";
  F.printSet();
  cout << endl;

  // print G
  cout << "G: ";
  G.printSet();
  cout << endl;

  // print H
  cout << "H: ";
  H.printSet();
  cout << endl;

  // print I
  cout << "I: ";
  I.printSet();
  cout << endl;


  // 5)

  cout << "H contains 6: ";
  if (H.contains(6))
    cout << "True" << endl;
  else
    cout << "False" << endl;


  cout << "D contains 2: ";
  if (D.contains(2))
    cout << "True" << endl;
  else
    cout << "False" << endl;


  
  // My tests
  cout << endl << endl << "My tests: \n" << endl << endl;

  // Test 1: Testing bounds of remove and addElemenet functions.
  // Also testing printing empty function

  cout << "Test 1: \n\n";
  
  IntSet t1;

  t1.addElement(-1);
  t1.addElement(0);
  t1.addElement(12);

  t1.removeElement(-1);
  t1.removeElement(0);
  t1.removeElement(12);

  // print t1
  cout << "t1: ";
  t1.printSet();
  cout << endl;


  // Test 2: Testing adding a value which exists in the set, and removing one
  // that does not.

  cout << "Test 2: \n\n";
  
  t1.addElement(1);
  t1.addElement(6);
  t1.addElement(6);

  // print t1
  cout << "t1: ";
  t1.printSet();
  cout << endl;

  t1.removeElement(1);
  t1.removeElement(2);
  t1.removeElement(10);

  // print t1
  cout << "t1: ";
  t1.printSet();
  cout << endl;


  // Test 3: Testing "unions" function.

  cout << "Test 3: \n\n";

  // Case 1: Union of two empty sets
  cout << "Case 1: \n";

  IntSet t2;
  IntSet t3;

  t1 = t2.unions(t3);

  cout << "t1: ";
  t1.printSet();
  cout << endl;

  // Case 2: Union of same set
  cout << "Case 2: \n";

  t2.addElement(1);
  t2.addElement(4);
  t2.addElement(8);

  t1 = t2.unions(t2);

  cout << "t2: ";
  t2.printSet();
  cout << endl;

  // Case 3: Union where one set is empty
  cout << "Case 3: \n";

  t1 = t2.unions(t3);

  cout << "t1: ";
  t1.printSet();
  cout << endl;

  t1 = t3.unions(t2);

  cout << "t1: ";
  t1.printSet();
  cout << endl;

  
  // Test 4: Testing "intersect" function.

  cout << "Test 4: \n\n";

  // Case 1: Intersect of two empty sets
  cout << "Case 1: \n";

  IntSet t4;
  IntSet t5;

  t1 = t4.intersect(t5);

  cout << "t1: ";
  t1.printSet();
  cout << endl;

  // Case 2: Intersect of same set
  cout << "Case 2: \n";

  t4.addElement(1);
  t4.addElement(4);
  t4.addElement(8);

  t1 = t4.intersect(t4);

  cout << "t4: ";
  t4.printSet();
  cout << endl;

  // Case 3: Intersect where one set is empty
  cout << "Case 3: \n";

  t1 = t4.intersect(t5);

  cout << "t1: ";
  t1.printSet();
  cout << endl;

  t1 = t5.intersect(t4);

  cout << "t1: ";
  t1.printSet();
  cout << endl;


  // Test 5: Testing "difference" function.

  cout << "Test 5: \n\n";

  // Case 1: difference of two empty sets
  cout << "Case 1: \n";

  IntSet t6;
  IntSet t7;

  t1 = t6.difference(t7);

  cout << "t1: ";
  t1.printSet();
  cout << endl;

  // Case 2: difference of same set
  cout << "Case 2: \n";

  t6.addElement(1);
  t6.addElement(4);
  t6.addElement(8);

  t1 = t6.difference(t6);

  cout << "t6: ";
  t6.printSet();
  cout << endl;

  // Case 3: difference where one set is empty
  cout << "Case 3: \n";

  t1 = t6.difference(t7);

  cout << "t1: ";
  t1.printSet();
  cout << endl;

  t1 = t7.difference(t6);

  cout << "t1: ";
  t1.printSet();
  cout << endl;

  return 0;
}
