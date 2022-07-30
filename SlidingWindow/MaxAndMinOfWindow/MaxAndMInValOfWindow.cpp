#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <deque>

using namespace std;

//      有一个 整型数组arr 和一个 大小为w 的窗口。
//      从数组的 最左边 滑到最右边，窗口 每次向右边滑一个位置。
//      返回一个长度为 n - w + 1 的 数组res ,
//      res[i] 表示 每一个窗口状态 下的 最大值。

//      以数组为[4,3,5,4,3,3,6,7] , w=3为例。
//      第一个 窗口[4,3,5]的最大值为5,
//      第二个 窗口[3,5,4]的最大值为5,
//      第三个 窗口[5,4,3]的最大值为5，
//      第四个 窗口[4,3,3]的最大值为4.
//      第五个 窗口[3,3,6]的最大值为6.
//      第六个 窗口[3,6,7]的最大值为7.
//      所以最终返回 [5,5,5,4,6,7].

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
vector<int> maxValOfWindow_A(vector<int> vec, int w);
vector<int> minValOfWindow_A(vector<int> vec, int w);
vector<int> maxValOfWindow_B(vector<int> vec, int w);
vector<int> minValOfWindow_B(vector<int> vec, int w);

int main()
{
    vector<int> vec = generateRandomVec(0, 10, 10);
    printVecElement(vec);
    int w = generateRandomNum(1, vec.size());

    printf("vec数组的子数组在长度为 %d 的滑动窗口下的最大值数组为\n", w);
    vector<int> resMaxA = maxValOfWindow_A(vec, w);
    vector<int> resMaxB = maxValOfWindow_B(vec, w);
    printVecElement(resMaxA);
    printVecElement(resMaxB);

    printf("vec数组的子数组在长度为 %d 的滑动窗口下的最小值数组为\n", w);
    vector<int> resMinA = minValOfWindow_A(vec, w);
    vector<int> resMinB = minValOfWindow_B(vec, w);
    printVecElement(resMinA);
    printVecElement(resMinB);
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

// 双端队列：
// Time: O(N)
// Space: O(N)
vector<int> maxValOfWindow_A(vector<int> vec, int w)
{
    deque<int> deque;
    vector<int> res;

    for (int i = 0; i < vec.size(); i++)
    {
        while (!deque.empty() && vec[i] >= vec[deque.back()])
        {
            deque.pop_back();
        }

        deque.push_back(i);

        if (deque.front() == i - w)
        {
            deque.pop_front();
        }

        if (i >= w - 1)
        {
            res.push_back(vec[deque.front()]);
        }
    }
    return res;
}

// 双端队列：
// Time: O(N)
// Space: O(N)
vector<int> minValOfWindow_A(vector<int> vec, int w)
{
    deque<int> deque;
    vector<int> res;

    for (int i = 0; i < vec.size(); i++)
    {
        while (!deque.empty() && vec[i] <= vec[deque.back()])
        {
            deque.pop_back();
        }

        deque.push_back(i);

        if (deque.front() == i - w)
        {
            deque.pop_front();
        }

        if (i >= w - 1)
        {
            res.push_back(vec[deque.front()]);
        }
    }
    return res;
}

// 暴力循环：
// Time: O(N ^ 2)
// Space: O(1)
vector<int> maxValOfWindow_B(vector<int> vec, int w)
{
    vector<int> res(vec.size() - w + 1, 0);
    int index = 0;
    int left = 0, right = w - 1;
    
    while (right < vec.size())
    {
        int tem = INT_MIN;
        for (int i = left; i <= right; i++)
        {
            tem = max(tem, vec[i]);
        }
        res[index++] = tem;
        left++;
        right++;
    }
    return res;
}

// 暴力循环：
// Time: O(N ^ 2)
// Space: O(1)
vector<int> minValOfWindow_B(vector<int> vec, int w)
{
    vector<int> res(vec.size() - w + 1, 0);

    int index = 0;
    int left = 0, right = w - 1;
    
    while (right < vec.size())
    {
        int tem = INT_MAX;
        for (int i = left; i <= right; i++)
        {
            tem = min(tem, vec[i]);
        }
        res[index++] = tem;
        left++;
        right++;
    }
    return res;
}
