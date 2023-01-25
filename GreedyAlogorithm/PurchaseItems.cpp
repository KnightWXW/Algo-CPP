#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//      某商店正在销售一种原价 price 的办公用品。
//      随着促销季的到来，将优惠售卖一定量的该办公用品，促销信息记录于数组 discount 中，
//      discount[j] = [day, promotionPrice, limit] 表示：
//      在第 day 天，办公用品的促销价为 promotionPrice，但该天最多优惠购买 limit 件。
//      公司正准备以预算 budget 采购该办公用品 num 件，
//      请问最早在第几天可采购齐办公用品（第几天从 1 开始计数）；
//      若预算无法采购齐办公用品，则返回 -1。
//      注意：
//      用例保证 discount 按 day 升序（严格递增，即discount[i][0] < discount[i+1][0]），
//      促销价均小于原价；
//      办公用品可在任意一天以原价购买，即从第 1 天就可购买，并且每天都不限数量售卖。
//      示例 1：
//          输入：
//              num = 3
//              price = 5
//              discount = [[2,4,2],[3,1,4]]
//              budget = 14
//          输出：2
//          解释：办公用品原价 5，需要买 3 件，预算为 14。
//              第 1 天无优惠，如果采用原价购买，需要花费 3*5=15，超出预算，
//                  无法购齐所有办公用品。
//              第 2 天购买办公用品 2 件，由于促销，花费 2*4=8；
//                  以原价购买办公用品 1 件，花费 1*5=5；总花费为 13，小于预算 14，
//                  因此最早第 2 天可购齐所有办公用品。
//              虽然第 3 天的用品价格更优惠，但是不需要等到第 3 天即可购齐所有办公用品。
//      示例 2：
//          输入：
//              num = 4
//              price = 10
//              discount = [[2,5,3],[3,6,2],[4,2,1],[6,1,4],[100,3,1]]
//              budget = 18
//          输出：4
//          解释：
//              尝试第 1 天完成采购：无优惠，采用原价购买，需要花费 4*10=40，
//                  超出预算，无法购齐；
//              尝试第 2 天完成采购：第 2 天以促销价 5 购买办公用品 3 件，花费 5*3=15，
//                  再以原价购买剩余 1 件，花费 1*10=10，共花费 25，超出预算，无法购齐；
//              尝试第 3 天完成采购：先以最优惠的促销价 5 购买办公用品 3 件，
//                  再以次优惠的价格 6 （第 3 天）购买办公用品 1 件，共花费 21，
//                  超出预算，无法购齐；
//              尝试第 4 天完成采购：先以最优惠的促销价 2 购买办公用品 1 件，
//                  再以次优惠的价格 5 （第 2 天）购买办公用品 3 件，共花费 17，
//                  小于预算，因此最早第 4 天可采购齐所有办公用品。
//              同理第 5 天也可购齐，但是不是最早的；
//              ...
//              同理第 100 天也可购齐，但也不是最早的。
//              因此返回 4 。
//      示例 3：
//          输入：
//              num = 2
//              price = 4
//              discount = [[2,3,3]]
//              budget = 10
//          输出：1
//          解释：第 1 天以原价 4 购买办公用品 2 件，花费 2*4=8，
//              小于预算，无需等到第 2 天的优惠，即可购齐所有办公用品，因此返回 1。
//      提示：
//          1 <= price <= 10^5
//          1 <= num <= 10^4
//          0 <= discount.length <= 2*10^4
//          1 <= discount[i][0] <= 10^5
//          1 <= discount[i][1] <= 10^5
//          1 <= discount[i][2] <= 10
//          1 <= budget <= 10^9

void print2DVecElement(vector<vector<int>> vec);

int PurchaseItems_A(int num, int price, vector<vector<int>> &discount, int budget);

int main()
{
    int num1 = 2;
    int price1 = 4;
    int budget1 = 10;
    vector<vector<int>> discount1 = {{2, 3, 3}};
    int ans1 = PurchaseItems_A(num1, price1, discount1, budget1);
    printf("以预算 %d 采购原价 为 %d 的办公用品 %d 件,\n促销信息为: \n", budget1, price1, num1);
    print2DVecElement(discount1);
    printf("最早在第 %d 天可采购齐办公用品。", ans1);

    int num2 = 3;
    int price2 = 5;
    int budget2 = 14;
    vector<vector<int>> discount2 = {{2, 4, 2},
                                     {3, 1, 4}};
    int ans2 = PurchaseItems_A(num2, price2, discount2, budget2);
    printf("以预算 %d 采购原价 为 %d 的办公用品 %d 件,\n促销信息为: \n", budget2, price2, num2);
    print2DVecElement(discount2);
    printf("最早在第 %d 天可采购齐办公用品。", ans2);

    int num3 = 4;
    int price3 = 10;
    int budget3 = 18;
    vector<vector<int>> discount3 = {{2, 5, 3},
                                     {3, 6, 2},
                                     {4, 2, 1},
                                     {6, 1, 4},
                                     {8, 3, 1}};
    int ans3 = PurchaseItems_A(num3, price3, discount3, budget3);
    printf("以预算 %d 采购原价 为 %d 的办公用品 %d 件,\n促销信息为: \n", budget3, price3, num3);
    print2DVecElement(discount3);
    printf("最早在第 %d 天可采购齐办公用品。", ans3);
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

struct cmp
{
    bool operator()(int &p1, int &p2)
    {
        return p1 < p2;
    }
};

int PurchaseItems_A(int num, int price, vector<vector<int>> &discount, int budget)
{
    int l = discount.size();
    if (num * price <= budget)
    {
        return 1;
    }
    priority_queue<int, vector<int>, cmp> pq;
    priority_queue<int, vector<int>, cmp> pqTem; // 临时栈 记录 之前的栈结构
    for (int i = 0; i < num; i++)
    {
        pq.push(price);
    }

    for (int i = 0; i < l; i++)
    {
        int day = discount[i][0];
        int disPrice = discount[i][1];
        int limit = discount[i][2];
        if (disPrice > pq.top())
        {
            continue;
        }
        for (int j = 0; j < limit; j++)
        {
            if (disPrice < pq.top())
            {
                pq.pop();
                pq.push(disPrice);
            }
        }

        int cnt = 0;
        pqTem = pq;
        while (!pq.empty())
        {
            cnt += pq.top();
            pq.pop();
        }

        if (cnt <= budget)
        {
            return day;
        }
        else
        {
            pq = pqTem;
        }
    }
    return -1;
}