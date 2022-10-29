#include "OOInt.h"
#include <iostream>


OOInt::OOInt(int d) : data(d) {}

bool OOInt::isLessThan( IComparable & comp ) {
    auto & other = dynamic_cast<OOInt &>(comp);
    return other.getData() >= data;
}

int OOInt::getData() const {
    return data;
}

void OOInt::print() const {
    cout << to_string(data) << endl;
}