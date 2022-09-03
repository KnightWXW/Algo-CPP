#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 64. 最小路径和

//      链接：https://leetcode.cn/problems/minimum-path-sum/

//      给定一个包含非负整数的 m x n 网格 grid ，
//      请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

//      说明：每次只能向下或者向右移动一步。

//      示例 1：
//      输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
//      输出：7
//      解释：因为路径 1→3→1→1→1 的总和最小。

//      示例 2：
//      输入：grid = [[1,2,3],[4,5,6]]
//      输出：12
 
//      提示：
//          m == grid.length
//          n == grid[i].length
//          1 <= m, n <= 200
//          0 <= grid[i][j] <= 100

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

int main()
{
    vector<vector<int>> vec = generateRandom2DVec(0, 9, 4, 6);
    print2DVecElement(vec);
    
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
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