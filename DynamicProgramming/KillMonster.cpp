#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//      给定 3 个参数，n，m，k ,
//      怪兽有N滴血，等着英雄来砍自己,
//      英雄每一次打击，都会让怪兽流失[0 - m]的血量
//      到底流失多少？每一次在[0 - m]上等概率的获得一个值
//      求 k 次打击之后，英雄把怪兽砍死的概率

