#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//      LeetCode 面试题 17.19. 消失的两个数字

//      链接：https://leetcode.cn/problems/missing-two-lcci/

//      给定一个数组，包含从 1 到 N 所有的整数，但其中缺了两个数字。
//      你能在 O(N) 时间内只用 O(1) 的空间找到它们吗？
//      以任意顺序返回这两个数字均可。
//      示例 1:
//          输入: [1]
//          输出: [2,3]
//      示例 2:
//          输入: [2,3]
//          输出: [1,4]
//      提示：
//          nums.length <= 30000

int generateRandomNum(int low, int high);
vector<int> generateRandomVecSeries(int len);
vector<int> shuffleVec(vector<int> vec);
void printVecElement(vector<int> vec);

vector<int> MissingTwo(vector<int>& nums);

int main()
{
    int n = generateRandomNum(2, 30);
    vector<int> vec = generateRandomVecSeries(n);
    vector<int> vecShuf = shuffleVec(vec);
    vector<int> arr;
    arr.assign(vecShuf.begin(), vecShuf.end() - 2);
    printVecElement(arr);
    vector<int> ans_A = MissingTwo(arr);
    printf("消失的两个数字为: %d\n");
    printVecElement(ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

vector<int> shuffleVec(vector<int> vec)
{
    srand((int)time(0));
    random_shuffle(vec.begin(), vec.end());
    return vec;
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

vector<int> generateRandomVecSeries(int len)
{
    vector<int> vec;
    for (int i = 0; i < len; i++)
    {
        vec.push_back(i + 1);
    }
    return vec;
}

vector<int> MissingTwo(vector<int>& nums)
{
    
}