#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

//      Huawei: 设计音乐播放器

//      设计一个音乐播放器MusicPlayer，完成音乐播放的基本功能：
//      创建一个 音乐播放器：输入参数为 歌曲数量
//      int AddMusic(int musicId): 加入一首歌曲：输入参数为 musicId,
//          规则如下：如果已经存在该 musicId, 返回-1, 否则如下：
//              如果音乐播放器容量未满，将 musicId 加入播放器中，返回0；
//              如果音乐播放器容量已满，则删除播放次数最少的一首歌曲，
//              再将 musicId 加入播放器中，返回删除的 musicId ；
//              删除规则如下：
//                  如果最少播放次数为 0, 则删除加入时间最早的歌曲；
//                  如果最少播放次数不为 0, 则删除首次播放时间最早的歌曲；
//      bool PlayMusic(int musicId): 播放一首歌曲：输入参数为 musicId,
//          如果播放器中不存在 musicId，返回false, 否则返回 true
//      bool DeleteMusic(int musicId): 删除一首歌曲： 输入参数为 musicId,
//         如果播放器中不存在 musicId，返回false, 否则删除该歌曲返回 true

void printBool(bool b)
{
    if (b == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

class MusicPlayer
{
public:
    int capacity;
    int time;
    // vector<tuple<musicId, addtime, playcnt, playtime>>
    vector<tuple<int, int, int, int>> vec;

    MusicPlayer(int num)
    {
        this->capacity = num;
        this->time = 0;
    }

    int FindMusic(int musicId)
    {
        int index = -1;
        for (int i = 0; i < vec.size(); i++)
        {
            if (get<0>(vec[i]) == musicId)
            {
                index = i;
            }
        }
        return index;
    }

    int AddMusic(int musicId)
    {
        int index = FindMusic(musicId);
        if (index != -1)
        {
            return -1;
        }
        this->time++;
        if (vec.size() < this->capacity)
        {
            vec.push_back(make_tuple(musicId, this->time, 0, 0));
            return 0;
        }
        else
        {
            sort(vec.begin(), vec.end(), [](tuple<int, int, int, int> t1, tuple<int, int, int, int> t2)
                 {
                if(get<2>(t1) == get<2>(t2)){
                    if(get<2>(t1) == 0){
                        return get<1>(t1) < get<1>(t2);
                    }else{
                        return get<3>(t1) < get<3>(t2);
                    }   
                }
                return get<2>(t1) < get<2>(t2); });
            int delId = get<0>(vec[0]);
            vec.erase(vec.begin());
            return delId;
        }
    }

    bool PlayMusic(int musicId)
    {
        int index = FindMusic(musicId);
        this->time++;
        if (index == -1)
        {
            return false;
        }
        else
        {
            get<2>(vec[index])++;
            if (get<2>(vec[index]) == 1)
            {
                get<3>(vec[index]) = this->time;
            }
            return true;
        }
    }

    bool DeleteMusic(int musicId)
    {
        int index = FindMusic(musicId);
        this->time++;
        if (index == -1)
        {
            return false;
        }
        else
        {
            vec.erase(vec.begin() + index);
            return true;
        }
    }
};

int main()
{
    int c1 = 3;
    MusicPlayer *musicPlayer = new MusicPlayer(c1);
    int a1 = musicPlayer->AddMusic(20);
    printf("添加结果为：%d\n", a1); // 0
    int a2 = musicPlayer->AddMusic(30);
    printf("添加结果为：%d\n", a2); // 0
    bool a3 = musicPlayer->PlayMusic(30);
    printf("播放结果为：\n");
    printBool(a3); // true
    int a4 = musicPlayer->AddMusic(10);
    printf("添加结果为：%d\n", a4); // 0
    int a5 = musicPlayer->AddMusic(50);
    printf("添加结果为：%d\n", a5); // 20
    bool a6 = musicPlayer->DeleteMusic(30);
    printf("删除结果为：\n");
    printBool(a6); // true
    bool a7 = musicPlayer->PlayMusic(30);
    printf("播放结果为：\n");
    printBool(a7); // false
    int a8 = musicPlayer->AddMusic(60);
    printf("添加结果为：%d\n", a8); // 0
}
