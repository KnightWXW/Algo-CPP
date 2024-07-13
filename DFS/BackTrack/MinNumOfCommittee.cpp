#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//      Huawei: 最少Committer人数

//      某代码仓配置了文件修改评审的Commiter信息。
//      现有一个MR(Merge Request)修改了一批文件files,
//      files[i]表示允许评审文件i的Commiter编号列表。
//      每个文件需要至少一名Commiter评审才能合入，
//      每名Commiter可以评审多个文件
//      请计算并返回该MR最少需要多少名Commiter,才能完成所有修改文件的评审？
//      输入：
//          0 < files.length(文件个数) <= 12
//          0 < files[i].length <= 10,
//          0 <= files[i][j] < 10,
//          files[i]中元素(Commiter编号)各不相同
//      输出：
//          一个整数，表示最少Commiter个数
//      样例1：
//          输入：
//              [[0], [5, 2, 3], [0, 5]]
//          输出：
//              2
//      样例2：
//          输入：
//              [[1, 5, 2, 4], [2, 9, 1], [4], [9], [3, 1]]
//          输出：
//              3

void print2DVecElement(vector<vector<int>> vec);

int MinNumOfCommittee(vector<vector<int>> arr);

int main()
{
    vector<vector<int>> vec1 = {{0}, {5, 2, 3}, {0, 5}};
    printf("二维数组元素为：\n");
    print2DVecElement(vec1);
    int ans_A = MinNumOfCommittee(vec1);
    printf(" 最少Commiter个数为 %d。\n", ans_A);
    vector<vector<int>> vec2 = {{1, 5, 2, 4}, {2, 9, 1}, {4}, {9}, {3, 1}};
    printf("二维数组元素为：\n");
    print2DVecElement(vec2);
    int ans_B = MinNumOfCommittee(vec2);
    printf(" 最少Commiter个数为 %d。\n", ans_B);
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

int MinNumOfCommittee(vector<vector<int>> arr)
{
    int l = arr.size();
    set<int> s;
    int minCommitee = 13;
    int tem =
}

int DFSMinNumOfCommittee(vector<vector<int>> arr, int i, set<int> set, int *minCommitee)
{
    
}
