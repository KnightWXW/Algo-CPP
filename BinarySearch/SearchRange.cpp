#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 34. 在排序数组中查找元素的第一个和最后一个位置

//      链接：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/

//      给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。
//      请你找出给定目标值在数组中的开始位置和结束位置。
//      如果数组中不存在目标值 target，返回 [-1, -1]。
//      你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
//      示例 1：
//          输入：nums = [5,7,7,8,8,10], target = 8
//          输出：[3,4]
//      示例 2：
//          输入：nums = [5,7,7,8,8,10], target = 6
//          输出：[-1,-1]
//      示例 3：
//          输入：nums = [], target = 0
//          输出：[-1,-1]
//      提示：
//          0 <= nums.length <= 105
//          -109 <= nums[i] <= 109
//          nums 是一个非递减数组
//          -109 <= target <= 109

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

vector<int> SearchRange(vector<int> &nums, int target);
int BasicBinarySearchLeft(vector<int> &vec, int target);
int BasicBinarySearchRight(vector<int> &vec, int target);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(1, 10, n);
    int target = vec[0];
    sort(vec.begin(), vec.end());
    printVec(vec);
    vector<int> ans = SearchRange(vec, target);
    printf("目标值 %d 在数组中的开始位置和结束位置为：", target);
    printVec(ans);
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
    printf("vector的元素依次为: ");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 二分查找：
// Time: O(NlogN)
// Space: O(1)
vector<int> SearchRange(vector<int> &nums, int target)
{
    int l = nums.size();
    vector<int> ans(2, -1);
    if (l == 0)
    {
        return ans;
    }
    int start = BasicBinarySearchLeft(nums, target);
    int end = BasicBinarySearchRight(nums, target);
    if (start <= end && nums[start] == target && nums[end] == target)
    {
        ans[0] = start;
        ans[1] = end;
        return ans;
    }else{
        return ans;
    }
}

int BasicBinarySearchLeft(vector<int> &vec, int target)
{
    int l = vec.size();
    int left = 0;
    int right = l - 1;
    int ans = 0;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (vec[mid] >= target)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int BasicBinarySearchRight(vector<int> &vec, int target)
{
    int l = vec.size();
    int left = 0;
    int right = l - 1;
    int ans = 0;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (vec[mid] <= target)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}