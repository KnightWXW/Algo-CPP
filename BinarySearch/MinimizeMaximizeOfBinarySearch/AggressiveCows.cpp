#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      POJ-2456 Aggressive Cows(愤怒的牛)

//      链接：http://poj.org/problem?id=2456

//      农夫 John 建造了一座很长的畜栏，它包括 N (2 <= N <= 100,000)个隔间，
//      这些小隔间依次编号为X1,......,Xn (0 <= Xi <= 1,000,000,000).
//      但是，John 的 C (2 <= C <= N)头牛们并不喜欢这种布局，
//      而且几头牛放在一个隔间里，他们就要发生争斗。
//      为了不让牛互相伤害。John决定自己给牛分配隔间，
//      使任意两头牛之间的最小距离尽可能的大，
//      那么，这个最大的最小距离是什么呢
//      输入:
//          第1行：两个空格分隔的整数：N 和 C
//          第2行 ...... N+1行：第i+1行包含整数暂停位置 Xi
//      输出
//          第1行：一个整数：最大最小距离
//      样本输入:
//          5 3
//          1
//          2
//          8
//          4
//          9
//      样本输出:
//          3
//      输出详细信息：
//          FJ可以将他的3头奶牛放在1，4和8位置的畜栏中，从而产生最小距离为3。

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVec(vector<int> &vec);

int AggressiveCows(vector<int> &stalls, int c);
bool JudgeAggressiveCows(vector<int> &stalls, int c, int n, int curDif);

int main()
{
    int n = generateRandomNum(2, 20);
    vector<int> vec = generateRandomVec(1, 100, n);
    int c = generateRandomNum(2, n / 2 + 2);
    printVec(vec);
    int ans = AggressiveCows(vec, c);
    printf("共有 %d 头牛, 任意两头牛之间的最大的最小距离为 %d。", c, ans);
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

void printVec(vector<int> &vec)
{
    printf("vector的元素依次为: ");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// 二分查找：
// Time: O(NlogN)
// Space: O(1)
int AggressiveCows(vector<int> &stalls, int c)
{
    sort(stalls.begin(), stalls.end());
    int l = stalls.size();
    int left = 0;
    int right = stalls[l - 1];
    int ans = 0;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (JudgeAggressiveCows(stalls, c, l, mid))
        {
            ans = left;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

// 判断 以 curDif 为间距，是否能够 满足 条件：
bool JudgeAggressiveCows(vector<int> &stalls, int c, int n, int curDif)
{
    int cnt = 1;
    int curPos = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - curPos >= curDif)
        {
            cnt++;
            curPos = stalls[i];
        }
    }
    return cnt >= c;
}