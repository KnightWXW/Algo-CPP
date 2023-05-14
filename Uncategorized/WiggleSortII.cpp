#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      LeetCode 324. 摆动排序 II

//      链接：https://leetcode.cn/problems/wiggle-sort-ii/

//      给你一个整数数组 nums，
//      将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
//      你可以假设所有输入数组都可以得到满足题目要求的结果。
//      示例 1：
//          输入：nums = [1,5,1,1,6,4]
//          输出：[1,6,1,5,1,4]
//          解释：[1,4,1,5,1,6] 同样是符合题目要求的结果，可以被判题程序接受。
//      示例 2：
//          输入：nums = [1,3,2,2,3,1]
//          输出：[2,3,1,3,1,2]
//      提示：
//          1 <= nums.length <= 5 * 104
//          0 <= nums[i] <= 5000
//          题目数据保证，对于给定的输入 nums ，总能产生满足题目要求的结果
//      进阶：你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

void WiggleSortII(vector<int>& nums);

int main()
{
    int n = generateRandomNum(0, 10);
    vector<int> arr = generateRandomVec(1, 10, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    vector<int> counts = countSmaller(arr);
    printVecElement(counts);
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

void WiggleSortII(vector<int>& nums);