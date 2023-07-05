#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

//      Huawei: 仓库管理系统

//      请设计一个仓库管理系统，实现以下功能：
//          StoreSystem(int coldStorageNum, int coldStoragePrice,
//                      int normalStorageNum, int normalStoragePrice, int delay):
//                  初始化仓库信息：仓库有冷藏和常温两种类型的储藏室，
//                      初始化其对应的数量的每天租赁价格
//                      若用户租赁日期超出delay天后，依旧未提取货物，该储物区将被清空
//          int Store(int date, int storeId, int storeType, int storeDays):
//                  在日期date为存单storeId租赁storeType类型的一个储藏室，
//                  并存放物品storeDays天。
//                  若有空间则存储成功，则须支付storeDays的费用
//                      (按照实际储藏室的类型进行计算：(天数*每日租赁价格)，返回该费用
//                  若无空间则不做任何处理，并返回-1
//                  系统保证storeId参数全局唯一
//                  storeType 为 0 表示冷藏, 1 表示 常温
//          int Retrieve(int date, int storeId):
//                  在日期date, 客户取出存单 storeId (存单一定存在且未被提取)对应的物品：
//                  若存单过期时，则取出物品，并返回0
//                  若存单过期但未超出delay天，则取出物品，
//                      并返回需要补交的费用(实际延迟天数*每日价格)，
//                      实际延迟天数 = date - (租赁起始日期 + storeDays)
//                  若存单过期但已超出delay天(日期超过 租赁起始日期 + storeDays + delay)时，
//                  则物品已被清空，则取出失败，返回-1
//          vector<int> Query(int date): 请返回截止日期date时3种状态的存单数量序列，
//                  依次为：物品已成功取出，物品未取仍在仓库中，物品被清空的存单数量
//                  注意：保证函数Store, Retrieve, Query的Date参数按输入顺序非严格递增
//      示例1：
//          输入:
//              [“StoreSystem”, "Query", “Store”, “Store”, “Store”, "Query", “Store”,
//              “Retrieve”, “Store”, "Query", "Query", “Retrieve”]
//              [[2, 2, 1, 3, 2], [0], [0, 21, 1, 3], [1, 22, 1, 4], [1, 23, 0, 2], [1],
//              [4, 26, 1, 2], [5, 21], [6, 24, 0, 7], [7], [8], [9, 22]]
//          输出：
//              [null, [0, 0, 0],9, 8, 4,[0, 3, 0], -1, 6, 14, [1, 2, 1], [1, 1, 2], -1]

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class StoreSystem
{
    StoreSystem(int coldStorageNum, int coldStoragePrice,
                int normalStorageNum, int normalStoragePrice, int delay)
    {
    }
    int Store(int date, int storeId, int storeType, int storeDays)
    {
    }
    int Retrieve(int date, int storeId)
    {
    }
    vector<int> Query(int date)
    {
    }
};

int main()
{
    StoreSystem *storeSystem = new StoreSystem(2, 2, 1, 3, 2);
    vector<int> q1 = storeSystem->Query(0);
    printf("该存单数量序列 为 :\n");
    printVec(q1);
    int s1 = storeSystem->Store(0, 21, 1, 3);
    printf("存储费用为: %d\n", s1);
    int s2 = storeSystem->Store(1, 22, 1, 4);
    printf("存储费用为: %d\n", s2);
    int s3 = storeSystem->Store(1, 23, 0, 2);
    printf("存储费用为: %d\n", s3);
    vector<int> q2 = storeSystem->Query(1);
    printf("该存单数量序列 为 :\n");
    printVec(q2);
    int s4 = storeSystem->Store(4, 26, 1, 2);
    printf("存储费用为: %d\n", s4);
    int r1 = storeSystem->Retrieve(5, 21);
    printf("取出物品结果为: %d\n", r1);
    int s5 = storeSystem->Store(6, 24, 0, 7);
    printf("存储费用为: %d\n", s5);
    vector<int> q3 = storeSystem->Query(7);
    printf("该存单数量序列 为 :\n");
    printVec(q3);
    vector<int> q4 = storeSystem->Query(8);
    printf("该存单数量序列 为 :\n");
    printVec(q4);
    int r2 = storeSystem->Retrieve(9, 22);
    printf("取出物品结果为: %d\n", r2);
}
