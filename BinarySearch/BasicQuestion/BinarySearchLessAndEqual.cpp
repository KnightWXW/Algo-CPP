#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// 在有序(升序)数组中查找 第一个 小于等于 目标值 target 的元素 所在的索引位置。
// 如果存在，返回索引；不存在返回 -1。

int binarySearchLessAndEqual_A(vector<int> &vec, int target);
int binarySearchLessAndEqual_B(vector<int> &vec, int target);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int main()
{
    vector<int> vec = generateRandomVec(0, 100, 10);
    printVec(vec);
    int target = vec[0];
    sort(vec.begin(), vec.end());
    printVec(vec);
    printf("小于等于 %d 在vector中的第一个索引位置为 %d\n", target, binarySearchLessAndEqual_A(vec, target));
    printf("小于等于 %d 在vector中的第一个索引位置为 %d\n", target, binarySearchLessAndEqual_B(vec, target));
}

// 产生随机数组：
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

// 打印数组：
void printVec(vector<int> &vec)
{
    printf("vector的元素依次为：");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// Time: O(logN)
// Space: O(1)
int binarySearchLessAndEqual_A(vector<int> &vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (vec[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    if(right < 0){
        return -1;
    }
    return right;
}

// Time: O(logN)
// Space: O(1)
int binarySearchLessAndEqual_B(vector<int> &vec, int target)
{
    int left = -1;
    int right = vec.size();
    while (left + 1 != right)
    {
        int mid = left + ((right - left) >> 1);
        if (vec[mid] <= target)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}