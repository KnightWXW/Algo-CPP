#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <set>

using namespace std;

//      LeetCode 330. 按要求补齐数组

//      链接：https://leetcode.cn/problems/patching-array/

//      给定一个已排序的正整数数组 nums ，和一个正整数 n 。
//      从 [1, n] 区间内选取任意个数字补充到 nums 中，
//      使得 [1, n] 区间内的任何数字都可以用 nums 中某几个数字的和来表示。
//      请返回 满足上述要求的最少需要补充的数字个数 。
//      示例 1:
//          输入: nums = [1,3], n = 6
//          输出: 1
//          解释:
//              根据 nums 里现有的组合 [1], [3], [1,3]，可以得出 1, 3, 4。
//              现在如果我们将 2 添加到 nums 中，
//              组合变为: [1], [2], [3], [1,3], [2,3], [1,2,3]。
//              其和可以表示数字 1, 2, 3, 4, 5, 6，能够覆盖 [1, 6] 区间里所有的数。
//              所以我们最少需要添加一个数字。
//      示例 2:
//          输入: nums = [1,5,10], n = 20
//          输出: 2
//          解释: 我们需要添加 [2,4]。
//      示例 3:
//          输入: nums = [1,2,2], n = 5
//          输出: 0
//      提示：
//          1 <= nums.length <= 1000
//          1 <= nums[i] <= 104
//          nums 按 升序排列
//          1 <= n <= 231 - 1

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int MinPatches(vector<int> &nums, int n);

int main()
{
    int n = generateRandomNum(1, 30);
    int l = generateRandomNum(1, 100);
    vector<int> vec = generateRandomVec(1, 50, n);
    printVecElement(vec);
    int ans_A = MinPatches(vec, l);
    printf("最少需要补充的数字个数为: %d\n", ans_A);
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
int MinPatches(vector<int> &nums, int n)
{
    int l = nums.size();
    int ans = 0;
    set<int> hset;
    for (int i = 0; i < l; i++)
    {
        hset[nums[i]] = true;
    }
    int cur = nums[0];
    while (cur <= n)
    {
        if (hset[nums[i]] == true)
        {

        }
    }
}