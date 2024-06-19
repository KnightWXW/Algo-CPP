#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>

using namespace std;

//      Huawei: 业务连通性检测

//      工程师对通信链路(包含主备链路)做 连通性检测，
//      共有 num 个站点(站点编号为 0 ~ num - 1),
//      每个站点均有主备两个设备，上一行为主设备，下一行为备设备
//      (1) 同一站点的主备设备之间物理联通，相邻站点的主备设备之间物理联通，备备设备之间物理联通
//      (2) 设备 "上电" 则该设备信号是通的，设备 "下电" 则该设备信号是不通
//          设备支持上/下电切换操作：若该设备状态为 “上电”，则变更为 “下电”；
//          若该设备状态为 “下电”，则变更为 “上电”；
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
void printVecElement(vector<int> vec);

int JudgePerConnect_A(unordered_set<int> hset, int num);
vector<int> CheckConnecttivity_A(int num, vector<vector<int>> operations);
vector<int> CheckConnecttivity_B(int num, vector<vector<int>> operations);

int main()
{
    int num1 = 5;
    vector<vector<int>> vec1 = {{0, 2}, {0, 1}, {1, 2}, {0, 2}, {0, 1}};
    print2DVecElement(vec1);
    vector<int> ans1a = CheckConnecttivity_A(num1, vec1);
    vector<int> ans1b = CheckConnecttivity_B(num1, vec1);
    printf("结果序列为 :\n");
    printVecElement(ans1a); // [1, 1, 0, 0, 1]
    printVecElement(ans1b); // [1, 1, 0, 0, 1]

    int num2 = 6;
    vector<vector<int>> vec2 = {{1, 1}, {0, 4}, {0, 1}, {1, 4}, {1, 1}, {0, 4}};
    print2DVecElement(vec2);
    vector<int> ans2a = CheckConnecttivity_A(num2, vec2);
    vector<int> ans2b = CheckConnecttivity_B(num2, vec2);
    printf("结果序列为 :\n");
    printVecElement(ans2a); // [1, 1, 0, 0, 0, 1]
    printVecElement(ans2b); // [1, 1, 0, 0, 0, 1]
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

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int JudgePerConnect_A(unordered_set<int> hset, int num)
{
    for (auto it = hset.begin(); it != hset.end(); it++)
    {
        auto k = *it;
        if (hset.count(k - num) > 0 || hset.count(k + num) > 0 || hset.count(k - num + 1) > 0 || hset.count(k + num + 1) > 0)
        {
            return 0;
        }
    }
    return 1;
}

// 哈希:
// Time: O(M * N)
// Space: O(N)
vector<int> CheckConnecttivity_A(int num, vector<vector<int>> operations)
{
    vector<int> ans(num, 0);
    unordered_set<int> hset;
    for (int i = 0; i < num; i++)
    {
        int tag = operations[i][0];
        int index = operations[i][1];
        auto tem = tag * num + index;
        if (hset.count(tem) == 0)
        {
            hset.insert(tem);
        }
        else
        {
            hset.erase(tem);
        }
        int a = JudgePerConnect_A(hset, num);
        ans[i] = a;
    }
    return ans;
}

// 寻找 断点:
// Time: O(M * N)
// Space: O(N)
vector<int> CheckConnecttivity_B(int num, vector<vector<int>> operations)
{
    vector<int> ans(num, 0);
    vector<vector<int>> stations(2, vector<int>(num, 0));
    int breakPoints = 0;
    for (int i = 0; i < num; i++)
    {
        int tag = operations[i][0];
        int index = operations[i][1];
        int ops = tag == 0 ? 1 : 0;
        int add = stations[tag][index] == 0 ? 1 : -1;
        if (tag == 0)
        {
            ops = 1;
        }
        if (stations[ops][index] == 1)
        {
            breakPoints += add;
        }
        if (index < (num - 1) && stations[ops][index + 1] == 1)
        {
            breakPoints += add;
        }
        if (index > 1 && stations[ops][index - 1] == 1)
        {
            breakPoints += add;
        }
        stations[tag][index] = stations[tag][index] == 0 ? 1 : 0;
        ans[i] = breakPoints > 0 ? 0 : 1;
    }
    return ans;
}