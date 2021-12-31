// NAME: Ethan Sue
// FILE: intSet.cpp
// DESCRIPTION: Implementation of the IntSet class.

#include <iostream>
using namespace std;
#include "intSet.h"

IntSet::IntSet()
{
  set = 0; // initialize set to 0
}

bool IntSet::inBounds(int val) {
  if(val > 0 && val < 11) { //  make sure val is within the set bounds
    return true;
  }

  return false;
}

void IntSet::addElement(int val)
{
  if (inBounds(val)) {//  make sure val is within the set bounds

    if(!contains(val)) { // check if val is not in set
      int add = 1; // int amount to add to set to get 1 in correct bit place
      
      for (int i = 10; i > val; i--) { // use powers to make correct bit = 1
        add = add*2;
      }

      set = set+add; // add the integer to the set

    }
  }
}


void IntSet::removeElement(int val)
{
  if (inBounds(val)) {//  make sure val is within the set bounds

    if(contains(val)) { // check if val is in set
      int add = 1; // int amount to remove from set to get 0 in bit place

      for (int i = 10; i > val; i--) { // use powers to make correct bit = 0
        add = add*2;
      }

      set = set-add; // subtract the integer from the set

    }
  }
}


bool IntSet::contains(int val) const
{
  if ( (set >> (10-val)) % 2) { // if there is a one at the digt place of val
    return true;
  }

  return false;
  
}


void IntSet::printSet() const
{
  int elemNum = 0; // counts the number of elements printed
  
  cout << "{";

  for (int i = 1; i <= 10; i++) { // loop through each bit

    if (contains(i)) { // check if bit = 1
      elemNum++; // increment elemNum
      
      if (elemNum != 1) { // print comma if it is not the first element printed
        cout << ", ";
      }
        
      cout << i;
      
    }
  }

  cout << "}\n" << endl;
}


void IntSet::printBit() const
{
  //loop through each bit and check if bit = 1
  for (int i = 1; i<=10; i++) {
    
    if (contains(i)) 
      cout << "1";
    else
      cout << "0";
  }

  cout << endl;
}

IntSet IntSet::unions(const IntSet& operand) const
{
  IntSet b; // temporary IntSet
  if ( set != 0 && operand.set != 0) { // if neither are zero sets
    b.set = (set | operand.set); // use bitwise or to create union
    return b;
  }
  else if (operand.set == 0) { // if operand set is empty set
    b.set = set;
    return b;
  }

  b.set = operand.set;
  return b; // if set or both sets being unionized are zero sets
}


IntSet IntSet::intersect(const IntSet& operand) const
{
  IntSet b; // temporary IntSet
  if ( set != 0 && operand.set != 0) { // if neither are zero sets
    b.set = (set & operand.set); // use bitwise and to create intersection
    return b;
  }
  else // if either set is an empty set
    b.set = 0;

  return b;

}


IntSet IntSet::difference(const IntSet& operand) const
{
  IntSet b; // temporary IntSet
  IntSet c; // stores the complement of operand set
  
  if (set != operand.set) { // difference is not of  two sets with same val
    if ( set != 0 && operand.set != 0) { // if neither are zero sets
      // Set Subtraction Law: A-B = A.inserct(~B)
      c.set = ~operand.set;
      
      b = intersect(c);
      
      return b;
    }
    else if (operand.set == 0) { // if operand set is empty
      b.set = set;
      return b;
    }
    
  } 

  return b; // if set or both sets are zero sets
    
}


IntSet IntSet::complement() const
{
  IntSet b; // tempory IntSet
  
  b.set = ~set;

  return b; // return the temp IntSet
}
