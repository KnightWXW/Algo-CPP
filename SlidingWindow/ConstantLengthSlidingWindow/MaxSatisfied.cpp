#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      LeetCode 1052. 爱生气的书店老板

//      链接：https://leetcode.cn/problems/grumpy-bookstore-owner/

//      有一个书店老板，他的书店开了 n 分钟。
//      每分钟都有一些顾客进入这家商店。给定一个长度为 n 的整数数组 customers ，
//      其中 customers[i] 是在第 i 分钟开始时进入商店的顾客数量，
//      所有这些顾客在第 i 分钟结束后离开。在某些时候，书店老板会生气。
//      如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。
//      当书店老板生气时，那一分钟的顾客就会不满意，若老板不生气则顾客是满意的。
//      书店老板知道一个秘密技巧，能抑制自己的情绪，
//      可以让自己连续 minutes 分钟不生气，但却只能使用一次。
//      请你返回 这一天营业下来，最多有多少客户能够感到满意 。
//      示例 1：
//      输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
//      输出：16
//          解释：书店老板在最后 3 分钟保持冷静。
//          感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.
//      示例 2：
//      输入：customers = [1], grumpy = [0], minutes = 1
//      输出：1
//      提示：
//          n == customers.length == grumpy.length
//          1 <= minutes <= n <= 2 * 104
//          0 <= customers[i] <= 1000
//          grumpy[i] == 0 or 1

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes);

int main()
{
    int n = generateRandomNum(1, 20);
    int minutes = generateRandomNum(1, n);
    vector<int> customers = generateRandomVec(0, 10, n);
    vector<int> grumpy = generateRandomVec(0, 1, n);
    printf("customers数组 元素为: ");
    printVecElement(customers);
    printf("grumpy数组 元素为: ");
    printVecElement(grumpy);
    printf("minutes 为: %d\n", minutes);
    int ans = maxSatisfied(customers, grumpy, minutes);
    printf("这一天营业下来，最多有 %d 名客户能够感到满意 \n", ans);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

vector<int> generateRandomVec(int low, int high, int len)
{
    srand((int)time(0));
    vector<int> vec;
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
{
    int l = customers.size();
    int left = 0;
    int right = 0;
    int ans = 0;
    int satisfied = 0;
    int unsatisfied = 0;

    while (right < l)
    {
        if (grumpy[right] == 0)
        {
            satisfied += customers[right];
        }
        else
        {
            unsatisfied += customers[right];
        }
        while (right - left + 1 > minutes)
        {
            if (grumpy[left] == 1)
            {
                unsatisfied -= customers[left];
            }
            left++;
        }
        ans = max(ans, unsatisfied);
        right++;
    }

    return ans + satisfied;
}