#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>

using namespace std;

//      LeetCode 907. 子数组的最小值之和

//      链接：https://leetcode.cn/problems/sum-of-subarray-minimums/

//      给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。

//      由于答案可能很大，因此 返回答案模 10^9 + 7 。

//      示例 1：
//      输入：arr = [3,1,2,4]
//      输出：17
//      解释：
//      子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。
//      最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。

//      示例 2：
//      输入：arr = [11,81,94,43,3]
//      输出：444

//      提示：
//          1 <= arr.length <= 3 * 104
//          1 <= arr[i] <= 3 * 104

void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);
int sumSubarrayMins_A(vector<int> arr);
vector<int> leftLessAndEqual_A(vector<int> arr, stack<int> stack);
vector<int> rightLess_A(vector<int> arr, stack<int> stack);
int sumSubarrayMins_B(vector<int> arr);
int sumSubarrayMins_C(vector<int> arr);
vector<int> leftLessAndEqual_C(vector<int> arr);
vector<int> rightLess_C(vector<int> arr);

int main()
{
    vector<int> arr = generateRandomVec(0, 5, 5);
    printVecElement(arr);
    printf("arr数组 的 子数组的 最小值之和 为%d\n", sumSubarrayMins_A(arr));
    printf("arr数组 的 子数组的 最小值之和 为%d\n", sumSubarrayMins_B(arr));
    printf("arr数组 的 子数组的 最小值之和 为%d\n", sumSubarrayMins_C(arr));
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

// 单调栈：
// Time: O(N)
// Space: O(N)
int sumSubarrayMins_A(vector<int> arr)
{
    if (arr.size() <= 0)
    {
        return 0;
    }
    int l = arr.size();
    stack<int> sk;
    vector<int> leftArr = leftLessAndEqual_A(arr, sk);
    // 清空栈：
    sk = stack<int>();
    vector<int> rightArr = rightLess_A(arr, sk);

    long ans = 0;
    for (int i = 0; i < l; i++)
    {
        long leftCnt = i - leftArr[i];
        long rightCnt = rightArr[i] - i;
        long sum = leftCnt * rightCnt * (long)arr[i];
        ans = (ans + sum) % 1000000007;
    }
    return (int)ans;
}

// 丛右向左 遍历
// 找到 arr数组 每个arr[i]元素 左侧 第一个 小于等于 arr[i] 的元素：
vector<int> leftLessAndEqual_A(vector<int> arr, stack<int> stack)
{
    int l = arr.size();
    vector<int> leftArr(l, 0);
    for (int i = l - 1; i >= 0; i--)
    {
        while (!stack.empty() && arr[stack.top()] >= arr[i])
        {
            int tem = stack.top();
            stack.pop();
            leftArr[tem] = i;
        }
        stack.push(i);
    }

    while (!stack.empty())
    {
        int tem = stack.top();
        stack.pop();
        leftArr[tem] = -1;
    }
    return leftArr;
}

// 从左向右遍历
// 找到 arr数组 每个arr[i]元素 右侧 第一个 大于 arr[i] 的元素：
vector<int> rightLess_A(vector<int> arr, stack<int> stack)
{
    int l = arr.size();
    vector<int> rightArr(l, 0);
    for (int i = 0; i < l; i++)
    {
        while (!stack.empty() && arr[stack.top()] > arr[i])
        {
            int tem = stack.top();
            stack.pop();
            rightArr[tem] = i;
        }
        stack.push(i);
    }

    while (!stack.empty())
    {
        int tem = stack.top();
        stack.pop();
        rightArr[tem] = l;
    }
    return rightArr;
}

// 单调栈(一次遍历操作)：
// Time: O(N)
// Space: O(N)
int sumSubarrayMins_B(vector<int> arr)
{
    if (arr.size() <= 0)
    {
        return 0;
    }
    int l = arr.size();
    stack<int> stack;
    long ans = 0;
    for (int i = 0; i < l; i++)
    {
        while (!stack.empty() && arr[stack.top()] > arr[i])
        {
            int tem = stack.top();
            stack.pop();
            long lessIndex = stack.empty() ? -1 : stack.top();
            long leftCnt = tem - lessIndex;
            long rightCnt = i - tem;
            long sum = rightCnt * leftCnt * arr[tem];
            ans = (ans + sum) % 1000000007;
        }
        stack.push(i);
    }

    while (!stack.empty())
    {
        int tem = stack.top();
        stack.pop();
        long lessIndex = stack.empty() ? -1 : stack.top();
        long leftCnt = tem - lessIndex;
        long rightCnt = l - tem;
        long sum = rightCnt * leftCnt * arr[tem];
        ans = (ans + sum) % 1000000007;
    }

    ans %= 1000000007;
    return (int)ans;
}

// 单调栈(手写栈)：
// Time: O(N)
// Space: O(N)
int sumSubarrayMins_C(vector<int> arr)
{
    if (arr.size() <= 0)
    {
        return 0;
    }
    int l = arr.size();
    vector<int> leftArr = leftLessAndEqual_C(arr);
    vector<int> rightArr = rightLess_C(arr);

    long ans = 0;
    for (int i = 0; i < l; i++)
    {
        long leftCnt = i - leftArr[i];
        long rightCnt = rightArr[i] - i;
        long sum = leftCnt * rightCnt * (long)arr[i];
        ans = (ans + sum) % 1000000007;
    }
    return (int)ans;
}

// 丛右向左 遍历
// 找到 arr数组 每个arr[i]元素 左侧 第一个 小于等于 arr[i] 的元素：
vector<int> leftLessAndEqual_C(vector<int> arr)
{
    int l = arr.size();
    vector<int> leftArr(l, 0);
    vector<int> stack(l, 0);
    int topIndex = -1;

    for (int i = l - 1; i >= 0; i--)
    {
        while (topIndex != -1 && arr[stack[topIndex]] >= arr[i])
        {
            leftArr[stack[topIndex--]] = i;
        }
        stack[++topIndex] = i;
    }

    while (topIndex != -1)
    {
        leftArr[stack[topIndex--]] = -1;
    }
    return leftArr;
}

// 从左向右遍历
// 找到 arr数组 每个arr[i]元素 右侧 第一个 大于 arr[i] 的元素：
vector<int> rightLess_C(vector<int> arr)
{
    int l = arr.size();
    vector<int> rightArr(l, 0);
    vector<int> stack(l, 0);
    int topIndex = -1;
    
    for (int i = 0; i < l; i++)
    {
        while (topIndex != -1 && arr[stack[topIndex]] > arr[i])
        {
            rightArr[stack[topIndex]] = i;
            topIndex--;
        }
        stack[++topIndex] = i;
    }

    while (topIndex != -1)
    {
        rightArr[stack[topIndex]] = l;
        topIndex--;
    }
    return rightArr;
}