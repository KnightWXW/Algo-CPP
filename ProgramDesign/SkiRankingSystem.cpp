#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

//      Huawei: 滑雪排名成绩系统

//      滑雪运动员每一次滑雪成绩都有记录，用 duration 记录此次滑雪的时间，
//      用 userId 标识滑雪运动员，userId唯一，
//      每次滑雪记录duration可能会相同，需支持
//          (1) AddRecord(int userId, int duration)、
//          (2) GetTopAthletes(int num)、
//          (3) QueryTop3Record(int userId)三个功能。
//      (1) AddRecord(int userId, int duration)：添加滑雪运动员的滑雪记录，可以存储多个。
//      (2) GetTopAthletes(int num)：获取滑雪时间duration最短的前num个运动员的userId，
//          如果不同的运动员的滑雪时间duration相同，则以最先取得该时间的运动员在前。
//          当运动员不足num个时，按实际人数返回。
//      (3) QueryTop3Record(int userId)：查找某个滑雪运动员userId的前3项滑雪记录，按成绩升序返回
//          如果不足3次，则以实际次数为主。
//      输入：
//          [“SkiRankingSystem”,“addRecord”,“addRecord”,“getTopAthletes”,“queryTop3Record”]
//          [[],[1,10],[2,8],[3],[1]]
//      输出：
//          [null,null,null,[2,1],[10]]
//      输入：
//          [“SkiRankingSystem”,“addRecord”,“addRecord”,“addRecord”,“getTopAthletes”,
//          “addRecord”,“addRecord”,“addRecord”,“getTopAthletes”,“addRecord”,
//          “queryTop3Record”,“addRecord”,“queryTop3Record”]
//          [[],[20,8],[22,6],[20,6],[4],[33,5],[22,9],[31,4],[4],[20,8],[20],[20,6],[20]]
//      输出：
//          [null,null,null,null,[22,20],null,null,null,[31,33,22,20],null,[6,8,8],null,[6,6,8]]

constexpr int THREE = 3;

struct Score
{
    int score;
    int userId;
    int time;
    bool operator<(const Score &s) const
    {
        if (this->score != s.score)
        {
            return this->score < s.score;
        }
        return this->time < s.time;
    }
};

class SkiRankingSystem
{
private:
    int time = 0;
    unordered_map<int, multiset<Score>> scoreMap;
    
public:
    // 添加滑雪运动员的滑雪记录，可以存储多个。
    void AddRecord(int userId, int duration)
    {
        time++;
        if (scoreMap.find(userId) == scoreMap.end())
        {
            scoreMap[userId] = {{duration, time, userId}};
        }
        else
        {
            scoreMap[userId].insert({duration, time, userId});
        }
    }
    // 获取滑雪时间duration最短的前num个运动员的userId，
    // 如果不同的运动员的滑雪时间duration相同，则以最先取得该时间的运动员在前。
    // 当运动员不足num个时，按实际人数返回。
    vector<int> GetTopAthletes(int num)
    {
        vector<Score> scores;
        for (const auto &user : scoreMap)
        {
            scores.push_back({user.second.begin()->score, user.second.begin()->time, user.first});
        }
        sort(scores.begin(), scores.end());
        vector<int> ans;
        int cnt = 0;
        for (int i = 0; i < scores.size(); i++)
        {
            ans.push_back(scores[i].userId);
            cnt++;
            if (cnt >= num)
            {
                break;
            }
        }
        return ans;
    }
    // 查找某个滑雪运动员userId的前3项滑雪记录，按成绩升序返回
    // 如果不足3次，则以实际次数为主。
    vector<int> QueryTop3Record(int userId)
    {
        int cnt = 0;
        vector<int> ans;
        for (const auto &s : scoreMap[userId])
        {
            ans.push_back(s.score);
            cnt++;
            if (cnt >= THREE)
            {
                break;
            }
        }
        return ans;
    }
};

void printVecElement(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int main()
{
    SkiRankingSystem skiRankingSystem;
    skiRankingSystem.AddRecord(1, 100);
    skiRankingSystem.AddRecord(1, 100);
    skiRankingSystem.AddRecord(1, 10);
    skiRankingSystem.AddRecord(1, 6);
    skiRankingSystem.AddRecord(2, 6);
    skiRankingSystem.AddRecord(2, 100);
    skiRankingSystem.AddRecord(2, 13);
    skiRankingSystem.AddRecord(2, 8);
    skiRankingSystem.AddRecord(3, 6);
    skiRankingSystem.AddRecord(3, 5);
    skiRankingSystem.AddRecord(4, 8);
    skiRankingSystem.AddRecord(4, 8);
    skiRankingSystem.AddRecord(4, 10);
    skiRankingSystem.AddRecord(4, 10);
    skiRankingSystem.AddRecord(5, 5);
    skiRankingSystem.AddRecord(5, 10);
    vector<int> top1 = skiRankingSystem.QueryTop3Record(1);
    printf("第 %d 个滑雪运动员的前3项滑雪记录为:\n", 1);
    printVecElement(top1);
    vector<int> top2 = skiRankingSystem.QueryTop3Record(2);
    printf("第 %d 个滑雪运动员的前3项滑雪记录为:\n", 2);
    printVecElement(top2);
    vector<int> topUser = skiRankingSystem.GetTopAthletes(3);
    printf("滑雪时间最短的前 %d 运动员为：\n", 3);
    printVecElement(topUser);
}

// struct Score {
//     int score;
//     unsigned int time;
//     int userId;
//     bool operator <(const Score& user) const
//     {
//         if (this->score != user.score) {
//             return this->score < user.score;
//         }
//         return this->time < user.time;
//     }
//  };

// class SkiRankingSystem {
// public:
//     /*
//      * 运动员userID 的N次滑雪的成绩分别是 t1, t2, … tN (滑雪成绩有可能相同)，将滑雪成绩录入系统, 设计一个滑雪成绩排名系统。需完成以下功能：
//      */
//     void AddRecord(int userId, int duration) {
//         time++;
//         auto record = mapSkiRankingRecord.find(userId);
//         if (record != mapSkiRankingRecord.end()) {
//             mapSkiRankingRecord[userId].insert({ duration, time, userId });
//         } else {
//             mapSkiRankingRecord[userId] = {{ duration, time, userId }};
//         }
//     }
//     /* 2. 查询参赛运动员的TopN最N成绩排名，如果成绩相同，取较早加入系统的成绩， 如果不足N个，按实际个数输出。
//     */
//     vector<int> GetTopAthletes(int num)
//     {
//         vector<Score> score;
//         for(const auto& user : mapSkiRankingRecord) {
//             score.push_back({user.second.begin()->score, user.second.begin()->time, user.first});
//         }
//         std::sort(score.begin(), score.end());

//         vector<int> res;
//         int cnt = 0;
//         for(const auto&user : score) {
//             res.push_back(user.userId);
//             cnt ++;
//             if (cnt >= num) {
//                 break;
//             }
//         }
//         return res;
//     }
//     /* 3. 获取指定运动员的Top3成绩，如果成绩相同，取较早加入系统的成绩， 如果不足3个，按实际个数输出。
//     */
//     vector<int> QueryTop3Record(int userId)
//     {
//         vector<int> res;
//         int cnt = 0;
//         auto iter = mapSkiRankingRecord.find(userId);
//         if (iter == mapSkiRankingRecord.end()) {
//             return res;
//         }
//         for (const auto& score : iter->second) {
//             res.push_back(score.score);
//             cnt ++;
//             if (cnt >= TOP_N) {
//                 break;
//             }
//         }

//         return res;
//     }

// private:
//     unsigned int time = 0;
//     std::unordered_map<int, multiset<Score>> mapSkiRankingRecord;
// };
// //测试代码
// TEST(coding_sample_one, get)
// {
//     SkiRankingSystem solution;
//     solution.AddRecord(1, 100);
//     solution.AddRecord(1, 100);
//     solution.AddRecord(1, 10);
//     solution.AddRecord(1, 6);
//     solution.AddRecord(2, 6);
//     solution.AddRecord(2, 100);
//     solution.AddRecord(2, 13);
//     solution.AddRecord(2, 8);
//     solution.AddRecord(3, 6);
//     solution.AddRecord(3, 5);
//     solution.AddRecord(4, 8);
//     solution.AddRecord(4, 8);
//     solution.AddRecord(4, 10);
//     solution.AddRecord(4, 10);
//     solution.AddRecord(5, 5);
//     solution.AddRecord(5, 10);
//     vector<int> topN_1 = solution.QueryTop3Record(1);
//     ASSERT_EQ(topN_1.size(), 3);
//     vector<int> topN_2 = solution.QueryTop3Record(2);
//     ASSERT_EQ(topN_2.size(), 3);
//     vector<int> topUser = solution.GetTopAthletes(3);
//     ASSERT_EQ(topUser.size(), 3);
// }

//     }
// };