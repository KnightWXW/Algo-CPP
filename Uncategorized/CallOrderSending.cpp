#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

//      Huawei: 话单发送

//      某核心网设备向计费网关发送话单(一个话单指一条通话记录的信息), 发送规则如下：
//      每个话单具有长度和优先级两个属性，
//      优先级值越小表示优先级越高，高优先级的发送完，才能发送低优先级的。
//      设备有一个承载规格，表示发送话单总容量的阈值。
//      发送话单的总长度不能超过承载规格。
//      现给定设备的承载规格和待发送话单(长度和优先级)列表，请计算最多可以发送多少个话单。
//      样例1：
//          输入：
//              110
//              {{50, 2}, {20, 2}, {30, 1}, {10, 3}, {50, 1}}
//          输出：
//              3

void print2DVecElement(vector<vector<int>> vec);

int CallOrderSending(vector<vector<int>> arr, int k);

int main()
{
    int k = 110;
    vector<vector<int>> vec = {{50, 2}, {20, 2}, {30, 1}, {10, 3}, {50, 1}};
    print2DVecElement(vec);
    int ans_A = CallOrderSending(vec, k);
    printf("阈值为 %d 时, 最多可以发送多少个话单 %d 。\n", k, ans_A);
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
    printf("\n");
}

int CallOrderSending(vector<vector<int>> arr, int k)
{
    
}