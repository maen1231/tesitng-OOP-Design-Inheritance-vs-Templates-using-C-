
#ifndef OOVSTEMPLATES_OOSTR_H
#define OOVSTEMPLATES_OOSTR_H
#include "IComparable.h"
#include <string>
#include <iostream>
using namespace std;

class OOStr : virtual public IComparable {
private:
    string data;
public:
    OOStr( string s );
    bool isLessThan(IComparable &comp);
    string getData() const;
    void print() const;
};
#endif //OOVSTEMPLATES_OOSTR_H
