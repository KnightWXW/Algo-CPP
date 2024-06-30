#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>

using namespace std;

//      Huawei: 货物抓取

//      码头抓取货物，优先抓取编号连续数目最多的货物，
//      如果多个货物数目相同，优先抓取最左侧的货物。
//      如果货物被抓取后，右侧货物自动向左侧补齐。
//      输出抓取完货物的次数。
//      示例1：
//          输入：{8,8,8,5,5,5,8,1,1,2,3}
//          输出：6

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int GrabGoods(vector<int> goods);

int main()
{
    int n = generateRandomNum(0, 50);
    vector<int> vec = generateRandomVec(1, 5, n);
    printVecElement(vec);
    int ans_A = GrabGoods(vec);
    printf("抓取完货物的次数为 %d\n", ans_A);
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

int GrabGoods(vector<int> goods)
{
    int l = goods.size();
    int ans = 0;
    stack<pair<int, int>> stk;
    for (int i = l - 1; i >= 0; i--)
    {
        stk.push(goods[i]);
    }
    while
}