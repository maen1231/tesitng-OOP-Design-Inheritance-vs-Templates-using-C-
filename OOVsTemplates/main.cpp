#include <iostream>
#include "OOStr.h"
#include "OOInt.h"
#include <stdlib.h>
#include <vector>
#include "time.h"
#include "mergeSort.h"
#include "genericWrapper.h"
/*
 "C:\Users\marashdehm2\Desktop\CSC 402\OOVsTemplates\OOVsTemplates\cmake-build-debug\OOVsTemplates.exe"
OO tests for a size of 1000
Iter 1 Sort is valid for OOInt, size: 1000 time elapsed: 3
Iter 2 Sort is valid for OOInt, size: 1000 time elapsed: 3
Iter 3 Sort is valid for OOInt, size: 1000 time elapsed: 3
Iter 1 Sort is valid for OOStr, size: 1000 time elapsed: 4
Iter 2 Sort is valid for OOStr, size: 1000 time elapsed: 4
Iter 3 Sort is valid for OOStr, size: 1000 time elapsed: 4
OO tests for a size of 10000
Iter 1 Sort is valid for OOInt, size: 10000 time elapsed: 29
Iter 2 Sort is valid for OOInt, size: 10000 time elapsed: 22
Iter 3 Sort is valid for OOInt, size: 10000 time elapsed: 34
Iter 1 Sort is valid for OOStr, size: 10000 time elapsed: 43
Iter 2 Sort is valid for OOStr, size: 10000 time elapsed: 41
Iter 3 Sort is valid for OOStr, size: 10000 time elapsed: 30
OO tests for a size of 100000
Iter 1 Sort is valid for OOInt, size: 100000 time elapsed: 257
Iter 2 Sort is valid for OOInt, size: 100000 time elapsed: 245
Iter 3 Sort is valid for OOInt, size: 100000 time elapsed: 231
Iter 1 Sort is valid for OOStr, size: 100000 time elapsed: 299
Iter 2 Sort is valid for OOStr, size: 100000 time elapsed: 305
Iter 3 Sort is valid for OOStr, size: 100000 time elapsed: 307
OO tests for a size of 1000000
Iter 1 Sort is valid for OOInt, size: 1000000 time elapsed: 2848
Iter 2 Sort is valid for OOInt, size: 1000000 time elapsed: 3011
Iter 3 Sort is valid for OOInt, size: 1000000 time elapsed: 3072
Iter 1 Sort is valid for OOStr, size: 1000000 time elapsed: 3681
Iter 2 Sort is valid for OOStr, size: 1000000 time elapsed: 3784
Iter 3 Sort is valid for OOStr, size: 1000000 time elapsed: 4131



Generic tests for a size of 1000
Iter 1 Sort is valid for GenInt, size: 1000 time elapsed: 3
Iter 2 Sort is valid for GenInt, size: 1000 time elapsed: 3
Iter 3 Sort is valid for GenInt, size: 1000 time elapsed: 2
Iter 1 Sort is valid for GenStr, size: 1000 time elapsed: 2
Iter 2 Sort is valid for GenStr, size: 1000 time elapsed: 2
Iter 3 Sort is valid for GenStr, size: 1000 time elapsed: 3
Generic tests for a size of 10000
Iter 1 Sort is valid for GenInt, size: 10000 time elapsed: 23
Iter 2 Sort is valid for GenInt, size: 10000 time elapsed: 21
Iter 3 Sort is valid for GenInt, size: 10000 time elapsed: 22
Iter 1 Sort is valid for GenStr, size: 10000 time elapsed: 26
Iter 2 Sort is valid for GenStr, size: 10000 time elapsed: 23
Iter 3 Sort is valid for GenStr, size: 10000 time elapsed: 27
Generic tests for a size of 100000
Iter 1 Sort is valid for GenInt, size: 100000 time elapsed: 245
Iter 2 Sort is valid for GenInt, size: 100000 time elapsed: 196
Iter 3 Sort is valid for GenInt, size: 100000 time elapsed: 199
Iter 1 Sort is valid for GenStr, size: 100000 time elapsed: 309
Iter 2 Sort is valid for GenStr, size: 100000 time elapsed: 281
Iter 3 Sort is valid for GenStr, size: 100000 time elapsed: 285
Generic tests for a size of 1000000
Iter 1 Sort is valid for GenInt, size: 1000000 time elapsed: 2377
Iter 2 Sort is valid for GenInt, size: 1000000 time elapsed: 2538
Iter 3 Sort is valid for GenInt, size: 1000000 time elapsed: 2510
Iter 1 Sort is valid for GenStr, size: 1000000 time elapsed: 3770
Iter 2 Sort is valid for GenStr, size: 1000000 time elapsed: 3692
Iter 3 Sort is valid for GenStr, size: 1000000 time elapsed: 3559

Process finished with exit code 0

 */
using namespace std;

int main() {

    clock_t t; //initialize our clock
    srand( time( NULL));

    vector<IComparable *> * intVec = new vector<IComparable *>;
    vector<IComparable *> * strVec = new vector<IComparable *>;

    char charset[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                      't', 'u', 'v', 'w',
                      'x', 'y', 'z'};

    //the sizes of vectors we will sort
    int vals[] = { 1000, 10000,100000, 1000000};
    for ( int j = 0; j < sizeof(vals)/sizeof(*vals) ; j++ ) {
        cout << "OO tests for a size of " + to_string( vals[j]) << endl;
        for ( int k = 0; k < 3 ; k++ ) {

            for (int i = 0; i < vals[j]; i++) { //push random ints into test vector
                intVec->push_back(new OOInt(rand() % 1000));
            }
            //sort int vector first
            t = clock();
            mergeSort(*intVec);
            t = clock() - t;

            //verify the sort worked correctly for the int test vector
            if (verifySort(*intVec)) {
                cout <<
                     "Iter " + to_string(k+1) + " Sort is valid for OOInt, size: " + to_string(vals[j])
                     + " time elapsed: " + to_string(t)
                     << endl;
            }

            intVec->clear();
        }

        for ( int k = 0; k < 3 ; k++ ) {

            for (int i = 0; i < vals[j]; i++) { //push random strings into test vector
                int length = rand() % 4 + 1; //max length is four
                string str = "";
                for (int j = 0; j < length; j++) {
                    str = str + charset[rand() % sizeof(charset)];
                }
                strVec->push_back(new OOStr(str));
            }

            //now sort string vector
            t = clock();
            mergeSort(*strVec);
            t = clock() - t;


            if (verifySort(*strVec)) { //verify string vector was sorted correctly
                cout <<
                     "Iter " + to_string(k+1) + " Sort is valid for OOStr, size: " + to_string(vals[j]) +
                     " time elapsed: " + to_string(t)
                     << endl;
            }

            strVec->clear();
        }
    }
    cout << "\n\n\n";

    vector< genericWrapper<int> *> * gIntVec = new vector< genericWrapper<int> *>;
    vector< genericWrapper<string> *> * gStrVec = new vector< genericWrapper<string> *>;

    comparator<string> * strComp = new comparator<string>();
    comparator<int> * intComp = new comparator<int>();

    for ( int j = 0; j < sizeof(vals)/sizeof(*vals) ; j++ ) {
        cout << "Generic tests for a size of " + to_string( vals[j]) << endl;

        for ( int k = 0; k < 3 ; k++ ) {
            for (int i = 0; i < vals[j]; i++) {//push random int genericWrappers onto vector
                gIntVec->push_back(new genericWrapper<int>(rand() % 1000));
            }
            t = clock();
            mergeSort(*gIntVec, *intComp);
            t = clock() - t;

            if (verifySort(*gIntVec, *intComp)) { //verify genericWrapper<int> sort
                cout <<
                     "Iter " + to_string(k+1) + " Sort is valid for GenInt, size: " + to_string(vals[j])
                     + " time elapsed: " + to_string(t)
                     << endl;
            }

            gIntVec->clear();

        }

        for ( int k = 0; k < 3 ; k++ ) {

            for (int i = 0; i < vals[j]; i++) {//push random string genericWrappers onto vector
                int length = rand() % 4 + 1;
                string str = "";
                for (int j = 0; j < length; j++) {
                    str = str + charset[rand() % sizeof(charset)];
                }
                gStrVec->push_back(new genericWrapper<string>(str));
            }

            //test strings
            t = clock();
            mergeSort(*gStrVec, *strComp);
            t = clock() - t;

            if (verifySort(*gStrVec, *strComp)) { //verify genericWrapper<string> sort
                cout <<
                     "Iter " + to_string(k+1) + " Sort is valid for GenStr, size: " + to_string(vals[j]) +
                     " time elapsed: " + to_string(t)
                     << endl;
            }

            //clean up
            gStrVec->clear();
        }
    }

    delete intVec;
    delete strVec;
    delete gIntVec;
    delete gStrVec;
    delete intComp;
    delete strComp;
}

//for verification of sort
bool verifySort( vector<IComparable *> amISorted ) {
    for ( int i = 1; i < amISorted.size() ; i++ ){
        if ( !amISorted[i-1]->isLessThan( *amISorted[i])) return false;
    }
    return true;
}
void merge( vector<IComparable *> & merger, vector<IComparable *> vec1, vector<IComparable *> vec2 ){
    merger.clear();

    int i, j, k;

    for ( i=0,j=0,k=0 ; i < vec1.size() && j < vec2.size() ; k++ ){
        if ( vec1[i]->isLessThan( *vec2[j]) ){
            merger.push_back( vec1[i]);
            i++;
        }
        else if ( vec2[j]->isLessThan( *vec1[i])){
            merger.push_back( vec2[j]);
            j++;
        }

    }

    while ( i < vec1.size() ){
        merger.push_back( vec1[i] );
        i++;
    }

    while( j < vec2.size() ){
        merger.push_back( vec2[j]);
        j++;
    }

}

void mergeSort( vector<IComparable *> & vec ){
    queue< vector<IComparable *> > * mergeQ = new queue< vector<IComparable *> >;
    vector<IComparable* > * merger = new vector<IComparable*>;

    //push each element of the vector onto the queue
    for (int i = 0; i < vec.size(); i++ ){
        mergeQ->push( vector<IComparable *>( 1, vec[i] ));
    }

    while ( mergeQ->size() > 1 ){
        vector<IComparable *> numOne;
        vector<IComparable *> numTwo;
        numOne = mergeQ->front();
        mergeQ->pop();
        numTwo = mergeQ->front();
        mergeQ->pop();
        merge( *merger, numOne, numTwo );
        mergeQ->push( *merger );
    }

    vec = mergeQ->front();

    merger->clear();
    delete merger;
    delete mergeQ;

}