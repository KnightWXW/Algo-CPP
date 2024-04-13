#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <functional>

using namespace std;

//      LeetCode 2587. 重排数组以得到最大前缀分数

//      链接：https://leetcode.cn/problems/rearrange-array-to-maximize-prefix-score/

//      给你一个下标从 0 开始的整数数组 nums 。
//      你可以将 nums 中的元素按 任意顺序 重排（包括给定顺序）。
//      令 prefix 为一个数组，它包含了 nums 重新排列后的前缀和。
//      换句话说，prefix[i] 是 nums 重新排列后下标从 0 到 i 的元素之和。
//      nums 的 分数 是 prefix 数组中正整数的个数。
//      返回可以得到的最大分数。
//      示例 1：
//          输入：nums = [2,-1,0,1,-3,3,-3]
//          输出：6
//          解释：数组重排为 nums = [2,3,1,-1,-3,0,-3] 。
//              prefix = [2,5,6,5,2,2,-1] ，分数为 6 。
//              可以证明 6 是能够得到的最大分数。
//      示例 2：
//          输入：nums = [-2,-3,0]
//          输出：0
//          解释：不管怎么重排数组得到的分数都是 0 。
//      提示：
//          1 <= nums.length <= 105
//          -106 <= nums[i] <= 106

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int MaxPrefixScore(vector<int> &nums);

int main()
{
    int n = generateRandomNum(0, 20);
    vector<int> vec = generateRandomVec(-100, 100, n);
    printVecElement(vec);
    int ans_A = MaxPrefixScore(vec);
    printf("重排数组以得到最大前缀分数 为 %d。\n", ans_A);
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
// Space: O(N)
int MaxPrefixScore(vector<int> &nums)
{
    int l = nums.size();
    long long pre = 0;
    int ans = 0;
    sort(nums.begin(), nums.end(), greater<int>());
    // sort(nums.rbegin(), nums.rend());
    for (int i = 0; i < l; i++)
    {
        pre += nums[i];
        if (pre > 0)
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    return ans;
}