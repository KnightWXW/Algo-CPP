#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//      给定一个非负整数num，如何不用循环语句，
//      返回 大于等于(>=)num，并且 距离 num 最近的 2的某次方 

int generateRandomNum(int low, int high);

int TheNearestPowerofTwo(int num);

int main()
{
    int num = generateRandomNum(0, 10000000);
    int ans = TheNearestPowerofTwo(num);
    printf("大于等于(>=) %d, 并且 距离 num 最近的 2的某次方 为 %d。\n", num, ans);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

int TheNearestPowerofTwo(int num){
    if(num == 0){
        return 1;
    }
    unsigned int n = num;
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
}