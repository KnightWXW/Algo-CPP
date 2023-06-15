#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//      LeetCode 456. 132 模式

//      链接：https://leetcode.cn/problems/132-pattern/

//      给你一个整数数组 nums ，数组中共有 n 个整数。
//      132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k] 组成，
//      并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j] 。
//      如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。
//      示例 1：
//          输入：nums = [1,2,3,4]
//          输出：false
//          解释：序列中不存在 132 模式的子序列。
//      示例 2：
//          输入：nums = [3,1,4,2]
//          输出：true
//          解释：序列中有 1 个 132 模式的子序列： [1, 4, 2] 。
//      示例 3：
//          输入：nums = [-1,3,2,0]
//          输出：true
//          解释：序列中有 3 个 132 模式的的子序列：[-1, 3, 2]、[-1, 3, 0] 和 [-1, 2, 0] 。
//      提示：
//          n == nums.length
//          1 <= n <= 2 * 105
//          -109 <= nums[i] <= 109

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);
void printBool(bool b);

bool Find132pattern(vector<int> &nums);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> vec = generateRandomVec(-100, 100, n);
    printVecElement(vec);
    bool ans_A = Find132pattern(vec);
    printf("nums 中是否存在 132 模式的子序列：\n");
    printBool(ans_A);
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

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

// 单调栈(含重复值) + 前缀和：
// Time: O(n)
// Space: O(n)
bool Find132pattern(vector<int> &nums)
{
    int l = nums.size();
    vector<int> preMin(l, 0);
    preMin[0] = nums[0];
    for (int i = 1; i < l; i++)
    {
        preMin[i] = min(preMin[i - 1], nums[i]);
    }
    stack<int> stk;
    int second = INT_MIN;
    for (int i = l - 1; i >= 0; i--)
    {
        if (nums[i] > preMin[i])
        {
            while (!stk.empty() && nums[i] > stk.top())
            {
                second = stk.top();
                stk.pop();
            }
            if (second > preMin[i])
            {
                return true;
            }
            if (nums[i] > second)
            {
                stk.push(nums[i]);
            }
        }
    }
    return false;
}