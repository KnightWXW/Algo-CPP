#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//      LeetCode 1497. 检查数组对是否可以被 k 整除

//      链接：https://leetcode.cn/problems/check-if-array-pairs-are-divisible-by-k/

//      给你一个整数数组 arr 和一个整数 k ，其中数组长度是偶数，值为 n 。
//      现在需要把数组恰好分成 n / 2 对，以使每对数字的和都能够被 k 整除。
//      如果存在这样的分法，请返回 True ；否则，返回 False 。
//      示例 1：
//          输入：arr = [1,2,3,4,5,10,6,7,8,9], k = 5
//          输出：true
//          解释：划分后的数字对为 (1,9),(2,8),(3,7),(4,6) 以及 (5,10) 。
//      示例 2：
//          输入：arr = [1,2,3,4,5,6], k = 7
//          输出：true
//          解释：划分后的数字对为 (1,6),(2,5) 以及 (3,4) 。
//      示例 3：
//          输入：arr = [1,2,3,4,5,6], k = 10
//          输出：false
//          解释：无法在将数组中的数字分为三对的同时满足每对数字和能够被 10 整除的条件。
//      提示：
//          arr.length == n
//          1 <= n <= 105
//          n 为偶数
//          -109 <= arr[i] <= 109
//          1 <= k <= 105

int generateRandomNum(int low, int high);
void printVecElement(vector<int> &vec);
vector<int> generateRandomVec(int low, int high, int len);
void printBool(bool b);

bool CanArrange(vector<int> &arr, int k);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(-100, 100, n);
    int k = generateRandomNum(1, 21);
    printf("k 为 %d 时, 数组元素为：\n", k);
    printVecElement(vec);
    bool ans = CanArrange(vec, k);
    printBool(ans);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

vector<int> generateRandomVec(int low, int high, int len)
{
    vector<int> vec;
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

void printVecElement(vector<int> &vec)
{
    printf("vector的元素依次为：");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

bool CanArrange(vector<int> &arr, int k)
{
    int l = arr.size();
    if((l & 1) == 1){
        return false;
    }
    unordered_map<int, int> hm;
    // arr[i] 可能 为负数，保证余数 [0, k−1]:
    for (int i = 0; i < l; i++)
    {
        hm[(arr[i] % k + k) % k]++;
    }

    for (auto it = hm.begin(); it != hm.end(); it++)
    {
        if (it->first != 0 && it->second != hm[k - it->first])
        {
            return false;
        }
    }
    // 余数为 0 的个数要为 偶数：
    if ((hm[0] & 1) == 1)
    {
        return false;
    }
    return true;
}