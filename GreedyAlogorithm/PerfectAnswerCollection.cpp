#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

//      Huawei: 完美答案收集

//      考生在在线平台考试结束后，可以查看自己每道题的结果
//      (包括题干、选项、答案、回答正确或错误)，
//      针对回答错误的题目并没有给出正确答案。
//      这是需要综合多个考生的正确答案才能得到一份该试卷的完美答案
//      (即包含所有题目的正确答案)。
//      假设共有 questionCount 道题，题目编号从 1 到 questionCount。
//      现在给出每个考生的答对题目的编号，
//      格式如 1 3, 表示答对第1到3题;
//      格式如 9 9, 表示答对第9题;
//      输入：
//          题目的总数量 questionCount  ([1, 1024])
//          考生的总数量 peopleCount    ([1, 1024])
//          peopleCount行，每行两个整数 start end，1 <= start <= end <= questionCount
//      输出：
//          综合到完美答案的最少人值
//          如果无法综合到完美答案，输出 -1
//      示例1：
//          输入：
//              10
//              6
//              1  3
//              4  6
//              1  6
//              6  10
//              5  8
//              10 10
//          输出:
//              2

void print2DVecElement(vector<vector<int>> vec);

int PerfectAnswerCollection_A(int questionCount, vector<vector<int>> people);
int PerfectAnswerCollection_B(int questionCount, vector<vector<int>> people);

int main()
{
    int questionCount = 10;
    vector<vector<int>> people = {{1, 3}, {4, 6}, {1, 6}, {6, 10}, {5, 8}, {10, 10}};
    print2DVecElement(people);
    int ans_A = PerfectAnswerCollection_A(questionCount, people);
    printf("综合到完美答案的最少人值 为 %d 。\n", ans_A);
    int ans_B = PerfectAnswerCollection_A(questionCount, people);
    printf("综合到完美答案的最少人值 为 %d 。\n", ans_B);
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

// 贪心：
// Time: O(NlogN)
// Space: O(logN)
int PerfectAnswerCollection_A(int questionCount, vector<vector<int>> vec)
{
    vector<vector<int>> people(vec);
    int peopleCount = people.size();
    sort(people.begin(), people.end(), [&](vector<int> vec1, vector<int> vec2)
         {
        if(vec1[0] == vec2[0]){
            return vec1[1] > vec2[1];
        }
        return vec1[0] < vec2[0]; });
    int left = people[0][0];
    int right = people[0][1];
    if (left > 1)
    {
        return -1;
    }
    if (right == questionCount)
    {
        return 1;
    }
    int index = 1;
    int cnt = 1;
    int rightMax = right;
    while (index < peopleCount)
    {
        if (people[index][0] == people[index - 1][0])
        {
            index++;
            continue;
        }
        while (index < peopleCount && people[index][0] <= rightMax + 1)
        {
            if (right < people[index][1])
            {
                right = people[index][1];
            }
            index++;
        }
        if (right == rightMax)
        {
            return -1;
        }
        left = people[index][0];
        rightMax = right;
        cnt++;
        if (rightMax == questionCount)
        {
            return cnt;
        }
    }
    if (rightMax == questionCount)
    {
        return cnt;
    }
    return -1;
}

// 暴力循环
// Time: O(M * N)
// Space: O(1)
int PerfectAnswerCollection_B(int questionCount, vector<vector<int>> people)
{
    int cnt = 0;
    int indexQues = 1;
    while (indexQues <= questionCount)
    {
        int rightRange = 0;
        for (auto p : people)
        {
            if (p[0] <= indexQues && p[1] >= indexQues && p[1] > rightRange)
            {
                rightRange = p[1];
            }
            if (rightRange == 0)
            {
                return -1;
            }
            indexQues = rightRange + 1;
            cnt++;
        }
    }
    return cnt;
}