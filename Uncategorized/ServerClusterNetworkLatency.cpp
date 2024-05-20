#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      Huawei: 服务器集群网络延迟

//      给定一个正整数数组表示某服务器集群内服务器的机位编号，
//      请选择一台服务器作为主服务器，使得集群网络延迟最小，并返回最小值。
//      每台服务器有唯一的机位编号;
//          两服务器之间的网络延迟，可以简单用所在机位编号之差的绝对差表示，服务器到自身的延迟为0;
//          集群网络延迟是指主服务器与所有服务器的网络延迟之和。
//      输入：
//          整数N, 数组元素个数, 元素取值范围 [1, 500]
//          N个整数，上述数组的元素 [1, 10000]
//      输出：
//          一个整数, 集群网络延迟的最小值
//      样例1：
//          输入1：
//              3
//              2 6 4
//          输出1：
//              4
//      样例2：
//          输入2：
//              4
//              2 4 3 1
//          输出2：
//              4

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int DigitSumDiff(int k, vector<int> arr);
int ServerClusterNetworkLatency(vector<int> arr);

int main()
{
    int n = generateRandomNum(0, 20);
    vector<int> vec = generateRandomVec(0, 100, n);
    printVecElement(vec);
    int ans_A = ServerClusterNetworkLatency(vec);
    printf("集群网络延迟最小 为 %d \n", ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

vector<int> generateRandomVec(int low, int high, int len)
{
    srand((int)time(0));
    vector<int> vec;
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int DigitSumDiff(int k, vector<int> arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += abs(k - arr[i]);
    }
    return sum;
}

// 贪心：
// Time: O(N)
// Space: O(1)
int ServerClusterNetworkLatency(vector<int> arr)
{
    int l = arr.size();
    sort(arr.begin(), arr.end());
    if ((l & 1) == 1)
    {
        return DigitSumDiff(arr[l / 2], arr);
    }
    else
    {
        return min(DigitSumDiff(arr[l / 2], arr), DigitSumDiff(arr[l / 2 + 1], arr));
    }
}