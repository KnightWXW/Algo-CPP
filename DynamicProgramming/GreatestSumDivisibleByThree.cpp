#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 1262. 可被三整除的最大和

//      链接：https://leetcode.cn/problems/greatest-sum-divisible-by-three/

//      给你一个整数数组 nums，请你找出并返回能被三整除的元素最大和。

//      示例 1：
//      输入：nums = [3,6,5,1,8]
//      输出：18
//      解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。

//      示例 2：
//      输入：nums = [4]
//      输出：0
//      解释：4 不能被 3 整除，所以无法选出数字，返回 0。

//      示例 3：
//      输入：nums = [1,2,3,4,4]
//      输出：12
//      解释：选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。

//      提示：
//          1 <= nums.length <= 4 * 10^4
//          1 <= nums[i] <= 10^4

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int greatestSumDivisibleByThree_AA(vector<int> vec);
int dfsGreatestSumDivisibleByThree_AA(vector<int> vec, int l, int len, int sum);
int greatestSumDivisibleByThree_AB(vector<int> vec);
int dfsGreatestSumDivisibleByThree_AB(vector<int> vec, int l, int len, int sum, vector<int> arr);
int greatestSumDivisibleByThree_AC(vector<int> vec);

int greatestSumDivisibleByThree_BA(vector<int> vec);
int dfsGreatestSumDivisibleByThree_BA(vector<int> vec, int i, int remind);
int greatestSumDivisibleByThree_BB(vector<int> vec);
int dfsGreatestSumDivisibleByThree_BB(vector<int> vec, int i, int remind, vector<vector<int>> arr);
int greatestSumDivisibleByThree_BC(vector<int> vec);

int greatestSumDivisibleByThree_CA(vector<int> vec);
int dfsGreatestSumDivisibleByThree_CA(vector<int> vec, int i, int target);
int greatestSumDivisibleByThree_CB(vector<int> vec);
int dfsGreatestSumDivisibleByThree_CB(vector<int> vec, int i, int target, vector<vector<int>> arr);
int greatestSumDivisibleByThree_CC(vector<int> vec);
int greatestSumDivisibleByThree_CD(vector<int> vec);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> arr = generateRandomVec(0, 20, n);
    printVecElement(arr);
    
    printf("(暴力递归<一>) 数组中能被三整除的元素最大和 为 %d \n", greatestSumDivisibleByThree_AA(arr));
    printf("(记忆化搜索<一>) 数组中能被三整除的元素最大和 为 %d \n", greatestSumDivisibleByThree_AB(arr));
    printf("(动态规划<一>) 数组中能被三整除的元素最大和 为 %d \n", greatestSumDivisibleByThree_AC(arr));
    printf("(暴力递归<二>) 数组中能被三整除的元素最大和 为 %d \n", greatestSumDivisibleByThree_BA(arr));
    printf("(记忆化搜索<二>) 数组中能被三整除的元素最大和 为 %d \n", greatestSumDivisibleByThree_BB(arr));
    printf("(动态规划<二>) 数组中能被三整除的元素最大和 为 %d \n", greatestSumDivisibleByThree_BC(arr));
    printf("(暴力递归<三>) 数组中能被三整除的元素最大和 为 %d \n", greatestSumDivisibleByThree_CA(arr));
    printf("(记忆化搜索<三>) 数组中能被三整除的元素最大和 为 %d \n", greatestSumDivisibleByThree_CB(arr));
    printf("(动态规划<三>) 数组中能被三整除的元素最大和 为 %d \n", greatestSumDivisibleByThree_CC(arr));
    printf("(动态规划<三><空间压缩>) 数组中能被三整除的元素最大和 为 %d \n", greatestSumDivisibleByThree_CD(arr));
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

// 暴力递归 (一) :
// Time: O(2^N)
// Space: O(N)
int greatestSumDivisibleByThree_AA(vector<int> vec)
{
    int l = vec.size();
    return dfsGreatestSumDivisibleByThree_AA(vec, l, l, 0);
}

int dfsGreatestSumDivisibleByThree_AA(vector<int> vec, int l, int len, int sum)
{
    if (len == 0)
    {
        if (sum % 3 == 0)
        {
            return sum;
        }
        else
        {
            return 0;
        }
    }
    int yes = dfsGreatestSumDivisibleByThree_AA(vec, l, len - 1, sum + vec[len - 1]);
    int no = dfsGreatestSumDivisibleByThree_AA(vec, l, len - 1, sum);

    return max(yes, no);
}

// 记忆化搜索 (一) :
// Time: O(2^N)
// Space: O(N)
int greatestSumDivisibleByThree_AB(vector<int> vec)
{
    int l = vec.size();
    vector<int> arr(l + 1, 0);
    return dfsGreatestSumDivisibleByThree_AB(vec, l, l, 0, arr);
}

int dfsGreatestSumDivisibleByThree_AB(vector<int> vec, int l, int len, int sum, vector<int> arr)
{
    if (len == 0)
    {
        if (sum % 3 == 0)
        {
            arr[0] = sum;
            return sum;
        }
        else
        {
            return 0;
        }
    }

    if (arr[len] > 0)
    {
        return arr[len];
    }

    int yes = dfsGreatestSumDivisibleByThree_AB(vec, l, len - 1, sum + vec[len - 1], arr);
    int no = dfsGreatestSumDivisibleByThree_AB(vec, l, len - 1, sum, arr);

    arr[len] = max(yes, no);

    return max(yes, no);
}

// 动态规划(一)：
// Time: O(N * S)
// Space: O(N * S)
int greatestSumDivisibleByThree_AC(vector<int> vec)
{
    int l = vec.size();
    int sumAll = 0;
    for (auto v : vec)
    {
        sumAll += v;
    }
    vector<vector<int>> dp(l + 1, vector<int>(sumAll + 1, 0));

    for (int s = 0; s <= sumAll; s++)
    {
        if (s % 3 == 0)
        {
            dp[0][s] = s;
        }
    }

    for (int i = 1; i <= l; i++)
    {
        for (int s = sumAll - vec[i - 1]; s >= 0; s--)
        {
            dp[i][s] = max(dp[i - 1][s + vec[i - 1]], dp[i - 1][s]);
        }
    }

    return dp[l][0];
}

// 暴力递归 (二) :
// Time: O(2^N)
// Space: O(N)
int greatestSumDivisibleByThree_BA(vector<int> vec)
{
    return dfsGreatestSumDivisibleByThree_BA(vec, 0, 0);
}

int dfsGreatestSumDivisibleByThree_BA(vector<int> vec, int i, int remind)
{
    if (i >= vec.size())
    {
        return remind == 0 ? 0 : INT_MIN;
    }
    // 分情况 讨论：
    if (vec[i] % 3 == 0)
    {
        if (remind == 0)
        {
            return max(dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 0),
                       dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 0) + vec[i]);
        }
        else if (remind == 1)
        {
            return max(dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 1),
                       dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 1) + vec[i]);
        }
        else if (remind == 2)
        {
            return max(dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 2),
                       dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 2) + vec[i]);
        }
    }
    else if (vec[i] % 3 == 1)
    {
        if (remind == 0)
        {
            return max(dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 0),
                       dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 2) + vec[i]);
        }
        else if (remind == 1)
        {
            return max(dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 1),
                       dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 0) + vec[i]);
        }
        else if (remind == 2)
        {
            return max(dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 2),
                       dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 1) + vec[i]);
        }
    }
    else if (vec[i] % 3 == 2)
    {
        if (remind == 0)
        {
            return max(dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 0),
                       dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 1) + vec[i]);
        }
        else if (remind == 1)
        {
            return max(dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 1),
                       dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 2) + vec[i]);
        }
        else if (remind == 2)
        {
            return max(dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 2),
                       dfsGreatestSumDivisibleByThree_BA(vec, i + 1, 0) + vec[i]);
        }
    }
    return -1;
}

// 记忆化搜索 (二) :
// Time: O(2^N)
// Space: O(N)
int greatestSumDivisibleByThree_BB(vector<int> vec)
{
    int l = vec.size();
    vector<vector<int>> arr(l + 1, vector<int>(3, 0));
    return dfsGreatestSumDivisibleByThree_BB(vec, 0, 0, arr);
}

int dfsGreatestSumDivisibleByThree_BB(vector<int> vec, int i, int remind, vector<vector<int>> arr)
{
    if (i >= vec.size())
    {
        if (remind == 0)
        {
            arr[vec.size()][0] = 0;
            return 0;
        }
        else
        {
            arr[vec.size()][1] = INT_MIN;
            arr[vec.size()][2] = INT_MIN;
            return INT_MIN;
        }
    }
    if (arr[i][remind] > 0)
    {
        return arr[i][remind];
    }

    // 分情况 讨论：
    if (vec[i] % 3 == 0)
    {
        if (remind == 0)
        {
            int tem = max(dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 0, arr),
                          dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 0, arr) + vec[i]);
            arr[i][remind] = tem;
            return tem;
        }
        else if (remind == 1)
        {
            int tem = max(dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 1, arr),
                          dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 1, arr) + vec[i]);
            arr[i][remind] = tem;
            return tem;
        }
        else if (remind == 2)
        {
            int tem = max(dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 2, arr),
                          dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 2, arr) + vec[i]);
            arr[i][remind] = tem;
            return tem;
        }
    }
    else if (vec[i] % 3 == 1)
    {
        if (remind == 0)
        {
            int tem = max(dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 0, arr),
                          dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 2, arr) + vec[i]);
            arr[i][remind] = tem;
            return tem;
        }
        else if (remind == 1)
        {
            int tem = max(dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 1, arr),
                          dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 0, arr) + vec[i]);
            arr[i][remind] = tem;
            return tem;
        }
        else if (remind == 2)
        {
            int tem = max(dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 2, arr),
                          dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 1, arr) + vec[i]);
            arr[i][remind] = tem;
            return tem;
        }
    }
    else if (vec[i] % 3 == 2)
    {
        if (remind == 0)
        {
            int tem = max(dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 0, arr),
                          dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 1, arr) + vec[i]);
            arr[i][remind] = tem;
            return tem;
        }
        else if (remind == 1)
        {
            int tem = max(dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 1, arr),
                          dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 2, arr) + vec[i]);
            arr[i][remind] = tem;
            return tem;
        }
        else if (remind == 2)
        {
            int tem = max(dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 2, arr),
                          dfsGreatestSumDivisibleByThree_BB(vec, i + 1, 0, arr) + vec[i]);
            arr[i][remind] = tem;
            return tem;
        }
    }
    return -1;
}

// 动态规划(二)：
// Time: O(N)
// Space: O(N)
int greatestSumDivisibleByThree_BC(vector<int> vec)
{
    int l = vec.size();
    vector<vector<int>> dp(l + 1, vector<int>(3, 0));
    dp[l][0] = 0;
    dp[l][1] = INT_MIN;
    dp[l][2] = INT_MIN;

    for (int i = l - 1; i >= 0; i--)
    {
        if (vec[i] % 3 == 0)
        {
            dp[i][0] = max(dp[i + 1][0], dp[i + 1][0] + vec[i]);
            dp[i][1] = max(dp[i + 1][1], dp[i + 1][1] + vec[i]);
            dp[i][2] = max(dp[i + 1][2], dp[i + 1][2] + vec[i]);
        }
        else if (vec[i] % 3 == 1)
        {
            dp[i][0] = max(dp[i + 1][0], dp[i + 1][2] + vec[i]);
            dp[i][1] = max(dp[i + 1][1], dp[i + 1][0] + vec[i]);
            dp[i][2] = max(dp[i + 1][2], dp[i + 1][1] + vec[i]);
        }
        else
        {
            dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] + vec[i]);
            dp[i][1] = max(dp[i + 1][1], dp[i + 1][2] + vec[i]);
            dp[i][2] = max(dp[i + 1][2], dp[i + 1][0] + vec[i]);
        }
    }
    return dp[0][0];
}

// 暴力递归 (三) :
// Time: O(2^N)
// Space: O(N)
int greatestSumDivisibleByThree_CA(vector<int> vec)
{
    return dfsGreatestSumDivisibleByThree_CA(vec, 0, 0);
}

int dfsGreatestSumDivisibleByThree_CA(vector<int> vec, int i, int target)
{
    if (i >= vec.size())
    {
        if (target == 0)
        {
            return 0;
        }
        else
        {
            return INT_MIN;
        }
    }
    int dif = target - (vec[i] % 3);
    int nextTarget = (dif >= 0) ? dif : dif + 3;
    return max(dfsGreatestSumDivisibleByThree_CA(vec, i + 1, target),
               dfsGreatestSumDivisibleByThree_CA(vec, i + 1, nextTarget) + vec[i]);
}

// 记忆化搜索 (三) :
// Time: O(2^N)
// Space: O(N)
int greatestSumDivisibleByThree_CB(vector<int> vec)
{
    int l = vec.size();
    vector<vector<int>> arr(l + 1, vector<int>(3, 0));
    return dfsGreatestSumDivisibleByThree_CB(vec, 0, 0, arr);
}

int dfsGreatestSumDivisibleByThree_CB(vector<int> vec, int i, int target, vector<vector<int>> arr)
{
    if (i >= vec.size())
    {
        if (target == 0)
        {
            arr[vec.size()][0] = 0;
            return 0;
        }
        else
        {
            arr[vec.size()][1] = INT_MIN;
            arr[vec.size()][2] = INT_MIN;
            return INT_MIN;
        }
    }
    if (arr[i][target] > 0)
    {
        return arr[i][target];
    }

    int dif = target - (vec[i] % 3);
    int nextTarget = (dif >= 0) ? dif : dif + 3;
    int tem = max(dfsGreatestSumDivisibleByThree_CA(vec, i + 1, target),
                  dfsGreatestSumDivisibleByThree_CA(vec, i + 1, nextTarget) + vec[i]);
    arr[i][target] = tem;
    return tem;
}

// 动态规划(三)：
// Time: O(N)
// Space: O(N)
int greatestSumDivisibleByThree_CC(vector<int> vec)
{
    int l = vec.size();
    vector<vector<int>> dp(l + 1, vector<int>(3, 0));
    dp[l][0] = 0;
    dp[l][1] = INT_MIN;
    dp[l][2] = INT_MIN;
    for (int i = l - 1; i >= 0; i--)
    {
        for (int j = 2; j >= 0; j--)
        {
            int dif = j - (vec[i] % 3);
            int next = (dif >= 0) ? dif : dif + 3;
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][next] + vec[i]);
        }
    }
    return dp[0][0];
}

// 动态规划(三)<空间压缩>：
// Time: O(N)
// Space: O(1)
int greatestSumDivisibleByThree_CD(vector<int> vec)
{
    int l = vec.size();
    vector<int> dp(3, 0);
    for (int i = l ; i >= 0; i--)
    {
        vector<int> cur(3, 0);
        for (int j = 2; j >= 0; j--)
        {
            if (i >= l) {
                cur[j] = (j == 0) ? 0 : INT_MIN;
                continue;
            }
            int dif = j - (vec[i] % 3);
            int next = (dif >= 0) ? dif : dif + 3;
            cur[j] = max(dp[j], dp[next] + vec[i]);
        }
        dp = cur;
    }
    return dp[0];
}