#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      实现一个产品生产与原材料库存管理系统，以满足以下功能：
//          InventorySystem(int materialsNum, vector<vector<int>> products):
//              初始化系统，其中materialsNum是物料的种类数量,
//              物料的编号是 0 ~ materialsNum - 1
//              vector<vector<int>> products二维数组表示
//              生产产品i的所需要的j编号的物料的数量，
//              如果数量为0，表示不需要物料j
//          void purchase(vector<vector<int>> materials): 购买物料并完成数量的更新，
//              其中vector<vector<int>> materials二维数组表示物料的数量，
//              以[物料编号，物料数量]格式输出
//          bool Produce(vector<int> productIds): 生产一套产品并消耗物料库存，
//              其中vector<int> productIds是若干个产品编号组成的数组，
//              并且产品编号可重复，表示生产多个同一种产品
//              注意：现有的库存足够生产这些商品，成功消耗库存，返回true
//              若现有的库存不足以生产这一套产品，返回false，并恢复物料库存至本次生产之前
//          int QueryMin(): 返回库存量最小的物料编号

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

class InventorySystem
{
public:
    InventorySystem(int materialsNum, vector<vector<int>> products)
    {
    }

    void Purchase(vector<vector<int>> products)
    {
    }

    bool Produce(vector<int> productIds)
    {
    }
    int QueryMin()
    {
    }
};

int main()
{
    int materialNum = 3;
    vector<vector<int>> products = {{0, 2, 0}, {2, 1, 1}, {0, 1, 1}};
    InventorySystem *inventorySystem = new InventorySystem(materialNum, products);
    inventorySystem->Purchase({{1, 5}, {2, 4}});
    inventorySystem->Purchase({{0, 9}, {1, 3}});
    bool p1 = inventorySystem->Produce({0, 1});
    printf("生产结果为：\n");
    printBool(p1); // true
    int q1 = inventorySystem->QueryMin();
    printf("查询最小值结果为：%d\n", q1); // 2
    bool p2 = inventorySystem->Produce({1, 1, 2});
    printf("生产结果为：\n");
    printBool(p2); // true
    inventorySystem->Purchase({{2, 2}});
    int q2 = inventorySystem->QueryMin();
    printf("查询最小值结果为：%d\n", q2); //  1
}
