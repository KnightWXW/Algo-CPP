#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//      LeetCode 1725. 可以形成最大正方形的矩形数目

//      链接：https://leetcode.cn/problems/number-of-rectangles-that-can-form-the-largest-square/

//      给你一个数组 rectangles，
//      其中 rectangles[i] = [li, wi] 表示第 i 个矩形的长度为 li 、宽度为 wi 。
//      如果存在 k 同时满足 k <= li 和 k <= wi ，
//      就可以将第 i 个矩形切成边长为 k 的正方形。
//      例如，矩形 [4,6] 可以切成边长最大为 4 的正方形。
//      设 maxLen 为可以从矩形数组 rectangles 切分得到的 最大正方形 的边长。
//      请你统计有多少个矩形能够切出边长为 maxLen 的正方形，并返回矩形 数目 。
//      示例 1：
//          输入：rectangles = [[5,8],[3,9],[5,12],[16,5]]
//          输出：3
//          解释：能从每个矩形中切出的最大正方形边长分别是 [5,3,5,5] 。
//          最大正方形的边长为 5 ，可以由 3 个矩形切分得到。
//      示例 2：
//          输入：rectangles = [[2,3],[3,7],[4,3],[3,7]]
//          输出：3
//      提示：
//          1 <= rectangles.length <= 1000
//          rectangles[i].length == 2
//          1 <= li, wi <= 109
//          li != wi

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

int CountGoodRectangles(vector<vector<int>> &rectangles);

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

int CountGoodRectangles(vector<vector<int>> &rectangles)
{
    int l = rectangles.size();
    int ans = 0;
    vector<int> cnt(l, INT_MAX);
    int maxEdge = 0;
    for (int i = 0; i < l; i++)
    {
        cnt[i] = min(rectangles[i][0], rectangles[i][1]);
        maxEdge = max(maxEdge, cnt[i]);
    }
    for (int i = 0; i < l; i++)
    {
        if (cnt[i] == maxEdge)
        {
            ans++;
        }
    }
    return ans;
}