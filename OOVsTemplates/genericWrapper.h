
#ifndef OOVSTEMPLATES_GENERICWRAPPER_H
#define OOVSTEMPLATES_GENERICWRAPPER_H
#include <iostream>
#include <string>
using namespace std;

//generic wrapper class
template < typename T >
class genericWrapper {
private:
    T data;
public:
    explicit genericWrapper( T initvalue = T() ) : data( initvalue ) {};
    T getData() const{
        return data;
    };
    void print() const{
        cout << to_string(data) << endl;
    };

};

//functor for genericWrapper objects
template < typename T >
class comparator {
public:
    bool operator()( genericWrapper<T> & rhs, genericWrapper<T> & lhs ){
        return !(lhs.getData() > rhs.getData());
    };
};


#endif //OOVSTEMPLATES_GENERICWRAPPER_H
