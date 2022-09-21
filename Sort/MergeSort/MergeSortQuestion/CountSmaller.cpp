#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 315. 计算右侧小于当前元素的个数

//      链接：https://leetcode.cn/problems/count-of-smaller-numbers-after-self/

//      给你一个整数数组 nums ，按要求返回一个新数组 counts 。
//      数组 counts 有该性质：
//      counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

//      示例 1：
//      输入：nums = [5,2,6,1]
//      输出：[2,1,1,0]
//      解释：
//          5 的右侧有 2 个更小的元素 (2 和 1)
//          2 的右侧仅有 1 个更小的元素 (1)
//          6 的右侧有 1 个更小的元素 (1)
//          1 的右侧有 0 个更小的元素

//      示例 2：
//      输入：nums = [-1]
//      输出：[0]

//      示例 3：
//      输入：nums = [-1,-1]
//      输出：[0,0]

//      提示：
//          1 <= nums.length <= 105
//          -104 <= nums[i] <= 104

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

vector<int> countSmaller(vector<int> &nums);
void process(vector<int> &nums, int left, int right, vector<int> &ans, vector<int> &indexs);
void merge(vector<int> &nums, int left, int mid, int right, vector<int> &ans, vector<int> &indexs);

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

vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    vector<int> indexs(n, 0);
    for (int i = 0; i < n; i++)
    {
        indexs[i] = i;
    }
    process(nums, 0, n - 1, ans, indexs);
    return ans;
}

// 归并排序(从大到小):
// helpIndexs : 记录排序后 每个元素索引 的 变化情况：
// help       : 记录排序后 的 元素顺序：
void process(vector<int> &nums, int left, int right, vector<int> &ans, vector<int> &indexs)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + ((right - left) >> 1);
    process(nums, left, mid, ans, indexs);
    process(nums, mid + 1, right, ans, indexs);
    merge(nums, left, mid, right, ans, indexs);
}

void merge(vector<int> &nums, int left, int mid, int right, vector<int> &ans, vector<int> &indexs)
{
    int l = right - left + 1;
    vector<int> help(l, 0);
    vector<int> helpIndexs(l, 0);

    int p1 = left;
    int p2 = mid + 1;
    int index = 0;

    while (p1 <= mid && p2 <= right)
    {
        if (nums[p1] > nums[p2])
        {
            ans[indexs[p1]] += right - p2 + 1;
            helpIndexs[index] = indexs[p1];
            help[index++] = nums[p1++];
        }
        else
        {
            helpIndexs[index] = indexs[p2];
            help[index++] = nums[p2++];
        }
    }

    while (p1 <= mid)
    {
        helpIndexs[index] = indexs[p1];
        help[index++] = nums[p1++];
    }

    while (p2 <= right)
    {
        helpIndexs[index] = indexs[p2];
        help[index++] = nums[p2++];
    }

    for (int i = 0; i < help.size(); i++)
    {
        indexs[i + left] = helpIndexs[i];
        nums[i + left] = help[i];
    }
}