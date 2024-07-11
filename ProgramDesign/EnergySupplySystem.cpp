#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

//      Huawei: 电力系统设计

//      设计一个电力系统，该电力系统由供应装置，存储装置和外部设备构成。
//      如图所示：
//                             storeRate
//          供电装置 ----------------------------->存储装置
//          |                                      |
//          | supplyR                              |
//          |                                      |
//          --------------->设备<------------------|

//      供电装置每单位时间可以以supplyRate给外部设备供电。
//      多余的电可以存储到存储装置。
//      存储装置每单位时间最多可以存储storeRate的电，
//      当他为外部设备供电时，也最多以每单位时间storeRate进行供电。
//      存储装置可存储电量的上限为storeLimit。
//      每个外部设备具有唯一标识符index, 自己每单位时间所消耗的电量为 consume,
//      自身优先级为 priority.
//      整个系统供电规则如下：
//          （1）优先使用供电装置给外部设备供电，如果供电装置不足以给外部设备供电，
//               可以使用存储装置配合一起供电
//          （2）先给优先级高的设备供电，若优先级高的设备不足以被供电，
//              则优先级低的也不会被供电
//      设计以下函数：
//          EnergySupplySystem(int supplyRate, int storeLimt, int storeRate):
//               初始化该电力系统
//          void Add(int time, int index, int consume, int priority):
//              在某一时刻 time 添加具有(index, consume, priority)的外部设备
//          int Remove(int time, int index):
//              在某一时刻 time 删除 标识符为 index 的外部设备。
//              若有该设备且成功删除返回1，否则返回-1
//          int Query(int time):
//              在某一时刻查询存储装置的当前电量。

class EnergySupplySystem
{
public:
    int supplyRate;
    int storeLimit;
    int storeRate;
    int curStore;
    int preTime;
    vector<pair<int, pair<int, int>>> vec;

    EnergySupplySystem(int supplyRate, int storeLimit, int storeRate)
    {
        this->supplyRate = supplyRate;
        this->storeLimit = storeLimit;
        this->storeRate = storeRate;
        this->curStore = 0;
        this->preTime = 0;
    }

    void OperateDev()
    {
        if (vec.size() == 0)
        {
            this->curStore = (this->curStore + this->storeRate >= this->storeLimit
                                  ? this->storeLimit
                                  : this->curStore + this->storeRate);
            return;
        }
        int curSupply = this->supplyRate;
        int storeSupply = this->storeRate;
        for (int i = 0; i < this->vec.size(); i++)
        {
            if (curSupply >= this->vec[i].second.first)
            {
                curSupply -= this->vec[i].second.first;
            }
            else if (this->vec[i].second.first - curSupply <= min(curSupply, storeSupply))
            {
                this->curStore = this->curStore - this->vec[i].second.first + curSupply;
                storeSupply = storeSupply - this->vec[i].second.first + curSupply;
                curSupply = 0;
            }
            else
            {
                break;
            }
            if (curSupply > 0)
            {
                if (curSupply >= this->storeRate)
                {
                    this->curStore = ((this->curStore + this->storeRate) > this->storeLimit) ? this->storeLimit : (this->curStore + this->storeRate);
                }
                else
                {
                    this->curStore = ((this->curStore + curSupply) > this->storeLimit) ? this->storeLimit : (this->curStore + curSupply);
                }
            }
        }
    }

    void Add(int time, int index, int consume, int priority)
    {
        for (int i = this->preTime; i < time; i++)
        {
            OperateDev();
        }
        this->preTime = time;
        vec.push_back({index, {consume, priority}});
        sort(vec.begin(), vec.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
             { return a.second.second > b.second.second; });
    }

    int Remove(int time, int index)
    {
        for (int i = this->preTime; i < time; i++)
        {
            OperateDev();
        }
        this->preTime = time;
        for (int i = 0; i < this->vec.size(); i++)
        {
            if (index == this->vec[i].first)
            {
                vec.erase(vec.begin() + i);
                return 1;
            }
        }
        return -1;
    }

    int Query(int time)
    {
        for (int i = this->preTime; i < time; i++)
        {
            OperateDev();
        }
        this->preTime = time;
        return this->curStore;
    }
};

int main()
{
    EnergySupplySystem *energySupplySystem = new EnergySupplySystem(8, 12, 5);
    energySupplySystem->Add(1, 301, 2, 200);
    int a1 = energySupplySystem->Query(1);
    printf("存储装置的当前电量 为 %d\n", a1); // 5
    int a2 = energySupplySystem->Query(2);
    printf("存储装置的当前电量 为 %d\n", a2); // 10
    energySupplySystem->Add(3, 405, 8, 100);
    int a3 = energySupplySystem->Query(3);
    printf("存储装置的当前电量 为 %d\n", a3); // 12
    int a4 = energySupplySystem->Query(4);
    printf("存储装置的当前电量 为 %d\n", a4); // 10
    energySupplySystem->Add(5, 102, 13, 500);
    int a5 = energySupplySystem->Query(5);
    printf("存储装置的当前电量 为 %d\n", a5); // 8
    int a6 = energySupplySystem->Query(6);
    printf("存储装置的当前电量 为 %d\n", a6); // 3
    int a7 = energySupplySystem->Query(7);
    printf("存储装置的当前电量 为 %d\n", a7); // 8
    int r1 = energySupplySystem->Remove(8, 102);
    printf("删除 外部设备 结果为 %d\n", r1);
    int a8 = energySupplySystem->Query(8);
    printf("存储装置的当前电量 为 %d\n", a8); // 3
    int a9 = energySupplySystem->Query(9);
    printf("存储装置的当前电量 为 %d\n", a9); // 1
    int a10 = energySupplySystem->Query(10);
    printf("存储装置的当前电量 为 %d\n", a10); // 6
    int a11 = energySupplySystem->Query(11);
    printf("存储装置的当前电量 为 %d\n", a11); // 4
}