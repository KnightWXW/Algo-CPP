#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 2303. 计算应缴税款总额

//      链接：https://leetcode.cn/problems/calculate-amount-paid-in-taxes/

//      给你一个下标从 0 开始的二维整数数组 brackets ，
//      其中 brackets[i] = [upperi, percenti] ，
//      表示第 i 个税级的上限是 upperi ，征收的税率为 percenti 。
//      税级按上限 从低到高排序（在满足 0 < i < brackets.length 的前提下，upperi-1 < upperi）。
//      税款计算方式如下：
//          不超过 upper0 的收入按税率 percent0 缴纳
//          接着 upper1 - upper0 的部分按税率 percent1 缴纳
//          然后 upper2 - upper1 的部分按税率 percent2 缴纳
//          以此类推
//      给你一个整数 income 表示你的总收入。
//      返回你需要缴纳的税款总额。与标准答案误差不超 10-5 的结果将被视作正确答案。
//      示例 1：
//          输入：brackets = [[3,50],[7,10],[12,25]], income = 10
//          输出：2.65000
//          解释：
//              前 $3 的税率为 50% 。需要支付税款 $3 * 50% = $1.50 。
//              接下来 $7 - $3 = $4 的税率为 10% 。需要支付税款 $4 * 10% = $0.40 。
//              最后 $10 - $7 = $3 的税率为 25% 。需要支付税款 $3 * 25% = $0.75 。
//              需要支付的税款总计 $1.50 + $0.40 + $0.75 = $2.65 。
//      示例 2：
//          输入：brackets = [[1,0],[4,25],[5,50]], income = 2
//          输出：0.25000
//          解释：
//              前 $1 的税率为 0% 。需要支付税款 $1 * 0% = $0 。
//              剩下 $1 的税率为 25% 。需要支付税款 $1 * 25% = $0.25 。
//              需要支付的税款总计 $0 + $0.25 = $0.25 。
//      示例 3：
//          输入：brackets = [[2,50]], income = 0
//          输出：0.00000
//          解释：
//              没有收入，无需纳税，需要支付的税款总计 $0 。
//      提示：
//          1 <= brackets.length <= 100
//          1 <= upperi <= 1000
//          0 <= percenti <= 100
//          0 <= income <= 1000
//          upperi 按递增顺序排列
//          upperi 中的所有值 互不相同
//          最后一个税级的上限大于等于 income

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

double CalculateTax(vector<vector<int>>& brackets, int income);

int main()
{
    int n = generateRandomNum(0, 20);
    vector<vector<int>> brackets = generateRandom2DVec(0, 20, n, 2);
    print2DVecElement(brackets);
    double ans = CalculateTax(brackets);
    printf("需要缴纳的税款总额为：%lf。\n", ans);
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

double CalculateTax(vector<vector<int>>& brackets, int income)
{
    int l = brackets.size();

}