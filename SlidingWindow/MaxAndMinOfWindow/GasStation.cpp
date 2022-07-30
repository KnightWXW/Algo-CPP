#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <deque>

using namespace std;

//      LeetCode 134. 加油站

//      链接：https://leetcode.cn/problems/gas-station/

//      在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
//      你有一辆油箱容量无限的的汽车，
//      从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。
//      你从其中的一个加油站出发，开始时油箱为空。
//      给定两个整数数组 gas 和 cost ，，
//      请返回一个bool数组 ans：若从序号为 i 的加油站出发时，如果你可以绕环路行驶一周，
//      ans[i] = true,否则 返回 false。

//      示例 1:
//      输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
//      输出: [false, false, false, true, false]
//      解释:
//      从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
//      开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
//      开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
//      开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
//      开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
//      开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
//      因此，3 可为起始索引。

//      示例 2:
//      输入: gas = [2,3,4], cost = [3,4,3]
//      输出: [false, false, false]
//      解释:
//      你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
//      我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
//      开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
//      开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
//      你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
//      因此，无论怎样，你都不可能绕环路行驶一周。

//      提示:

//      gas.length == n
//      cost.length == n
//      1 <= n <= 105
//      0 <= gas[i], cost[i] <= 104

void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
vector<int> gasStation_A(vector<int> gas, vector<int> cost);

int main()
{
    vector<int> gas = generateRandomVec(1, 9, 5);
    vector<int> cost = generateRandomVec(1, 8, 5);

    printVecElement(gas);
    printVecElement(cost);
    vector<int> flag_A = gasStation_A(gas, cost);
    printVecElement(flag_A);
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

// 双端队列:
// Time: O(N)
// Space: O(N)
vector<int> gasStation_A(vector<int> gas, vector<int> cost)
{
    int l = gas.size();
    vector<int> arr(2 * l, 0);

    // 构建 前缀和数组 arr:
    for (int i = 0; i < 2 * l; i++)
    {
        arr[i] = gas[i % l] - cost[i % l];
    }
    for (int i = 1; i < 2 * l; i++)
    {
        arr[i] += arr[i - 1];
    }

    deque<int> deque;
    vector<int> flag;

    // 构建arr[0 : l]的 滑动窗口大小为 l 的 最小值结构：
    for (int i = 0; i < l; i++)
    {
        while (!deque.empty() && arr[deque.back()] >= arr[i])
        {
            deque.pop_back();
        }
        deque.push_back(i);
    }

    // offset: 记录 arr 每个滑动窗口 之前 一个 元素 的大小，用来 计算 最小值：
    // i : 记录 offset 的 索引位置： 
    // j : 记录 滑动窗口 末尾元素 所在的 索引位置：
    for (int offset = 0, i = 0, j = l; j < 2 * l; offset = arr[i++], j++)
    {
        if (arr[deque.front()] - offset >= 0)
        {
            flag.push_back(1);
        }
        else
        {
            flag.push_back(0);
        }

        if (deque.front() == i)
        {
            deque.pop_front();
        }

        while (!deque.empty() && arr[deque.back()] >= arr[j])
        {
            deque.pop_back();
        }
        deque.push_back(j);
    }
    return flag;
}