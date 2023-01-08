#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//      LeetCode: 48. 旋转图像

//      链接：https://leetcode.cn/problems/rotate-image

//      给定一个 n × n 的二维矩阵 matrix 表示一个图像。
//      请你将图像顺时针旋转 90 度。
//      你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。
//      请不要 使用另一个矩阵来旋转图像。
//      矩阵为正方形矩阵：n == matrix.length == matrix[i].length
//      输入：matrix = [[1,2,3],
//                     [4,5,6],
//                     [7,8,9]]                  
//      输出：[[7,4,1],
//             [8,5,2],
//             [9,6,3]]
//      输入：matrix = [[5,1,9,11],
//                      [2,4,8,10],
//                      [13,3,6,7],
//                      [15,14,12,16]]
//      输出：[[15,13,2,5],
//             [14,3,4,1],
//             [12,6,8,9],
//             [16,7,10,11]]

void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

void rotateImage(vector<vector<int>> &vec);
void rotate(vector<vector<int>> &vec, int x1, int y1, int x2, int y2);

int main(){
    vector<vector<int>> vec = generateRandom2DVec(0, 20, 3, 3);
    printf("数组翻转前为：\n");
    print2DVecElement(vec);
    rotateImage(vec);
    printf("数组翻转后为：\n");
    print2DVecElement(vec);
}

void print2DVecElement(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for(int j = 0 ; j < vec[0].size(); j++)
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
        for( int j = 0 ; j < col ; j++){
            int v = (rand() % (high - low + 1)) + low;
            tem.push_back(v);
        }
        vec.push_back(tem);
    }
    return vec;
}

// 按圈 原地旋转：
// Time: O(m * n)
// Space: O(m * n)
void rotateImage(vector<vector<int>> &vec){
    int x1 = 0, y1 = 0;
    int x2 = vec.size() - 1, y2 = vec[0].size() - 1;
    while(x1 < x2 && y1 < y2){
        rotate(vec, x1++, y1++, x2--, y2--);
    }
}

void rotate(vector<vector<int>> &vec, int x1, int y1, int x2, int y2)
{
    int tem = 0;
    for (int i = 0 ; i < y2 - y1 ; i++){
        tem = vec[x1][y1 + i];
        vec[x1][y1 + i] = vec[x2 - i][y1];;
        vec[x2 - i][y1] = vec[x2][y2 - i];
        vec[x2][y2 - i] = vec[x1 + i][y2];
        vec[x1 + i][y2] = tem;
    }
}