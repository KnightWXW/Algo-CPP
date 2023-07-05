#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

//      Huawei: Mini订货系统

//      请实现一个Mini订货系统，提供订货，发货，查询功能：
//      OrderSystem(): 系统初始化
//      void Order(int customerId, vector<string> goods):
//          表示某客户的一次订货，goods每个元素表示一件商品，值为商品种类：
//          同一客户可以多次订货；单次订货，可对同一种类的商品订购多件：
//      void Deliver(vector<string> goods): 表示发货多件商品，goods含义同上，
//          每个元素表示一件商品，值为商品种类
//          依次将每件商品按照订购的先后顺序发给订购这件商品的用户
//          注：用例保证发的商品一定被某客户订购过
//      int Query():查询并返回系统中未发货件数最大的客户Id:
//          若存在并列：返回客户Id较小的；
//          若所有客户都完成发货，返回-1；
//      输入：
//          每行表示一个函数调用，初始化函数仅首行调用一行，累计函数调用不超过1000次。
//          1 <= customerId <= 1000
//          1 <= goods.size() <= 1000
//          1 <= goods[i].size() <= 1000
//      输出：
//          按顺序输出每个函数的执行结果。
//          注：无返回结果的函数，框架自动输出字符串 “null”
//      示例一：
//          输入：
//                  OrderSystem()
//                  Order(99, ["gd1000"])
//                  Order(88, ["gd666", "gd555"])
//                  Order(99, ["gd666"])
//                  Query()
//                  Deliver(["gd666"])
//                  Query()
//          输出：
//                  null
//                  null
//                  null
//                  null
//                  88
//                  null
//                  99

class OrderSystem
{
public:
    vector<int> customers;
    vector<string> goodSums;

    OrderSystem()
    {
    }

    void Order(int customerId, vector<string> goods)
    {
        for (int i = 0; i < goods.size(); i++)
        {
            customers.push_back(customerId);
            goodSums.push_back(goods[i]);
        }
        return;
    }

    void Deliver(vector<string> goods)
    {
        for (int i = 0; i < goods.size(); i++)
        {
            auto it = find(goodSums.begin(), goodSums.end(), goods[i]);
            if (it != goodSums.end())
            {
                customers.erase(customers.begin() + (it - goodSums.begin()));
                goodSums.erase(it);
            }
        }
        return;
    }

    int Query()
    {
        if (customers.size() == 0)
        {
            return -1;
        }
        int ans = 0;
        vector<int> vec(customers.begin(), customers.end());
        unordered_map<int, int> cntMap;
        for (int i = 0; i < vec.size(); i++)
        {
            cntMap[vec[i]]++;
        }
        sort(vec.begin(), vec.end(), [&](int i, int j)
             { 
            if(cntMap[i] ==cntMap[j]){
                return i < j;
            }
            return cntMap[i] > cntMap[j]; });
        ans = vec[0];
        return ans;
    }
};

int main()
{
    OrderSystem *orderSystem = new OrderSystem();
    orderSystem->Order(99, {"gd1000"});
    orderSystem->Order(88, {"gd666", "gd555"});
    orderSystem->Order(99, {"gd666"});
    int q1 = orderSystem->Query();
    printf("系统中未发货件数最大的客户Id为 %d \n", q1);
    orderSystem->Deliver({"gd666"});
    int q2 = orderSystem->Query();
    printf("系统中未发货件数最大的客户Id为 %d \n", q2);
}
