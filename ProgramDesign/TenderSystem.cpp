#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//      Huawei: 招标系统

//      请设计一个招标系统，需要实现以下几个功能
//          void AddTender(int userId, int projectId, int price):
//              将投标方userId对项目projectId的投标金额price录入系统；
//              若系统中已存在投标方userId对项目projectId的投标金额，则不作处理
//          int UpdateTender(int userId, int projectId, int price):
//              若系统中存在投标方userId对项目projectId的投标金额，
//              则将该金额更新为price,并返回更新前的投标金额
//              否则请返回-1;
//          int RemoveTender(int userId, int projectId):
//              若系统中存在投标方userId对项目projectId的投标金额，
//              则删除该投标记录，并返回删除前的投标金额，
//              否则请返回-1;
//          int QueryTender(int projectId, int price):
//              查询并返回系统中项目projectId的投标记录中，
//              投标金额大于price且最接近于price的投标方userId
//              若有多个投标方投标金额相同，比较投标方最后一次投标时间，
//              返回投标时间最早的投标方userId;
//              (AddTender 和 UpdateTender 都是投标)
//              若不存在符合要求的投标记录，返回-1；
//      示例1：
//         输入：["TenderSystem", "AddTender", "AddTender", "AddTender",
//              "UpdateTender", "UpdateTender", "RemoveTender",
//              "RemoveTender","AddTender", "AddTender", "AddTender",
//               "QueryTender", "QueryTender"]
//              [[], [1, 1, 10], [2, 2, 20], [2, 2, 30], [1, 1, 40],
//              [1, 3, 40], [1, 1], [1, 3], [1, 2, 20], [3, 2, 10],
//              [4, 2, 40], [2, 15], [5, 10]]
//         输出：[null, null, null, null, 10, -1, 40, -1,
//              null, null, null, 2, -1]
//      示例2：
//         输入：["TenderSystem", "AddTender", "AddTender", "UpdateTender",
//               "QueryTender"]
//              [[], [1, 1, 10], [2, 1, 20], [1, 1, 20], [1, 10]]
//         输出：[null, null, null, 10, 2]

class TenderSystem
{
public:
    TenderSystem()
    {
    }

    vector<tuple<int, int, int>> hvec;

    void AddTender(int userId, int projectId, int price)
    {
        for (int i = 0; i < hvec.size(); i++)
        {
            if (get<0>(hvec[i]) == userId && get<1>(hvec[i]) == projectId)
            {
                return;
            }
        }
        tuple<int, int, int> tem = make_tuple(userId, projectId, price);
        hvec.push_back(tem);
    }

    int UpdateTender(int userId, int projectId, int price)
    {
        for (int i = 0; i < hvec.size(); i++)
        {
            if (get<0>(hvec[i]) == userId && get<1>(hvec[i]) == projectId)
            {
                int prePrice = get<2>(hvec[i]);
                hvec.erase(hvec.begin() + i);
                tuple<int, int, int> tem = make_tuple(userId, projectId, price);
                hvec.push_back(tem);
                return prePrice;
            }
        }
        return -1;
    }

    int RemoveTender(int userId, int projectId)
    {
        for (int i = 0; i < hvec.size(); i++)
        {
            if (get<0>(hvec[i]) == userId && get<1>(hvec[i]) == projectId)
            {
                int prePrice = get<2>(hvec[i]);
                hvec.erase(hvec.begin() + i);
                return prePrice;
            }
        }
        return -1;
    }

    int QueryTender(int projectId, int price)
    {
        int ans = -1;
        int minPrice = INT_MAX;
        for (int i = 0; i < hvec.size(); i++)
        {
            if (get<1>(hvec[i]) == projectId && get<2>(hvec[i]) > price)
            {
                if (get<2>(hvec[i]) < minPrice)
                {
                    minPrice = get<2>(hvec[i]);
                    ans = get<0>(hvec[i]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    TenderSystem *tenderSystem = new TenderSystem();
    tenderSystem->AddTender(1, 1, 10);
    tenderSystem->AddTender(2, 2, 20);
    tenderSystem->AddTender(2, 2, 30);
    int u1 = tenderSystem->UpdateTender(1, 1, 40);
    printf("更新投标结果为 %d\n", u1);
    int u2 = tenderSystem->UpdateTender(1, 3, 40);
    printf("更新投标结果为 %d\n", u2);
    int r1 = tenderSystem->RemoveTender(1, 1);
    printf("删除投标结果为 %d\n", r1);
    int r2 = tenderSystem->RemoveTender(1, 3);
    printf("删除投标结果为 %d\n", r2);
    tenderSystem->AddTender(1, 2, 20);
    tenderSystem->AddTender(3, 2, 10);
    tenderSystem->AddTender(4, 2, 40);
    int q1 = tenderSystem->QueryTender(2, 15);
    printf("查询投标结果为 %d\n", q1);
    int q2 = tenderSystem->QueryTender(5, 10);
    printf("查询投标结果为 %d\n", q2);
}