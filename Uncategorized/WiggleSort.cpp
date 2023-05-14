#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      LeetCode 280. 摆动排序

//      链接：https://leetcode.cn/problems/wiggle-sort/

//      给你一个的整数数组 nums, 
//      将该数组重新排序后使 nums[0] <= nums[1] >= nums[2] <= nums[3]…
//      输入数组总是有一个有效的答案。
//      示例 1:
//          输入：nums = [3,5,2,1,6,4]
//          输出：[3,5,1,6,2,4]
//          解释：[1,6,2,5,3,4]也是有效的答案
//      示例 2:
//          输入：nums = [6,6,5,6,3,8]
//          输出：[6,6,5,6,3,8]
//      提示：
//          1 <= nums.length <= 5 * 104
//          0 <= nums[i] <= 104
//          输入的 nums 保证至少有一个答案。
//      进阶：你能在 O(n) 时间复杂度下解决这个问题吗？

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

void WiggleSort(vector<int>& nums);

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

void WiggleSort(vector<int>& nums);