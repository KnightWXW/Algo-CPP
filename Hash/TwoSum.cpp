#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 1. 两数之和

//      链接：https://leetcode.cn/problems/two-sum/

//      给定一个整数数组 nums 和一个整数目标值 target，
//      请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//      你可以假设每种输入只会对应一个答案。
//      但是，数组中同一个元素在答案里不能重复出现。
//      你可以按任意顺序返回答案。
//      示例 1：
//          输入：nums = [2,7,11,15], target = 9
//          输出：[0,1]
//          解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
//      示例 2：
//          输入：nums = [3,2,4], target = 6
//          输出：[1,2]
//      示例 3：
//          输入：nums = [3,3], target = 6
//          输出：[0,1]
//      提示：
//          2 <= nums.length <= 104
//          -109 <= nums[i] <= 109
//          -109 <= target <= 109
//          只会存在一个有效答案
//      进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？

int generateRandomNum(int low, int high);
void printVec(vector<int> &vec);
vector<int> generateRandomVec(int low, int high, int len);

vector<int> TwoSum_A(vector<int> &nums, int target);
vector<int> TwoSum_B(vector<int> &nums, int target);

int main()
{
    int n = generateRandomNum(0, 20);
    vector<int> vec = generateRandomVec(-100, 100, n);
    printVec(vec);
    int sum = accumulate(vec.begin(), vec.end(), 0);
    int target = generateRandomNum(0, sum);
    vector<int> ans_A = TwoSum_A(vec, target);
    vector<int> ans_B = TwoSum_B(vec, target);
    printf("两数之和 为 %d 的索引位置为\n", target);
    printVec(ans_A);
    printVec(ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
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

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

vector<int> TwoSum_A(vector<int> &nums, int target)
{
    int l = nums.size();
    vector<int> ans(2, -1);
    for (int i = 0; i < l; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans[0] = i;
                ans[1] = j;
                break;
            }
        }
    }
    return ans;
}

vector<int> TwoSum_B(vector<int> &nums, int target)
{
    int l = nums.size();
    vector<int> ans(2, -1);
    unordered_map<int, int> umap;
    for (int i = 0; i < l; i++)
    {
        if (umap.find(target - nums[i]) != umap.end())
        {
            ans[0] = umap[target - nums[i]];
            ans[1] = i;
            break;
        }
        umap[nums[i]] = i;
    }
    return ans;
}