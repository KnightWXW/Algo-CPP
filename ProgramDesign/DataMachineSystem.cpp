#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//      Huawei: 数据设备系统设计

//      现有一套由若干个设备组成的系统，每个设备既能产生，也能发送和接收数据，
//      系统保证每个设备新产生数据的编号全局唯一。请实现如下功能：
//      DataMachineSystem(int num): 初始化系统的设备数量为 num (编号 1 --- num)。
//      int TransferData(int machineA, int machineB, int dataId):
//          设备 machineA 点到点发送编号dataId 的数据给设备machineB,
//          若machineB已经有该数据，则不接受并返回0，否则接收该数据，
//          machineA, machineB 都会留存数据dataId, 并返回1。
//          注：若machineA没有该数据，表示系统中也无该数据，
//              则自己产生编号为dataId的数据后再发送
//      int TransferDataToAll(int machine, int dataId):
//          设备 machineA 群发 编号dataId 的数据给所有设备,
//          已经由此数据的设备不会接受，请返回发送后接收了此数据的设备数量。
//          发送后，machine和接收到此数据的设备都会留存数据dataId,
//          注：若machine没有该数据，表示系统中也无该数据，
//              则自己产生编号为dataId的数据后再发送
//      int QueryContribution(int machine):
//          查询设备 machine 的贡献量，贡献量的计算规则如下：
//          对于每个接收到数据的设备，其发送方都增加贡献量10；
//          对于群发，发送方增加贡献量为接收到此数据的设备数量 * 10
//          贡献会传递：如果发送方的数据来源于另一设备，
//          那么该设备的贡献量也增加 10
//          贡献继续传递，直至数据的产生方
//      示例1：
//          输入：
//          ["DataMachineSystem", "TransferData", "TransferData", "TransferData",
//          "QueryContribution", "TransferData", "TransferDataToAll",
//          "QueryContribution", "TransferData", "QueryContribution",
//          "QueryContribution","QueryContribution",]
//          [[4],[1,2,5],[2,3,15],[3,4,15],[1],[2,4,37],[2,37],[2],
//          [3,4,37],[1],[3],[4]]
//          输出：
//              [null, 1, 1, 1, 30, 1, 2, 50, 0, 30, 10, 0]

class DataMachineSystem
{
public:
    int numMachines; // 机器数量
    unordered_map<int, unordered_map<int, vector<int>>> dataMap;
    // unordered_map<destMachine, unordered_map<dataId, vector<srcMachine>>>
    vector<int> contributions;  // 机器贡献值

    DataMachineSystem(int num)
    {
        numMachines = num;
        contributions = vector<int>(numMachines + 1);
    }

    int TransferData(int machineA, int machineB, int dataId)
    {
        // machineA里面没有数据：
        if (dataMap[machineA].find(dataId) == dataMap[machineA].end())
        {
            // 将 machineA 加入 machineA数组:
            dataMap[machineA][dataId].push_back(machineA);
        }
        // machineB里面没有数据：
        if (dataMap[machineB].find(dataId) == dataMap[machineB].end())
        {
            // 将 machineA中所有路径数据加入machineB:
            dataMap[machineB][dataId] = dataMap[machineA][dataId];
            // 更新贡献值：
            for (int i = 0; i < dataMap[machineB][dataId].size(); i++)
            {
                contributions[dataMap[machineB][dataId][i]] += 10;
            }
            // 将 machineB 加入 machineB数组:
            dataMap[machineB][dataId].push_back(machineB);
            return 1;
        }
        // machineB 已经有了数据:
        return 0;
    }

    int TransferDataToAll(int machine, int dataId)
    {
        int cnt = 0;
        for (int i = 0; i < numMachines; i++)
        {
            cnt += TransferData(machine, i + 1, dataId);
        }
        return cnt;
    }

    int QueryContribution(int machine)
    {
        return contributions[machine];
    }
};

int main()
{
    DataMachineSystem *dataMachineSystem = new DataMachineSystem(4);
    int t1 = dataMachineSystem->TransferData(1, 2, 15);
    printf("发送数据结果为 %d\n", t1);
    int t2 = dataMachineSystem->TransferData(2, 3, 15);
    printf("发送数据结果为 %d\n", t2);
    int t3 = dataMachineSystem->TransferData(3, 4, 15);
    printf("发送数据结果为 %d\n", t3);
    int q1 = dataMachineSystem->QueryContribution(1);
    printf("设备贡献值为 %d\n", q1);
    int t4 = dataMachineSystem->TransferData(2, 4, 37);
    printf("发送数据结果为 %d\n", t4);
    int t5 = dataMachineSystem->TransferDataToAll(2, 37);
    printf("发送数据结果为 %d\n", t5);
    int q2 = dataMachineSystem->QueryContribution(2);
    printf("设备贡献值为 %d\n", q2);
    int t6 = dataMachineSystem->TransferData(3, 4, 37);
    printf("发送数据结果为 %d\n", t6);
    int q3 = dataMachineSystem->QueryContribution(1);
    printf("设备贡献值为 %d\n", q3);
    int q4 = dataMachineSystem->QueryContribution(3);
    printf("设备贡献值为 %d\n", q4);
    int q5 = dataMachineSystem->QueryContribution(4);
    printf("设备贡献值为 %d\n", q5);
}