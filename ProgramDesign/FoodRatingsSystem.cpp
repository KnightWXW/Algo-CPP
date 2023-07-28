#include <stdio.h>
#include <vector>
#include <ctime>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

//      LeetCode 2353. 设计食物评分系统

//      链接：https://leetcode.cn/problems/design-a-food-rating-system/

//      设计一个支持下述操作的食物评分系统：
//      修改 系统中列出的某种食物的评分。
//      返回系统中某一类烹饪方式下评分最高的食物。
//      实现 FoodRatings 类：
//          FoodRatings(String[] foods, String[] cuisines, int[] ratings) 初始化系统。
//                  食物由 foods、cuisines 和 ratings 描述，长度均为 n 。
//                  foods[i] 是第 i 种食物的名字。
//                  cuisines[i] 是第 i 种食物的烹饪方式。
//                  ratings[i] 是第 i 种食物的最初评分。
//          void changeRating(String food, int newRating) ：
//                  修改名字为 food 的食物的评分。
//          String highestRated(String cuisine)：
//                  返回指定烹饪方式 cuisine 下评分最高的食物的名字。
//                  如果存在并列，返回 字典序较小 的名字。
//          注意，字符串 x 的字典序比字符串 y 更小的前提是：x 在字典中出现的位置在 y 之前，
//          也就是说，要么 x 是 y 的前缀，或者在满足 x[i] != y[i] 的第一个位置 i 处，
//          x[i] 在字母表中出现的位置在 y[i] 之前。
//      示例：
//          输入
//          ["FoodRatings", "highestRated", "highestRated", "changeRating",
//          "highestRated", "changeRating", "highestRated"]
//          [[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"],
//          ["korean", "japanese", "japanese", "greek", "japanese", "korean"],
//           [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16],
//          4 ["japanese"], ["ramen", 16], ["japanese"]]
//          输出
//          [null, "kimchi", "ramen", null, "sushi", null, "ramen"]
//          解释
//          FoodRatings foodRatings = new FoodRatings(["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]);
//          foodRatings.highestRated("korean"); // 返回 "kimchi"
//                                      // "kimchi" 是分数最高的韩式料理，评分为 9 。
//          foodRatings.highestRated("japanese"); // 返回 "ramen"
//                                      // "ramen" 是分数最高的日式料理，评分为 14 。
//          foodRatings.changeRating("sushi", 16); // "sushi" 现在评分变更为 16 。
//          foodRatings.highestRated("japanese"); // 返回 "sushi"
//                                      // "sushi" 是分数最高的日式料理，评分为 16 。
//          foodRatings.changeRating("ramen", 16); // "ramen" 现在评分变更为 16 。
//          foodRatings.highestRated("japanese"); // 返回 "ramen"
//                                      // "sushi" 和 "ramen" 的评分都是 16 。
//                                      // 但是，"ramen" 的字典序比 "sushi" 更小。
//      提示：
//          1 <= n <= 2 * 104
//          n == foods.length == cuisines.length == ratings.length
//          1 <= foods[i].length, cuisines[i].length <= 10
//          foods[i]、cuisines[i] 由小写英文字母组成
//          1 <= ratings[i] <= 108
//          foods 中的所有字符串 互不相同
//          在对 changeRating 的所有调用中，food 是系统中食物的名字。
//          在对 highestRated 的所有调用中，cuisine 是系统中 至少一种 食物的烹饪方式。
//          最多调用 changeRating 和 highestRated 总计 2 * 104 次

void printString(string s)
{
    printf("%s\n", s.c_str());
}

class FoodRatings_A
{
public:
    int size;
    unordered_map<string, pair<string, int>> foodMap; // K: foodName V: pair<cuisine, rate>

    FoodRatings_A(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        size = foods.size();
        for (int i = 0; i < size; i++)
        {
            foodMap[foods[i]] = make_pair(cuisines[i], ratings[i]);
        }
    }

    void changeRating(string food, int newRating)
    {
        foodMap[food].second = newRating;
    }

    string highestRated(string cuisine)
    {
        vector<pair<int, string>> arr;
        for (auto it = foodMap.begin(); it != foodMap.end(); it++)
        {
            if (it->second.first == cuisine)
            {
                pair<int, string> tem = make_pair(it->second.second, it->first);
                arr.push_back(tem);
            }
        }
        sort(arr.begin(), arr.end(), [](pair<int, string> a, pair<int, string> b)
             {
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first; });
        return arr[0].second;
    }
};

class FoodRatings_B
{
public:
    int size;
    unordered_map<string, pair<string, int>> foodMap; // K: foodName V: pair<cuisine, rate>
    unordered_map<string, set<pair<int, string>>> rateMap;  // K: cuisine V: set<pair<rate, foodName>>

    FoodRatings_B(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        size = foods.size();
        for (int i = 0; i < size; i++)
        {
            foodMap[foods[i]] = make_pair(cuisines[i], ratings[i]);
            rateMap[cuisines[i]].insert(make_pair(-ratings[i], foods[i]));
        }
    }

    void changeRating(string food, int newRating)
    {
        string preCuisine = foodMap[food].first;
        int preRate = foodMap[food].second;
        foodMap[food].second = newRating;
        rateMap[preCuisine].erase(make_pair(-preRate, food));
        rateMap[preCuisine].insert(make_pair(-newRating, food));
    }

    string highestRated(string cuisine)
    {
        return rateMap[cuisine].begin()->second;
    }
};

int main()
{
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};

    FoodRatings_B *foodRatings_A = new FoodRatings_B(foods, cuisines, ratings);
    string hA1 = foodRatings_A->highestRated("korean");
    printString(hA1);
    // 返回 "kimchi"
    // "kimchi" 是分数最高的韩式料理，评分为 9 。
    string hA2 = foodRatings_A->highestRated("japanese");
    printString(hA2);
    // 返回 "ramen"
    // "ramen" 是分数最高的日式料理，评分为 14 。
    foodRatings_A->changeRating("sushi", 16);
    // "sushi" 现在评分变更为 16 。
    string hA3 = foodRatings_A->highestRated("japanese");
    printString(hA3);
    // 返回 "sushi"
    // "sushi" 是分数最高的日式料理，评分为 16 。
    foodRatings_A->changeRating("ramen", 16);
    // "ramen" 现在评分变更为 16 。
    string hA4 = foodRatings_A->highestRated("japanese");
    printString(hA4);
    // 返回 "ramen"
    // "sushi" 和 "ramen" 的评分都是 16 。
    // 但是，"ramen" 的字典序比 "sushi" 更小。

    FoodRatings_B *foodRatings_B = new FoodRatings_B(foods, cuisines, ratings);
    string hB1 = foodRatings_B->highestRated("korean");
    printString(hB1);
    // 返回 "kimchi"
    // "kimchi" 是分数最高的韩式料理，评分为 9 。
    string hB2 = foodRatings_B->highestRated("japanese");
    printString(hB2);
    // 返回 "ramen"
    // "ramen" 是分数最高的日式料理，评分为 14 。
    foodRatings_B->changeRating("sushi", 16);
    // "sushi" 现在评分变更为 16 。
    string hB3 = foodRatings_B->highestRated("japanese");
    printString(hB3);
    // 返回 "sushi"
    // "sushi" 是分数最高的日式料理，评分为 16 。
    foodRatings_B->changeRating("ramen", 16);
    // "ramen" 现在评分变更为 16 。
    string hB4 = foodRatings_B->highestRated("japanese");
    printString(hB4);
    // 返回 "ramen"
    // "sushi" 和 "ramen" 的评分都是 16 。
    // 但是，"ramen" 的字典序比 "sushi" 更小。
}