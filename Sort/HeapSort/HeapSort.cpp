#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);
void heapSort_A(vector<int> &nums);
void heapInsert_A(vector<int> &nums, int index);
void heapify_A(vector<int> &nums, int index, int heapSize);

int main()
{
    vector<int> vec_A = generateRandomVec(-100, 100, 10);

    printf("数组未排序 前为：\n");
    printVecElement(vec_A);

    heapSort_A(vec_A);

    printf("堆排序 后为：\n");
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

// 堆排序：
// Time: O(NlogN)
// Space: O(1)
void heapSort_A(vector<int> &nums)
{
    int l = nums.size();

    // // 从下向上 建立 堆结构：
    // // heapInsert_A
    // // Time: O(N*logN)
    // for (int i = 0; i < l; i++)
    // {
    //     heapInsert_A(nums, i);
    // }

    // 从上向下 建立 堆结构：
    // heapify_A
    // Time: O(N):
    for (int i = l - 1; i >= 0; i--)
    {
        heapify_A(nums, i, l);
    }

    // Time: O(NlogN)
    int heapSize = l;
    swap(nums[0], nums[heapSize - 1]);
    heapSize--;
    while (heapSize > 0)
    {
        heapify_A(nums, 0, heapSize);
        swap(nums[0], nums[heapSize - 1]);
        heapSize--;
    }
}

void heapInsert_A(vector<int> &nums, int index)
{
    while (nums[index] > nums[(index - 1) >> 1])
    {
        swap(nums[index], nums[(index - 1) >> 1]);
        index = (index - 1) >> 1;
    }
}

void heapify_A(vector<int> &nums, int index, int heapSize)
{
    int leftIndex = (index << 1) + 1;
    while (leftIndex < heapSize)
    {
        int rightIndex = leftIndex + 1;
        int largeIndex = (rightIndex < heapSize && nums[rightIndex] > nums[leftIndex]) ? rightIndex : leftIndex;
        largeIndex = nums[largeIndex] > nums[index] ? largeIndex : index;
        if (largeIndex == index)
        {
            break;
        }

        swap(nums[largeIndex], nums[index]);
        index = largeIndex;
        leftIndex = (index << 1) + 1;
    }
}

