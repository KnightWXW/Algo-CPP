#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//      切金条问题

//      一块金条切成两半，是需要花费和长度数值一样的铜板。 
//      比如长度为20的金条，不管怎么切都要花费20个铜板，
//      一群人想整分整块金条，怎么分最省铜板? 
//      例如，给定数组{10,20,30}，代表一共三个人，整块金条长度为60，
//      金条要分成 10，20，30 三个部分。 
//      如果先把长度 60 的金条分成 10 和 50，花费 60；
//      再把长度 50 的金条分成 20 和 30 ，花费 50 ；一共花费 110 铜板 
//      但如果先把长度60的金条分成 30 和 30，花费60；
//      再把长度 30 金条分成 10 和20，花费 30 ；一共花费 90 铜板
//      输入一个数组，返回分割的最小代价

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int cuttingGold(vector<int> arr);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> arr = generateRandomVec(1, 5, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    printf("分割金子 的 最小代价为 %d。\n", cuttingGold(arr));
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
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

// 贪心：
//    每次找 堆内最小 的 两个元素 合并，合并 后 加入堆：
//    分金 顺序 与 合并顺序 相反
// Time: O(NlogN)
// Space: O(N)
int cuttingGold(vector<int> arr)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto v : arr){
        pq.push(v);
    }

    int cost = 0;
    while(pq.size() >= 2){
        int v1 = pq.top();
        pq.pop();
        int v2 = pq.top();
        pq.pop();

        pq.push(v1 + v2);
        cost += v1 + v2;
    }
    return cost;
}