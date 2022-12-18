#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 540. 有序数组中的单一元素

//      链接：https://leetcode.cn/problems/single-element-in-a-sorted-array/

//      给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
//      请你找出并返回只出现一次的那个数。
//      你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。
//      示例 1:
//          输入: nums = [1,1,2,3,3,4,4,8,8]
//          输出: 2
//      示例 2:
//          输入: nums = [3,3,7,7,10,11,11]
//          输出: 10
//      提示:
//          1 <= nums.length <= 105
//          0 <= nums[i] <= 105

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int SingleNonDuplicate_A(vector<int> &nums);
int SingleNonDuplicate_B(vector<int> &nums);
int SingleNonDuplicate_C(vector<int> &nums);
int SingleNonDuplicate_D(vector<int> &nums);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(1, 30, n);
    vector<int> copyArr(vec);
    copyArr.erase(vec.end() - 1);
    copy(copyArr.begin(), copyArr.end(), vec.end());
    printVec(vec);
    int ans = SingleNonDuplicate(vec);
    printf("找出并返回只出现一次的那个数 为 %d。", ans);
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
int SingleNonDuplicate_A(vector<int> &nums)
{
    int l = nums.size();
    int left = 0;
    int right = l - 1;
    // 由于数组是有序的，因此数组中相同的元素一定相邻。
    // 目标下标 x 是相同元素的开始下标的奇偶性的分界。
    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        // 对于目标下标 x 左边的下标 y，如果 nums[y] = nums[y+1]，则 y 一定是偶数；
        if ((mid & 1) == 0)
        {
            if (mid + 1 < l && nums[mid] == nums[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        // 对于目标下标 x 右边的下标 z，如果 nums[z] = nums[z+1]，则 z 一定是奇数。
        else
        {
            if (mid - 1 >= 0 && nums[mid] == nums[mid - 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
    }
    return nums[left];
    // return nums[right];
}

int SingleNonDuplicate_B(vector<int> &nums)
{
    int l = nums.size();
    int left = 0;
    int right = l - 1;
    // 由于数组是有序的，因此数组中相同的元素一定相邻。
    // 目标下标 x 是相同元素的开始下标的奇偶性的分界。
    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        // 若 mid 在 奇数索引, mid ^ 1 为 mid - 1 位置
        // 若 mid 在 偶数索引, mid ^ 1 为 mid + 1 位置
        if (nums[mid] == nums[mid ^ 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return nums[left];
    // return nums[right];
}

int SingleNonDuplicate_C(vector<int> &nums)
{
    int l = nums.size();
    if (l == 1)
    {
        return nums[0];
    }
    int left = -1;
    int right = l;
    // 由于数组是有序的，因此数组中相同的元素一定相邻。
    // 目标下标 x 是相同元素的开始下标的奇偶性的分界。
    while (left + 1 != right)
    {
        int mid = left + ((right - left) >> 1);
        // 若 mid 在 奇数索引, mid ^ 1 为 mid - 1 位置
        // 若 mid 在 偶数索引, mid ^ 1 为 mid + 1 位置
        if (nums[mid] == nums[mid ^ 1])
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    return nums[right];
}

int SingleNonDuplicate_D(vector<int> &nums)
{
    int l = nums.size();
    if (l == 1)
    {
        return nums[0];
    }
    int left = -1;
    int right = l;
    // 由于数组是有序的，因此数组中相同的元素一定相邻。
    // 目标下标 x 是相同元素的开始下标的奇偶性的分界。
    while (left + 1 != right)
    {
        int mid = left + ((right - left) >> 1);
        // 对于目标下标 x 左边的下标 y，如果 nums[y] = nums[y+1]，则 y 一定是偶数；
        if ((mid & 1) == 0)
        {
            if (mid + 1 < l && nums[mid] == nums[mid + 1])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        // 对于目标下标 x 右边的下标 z，如果 nums[z] = nums[z+1]，则 z 一定是奇数。
        else
        {
            if (mid - 1 >= 0 && nums[mid] == nums[mid - 1])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
    }
    return nums[right];
}