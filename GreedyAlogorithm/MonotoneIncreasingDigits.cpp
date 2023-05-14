#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 738. 单调递增的数字

//      链接：https://leetcode.cn/problems/monotone-increasing-digits/

//      当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，
//      我们称这个整数是单调递增的。
//      给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增。
//      示例 1:
//          输入: n = 10
//          输出: 9
//      示例 2:
//          输入: n = 1234
//          输出: 1234
//      示例 3:
//          输入: n = 332
//          输出: 299
//      提示:
//          0 <= n <= 109

int generateRandomNum(int low, int high);

int MonotoneIncreasingDigits(int n);

int main()
{
    int l = generateRandomNum(1, 20);
    vector<int> arr = generateRandomVec(0, 10, l);
    printf("arr数组 元素为: ");
    printVecElement(arr);
    printf("灌溉 长度为 %d 的整个花园的 最少水龙头数目 %d。\n", l - 1, minTaps(l - 1, arr));
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
}

int MonotoneIncreasingDigits(int n){
    
}