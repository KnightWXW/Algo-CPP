#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      蛇形打印矩阵

//      给定一个矩阵，将其 按蛇形 打印 出来。

//      例如： 输入矩阵为：
//                          [[1,2,3],
//                           [4,5,6],
//                           [7,8,9]]

//       蛇形打印顺序为：     [[1],
//                            [4,2],
//                            [3,5,7],
//                            [8,6],
//                            [9]    ]

void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);
vector<vector<int>> snakePrint(vector<vector<int>> vec);
void snackPrint_A(vector<vector<int>> vec, int &i, int &j, bool &flag, vector<vector<int>> &ans);
void snackPrint_B(vector<vector<int>> vec, int &i, int &j, bool &flag, vector<vector<int>> &ans);

int main()
{
    vector<vector<int>> vec = generateRandom2DVec(0, 20, 3, 3);
    printf("原数组为：\n");
    print2DVecElement(vec);
    vector<vector<int>> ans = snakePrint(vec);
    printf("蛇形打印数组为：\n");
    print2DVecElement(ans);
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

vector<vector<int>> snakePrint(vector<vector<int>> vec)
{
    int row = vec.size();
    int col = vec[0].size();

    vector<vector<int>> ans;
    int i = 0;
    int j = 0;
    bool flag = true;

    for (int k = 0; k < row + col - 1; k++)
    {
        if (flag == true)
        {
            vector<int> tem;
            while (j >= 0 && i < row)
            {
                tem.push_back(vec[i][j]);
                i++;
                j--;
            }
            ans.push_back(tem);

            flag = false;

            if (j == -1 && i < row)
            {
                j = 0;
            }
            else
            {
                j += 2;
                i = row - 1;
            }
        }
        else
        {
            if (flag == false)
            {
                vector<int> tem;
                while (i >= 0 && j < col)
                {
                    tem.push_back(vec[i][j]);
                    i--;
                    j++;
                }
                ans.push_back(tem);

                flag = true;

                if (i == -1 && j < col)
                {
                    i = 0;
                }
                else
                {
                    i += 2;
                    j = col - 1;
                }
            }
        }
    }

    return ans;
}

void snackPrint_A(vector<vector<int>> vec, int &i, int &j, bool &flag, vector<vector<int>> &ans)
{
    int row = vec.size();
    if (flag == true)
    {
        vector<int> tem;
        while (j >= 0 && i < row)
        {
            tem.push_back(vec[i][j]);
            i++;
            j--;
        }
        ans.push_back(tem);

        flag = false;

        if (j == -1 && i < row)
        {
            j = 0;
        }
        else
        {
            j += 2;
            i = row - 1;
        }
    }
}

// Time: O(M * N)
// Space: O(M * N)
void snackPrint_B(vector<vector<int>> vec, int &i, int &j, bool &flag, vector<vector<int>> &ans)
{
    int col = vec[0].size();
    if (flag == false)
    {
        vector<int> tem;
        while (i >= 0 && j < col)
        {
            tem.push_back(vec[i][j]);
            i--;
            j++;
        }
        ans.push_back(tem);

        flag = true;

        if (i == -1 && j < col)
        {
            i = 0;
        }
        else
        {
            i += 2;
            j = col - 1;
        }
    }
}