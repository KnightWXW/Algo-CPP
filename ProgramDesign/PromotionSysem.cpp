#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

//      Huawei: 优惠活动管理系统

//      设计一个优惠活动管理系统PromotionSysem,功能如下：
//      bool AddPromotion(int activityId, int startDate, int endDate, int category,
//             int number, int priceLimit, int discount):
//          创建一个编号为 activityId 的 优惠活动，若不存在，添加并返回true，
//          否则不处理 并 返回false
//          优惠活动要求：
//              (1) 优惠时间：[startDate, endDate]
//              (2) 商品属于 category品类，且价格 >= priceLimit
//              (3) 前 number 笔 享受 discount 的优惠减免
//      int ProcessPromotion(int date, int category, int price)
//          在date购入一件品类为 category，价格为 price 的商品，
//          进行优惠处理，返回最终支付价格；
//          若满足多个优惠，仅可享受一次
//          选择规则如下：
//              (1) 优先选择减免值最大的
//              (2) 其次选择最接近endDate的
//              (3) 再选择activity最小的
//          若享受优惠，最终价格 = 原价 - 减免，且优惠次数减一，不满足条件则原价支付
//      int QueryRemainNum(int date, int activityId)
//          查询时间为 date，活动为 activityId 的剩余优惠次数
//          题目保证输入的 activityId 存在，
//          若 date 处于活动有效期，则返回该活动剩余优惠次数，否则返回 0。

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

class PromotionSysem
{
public:
    // K: activityId
    // V: tuple<startDate, endDate, category, number, priceLimit, discount>
    unordered_map<int, tuple<int, int, int, int, int, int>> hmap;
    PromotionSysem()
    {
    }

    bool AddPromotion(int activityId, int startDate, int endDate, int category,
                      int number, int priceLimit, int discount)
    {
        if (hmap.find(activityId) != hmap.end())
        {
            return false;
        }
        hmap[activityId] = make_tuple(startDate, endDate, category, number, priceLimit, discount);
        return true;
    }

    int ProcessPromotion(int date, int category, int price)
    {
        vector<tuple<int, int, int>> vec;
        for (auto it = hmap.begin(); it != hmap.end(); it++)
        {
            if ((get<0>(it->second) <= date) && (get<1>(it->second) >= date) && (get<2>(it->second) == category) && (get<3>(it->second) > 0) && (get<4>(it->second) <= price))
            {
                vec.push_back(make_tuple(it->first, get<1>(it->second), get<5>(it->second)));
            }
        }
        sort(vec.begin(), vec.end(), [&](tuple<int, int, int> t1, tuple<int, int, int> t2)
             {
            if (get<2>(t1) == get<2>(t2)){
                if(date - get<1>(t1) == date - get<1>(t2)){
                    return get<0>(t1) < get<0>(t2);
                }
                return (date - get<1>(t1)) < (date - get<1>(t2));
            }
            return  get<2>(t1) > get<2>(t2); });
        if (vec.size() == 0)
        {
            return price;
        }
        int id = get<0>(vec[0]);
        int curDiscount = get<2>(vec[0]);
        get<3>(hmap[id])--;
        return price - curDiscount;
    }

    int QueryRemainNum(int date, int activityId)
    {
        if (date >= get<0>(hmap[activityId]) && date <= get<1>(hmap[activityId]))
        {
            return get<2>(hmap[activityId]);
        }
        return 0;
    }
};

int main()
{
    PromotionSysem *promotionSysem1 = new PromotionSysem();
    bool a1 = promotionSysem1->AddPromotion(0, 1, 3, 5, 1, 20, 10);
    printf("创建结果为：\n");
    printBool(a1); // true
    int a2 = promotionSysem1->ProcessPromotion(1, 5, 16);
    printf("处理结果为：%d\n", a2); // 16
    int a3 = promotionSysem1->ProcessPromotion(2, 5, 25);
    printf("处理结果为：%d\n", a3); // 15
    int a4 = promotionSysem1->ProcessPromotion(2, 2, 50);
    printf("处理结果为：%d\n", a4); // 50
    bool a5 = promotionSysem1->AddPromotion(1, 2, 7, 5, 2, 10, 6);
    printf("创建结果为：\n");
    printBool(a5); // true
    int a6 = promotionSysem1->QueryRemainNum(2, 0);
    printf("查询结果为：%d\n", a6); // 0
    int a7 = promotionSysem1->ProcessPromotion(2, 5, 22);
    printf("处理结果为：%d\n", a7); // 16
    bool a8 = promotionSysem1->AddPromotion(15, 4, 5, 5, 2, 7, 6);
    printf("创建结果为：\n");
    printBool(a8); // true
    bool a9 = promotionSysem1->AddPromotion(2, 4, 5, 5, 20, 7, 6);
    printf("创建结果为：\n");
    printBool(a9); // true
    int a10 = promotionSysem1->ProcessPromotion(4, 5, 30);
    printf("处理结果为：%d\n", a10); // 24
    int a11 = promotionSysem1->QueryRemainNum(5, 2);
    printf("查询结果为：%d\n", a11); // 19
    int a12 = promotionSysem1->QueryRemainNum(8, 1);
    printf("查询结果为：%d\n", a12); // 0
    bool a13 = promotionSysem1->AddPromotion(0, 2, 2, 4, 3, 10, 5);
    printf("创建结果为：\n");
    printBool(a13); // false
}