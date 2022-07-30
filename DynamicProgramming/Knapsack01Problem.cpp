#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

//   背包问题:
//      给定 两个 长度都为 N 的非负数组 weights 和 values。
//      weight[i] 和 value[i] 分别代表 i号物品 的 重量 和 价值。
//      给定一个 正数bag，表示一个 载重bag 的 袋子。
//      每个物品只能装载一次，并且装载的物品 不能超过 重量bag, 返回能装下的最大价值。

int knapsack01_A(vector<int> weight, vector<int> value, int bag);
int dfsKnapsack01_A(vector<int> weight, vector<int> value, int bag, int index);
int knapsack01_B(vector<int> weight, vector<int> value, int bag);
int dfsKnapsack01_B(vector<int> weight, vector<int> value, int bag, int index, int **arr);
int knapsack01_C(vector<int> weight, vector<int> value, int bag);
int knapsack01_D(vector<int> weight, vector<int> value, int bag);

int main()
{
    vector<int> weight = {3, 2, 4, 7, 3, 1, 7};
    vector<int> value = {5, 6, 3, 19, 12, 4, 2};
    int bag = 15;
    printf("暴力递归：%d\n", knapsack01_A(weight, value, bag));             // 42
    printf("记忆化搜索：%d\n", knapsack01_B(weight, value, bag));           // 42
    printf("动态规划：%d\n", knapsack01_C(weight, value, bag));             // 42
    printf("动态规划（空间优化）：%d\n", knapsack01_D(weight, value, bag)); // 42
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int knapsack01_A(vector<int> weight, vector<int> value, int bag)
{
    if (weight.size() != value.size() || weight.size() == 0)
    {
        return 0;
    }
    return dfsKnapsack01_A(weight, value, bag, 0);
}

int dfsKnapsack01_A(vector<int> weight, vector<int> value, int bag, int index)
{
    if (index == weight.size())
    {
        return 0;
    }

    // 选择1：不选择 当前index背包 的物品
    int p1 = dfsKnapsack01_A(weight, value, bag, index + 1);
    // 选择2：选择 当前index背包 的物品
    // 选择的条件：bag >= weight[index]
    int p2 = 0;
    if (bag >= weight[index])
    {
        p2 = value[index] + dfsKnapsack01_A(weight, value, bag - weight[index], index + 1);
    }
    return max(p1, p2);
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int knapsack01_B(vector<int> weight, vector<int> value, int bag)
{
    if (weight.size() != value.size() || weight.size() == 0)
    {
        return 0;
    }

    int N = weight.size();
    int **arr ;
    arr = new int*[N + 1];
    for (int i = 0; i < N + 1; i++){
        arr[i] = new int[bag + 1];
    }

    int ans = dfsKnapsack01_B(weight, value, bag, 0, arr);

    for (int i = 0; i < N + 1; i++){
        free(arr[i]);
    }
    free(arr);
    return ans; 
}

int dfsKnapsack01_B(vector<int> weight, vector<int> value, int bag, int index, int **arr)
{
    if (index == weight.size())
    {
        return 0;
    }
    if (arr[index][bag] > 0)
    {
        return arr[index][bag];
    }

    // 选择1：不选择 当前index背包 的物品
    int p1 = dfsKnapsack01_B(weight, value, bag, index + 1, arr);

    // 选择2：选择 当前index背包 的物品
    // 选择的条件：bag >= weight[index]
    int p2 = 0;
    if (bag >= weight[index])
    {
        p2 = dfsKnapsack01_B(weight, value, bag - weight[index], index + 1, arr) + value[index];
    }
    arr[index][bag] = max(p1, p2);
    return arr[index][bag];
}

// 动态规划：
// Time: O(M * N)
// Space: O(M * N)
int knapsack01_C(vector<int> weight, vector<int> value, int bag)
{
    if (weight.size() != value.size() || weight.size() == 0)
    {
        return 0;
    }

    int N = weight.size();

    int **dp;
    dp = new int*[N + 1];
    for (int i = 0; i < N + 1; i++){
        dp[i] = new int[bag + 1];
    }

    for (int index = N - 1; index >= 0; index--)
    {
        for (int remain = 0; remain <= bag; remain++)
        {
            int p1 = dp[index + 1][remain];
            int p2 = 0;
            if (remain >= weight[index])
            {
                p2 = dp[index + 1][remain - weight[index]] + value[index];
            }
            dp[index][remain] = max(p1, p2);
        }
    }
    int ans = dp[0][bag];
    for (int i = 0 ; i < N + 1; i++){
        free(dp[i]);
    }
    free(dp);
    return ans;
}

// 动态规划(空间优化)：
// Time: O(M * N)
// Space: O(N)
int knapsack01_D(vector<int> weight, vector<int> value, int bag)
{
    if (weight.size() != value.size() || weight.size() == 0)
    {
        return 0;
    }

    int N = weight.size();
    int *dp;
    dp = new int[bag + 1];

    for (int index = N - 1; index >= 0; index--)
    {
        for (int remain = bag; remain >= 0; remain--)
        {
            int p1 = dp[remain];
            int p2 = 0;
            if (remain >= weight[index])
            {
                p2 = dp[remain - weight[index]] + value[index];
            }
            dp[remain] = max(p1, p2);
        }
    }
    int ans = dp[bag];
    free(dp);
    return ans;
}