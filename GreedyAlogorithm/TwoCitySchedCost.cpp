#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//      LeetCode 1029. 两地调度

//      链接：https://leetcode.cn/problems/two-city-scheduling/

//      公司计划面试 2n 人。给你一个数组 costs ，其中 costs[i] = [aCosti, bCosti] 。
//      第 i 人飞往 a 市的费用为 aCosti ，飞往 b 市的费用为 bCosti 。
//      返回将每个人都飞到 a 、b 中某座城市的最低费用，要求每个城市都有 n 人抵达。
//      示例 1：
//      输入：costs = [[10,20],[30,200],[400,50],[30,20]]
//      输出：110
//      解释：
//          第一个人去 a 市，费用为 10。
//          第二个人去 a 市，费用为 30。
//          第三个人去 b 市，费用为 50。
//          第四个人去 b 市，费用为 20。
//      最低总费用为 10 + 30 + 50 + 20 = 110，每个城市都有一半的人在面试。
//      示例 2：
//      输入：costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
//      输出：1859
//      示例 3：
//      输入：costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
//      输出：3086
//      提示：
//          2 * n == costs.length
//          2 <= costs.length <= 100
//          costs.length 为偶数
//          1 <= aCosti, bCosti <= 1000

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);
int TwoCitySchedCost(vector<vector<int>> &costs);

int main()
{
    int n = generateRandomNum(0, 20);
    vector<vector<int>> costs = generateRandom2DVec(0, 20, n, 2);
    printf("原数组为：\n");
    print2DVecElement(costs);
    int ans = TwoCitySchedCost(costs);
    printf("每个人 都飞到 a, b 中 某座城市 的 最低费用为：%d。\n", ans);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

void print2DVecElement(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
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

// 贪心：
//    按照 priceA - priceB 升序排序；
//    将前 N 个人飞往 A 市，后 N 人飞往 B 市，计算出总费用
// Time: O(NlogN)
// Space: O(N)
int TwoCitySchedCost(vector<vector<int>> &costs)
{
    sort(costs.begin(), costs.end(), [](vector<int> v1, vector<int> v2)
         { return v1[0] - v1[1] < v2[0] - v2[1]; });

    int cost = 0;

    int n = costs.size();
    for(int i = 0; i < n / 2; i++){
        cost += costs[i][0] + costs[i + n / 2][1];
    }
    return cost;
}