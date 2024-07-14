#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      Huawei: 鱼缸难题

//      最近小华买了 N 条鱼，小华想买一些鱼缸去装他们，
//      商店有两种鱼缸：
//          第一种：每个鱼缸价格是C1元，可以装N1条鱼
//          第二种：每个鱼缸价格是C2元，可以装N2条鱼
//      小华想把所有的鱼都养在买的那些鱼缸里，
//      而且每个鱼缸都要装满鱼，
//      小华很难计算出两种鱼缸各买多少个最实惠(总花费最小)，
//      请你使用程序帮小华计算出最实惠方案。
//      输入：
//          共三行:
//              整数 N
//              C1 N1
//              C2 N2
//              所有数范围 [1, 2000000000]
//      输出：
//          每个用例占一行，对于不存在解的情况输出Failed
//          (即不能满足所有的鱼都装在鱼缸中且每个鱼缸都装满)
//          否则，请输出两个整数 M1, M2
//          (表示第一种鱼缸买 M1 个，第二种鱼缸买 M2 个，保证是唯一解)
//      输入样例1：
//          43
//          1 3
//          2 4
//      输出样例1：
//          13 1

int generateRandomNum(int low, int high);

vector<int> FishTankChallenge(int fishes, int c1, int n1, int c2, int n2);

int main()
{
    int fishes = generateRandomNum(1, 1000);
    int c1 = generateRandomNum(1, 100);
    int n1 = generateRandomNum(1, 101);
    int c2 = generateRandomNum(1, 102);
    int n2 = generateRandomNum(1, 103);
    vector<int> ans_A = FishTankChallenge(fishes, c1, n1, c2, n2);
    printf("fishes == %d, c1 == %d, n1 == %d, c2 == %d, n2 == %d, 最小花费为: [1]%d $ [2]%d\n", fishes, c1, n1, c2, n2, ans_A[0], ans_A[1]);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

// 数学：
// Time: O(N)
// Space: O(1)
vector<int> FishTankChallenge(int fishes, int c1, int n1, int c2, int n2)
{
    bool flag = true;
    int smallC = c1;
    int smallN = n1;
    int largeC = c2;
    int largeN = n2;
    if ((1.0 * c1 / n1) > (1.0 * c2 / n2))
    {
        flag = false;
        smallC = c2;
        smallN = n2;
        largeC = c1;
        largeN = n1;
    }
    int cnt = fishes / smallN;
    int a1 = cnt;
    int a2 = 0;
    int dif = fishes % smallN;
    for (int i = 0; i <= cnt; i++)
    {
        int tem = dif + smallN * i;
        if (tem % largeN == 0)
        {
            a1 -= i;
            a2 = tem / largeN;
            break;
        }
        if (i == cnt)
        {
            return {-1, -1};
        }
    }

    if (flag == true)
    {
        return {a1, a2};
    }
    else
    {
        return {a2, a1};
    }
}