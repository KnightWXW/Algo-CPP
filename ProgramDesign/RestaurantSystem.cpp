#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

//      Huawei: 食堂消费系统

//      设计一个食堂消费系统，一个食堂有多个餐厅，餐厅通过 餐厅ID (restaurantId) 唯一标识，
//      每个餐厅的餐食分为早餐，中餐，晚餐，每个餐厅三种餐食有自己的销售额。
//      RestaurantSystem(): 初始化食堂系统：
//      void SellMeals(int restaurantId, int mealType, int money):
//          顾客向指定餐厅购买了一份餐食，种类为 mealType, 金额为 money;
//      vector<int> QueryRestaurant(): 统计每个餐厅各种餐食的应收总额。
//          返回 餐厅Id 序列，并根据销售总额进行降序排序，
//          若销售额相同，则根据餐厅Id升序排序;
//      int GetRestaurantMoney(int restaurantId):
//          查询指定 餐厅Id 的所有餐食的销售总额并返回;
//      输入：
//          ["RestaurantSystem", "SellMeals", "SellMeals", "SellMeals",
//           "QueryRestaurant", "GetRestaurantMoney"]
//          [[], [1, 1, 20], [2, 1, 30], [1, 2, 15], [], [1]]
//      输出：
//          [null, null, null, null, null, [1, 2], [35]]

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class RestaurantSystem
{
public:

    // unordered_map<restaurantId, vector<pair<mealType, money>>>
    unordered_map<int, vector<pair<int, int>>> hmap;

    RestaurantSystem()
    {
    }

    void SellMeals(int restaurantId, int mealType, int money)
    {
        pair<int, int> p1 = make_pair(mealType, money);
        hmap[restaurantId].push_back(p1);
    }

    vector<int> QueryRestaurant()
    {
        vector<vector<int>> tem;
        for (auto it = hmap.begin(); it != hmap.end(); it++)
        {
            int sum = 0;
            sum += GetRestaurantMoney(it->first);
            tem.push_back({it->first, sum});
        }
        sort(tem.begin(), tem.end(), [](vector<int> v1, vector<int> v2)
             {
            if(v1[1] == v2[1]){
                return v1[0] < v2[0];
            }
            return  v1[1] > v2[1]; });
        vector<int> ans(tem.size(), 0);
        for (int i = 0; i < tem.size(); i++)
        {
            ans[i] = tem[i][0];
        }
        return ans;
    }

    int GetRestaurantMoney(int restaurantId)
    {
        int sum = 0;
        vector<pair<int, int>> vec = hmap[restaurantId];
        for (int i = 0; i < vec.size(); i++)
        {
            sum += get<1>(vec[i]);
        }
        return sum;
    }
};

int main()
{
    RestaurantSystem *restaurantSystem = new RestaurantSystem();
    restaurantSystem->SellMeals(1, 1, 20);
    restaurantSystem->SellMeals(2, 1, 30);
    restaurantSystem->SellMeals(1, 2, 15);
    vector<int> a1 = restaurantSystem->QueryRestaurant();
    printf("每个餐厅各种餐食的应收总额为:\n");
    printVecElement(a1);
    int a2 = restaurantSystem->GetRestaurantMoney(1);
    printf("餐厅 %d 的所有餐食的销售总额为: %d\n", 1, a2);
}