#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

//      牛客 K进制下一的个数

//      链接：https://www.nowcoder.com/questionTerminal/304aafab7eb04856bb1d91f95f215062

//      k进制下1∼m中数字1出现的次数，记作F(m,k)。
//      例如F(5,3)=5，因为三进制1∼5为 {1,2,10,11,12}，
//      数字1出现了5次。牛牛现在给你 k和 n，
//      他想知道F(m,k)≥n，最小的m是多少呢。请你返回m的值。
//      示例1
//          输入 5, 3
//          输出 5
//          说明 F(m,3)≥5，最小的m为5。
//      示例2
//          输入 10, 10
//          输出 17
//          说明 十进制下1∼9只有一个1，10,11,12,13,14,15,16,17，一共10个1。
//               所以最小的m=17。
//      备注: 1 ≤ n ≤ 10^9,2 ≤ k ≤ 10^9。

int generateRandomNum(int low, int high);

int DigitKBase(int k, int x);
int SumNumberOfTensInKBase_A(int k, int n);
int SumNumberOfTensInKBase_B(int k, int n);

int main()
{
    int k = generateRandomNum(1, 100);
    int n = generateRandomNum(1, 100);
    int ans_A = SumNumberOfTensInKBase_A(k, n);
    int ans_B = SumNumberOfTensInKBase_B(k, n);
    printf("%d 进制下 1 ∼ m 的元素中,\n F(%d, m) ≥ %d, 最小的 m 为：%d\n", k, k, n, ans_A);
    printf("%d 进制下 1 ∼ m 的元素中,\n F(%d, m) ≥ %d, 最小的 m 为：%d\n", k, k, n, ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

int DigitKBase(int k, int x)
{
    int ans = 0;
    while (x != 0)
    {
        ans += x % k == 1 ? 1 : 0;
        x /= k;
    }
    return ans;
}

// 暴力位运算：
// Time：O(N)
// Space：O(1)
int SumNumberOfTensInKBase_A(int k, int n)
{
    int cnt = 1;
    int x = 1;
    while (cnt < n)
    {
        cnt += DigitKBase(k, x);
        x++;
    }
    return x;
}

int DigitLength(int x, int k)
{
    int cnt = 0;
    while (x != 0)
    {
        cnt++;
        x /= k;
    }
    return cnt;
}

// 二分查找：
// Time：O(N)
// Space：O(1)
int SumNumberOfTensInKBase_B(int k, int n)
{
    int l = DigitLength(n, k);
    int left = 1;
    int right = pow(k, l + 1) + 1;
    int ans = right;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        int tem = 0;
        for (int i = 1; i <= mid; i++)
        {
            tem += DigitKBase(k, i);
        }
        if (tem >= n)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}