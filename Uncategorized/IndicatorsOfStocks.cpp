#include <stdio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

//      神策: 股票的指标

//      给定一个数组 arr, 表示连续 n 天的股价, 数组下标表示第几天 指标 X:
//          任意两天的股价之和 – 此两天间隔的天数
//      比如
//          第3天，价格是10第9天，价格是30
//          那么 第3天 和 第9天 的 指标X= 10 + 30 - (9 - 3) = 34 
//      返回 arr中 最大的指标 X

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int IndicatorsOfStocks(vector<int> arr);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(1, 100, n);
    printVecElement(vec);
    int ans_A = IsMagicSequence(vec);
    printf("arr 中 最大的指标为 %d。\n", ans_A);
    printBool(ans_A);
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

int IndicatorsOfStocks(vector<int> arr)
{
    int l = arr.size();

}