#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//      Huawei: 手机壳库存管理

//      库存管理对于手机壳销售是否达成最大化至关重要。
//      仓库中有一批不同型号的手机壳，
//      每种型号手机壳的库存数量存在inventory中，
//      总售价存在数组 price 中，
//      每种型号的手机壳的销售收益 = 销售数量 * (price[i] / inventory[i])。
//      现给定市场上手机壳的最大需求量 demand ,
//      请制定最佳销售策略以获取最大的总销售收益，并返回该值。
//      输入：
//          M: 手机壳种类数 [1, 1000]
//          N: 市场最大需求量 [1, 500]
//          M个数字: 每种手机壳的数量 [0.0, 1000.0] (千件为单位)
//          M个数字: 每种手机壳的总售价 [0.0, 10000.0] (万元为单位)
//      输出:
//          浮点书形式的最大收益值(万元为单位)
//      输入样例1：
//          3
//          20
//          18.0 15.0 10.0
//          75.0 72.0 45.0
//      输出样例1：
//          94.50

int generateRandomNum(int low, int high);
vector<double> generateRandomVec(double low, double high, int len);
void printVec(vector<double> &vec);

double PhoneSellManage(double demand, vector<double> inventory, vector<double> price);

int main()
{
    vector<double> inventory = {18.0, 15.0, 10.0};
    vector<double> price = {75.0, 72.0, 45.0};
    printf("每种手机壳的库存数量为：\n");
    printVec(inventory);
    printf("每种手机壳的总售价为：\n");
    printVec(price);
    double demand = 20;
    double ans = PhoneSellManage(demand, inventory, price);
    printf("获取最大的总销售收益为 %lf。\n", ans);
}

void printVec(vector<double> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%f ", vec[i]);
    }
    printf("\n");
}

// 贪心：
// Time: O(NlogN)
// Space: O(logN)
double PhoneSellManage(double demand, vector<double> inventory, vector<double> price)
{
    int l = inventory.size();
    vector<pair<double, double>> vec;
    for (int i = 0; i < l; i++)
    {
        vec.push_back(make_pair(inventory[i], price[i] / inventory[i]));
    }
    sort(vec.begin(), vec.end(), [](pair<double, double> p1, pair<double, double> p2)
         { if(p1.second == p2.second)
            {
                return p1.first < p2.first;
            }
            return p1.second > p2.second; });
    double ans = 0.0;
    double k = demand;
    for (int i = 0; i < l; i++)
    {
        double tem = min(vec[i].first, k);
        k -= tem;
        ans += tem * vec[i].second / 1.0;
        if (k == 0)
        {
            break;
        }
    }
    return ans;
}