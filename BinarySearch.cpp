#include <iostream>

int binarySearch(int arr[], int left, int right, int elem_to_find){
    if (right >= left) {
        int mid = (left+right)/2;
        if (arr[mid] == elem_to_find){
            return mid+1;
        }else if (arr[mid]>elem_to_find){
            return binarySearch(arr, left, mid-1, elem_to_find);
        }else if (arr[mid]<elem_to_find){
            return binarySearch(arr, mid+1, right, elem_to_find);
        }
    }
    return -1;
}

int binarySearch(int arr[], int len, int elem_to_find){
    return binarySearch(arr, 0, len-1, elem_to_find);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)
    int result = binarySearch(arr, 0, n, 10);
    if (result == -1){
        std::cout<<"Element is not present in array"<<std::endl;
    }else {
        std::cout<<"Element is present in array at index "<<result<<std::endl;
    }
    return 0;
}
