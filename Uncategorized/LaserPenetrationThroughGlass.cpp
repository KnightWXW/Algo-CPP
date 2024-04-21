#include <stdio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//      Huawei: 激光穿透玻璃

//      材料实验室研究员正在研究激光在新型透光玻璃中传输时的衰减效果
//      给定多层上下叠放的介质，每层介质等长，并划分成若干个单位为1的格子。
//      planks记录了从上到下每层介质信息，
//      planks[i]代表第i层介质从左往右的透光玻璃放置情况，其中：
//          1：表示该位置有透光玻璃，可以穿过激光；每层至少包含了一块透光玻璃
//          0：表示该位置为不透光介质，无法穿透激光
//      研究员从最上方，任意位置垂直向下发射激光，
//      每次移动可以将任意一层介质左移(或右移)一个单位长度
//      请问研究员最少需要移动多少次介质，可以使激光穿过所有介质(即每层介质都要被穿过)
//      示例1：
//          输入：planks=[[1, 0, 0, 0, 0], [0, 0, 0, 0, 1], [1, 0, 0, 0, 0]]
//          输出：4
//      示例2：
//          输入：planks=[[0, 1, 0, 0, 0], [1, 0, 0, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 1, 1]]
//          输出：4
//      示例3：
//          输入：planks=[[1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1]]
//          输出：0
//      提示：
//          2 <= planks[i].size() <= 1000
//          2 <= planks.size() <= 1000
//          0 <= planks[i][j] <= 1

int LaserPenetrationThroughGlass_A(vector<vector<int>> planks);
int LaserPenetrationThroughGlass_B(vector<vector<int>> planks);
int DigitMaxDistance(vector<vector<int>> planks, vector<vector<int>> posArr);

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

int main()
{
    int row = generateRandomNum(1, 9);
    int col = generateRandomNum(1, 10);
    vector<vector<int>> vec = generateRandom2DVec(0, 1, row, col);
    print2DVecElement(vec);
    int ans_A = LaserPenetrationThroughGlass_A(vec);
    int ans_B = LaserPenetrationThroughGlass_B(vec);
    printf("研究员最少需要移动 %d 次介质，可以使激光穿过所有介质。\n", ans_A);
    printf("研究员最少需要移动 %d 次介质，可以使激光穿过所有介质。\n", ans_B);
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

int DigitMaxDistance(vector<vector<int>> planks, vector<vector<int>> posArr)
{
    int row = planks.size();
    int col = planks[0].size();
    int ans = INT_MAX;
    for (int j = 0; j < col; j++)
    {
        int colSum = 0;
        for (int i = 0; i < row; i++)
        {
            colSum += posArr[i][j];
        }
        ans = min(ans, colSum);
    }
    return ans;
}

int LaserPenetrationThroughGlass_A(vector<vector<int>> planks)
{
    int row = planks.size();
    int col = planks[0].size();
    int ans = INT_MAX;
    vector<vector<int>> posArr(row, vector<int>(col, col));
    for (int i = 0; i < row; i++)
    {
        int left = INT_MAX;
        for (int j = 0; j < col; j++)
        {
            if (planks[i][j] == 0)
            {
                posArr[i][j] = left == INT_MAX ? INT_MAX : j - left;
            }
            else
            {
                posArr[i][j] = 0;
                left = j;
            }
        }
        int right = INT_MAX;
        for (int j = col - 1; j >= 0; j--)
        {
            if (planks[i][j] == 0)
            {
                int tem = right == INT_MAX ? INT_MAX : right - j;
                posArr[i][j] = min(tem, posArr[i][j]);
            }
            else
            {
                posArr[i][j] = 0;
                right = j;
            }
        }
    }

    return DigitMaxDistance(planks, posArr);
}

int LaserPenetrationThroughGlass_B(vector<vector<int>> planks)
{
    int row = planks.size();
    int col = planks[0].size();
    int ans = INT_MAX;
    vector<vector<int>> posArr(row, vector<int>(col, col));
    for (int i = 0; i < row; i++)
    {
        int left = -1;
        for (int j = 0; j < col; j++)
        {
            if (planks[i][j] == 1)
            {
                left = j;
            }

            if (left != -1)
            {
                posArr[i][j] = j - left;
            }
        }
        int right = INT_MAX;
        for (int j = col - 1; j >= 0; j--)
        {
            if (planks[i][j] == 1)
            {
                right = j;
            }
            if (right != INT_MAX)
            {
                posArr[i][j] = min(posArr[i][j], right - j);
            }
        }
    }
    return DigitMaxDistance(planks, posArr);
}
