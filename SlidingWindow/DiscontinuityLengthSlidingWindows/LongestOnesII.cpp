#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 487. 最大连续1的个数 II

//      链接：https://leetcode.cn/problems/max-consecutive-ones-ii/

//      给定一个二进制数组，你可以最多将 1 个 0 翻转为 1，找出其中最大连续 1 的个数。

//      示例 1：

//      输入：[1,0,1,1,0]
//      输出：4
//      解释：翻转第一个 0 可以得到最长的连续 1。
//      当翻转以后，最大连续 1 的个数为 4。

//      提示：
//          1 <= nums.length <= 105
//          nums[i] 不是 0 就是 1
//          0 <= k <= nums.length

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int longestOnesII(vector<int> &nums);

int main()
{
    int n = generateRandomNum(0, 30);
    vector<int> arr = generateRandomVec(0, 1, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    int ans = longestOnesII(arr);
    printf("数组中连续 1 的最大个数为 %d", ans);
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
int longestOnesII(vector<int> &nums)
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
        while (cnt > 1)
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