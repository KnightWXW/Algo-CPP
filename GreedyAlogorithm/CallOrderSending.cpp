#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

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

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

int CallOrderSending(vector<vector<int>> arr, int k);

int main()
{
    int k = generateRandomNum(10, 100);
    int n = generateRandomNum(1, 30);
    vector<vector<int>> vec = generateRandom2DVec(0, 10, n, 2);
    print2DVecElement(vec);
    int ans_A = CallOrderSending(vec, k);
    printf("阈值为 %d 时, 最多可以发送多少个话单 %d 。\n", k, ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col)
{
    srand((int)time(0));
    vector<vector<int>> vec;
    for (int i = 0; i < row; i++)
    {
        vector<int> tem;
        for (int j = 0; j < col; j++)
        {
            int v = (rand() % (high - low + 1)) + low;
            tem.push_back(v);
        }
        vec.push_back(tem);
    }
    return vec;
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
    int l = arr.size();
    vector<vector<int>> vec(arr);
    sort(vec.begin(), vec.end(), [](vector<int> v1, vector<int> v2)
         {
        if(v1[1] == v2[1]){
            return v1[0] < v2[0];
        }
        return v1[1] < v2[1]; });
    int cnt = 0;
    int leng = k;
    for (int i = 0; i < l; i++)
    {
        if (vec[i][0] < leng)
        {
            leng -= vec[i][0];
            cnt++;
        }
        else
        {
            break;
        }
    }
    return cnt;
}