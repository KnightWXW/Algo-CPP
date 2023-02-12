#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 69. x 的平方根 

//      链接：https://leetcode.cn/problems/sqrtx/

//      给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
//      由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
//      注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
//      示例 1：
//          输入：x = 4
//          输出：2
//      示例 2：
//          输入：x = 8
//          输出：2
//          解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
//      提示：
//          0 <= x <= 231 - 1

double generateRandomNumDouble(int low, int high);
int generateRandomNum(int low, int high);

int MySqrt(int x);
double MySqrtDouble(double x); // 精准到 0.001

int main()
{
    int n = generateRandomNum(0, 100000000);
    double d = generateRandomNumDouble(0, 1000000);
    int ans = MySqrt(n);
    double ansD = MySqrtDouble(d);
    printf("计算 %d 的算数平方根为 : %d。\n", n, ans);
    printf("计算 %lf 的算数平方根为 : %lf。\n", d, ansD);
}

double generateRandomNumDouble(int low, int high)
{
    srand((int)time(0));
    double ran = (rand() % (high * 100 - low * 100 + 1) + low * 100) / 100.0;
    return ran;
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// Int类型：
int MySqrt(int x){
    if(x <= 1){
        return x;
    }
    int left = 0;
    int right = x / 2;
    int ans = 0;
    while(left <= right){
        int mid = left + ((right - left) >> 1);
        if((long long)mid * mid <= x){
            ans = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return ans;
}

// Double类型：精准到 0.001
double MySqrtDouble(double x){
    if(x <= 1){
        return x;
    }
    double left = 0.0;
    double right = x;
    double ans = 0.0;
    while(left <= right){
        double mid = left + ((right - left) / 2);
        if((long double)mid * mid <= x){
            ans = mid;
            left = mid + 0.001;
        }else{
            right = mid - 0.001;
        }
    }
    return ans;
}