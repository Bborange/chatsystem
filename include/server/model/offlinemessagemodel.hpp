#ifndef OFFLINEMESSAGEMODEL_H
#define OFFLINEMESSAGEMODEL_H

#include<string>
#include<vector>
using namespace std;
//提供离线消息表的操作方法接口
class OfflineMsgModel
{
public:
//存储用户的离线消息
void insert(int userid,string msg);

//删除离线消息
void remove(int userid);

//查询用户的离线消息 可能有多个，所有用容器
vector<string> query(int userid);


};


#endif