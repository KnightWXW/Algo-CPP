



//      Huawei: 结果高效对比

//      终端某产品的车间工人位置视作一个矩阵，记为二维数组scores
//      scores[row][col]代表此位置工人的11月的完成件数
//      每位工人都想计算同行同列中一共多少人比自己完成件数多，
//      最后把计算结果记录在一个新的二维数组的对应位置上，返回该二维数组。
//      示例1：
//          输入：scores = [[10, 20], [30, 10]]
//          输出：[[2, 0], [0, 2]]


vector<vector<int>> EfficientComparisonOfResults(vector<vector<int>> scores);