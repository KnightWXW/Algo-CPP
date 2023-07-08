#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 188. 买卖股票的最佳时机 IV

//      链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/

//      给定一个整数数组 prices，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格，
//      和一个整型 k 。
//      设计一个算法来计算你所能获取的最大利润。
//      你最多可以完成 k 笔交易。
//      也就是说，你最多可以买 k 次，卖 k 次。
//      注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//      示例 1：
//          输入：k = 2, prices = [2,4,1]
//          输出：2
//          解释：在第 1 天 (股票价格 = 2) 的时候买入，
//              在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
//      示例 2：
//          输入：k = 2, prices = [3,2,6,5,0,3]
//          输出：7
//          解释：在第 2 天 (股票价格 = 2) 的时候买入，
//              在第 3 天 (股票价格 = 6) 的时候卖出, 
//              这笔交易所能获得利润 = 6-2 = 4 。
//              随后，在第 5 天 (股票价格 = 0) 的时候买入，
//              在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
//      提示：
//          0 <= k <= 100
//          0 <= prices.length <= 1000
//          0 <= prices[i] <= 1000

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int MaxProfitIV(int k, vector<int> &prices);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(1, 100, n);
    int k = generateRandom(1, 20);
    printVecElement(vec);
    int ans_A = MaxProfitIV(vec, k);
    printf("最多可以完成 %d 笔交易, 交易中获取的最大利润为: %d\n", k, ans_A);
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
    srand((int)time(0));
    vector<int> vec;
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

// 贪心：
// Time: O(N)
// Space: O(1)
int MaxProfitIV(int k, vector<int> &prices)
{
    int l = prices.size();
    int ans = 0;
    //int minVal = INT_MAX;
    for (int i = 1; i < l; i++)
    {
        if(prices[i] > prices[i - 1]){
            ans += (prices[i] - prices[i - 1]);
        }
    }
    return ans;
}