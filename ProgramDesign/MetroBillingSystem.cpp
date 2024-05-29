#include <vector>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

//      Huawei: 地铁计价系统

//      请设计一个地铁计价系统，每个乘客有一张地铁卡，用于乘坐地铁，可以按距离计价或者按次数计价
//      请实现以下功能：
//      MetroBillingSys(vector<int> cost, int price, int limit):初始化系统，
//          初始化时乘客的地铁卡余额为0。
//          [次票]次数为0；乘坐地铁有两种方式：
//              按距离计价：乘坐i + 1站的票价为cost[i]
//              按次计价：一张[次票]的售价为price，可搭乘 limit 次地铁(不受距离影响)。
//                      每乘坐1次，消耗[次票]中的1次
//      void ReCharge(int id, int amount):
//          乘客id向地铁卡中充值amount的金额。
//      bool PurCharge(int id): 乘客id使用地铁卡余额购买一张[次票]。
//          若余额足够，则购买一张并返回true,否则返回false:
//      bool Commute(int id, int distance):
//          乘客id搭乘地铁乘坐distance站，成功搭乘返回true，失败返回false。
//          搭乘规则如下：
//              若乘客仍有[次票]次数，优先消耗[次票]，次数减一次；
//              若乘客已无[次票]次数：
//                  当地铁卡的余额大于0，则能正常搭乘地铁。
//                  按距离计价扣除费用，即使余额不足以支付票价，仍可以正常出站，
//                  但余额将扣除费用后成为负数，当余额小于等于0时，则无法搭乘地铁
//      vector<int> Query(int id): 查询乘客id的余额和[次数]剩余次数，返回形式为[余额, 剩余次数]
//      示例1：
//          输入：
//          ["MetroBillingSys", "Recharge", "PurCharge", "Commute", "PurCharge",
//          "Query", "Recharge", "Commute", "Query", "Commute", "Recharge",
//          "Commute"]
//          [[[3, 4, 5, 6, 7], 15, 4], [101, 32], [101], [101, 3], [101], [101],
//          [102, 5], [102, 4], [102], [102, 1], [102, 1], [102, 1]]
//          输出：
//          [null, null, true, true, true, [2, 7], null, true, [-1, 0],
//          false, null, false]

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class MetroBillingSystem
{
    MetroBillingSys(vector<int> cost, int price, int limit)
    {
    }

    void ReCharge(int id, int amount)
    {
    }

    bool PurCharge(int id)
    {
    }

    bool Commute(int id, int distance)
    {
    }

    vector<int> Query(int id)
    {
    }
};

int main()
{
    vector<int> cost1 = {3, 4, 5, 6, 7};
    int price1 = 15;
    int limit1 = 4;
    MetroBillingSystem *metroBillingSystem1 = new MetroBillingSystem(cost1, price1, limit1);
    metroBillingSystem1->Recharge({101, 32});
    bool a11 = metroBillingSystem1->PurCharge(101);
    printf("购买车票的结果为：\n");
    printBool(a11);
    bool a12 = metroBillingSystem1->Commute({101, 3});
    printf("搭乘车票的结果为：\n");
    printBool(a12);
    bool a13 = metroBillingSystem1->PurCharge(101);
    printf("搭乘车票的结果为：\n");
    printBool(a13);
    vector<int> a14 = metroBillingSystem1->Query(101);
    printf("查询车票的结果为：\n");
    printVecElement(a14);
    metroBillingSystem1->Recharge({102, 5});
    bool a15 = metroBillingSystem1->Commute({102, 4});
    printf("搭乘车票的结果为：\n");
    printBool(a15);
    vector<int> a16 = metroBillingSystem1->Query(102);
    printf("查询车票的结果为：\n");
    printVecElement(a16);
    bool a17 = metroBillingSystem1->Commute({102, 1});
    printf("搭乘车票的结果为：\n");
    printBool(a17);
    metroBillingSystem1->Recharge({102, 1});
    bool a18 = metroBillingSystem1->Commute({102, 1});
    printf("搭乘车票的结果为：\n");
    printBool(a18);
}