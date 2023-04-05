#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

//      牛客 或与加

//      链接：https://www.nowcoder.com/questionTerminal/729f5e6e2acc4f3cb14a2262888f86fb?

//      给定 x, k, 求满足 x + y = x | y 的第 k 小的正整数 y。
//      | 是二进制的或(or)运算，例如 3 | 5 = 7。
//      比如当 x=5，k=1时返回 2，因为5+1=6 不等于 5|1=5，而 5+2=7 等于 5 | 2 = 7。
//      输入描述:
//          每组测试用例仅包含一组数据，每组数据为两个正整数 x, k。
//          满足 0 < x , k ≤ 2,000,000,000。
//      输出描述:
//          输出一个数 y。
//      输入例子:
//          5 1
//      输出例子:
//          2

int generateRandomNum(int low, int high);

int OrAndAdd_A(int x, int k);
int OrAndAdd_B(int x, int k);

int main()
{
    int x = generateRandomNum(1, 1000);
    int m = generateRandomNum(1, 999);
    int ans_A = OrAndAdd_A(x, m);
    int ans_B = OrAndAdd_B(x, m);
    printf("当 x = %d, k = %d 时, 满足 x + y = x | y 的第 k 小的正整数 y 为 %d.\n", x, m, ans_A);
    printf("当 x = %d, k = %d 时, 满足 x + y = x | y 的第 k 小的正整数 y 为 %d.\n", x, m, ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

// 暴力模拟：
// Time: O(N)
// Space: O(1)
int OrAndAdd_A(int x, int k)
{
    const int MAX_NUM = 2000000000;
    int ans = 1;
    int cnt = 0;
    while (ans <= MAX_NUM)
    {
        if (cnt < k && ((x + ans) == (x | ans)))
        {
            cnt++;
        }
        if (cnt == k)
        {
            break;
        }
        ans++;
    }
    return ans;
}

// 位运算：
// x + y == x | y : 
//    在二进制上看，每一位 x 和 y 不能 同时取 1
// Time: O(N)
// Space: O(1)
int OrAndAdd_B(int x, int k)
{
    int ans = 0;
    int bitNum = 1;
    while (k > 0)
    {
        if ((x & bitNum) == 0)
        {
            ans += (bitNum * (k & 1));
            k >>= 1;
        }
        bitNum <<= 1;
    }
    return ans;
}