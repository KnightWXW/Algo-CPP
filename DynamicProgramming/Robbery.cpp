#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//      LeetCode 198. 打家劫舍

//      链接：https://leetcode.cn/problems/house-robber/

//      你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
//      影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
//      如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//      给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

//      示例 1：
//      输入：[1,2,3,1]
//      输出：4
//      解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//           偷窃到的最高金额 = 1 + 3 = 4 。
//      示例 2：
//      输入：[2,7,9,3,1]
//      输出：12
//      解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//          偷窃到的最高金额 = 2 + 9 + 1 = 12 。

//      提示：
//      1 <= nums.length <= 100
//      0 <= nums[i] <= 400

//      链接：https://leetcode.cn/problems/house-robber/

void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
int robbery_A(vector<int> vec);
int dfsRobbery_A(vector<int> vec, int index);
int robbery_B(vector<int> vec);
int dfsRobbery_B(vector<int> vec, int index, int *arr);
int robbery_C(vector<int> vec);
int robbery_D(vector<int> vec);

int main()
{
    vector<int> vec = generateRandomVec(1, 100, 25);
    printVecElement(vec);
    printf("暴力递归：%d\n", robbery_A(vec));
    printf("记忆化搜索：%d\n", robbery_B(vec));
    printf("动态规划：%d\n", robbery_C(vec));
    printf("动态规划(空间优化)：%d\n", robbery_D(vec));
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

// 暴力递归：
// Time: O(2^N)
// Space: O(N)
int robbery_A(vector<int> vec)
{
    return dfsRobbery_A(vec, vec.size() - 1);
}

int dfsRobbery_A(vector<int> vec, int index)
{
    if (index < 0)
    {
        return 0;
    }

    int p1 = dfsRobbery_A(vec, index - 1);
    int p2 = dfsRobbery_A(vec, index - 2) + vec[index];
    return max(p1, p2);
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(N)
int robbery_B(vector<int> vec)
{
    int *arr;
    arr = new int[vec.size() + 1];
    for (int i = 0; i < vec.size(); i++)
    {
        arr[i] = 0;
    }
    int ans = dfsRobbery_B(vec, vec.size() - 1, arr);

    free(arr);
    return ans;
}

int dfsRobbery_B(vector<int> vec, int index, int *arr)
{
    if (index < 0)
    {
        return 0;
    }
    if (arr[index] > 0)
    {
        return arr[index];
    }

    int p1 = dfsRobbery_B(vec, index - 1, arr);
    int p2 = dfsRobbery_B(vec, index - 2, arr) + vec[index];
    arr[index] = max(p1, p2);
    return max(p1, p2);
}

// 动态规划：
// Time: O(N)
// Space: O(N)
int robbery_C(vector<int> vec)
{
    int *dp;
    dp = new int[vec.size()];
    dp[0] = vec[0];
    dp[1] = max(vec[0], vec[1]);
    for (int i = 2; i < vec.size(); i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + vec[i]);
    }
    int ans = dp[vec.size() - 1];
    free(dp);
    return ans;
}

// 动态规划(空间优化)：
// Time: O(N)
// Space: O(1)
int robbery_D(vector<int> vec)
{
    int a = vec[0];
    int b = max(vec[0], vec[1]);
    for (int i = 2; i < vec.size(); i++)
    {
        int c = max(b, a + vec[i]);
        a = b;
        b = c;
    }
    return b;
}