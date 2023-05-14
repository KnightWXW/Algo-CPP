#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      剑指 Offer 51. 数组中的逆序对

//      链接：https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/

//      在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//      输入一个数组，求出这个数组中的逆序对的总数。
//      示例 1:
//          输入: [7,5,6,4]
//          输出: 5
//      限制：
//          0 <= 数组长度 <= 50000

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int reversePairs_A(vector<int> &vec);
int process_A(vector<int> &vec, int left, int right);
int merge_A(vector<int> &vec, int left, int mid, int right);

int reversePairs_B(vector<int> &vec);
int process_B(vector<int> &vec, int left, int right);
int merge_B(vector<int> &vec, int left, int mid, int right);

int reversePairs_C(vector<int> &vec);
int process_C(vector<int> &vec, int left, int right);
int merge_C(vector<int> &vec, int left, int mid, int right);

int main()
{
    int n = generateRandomNum(0, 50);
    vector<int> vec_A = generateRandomVec(0, 10, n);
    vector<int> vec_B;
    vec_B.assign(vec_A.begin(), vec_A.end());
    vector<int> vec_C;
    vec_C.assign(vec_A.begin(), vec_A.end());
    printVecElement(vec_A);
    printf("<一>数组中 的 逆序对数量 为 %d\n", reversePairs_A(vec_A));
    printf("<二>数组中 的 逆序对数量 为 %d\n", reversePairs_B(vec_B));
    printf("<三>数组中 的 逆序对数量 为 %d\n", reversePairs_C(vec_C));
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

// 归并排序<一>：
// 先计算 逆序对 数目：
// Time: O(NlogN)
// Space: O(logN)
int reversePairs_A(vector<int> &vec)
{
    return process_A(vec, 0, vec.size() - 1);
}

int process_A(vector<int> &vec, int left, int right)
{
    if (left >= right)
    {
        return 0;
    }
    int mid = left + ((right - left) >> 1);
    return process_A(vec, left, mid) + process_A(vec, mid + 1, right) + merge_A(vec, left, mid, right);
}

int merge_A(vector<int> &vec, int left, int mid, int right)
{
    int ans = 0;
    int rightRange = mid + 1;
    for (int i = left; i <= mid; i++)
    {
        while (rightRange <= right && vec[i] > vec[rightRange])
        {
            rightRange++;
        }
        ans += (rightRange - mid - 1);
    }

    int p1 = left;
    int p2 = mid + 1;
    int index = 0;
    int n = right - left + 1;
    vector<int> help(n, 0);

    while (p1 <= mid && p2 <= right)
    {
        if (vec[p1] <= vec[p2])
        {
            help[index++] = vec[p1++];
        }
        else
        {
            help[index++] = vec[p2++];
        }
    }

    while (p1 <= mid)
    {
        help[index++] = vec[p1++];
    }

    while (p2 <= right)
    {
        help[index++] = vec[p2++];
    }

    for (int i = 0; i < n; i++)
    {
        vec[left + i] = help[i];
    }
    return ans;
}

// 归并排序<二>：
// 自右向左，计算 右半部分
// Time: O(NlogN)
// Space: O(logN)
int reversePairs_B(vector<int> &vec)
{
    return process_B(vec, 0, vec.size() - 1);
}

int process_B(vector<int> &vec, int left, int right)
{
    if (left >= right)
    {
        return 0;
    }
    int mid = left + ((right - left) >> 1);
    return process_B(vec, left, mid) + process_B(vec, mid + 1, right) + merge_B(vec, left, mid, right);
}

int merge_B(vector<int> &vec, int left, int mid, int right)
{
    int ans = 0;

    int p1 = mid;
    int p2 = right;
    int n = right - left + 1;
    int index = n - 1;
    vector<int> help(n, 0);

    while (p1 >= left && p2 >= mid + 1)
    {
        if (vec[p1] <= vec[p2])
        {
            help[index--] = vec[p2--];
        }
        else
        {
            help[index] = vec[p1]; 
            ans += (p2 - mid);
            index--;
            p1--;
        }
    }

    while (p1 >= left)
    {
        help[index--] = vec[p1--];
    }

    while (p2 >= mid + 1)
    {
        help[index--] = vec[p2--];
    }

    for (int i = 0; i < n; i++)
    {
        vec[left + i] = help[i];
    }
    return ans;
}

// 归并排序<三>：
// 自左向右，计算 左半部分
// Time: O(NlogN)
// Space: O(logN)
int reversePairs_C(vector<int> &vec)
{
    return process_C(vec, 0, vec.size() - 1);
}

int process_C(vector<int> &vec, int left, int right)
{
    if (left >= right)
    {
        return 0;
    }
    int mid = left + ((right - left) >> 1);
    return process_C(vec, left, mid) + process_C(vec, mid + 1, right) + merge_C(vec, left, mid, right);
}

int merge_C(vector<int> &vec, int left, int mid, int right)
{
    int ans = 0;

    int p1 = left;
    int p2 = mid + 1;
    int index = 0;
    int n = right - left + 1;
    vector<int> help(n, 0);

    while (p1 <= mid && p2 <= right)
    {
        if (vec[p1] <= vec[p2])
        {
            help[index++] = vec[p1++];
        }
        else
        {
            help[index] = vec[p2];
            ans += mid - p1 + 1;
            index++;
            p2++;
        }
    }

    while (p1 <= mid)
    {
        help[index++] = vec[p1++];
    }

    while (p2 <= right)
    {
        help[index++] = vec[p2++];
    }

    for (int i = 0; i < n; i++)
    {
        vec[left + i] = help[i];
    }
    return ans;
}