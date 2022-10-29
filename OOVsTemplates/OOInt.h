
#ifndef OOVSTEMPLATES_OOINT_H
#define OOVSTEMPLATES_OOINT_H
#include <iostream>
#include <string>
#include "IComparable.h"

using namespace std;
class OOInt : virtual public IComparable {
private:
    int data;
public:
    OOInt( int d );
    bool isLessThan( IComparable & other );
    int getData() const;
    void print() const; //used for testing

};
#endif //OOVSTEMPLATES_OOINT_H
