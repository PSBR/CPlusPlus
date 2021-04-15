#include <iostream>
#include <string>

//header file for the dynamic array assignment 

class IntBag {
    const static int capacity = 128;
    const static int mult = 2;
    public:
        IntBag();//finished
        IntBag(const IntBag& k);//finished
        void add(const int item);
        int get_size() const {return size_;};//finished
        void set_size(int size) {size_ = size;};//finished
        int get_point (int index) const {return arr_[index];};
        void fill(int c);//finished
        void clear();
        void deletes(int pos);
        int operator[](int index);
        IntBag& operator= (const IntBag& a); 
    
    private:
        int* arr_;
        int size_;

};