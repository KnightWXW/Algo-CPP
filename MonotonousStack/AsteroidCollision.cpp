#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <stack>

using namespace std;

//      LeetCode 735. 行星碰撞

//      链接：https://leetcode.cn/problems/asteroid-collision/

//      给定一个整数数组 asteroids，表示在同一行的行星。
//      对于数组中的每一个元素，其绝对值表示行星的大小，
//      正负表示行星的移动方向（正表示向右移动，负表示向左移动）。
//      每一颗行星以相同的速度移动。找出碰撞后剩下的所有行星。
//      碰撞规则：
//          两个行星相互碰撞，较小的行星会爆炸。
//          如果两颗行星大小相同，则两颗行星都会爆炸。
//          两颗移动方向相同的行星，永远不会发生碰撞。
//      示例 1：
//          输入：asteroids = [5,10,-5]
//          输出：[5,10]
//          解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。
//      示例 2：
//          输入：asteroids = [8,-8]
//          输出：[]
//          解释：8 和 -8 碰撞后，两者都发生爆炸。
//      示例 3：
//          输入：asteroids = [10,2,-5]
//          输出：[10]
//          解释：2 和 -5 发生碰撞后剩下 -5 。10 和 -5 发生碰撞后剩下 10 。
//      提示：
//          2 <= asteroids.length <= 104
//          -1000 <= asteroids[i] <= 1000
//          asteroids[i] != 0

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
vector<int> generateRandomVec(int low, int high, int len);

vector<int> AsteroidCollision(vector<int> &asteroids);

int main()
{
    int n = generateRandomNum(1, 20);
    vector<int> vec = generateRandomVec(-100, 100, n);
    printVecElement(vec);
    vector<int> ans = AsteroidCollision(vec);
    printf("碰撞后剩下的所有行星为： \n");
    printVecElement(ans);
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

vector<int> AsteroidCollision(vector<int> &asteroids)
{
    int l = asteroids.size();
    stack<int> s;
    for (int i = 0; i < l; i++)
    {
        int tem = asteroids[i];
        bool flag = true;
        while (flag && !s.empty() && s.top() > 0 && tem < 0)
        {
            int a = s.top();
            int b = -tem;
            if (a <= b)
            {
                s.pop();
            }
            if (a >= b)
            {
                flag = false;
            }
        }
        if (flag)
        {
            s.push(tem);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        int tem = s.top();
        s.pop();
        ans.push_back(tem);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}