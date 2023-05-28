#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

//      LeetCode 525. 连续数组

//      链接1 ：https://leetcode.cn/problems/contiguous-array/
//      链接2 ：https://leetcode.cn/problems/A1NYOS/

//      给定一个 二进制数组 nums,
//      找到含有 相同数量 的 0 和 1 的 最长连续子数组，
//      并返回该子数组的长度。
//      示例 1:
//          输入: nums = [0,1]
//          输出: 2
//          说明: [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
//      示例 2:
//          输入: nums = [0,1,0]
//          输出: 2
//          说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
//      提示：
//          1 <= nums.length <= 105
//          nums[i] 不是 0 就是 1

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int FindMaxLength(vector<int> &nums);

int main()
{
    int n = generateRandomNum(1, 50);
    vector<int> vec = generateRandomVec(0, 1, n);
    printVecElement(vec);
    int ans = FindMaxLength(vec);
    printf("含有 相同数量 的 0 和 1 的 最长连续子数组 的长度 为 %d\n", ans);
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

int FindMaxLength(vector<int> &nums)
{
    int l = nums.size();
    int ans = 0;
    int sum = 0;
    unordered_map<int, int> hmap;
    hmap[0] = -1;
    for (int i = 0; i < l; i++)
    {
        if (nums[i] == 1)
        {
            sum++;
        }
        else
        {
            sum--;
        }
        if (hmap.find(sum) != hmap.end())
        {
            ans = max(ans, i - hmap[sum]);
        }
        else
        {
            hmap[sum] = i;
        }
    }
    return ans;
}