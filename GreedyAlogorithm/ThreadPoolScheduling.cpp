#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      Huawei: 线程池调度

//      某设备有一个线程池调度特性，现在给一个任务安排的时间数组，
//      每个任务时间都会包括开始和结束的时间[[s1, e1], [s2, e2] ......]
//      为避免线程冲突，并充分利用资源，请给调度特性计算至少需要线程池中多少个线程？
//      示例一：
//          输入: {{0, 30}, {5, 10}, {15, 20}}
//          输出: 2
//      示例二：
//          输入: {{7, 10}, {2, 4}}
//          输出: 1
//      示例三：
//          输入: {{7, 10}, {2, 7}}
//          输出: 1

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

int ThreadPoolScheduling(vector<vector<int>> arr);

int main()
{
    int row = generateRandomNum(1, 50);
    vector<vector<int>> vec = generateRandom2DVec(1, 10, row, 2);
    printf("二维数组元素为：\n");
    print2DVecElement(vec);
    int ans_A = ThreadPoolScheduling(vec);
    printf(" 至少需要线程池中 %d 个线程有。\n", ans_A);
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
    printf("\n");
}

vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col)
{
    srand((int)time(0));
    vector<vector<int>> vec;
    for (int i = 0; i < row; i++)
    {
        vector<int> tem;
        for (int j = 0; j < col; j++)
        {
            int v = (rand() % (high - low + 1)) + low;
            tem.push_back(v);
        }
        vec.push_back(tem);
    }
    return vec;
}

int ThreadPoolScheduling(vector<vector<int>> arr)
{
    int l = arr.size();
}