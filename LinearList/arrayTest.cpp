#include "array.cpp"
#include <iostream>
#include <stdio.h>
#define SPACE printf(" ")
#define ENTER printf("\n")

int main(){
    she::array<int> arr(10,0);
    she::array<int> arr2;
    she::array<int> arr3(-1);

    for(int i=0;i<arr.length();i++){
        std::cout<<arr.get(i);SPACE;
        std::cout<<arr[i];SPACE;
        arr.set(i,i);
    }
    ENTER;
    for(int i=0;i<arr.length();i++){
        std::cout<<arr.get(i);SPACE;
        std::cout<<arr[i];SPACE;
    }
    ENTER;
    for(int i=0;i<arr2.length();i++){
        std::cout<<arr2[i];SPACE;
    }
    ENTER;
    std::cout<<arr[10];SPACE;

    return 0;
}