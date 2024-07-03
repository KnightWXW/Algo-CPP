#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

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

int SumNumberOfTensInKBase(int k, int n);

int main()
{
    int k = generateRandomNum(1, 100);
    int n = generateRandomNum(1, 100);
    int ans = SumNumberOfTensInKBase(k, n);
    printf("%d 进制下 1∼%d 的元素中,\n F(%d, m) ≥ %d，最小的 m 为：\n"; k, n, k, n, ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

int SumNumberOfTensInKBase(int k, int m)
{
    
}