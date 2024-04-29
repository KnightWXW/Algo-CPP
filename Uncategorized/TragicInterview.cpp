#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

//      Huawei：悲剧的面试

//      小华十分向往华为公司，今天他来到华为公司面试。
//      总共有n位面试官，每位面试官都给小华打了一个综合分a[i],
//      但由于统计失误，各个面试官打的分数都错乱了，不知道谁打了多少分。
//      现在，给你打乱的 N 个分数，请你求出有多少种考官打分的情况。
//      在两种情况中，只要有一位考官打的分是不同的就认为这两种情况是不同的。
//      输入：
//          分数数组 arr  arr[1] [1, 1000000]
//      输出：
//          多少种不同情况(取模1000000007)
//      输入样例1：
//          1 2 3
//      输出样例1：
//          6

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int TragicInterview(vector<int> arr);

int main()
{
    int n = generateRandomNum(0, 20);
    vector<int> arr = generateRandomVec(1, 1000, n);
    printf("分数数组 元素为: ");
    printVecElement(arr);
    int ans = TragicInterview(arr);
    printf("有 %d 种考官打分的情况。", ans);。
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