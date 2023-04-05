#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

//      LeetCode 355. 设计推特

//      链接：https://leetcode.cn/problems/design-twitter/

//      设计一个简化版的推特(Twitter)，可以让用户实现发送推文，
//      关注/取消关注其他用户，能够看见关注人（包括自己）的最近 10 条推文。

//      实现 Twitter 类：
//          Twitter() : 初始化简易版推特对象
//          void postTweet(int userId, int tweetId):
//                  根据给定的 tweetId 和 userId 创建一条新推文。
//                  每次调用此函数都会使用一个不同的 tweetId 。
//          List<Integer> getNewsFeed(int userId):
//                  检索当前用户新闻推送中最近  10 条推文的 ID 。
//                  新闻推送中的每一项都必须是由用户关注的人或者是用户自己发布的推文。
//                  推文必须 按照时间顺序由最近到最远排序 。
//          void follow(int followerId, int followeeId):
//                  ID 为 followerId 的用户开始关注 ID 为 followeeId 的用户。
//          void unfollow(int followerId, int followeeId):
//                  ID 为 followerId 的用户不再关注 ID 为 followeeId 的用户。
//      示例：
//          输入
//          ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
//          [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
//      输出
//          [null, null, [5], null, null, [6, 5], null, [5]]
//      解释
//          Twitter twitter = new Twitter();
//          twitter.postTweet(1, 5); // 用户 1 发送了一条新推文 (用户 id = 1, 推文 id = 5)
//          twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含一个 id 为 5 的推文
//          twitter.follow(1, 2);    // 用户 1 关注了用户 2
//          twitter.postTweet(2, 6); // 用户 2 发送了一个新推文 (推文 id = 6)
//          twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含两个推文，
//                                      id 分别为 -> [6, 5] 。推文 id 6 应当在推文 id 5 之前，
//                                      因为它是在 5 之后发送的
//          twitter.unfollow(1, 2);  // 用户 1 取消关注了用户 2
//          twitter.getNewsFeed(1);  // 用户 1 获取推文应当返回一个列表，其中包含一个 id 为 5 的推文。
//                                      因为用户 1 已经不再关注用户 2
//      提示：
//          1 <= userId, followerId, followeeId <= 500
//          0 <= tweetId <= 104
//          所有推特的 ID 都互不相同
//          postTweet、getNewsFeed、follow 和 unfollow 方法最多调用 3 * 104 次

void printVec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class Twitter
{
public:
    Twitter()
    {
    }

    map<int, unordered_set<int>> hmap; // 存储 每个 用户 及其 follower
    vector<pair<int, int>> vec = {};   // 存储 当前 推特列表信息

    void postTweet(int userId, int tweetId)
    {
        vec.push_back(make_pair(userId, tweetId));
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> ans = {};
        for (int i = vec.size() - 1; i >= 0; i--)
        {

            if (vec[i].first == userId || hmap[userId].count(vec[i].first) > 0)
            {
                ans.push_back(vec[i].second);
            }
            if (ans.size() >= 10)
            {
                break;
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        hmap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        hmap[followerId].erase(followeeId);
    }
};

int main()
{
    Twitter *twitter = new Twitter();
    twitter->postTweet(1, 5);
    vector<int> ans1 = twitter->getNewsFeed(1);
    printVec(ans1);
    twitter->follow(1, 2);
    twitter->postTweet(2, 6);
    vector<int> ans2 = twitter->getNewsFeed(1);
    printVec(ans2);
    twitter->unfollow(1, 2);
    vector<int> ans3 = twitter->getNewsFeed(1);
    printVec(ans3);
}