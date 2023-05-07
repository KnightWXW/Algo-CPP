#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//      LeetCode 442. 数组中重复的数据

//      链接：https://leetcode.cn/problems/find-all-duplicates-in-an-array/

//      给你一个长度为 n 的整数数组 nums，
//      其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次。
//      请你找出所有出现 两次 的整数，并以数组形式返回。
//      你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。
//      示例 1：
//          输入：nums = [4,3,2,7,8,2,3,1]
//          输出：[2,3]
//      示例 2：
//          输入：nums = [1,1,2]
//          输出：[1]
//      示例 3：
//          输入：nums = [1]
//          输出：[]
//      提示：
//          n == nums.length
//          1 <= n <= 105
//          1 <= nums[i] <= n
//          nums 中的每个元素出现 一次 或 两次

int generateRandomNum(int low, int high);
void printVec(vector<int> &vec);
vector<int> generateRandomVec(int low, int high, int len);

vector<int> FindDuplicates_A(vector<int> &nums);
vector<int> FindDuplicates_B(vector<int> &nums);

int main()
{
    int n = generateRandomNum(2, 20);
    vector<int> vec = generateRandomVec(1, n, n);
    printVec(vec);
    vector<int> ans_A = FindDuplicates_A(vec);
    vector<int> ans_B = FindDuplicates_B(vec);
    printf("所有出现 两次 的整数 为 :\n");
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

vector<int> FindDuplicates_A(vector<int> &nums)
{
    int l = nums.size();
    vector<int> ans;
    for (int i = 0; i < l; i++)
    {
        while (nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < l; i++)
    {
        if (nums[i] - 1 != i)
        {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

vector<int> FindDuplicates_B(vector<int> &nums)
{
    int l = nums.size();
    vector<int> ans;
    for (int i = 0; i < l; i++)
    {
        int tem = abs(nums[i]);
        if (nums[tem - 1] > 0)
        {
            nums[tem - 1] = -nums[tem - 1];
        }
        else
        {
            ans.push_back(tem);
        }
    }
    return ans;
}