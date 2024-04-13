#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 2366. 将数组排序的最少替换次数

//      链接：https://leetcode.cn/problems/minimum-replacements-to-sort-the-array/

//      给你一个下表从 0 开始的整数数组 nums 。
//      每次操作中，你可以将数组中任何一个元素替换为 任意两个 和为该元素的数字。
//      比方说，nums = [5,6,7] 。
//      一次操作中，我们可以将 nums[1] 替换成 2 和 4 ，将 nums 转变成 [5,2,4,7] 。
//      请你执行上述操作，将数组变成元素按 非递减 顺序排列的数组，并返回所需的最少操作次数。
//      示例 1：
//          输入：nums = [3,9,3]
//          输出：2
//          解释：以下是将数组变成非递减顺序的步骤：
//              - [3,9,3] ，将9 变成 3 和 6 ，得到数组 [3,3,6,3]
//              - [3,3,6,3] ，将 6 变成 3 和 3 ，得到数组 [3,3,3,3,3]
//              总共需要 2 步将数组变成非递减有序，所以我们返回 2 。
//      示例 2：
//          输入：nums = [1,2,3,4,5]
//          输出：0
//          解释：数组已经是非递减顺序，所以我们返回 0 。
//      提示：
//          1 <= nums.length <= 105
//          1 <= nums[i] <= 109

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

long long MinimumReplacement(vector<int> &nums);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(1, 100, n);
    printVec(vec);
    long long ans = MinimumReplacement(vec);
    printf("将数组变成元素按 非递减 顺序排列的数组，所需的最少操作次数 为 %ld。\n", ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

vector<int> generateRandomVec(int low, int high, int len)
{
    vector<int> vec;
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 贪心 + 从后遍历
//     最后一个数字 不 拆分
// Time: O(N)
// Space: O(1)
long long MinimumReplacement(vector<int> &nums)
{
    int l = nums.size();
    long long ans = 0;
    int cur = nums[l - 1]; // 当前的数值
    int k = 0;             // 划分的次数
    for (int i = l - 1; i >= 0; i--)
    {
        k = (nums[i] - 1) / cur;
        ans += k;
        cur = (nums[i]) / (k + 1);
    }
    return ans;
}
