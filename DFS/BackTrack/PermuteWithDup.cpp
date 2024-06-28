#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>

using namespace std;

//      LeetCode 47. 全排列 II

//      链接：https://leetcode.cn/problems/permutations-ii/

//      给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
//      示例 1：
//      输入：nums = [1,1,2]
//      输出：
//           [[1,1,2],
//            [1,2,1],
//            [2,1,1]]
//      示例 2：
//      输入：nums = [1,2,3]
//      输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//      提示：
//          1 <= nums.length <= 8
//          -10 <= nums[i] <= 10

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

vector<vector<int>> permuteWithDup_A(vector<int> nums);
void dfsPermuteWithDup_A(vector<int> &nums, int index, vector<vector<int>> &ans);

int main()
{
    int n = generateRandomNum(0, 5);
    vector<int> vec = generateRandomVec(1, 3, n);
    vector<vector<int>> ans_A = permuteWithDup_A(vec);
    printf("vec数组 元素为:");
    printVecElement(vec);

    printf("方法一：\n");
    for (int i = 0; i < ans_A.size(); i++)
    {
        printVecElement(ans_A[i]);
    }
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

// 递归一:
// Time: O(2^N)
// Space: O(2^N)
vector<vector<int>> permuteWithDup_A(vector<int> nums)
{
    vector<vector<int>> ans;
    if (nums.size() == 0)
    {
        return ans;
    }
    dfsPermuteWithDup_A(nums, 0, ans);
    return ans;
}

void dfsPermuteWithDup_A(vector<int> &nums, int index, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    set<int> flagSet;

    // 还原现场：
    for (int i = index; i < nums.size(); i++)
    {
        if (flagSet.count(nums[i]) == 0)
        {
            flagSet.insert(nums[i]);
            swap(nums[i], nums[index]);
            dfsPermuteWithDup_A(nums, index + 1, ans);
            swap(nums[i], nums[index]);
        }
    }
}