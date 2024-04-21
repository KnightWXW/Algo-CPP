#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//      Huawei: 高铁选座

//      在某趟高铁列车上，每个车厢内共有rows行座位，
//      每行/列座位的序号和分布如图一所示
//          窗口      1A   1B   1C   通道   1D    1F
//          窗口      2A   2B   2C   通道   2D    2F
//          窗口      3A   3B   3C   通道   3D    3F
//      列表seats中保存了此车厢已被购买的座位。若列表为空，
//      表示该车厢内的座位还未被购买，且每个座位只能被购买一次
//      根据seats显示的售卖情况，
//      请问可以订到多少对(2张)同一行并且相邻的座位("C" 和 "D"跨过道不相邻)
//      座位编号 从 1 开始
//      示例1：
//          输入: rows = 4, seats = ["3A", "4F", "3B"]
//          输出：6
//      注意：
//          1 <= rows <= 10^9
//          0 <= seats.size() <= 10^5

void printString(string s);
void printStringVector(vector<string> vec);
int SeatSelectionOfHighSpeedRail(int rows, vector<string> seats);

int main()
{
    vector<string> vec_A = {"3A", "4F", "3B"};
    int rows_A = 4;
    int ans_A = SeatSelectionOfHighSpeedRail(rows_A, vec_A);
    printStringVector(vec_A);
    printf("订到 %d 对(2张)同一行并且相邻的座位.\n", ans_A);
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

void printStringVector(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printString(vec[i]);
    }
}

int SeatSelectionOfHighSpeedRail(int rows, vector<string> seats)
{
    int l = seats.size();
    int ans = 0;
    vector<int> abc(rows + 1, 0);
    vector<int> df(rows + 1, 0);
    for (int i = 0; i < l; i++)
    {
        string str = seats[i];
        string k = str.substr(0, str.size() - 1);
        int index = atoi(k.c_str());
        if (str[1] == 'D' || str[1] == 'F')
        {
            df[index] += 2;
        }
        else if (str[1] == 'A' || str[1] == 'C')
        {
            abc[index] += 1;
        }
        else if (str[1] == 'B')
        {
            abc[index] += 2;
        }
    }

    for (int i = 1; i <= rows; i++)
    {
        ans += abc[i] <= 1 ? 1 : 0;
        ans += df[i] <= 1 ? 1 : 0;
    }
    return ans;
}