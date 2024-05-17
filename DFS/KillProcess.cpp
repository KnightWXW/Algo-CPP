#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//      LeetCode 582 杀死进程

//      链接：https://leetcode-cn.com/problems/kill-process

//      给 n 个进程，每个进程都有一个独一无二的 PID （进程编号）和它的 PPID （父进程编号）。
//      每一个进程只有一个父进程，但是每个进程可能会有一个或者多个孩子进程。
//      它们形成的关系就像一个树状结构。
//      只有一个进程的 PPID 是 0 ，意味着这个进程没有父进程。
//      所有的 PID 都会是唯一的正整数。
//      我们用两个序列来表示这些进程，第一个序列包含所有进程的 PID ，
//      第二个序列包含所有进程对应的 PPID。
//      现在给定这两个序列和一个 PID 表示你要杀死的进程，
//      函数返回一个 PID 序列，表示因为杀这个进程而导致的所有被杀掉的进程的编号。
//      当一个进程被杀掉的时候，它所有的孩子进程和后代进程都要被杀掉。
//      你可以以任意顺序排列返回的 PID 序列。
//      示例 1:
//          输入:
//          pid =  [1, 3, 10, 5]
//          ppid = [3, 0, 5, 3]
//          kill = 5
//          输出: [5,10]
//          解释:
//                  3
//                /   \
//               1     5
//                    /
//                   10
//          杀掉进程 5 ，同时它的后代进程 10 也被杀掉。
//      注意:
//          被杀掉的进程编号一定在 PID 序列中。
//          n >= 1.

void printVecElement(vector<int> vec);

vector<int> KillProcess_A(vector<int> &pid, vector<int> &ppid, int kill);
vector<int> KillProcess_B(vector<int> &pid, vector<int> &ppid, int kill);
void KillProcess_DFS_B(unordered_map<int, vector<int>> &hmap, int cur, vector<int> &ans);

int main()
{
    vector<int> pid1 = {1, 3, 10, 5};
    vector<int> ppid1 = {3, 0, 5, 3};
    int kill1 = 5;
    printVecElement(pid1);
    printVecElement(ppid1);
    vector<int> ans_A1 = KillProcess_A(pid1, ppid1, kill1);
    printf("进程 %d 被杀掉的时候, 杀掉的进程为: \n", kill1);
    printVecElement(ans_A1);
    vector<int> ans_B1 = KillProcess_B(pid1, ppid1, kill1);
    printf("进程 %d 被杀掉的时候, 杀掉的进程为: \n", kill1);
    printVecElement(ans_B1);

    vector<int> pid2 = {1, 5, 6, 8, 7, 2, 3, 4};
    vector<int> ppid2 = {8, 3, 3, 0, 4, 8, 1, 1};
    int kill2 = 1;
    printVecElement(pid2);
    printVecElement(ppid2);
    vector<int> ans_A2 = KillProcess_A(pid2, ppid2, kill2);
    printf("进程 %d 被杀掉的时候, 杀掉的进程为: \n", kill2);
    printVecElement(ans_A2);
    vector<int> ans_B2 = KillProcess_B(pid2, ppid2, kill2);
    printf("进程 %d 被杀掉的时候, 杀掉的进程为: \n", kill2);
    printVecElement(ans_B2);
}

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

// BFS + 哈希：
// Time: O(N)
// Space: O(N)
vector<int> KillProcess_A(vector<int> &pid, vector<int> &ppid, int kill)
{
    int l = pid.size();
    vector<int> ans;
    unordered_map<int, vector<int>> hmap;
    for (int i = 0; i < l; i++)
    {
        if (ppid[i] != 0)
        {
            hmap[ppid[i]].push_back(pid[i]);
        }
    }
    ans.push_back(kill);
    for (int i = 0; i < ans.size(); i++)
    {
        if (hmap.find(ans[i]) != hmap.end())
        {
            for (int j = 0; j < hmap[ans[i]].size(); j++)
            {
                ans.push_back(hmap[ans[i]][j]);
            }
        }
    }
    return ans;
}

// DFS + 哈希：
// Time: O(N)
// Space: O(N)
vector<int> KillProcess_B(vector<int> &pid, vector<int> &ppid, int kill)
{
    int l = pid.size();
    vector<int> ans;
    int cur = kill;
    unordered_map<int, vector<int>> hmap;
    for (int i = 0; i < l; i++)
    {
        if (ppid[i] != 0)
        {
            hmap[ppid[i]].push_back(pid[i]);
        }
    }
    KillProcess_DFS_B(hmap, cur, ans);
    return ans;
}

void KillProcess_DFS_B(unordered_map<int, vector<int>> &hmap, int cur, vector<int> &ans)
{
    ans.push_back(cur);
    for (int i = 0; i < hmap[cur].size(); i++)
    {
        KillProcess_DFS_B(hmap, hmap[cur][i], ans);
    }
    return;
}