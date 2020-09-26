#include "array.cpp"
#include <iostream>

int main(){
    she::array<int> arr(10);

    for(int i=0;i<10;i++){
        std::cout<<arr.get(i)<<" ";
        arr.set(i,i);
    }
    std::cout<<"\n";
    for(int i=0;i<10;i++){
        std::cout<<arr.get(i)<<" ";
    }

    return 0;
}