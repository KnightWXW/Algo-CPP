#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

//      LeetCode 474. 一和零

//      链接：https://leetcode.cn/problems/ones-and-zeroes/

//      给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
//      请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
//      如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

 
//      示例 1：
//      输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
//      输出：4
//      解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
//      其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。

//      示例 2：
//      输入：strs = ["10", "0", "1"], m = 1, n = 1
//      输出：2
//      解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 

//      提示：
//          1 <= strs.length <= 600
//          1 <= strs[i].length <= 100
//          strs[i] 仅由 '0' 和 '1' 组成
//          1 <= m, n <= 100

int generateRandomNum(int low, int high);
void printVecElement(vector<string> vec);
vector<string> generateRandomVec(int len);
string generateRandomString(int n);

int main()
{
    int n = generateRandomNum(1,30);
    vector<string> vec = generateRandomVec(n);
    printVecElement(vec);
    // printf("暴力递归：%d\n", robbery_A(vec));
    // printf("记忆化搜索：%d\n", robbery_B(vec));
    // printf("动态规划：%d\n", robbery_C(vec));
    // printf("动态规划(空间优化)：%d\n", robbery_D(vec));
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void printVecElement(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%s ", vec[i]);
    }
    printf("\n");
}

vector<string> generateRandomVec(int len)
{
    srand((int)time(0));
    vector<string> vec;
    for (int i = 0; i < len; i++)
    {
        string v = generateRandomString(generateRandomNum(0, 10));
        vec.push_back(v);
    }
    return vec;
}

string generateRandomString(int n)
{
    string str = "";
    srand((int)time(0));
    char arr[] = "01";
    for (int i = 0; i < n; i++)
    {
        int index = rand() % (sizeof(arr) - 1);
        str += arr[index];
    }
    return str;
}

int zeroAndOne_A(vector<string>& strs, int m, int n){
    
}
