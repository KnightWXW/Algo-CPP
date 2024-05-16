#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>

using namespace std;

//      LeetCode 781. 森林中的兔子

//      链接：https://leetcode.cn/problems/rabbits-in-forest/

//      森林中有未知数量的兔子。
//      提问其中若干只兔子 "还有多少只兔子与你（指被提问的兔子）颜色相同?" ，
//      将答案收集到一个整数数组 answers 中，其中 answers[i] 是第 i 只兔子的回答。
//      给你数组 answers ，返回森林中兔子的最少数量。
//      示例 1：
//          输入：answers = [1,1,2]
//          输出：5
//          解释：
//              两只回答了 "1" 的兔子可能有相同的颜色，设为红色。
//              之后回答了 "2" 的兔子不会是红色，否则他们的回答会相互矛盾。
//              设回答了 "2" 的兔子为蓝色。
//              此外，森林中还应有另外 2 只蓝色兔子的回答没有包含在数组中。
//              因此森林中兔子的最少数量是 5 只：3 只回答的和 2 只没有回答的。
//      示例 2：
//          输入：answers = [10,10,10]
//          输出：11
//      提示：
//          1 <= answers.length <= 1000
//          0 <= answers[i] < 1000

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

int NumRabbits_A(vector<int> &answers);
int NumRabbits_B(vector<int> &answers);

int main()
{
    int n = generateRandomNum(0, 50);
    vector<int> answers = generateRandomVec(1, 5, n);
    printVecElement(answers);
    int ans_A = NumRabbits_A(answers);
    printf("鹅厂中企鹅的最少数量为 %d\n", ans_A);
    int ans_B = NumRabbits_A(answers);
    printf("鹅厂中企鹅的最少数量为 %d\n", ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

vector<int> generateRandomVec(int low, int high, int len)
{
    srand((int)time(0));
    vector<int> vec;
    for (int i = 0; i < len; i++)
    {
        int v = (rand() % (high - low + 1)) + low;
        vec.push_back(v);
    }
    return vec;
}

int NumRabbits_A(vector<int> &answers)
{

}

int NumRabbits_B(vector<int> &answers)
{
    
}