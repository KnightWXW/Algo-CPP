#include <stdio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

//      神策: 股票的指标

//      给定一个数组 arr, 表示连续 n 天的股价, 数组下标表示第几天
//          指标 X: 任意两天的股价之和 – 此两天间隔的天数
//      比如
//          第3天，价格是10
//          第9天，价格是30
//          那么 第3天 和 第9天 的 指标X= 10 + 30 - (9 - 3) = 34
//      返回 arr中 最大的指标 X

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int IndicatorsOfStocks_A(vector<int> arr);
int IndicatorsOfStocks_B(vector<int> arr);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(1, 100, n);
    printVecElement(vec);
    int ans_A = IndicatorsOfStocks_A(vec);
    int ans_B = IndicatorsOfStocks_B(vec);
    printf("arr 中 最大的指标为 %d。\n", ans_A);
    printf("arr 中 最大的指标为 %d。\n", ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
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
    vector<int> vec;
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

// 暴力循环：
// Time: O(N^2)
// Space:O(1)
int IndicatorsOfStocks_A(vector<int> arr)
{
    int ans = 0;
    int l = arr.size();
    for (int i = 0; i < l; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            ans = max(ans, arr[i] + arr[j] - (j - i));
        }
    }
    return ans;
}

// 贪心：
// Time: O(N)
// Space:O(1)
int IndicatorsOfStocks_B(vector<int> arr)
{
    int ans = 0;
    int l = arr.size();
    int pre = arr[0];
    for (int i = 1; i < l; i++)
    {
        ans = max(ans, pre + arr[i] - i);
        pre = max(pre, arr[i] + i);
    }
    return ans;
}