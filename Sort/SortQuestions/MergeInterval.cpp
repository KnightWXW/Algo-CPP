#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//      LeetCode 56. 合并区间

//      链接1 ：https://leetcode.cn/problems/merge-intervals/
//      链接2 ：https://leetcode.cn/problems/SsGoHC/

//      以数组 intervals 表示若干个区间的集合，
//      其中单个区间为 intervals[i] = [starti, endi]。
//      请你合并所有重叠的区间，并返回 一个不重叠的区间数组，
//      该数组需恰好覆盖输入中的所有区间 。
//      示例 1：
//          输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//          输出：[[1,6],[8,10],[15,18]]
//          解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//      示例 2：
//          输入：intervals = [[1,4],[4,5]]
//          输出：[[1,5]]
//          解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
//      提示：
//          1 <= intervals.length <= 104
//          intervals[i].length == 2
//          0 <= starti <= endi <= 104

int generateRandomNum(int low, int high);
void print2DVecElement(vector<vector<int>> vec);
vector<vector<int>> generateRandom2DVec(int low, int high, int row, int col);

vector<vector<int>> MergeInterval(vector<vector<int>> &intervals);

int main()
{
    int n = generateRandomNum(0, 10);
    vector<vector<int>> arr = generateRandom2DVec(0, 1000, n, 2);
    printf("原数组为：\n");
    print2DVecElement(arr);
    vector<vector<int>> ans = MergeInterval(arr);
    printf("合并所有重叠的区间，返回 一个不重叠的区间数组：\n");
    print2DVecElement(ans);
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
        sort(tem.begin(), tem.end());
        vec.push_back(tem);
    }
    return vec;
}

vector<vector<int>> MergeInterval(vector<vector<int>> &intervals)
{
    int l = intervals.size();
    vector<vector<int>> ans;
    if(l == 0){
        return ans;
    }
    sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2){
        if(v1[0] == v2[0]){
            return v1[1] < v2[1];
        }
        return v1[0] < v2[0];
    });
    for (int i = 0; i < l; i++)
    {
        int left = intervals[i][0];
        int right = intervals[i][1];
        if(ans.size() == 0 || ans[ans.size() - 1][1] < left){
            ans.push_back({left, right});
        }else{
            ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], right);
        }
    }
    return ans;
}