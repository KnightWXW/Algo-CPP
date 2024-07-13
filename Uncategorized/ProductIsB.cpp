#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      LintCode 1322 乘积为 B

//      链接：https://www.lintcode.com/problem/1322/

//      给定一个长度为 n 的正整数序列A。A的长度是n。
//      你每次可以花费1的代价，将序列中某一个数加一或者减一。
//      你希望用最小的代价使得序列所有数的乘积为 B.
//      每次操作结束后 每个数都要是正整数
//      示例
//          输入:12
//              [1,3,5]
//          输出:1
//          解释:可以把A[2]减一变为4

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int ProductIsB(vector<int> vec, int k);

int main()
{
    int n = generateRandomNum(0, 10);
    vector<int> arr = generateRandomVec(1, 10, n);
    int k = generateRandomNum(0, 100);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    int ans = ProductIsB(arr, k);
    printf("最小的代价 为: %d \n", ans);
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

int ProductIsB(vector<int> vec, int k)
{
    inr l = vec.size();
}