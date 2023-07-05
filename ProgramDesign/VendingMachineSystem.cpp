#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

//      Huawei: 自动售货机系统

//      请设计一款自动售货机的进出货管理系统VendingMachineSystem(),
//      需实现以下功能：
//          VendingMachineSystem(int trayNum, int trayCapacity):
//              设置该自动售货机上共有trayNum个商品轨道，
//              每个商品轨道上最多可放置trayCapacity个商品：
//              每个轨道上只能放置同一品牌的商品；同一品牌的商品只能放置在一个轨道上
//              对于已售空的轨道可以加入某一品牌的商品，即不一定是原品牌
//          bool AddProductIdList(int brandId, vector<int> productIdList):
//              向系统中添加商品，品牌为brandId,商品编号为 productIdList，
//              从所在的轨道的末端商品之后按数组productIdList下标依次放入。
//              若售货机内已有该品牌的商品：若所在轨道剩余空间充足，则放入商品并返回true;
//              否则不做任何操作并返回false:
//              若售货机内没有该品牌的商品：若所在轨道有空轨道，且该轨道空间充足，
//              则放入商品并返回true，否则不做任何操作并返回false。
//          vector<int> BuyProduct(int brandId, int num): 购买品牌为 brandId 的num个商品：
//              若有足够商品，则取该轨道上前num个商品并返回其商品编号列表：
//              若没有足够商品，或该商品数量不足num个，则不做任何操作并返回空数组[]
//          vector<int> QueryProduct(): 按照品牌编号升序返回每个品牌的首个商品编号(忽略空轨道)
//              若售货机为空，则返回空数组[]
//      示例：
//          输入：
//              ["VendingMachineSystem", "AddProductIdList", "AddProductIdList", 
//              "AddProductIdList","AddProductIdList", 
//              "BuyProduct", "BuyProduct", "BuyProduct",
//              "QueryProduct", "AddProductIdList", "AddProductIdList",
//              "BuyProduct","AddProductIdList"]    
//              [[2, 5], [3, [3, 5, 4, 6, 2, 1]], [3, [3, 5, 4, 6, 2]],
//              [1, [9]], [2, [7]], [3, 3], [9, 3], [3, 3], [],
//              [3, [10, 20, 13, 14]], [3, [10, 20, 13]], [3, 5],
//              [9, [5, 4]]]
//          输出：
//              [null, false, true, true, false, [3, 5, 4], [], [], [9, 6],
//              false, true, [6, 2, 10, 20, 13], true]

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

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class VendingMachineSystem
{
public:
    int number;
    int capacity;
    map<int, vector<int>> hMap;
    VendingMachineSystem(int trayNum, int trayCapacity)
    {
        this->number = trayNum;
        this->capacity = trayCapacity;
    }
    bool AddProductIdList(int brandId, vector<int> productIdList)
    {
        bool flag = false;
        if ((hMap.count(brandId) == 0) && (hMap.size() < number) && (productIdList.size() <= capacity))
        {
            hMap[brandId] = productIdList;
            flag = true;
        }
        if (hMap.count(brandId) > 0 && hMap[brandId].size() + productIdList.size() <= capacity)
        {
            hMap[brandId].insert(hMap[brandId].end(), productIdList.begin(), productIdList.end());
            flag = true;
        }
        return flag;
    }
    vector<int> BuyProduct(int brandId, int num)
    {
        vector<int> ans;
        vector<int> tem;
        if (hMap.count(brandId) == 0)
        {
            return ans;
        }
        if (hMap.count(brandId) > 0 && hMap[brandId].size() < num)
        {
            return ans;
        }
        ans.assign(hMap[brandId].begin(), hMap[brandId].begin() + num);
        tem.assign(hMap[brandId].begin() + num, hMap[brandId].end());
        hMap[brandId] = tem;
        if (tem.size() == 0)
        {
            hMap.erase(brandId);
        }
        return ans;
    }
    vector<int> QueryProduct()
    {
        vector<int> ans;
        for (auto it = hMap.begin(); it != hMap.end(); it++)
        {
            ans.push_back(it->second[0]);
        }
        return ans;
    }
};

int main()
{
    VendingMachineSystem *vendingMachineSystem = new VendingMachineSystem(2, 5);
    bool a1 = vendingMachineSystem->AddProductIdList(3, {3, 5, 4, 6, 2, 1});
    printf("系统中添加商品 结果 为 :\n");
    printBool(a1);
    bool a2 = vendingMachineSystem->AddProductIdList(3, {3, 5, 4, 6, 2});
    printf("系统中添加商品 结果 为 :\n");
    printBool(a2);
    bool a3 = vendingMachineSystem->AddProductIdList(1, {9});
    printf("系统中添加商品 结果 为 :\n");
    printBool(a3);
    bool a4 = vendingMachineSystem->AddProductIdList(2, {7});
    printf("系统中添加商品 结果 为 :\n");
    printBool(a4);
    vector<int> b1 = vendingMachineSystem->BuyProduct(3, 3);
    printf("系统中购买商品 结果 为 :\n");
    printVec(b1);
    vector<int> b2 = vendingMachineSystem->BuyProduct(9, 3);
    printf("系统中购买商品 结果 为 :\n");
    printVec(b2);
    vector<int> b3 = vendingMachineSystem->BuyProduct(3, 3);
    printf("系统中购买商品 结果 为 :\n");
    printVec(b3);
    vector<int> q1 = vendingMachineSystem->QueryProduct();
    printf("系统中查询商品 结果 为 :\n");
    printVec(q1);
    bool a5 = vendingMachineSystem->AddProductIdList(3, {10, 20, 13, 14});
    printf("系统中添加商品 结果 为 :\n");
    printBool(a5);
    bool a6 = vendingMachineSystem->AddProductIdList(3, {10, 20, 13});
    printf("系统中添加商品 结果 为 :\n");
    printBool(a6);
    vector<int> b4 = vendingMachineSystem->BuyProduct(3, 5);
    printf("系统中购买商品 结果 为 :\n");
    printVec(b4);
    bool a7 = vendingMachineSystem->AddProductIdList(9, {5, 4});
    printf("系统中添加商品 结果 为 :\n");
    printBool(a7);
}