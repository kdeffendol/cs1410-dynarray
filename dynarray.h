/**
 * header file
 * CS 1410
 * Project 9
 * Author: Kelsey Deffendol
 * Date last modified: June 2019
 * 
 * Purpose: To create a DynArray class using a template
 */


#include <iostream>
using namespace std;

template<typename T>
class DynArray {
    public:

        DynArray();
        DynArray(int n);
        ~DynArray();
        int size() const;
        int capacity() const;
        void clear();
        void push_back(const T& n);
        void pop_back();
        T& at(int n) const;

        T& back();
        T& front();
        DynArray(const DynArray<T>& origObject);
        DynArray& operator=(const DynArray<T>& origObject);
        //T& operator[] (int& n);

    private:
        int _size;
        int cap;
        T* data;
        

};


/**
 * constructor creating a new dynarray with the default capacity and size.
 */
template<typename T>
DynArray<T>::DynArray() {
    //data = nullptr;
    cap = 2; //max
    _size = 0; //elements stored by user
    data = new T[cap];
}

/**
 * constructor creating a new dynarray with capacity inputted by user and size.
 * @param n: capacity of the dynamic array.
 */
template<typename T>
DynArray<T>::DynArray(int n) {
    cap = n;
    _size = 0;
    data = new T[cap];
}

/**
 * copy constructor - copies data into a new array
 * @param origObject - original dynamic array 
 */
template<typename T>
DynArray<T>::DynArray(const DynArray<T>& origObject) {
    cout << "copy" << endl;

    //copy array   
    data = new T[origObject.capacity()];
    _size = origObject.size();
    cap = origObject.capacity();

    for(int i=0; i<origObject.size(); i++) {
        data[i] = origObject.at(i);
    }
}

/**
 * copy assignment operator
 * @param origObject - original dynamic array
 */
template<typename T>
DynArray<T>& DynArray<T>::operator=(const DynArray<T>& origObject) {
    cout << "assign" << endl;

    if (this != &origObject) {
        delete [] data;

        data = new T[origObject.capacity()];
        cap = origObject.capacity();
        _size = origObject.size();

        for (int i=0; i < origObject.size(); i++) {
            data[i] = origObject.at(i);
        }
    }

    return *this;
}

/**
 * deconstructor
 */
template<typename T>
DynArray<T>::~DynArray() {
    delete [] data;
    data = nullptr;
}

/**
 * getter function for size
 * @return size of dyn array
 */
template<typename T>
int DynArray<T>::size() const {
    return _size;
}

/**
 * getter function for capacity
 * @return capacity of the dyn array
 */
template<typename T>
int DynArray<T>::capacity() const {
    return cap;
}

/**
 * changes dyn array to default size and capacity and removes all elements
 * @return new empty dyn array with default sizing
 */
template<typename T>
void DynArray<T>::clear() {
    _size = 0;
    cap = 2;
    delete [] data;
    data = new T[cap];
}

/**
 * stores the next value in the array, increments size if needed
 * @param n - new value to be set into array
 */
template<typename T>
void DynArray<T>::push_back(const T& n) {
    //store next value
    //increment the size

    if (_size >= cap) {
        //allocate new array (double cap)
        cout << "grow" << endl;
        T* tempPtr = new T[cap*2];
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

/**
 * moves size one back to delete the last element in the array
 */
template<typename T>
void DynArray<T>::pop_back() {
    _size--;
}

/**
 * returns the indicated data point at the given index number
 * @param index - index of item being returned
 * @return item and given index
 */
template<typename T>
T& DynArray<T>::at(int index) const {
    if (index >= _size || index < 0) {
        throw runtime_error("invalid index");
    }
    return data[index];
}

/**
 * returns last item of the array
 * @return the last item in array
 */
template<typename T>
T& DynArray<T>::back() {
    if (size() == 0) {
        throw runtime_error("empty array");
    }
    return data[size()-1];
}

/**
 * returns the first item in the array
 * @return the first item in array
 */
template<typename T>
T& DynArray<T>::front() {
    if (size() == 0) {
        throw runtime_error("empty array");
    }
    return data[0];
}

