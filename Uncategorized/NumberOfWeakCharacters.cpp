#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 1996. 游戏中弱角色的数量

//      链接：https://leetcode.cn/problems/the-number-of-weak-characters-in-the-game/

//      你正在参加一个多角色游戏，每个角色都有两个主要属性：攻击 和 防御 。
//      给你一个二维整数数组 properties ，
//      其中 properties[i] = [attacki, defensei] 表示游戏中第 i 个角色的属性。
//      如果存在一个其他角色的攻击和防御等级都严格高于该角色的攻击和防御等级，
//      则认为该角色为 弱角色 。
//      更正式地，如果认为角色 i 弱于 存在的另一个角色 j ，
//      那么 attackj > attacki 且 defensej > defensei 。
//      返回 弱角色 的数量。
//      示例 1：
//          输入：properties = [[5,5],[6,3],[3,6]]
//          输出：0
//          解释：不存在攻击和防御都严格高于其他角色的角色。
//      示例 2：
//          输入：properties = [[2,2],[3,3]]
//          输出：1
//          解释：第一个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
//      示例 3：
//          输入：properties = [[1,5],[10,4],[4,3]]
//          输出：1
//          解释：第三个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
//      提示：
//          2 <= properties.length <= 105
//          properties[i].length == 2
//          1 <= attacki, defensei <= 105

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

int NumberOfWeakCharacters(vector<vector<int>>& properties);

int main()
{
    int row = generateRandomNum(1, 50);
    vector<vector<int>> vec = generateRandom2DVec(1, 10, row, 2);
    printf("二维数组元素为：\n");
    print2DVecElement(vec);
    int ans_A = CountGoodRectangles(vec);
    printf("统计有 %d 个矩形能够切出边长最大 的正方形。\n", ans_A);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
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
    printf("\n");
}

vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col)
{
    srand((int)time(0));
    vector<vector<int>> vec;
    for (int i = 0; i < row; i++)
    {
        vector<int> tem;
        for (int j = 0; j < col; j++)
        {
            int v = (rand() % (high - low + 1)) + low;
            tem.push_back(v);
        }
        vec.push_back(tem);
    }
    return vec;
}

int NumberOfWeakCharacters(vector<vector<int>>& properties)
{

}