#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);
void selectSort_A(vector<int> &vec);

int main()
{
    vector<int> vec_A = generateRandomVec(-100, 100, 10);
    // vector<int> vec_B ;
    // vec_B.assign(vec_A.begin(), vec_A.end());

    printf("数组未排序 前为：\n");
    printVecElement(vec_A);
    // printVecElement(vec_B);

    selectSort_A(vec_A);

    printf("选择排序 后为：\n");
    printVecElement(vec_A);
    // printVecElement(vec_B);
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

// 选择排序：
// Time: O(n ^ 2)
// Space: O(1)
void selectSort_A(vector<int> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[index])
            {
                index = j;
            }
        }
        swap(vec[index], vec[i]);
    }
}

// Time: O(n ^ 2)
// Space: O(1)
// 添加 flag 标志位:
//   flag == true:   数组 已经 有序：
//   flag == false:  数组 仍然 无序：
// void bubbleSort_B(vector<int> &vec)
// {
//     for (int i = vec.size() - 1; i >= 0; i--)
//     {
//         bool flag = true;
//         for (int j = 0; j < i; j++)
//         {
//             if (vec[j] > vec[j + 1])
//             {
//                 swap(vec[j], vec[j + 1]);
//                 flag = false;
//             }
//         }
//         if (flag == true)
//         {
//             break;
//         }
//     }
// }