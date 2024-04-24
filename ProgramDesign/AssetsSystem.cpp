


//      Huawei: 简易资产管理系统

//      请设计一个资产管理系统，支持资产增加，借用，归还，统计的功能。
//      每个资产编号是全局唯一的。
//          AssetsSystem():系统初始化
//          AddAssets(int assetsId): 
//              向系统中增加一个编号为assetId的资产,
//                  如果资产已经存在,则直接返回0,否则增加成功,返回1;
//          BorrowAssets(int employeesId, int assetsId): 
//              员工employeesId借用资产assetsId;
//                  如果资产不存在，则直接返回-1;
//                  如果资产未被借用，且未被归还，则直接返回 0;
//                  如果资产未被借用，则成功借用并返回 1;
//          ReturnAssets(int assetsId): 
//              归还资产assetsId;
//                  如果资产不存在，则直接返回-1;
//                  如果资产未被任何人借用，则直接返回 0;
//                  否则成功归还，并返回 1;
//          StatAssets(int topNum): 
//              统计当前系统内有借用，且未被归还的借用人，并按如下规则返回：
//                  topNum个借用人的employeeId和未归还资产的数量：
//                      优先按未归还的数量从大到小排序；
//                      若数量相同，再按借用人的employeeId从小到大排序
//                      如果人数不足topNum,则按实际人数返回；
//                      如果实际人数为0，返回空数组[]
//      输入1：
//          AssetsSystem()
//          AddAssets(6789)
//          BorrowAssets(41336, 6789)
//          AddAssets(1234)
//          AddAssets(2345)
//          BorrowAssets(99527, 1234)
//          BorrowAssets(99527, 2345)
//          StatAssets(2)
//          ReturnAssets(2345)
//          StatAssets(2)
//          ReturnAssets(555)
//      输出1：
//          null
//          1
//          1
//          1
//          1
//          1
//          1
//          {{99527, 2}, {41336, 1}}
//          1
//          {{41336, 1}, {99527, 1}}
//          -1

