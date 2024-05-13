#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;

//      LeetCode 447. 回旋镖的数量

//      链接：https://leetcode.cn/problems/number-of-boomerangs/

//      给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。
//      回旋镖 是由点 (i, j, k) 表示的元组 ，
//      其中 i 和 j 之间的欧式距离和 i 和 k 之间的欧式距离相等（需要考虑元组的顺序）。
//      返回平面上所有回旋镖的数量。
//      示例 1：
//          输入：points = [[0,0],[1,0],[2,0]]
//          输出：2
//          解释：两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
//      示例 2：
//          输入：points = [[1,1],[2,2],[3,3]]
//          输出：2
//      示例 3：
//          输入：points = [[1,1]]
//          输出：0
//      提示：
//          n == points.length
//          1 <= n <= 500
//          points[i].length == 2
//          -104 <= xi, yi <= 104
//          所有点都 互不相同

void print2DVecElement(vector<vector<int>> vec);

int JudgeDistance(vector<int> v1, vector<int> v2);
int NumberOfBoomerangs(vector<vector<int>> &points);

int main()
{
    vector<vector<int>> vec1 = {{0, 0}, {1, 0}, {2, 0}};
    print2DVecElement(vec1);
    int ans1 = NumberOfBoomerangs(vec1);
    printf("平面上所有回旋镖的数量 为 %d 。\n", ans1);
    vector<vector<int>> vec2 = {{1, 1}, {2, 2}, {3, 3}};
    print2DVecElement(vec2);
    int ans2 = NumberOfBoomerangs(vec2);
    printf("平面上所有回旋镖的数量 为 %d 。\n", ans2);
    vector<vector<int>> vec3 = {{1, 1}};
    print2DVecElement(vec3);
    int ans3 = NumberOfBoomerangs(vec3);
    printf("平面上所有回旋镖的数量 为 %d 。\n", ans3);
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
}

int JudgeDistance(vector<int> v1, vector<int> v2)
{
    return pow(v1[0] - v2[0], 2) + pow(v1[1] - v2[1], 2);
}

// 哈希表：
// Time: O(N)
// Space: O(N)
int NumberOfBoomerangs(vector<vector<int>> &points)
{
    int l = points.size();
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        unordered_map<int, int> hmap;
        for (int j = 0; j < l; j++)
        {
            if (i == j)
            {
                continue;
            }
            int dis = JudgeDistance(points[i], points[j]);
            hmap[dis]++;
        }
        for (auto it = hmap.begin(); it != hmap.end(); it++)
        {
            ans += it->second * (it->second - 1);
        }
    }
    return ans;
}