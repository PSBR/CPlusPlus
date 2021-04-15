#include "60hw4.h"
#include <iostream>

//Assignment: Utilize dynmaic arrays to create a class that includes helpful array based functions

int main() {
    IntBag a;
    std::cout<<a.get_point(1)<<std::endl;
    a.fill(5);
    IntBag b;
    b = a;
    a.clear();
    std::cout<<b.get_point(3)<<" "<<a.get_point(3) <<std::endl;
    b.fill(7);
    b.deletes(4);
    std::cout<<b.get_point(3)<<" "<<a.get_point(4) <<std::endl;
    


    return 0;
}


    
    
    