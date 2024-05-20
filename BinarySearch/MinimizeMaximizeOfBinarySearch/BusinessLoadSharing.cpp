#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//      Huawei: 业务负载分担

//      现在有一个服务器集群(服务器数量为 serveNum),
//      和一批不同类型的任务(用数组 task 表示，下标表示任务类型，值表示任务数量)；
//      现需要把这批任务都分配到集群的服务器上，分配规则如下：
//      应业务安全要求，不同类型的任务不能分配到同一台服务器上，
//      一种类型的多个任务可以分配在多台服务器上
//      “负载”定义为某台服务器所分配的任务个数，无任务的服务器负载为0
//      “最高负载”定义为所有服务器中负载的最大值
//      请你制定分配方案，使得分配后 “最高负载” 的值最小，并返回该最小值。
//      输入：
//          集群中服务器的数量
//          这批任务有 taskTypeNum 种类型
//          taskTypeNum个整数，为task数组，表示这批任务
//      输出：
//          “最高负载” 的最小值
//      示例1：
//          输入：
//              5
//              2
//              7 4
//          输出:
//              3
//      示例2：
//          输入：
//              8
//              5
//              101 1 1 20 40
//          输出:
//              34

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

bool JudgeBusinessLoadSharing(vector<int> arr, int serveNum, int mid)
int BusinessLoadSharing(vector<int> arr, int serveNum);

int main()
{
    int n = generateRandomNum(0, 30);
    vector<int> vec = generateRandomVec(0, 100, n);
    int serveNum = generateRandomNum(0, 50);
    printVecElement(vec);
    int ans_A = BusinessLoadSharing(vec, serveNum);
    printf("当服务器数量为 %d 时, 分配后 “最高负载” 的值最小为 %d\n", serveNum, ans_A);
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

bool JudgeBusinessLoadSharing(vector<int> arr, int serveNum, int mid)
{
    int l = arr.size();
    int sum = 0;
    for (int i = 0; i < l; i++)
    {
        sum += arr[i] / mid;
        sum += arr[i] % mid == 0 ? 0 : 1;
    }
    return sum <= serveNum;
}

// 二分查找：
// Time: O(NlogN)
// Space: O(1)
int BusinessLoadSharing(vector<int> arr, int serveNum)
{
    int l = arr.size();
    int maxVal = 0;
    for (int i = 0; i < l; i++)
    {
        maxVal = max(maxVal, arr[i]);
    }
    int left = 1;
    int right = maxVal;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (JudgeBusinessLoadSharing(arr, serveNum, mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}