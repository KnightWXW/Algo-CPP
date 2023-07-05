#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

//      Huawei: 共享单车管理系统

//      某城市有一个共享单车管理系统,可用一颗树表示，
//      其中包含了仓库和租借点两种节点
//      根节点为仓库，能存放和提供不限量的共享单车
//      其余为租借点，可以租借和归还共享单车
//      请你实现管理系统的如下功能：
//          BikeManager(vector<int> preNode, int capacity): 初始化系统
//              共有preNode.size()个节点，节点编号从0开始；
//              节点0是根节点仓库，其他节点为租借点
//              preNode[i]表示节点i的父节点编号，preNode[0]约定为-1；
//              租借点的容量为capacity,初始时均有[capacity / 2]辆共享单车
//          int RentBikes(int nodeId, int num):
//              在租借点nodeId处租借出num辆共享单车，
//              返回借出后此节点剩余单车数量。
//              若节点nodeId处的共享单车数量不足num辆，则不足的部分向其父节点索取，
//              这一过程向其父节点递归求解，直到成功借出
//          int ReturnBikes(int nodeId, int num):
//              在租借点nodeId处归还出num辆共享单车，
//              返回归还后此节点的单车数量。
//              若节点nodeId放满共享单车后还有剩余，
//              则将多余的共享单车归还给其父节点，
//              这一过程同样将向其父节点递归求解，直到成功归还。
//          int Reset():重置租借点的共享单车数量，并返回被重置的节点数。
//              对于当前共享单车数量为0或者capacity的租借点，
//              将他们的共享单车数量重置为[capacity / 2], 其他节点不重置。
//          vector<int> GetTop5Nodes():按规则返回top5的租借点编号，
//              若租借点不足5个，则按实际数量返回。
//              规则:优先按剩余单车数量降序；若数量相同，则按编号升序。
//      注意：[x] 表示向下取整，即floor(x)
//      示例：
//          输入：
//              ["BikeManager", "RentBikes", "RentBikes", "GetTop5Nodes",
//              "ReturnBikes", "RentBikes","Reset", "RentBikes", "GetTop5Nodes"]
//              [[[-1, 0, 1, 1, 5, 0, 1, 0], 41], [2, 31], [3, 45], [],
//              [5, 29], [5, 100], [], [3, 12], []]
//          输出：
//              [null, 0, 0, [4, 5, 6, 7, 1], 41, 0, 4, 8, [1, 2, 4, 5, 6]]

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class BikeManager
{
public:
    vector<int> bikeNode;
    vector<int> bikeStation;
    int maxCapacity;
    int bikeSize;

    BikeManager(vector<int> preNode, int capacity)
    {
        bikeSize = preNode.size();
        bikeNode = preNode;
        maxCapacity = capacity;
        bikeStation = vector<int>(bikeSize, capacity / 2);
        bikeStation[0] = -1;
    }

    int RentBikes(int nodeId, int num)
    {
        int curId = nodeId;
        while (curId > 0 && num > 0)
        {
            int rentNum = min(bikeStation[curId], num);
            bikeStation[curId] -= rentNum;
            num -= rentNum;
            curId = bikeNode[curId];
        }
        return bikeStation[nodeId];
    }

    int ReturnBikes(int nodeId, int num)
    {
        int curId = nodeId;
        while (curId > 0 && num > 0)
        {
            int returnNum = min(num, maxCapacity - bikeStation[curId]);
            bikeStation[curId] += returnNum;
            num -= returnNum;
            curId = bikeNode[curId];
        }
        return bikeStation[nodeId];
    }

    int Reset()
    {
        int cnt = 0;
        for (int i = 1; i < bikeSize; i++)
        {
            if (bikeStation[i] == maxCapacity || bikeStation[i] == 0)
            {
                cnt++;
                bikeStation[i] = maxCapacity / 2;
            }
        }
        return cnt;
    }

    vector<int> GetTop5Nodes()
    {
        vector<int> ans(bikeSize - 1);
        iota(ans.begin(), ans.end(), 1);
        nth_element(ans.begin(), ans.begin() + min(bikeSize - 1, 5), ans.end(),
                    [this](int i, int j)
                    {
                        if (bikeStation[i] != bikeStation[j])
                        {
                            return bikeStation[i] > bikeStation[j];
                        }
                        return i < j;
                    });
        sort(ans.begin(), ans.begin() + min(bikeSize - 1, 5),
             [this](int i, int j)
             {
                 if (bikeStation[i] != bikeStation[j])
                 {
                     return bikeStation[i] > bikeStation[j];
                 }
                 return i < j;
             });
        return vector<int>(ans.begin(), ans.begin() + min(bikeSize - 1, 5));
    }
};

int main()
{
    BikeManager *bikeManager = new BikeManager({-1, 0, 1, 1, 5, 0, 1, 0}, 41);
    int r1 = bikeManager->RentBikes(2, 31);
    printf("此节点剩余单车的量 为 %d\n", r1);
    int r2 = bikeManager->RentBikes(3, 45);
    printf("此节点剩余单车的量 为 %d\n", r2);
    vector<int> g1 = bikeManager->GetTop5Nodes();
    printVec(g1);
    int r3 = bikeManager->ReturnBikes(5, 29);
    printf("此节点剩余单车的量 为 %d\n", r3);
    int r4 = bikeManager->RentBikes(5, 100);
    printf("此节点剩余单车的量 为 %d\n", r4);
    int s1 = bikeManager->Reset();
    printf("被重置的节点数 为 %d\n", s1);
    int r5 = bikeManager->RentBikes(3, 12);
    printf("此节点剩余单车的量 为 %d\n", r5);
    vector<int> g2 = bikeManager->GetTop5Nodes();
    printVec(g2);
}
