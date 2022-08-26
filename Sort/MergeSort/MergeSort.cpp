#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);
void mergeSort_A(vector<int> &vec, int left, int right);
void merge(vector<int> &vec, int left, int mid, int right);
//void mergeSort_B(vector<int> &vec);

int main()
{
    vector<int> vec_A = generateRandomVec(-100, 100, 10);
    vector<int> vec_B;
    vec_B.assign(vec_A.begin(), vec_A.end());

    printf("数组未排序 前为：\n");
    printVecElement(vec_A);
    printVecElement(vec_B);

    mergeSort_A(vec_A, 0, vec_A.size() - 1);
    //mergeSort_B(vec_B);

    printf("归并排序 后为：\n");
    printVecElement(vec_A);
    printVecElement(vec_B);
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

// 归并排序：
// 递归 实现：
// Time: O(N*logN)
// Space: O(N)
void mergeSort_A(vector<int> &vec, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + ((right - left) >> 1);
    mergeSort_A(vec, left, mid);
    mergeSort_A(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

void merge(vector<int> &vec, int left, int mid, int right)
{
    int curA = left, curB = mid + 1;
    int index = 0;
    vector<int> tem (right - left + 1, 0);
    while (curA <= mid && curB <= right)
    {
        if (vec[curA] < vec[curB])
        {
            tem[index] = vec[curA];
            curA++;
        }
        else
        {
            tem[index] = vec[curB];
            curB++;
        }
        index++;
    }

    while (curA <= mid)
    {
        tem[index] = vec[curA];
        curA++;
        index++;
    }

    while (curB <= right)
    {
        tem[index] = vec[curB];
        curB++;
        index++;
    }

    for (int i = 0; i < tem.size(); i++)
    {
        vec[left + i] = tem[i];
    }
}

// 归并排序：
// 非递归 实现：
// Time: O(N*logN)
// Space: O(N)
// void mergeSort_B(vector<int> &vec)
// {
    
// }