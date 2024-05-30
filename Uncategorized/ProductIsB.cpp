#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//      LintCode 1322 乘积为 B

//      链接：https://www.lintcode.com/problem/1322/

//      给定一个长度为 n 的正整数序列A。A的长度是n。
//      你每次可以花费1的代价，将序列中某一个数加一或者减一。
//      你希望用最小的代价使得序列所有数的乘积为 B.
//      每次操作结束后 每个数都要是正整数
//      示例
//          输入:12
//              [1,3,5]
//          输出:1
//          解释:可以把A[2]减一变为4

int ProductIsB(vector<int> vec, int k);