#include "dynarray.h"
#include <iostream>
using namespace std;

DynArray::DynArray() {
    //data = nullptr;
    cap = 2; //max
    _size = 0; //elements stored by user
    data = new int[cap];
}

DynArray::DynArray(int n) {
    cap = n;
    _size = 0;
    data = new int[cap];
}
//deconstructor
DynArray::~DynArray() {
    delete [] data;
    data = nullptr;
}

int DynArray::size() {
    return _size;
}

int DynArray::capacity() {
    return cap;
}

void DynArray::clear() {
    _size = 0;
    cap = 2;
    delete [] data;
    data = new int[cap];
}

void DynArray::push_back(int n) {
    //store next value
    //increment the size

    if (_size >= cap) {
        //allocate new array (double cap)
        int* tempPtr = new int[cap*2];
        for (int i=0; i<cap; i++) {
            tempPtr[i] = data[i];
        }
        delete [] data;
        cap *= 2;
        data = tempPtr; // makes data pointer point to the new array
    }
    data[_size] = n;
    _size++;
}

void DynArray::pop_back() {
    _size--;
}

int DynArray::at(int n) {
    if (n >= _size || n < 0) {
        throw runtime_error("invalid index");
    }
    return data[n];
}