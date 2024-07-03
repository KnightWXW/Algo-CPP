#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

//      Huawei: 船票预约系统设计

//      国庆将至，慧通计划安排东南亚七日游，请实现一个船票预约系统，实现以下功能：
//      TicketSystem(vector<int> cabins): 初始化船舱数以及每个船舱的座位数，
//          cabins下标表示舱位号，值代表舱位的座位数量，座位号从0开始：
//      bool Book(int id, int cabinId, int num):
//          从cabinId舱位中预定num个座位，订单编号为id，
//          若对应舱位候补队列为空：
//              对应舱位有足够余票，则预定成功并按【连续优先订票规则】分配座位，返回true
//              对应舱位余票不足，则预定失败并进入该舱位候补队列队尾，返回false
//          只要对应舱位候补队列非空，则预定失败并进入该舱位候补队列队尾，返回false
//              候补队列是用来存放预定失败的订单，新的候补队列放在队尾。
//          注：订单编号全局唯一，且在预定座位时id不会重复使用
//      bool Cancel(int id):
//          取消编号为id的订单，并及时处理候补订单。
//          若该订单已经预订成功，则成功取消订单，退票并返回true
//          若该订单位于候补队列，则成功取消订单，离开候补队列并返回true
//          若该订单不存在或者已经取消，返回false
//          处理规则：当成功取消订单之后(包含候补队列取消)，
//              按照【先进先出】规则持续处理候补队列队首的订单，
//              若余票满足队首订单需求，则预订成功，并从候补队列移除；
//              继续处理队首订单，直到余票无法满足要求或者候补队列为空为止。
//      int Query(int id): 查询编号为id的订单的最小的座位编号。
//          若订单 已经预定成功，返回最小的座位编号；
//          若订单状态为候补/已取消/不存在，返回 -1
//      [连续优先订票规则]：
//          若存在连续的num个座位号, 则优先分配num个连续座位给乘客，并且座位号尽可能小
//          若不存在连续的num个座位号, 则分配座位号尽可能小的num个座位给乘客，

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

void printVecElement(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class TicketSystem
{
public:
    TicketSystem(vector<int> cabins)
    {
    }
    bool Book(int id, int cabinId, int num)
    {
    }
    bool Cancel(int id)
    {
    }
    int Query(int id)
    {
    }
};

int main()
{
    vector<int> c1 = {10, 1};
    printVecElement(c1);
    TicketSystem *ticketSystem1 = new TicketSystem(c1);
    bool a1 = alarmSystem1->Book(71, 0, 2);
    printf("预定船票结果为：\n");
    printBool(a1); // true
    bool a2 = alarmSystem1->Book(73, 0, 10);
    printf("预定船票结果为：\n");
    printBool(a2); // false
    bool a3 = alarmSystem1->Book(72, 0, 2);
    printf("预定船票结果为：\n");
    printBool(a3); // false
    int q1 = alarmSystem1->Query(72);
    printf("查询订单结果为：%d\n", q1);
    bool a4 = alarmSystem1->Book(74, 0, 2);
    printf("预定船票结果为：\n");
    printBool(a4);                      // false
    bool a5 = alarmSystem1->Cancel(73); // -1
    printf("预定船票结果为：\n");
    printBool(a5); // true
    int q2 = alarmSystem1->Query(74);
    printf("查询订单结果为：%d\n", q2); // 4
    int q3 = alarmSystem1->Query(72);
    printf("查询订单结果为：%d\n", q3); // 2
    bool a6 = alarmSystem1->Cancel(72);
    printf("预定船票结果为：\n");
    printBool(a6); // true
    bool a7 = alarmSystem1->Book(75, 0, 3);
    printf("预定船票结果为：\n");
    printBool(a7); // true
    int q4 = alarmSystem1->Query(75);
    printf("查询订单结果为：%d\n", q4); // 6
    bool a8 = alarmSystem1->Cancel(75);
    printf("预定船票结果为：\n");
    printBool(a8); // true
    bool a9 = alarmSystem1->Book(76, 0, 2);
    printf("预定船票结果为：\n");
    printBool(a9); // true
    bool a10 = alarmSystem1->Book(77, 0, 2);
    printf("预定船票结果为：\n");
    printBool(a10); // true
    bool a11 = alarmSystem1->Cancel(76);
    printf("预定船票结果为：\n");
    printBool(a11); // true
    bool a12 = alarmSystem1->Book(78, 0, 3);
    printf("预定船票结果为：\n");
    printBool(a12); // true
    int q5 = alarmSystem1->Query(78);
    printf("查询订单结果为：%d\n", q5); // 2
}
