#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 50. Pow(x, n)

//      链接：https://leetcode.cn/problems/powx-n/

//      实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，x^n）。
//      示例 1：
//          输入：x = 2.00000, n = 10
//           输出：1024.00000
//      示例 2：
//          输入：x = 2.10000, n = 3
//          输出：9.26100
//      示例 3：
//          输入：x = 2.00000, n = -2
//          输出：0.25000
//          解释：2-2 = 1/22 = 1/4 = 0.25
//      提示：
//          -100.0 < x < 100.0
//          -231 <= n <= 231-1
//          n 是一个整数
//          -104 <= xn <= 104

double generateRandomNumDouble(int low, int high);
int generateRandomNum(int low, int high);

double MyPow(double x, int n);

int main()
{
    double x = generateRandomNumDouble(-100, 100);
    int n = generateRandomNum(-100, 100);
    double ans = MyPow(x, n);
    printf("计算 %lf 的整数 %d 次幂函数 为: \n %lf。", x, n, ans);
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

double MyPow(double x, int n){
    if(n == 0){
        return double(1.0);
    }
    double ans = 1.0;
    double k = x;
    int m = n == INT_MIN ? abs(n + 1) : abs(n);
    while(m != 0){
        if((m & 1) == 1){
            ans *= k;
        }
        k *= k;
        m >>= 1;
    }
    if(n == INT_MIN){
        ans *= x;
    }
    return n > 0 ? ans : 1 / ans;
}