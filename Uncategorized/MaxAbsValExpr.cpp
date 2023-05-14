#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>

using namespace std;

//      LeetCode 1131. 绝对值表达式的最大值

//      链接：https://leetcode.cn/problems/maximum-of-absolute-value-expression/

//      给你两个长度相等的整数数组，返回下面表达式的最大值：
//          |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
//      其中下标 i，j 满足 0 <= i, j < arr1.length。
//      示例 1：
//          输入：arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
//          输出：13
//      示例 2：
//          输入：arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
//          输出：20
//      提示：
//          2 <= arr1.length == arr2.length <= 40000
//          -10^6 <= arr1[i], arr2[i] <= 10^6

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int MaxAbsValExpr_A(vector<int> &arr1, vector<int> &arr2);
int MaxAbsValExpr_B(vector<int> &arr1, vector<int> &arr2);

int main()
{
    int n = generateRandomNum(2, 20);
    vector<int> arr1 = generateRandomVec(-10000, 10000, n);
    vector<int> arr2 = generateRandomVec(-10001, 10001, n);
    printf("arr1数组 元素为: ");
    printVecElement(arr1);
    printf("arr2数组 元素为: ");
    printVecElement(arr2);
    int ans = MaxAbsValExpr(arr1, arr2);
    printf("绝对值表达式的最大值为 %d。\n", ans);
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

int MaxAbsValExpr_A(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();

}

int MaxAbsValExpr_B(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();

}