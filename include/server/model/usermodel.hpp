#ifndef USERMODEL_H
#define USERMOFEL_H

#include "user.hpp"

//User表的数据操作类
class UserModel
{
public:
    //User表的增加方法
    bool insert(User &user);
    //根据主键查询用户信息
    User query(int id);
    //更新用户状态信息
    bool updateState(User &User);
    //重置状态信息
    void resetState();
};

#endif