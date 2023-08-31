#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

//      Huawei: 礼物组合

//      输入为无序的两个整数数组 goods 和 fruits 和 n, 分别为 good 与 fruit 的价格。
//      从两个整形数组中各取一个礼物(即取一个数)组合成一份礼物(即计算两数之和),
//      取礼物价值最小的前 n 份。
//      如果 两个组合的数量和相等，则goods更小的优先。

vector<int> GiftCombination(vector<int> goods, vector<int> fruits, int n);

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

vector<int> GiftCombination(vector<int> goods, vector<int> fruits, int n);

int main()
{
    int n1 = generateRandomNum(1, 20);
    int n2 = generateRandomNum(1, 21);
    int n3 = min(n1, n2);
    int n = generateRandomNum(1, n3);
    vector<int> goods = generateRandomVec(1, 100, n1);
    vector<int> fruits = generateRandomVec(1, 101, n2);
    printVecElement(goods);
    printVecElement(fruits);
    vector<int> ans_A = GiftCombination(goods, fruits, n);
    printf("礼物价值最小的前 %d 份 为: \n", n);
    printVecElement(ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
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
    vector<int> vec;
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

struct cmp
{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        if (p1.first + p1.second == p2.first + p2.second)
        {
            return p1.first <= p2.first;
        }
        return p1.first + p1.second <= p2.first + p2.second;
    }
};

// 排序 + 大根堆
// Time：O(NlogN)
// Space: O(N)
vector<int> GiftCombination(vector<int> goods, vector<int> fruits, int n)
{
    int l1 = goods.size();
    int l2 = goods.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    vector<int> ans;
    sort(goods.begin(), goods.end());
    sort(fruits.begin(), fruits.end());
    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < l2; j++)
        {
            if (pq.size() < n)
            {
                pq.push(make_pair(goods[i], fruits[j]));
                continue;
            }
            pair<int, int> tem = pq.top();
            if (goods[i] + fruits[j] < tem.first + tem.second)
            {
                pq.pop();
                pq.push(make_pair(goods[i], fruits[j]));
            }
            else
            {
                break;
            }
        }
    }

    while (!pq.empty())
    {
        auto tem = pq.top();
        ans.push_back(tem.first + tem.second);
        pq.pop();
    }
    return ans;
}