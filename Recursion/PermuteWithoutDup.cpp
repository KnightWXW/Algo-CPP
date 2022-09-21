#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 46. 全排列

//      链接：https://leetcode.cn/problems/permutations/

//      给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列。
//      你可以 按任意顺序 返回答案。

//      示例 1：

//      输入：nums = [1,2,3]
//      输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

//      示例 2：
//      输入：nums = [0,1]
//      输出：[[0,1],[1,0]]

//      示例 3：
//      输入：nums = [1]
//      输出：[[1]]

//      提示：
//          1 <= nums.length <= 6
//          -10 <= nums[i] <= 10
//          nums 中的所有整数 互不相同

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

vector<vector<int>> permuteWithDup_A(vector<int> nums);
vector<vector<int>> permuteWithDup_B(vector<int> nums);
void dfsPermuteWithDup_A(vector<int> nums, vector<int> &path, vector<vector<int>> &ans, vector<bool> flag);
void dfsPermuteWithDup_B(vector<int> &nums, int index, vector<vector<int>> &ans);

int main()
{
    int n = generateRandomNum(0, 5);
    vector<int> vec = generateRandomVec(0, 9, n);
    vector<vector<int>> ans_A = permuteWithDup_A(vec);
    vector<vector<int>> ans_B = permuteWithDup_B(vec);
    printf("vec数组 元素为:");
    printVecElement(vec);

    printf("方法一：\n");
    for (int i = 0; i < ans_A.size(); i++)
    {
        printVecElement(ans_A[i]);
    }

    printf("方法二：\n");
    for (int i = 0; i < ans_B.size(); i++)
    {
        printVecElement(ans_B[i]);
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
    vector<bool> flag(nums.size());
    vector<int> path;
    dfsPermuteWithDup_A(nums, path, ans, flag);
    return ans;
}

void dfsPermuteWithDup_A(vector<int> nums, vector<int> &path, vector<vector<int>> &ans, vector<bool> flag)
{
    if (path.size() == nums.size())
    {
        ans.push_back(path);
        return;
    }

    // 标记数组 是否 访问过：
    for (int i = 0; i < nums.size(); i++)
    {
        if (flag[i] != true)
        {
            flag[i] = true;
            path.push_back(nums[i]);
            dfsPermuteWithDup_A(nums, path, ans, flag);
            path.pop_back();
            flag[i] = false;
        }
    }
}

// 递归二:
// Time: O(2^N)
// Space: O(2^N)
vector<vector<int>> permuteWithDup_B(vector<int> nums)
{
    vector<vector<int>> ans;
    if (nums.size() == 0)
    {
        return ans;
    }
    dfsPermuteWithDup_B(nums, 0, ans);
    return ans;
}

void dfsPermuteWithDup_B(vector<int> &nums, int index, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    // 还原现场：
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[i], nums[index]);
        dfsPermuteWithDup_B(nums, index + 1, ans);
        swap(nums[i], nums[index]);
    }
}