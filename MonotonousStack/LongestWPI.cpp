#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//      LeetCode 1124. 表现良好的最长时间段

//      链接：https://leetcode.cn/problems/longest-well-performing-interval/

//      给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。
//      我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。
//      所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。
//      请你返回「表现良好时间段」的最大长度。
//      示例 1：
//          输入：hours = [9,9,6,0,6,6,9]
//          输出：3
//          解释：最长的表现良好时间段是 [9,9,6]。
//      示例 2：
//          输入：hours = [6,6,6]
//          输出：0
//      提示：
//          1 <= hours.length <= 104
//          0 <= hours[i] <= 16

int generateRandomNum(int low, int high);
vector<int> generateRandomVec(int low, int high, int len);
void printVecElement(vector<int> vec);

int LongestWPI(vector<int> &hours);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<int> arr = generateRandomVec(1, 20, n);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    int ans = LongestWPI(arr);
    printf("工作时间表中「表现良好时间段」的最大长度 %d。\n", ans);
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

// 单调栈 + 前缀和：
// Time: O(N)
// Space: O(N)
int LongestWPI(vector<int> &hours)
{
    int l = hours.size();
    vector<int> cnt(l, 0);
    vector<int> preSum(l + 1, 0);
    for (int i = 0; i < l; i++)
    {
        cnt[i] = hours[i] > 8 ? 1 : -1;
    }
    for (int i = 1; i <= l; i++)
    {
        preSum[i] = preSum[i - 1] + cnt[i - 1];
    }
    // 单调栈满足从栈底到栈顶的下标对应的 preSum 的元素单调递减
    // stack: 存储
    stack<int> stack;
    int ans = 0;
    for (int i = 0; i <= l; i++)
    {
        if (stack.empty() || preSum[i] < preSum[stack.top()])
        {
            stack.push(i);
        }
    }

    for (int i = l; i >= 0; i--)
    {
        while (!stack.empty() && preSum[i] > preSum[stack.top()])
        {
            ans = max(ans, i - stack.top());
            stack.pop();
        }
    }
    return ans;
}