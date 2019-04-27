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

template<typename T>
DynArray<T>::DynArray() {
    //data = nullptr;
    cap = 2; //max
    _size = 0; //elements stored by user
    data = new T[cap];
}

template<typename T>
DynArray<T>::DynArray(int n) {
    cap = n;
    _size = 0;
    data = new T[cap];
}

//new
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

//new
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

//deconstructor
template<typename T>
DynArray<T>::~DynArray() {
    delete [] data;
    data = nullptr;
}

template<typename T>
int DynArray<T>::size() const {
    return _size;
}

template<typename T>
int DynArray<T>::capacity() const {
    return cap;
}

template<typename T>
void DynArray<T>::clear() {
    _size = 0;
    cap = 2;
    delete [] data;
    data = new T[cap];
}

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

template<typename T>
void DynArray<T>::pop_back() {
    _size--;
}

template<typename T>
T& DynArray<T>::at(int index) const {
    if (index >= _size || index < 0) {
        throw runtime_error("invalid index");
    }
    return data[index];
}

template<typename T>
T& DynArray<T>::back() {
    if (size() == 0) {
        throw runtime_error("empty array");
    }
    return data[size()-1];
}

template<typename T>
T& DynArray<T>::front() {
    if (size() == 0) {
        throw runtime_error("empty array");
    }
    return data[0];
}

