#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      给定一个正数 n ，求 n 的裂开方法数， 
//      规定：后面的数不能比前面的数小 
//      比如 4 的裂开方法有： (1+1+1+1、 1+1+2、 1+3、 2+2、 4) 共 5 种，
//      所以返回 5

int generateRandomNum(int low, int high);

int splitNumber_A(int n);
int dfsSplitNumber_A(int n);
int splitNumber_B(int n);
int dfsSplitNumber_B(int n);
int splitNumber_C(int n);

int main(){
    int n = generateRandomNum(1, 20);

}


int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

int splitNumber_A(int n){

}

int dfsSplitNumber_A(int n){
    
}

int splitNumber_B(int n){
    
}

int dfsSplitNumber_B(int n){
    
}

int splitNumber_C(int n){
    
}