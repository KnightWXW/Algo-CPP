#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

//      LeetCode 494. 目标和

//      链接：https://leetcode.cn/problems/target-sum/

//      给你一个整数数组 nums (0 <= nums[i] <= 1000)和一个整数 target(-1000 <= target <= 1000) 。
//      向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
//           例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，
//           然后串联起来得到表达式 "+2-1" 。
//      返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
//      示例 1：
//          输入：nums = [1,1,1,1,1], target = 3
//          输出：5
//          解释：一共有 5 种方法让最终目标和为 3 。
//              -1 + 1 + 1 + 1 + 1 = 3
//              +1 - 1 + 1 + 1 + 1 = 3
//              +1 + 1 - 1 + 1 + 1 = 3
//              +1 + 1 + 1 - 1 + 1 = 3
//              +1 + 1 + 1 + 1 - 1 = 3
//      示例 2：
//          输入：nums = [1], target = 1
//          输出：1 
//          提示：
//              1 <= nums.length <= 20
//              0 <= nums[i] <= 1000
//              0 <= sum(nums[i]) <= 1000
//              -1000 <= target <= 1000

void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
int generateRandomNum(int low, int high);
int DigitSum(vector<int> vec);
int TargetSum_A(vector<int> vec, int target);
int DfsTargetSum_A(vector<int> vec, int index, int temSum, int target);
int TargetSum_B(vector<int> vec, int target);
int DfsTargetSum_B(vector<int> vec, int index, int temSum, int target, unordered_map<string, int> map);
int TargetSum_C(vector<int> vec, int target);
int DfsTargetSum_C(vector<int> vec, int index, int temSum, int target, int sum, int **arr);
int TargetSum_D(vector<int> vec, int target);
int TargetSum_E(vector<int> vec, int target);
int TargetSum_F(vector<int> vec, int target);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> vec = generateRandomVec(0, 10, n);
    int sum = DigitSum(vec);
    int target = generateRandomNum(-sum, sum);
    printVecElement(vec);
    printf("target 为：%d。\n", target);
    printf("暴力递归：%d\n", TargetSum_A(vec, target));
    printf("记忆化搜索(map存储): %d\n", TargetSum_B(vec, target));
    printf("记忆化搜索(数组存储): %d\n", TargetSum_C(vec, target));
    printf("动态规划：%d\n", TargetSum_D(vec, target));
    printf("背包问题：%d\n", TargetSum_E(vec, target));
    printf("背包问题(空间压缩): %d\n", TargetSum_F(vec, target));
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

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

int DigitSum(vector<int> vec)
{
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }
    return sum;
}

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int TargetSum_A(vector<int> vec, int target)
{
    int sum = DigitSum(vec);
    if (sum < target || target < -sum)
    {
        return -1;
    }
    return DfsTargetSum_A(vec, 0, 0, target);
}

int DfsTargetSum_A(vector<int> vec, int index, int temSum, int target)
{
    if (index == vec.size())
    {
        if (temSum == target)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int cnt = 0;
    cnt += DfsTargetSum_A(vec, index + 1, temSum + vec[index], target);
    cnt += DfsTargetSum_A(vec, index + 1, temSum - vec[index], target);
    return cnt;
}

// 记忆化搜索(map存储)：
// Time: O(2^N)
// Space: O(N)
int TargetSum_B(vector<int> vec, int target)
{
    int sum = DigitSum(vec);
    if (sum < target || target < -sum)
    {
        return -1;
    }

    unordered_map<string, int> map;
    int ans = DfsTargetSum_B(vec, 0, 0, target, map);

    return ans;
}

int DfsTargetSum_B(vector<int> vec, int index, int temSum, int target, unordered_map<string, int> map)
{
    string key = to_string(index) + "_" + to_string(temSum);
    if (index == vec.size())
    {
        if (temSum == target)
        {
            map[key] = 1;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (map.count(key))
    {
        return map[key];
    }

    int cnt = 0;
    cnt += DfsTargetSum_B(vec, index + 1, temSum - vec[index], target, map);
    cnt += DfsTargetSum_B(vec, index + 1, temSum + vec[index], target, map);
    map[key] = cnt;
    return cnt;
}

// 记忆化搜索(数组存储)：
// Time: O(2^N)
// Space: O(N)
int TargetSum_C(vector<int> vec, int target)
{
    int sum = DigitSum(vec);
    if (sum < target || target < -sum)
    {
        return -1;
    }

    int **arr;
    arr = new int *[vec.size() + 1];
    for (int i = 0; i < vec.size() + 1; i++)
    {
        arr[i] = new int[2 * sum + 1];
        for (int j = 0; j < 2 * sum + 1; j++)
        {
            arr[i][j] = 0;
        }
    }

    int ans = DfsTargetSum_C(vec, 0, 0, target, sum, arr);

    for (int i = 0; i < vec.size() + 1; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return ans;
}

int DfsTargetSum_C(vector<int> vec, int index, int temSum, int target, int sum, int **arr)
{
    if (index == vec.size())
    {
        if (temSum == target)
        {
            arr[vec.size()][target + sum] = 1;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (arr[index][temSum + sum] > 0)
    {
        return arr[index][temSum + sum];
    }

    int cnt = 0;
    cnt += DfsTargetSum_C(vec, index + 1, temSum + vec[index], target, sum, arr);
    cnt += DfsTargetSum_C(vec, index + 1, temSum - vec[index], target, sum, arr);
    arr[index][temSum + sum] = cnt;
    return cnt;
}

// 动态规划：
// Time: O(M * N)
// Space: O(M * N)
int TargetSum_D(vector<int> vec, int target)
{
    int sum = DigitSum(vec);
    if (sum < target || target < -sum)
    {
        return -1;
    }

    int **dp;
    dp = new int *[vec.size() + 1];
    for (int i = 0; i < vec.size() + 1; i++)
    {
        dp[i] = new int[2 * sum + 1];
        for (int j = 0; j < 2 * sum + 1; j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[vec.size()][target + sum] = 1;
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2 * sum + 1; j++)
        {
            if (j - vec[i] >= 0)
            {
                dp[i][j] += dp[i + 1][j - vec[i]];
            }
            if (j + vec[i] < 2 * sum + 1)
            {
                dp[i][j] += dp[i + 1][j + vec[i]];
            }
        }
    }

    int ans = dp[0][sum];

    for (int i = 0; i < vec.size() + 1; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return ans;
}

// 转换为背包问题：
// 求目标问题 实际上 就是求 背包问题 ：
// Time: O(M * N)
// Space: O(M * N)
// target = 正数和 - 负数和
//        = sumAll - 负数和 - 负数和
//        = sumAll - 2 * 负数和
int TargetSum_E(vector<int> vec, int target)
{
    int l = vec.size();
    int sumAll = DigitSum(vec);
    int k = sumAll - target;
    if ((k & 1) == 1 || k < 0)
    {
        return 0;
    }
    k /= 2;
    vector<vector<int>> dp(l + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= l; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (j >= vec[i - 1])
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - vec[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[l][k];
}

// 转换为 背包问题(空间压缩)：
// 求目标问题 实际上 就是求 背包问题 ：
// Time: O(M * N)
// Space: O(M * N)
int TargetSum_F(vector<int> vec, int target)
{
    int l = vec.size();
    int sumAll = DigitSum(vec);
    int k = sumAll - target;
    if ((k & 1) == 1 || k < 0)
    {
        return 0;
    }
    k /= 2;
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= l; i++)
    {
        for (int j = k; j >= vec[i - 1]; j--)
        {
            dp[j] += dp[j - vec[i - 1]];
        }
    }
    return dp[k];
}