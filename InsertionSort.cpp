#include <algorithm>
#include <iostream>
#include <cstdlib>

int* insertionSort (int arr[], int size){
    int check, move = 0;
    for (int i=1; i<size; i++){
        check = arr[i];
        move = i-1;
        while (move >= 0 && arr[move] > check){
            arr[move+1] = arr[move];
            move = move-1;
        }
        arr[move+1] = check;
    }
    return arr;
}

void print(int arr[], int size){
    std::cout<<"[ ";
    for (int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"]"<<std::endl;
}



int main(int argc, const char * argv[]) {
    int size = 8;
    int test[] = {1,7,8,5,3,6,4,2};
    print(test, size);
    insertionSort(test, size);
    print(test, size);
    return 0;
}
