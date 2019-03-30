class DynArray {
    public:

        DynArray();
        DynArray(int n);
        ~DynArray();
        int size();
        int capacity();
        void clear();
        void push_back(int n);
        void pop_back();
        int at(int n);
    private:
        int _size;
        int cap;
        int* data;

};