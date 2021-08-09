#include "usermodel.hpp"
#include "db.h"
#include <iostream>
using namespace std;

//User表增加方法
bool UserModel::insert(User &user)
{
    //组装sql语句
    char sql[1024] = {0};
    sprintf(sql, "insert into user(name, password, state) values('%s','%s','%s')",
            user.getName().c_str(), user.getPwd().c_str(), user.getState().c_str());
    //c_str,把str转成char*类型

    MySQL mysql;
    if (mysql.connect()) //连接成功
    {
        if (mysql.update(sql))
        {
            //获取插入成功的用户数据生成的主键id
            user.setId(mysql_insert_id(mysql.getConnection()));
            return true;
        }
    }
    return false;
};

User UserModel::query(int id)
{ //组装sql语句
    char sql[1024] = {0};
    sprintf(sql, "select * from user where id = %d",
            id);

    MySQL mysql;
    if (mysql.connect()) //连接成功
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row = mysql_fetch_row(res);
            if (row != nullptr)
            {
                User user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setPwd(row[2]);
                user.setState(row[3]);
                mysql_free_result(res);
                return user;
            }
        }
    }
    return User();
};

bool UserModel::updateState(User &user)
{
    //组装sql语句
    char sql[1024] = {0};
    sprintf(sql, "update user set state = '%s' where id = %d", user.getState().c_str(), user.getId());

    MySQL mysql;
    if (mysql.connect()) //连接成功
    {
        if (mysql.update(sql))
        {
            return true;
        }
    }
    return false;
}

void UserModel::resetState()
{ //组装sql语句
    char sql[1024] = "update user set state = 'offline' where state = 'online' ";

    MySQL mysql;
    if (mysql.connect()) //连接成功
    {
        mysql.update(sql);
    }
}
