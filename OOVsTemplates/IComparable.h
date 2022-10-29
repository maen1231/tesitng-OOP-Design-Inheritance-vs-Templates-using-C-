
#ifndef OOVSTEMPLATES_ICOMPARABLE_H
#define OOVSTEMPLATES_ICOMPARABLE_H
class IComparable {
public:
    virtual bool isLessThan( IComparable & other ) = 0;

};
#endif //OOVSTEMPLATES_ICOMPARABLE_H
