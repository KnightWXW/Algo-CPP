#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <deque>

using namespace std;

//      LeetCode 239. 滑动窗口最大值

//      链接：https://leetcode.cn/problems/sliding-window-maximum/

//      给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
//      你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
//      返回 滑动窗口中的最大值 。

//      示例 1：

//      输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//      输出：[3,3,5,5,6,7]
//      解释：
//      滑动窗口的位置                最大值
//      ---------------               -----
//      [1  3  -1] -3  5  3  6  7       3
//      1 [3  -1  -3] 5  3  6  7       3
//      1  3 [-1  -3  5] 3  6  7       5
//      1  3  -1 [-3  5  3] 6  7       5
//      1  3  -1  -3 [5  3  6] 7       6
//      1  3  -1  -3  5 [3  6  7]      7

//      示例 2：
//      输入：nums = [1], k = 1
//      输出：[1]
 
//      提示：

//          1 <= nums.length <= 105
//          -104 <= nums[i] <= 104
//          1 <= k <= nums.length

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
