#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>

using namespace std;

//      Huawei: 工厂流水线系统

//      有一个工厂具有多条流水线，流水线上均可生产多种产品，
//      产品生产有一定的周期，完成 ProductionLineMgmtSyn 类:
//          ProductionLineMgmtSyn(int num, vector<int> periods): 初始化函数，
//              入参是流水条数num, 以及各编号产品的生产周期，在一个数组中 periods 中。
//          int Production(int date, int assemblyId, int productId): 生产函数，
//              入参是开始生产时间date, 流水线编号assemblyId, 以及产品编号productId，规则是:
//                  (1) 若该流水线未被占用，则从此开始生产时间生产该编号的产品，并返回1；
//                  (2) 若该流水线正在被占用，且恰好是同一产品。
//                      则该流水线继续生产该产品，并返回0；
//                  (3) 若该流水线正在被占用，并且是另外一种产品。
//                      则直接在此开始生产时间开始生产新的产品，并返回-1；
//                  (4) 切换规则，比如上个产品在时刻2开始生产，其生产周期为3，
//                      则在时刻8切换生产新的产品时，上个产品已经生产了2个；
//                      而在时刻10切换生产新的产品时，由于最后一个还没有生产完全，
//                      丢弃最后一个，仍然只算成功生产2个；
//          int GetProductCount(int date, int productId): 统计函数
//              入参是 时间date, 以及产品编号productId，
//              统计的是时间date时，工厂生产编号productId的产品的总数量，返回这个值
//              保证 date 是递增的
//      示例：
//          输入：
//              ["ProductionLineMgmtSyn", "Production", "Production",
//              "Production", "GetProductCount"]
//              [[2, [1, 3, 5]], [1, 0, 1], [1, 1, 0], [9, 0, 2], [10, 1]]
//          输出：
//              [null, 1, 1, -1, 2]

class ProductionLineMgmtSyn
{
public:
    int lineNum;
    vector<int> periodArr;
    vector<int> productArr;
    map<int, pair<int, int>> lineMap; // map<流水线编号, pair<开始时间, 该流水线正在生产产品编号>>

    ProductionLineMgmtSyn(int num, vector<int> periods)
    {
        lineNum = num;
        periodArr = vector<int>(periods.begin(), periods.end());
        productArr = vector<int>(lineNum, 0);
    }

    int Production(int date, int assemblyId, int productId)
    {
        // 若该流水线未被占用，则从此开始生产时间生产该编号的产品，并返回1；
        if (lineMap.find(assemblyId) == lineMap.end())
        {
            lineMap[assemblyId] = make_pair(date, productId);
            return 1;
        }
        // 若该流水线正在被占用，且恰好是同一产品。则该流水线继续生产该产品，并返回0；
        if (lineMap[assemblyId].second == productId)
        {
            return 0;
        }
        // 若该流水线正在被占用，并且是另外一种产品。
        // 则直接在此开始生产时间开始生产新的产品，并返回-1；
        int time = date - lineMap[assemblyId].first;
        int lastProductId = lineMap[assemblyId].second;
        int lastProductCnt = time / periodArr[lastProductId];
        productArr[lastProductId] += lastProductCnt;
        lineMap[assemblyId].first = date;
        lineMap[assemblyId].second = productId;
        return -1;
    }

    int GetProductCount(int date, int productId)
    {
        int ans = 0;
        for (auto it = lineMap.begin(); it != lineMap.end(); it++)
        {
            if (it->second.second == productId)
            {
                int time = date - it->second.first;
                ans += time / periodArr[productId];
            }
        }
        ans += productArr[productId];
        return ans;
    }
};

int main()
{
    ProductionLineMgmtSyn *productionLineMgmtSyn = new ProductionLineMgmtSyn(2, {1, 3, 5});
    int p1 = productionLineMgmtSyn->Production(1, 0, 1);
    printf("工厂生产结果 为 %d:\n", p1);
    int p2 = productionLineMgmtSyn->Production(1, 1, 0);
    printf("工厂生产结果 为 %d:\n", p2);
    int p3 = productionLineMgmtSyn->Production(9, 0, 2);
    printf("工厂生产结果 为 %d:\n", p3);
    int g2 = productionLineMgmtSyn->GetProductCount(10, 1);
    printf("工厂统计结果 为 %d:\n", g2);
}
