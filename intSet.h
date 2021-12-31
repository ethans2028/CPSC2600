// NAME: Ethan Sue
// FILE: intSet.h
// DESCRIPTION: Definition of the IntSet class.

#ifndef INTSET_H
#define INTSET_H


#include <iostream>
using namespace std;

class IntSet {

  private:
    //Complete the private section of the class
    int set; // pointer to bit vector
  
    bool inBounds(int val); // checks if inputted value is within universal set
    
  
  public: 
    
    // Default constructor: the domain of the set is {1, 2, 3, ..., 10}.
    // The set is initially a null set.
    IntSet();

    // Adds the value to the set if not already an element.
    void addElement(int val);

    // Removes the value if it is in the set.  
    // Nothing happens if the value is not in the set.
    void removeElement(int val);

    // Returns true if the set contains the value. 
    // Returns false otherwise.
    bool contains(int val) const;

    // Displays the set to the screen in the format: {1, 3, 4}
    void printSet() const;

    // Displays the set to the screen using the bit string format.
    void printBit() const;

    
    IntSet unions(const IntSet& operand) const;

    IntSet intersect(const IntSet& operand) const;

    IntSet difference(const IntSet& operand) const;

    IntSet complement() const;


};

#endif
