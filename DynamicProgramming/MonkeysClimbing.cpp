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
int MonkeysClimbing_C(int n);
int MonkeysClimbing_D(int n);

int main()
{
    int num = generateRandomNum(0, 46);
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
