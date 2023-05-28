#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      安排加工零件的工人

//      某工厂有n个零件加工的师傅，每位师傅每天能够加工出不同数量的零件
//      现有m个零件要求一天加工完，请问该工厂最少需要派几个师傅来完成这次零件加工任务，
//      如果安排所有的师傅都参与加工也不能在一天内完成任务，请输出-1。
//      输入
//          第一行有两个整数，用空格隔开;
//              第一个整数代表要加工的总零件个数，
//              第二个整数代表工厂的零件加工师傅的数量
//          第二行有n个整数，分别代表每个师傅每天能够加工出来的零件数量
//              (每个师傅每天加工的零件数量ns10A4)。
//      输出
//          输出工厂在1天时间内加工所有零件需要的师傅数量，或者输出-1
//      输入
//          10 5
//          1 3 2 4 2
//      输出
//          4

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int ArrangeWorkersToProcessParts(vector<int> vec, int num);

int main()
{
    int n = generateRandomNum(1, 50);
    vector<int> vec = generateRandomVec(1, 300, n);
    sort(vec.begin(), vec.end());
    int dist = generateRandomNum(1, n / 2 + 1);
    printVec(vec);
    int ans = AddRungs(vec, dist);
    printf("每次移动中，你可以到达下一个距离你当前位置（地板或台阶）不超过 %d 高度的台阶。\n爬到最后一阶时必须添加到梯子上的 最少 台阶数 %d。", dist, ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

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

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}