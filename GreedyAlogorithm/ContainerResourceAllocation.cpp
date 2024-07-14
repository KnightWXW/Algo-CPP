#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

//      Huawei: 容器资源分配

//      容器化是当前云化趋势下的一种重要技术。
//      请实现一种CPU分配方案，满足以下要求：
//      假如所有虚拟机的CPU核数都为 cpuCore
//      每个虚拟机都至多部署两个容器，一个容器占有一定数量的CPU核数，
//      一个虚拟机上容器占有的CPU核数总和不能超过 cpuCore；
//          现有A,B两个业务，每个业务都有一个或多个微服务，每个微服务独自占用一个容器
//          业务A的每个容器需要的CPU核数存放于serviceA中，
//          serviceA[i]表示容器i所需要的CPU核数。serviceB 一致
//          业务A需要支持反亲和策略，即业务A的任意两个容器不能同时运行在同一个虚拟机上，
//          业务B不需要
//      至少需要多少个虚拟机 来满足A B 两个业务

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int ContainerResourceAllocation(int cpuCore, vector<int> &serviceA, vector<int> &serviceB);

int main()
{
    int la = generateRandomNum(1, 20);
    int lb = generateRandomNum(1, 30);
    vector<int> serviceA1 = generateRandomVec(1, 64, la);
    vector<int> serviceB1 = generateRandomVec(1, 63, lb);
    int cpuCore1 = generateRandomNum(63, 128);
    printVecElement(serviceA1);
    printVecElement(serviceB1);
    int ans1 = ContainerResourceAllocation(cpuCore1, serviceA1, serviceB1); 
    printf("cpuCore为 %d 时, 至少需要 %d 个虚拟机 来满足A B 两个业务 \n", cpuCore1, ans1);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
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

// 贪心：serviceA.size() + serviceB.size() - A/B 最大匹配数目
// Time: O(logN)
// Space: O(1)
int ContainerResourceAllocation(int cpuCore, vector<int> &serviceA, vector<int> &serviceB)
{
    int la = serviceA.size();
    int lb = serviceB.size();
    int ans = la + lb;
    sort(serviceA.begin(), serviceA.end());
    sort(serviceB.begin(), serviceB.end(), [](int a, int b)
         { return a > b; });
    vector<int> remainB;
    int ia = 0;
    int ib = 0;
    while (ia < la && ib < lb)
    {
        if (serviceA[ia] + serviceB[ib] <= cpuCore)
        {
            ia++; 
        }
        else
        {
            remainB.push_back(serviceB[ib]);
        }
        ib++;
        ans--;
    }
    int left = 0;
    int right = remainB.size() - 1;
    while(left <= right){
        if(remainB[left] + remainB[right] <= cpuCore){
            left++;
            right--;
            ans--;
        }else{
            right--;
        }
    }
    return ans;
}