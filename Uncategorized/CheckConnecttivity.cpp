#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      Huawei: 业务连通性检测

//      工程师对通信链路(包含主备链路)做 连通性检测，
//      共有 num 个站点(站点编号为 0 ~ num - 1), 
//      每个站点均有主备两个设备，上一行为主设备，下一行为备设备
//      (1) 同一站点的主备设备之间物理联通，相邻站点的主备设备之间物理联通，备备设备之间物理联通
//      (2) 设备 "上电" 则该设备信号是通的，设备 "下电" 则该设备信号是不通
//          设备支持上/下电切换操作：若该设备状态为“上电”，则变更为“下电”；
//          若该设备状态为“下电”，则变更为“上电”；
//          未进行切换操作，则设备状态维持不变。
//          初始时，所有设备均为 “上电” 状态。
//          二维数组 operations 表示对设备的上下电切换操作，
//          其中每个值为操作的设备，格式[主备标识, 站点编号], 
//          主备标识为 0 表示主设备, 1 表示备设备 
//      现按 operations 依次操作，请计算每次操作后的 连通性检测 结果，并返回结果序列。
//      "连通性检测" 方式：操作后，信号是否能从链路的发送端设备(最左侧的主或备)传输至接收端设备(最右侧的主或备),
//      若成功则结果为 1, 否则为 0
//      示例1:
//          num = 5
//          operations = {{0, 2}, {0, 1}, {1, 2}, {0, 2}, {0, 1}};
//          输出：[1, 1, 0, 0, 1]
//      示例2:
//          num = 6
//          operations = {{1, 1}, {0, 4}, {0, 1}, {1, 4}, {1, 1}, {0, 4}};
//          输出：[1, 1, 0, 0, 0, 1]
//      提示：
//          3 <= num <= 10^5
//          1 <= operations.size() <= 10^5
//          operations[i].size() == 2
//          0 <= opeartion[i][0] <= 1
//          0 < opeartion[i][1] < num - 1

void print2DVecElement(vector<vector<int>> vec);
void printVecElement(vector<string> vec);

vector<int> CheckConnecttivity(int num, vector<vector<int>> operations);

int main()
{
    int num1 = 5;
    vector<vector<int>> vec1 = {{0, 2}, {0, 1}, {1, 2}, {0, 2}, {0, 1}};
    print2DVecElement(vec1);
    vector<int> ans1 = CheckConnecttivity(num1, vec1);
    printf("结果序列为 %d\n", ans1);

    int num2 = 6;
    vector<vector<int>> vec2 = {{1, 1}, {0, 4}, {0, 1}, {1, 4}, {1, 1}, {0, 4}};
    print2DVecElement(vec2);
    vector<int> ans2 = CheckConnecttivity(num2, vec2);
    printf("结果序列为 %d\n", ans2);
}

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

void printVecElement(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%s ", vec[i]);
    }
    printf("\n");
}

vector<int> CheckConnecttivity(int num, vector<vector<int>> operations)
{
    
}