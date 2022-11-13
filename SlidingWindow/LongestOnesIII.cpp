#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 1004. 最大连续1的个数 III

//      链接：https://leetcode.cn/problems/max-consecutive-ones-iii/

//      给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，
//      则返回 数组中连续 1 的最大个数 。

//      示例 1：
//      输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
//      输出：6
//      解释：[1,1,1,0,0,1,1,1,1,1,1]
//      粗体数字从 0 翻转到 1，最长的子数组长度为 6。

//      示例 2：
//      输入：nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
//      输出：10
//      解释：[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
//      粗体数字从 0 翻转到 1，最长的子数组长度为 10。

//      提示：
//          1 <= nums.length <= 105
//          nums[i] 不是 0 就是 1
//          0 <= k <= nums.length

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int longestOnesIII(vector<int> &nums, int k);

int main()
{
    int n = generateRandomNum(0, 30);
    int k = generateRandomNum(0, n);
    vector<int> arr = generateRandomVec(0, 1, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    int ans = longestOnesIII(arr, k);
    printf("当 k 为 %d 时, 数组中连续 1 的最大个数为 %d", k, ans);
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

// 滑动窗口：
// Time: O(n)
// Space: O(1)
int longestOnesIII(vector<int> &nums, int k)
{
    int n = nums.size();

    int ans = 0;
    int cnt = 0;

    int left = 0;
    int right = 0;

    while (right < n)
    {
        if (nums[right] == 0)
        {
            cnt++;
        }
        while (cnt > k)
        {
            if (nums[left] == 0)
            {
                cnt--;
            }

            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }

    return ans;
}