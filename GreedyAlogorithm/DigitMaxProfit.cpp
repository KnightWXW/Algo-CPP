#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      Huawei: 计算最大利润

//      终端计算利润，给定一个价格数组prices,
//      在 第 i 天买入某商品后, 在第 j 天卖出，同时需要支付 (j - i) 元 租金
//      计算最大可以获得多少利润？
//      示例 1:
//          输入: {2, 1, 5}
//          输出: 3
//      示例 2:
//          输入: {7, 6, 5}
//          输出: 0

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int DigitMaxProfit_A(vector<int> arr);
int DigitMaxProfit_B(vector<int> arr);

int main()
{
    int n = generateRandomNum(0, 20);
    vector<int> arr1 = generateRandomVec(0, 100, n);
    printf("price 数组 元素为: ");
    printVecElement(arr1);
    int ans_A = DigitMaxProfit_A(arr1);
    printf("最大利润 为 %d。\n", ans_A);
    int ans_B = DigitMaxProfit_B(arr1);
    printf("最大利润 为 %d。\n", ans_B);
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

// 暴力循环：
// Time：O(N2)
// Space: O(1)
int DigitMaxProfit_A(vector<int> arr)
{
    int l = arr.size();
    int profit = 0;
    int cur = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = i; j < l; j++)
        {
            cur = arr[j] - arr[i] - (j - i);
            profit = max(profit, cur);
        }
    }
    return profit;
}

// 贪心：
// Time: O(N)
// Space: O(1)
int DigitMaxProfit_B(vector<int> arr)
{
    int l = arr.size();
    int profit = 0;
    int cost = arr[0] + 0;
    for (int i = 1; i < l; i++)
    {
        cost = min(cost + 1, arr[i]);
        profit = max(profit, arr[i] - cost);
    }
    return profit;
}