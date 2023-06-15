#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 面试题 08.03. 魔术索引

//      链接：https://leetcode.cn/problems/magic-index-lcci/

//      在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i] = i。
//      给定一个有序整数数组，编写一种方法找出魔术索引，
//      若有的话，在数组A中找出一个魔术索引，如果没有，则返回-1。
//      若有多个魔术索引，返回索引值最小的一个。
//      示例1:
//          输入：nums = [0, 2, 3, 4, 5]
//          输出：0
//          说明: 0下标的元素为 0
//      示例2:
//          输入：nums = [1, 1, 1]
//          输出：1
//      说明:
//          nums长度在[1, 1000000]之间
//          此题为原书中的 Follow-up，即数组中可能包含重复元素的版本

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int FindMagicIndex_A(vector<int> &nums);
int FindMagicIndex_B(vector<int> &nums);
int FindMagicIndex_B_Helper(vector<int> &nums, int left, int right);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> vec = generateRandomVec(1, 5, n);
    sort(vec.begin(), vec.end());
    printVecElement(vec);
    int ans_A = FindMagicIndex_A(vec);
    int ans_B = FindMagicIndex_B(vec);
    printf("数组 中找出一个魔术索引为 %d \n", ans_A);
    printf("数组 中找出一个魔术索引为 %d \n", ans_B);
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

// 暴力遍历：
// Time: O(N)
// Space: O(1)
int FindMagicIndex_A(vector<int> &nums)
{
    int l = nums.size();
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        if (nums[i] == i)
        {
            return i;
        }
    }
    return -1;
}

// 二分查找：
// Time: O(N)
// Space: O(1)
int FindMagicIndex_B(vector<int> &nums)
{
    int l = nums.size();
    return FindMagicIndex_B_Helper(nums, 0, l - 1);
}

int FindMagicIndex_B_Helper(vector<int> &nums, int left, int right)
{  
    if (left > right)
    {
        return -1;
    }
    int mid = left + ((right - left) >> 1);
    int leftIndex = FindMagicIndex_B_Helper(nums, left, mid - 1);
    if (leftIndex != -1)
    {
        return leftIndex;
    }
    else if (nums[mid] == mid)
    {
        return mid;
    }
    return FindMagicIndex_B_Helper(nums, mid + 1, right);
}