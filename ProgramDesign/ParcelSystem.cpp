#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

//      Huawei: 快递柜系统

//      快递柜一共不多于快递区域(areas),每个区域有小(0), 中(1), 大(2) 三种尺寸的格子;
//      ParcelSystem(int area, vector<int> volumes):
//          初始化快递柜系统，给定快递区域area, 以及该区域三个尺寸柜子数量。
//          如果area已经初始化过，则返回-1。否则初始化并返回 1.
//      int Deposit(int id, int area, int vloume): 存入快递。
//          给定 快递的ID, 规定区域area, 以及标准尺寸 volume. 因为全系统快递ID 唯一。
//          如果该id已经存在，则返回-1；如果该区域中 volume尺寸 的柜子没有了，
//          则可以依次存入比他大一个尺寸的柜子里，
//          如果还是没得地方存，返回-1.成功存入返回存放的volume.
//      int Retrieve(int id):取出快递。
//          给定快递ID，如果该id存在, 则删除该快递的记录并 返回1，如果不存在则返回 -1。
//      int Query(int id):查询快递。
//          给定快递id，给定该ID存在，则返回该ID储存的area，如果不存在则返回-1；

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class ParcelSystem
{
public:
    unordered_map<int, vector<int>> areaMap;
    unordered_map<int, pair<int, int>> hmap;

    ParcelSystem(int area, vector<int> volumes)
    {
        areaMap[area] = volumes;
    }

    int Deposit(int id, int area, int vloume)
    {
        if (areaMap.find(area) == areaMap.end())
        {
            printf("11111111\n");
            return -1;
        }
        if (hmap.find(id) != hmap.end())
        {
            printf("222222222\n");
            return -1;
        }
        int v = -1;
        for (int i = vloume; i < 3; i++)
        {
            if (this->areaMap[area][i] > 0)
            {
                this->areaMap[area][i]--;
                v = i;
                break;
            }
        }
        hmap[id] = make_pair(area, v);
        return v == -1 ? -1 : v;
    }

    int Retrieve(int id)
    {
        if (hmap.find(id) == hmap.end())
        {
            return -1;
        }
        hmap.erase(id);
        return 1;
    }

    int Query(int id)
    {
        if (hmap.find(id) == hmap.end())
        {
            return -1;
        }
        return hmap[id].first;
    }
};

int main()
{
    int area1 = 8;
    vector<int> vol = {0, 1, 2};
    printf(" # %d 区域 的 尺寸柜子数量为: \n", area1);
    printVec(vol);
    ParcelSystem *parcelSystem = new ParcelSystem(area1, vol);
    int s1 = parcelSystem->Deposit(0, 7, 3);
    printf("存入快递结果为: %d\n", s1); // -1
    int s2 = parcelSystem->Deposit(1, 8, 2);
    printf("存入快递结果为: %d\n", s2); // 2
    int s3 = parcelSystem->Deposit(2, 8, 2);
    printf("存入快递结果为: %d\n", s3); // 3
    int s4 = parcelSystem->Deposit(3, 8, 1);
    printf("存入快递结果为: %d\n", s4); // 3
    int s5 = parcelSystem->Query(2);
    printf("查询快递结果为: %d\n", s5); // 8
    int s6 = parcelSystem->Query(1);
    printf("查询快递结果为: %d\n", s6); // 8
    int s7 = parcelSystem->Retrieve(2);
    printf("取出快递结果为: %d\n", s7); // 1
    int s8 = parcelSystem->Query(2);
    printf("查询快递结果为: %d\n", s8); // -1
}