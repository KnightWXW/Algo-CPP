#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

//      LeetCode 295. 数据流的中位数

//      链接：https://leetcode.cn/problems/find-median-from-data-stream/

//      中位数是有序整数列表中的中间值。
//      如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
//      例如 arr = [2,3,4] 的中位数是 3 。
//      例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
//      实现 MedianFinder 类:
//          MedianFinder()
//              初始化 MedianFinder 对象。
//          void addNum(int num)
//              将数据流中的整数 num 添加到数据结构中。
//          double findMedian()
//              返回到目前为止所有元素的中位数。
//              与实际答案相差 10-5 以内的答案将被接受。
//      示例 1：
//          输入
//              ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
//              [[], [1], [2], [], [3], []]
//          输出
//              [null, null, null, 1.5, null, 2.0]
//          解释
//              MedianFinder medianFinder = new MedianFinder();
//              medianFinder.addNum(1);    // arr = [1]
//              medianFinder.addNum(2);    // arr = [1, 2]
//              medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
//              medianFinder.addNum(3);    // arr[1, 2, 3]
//              medianFinder.findMedian(); // return 2.0
//      提示:
//          -105 <= num <= 105
//          在调用 findMedian 之前，数据结构中至少有一个元素
//          最多 5 * 104 次调用 addNum 和 findMedian

void printDouble(double d){
    printf("%f\n", d);
}

class MedianFinder
{
public:
    priority_queue<int, vector<int>, greater<int>> pqLeft; // 左侧：大根堆
    priority_queue<int, vector<int>, less<int>> pqRight;   // 右侧：小根堆

    void balancePriorityQueue()
    {
        if (abs((int)pqLeft.size() - (int)pqRight.size()) == 2)
        {
            if (pqLeft.size() > pqRight.size())
            {
                pqRight.push(pqLeft.top());
                pqLeft.pop();
            }
            else
            {
                pqLeft.push(pqRight.top());
                pqRight.pop();
            }
        }
    }

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (pqLeft.empty() || pqLeft.top() <= num)
        {
            pqLeft.push(num);
        }
        else
        {
            pqRight.push(num);
        }
        balancePriorityQueue();
    }

    double findMedian()
    {
        if (pqLeft.size() == pqRight.size())
        {
            return (double)(pqLeft.top() + pqRight.top()) / 2;
        }
        else
        {
            return pqLeft.size() > pqRight.size() ? pqLeft.top() : pqRight.top();
        }
    }
};

int main()
{
    MedianFinder *medianFinder = new MedianFinder();
    medianFinder->addNum(1);
    medianFinder->addNum(2);                  // arr = [1, 2]
    double mid1 = medianFinder->findMedian(); // 返回 1.5 ((1 + 2) / 2)
    printDouble(mid1);
    medianFinder->addNum(3);                  // arr[1, 2, 3]
    double mid2 = medianFinder->findMedian(); // return 2.0
    printDouble(mid2);
}