#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//      LeetCode 2789. 合并后数组中的最大元素

//      链接：https://leetcode.cn/problems/largest-element-in-an-array-after-merge-operations/

//      给你一个下标从 0 开始、由正整数组成的数组 nums 。
//      你可以在数组上执行下述操作 任意 次：
//      选中一个同时满足 0 <= i < nums.length - 1 和 nums[i] <= nums[i + 1] 的整数 i 。
//      将元素 nums[i + 1] 替换为 nums[i] + nums[i + 1] ，并从数组中删除元素 nums[i] 。
//      返回你可以从最终数组中获得的 最大 元素的值。
//      示例 1：
//          输入：nums = [2,3,7,9,3]
//          输出：21
//          解释：我们可以在数组上执行下述操作：
//              - 选中 i = 0 ，得到数组 nums = [5,7,9,3] 。
//              - 选中 i = 1 ，得到数组 nums = [5,16,3] 。
//              - 选中 i = 0 ，得到数组 nums = [21,3] 。
//              最终数组中的最大元素是 21 。可以证明我们无法获得更大的元素。
//      示例 2：
//          输入：nums = [5,3,3]
//          输出：11
//          解释：我们可以在数组上执行下述操作：
//              - 选中 i = 1 ，得到数组 nums = [5,6] 。
//              - 选中 i = 0 ，得到数组 nums = [11] 。
//              最终数组中只有一个元素，即 11 。
//      提示：
//          1 <= nums.length <= 105
//          1 <= nums[i] <= 106

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

long long MaxArrayValue(vector<int> &nums);

int main()
{
    int n = generateRandomNum(0, 20);
    vector<int> vec = generateRandomVec(0, 100, n);
    printVecElement(vec);
    long long ans_A = MaxArrayValue(vec);
    printf("从最终数组中获得的 最大 元素的值 为 %d。\n", ans_A);
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

// 贪心：逆向遍历
// Time: O(N)
// Space: O(N)
long long MaxArrayValue(vector<int> &nums)
{
    long long ans = 0;
    int l = nums.size();
    for (int i = l - 1; i >= 0; i--)
    {
        if (nums[i] <= ans)
        {
            ans += nums[i];
        }
        else
        {
            ans = nums[i];
        }
    }
    return ans;
}