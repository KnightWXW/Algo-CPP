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
//          若存在连续的 num 个座位号, 则优先分配 num 个连续座位给乘客，并且座位号尽可能小
//          若不存在连续的 num 个座位号, 则分配座位号尽可能小的 num 个座位给乘客，

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

define MAX 1001

    typedef struct
{
    int boat;
    int num;
    int status;
    int seat[MAX];
} bookinfo;

typedef struct
{
    int boat[MAX];
    int reserv[MAX];
    int hash[MAX][MAX];
    int waite[MAX][MAX];
    int waitecnt[MAX];
    bookinfo book[MAX];
} TicketSystem;

TicketSystem *TicketSystemCreate(int *cabins, int cabinsSize)
{
    TicketSystem *obj = (TicketSystem *)calloc(1, sizeof(TicketSystem));
    for (int i = 0; i < cabinsSize; i++)
    {
        obj->boat[i] = cabins[i];
        obj->reserv[i] = cabins[i];
    }
    return obj;
}

int find(TicketSystem *obj, int id, int cabinId, int num)
{
    obj->book[i].boat = cabinId;
    obj->book[i].num = num;
    if ((obj->waitecnt[cabinId] != 0) || (obj->reserv[cabinId] < num))
    {
        obj->waite[cabinId][obj->waitecnt[cabinId]] = id;
        obj->waitecnt[cabinId]++;
        obj->book[id].status = 2;
        return false;
    }
    else
    {
        int cnt = 0;
        int i = find(obj, cabinId, num);
        for (; i < obj->boat[cabinId] && cnt < num; i++)
        {
            if (obj->hash[cabinId][i] != 1)
            {
                obj->book[id].seat[cnt++] = i;
                obj->hash[cabinId][i] = 1;
                obj->book[id].status = 1;
            }
        }
        obj->reserv[cabinId] -= num;
        return true;
    }
}

bool TicketSystemBookNew(TicketSystem *obj, int id, int cabinId, int num)
{
    if (obj->reserv[cabinId] >= num)
    {
        int cnt = 0;
        int i = find(obj, cabinId, num);
        for (; i < obj->boat[cabinId] && cnt < num; i++)
        {
            if (obj->hash[cabinId][i] != 1)
            {
                obj->book[id].seat[cnt++] = i;
                obj->hash[cabinId][i] = 1;
                obj->book[id].status = 1;
            }
        }
        obj->reserv[cabinId] -= num;
        return true;
    }
    return false;
}

bool TicketSystemBookCancel(TicketSystem *obj, int id)
{
    if (obj->book[id].status == 0)
    {
        return false;
    }
    if (obj->book[id].status == 1)
    {
        int cabinId = obj->book[id].boat;
        obj->book[id].status = 0;
        for (int i = 0; i < obj->book[id].num; i++)
        {
            obj->hash[cabinId][obj->book[id].seat[i]] = 0;
        }
        obj->reserv[cabinId] += obj->book[id].num;
        int i;
        for (i = 0; i < obj->waitecnt[cabinId]; i++)
        {
            int newid = obj->waite[cabinId][i];
            int num = obj->book[newid].num;
            if (TicketSystemBookNew(obj, newid, cabinId, num) == false)
            {
                break;
            }
        }
        for (i = 0; i < obj->waitecnt[cabinId]; i++)
        {
            obj->waite[cabinId][j] = obj->waite[cabinId][i + j];
        }
        obj->waitecnt[cabinId] -= i;
        return false;
    }
    obj->book[id].status = 0;
    int cabinId = obj->book[id].boat;
    int flag = 0;
    for (i = 0; i < obj->waitecnt[cabinId]; i++)
    {
        if (obj->waite[cabinId][i] == id)
        {
            flag = 1;
        }
        if (flag == 1)
        {
            obj->waite[cabinId][i] = obj->waite[cabinId][i + 1];
        }
    }
    obj->waitecnt[cabinId]--;
    int i = 0;
    for (i = 0; i < obj->waitecnt[cabinId]; i++)
    {
        int newid = obj->waite[cabinId][i];
        int num = obj->book[newid].num;
        if (TicketSystemBookNew(obj, newid, cabinId, num) == false)
        {
            break;
        }
    }
    for (int j = 0; j < obj->waitecnt[cabinId]; j++)
    {
        obj->waite[cabinId][j] = obj->waite[cabinId][i + j];
    }
    obj->waitecnt[cabinId] -= i;
    return true;
}

int TicketSystemQuery(TicketSystem *obj, int id)
{
    if (obj->book[id].status == 1)
    {
        return obj->book[id].seat[0];
    }
    return -1;
}

void TicketSystemFree(TicketSystem *obj)
{
    free(obj);
}

// ---------------------------------------------------
class TicketSystem
{
public:
    map<int, vector<pair<int, vector<int>>>> booked; // k:船舱号  v: 订单id
    map<int, vector<int>> canibs;                    // k:船舱号  v: 每个座位的编号
    map<int, vector<pair<int, int>>> wait;           // k:船舱号  v: 候补订单的订单号和定的座位个数

    TicketSystem(vector<int> cabins)
    {
        for (int i = 0; i < cabins.size(); i++)
        {
            pair<int, vector<int>> tmp;
            tmp.first = i;
            vector<int> temset;
            for (int j = 0; j < cabins.size(); j++)
            {
                tmpset.emplace_back(j);
            }
            tmp.second = temset;
            cabins[i] = temset;
        }
    }

    bool Book(int id, int cabinId, int num)
    {
        if (wait[cabinId].size() != 0 || cabins[cabinId].size() < num)
        {
            wait[cabinId].emplace_back(id, num);
            return false;
        }
        Request(id, canineId, num);
        return true;
    }

    void Request(int id, int cabinId, int num)
    {
        int index = 0;
        for (int i = 0; i + num - 1 < cabins[cabinId].size(); i++)
        {
            if (cabins[cabinId][i + num - 1] - cabins[cabinId][i] == num - 1)
            {
                index = i;
                break;
            }
        }
        vector<int> tmpset;
        int flag = index;
        for (int i = 0; i < num; i++)
        {
            tmpset.push_back(cabins[cabinId][index]);
            index++;
        }
        cabins[cabinId].erase(cabins[cabinId].begin() + flag, cabins[cabinId].begin() + sort(cabins[cabinId].begin(), cabins[cabinId].end()));
        booked[cabinId].emplace_back(make_pair(id, tmpset));
    }

    bool Cancel(int id)
    {
    }

    int Query(int id)
    {
        for (int i = 0; i < booked.size(); i++)
        {
            for (int j = 0; j < booked[i].size(); j++)
            {
                if (booked[i][j].first == id)
                {
                    return booked[i][j].second[0];
                }
            }
        }
        return -1;
    }
};

// -----------------------------------------

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
