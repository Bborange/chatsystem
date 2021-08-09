#ifndef GROUPMODEL_H
#define GROUPMODEL_H
#include <vector>
#include <string>
#include "group.hpp"
class GroupModel
{
public:
    //创建群组
    bool createGroup(Group &group);

    //加入群组
    void addGroup(int usrid, int groupid, string role);

    //查询用户所在群组信息
    vector<Group> quryGroups(int usrid);

    //根据指定的groupid查询用户id列表，除了usrid自己，主要群聊业务给群组其他成员发消息
    vector<int> queyGroupUsers(int usrid, int groupid);
};

#endif