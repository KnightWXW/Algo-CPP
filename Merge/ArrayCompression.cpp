#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

//      Huawei: 数组压缩

//      有一种数组压缩机制，将连续的重复数字以[数字，重复次数]的形式记录
//      例如，一维数组[1,1,28,28,28,3]压缩后形成二维数组[[1, 2],[28, 3],[3, 1]]
//      现有两个压缩后的二维数组numsA和numsB, 对其进行解压，加压后的两个新数组若长度不同
//      在较短的数组后补0, 使得两个数组长度相等。
//      然后将两个数组的相同索引的数字相乘，所得结果存入临时数组，
//      最后将临时数组以同样的压缩机制进行压缩后返回。
//      注：解压后的数组长度可能跟大，请以高效的方式实现整个过程
//      示例一：
//          输入：
//          numsA = [[3, 3], [4, 1]]
//          numsA = [[2, 1], [4, 2], [3, 2]]
//          输出：[[6, 1], [12, 3], [0, 1]]
//      示例二：
//          输入：
//          numsA = [[2, 3], [5, 3], [1, 4], [3, 3]]
//          numsA = [[1, 2], [7, 1], [3, 8]]
//          输出：[[2, 2], [14, 1], [15, 3], [3, 4], [9, 1], [0, 2]]
//      示例三：
//          输入：
//          numsA = [[2, 1000000], [3, 1000000]]
//          numsA = [[7, 999999], [8, 2], [6, 999999]]
//          输出：[[14, 999999], [16, 1], [24, 1], [18, 999999]]
//      提醒：numsA或numsB的长度可能很大(如1000)，请使用高效的方式，以减少空间使用和计算量
//      提示：
//          1<= numsA.size(), numsB.size() <= 1000
//          1<= numsA[i][0], numsB[i][0] <= 10^4
//          1<= numsA[i][1], numsB[i][1] <= 10^6

void print2DVecElement(vector<vector<int>> vec);

vector<vector<int>> ArrayCompression(vector<vector<int>> numsA, vector<vector<int>> numsB);

int main()
{
    vector<vector<int>> vecA1 = {{3, 3}, {4, 1}};
    vector<vector<int>> vecA2 = {{2, 1}, {4, 2}, {3, 2}};
    printf("数组A为：\n");
    print2DVecElement(vecA1);
    printf("数组B为：\n");
    print2DVecElement(vecA2);
    vector<vector<int>> ansA = ArrayCompression(vecA1, vecA2);
    printf("数组压缩后为：\n");
    print2DVecElement(ansA);

    vector<vector<int>> vecB1 = {{2, 3}, {5, 3}, {1, 4}, {3, 3}};
    vector<vector<int>> vecB2 = {{1, 2}, {7, 1}, {3, 8}};
    printf("数组A为：\n");
    print2DVecElement(vecB1);
    printf("数组B为：\n");
    print2DVecElement(vecB2);
    vector<vector<int>> ansB = ArrayCompression(vecB1, vecB2);
    printf("数组压缩后为：\n");
    print2DVecElement(ansB);

    vector<vector<int>> vecC1 = {{2, 1000000}, {3, 1000000}};
    vector<vector<int>> vecC2 = {{7, 999999}, {8, 2}, {6, 999999}};
    printf("数组A为：\n");
    print2DVecElement(vecC1);
    printf("数组B为：\n");
    print2DVecElement(vecC2);
    vector<vector<int>> ansC = ArrayCompression(vecC1, vecC2);
    printf("数组压缩后为：\n");
    print2DVecElement(ansC);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void print2DVecElement(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            printf("%d\t", vec[i][j]);
        }
        printf("\n");
    }
}

vector<vector<int>> ArrayCompression(vector<vector<int>> numsA, vector<vector<int>> numsB)
{
    int la = numsA.size();
    int lb = numsB.size();
    deque<vector<int>> dq;
    vector<vector<int>> res;
    deque<vector<int>> dqa;
    deque<vector<int>> dqb;
    for (int i = 0; i < la; i++)
    {
        dqa.push_back(numsA[i]);
    }
    for (int i = 0; i < lb; i++)
    {
        dqb.push_back(numsB[i]);
    }
    // 合并两个数组:
    while (!dqa.empty() && !dqb.empty())
    {
        vector<int> a = dqa.front();
        vector<int> b = dqb.front();
        dqa.pop_front();
        dqb.pop_front();
        if (a[1] < b[1])
        {
            vector<int> c = vector<int>{b[0], b[1] - a[1]};
            vector<int> d = vector<int>{a[0] * b[0], a[1]};
            dqb.push_front(c);
            dq.push_back(d);
        }
        else if (a[1] > b[1])
        {
            vector<int> c = vector<int>{a[0], a[1] - b[1]};
            vector<int> d = vector<int>{a[0] * b[0], b[1]};
            dqa.push_front(c);
            dq.push_back(d);
        }
        else
        {
            vector<int> d = vector<int>{a[0] * b[0], a[1]};
            dq.push_back(d);
        }
    }
    // 处理长数组的 0 :
    while (!dqa.empty())
    {
        vector<int> a = dqa.front();
        dqa.pop_front();
        vector<int> d = vector<int>{0, a[1]};
        dq.push_back(d);
    }
    while (!dqb.empty())
    {
        vector<int> b = dqb.front();
        dqb.pop_front();
        vector<int> d = vector<int>{0, b[1]};
        dq.push_back(d);
    }
    // 进行相同乘积值的合并:
    while (!dq.empty())
    {
        vector<int> tem = dq.front();
        dq.pop_front();
        if (res.empty())
        {
            res.push_back(tem);
        }
        else
        {
            if (tem[0] == res.back()[0])
            {
                res.back()[1] += tem[1];
            }
            else
            {
                res.push_back(tem);
            }
        }
    }
    return res;
}