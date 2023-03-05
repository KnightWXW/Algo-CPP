#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//      Huawei: 挑7

//      输出 1 到 n 之间 的与 7 有关数字的个数。
//      一个数与7有关是指这个数是 7 的倍数，或者是包含 7 的数字
//      (如 17 ，27 ，37 ... 70 ，71 ，72 ，73...)
//      数据范围： 1 ≤ n ≤ 30000
//      输入描述：一个正整数 n 。( n 不大于 30000 )
//      输出描述：
//          一个整数，表示1到n之间的与7有关的数字个数。
//      示例1
//          输入： 20
//          输出： 3
//          说明： 输入20，
//                1 到 20 之间有关的数字包括 7,14,17 共 3 个

int generateRandomNum(int low, int high);
void printString(string s);

bool HasSeven(int cur);
int PickSeven(int num);

int main()
{
    int n = generateRandomNum(1, 30000);
    int ans = PickSeven(n);
    printf("1 ~ %d 之间的 与 7 有关的数字个数为 %d 。\n", n, ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

bool HasSeven(int cur)
{
    int tem = cur;
    while (tem != 0)
    {
        if (tem % 10 == 7)
        {
            return true;
        }
        tem /= 10;
    }
    return false;
}

int PickSeven(int num)
{
    int ans = 0;
    for (int i = 1; i <= num; i++)
    {
        if ((i % 7 == 0) || HasSeven(i))
        {
            ans++;
        }
    }
    return ans;
}