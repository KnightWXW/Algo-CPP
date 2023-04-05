





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