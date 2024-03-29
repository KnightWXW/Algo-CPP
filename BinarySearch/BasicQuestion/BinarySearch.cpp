#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// 在有序(升序)数组中查找 等于目标值 target 的元素 所在的索引位置。
// 如果存在，返回索引；不存在返回 -1。

int binarySearch(vector<int> &vec, int target);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int main()
{
    vector<int> vec = generateRandomVec(0, 100, 10);
    printVec(vec);
    int target = vec[0];
    sort(vec.begin(), vec.end());
    printVec(vec);
    printf("target在vector中的索引位置为 %d\n", binarySearch(vec, target));
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
int binarySearch(vector<int> &vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (vec[mid] < target)
        {
            left = mid + 1;
        }
        else if (vec[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}