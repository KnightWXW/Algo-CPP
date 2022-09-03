#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//      给定一个整数数组，给定一个值K，这个值在原数组中一定存在，
//      要求把数组中小于K的元素放到数组的左边，
//      大于K的元素放到数组的右边，
//      等于K的元素放到数组的中间，
//      最终返回一个整数数组，其中只有两个值，分别是等于K的数组部分的 左右两个下标值.

vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);
vector<int> netherLandFlag_A(vector<int> &vec, int left, int right, int target);

int main()
{
    vector<int> vec_A = generateRandomVec(0, 10, 20);

    printf("数组为：\n");
    printVecElement(vec_A);
    int target = vec_A[(vec_A.size()) >> 1];
    vector<int> ans = netherLandFlag_A(vec_A, 0, vec_A.size() - 1, target);
    printf("荷兰国旗问题 原数组 处理后为：\n");
    printVecElement(vec_A);
    printf("与 %d 相等的 索引范围 为 ：\n", target);
    printVecElement(ans);
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

// Time: O(n)
// Space: O(1)
vector<int> netherLandFlag_A(vector<int> &vec, int left, int right, int target)
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
    int highRange = right + 1;
    int index = left;

    while (index < highRange)
    {
        if (vec[index] < target)
        {
            swap(vec[index], vec[lowRange + 1]);
            lowRange++;
            index++;
        }
        else if (vec[index] > target)
        {
            swap(vec[index], vec[highRange - 1]);
            highRange--;
        }
        else
        {
            index++;
        }
    }

    return vector<int>{lowRange + 1, highRange - 1};
}