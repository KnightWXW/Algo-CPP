#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//      Huawei: 连续正数和的数

//      定义一种数：可以表示成若干（数量>1）连续正数和的数
//      比如，5=2+3，5 就是这样的数；
//          12=3+4+5，12 就是这样的数
//          2=1+1，2 不是这样的数，
//      因为等号右边不是连续正数
//      给定一个参数 N，返回是不是可以表示成若干连续正数和的数

int generateRandomNum(int low, int high);

bool ConstantSum_A(int n);
bool ConstantSum_B(int n);

int main()
{
    int n = generateRandomNum(1, 500);
    if (ConstantSum_A(n))
    {
        printf("%d 可以表示成若干连续正数和的数。\n", n);
    }
    else
    {
        printf("%d 不可以表示成若干连续正数和的数。\n", n);
    }

    if (ConstantSum_B(n))
    {
        printf("%d 可以表示成若干连续正数和的数。\n", n);
    }
    else
    {
        printf("%d 不可以表示成若干连续正数和的数。\n", n);
    }
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

// 模拟：
// Time: O(n)
// Space: O(1)
bool ConstantSum_A(int n)
{
    for (int left = 1; left <= n; left++)
    {
        int sum = left;
        for (int right = left + 1; right <= n; right++)
        {
            if (sum + right < n)
            {
                sum += right;
            }
            else if (sum + right > n)
            {
                break;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

// 打表 找规律：
//  2 ^ k 不可以 表示。
// Time: O(n)
// Space: O(1)
bool ConstantSum_B(int n)
{
    return (n & (n - 1)) != 0;
    // return n == (n & (~n + 1));
    // return n == (n & (-n));
}