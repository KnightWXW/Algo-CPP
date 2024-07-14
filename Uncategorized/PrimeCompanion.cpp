#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//      Huawei 素数伴侣

//          若两个正整数的和为素数，则这两个正整数称之为“素数伴侣”，如2和5、6和13，
//          它们能应用于通信加密。现在密码学会请你设计一个程序，
//          从已有的 N （ N 为偶数）个正整数中挑选出若干对组成“素数伴侣”，
//          挑选方案多种多样，例如有4个正整数：2，5，6，13，
//          如果将5和6分为一组中只能得到一组“素数伴侣”，
//          而将2和5、6和13编组将得到两组“素数伴侣”，
//          能组成“素数伴侣”最多的方案称为“最佳方案”，
//          当然密码学会希望你寻找出“最佳方案”。
//      输入:
//          有一个正偶数 n ，表示待挑选的自然数的个数。后面给出 n 个具体的数字。
//      输出:
//          输出一个整数 K ，表示你求得的“最佳方案”组成“素数伴侣”的对数。
//      数据范围：1 ≤ n ≤ 100  ，输入的数据大小满足 2 ≤ val ≤ 30000 
//      输入描述：
//          输入说明
//              1 输入一个正偶数 n
//              2 输入 n 个整数
//      输出描述：
//          求得的“最佳方案”组成“素数伴侣”的对数。
//      示例1
//          输入：4
//               2 5 6 13
//          输出：2
//      示例2
//          输入：2
//               3 6
//          输出：0

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int PrimeCompanion(vector<int> arr);

int main()
{
    int n = generateRandomNum(0, 30);
    vector<int> arr = generateRandomVec(0, 1, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    int ans = PrimeCompanion(arr);
    printf("能组成“素数伴侣”最多的方案为 %d", ans);
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

int PrimeCompanion(vector<int> arr)
{
    int l = arr.size();
    
}