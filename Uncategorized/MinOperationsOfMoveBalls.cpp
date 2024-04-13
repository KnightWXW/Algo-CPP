#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//      LeetCode 1769. 移动所有球到每个盒子所需的最小操作数

//      链接：https://leetcode.cn/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

//      有 n 个盒子。给你一个长度为 n 的二进制字符串 boxes ，
//      其中 boxes[i] 的值为 '0' 表示第 i 个盒子是 空 的，
//      而 boxes[i] 的值为 '1' 表示盒子里有 一个 小球。
//      在一步操作中，你可以将 一个 小球从某个盒子移动到一个与之相邻的盒子中。
//      第 i 个盒子和第 j 个盒子相邻需满足 abs(i - j) == 1 。
//      注意，操作执行后，某些盒子中可能会存在不止一个小球。
//      返回一个长度为 n 的数组 answer，
//      其中 answer[i] 是将所有小球移动到第 i 个盒子所需的 最小 操作数。
//      每个 answer[i] 都需要根据盒子的 初始状态 进行计算。
//      示例 1：
//          输入：boxes = "110"
//          输出：[1,1,3]
//          解释：每个盒子对应的最小操作数如下：
//              1) 第 1 个盒子：将一个小球从第 2 个盒子移动到第 1 个盒子，需要 1 步操作。
//              2) 第 2 个盒子：将一个小球从第 1 个盒子移动到第 2 个盒子，需要 1 步操作。
//              3) 第 3 个盒子：将一个小球从第 1 个盒子移动到第 3 个盒子，需要 2 步操作。将一个小球从第 2 个盒子移动到第 3 个盒子，需要 1 步操作。共计 3 步操作。
//      示例 2：
//          输入：boxes = "001011"
//          输出：[11,8,5,4,3,4]
//      提示：
//          n == boxes.length
//          1 <= n <= 2000
//          boxes[i] 为 '0' 或 '1'

int generateRandomNum(int low, int high);
string generateRandomString(int n);
void printString(string s);
void printVecElement(vector<int> vec);

vector<int> MinOperationsOfMoveBalls(string boxes);

int main()
{
    int n = generateRandomNum(0, 20);
    string str = generateRandomString(n);
    printf("盒子的 初始状态为：");
    printString(str);
    vector<int> ans_A = MinOperationsOfMoveBalls(str);
    printf("移动所有球到每个盒子所需的最小操作数为：\n");
    printStringVecElement(ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
    return (rand() % (high - low + 1)) + low;
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

void printString(string s)
{
    printf("%s\n", s.c_str());
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

vector<int> MinOperationsOfMoveBalls(string boxes)
{
    int l = boxes.size();
    vector<int> ans(l, 0);
    
}