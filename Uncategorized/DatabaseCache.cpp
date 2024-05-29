#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;


//      Huawei: 数据库缓存

//      缓存是一种提高数据库查询效率的手段，试用训练数据进行模拟访问，以对缓存机制进行优化。
//      模拟访问规则如下：
//          当查询的数据在缓存中时，直接访问缓存，无需访问数据库；
//          当查询的数据不在缓存中，则需要访问数据库，并把数据放入缓存；
//          若放入前回缓存已满，则必须先删除缓存中的一个数据；
//      给定缓存大小的训练数据(一组数据编号)，依次模拟访问这组数据，
//      请分析在访问规则下最少的数据库访问次数。

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int DatabaseCache(vector<int> data, int cache);

int main()
{
    int n = generateRandomNum(1, 30);
    int cache = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(1, 100, n);
    printVecElement(vec);
    int ans_A = DatabaseCache(vec, cache);
    printf("能以递增顺序显示卡牌的牌组顺序为: \n");
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
    srand((int)time(0));
    vector<int> vec;
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

int DatabaseCache(vector<int> data, int cache)
{
    int l = data.size();
    
}