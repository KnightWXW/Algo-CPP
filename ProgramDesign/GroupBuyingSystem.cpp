#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

//      Huawei: 设计团购系统

//      请你设计一个团购系统，规则为：
//          拼团的团数不限，每个拼团的优惠商品配额相等，并固定为eachSize
//          拼团从 0 开始编号，顺序递增，系统支持拼团申请功能
//          支持删除指定团(编号为 groupIndex) 的团尾一次拼团申请，
//          支持剔除最后一个非空拼团的团尾一次拼团申请。
//      设计接口如下：
//      GroupBuyingSystem(int eachSize):
//          初始化拼团申购系统，并指定每个拼团的配额。
//      void Join(int id): 接收某人(id)的一次拼团申请，加入规则如下：
//          优先分配到编号尽量小，有空闲名额的团，若当前所有团满员，则开一新团。
//          申请参团即占用团里一个名额，并分配到团尾第一个空余位置。
//          一次申请只能买一件商品，多买则需要多次申请。
//      int RemoveFrom(int groupIndex):
//          删除拼团编号为groupIndex的团尾的一次申请，并返回此成员的id.
//          如果编号为groupIndex的拼团已空，则返回-1；
//      int RemoveLast(void):
//          删除最后一个非空拼团的团尾的一次申请，并返回此成员id;
//          如果所有拼团都空，则返回 -1

class GroupBuyingSystem
{
public:
    int groupSize;
    int groupIndex;
    unordered_map<int, vector<int>> hmap;

    GroupBuyingSystem(int eachSize)
    {
        this->groupSize = eachSize;
        this->groupIndex = 0;
    }

    void Join(int id)
    {
        for (int i = 0; i < this->groupIndex; i++)
        {
            if (hmap[i].size() < this->groupSize)
            {
                hmap[i].push_back(id);
                return;
            }
        }
        hmap[this->groupIndex++] = {id};
        return;
    }

    int RemoveFrom(int groupIndex)
    {
        int id = hmap[groupIndex].back();
        hmap[groupIndex].pop_back();
        // hmap[groupIndex].erase(hmap[groupIndex].size() - 1);
        return id;
    }

    int RemoveLast(void)
    {
        int ans = 0;
        for (int i = this->groupIndex; i >= 0; i--)
        {
            if (hmap[i].size() != 0)
            {
                ans = hmap[i][hmap[i].size() - 1];
                hmap[i].pop_back();
                // hmap[i].erase(hmap[i].size() - 1);
                return ans;
            }
        }
        return -1;
    }
};

int main()
{
    int c1 = 2;
    GroupBuyingSystem *groupBuyingSystem1 = new GroupBuyingSystem(c1);
    groupBuyingSystem1->Join(1);
    groupBuyingSystem1->Join(1);
    groupBuyingSystem1->Join(1);
    groupBuyingSystem1->Join(4);
    groupBuyingSystem1->Join(5);
    int a1 = groupBuyingSystem1->RemoveFrom(0);
    printf("删除拼团结果为：%d\n", a1); // 1
    groupBuyingSystem1->Join(20);
    groupBuyingSystem1->Join(21);
    int a2 = groupBuyingSystem1->RemoveFrom(0);
    printf("删除拼团结果为：%d\n", a2); // 20
    int a3 = groupBuyingSystem1->RemoveFrom(2);
    printf("删除拼团结果为：%d\n", a3); // 21
    int a4 = groupBuyingSystem1->RemoveLast();
    printf("删除拼团结果为：%d\n", a4); // 5
    int a5 = groupBuyingSystem1->RemoveLast();
    printf("删除拼团结果为：%d\n", a5); // 4
    int a6 = groupBuyingSystem1->RemoveLast();
    printf("删除拼团结果为：%d\n", a6); // 1
    int a7 = groupBuyingSystem1->RemoveLast();
    printf("删除拼团结果为：%d\n", a7); // 1
    int a8 = groupBuyingSystem1->RemoveLast();
    printf("删除拼团结果为：%d\n", a8); // -1
}
