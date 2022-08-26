#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);
void insertSort_A(vector<int> &vec);

int main()
{
    vector<int> vec_A = generateRandomVec(-100, 100, 10);

    printf("数组未排序 前为：\n");
    printVecElement(vec_A);

    insertSort_A(vec_A);

    printf("插入排序 后为：\n");
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

// 插入排序：
// Time: O(n ^ 2)
// Space: O(1)
void insertSort_A(vector<int> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (vec[j + 1] < vec[j])
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}