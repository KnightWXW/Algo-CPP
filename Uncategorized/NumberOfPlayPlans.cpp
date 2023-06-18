#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//      Huawei: 游玩方案数

//      某一单位组织大家去一个景区游玩，该景区有很多旅游景点，
//      不同的旅游景点同不同的数字分别表示
//      该景区的参观路线桶数组spots表示
//      单位将大家分为两拨人，一拨人从头按照参观路线出发，
//      一拨人从尾部出发，两拨人均可以在任意景点停止游玩
//      问有多少种方法使得两拨人游玩的景点一样
//      示例: 
//          spots = [1,3,2,1]
//          该景区有3个景点，满足所有条件的方案如下
//                  从头出发     |     从尾出发
//                     1        |         1
//                   1,3,2      |       1,2,3
//                  1,3,2,1     |       1,2,3
//                  1,3,2,1     |      1,2,3,1
//                   1,3,2      |      1,2,3,1
//          所以答案为 5, 注意只要两拨人旅游景点去重后相等就是可行的方案
//      提示:  
//          0 <= spots.size() <= 10^5
//          -10^5 <= spots[i] <= 10^5


int generateRandomNum(int low, int high);
void printVecElement(vector<int> &vec);
vector<int> generateRandomVec(int low, int high, int len);

int NumberOfPlayPlans(vector<int> spots);

int main()
{
    int n = generateRandomNum(1, 30);
    vector<int> vec = generateRandomVec(0, 10, n);
    printVecElement(vec);
    int ans = NumberOfPlayPlans(vec);
    printf("有 %d 种方法使得两拨人游玩的景点一样。\n", ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
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

void printVecElement(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int NumberOfPlayPlans(vector<int> spots){
    
}