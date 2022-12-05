#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 1493. 删掉一个元素以后全为 1 的最长子数组

//      链接：https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/

//      给你一个二进制数组 nums ，你需要从中删掉一个元素。
//      请你在删掉元素的结果数组中，返回最长的且只包含 1 的非空子数组的长度。
//      如果不存在这样的子数组，请返回 0 。
//      提示 1：
//          输入：nums = [1,1,0,1]
//          输出：3
//          解释：删掉位置 2 的数后，[1,1,1] 包含 3 个 1 。
//      示例 2：
//          输入：nums = [0,1,1,1,0,1,1,0,1]
//          输出：5
//          解释：删掉位置 4 的数字后，[0,1,1,1,1,1,0,1] 的最长全 1 子数组为 [1,1,1,1,1] 。
//      示例 3：
//          输入：nums = [1,1,1]
//          输出：2
//          解释：你必须要删除一个元素。
//      提示：
//          1 <= nums.length <= 105
//          nums[i] 要么是 0 要么是 1 。

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int LongestSubVector(vector<int> &nums);

int main()
{
    int n = generateRandomNum(0, 30);
    vector<int> arr = generateRandomVec(0, 1, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    int ans = LongestSubVector(arr);
    printf("最长的且只包含 1 的非空子数组的长度 %d", ans);
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

int LongestSubVector(vector<int> &nums)
{
    int l = nums.size();
    int left = 0;
    int right = 0;
    int ans = 0;
    int cnt = 0;
    while (right < l)
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
        ans = max(right - left, ans);
        right++;
    }
    return ans;
}