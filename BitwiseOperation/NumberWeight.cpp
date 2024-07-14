#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      Huawei: 数字权重

//      给定一个范围[minNum, maxNum), 再给定一个权重weight,
//      问该范围内数字的二进制表示中, 1的个数为weight，
//      问该范围内数字的二进制表示中, 1 的个数为 weight 的数有多少个,
//      若有则返回对应数量, 若无则返回 0。
//      数据范围：
//          0 <= minNum, maxNum <= 2^31 - 1
//          0 <= weight <= 31
//      样例1：
//          输入：
//              3 10 2
//          输出：
//              4
//      样例2:
//          输入:
//              17483649 123456789 15
//          输出：
//              14311708
//      样例3:
//          输入:
//              0 4294967295 3
//          输出：
//              4960

int generateRandomNum(int low, int high);

int NumberWeight(int minNum, int maxNum, int weight);

int main()
{
    int ans_A = NumberWeight(7483649, 123456789, 15);
    int ans_B = NumberWeight(0, 4294967295, 3);
    int ans_C = NumberWeight(3, 10, 2);
    printf("%d\n", ans_A);
    printf("%d\n", ans_B);
    printf("%d\n", ans_C);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

int DigitWeight(int num)
{
    int cnt = 0;
    while (num != 0)
    {
        num &= (num - 1);
        cnt++;
    }
    return cnt;
}

int NumberWeight(int minNum, int maxNum, int weight)
{
    int ans = 0;
    for (int i = minNum; i < maxNum; i++)
    {
        if (DigitWeight(i) == weight)
        {
            ans++;
        }
    }
    return ans;
}