#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//      Huawei: 简易资产管理系统

//      请设计一个资产管理系统，支持资产增加，借用，归还，统计的功能。
//      每个资产编号是全局唯一的。
//          int AssetsSystem():系统初始化
//          int AddAssets(int assetsId):
//              向系统中增加一个编号为assetId的资产,
//                  如果资产已经存在,则直接返回0,否则增加成功,返回1;
//          int BorrowAssets(int employeesId, int assetsId):
//              员工employeesId借用资产assetsId;
//                  如果资产不存在, 则直接返回-1;
//                  如果资产被借用, 且未被归还, 则直接返回 0;
//                  如果资产未被借用, 则成功借用, 并返回 1;
//          int ReturnAssets(int assetsId):
//              归还资产assetsId;
//                  如果资产不存在，则直接返回-1;
//                  如果资产未被任何人借用，则直接返回 0;
//                  否则成功归还，并返回 1;
//          vector<int> StatAssets(int topNum):
//              统计当前系统内有借用，且未被归还的借用人，并按如下规则返回：
//                  topNum个借用人的employeeId和未归还资产的数量：
//                     优先按未归还的数量从大到小排序；
//                      若数量相同，再按借用人的employeeId从小到大排序
//                     如果人数不足topNum,则按实际人数返回；
//                      如果实际人数为0，返回空数组[]
//      输入1：
//          AssetsSystem()
//          AddAssets(6789)
//          BorrowAssets(41336, 6789)
//          AddAssets(1234)
//          AddAssets(2345)
//          BorrowAssets(99527, 1234)
//          BorrowAssets(99527, 2345)
//          StatAssets(2)
//          ReturnAssets(2345)
//          StatAssets(2)
//          ReturnAssets(555)
//      输出1：
//          null
//          1
//          1
//          1
//          1
//          1
//          1
//          {{99527, 2}, {41336, 1}}
//          1
//          {{41336, 1}, {99527, 1}}
//          -1

void print2DVecElement(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            printf("%d\t", vec[i][j]);
        }
        printf("\n");
    }
}
class AssetsSystem
{
public:
    unordered_map<int, int> assetMap;    // K: assetsId     V: employeesId
    unordered_map<int, int> employeeMap; // K: employeesId  V: assetsNum

    AssetsSystem()
    {
    }

    int AddAssets(int assetsId)
    {
        if (assetMap.find(assetsId) == assetMap.end())
        {
            assetMap[assetsId] = -1;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int BorrowAssets(int employeesId, int assetsId)
    {
        if (assetMap.find(assetsId) == assetMap.end())
        {
            return -1;
        }
        else if (assetMap[assetsId] > 0)
        {
            return 0;
        }
        else if (assetMap[assetsId] == -1)
        {
            assetMap[assetsId] = employeesId;
            employeeMap[employeesId]++;
            return 1;
        }
    }

    int ReturnAssets(int assetsId)
    {
        if (assetMap.find(assetsId) == assetMap.end())
        {
            return -1;
        }
        else if (assetMap[assetsId] == -1)
        {
            return 0;
        }
        else if (assetMap[assetsId] > 0)
        {
            int employeeId = assetMap[assetsId];
            employeeMap[employeeId]--;
            assetMap[assetsId] = -1;
            return 1;
        }
    }

    vector<vector<int>> StatAssets(int topNum)
    {
        vector<vector<int>> vec;
        if (employeeMap.size() == 0)
        {
            return {{}};
        }
        for (auto it = employeeMap.begin(); it != employeeMap.end(); it++)
        {
            vec.push_back({it->first, it->second});
        }
        sort(vec.begin(), vec.end(), [](vector<int> v1, vector<int> v2)
             {
            if(v1[1] == v2[1]){
                return v1[0] < v1[0];
            }
            return v1[1] > v2[1]; });
        if (vec.size() <= topNum)
        {
            return vec;
        }
        else
        {
            vector<vector<int>> ans(vec.begin(), vec.begin() + topNum);
            return ans;
        }
    }
};

int main()
{
    AssetsSystem *assetsSystem1 = new AssetsSystem();
    int a11 = assetsSystem1->AddAssets(6789);
    printf("增加资产的结果为 %d。\n", a11);
    int a12 = assetsSystem1->BorrowAssets(41336, 6789);
    printf("借用资产的结果为 %d。\n", a12);
    int a13 = assetsSystem1->AddAssets(1234);
    printf("增加资产的结果为 %d。\n", a13);
    int a14 = assetsSystem1->AddAssets(2345);
    printf("增加资产的结果为 %d。\n", a14);
    int a15 = assetsSystem1->BorrowAssets(99527, 1234);
    printf("借用资产的结果为 %d。\n", a15);
    int a16 = assetsSystem1->BorrowAssets(99527, 2345);
    printf("借用资产的结果为 %d。\n", a16);
    vector<vector<int>> a17 = assetsSystem1->StatAssets(2);
    printf("统计资产的结果为:\n");
    print2DVecElement(a17);
    int a18 = assetsSystem1->ReturnAssets(2345);
    printf("归还资产的结果为 %d。\n", a18);
    vector<vector<int>> a19 = assetsSystem1->StatAssets(2);
    printf("统计资产的结果为:\n");
    print2DVecElement(a19);
    int a20 = assetsSystem1->ReturnAssets(555);
    printf("归还资产的结果为 %d。\n", a20);
}
