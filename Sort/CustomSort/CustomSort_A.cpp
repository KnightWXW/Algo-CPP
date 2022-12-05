#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// 自定义排序：从大到小

vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

bool cmpGreatToLess(const int &v1, const int &v2);

int main()
{
    vector<int> vec_A = generateRandomVec(-100, 100, 10);
    vector<int> vec_B;
    vec_B.assign(vec_A.begin(), vec_A.end());

    printf("数组未排序 前为：\n");
    printVecElement(vec_A);
    printVecElement(vec_B);

    // 排序：
    // 自定义比较器：
    sort(vec_A.begin(), vec_A.end(), cmpGreatToLess);
    // lambda表达式：
    sort(vec_B.begin(), vec_B.end(), [](const int &v1, const int &v2){
        return v1 > v2;
    });

    printf("自定义排序 后为：\n");
    printVecElement(vec_A);
    printVecElement(vec_B);
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

// 从大到小排序：
bool cmpGreatToLess(const int &v1, const int &v2)
{
    return v1 > v2;
}