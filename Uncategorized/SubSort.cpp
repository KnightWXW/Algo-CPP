#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 面试题 16.16. 部分排序

//      链接：https://leetcode.cn/problems/sub-sort-lcci/

//      给定一个整数数组，编写一个函数，找出索引m和n，
//      只要将索引区间[m,n]的元素排好序，整个数组就是有序的。
//      注意：n-m尽量最小，也就是说，找出符合条件的最短序列。
//      函数返回值为[m,n]，若不存在这样的m和n（例如整个数组是有序的），请返回[-1,-1]。
//      示例：
//          输入： [1,2,4,7,10,11,7,12,6,7,16,18,19]
//          输出： [3,9]
//      提示：
//          0 <= len(array) <= 1000000

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

vector<int> SubSort_A(vector<int> &array);
vector<int> SubSort_B(vector<int> &array);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> vec = generateRandomVec(1, 100, n);
    printVecElement(vec);
    vector<int> ans_A = SubSort_A(vec);
    vector<int> ans_B = SubSort_B(vec);
    printf("符合条件的最短索引区间为: \n");
    printVecElement(ans_A);
    printVecElement(ans_B);
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

//  如果左侧最大值大于中间的最小值，则一定会被中间序列包括；
//  同理，如果右侧最小值大于中间的最大值，则一定会被中间序列包括。
vector<int> SubSort_A(vector<int> &array)
{
    int l = array.size();
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    int leftIndex = -1;
    int rightIndex = -1;
    //  从前向后扫描数组，判断当前array[i]是否比maxVal小，
    //  是则将rightIndex置为当前array下标i，否则更新maxVal
    for (int i = 0; i < l; i++)
    {
        if (array[i] < maxVal)
        {
            rightIndex = i;
        }
        else
        {
            maxVal = array[i];
        }
    }
    //  从后向前扫描数组，判断当前array[i]是否比minVal大，
    //  是则将leftIndex置位当前下标i，否则更新minVal;
    for (int i = l - 1; i >= 0; i--)
    {
        if (array[i] > minVal)
        {
            leftIndex = i;
        }
        else
        {
            minVal = array[i];
        }
    }
    return {leftIndex, rightIndex};
}

vector<int> SubSort_B(vector<int> &array)
{
    int l = array.size();
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    int leftIndex = -1;
    int rightIndex = -1;
    for (int i = 0; i < l; i++)
    {
        if (array[i] < maxVal)
        {
            rightIndex = i;
        }
        else
        {
            maxVal = array[i];
        }

        if (array[l - i - 1] > minVal)
        {
            leftIndex = l - i - 1;
        }
        else
        {
            minVal = array[l - i - 1];
        }
    }
    return {leftIndex, rightIndex};
}