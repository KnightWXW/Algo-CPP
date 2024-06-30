#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//      Huawei: 预定往返机票

//      有个工程师出差支持某项目，要求找到最便宜的往返机票价格。
//      给定两个数组：表示去程的连续N天机票价格 go；表示返程的连续N天机票价格 back
//      给定一个 最大支撑天数maxDays 和 最小支撑天数minDays
//      表示这次出差最多支持maxDays, 最少支持minDays,
//      支撑天数 = 返程时间 - 出发时间。
//      示例1：
//          输入：  {10, 9, 1, 3, 5, 7, 3, 8, 6, 8}
//                  {9, 4, 3, 7, 2, 7, 2, 6, 1, 6}
//                  9
//                  3
//          输出:   2
//      示例2：
//          输入：  {10, 9, 1, 3, 5, 7, 3, 8, 6, 8}
//                  {9, 4, 3, 7, 2, 7, 2, 6, 1, 6}
//                  5
//                  3
//          输出:   3

void printVecElement(vector<int> vec);

int BookingFlight(vector<int> go, vector<int> back, int maxDays, int minDays);

int main()
{
    vector<int> go1 = {10, 9, 1, 3, 5, 7, 3, 8, 6, 8};
    vector<int> back1 = {9, 4, 3, 7, 2, 7, 2, 6, 1, 6};
    int maxDays1 = 9;
    int minDays1 = 3;
    int ans_A = BookingFlight(go1, back1, maxDays1, minDays1);
    printVecElement(go1);
    printVecElement(back1);
    printf("出差最多支持%d天, 最少支持%d天时, 最便宜的往返机票价格为 %d\n", maxDays1, minDays1, ans_A);

    vector<int> go2 = {10, 9, 1, 3, 5, 7, 3, 8, 6, 8};
    vector<int> back2 = {9, 4, 3, 7, 2, 7, 2, 6, 1, 6};
    int maxDays2 = 5;
    int minDays2 = 3;
    int ans_B = BookingFlight(go2, back2, maxDays2, minDays2);
    printVecElement(go2);
    printVecElement(back2);
    printf("出差最多支持%d天, 最少支持%d天时, 最便宜的往返机票价格为 %d\n", maxDays2, minDays2, ans_B);
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int BookingFlight(vector<int> go, vector<int> back, int maxDays, int minDays)
{
    
}