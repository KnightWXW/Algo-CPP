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


void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
int generateRandomNum(int low, int high);
int digitSum(vector<int> vec);
int targetSum_A(vector<int> vec, int target);
int dfsTargetSum_A(vector<int> vec, int index, int temSum, int target);
int targetSum_B(vector<int> vec, int target);
int dfsTargetSum_B(vector<int> vec, int index, int temSum, int target, unordered_map<string, int> map);
int targetSum_C(vector<int> vec, int target);
int dfsTargetSum_C(vector<int> vec, int index, int temSum, int target, int sum, int **arr);
int targetSum_D(vector<int> vec, int target);

int main()
{
    vector<int> vec = generateRandomVec(0, 10, 10);
    int sum = digitSum(vec);
    int target = generateRandomNum(-sum, sum);
    printVecElement(vec);
    printf("target 为：%d。\n", target);
    printf("暴力递归：%d\n", targetSum_A(vec, target));
    printf("记忆化搜索(map存储)：%d\n", targetSum_B(vec, target));
    printf("记忆化搜索(数组存储)：%d\n", targetSum_C(vec, target));
    printf("动态规划：%d\n", targetSum_D(vec, target));
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

int digitSum(vector<int> vec)
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
int targetSum_A(vector<int> vec, int target)
{
    int sum = digitSum(vec);
    if (sum < target || target < -sum)
    {
        return -1;
    }
    return dfsTargetSum_A(vec, 0, 0, target);
}

int dfsTargetSum_A(vector<int> vec, int index, int temSum, int target)
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
    cnt += dfsTargetSum_A(vec, index + 1, temSum + vec[index], target);
    cnt += dfsTargetSum_A(vec, index + 1, temSum - vec[index], target);
    return cnt;
}

// 记忆化搜索(map存储)：
// Time: O(2^N)
// Space: O(N)
int targetSum_B(vector<int> vec, int target)
{
    int sum = digitSum(vec);
    if (sum < target || target < -sum)
    {
        return -1;
    }

    unordered_map<string, int> map;
    int ans = dfsTargetSum_B(vec, 0, 0, target, map);

    return ans;
}

int dfsTargetSum_B(vector<int> vec, int index, int temSum, int target, unordered_map<string, int> map)
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
    cnt += dfsTargetSum_B(vec, index + 1, temSum - vec[index], target, map);
    cnt += dfsTargetSum_B(vec, index + 1, temSum + vec[index], target, map);
    map[key] = cnt;
    return cnt;
}

// 记忆化搜索(数组存储)：
// Time: O(2^N)
// Space: O(N)
int targetSum_C(vector<int> vec, int target)
{
    int sum = digitSum(vec);
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

    int ans = dfsTargetSum_C(vec, 0, 0, target, sum, arr);

    for (int i = 0; i < vec.size() + 1; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return ans;
}

int dfsTargetSum_C(vector<int> vec, int index, int temSum, int target, int sum, int **arr)
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
    cnt += dfsTargetSum_C(vec, index + 1, temSum + vec[index], target, sum, arr);
    cnt += dfsTargetSum_C(vec, index + 1, temSum - vec[index], target, sum, arr);
    arr[index][temSum + sum] = cnt;
    return cnt;
}

// 动态规划：
// Time: O(M * N)
// Space: O(M * N)
int targetSum_D(vector<int> vec, int target)
{
    int sum = digitSum(vec);
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
            if (j - vec[i] >= 0){
                dp[i][j] += dp[i + 1][j - vec[i]];
            }
            if (j + vec[i] < 2 * sum + 1){
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