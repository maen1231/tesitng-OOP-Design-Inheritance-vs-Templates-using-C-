#include "OOStr.h"

OOStr::OOStr( string s ) : data(s) {};

string OOStr::getData() const {
    return data;
}

bool OOStr::isLessThan(IComparable & comp) {
    OOStr & other = dynamic_cast<OOStr &>(comp);
    return other.getData() >= data;
}

void OOStr::print() const {
    cout << data << endl;
}