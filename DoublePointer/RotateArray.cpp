#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 189. 轮转数组

//      链接：https://leetcode.cn/problems/rotate-array/

//      给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
//      示例 1:
//          输入: nums = [1,2,3,4,5,6,7], k = 3
//          输出: [5,6,7,1,2,3,4]
//          解释:
//              向右轮转 1 步: [7,1,2,3,4,5,6]
//              向右轮转 2 步: [6,7,1,2,3,4,5]
//              向右轮转 3 步: [5,6,7,1,2,3,4]
//      示例 2:
//          输入：nums = [-1,-100,3,99], k = 2
//          输出：[3,99,-1,-100]
//          解释:
//              向右轮转 1 步: [99,-1,-100,3]
//              向右轮转 2 步: [3,99,-1,-100]
//      提示：
//          1 <= nums.length <= 105
//          -231 <= nums[i] <= 231 - 1
//          0 <= k <= 105
//      进阶：
//          尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
//          你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

vector<int> RotateArray(vector<int> &nums, int k);
void RotateArr(vector<int> &nums, int start, int end);

int main()
{
    int n = generateRandomNum(1, 10);
    int k = generateRandomNum(1, 100);
    vector<int> vec = generateRandomVec(-100, 100, n);
    printVec(vec);
    vector<int> ans = RotateArray(vec, k);
    printf("将数组中的元素向右轮转 %d 个位置, 数组为：", k);
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
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

vector<int> RotateArray(vector<int> &nums, int k)
{
    vector<int> vec(nums);
    int l = nums.size();
    k %= l;
    RotateArr(vec, 0, l - k - 1);
    RotateArr(vec, l - k, l - 1);
    RotateArr(vec, 0, l - 1);
    return vec;
}

void RotateArr(vector<int> &nums, int start, int end)
{
    int left = start;
    int right = end;
    while (left <= right)
    {
        int tem = nums[left];
        nums[left] = nums[right];
        nums[right] = tem;
        left++;
        right--;
    }
    return;
}