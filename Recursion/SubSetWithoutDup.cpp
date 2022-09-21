#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//      LeetCode 78. 子集

//      链接：https://leetcode.cn/problems/subsets/

//      给你一个整数数组 nums ，数组中的元素 互不相同 。
//      返回该数组所有可能的子集（幂集）。
//      解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

//      示例 1：
//      输入：nums = [1,2,3]
//      输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

//      示例 2：
//      输入：nums = [0]
//      输出：[[],[0]]

//      提示：

//          1 <= nums.length <= 10
//          -10 <= nums[i] <= 10
//          nums 中的所有元素 互不相同

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

vector<vector<int>> subSetWithDup(vector<int> nums);
void dfsSubSetWithDup(vector<int> nums, int index, set<vector<int>> &ans, vector<int> &path);

int main()
{
    int n = generateRandomNum(0, 5);
    vector<int> vec = generateRandomVec(1, 3, n);
    printf("vec数组元素为:");
    printVecElement(vec);
    vector<vector<int>> ans = subSetWithDup(vec);
    for (int i = 0; i < ans.size(); i++)
    {
        printVecElement(ans[i]);
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

vector<vector<int>> subSetWithDup(vector<int> nums)
{
    if (nums.size() == 0)
    {
        return vector<vector<int>>{};
    }
    
    set<vector<int>> sets;
    vector<int> path;
    sort(nums.begin(), nums.end());
    dfsSubSetWithDup(nums, 0, sets, path);
    vector<vector<int>> ans(sets.begin(), sets.end());
    return ans;
}

// 递归:
// Time: O(2^N)
// Space: O(2^N)
void dfsSubSetWithDup(vector<int> nums, int index, set<vector<int>> &sets, vector<int> &path)
{
    if (index == nums.size())
    {
        sets.insert(path);
        return;
    }

    // 没有选择 nums[index]：
    vector<int> noVec;
    noVec.assign(path.begin(), path.end());
    dfsSubSetWithDup(nums, index + 1, sets, noVec);

    // 选择了 nums[index]：
    vector<int> yesVec;
    yesVec.assign(path.begin(), path.end());
    yesVec.push_back(nums[index]);
    dfsSubSetWithDup(nums, index + 1, sets, yesVec);
}