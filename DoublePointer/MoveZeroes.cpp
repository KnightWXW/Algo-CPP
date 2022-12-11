#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      LeetCode 283. 移动零

//      链接：https://leetcode.cn/problems/move-zeroes/

//      给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，
//      同时保持非零元素的相对顺序。
//      请注意 ，必须在不复制数组的情况下原地对数组进行操作。
//      示例 1:
//          输入: nums = [0,1,0,3,12]
//          输出: [1,3,12,0,0]
//      示例 2:
//          输入: nums = [0]
//          输出: [0]
//      提示:
//          1 <= nums.length <= 104
//          -231 <= nums[i] <= 231 - 1

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

void MoveZeroesTail(vector<int> &nums);
void MoveZeroesHead(vector<int> &nums);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec_A = generateRandomVec(0, 5, n);
    vector<int> vec_B(vec_A);
    printVecElement(vec_A);

    MoveZeroesTail(vec_A);
    printf("移动零到数组尾部之后, 数组为: \n");
    printVecElement(vec_A);

    MoveZeroesHead(vec_B);
    printf("移动零到数组头部之后, 数组为: \n");
    printVecElement(vec_B);
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

// 同向双指针：
// Time: O(N)
// Space: O(1)
// slow指针: 指向当前已经处理好的序列的尾部，
// fast指针: 指向待处理序列的头部.   
void MoveZeroesTail(vector<int> &nums)
{
    int l = nums.size();
    int fast = 0;
    int slow = 0;
    while (fast < l)
    {
        if (nums[fast] != 0)
        {
            swap(nums[fast], nums[slow]);
            slow++;
        }
        fast++;
    }
}

// 同向双指针：
// Time: O(N)
// Space: O(1)
// slow指针: 指向当前已经处理好的序列的尾部，
// fast指针: 指向待处理序列的头部。
void MoveZeroesHead(vector<int> &nums)
{
    int l = nums.size();
    int fast = l - 1;
    int slow = l - 1;
    while (fast >= 0)
    {
        if (nums[fast] != 0)
        {
            swap(nums[fast], nums[slow]);
            slow--;
        }
        fast--;
    }
}