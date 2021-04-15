#include "60hw4.h"

//Creating the IntBag class which holds integers in a dynamic array and allows for functionality
//member functions
IntBag::IntBag(){
    size_ = 100;
    arr_ = new int[size_];
}

IntBag::IntBag(const IntBag& k){
    size_ = k.get_size();
    arr_ = new int[size_];
    for (int i=0; i<size_; i++){
        arr_[i] = k.get_point(i);
    }
}

void IntBag::add(const int item){
    
}

IntBag& IntBag::operator= (const IntBag& a){
    size_ = a.get_size();
    arr_ = new int[size_];
    for (int i=0; i<size_; i++){
        arr_[i] = a.get_point(i);
    }
}

void IntBag::fill(int c){
    for (int i=0; i<size_; i++){
        arr_[i] = c;
    }
}

void IntBag::deletes(int pos){
    for (int i=pos; i<size_; i++){
        if (i==pos){
            arr_[pos] = arr_[pos+1];
        }else if (i<(size_-1)){
            arr_[i] = arr_[i+1];
        }else{
            arr_[i] = 0;
        }
    }
}

void IntBag::clear(){
    arr_ = new int[NULL];
}

int IntBag::operator[](int index){
    return arr_[index];
}

//void IntBag::add(const int item){
    