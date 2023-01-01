#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      LeetCode 329. 矩阵中的最长递增路径

//      链接：https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/

//      给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
//      对于每个单元格，你可以往上，下，左，右四个方向移动。
//      你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
//      示例 1：
//          输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
//          输出：4
//          解释：最长递增路径为 [1, 2, 6, 9]。
//      示例 2：
//          输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
//          输出：4
//          解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
//      示例 3：
//          输入：matrix = [[1]]
//          输出：1
//      提示：
//          m == matrix.length
//          n == matrix[i].length
//          1 <= m, n <= 200
//          0 <= matrix[i][j] <= 231 - 1

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);
int LongestIncreasingPath_A(vector<vector<int>> &matrix);
int DfsLongestIncreasingPath_A(vector<vector<int>> &matrix, int i, int j);
int LongestIncreasingPath_B(vector<vector<int>> &matrix);
int DfsLongestIncreasingPath_B(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &mem);

int main()
{
    int n = generateRandomNum(1, 10);
    vector<vector<int>> vec = generateRandom2DVec(0, 20, n, n);
    printf("原数组为：\n");
    print2DVecElement(vec);
    int ans_A = LongestIncreasingPath_A(vec);
    int ans_B = LongestIncreasingPath_B(vec);
    printf("(暴力递归)其中 最长递增路径 的长度 为 %d。\n", ans_A);
    printf("(记忆化搜索)其中 最长递增路径 的长度 为 %d。\n", ans_B);
}

int generateRandomNum(int low, int high)
{
    srand((int)time(0));
    return (rand() % (high - low + 1)) + low;
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

void print2DVecElement(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
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

// 暴力递归：
// Time: O(2^N)
// Space: O(1)
int LongestIncreasingPath_A(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int ans = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int tem = DfsLongestIncreasingPath_A(matrix, i, j);
            ans = max(ans, tem);
        }
    }
    return ans;
}

int DfsLongestIncreasingPath_A(vector<vector<int>> &matrix, int i, int j)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int leftPath = 0;
    int rightPath = 0;
    int topPath = 0;
    int bottomPath = 0;
    if (i > 0 && matrix[i - 1][j] > matrix[i][j])
    {
        leftPath = DfsLongestIncreasingPath_A(matrix, i - 1, j);
    }
    if (j > 0 && matrix[i][j - 1] > matrix[i][j])
    {
        topPath = DfsLongestIncreasingPath_A(matrix, i, j - 1);
    }
    if (i < row - 1 && matrix[i + 1][j] > matrix[i][j])
    {
        bottomPath = DfsLongestIncreasingPath_A(matrix, i + 1, j);
    }
    if (j < col - 1 && matrix[i][j + 1] > matrix[i][j])
    {
        rightPath = DfsLongestIncreasingPath_A(matrix, i, j + 1);
    }
    return max(max(leftPath, rightPath), max(topPath, bottomPath)) + 1;
}

// 记忆化搜索：
// Time: O(2^N)
// Space: O(M * N)
int LongestIncreasingPath_B(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> mem(row, vector<int>(col, 0));
    int ans = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int tem = DfsLongestIncreasingPath_B(matrix, i, j, mem);
            ans = max(ans, tem);
        }
    }
    return ans;
}

int DfsLongestIncreasingPath_B(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &mem)
{
    int row = matrix.size();
    int col = matrix[0].size();
    if (mem[i][j] > 0)
    {
        return mem[i][j];
    }
    int leftPath = 0;
    int rightPath = 0;
    int topPath = 0;
    int bottomPath = 0;
    if (i > 0 && matrix[i - 1][j] > matrix[i][j])
    {
        leftPath = DfsLongestIncreasingPath_B(matrix, i - 1, j, mem);
    }
    if (j > 0 && matrix[i][j - 1] > matrix[i][j])
    {
        topPath = DfsLongestIncreasingPath_B(matrix, i, j - 1, mem);
    }
    if (i < row - 1 && matrix[i + 1][j] > matrix[i][j])
    {
        bottomPath = DfsLongestIncreasingPath_B(matrix, i + 1, j, mem);
    }
    if (j < col - 1 && matrix[i][j + 1] > matrix[i][j])
    {
        rightPath = DfsLongestIncreasingPath_B(matrix, i, j + 1, mem);
    }
    int path = max(max(leftPath, rightPath), max(topPath, bottomPath)) + 1;
    mem[i][j] = path;
    return path;
}