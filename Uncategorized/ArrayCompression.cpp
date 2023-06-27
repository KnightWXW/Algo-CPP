



//      Huawei: 数组压缩

//      有一种数组压缩机制，将连续的重复数字以[数字，重复次数]的形式记录
//      例如，一维数组[1,1,28,28,28,3]压缩后形成二维数组[[1, 2],[28, 3],[3, 1]]
//      现有两个压缩后的二维数组numsA和numsB, 对其进行解压，加压后的两个新数组若长度不同
//      在较短的数组后补0, 使得两个数组长度相等。
//      然后将两个数组的相同索引的数字相乘，所得结果存入临时数组，最后将临时数组以同样的压缩机制进行压缩后返回。
//      注：解压后的数组长度可能跟大，请以高效的方式实现整个过程
//      示例一：
//          输入：
//          numsA = [[3, 3], [4, 1]]
//          numsA = [[2, 1], [4, 2], [3, 2]]
//          输出：[[6, 1], [12, 3], [0, 1]]
//      示例二：
//          输入：
//          numsA = [[2, 3], [5, 3], [1, 4], [3, 3]]
//          numsA = [[1, 2], [7, 1], [3, 8]]
//          输出：[[2, 2], [14, 1], [15, 3], [3, 4], [9, 1], [0, 1]]
//      示例三：
//          输入：
//          numsA = [[2, 1000000], [3, 1000000]]
//          numsA = [[7, 999999], [8, 2], [6, 999999]]
//          输出：[[14, 999999], [16, 1], [24, 1], [18, 999999]]
//      提醒：numsA或numsB的长度可能很大(如1000)，请使用高效的方式，以减少空间使用和计算量
//      提示：
//          1<= numsA.size(), numsB.size() <= 1000
//          1<= numsA[i][0], numsB[i][0] <= 10^4
//          1<= numsA[i][1], numsB[i][1] <= 10^6

vector<vector<int>> ArrayCompression(vector<vector<int>> numsA, vector<vector<int>> numsB);

