#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//      LeetCode 1109. 航班预订统计

//      链接：https://leetcode.cn/problems/corporate-flight-bookings/

//      这里有 n 个航班，它们分别从 1 到 n 进行编号。
//      有一份航班预订表 bookings，
//      表中第 i 条预订记录 bookings[i] = [firsti, lasti, seatsi]
//      意味着在从 firsti 到 lasti （包含 firsti 和 lasti ）的
//      每个航班 上预订了 seatsi 个座位。
//      请你返回一个长度为 n 的数组 answer，里面的元素是每个航班预定的座位总数。
//      示例 1：
//          输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
//          输出：[10,55,45,25,25]
//          解释：
//              航班编号        1   2   3   4   5
//              预订记录 1 ：   10  10
//              预订记录 2 ：       20  20
//              预订记录 3 ：       25  25  25  25
//              总座位数：      10  55  45  25  25
//              因此，answer = [10,55,45,25,25]
//      示例 2：
//          输入：bookings = [[1,2,10],[2,2,15]], n = 2
//          输出：[10,25]
//          解释：
//              航班编号        1   2
//              预订记录 1 ：   10  10
//              预订记录 2 ：       15
//              总座位数：      10  25
//              因此，answer = [10,25]
//      提示：
//          1 <= n <= 2 * 104
//          1 <= bookings.length <= 2 * 104
//          bookings[i].length == 3
//          1 <= firsti <= lasti <= n
//          1 <= seatsi <= 104

int generateRandomNum(int low, int high);
void printVecElement(vector<int> vec);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

vector<int> CorpFlightBookings(vector<vector<int>> &bookings, int n);

int main()
{
    int n = generateRandomNum(0, 30);
    int k = generateRandomNum(0, 50);
    vector<vector<int>> vec = generateRandom2DVec(0, 20, n, 3);
    printf("vec数组 元素为: ");
    print2DVecElement(vec);
    vector<int> ans = CorpFlightBookings(vec, k);
    printf("每个航班预定的座位总数为:");
    printVecElement(ans);
}

int generateRandomNum(int low, int high)
{
    srand((unsigned)time(NULL));
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

// 差分：
// Time: O(n)
// Space: O(n)
vector<int> CorpFlightBookings(vector<vector<int>> &bookings, int n)
{
    int l = bookings.size();
    vector<int> preSum(n + 2, 0);
    for (int i = 0; i < l; i++)
    {
        int start = bookings[i][0];
        int end = bookings[i][1];
        int seats = bookings[i][2];
        preSum[start] += seats;
        preSum[end + 1] -= seats;
    }
    for (int i = 1; i < preSum.size(); i++)
    {
        preSum[i] += preSum[i - 1];
    }
    vector<int> ans(preSum.begin() + 1, preSum.end() - 1);
    return ans;
}