#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//     快速排序(递归方式)：

vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

void quickSort_A(vector<int> &nums);
void process_A(vector<int> &nums, int left, int right);
vector<int> partition_A(vector<int> &nums, int left, int right);

int main()
{
    vector<int> vec_A = generateRandomVec(-100, 100, 15);

    printf("数组为：\n");
    printVecElement(vec_A);

    quickSort_A(vec_A);

    printf("快速排序 后 数组 为：\n");
    printVecElement(vec_A);
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

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 快速排序(递归)：
// Time: O(NlogN)
// Space: O(logN)
void quickSort_A(vector<int> &nums)
{
    int l = nums.size();
    if (l <= 1)
    {
        return;
    }
    process_A(nums, 0, l - 1);
}

void process_A(vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    // 随机选择 一个 索引位置，交换到 数组最后 位置：
    int randomIndex = left + (rand() % (right - left + 1));
    swap(nums[right], nums[randomIndex]);

    vector<int> area = partition_A(nums, left, right);
    process_A(nums, left, area[0] - 1);
    process_A(nums, area[1] + 1, right);
}

vector<int> partition_A(vector<int> &nums, int left, int right)
{
    if (left > right)
    {
        return vector<int>{-1, -1};
    }
    if (left == right)
    {
        return vector<int>{left, right};
    }

    int lowRange = left - 1;
    int highRange = right;
    int index = left;

    // 基准值(pivot)：nums[right]
    while (index < highRange)
    {
        if (nums[index] < nums[right])
        {
            swap(nums[index], nums[lowRange + 1]);
            index++;
            lowRange++;
        }
        else if (nums[index] > nums[right])
        {
            swap(nums[index], nums[highRange - 1]);
            highRange--;
        }
        else
        {
            index++;
        }
    }
    // 交换 pivot 与 nums[highRange - 1]
    swap(nums[highRange], nums[right]);
    return vector<int>{lowRange + 1, highRange};
}