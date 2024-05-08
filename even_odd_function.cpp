#include <iostream>
void check(int num);
int main(){
    std::cout<<"================ Wellcome to odd even function ================\n";
    int number;
    std::cout<<"enter the number you want to check for";
    std::cin>>number;
    check(number);
}
void check(int num){
    if(num%2==0){
        std::cout<<"the number is even\n";

    }
    else{
        std::cout<<"the number is odd\n";
    }
}