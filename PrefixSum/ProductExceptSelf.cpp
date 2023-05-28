#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

//      LeetCode 238. 除自身以外数组的乘积

//      链接：https://leetcode.cn/problems/product-of-array-except-self/

//      给你一个整数数组 nums，返回 数组 answer，
//      其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
//      题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在 32 位 整数范围内。
//      请不要使用除法，且在 O(n) 时间复杂度内完成此题。
//      示例 1:
//          输入: nums = [1,2,3,4]
//          输出: [24,12,8,6]
//      示例 2:
//          输入: nums = [-1,1,0,-3,3]
//          输出: [0,0,9,0,0]
//      提示：
//          2 <= nums.length <= 105
//          -30 <= nums[i] <= 30
//      保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在 32 位 整数范围内
//      进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？
//      （ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

vector<int> ProductExceptSelf_A(vector<int> &nums);
vector<int> ProductExceptSelf_B(vector<int> &nums);
vector<int> ProductExceptSelf_C(vector<int> &nums);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> vec = generateRandomVec(-10, 10, n);
    printVecElement(vec);
    vector<int> ans_A = ProductExceptSelf_A(vec);
    vector<int> ans_B = ProductExceptSelf_B(vec);
    vector<int> ans_C = ProductExceptSelf_C(vec);
    printf("除自身以外数组的乘积 为：\n");
    printVecElement(ans_A);
    printVecElement(ans_B);
    printVecElement(ans_C);
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

// 前缀积：两个辅助数组
// Time: O(N)
// Space: O(N)
vector<int> ProductExceptSelf_A(vector<int> &nums)
{
    int l = nums.size();
    vector<int> leftArr(l, 1);
    vector<int> rightArr(l, 1);
    vector<int> ans(l, 1);
    for (int i = 1; i < l; i++)
    {
        leftArr[i] = leftArr[i - 1] * nums[i - 1];
    }
    for (int i = l - 2; i >= 0; i--)
    {
        rightArr[i] = rightArr[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < l; i++)
    {
        ans[i] = leftArr[i] * rightArr[i];
    }
    return ans;
}

// 前缀积：一个辅助数组
// Time: O(N)
// Space: O(N)
vector<int> ProductExceptSelf_B(vector<int> &nums)
{
    int l = nums.size();
    int leftMul = 1;
    vector<int> rightArr(l, 1);
    vector<int> ans(l, 1);
    for (int i = l - 2; i >= 0; i--)
    {
        rightArr[i] = rightArr[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < l; i++)
    {
        ans[i] = leftMul * rightArr[i];
        leftMul *= nums[i];
    }
    return ans;
}

// 分情况讨论：
// Time: O(N)
// Space: O(1)
vector<int> ProductExceptSelf_C(vector<int> &nums)
{
    int l = nums.size();
    vector<int> ans;
    int zero = 0;
    int zeroIndex = -1;
    for (int i = 0; i < l; i++)
    {
        if (nums[i] == 0)
        {
            zeroIndex = i;
            zero++;
        }
    }
    // 数组中 0 的个数 大于1
    if (zero > 1)
    {
        ans = vector<int>(l, 0);
        return ans;
    }
    // 数组中 0 的个数 等于1
    else if (zero == 1)
    {
        int mul = 1;
        for (int i = 0; i < l; i++)
        {
            if (i != zeroIndex)
            {
                mul *= nums[i];
            }
        }
        ans = vector<int>(l, 0);
        ans[zeroIndex] = mul;
        return ans;
    }
    // 数组中 0 的个数 为 0
    int mulAll = 1;
    ans = vector<int>(l, 1);
    for (int i = 0; i < l; i++)
    {
        mulAll *= nums[i];
    }
    for (int i = 0; i < l; i++)
    {
        ans[i] = mulAll / nums[i];
    }
    return ans;
}