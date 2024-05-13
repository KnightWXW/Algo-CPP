#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

//      Huawei: 猴子爬山

//      一天一只顽猴想从山脚爬到山顶，途中经过一个有N个台阶的阶梯。
//      但是这个猴子有一个习惯，每一次只能跳 1 步或者 跳 3 步，
//      试问猴子通过这个阶梯有多少种不同的跳跃方式？
//      输入：
//          N(阶梯数值)
//      输出：
//          跳跃方式数值
//      输入样例1：
//          3
//      输出样例1：
//          2
//      输入样例2：
//          50
//      输出样例2：
//          122106097

int generateRandomNum(int low, int high);

int MonkeysClimbing_A(int n);
int MonkeysClimbing_B(int n);
int DFS_MonkeysClimbing_B(int n, vector<int> *arr);
int MonkeysClimbing_C(int n);
int MonkeysClimbing_D(int n);

int main()
{
    int num = generateRandomNum(0, 40);
    printf("台阶个数为：%d\n", num);
    printf("暴力递归：%d\n", MonkeysClimbing_A(num));
    printf("记忆化搜索：%d\n", MonkeysClimbing_B(num));
    printf("动态规划：%d\n", MonkeysClimbing_C(num));
    printf("动态规划（空间优化）：%d\n", MonkeysClimbing_D(num));
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// 暴力递归:
// Time：O(2 ^ N)
// Space：O(N)
int MonkeysClimbing_A(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 1;
    }
    else if (n == 3)
    {
        return 2;
    }
    else
    {
        return MonkeysClimbing_A(n - 1) + MonkeysClimbing_A(n - 3);
    }
}

// 记忆化搜索:
// Time：O(2 ^ N)
// Space：O(N)
int MonkeysClimbing_B(int n)
{
    vector<int> arr(n + 1, 0);
    int ans = DFS_MonkeysClimbing_B(n, &arr);
    return ans;
}

int DFS_MonkeysClimbing_B(int n, vector<int> *arr)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 1;
    }
    else if (n == 3)
    {
        return 2;
    }
    if (arr->at(n) > 0)
    {
        return arr->at(n);
    }
    int tem = DFS_MonkeysClimbing_B(n - 1, arr) + DFS_MonkeysClimbing_B(n - 3, arr);
    arr->at(n) = tem;
    return arr->at(n);
}

// 动态规划:
// Time：O(2 ^ N)
// Space：O(N)
int MonkeysClimbing_C(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 1;
    }
    else if (n == 3)
    {
        return 2;
    }
    vector<int> arr(n + 1, 0);
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 2;
    for (int i = 4; i <= n; i++)
    {
        arr[i] = arr[i - 3] + arr[i - 1];
    }
    return arr[n];
}

// 动态规划(空间优化):
// Time：O(2 ^ N)
// Space：O(1)
int MonkeysClimbing_D(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 1;
    }
    else if (n == 3)
    {
        return 2;
    }
    int a = 1;
    int b = 1;
    int c = 2;
    int d = 0;
    for (int i = 4; i <= n; i++)
    {
        d = a + c;
        a = b;
        b = c;
        c = d;
    }
    return c;
}