#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 1094. 拼车

//      链接：https://leetcode.cn/problems/car-pooling/

//      车上最初有 capacity 个空座位。车 只能 向一个方向行驶（也就是说，不允许掉头或改变方向）
//      给定整数 capacity 和一个数组 trips ,
//      trip[i] = [numPassengersi, fromi, toi] 表示第 i 次旅行有 numPassengersi 乘客，
//      接他们和放他们的位置分别是 fromi 和 toi 。这些位置是从汽车的初始位置向东的公里数。
//      当且仅当你可以在所有给定的行程中接送所有乘客时，返回 true，否则请返回 false。
//      示例 1：
//          输入：trips = [[2,1,5],[3,3,7]], capacity = 4
//          输出：false
//      示例 2：
//          输入：trips = [[2,1,5],[3,3,7]], capacity = 5
//          输出：true
//      提示：
//          1 <= trips.length <= 1000
//          trips[i].length == 3
//          1 <= numPassengersi <= 100
//          0 <= fromi < toi <= 1000
//          1 <= capacity <= 105

void print2DVecElement(vector<vector<int>> vec);
void printBool(bool b);

bool CarPooling(vector<vector<int>> &trips, int capacity);

int main()
{
    vector<vector<int>> vec1 = {{2, 1, 5}, {3, 3, 7}};
    print2DVecElement(vec1);
    int capacity1 = 4;
    int ans1 = CarPooling(vec1, capacity1);
    printf("可以在所有给定的行程中接送所有乘客吗? \n");
    printBool(ans1);

    vector<vector<int>> vec2 = {{2, 1, 5}, {3, 3, 7}};
    print2DVecElement(vec2);
    int capacity2 = 5;
    int ans2 = CarPooling(vec2, capacity2);
    printf("可以在所有给定的行程中接送所有乘客吗? \n");
    printBool(ans2);
}

void print2DVecElement(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            printf("%d\t", vec[i][j]);
        }
        printf("\n");
    }
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

// 差分：
// Time：O(N)
// Space: O(N)
bool CarPooling(vector<vector<int>> &trips, int capacity)
{
    int l = trips.size();
    int maxDest = 0;
    for (int i = 0; i < l; i++)
    {
        maxDest = max(maxDest, trips[i][2]);
    }
    vector<int> help(maxDest + 1, 0);
    for (int i = 0; i < l; i++)
    {
        int num = trips[i][0];
        int start = trips[i][1];
        int end = trips[i][2];
        help[start] += num;
        help[end] -= num;
    }
    for (int i = 0; i < maxDest; i++)
    {
        help[i + 1] += help[i];
        if (help[i] > capacity)
        {
            return false;
        }
    }
    return true;
}