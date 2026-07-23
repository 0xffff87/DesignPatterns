#pragma once
#include "reflect.h"
#include "user.h"
#include "department.h"
#include <fstream>
#include <sstream>

using namespace std;

// 注册具体产品类，相当于 C# 程序集里已有这些类型可供反射创建
REGISTER_CLASS(SqlserverUser);
REGISTER_CLASS(AccessUser);
REGISTER_CLASS(SqlserverDepartment);
REGISTER_CLASS(AccessDepartment);

class DataAccess
{
public:
    // 对应 C#:
    // string className = AssemblyName + "." + db + "User";
    // return (IUser)Assembly.Load(AssemblyName).CreateInstance(className);
    static IUser* CreateUser()
    {
        string className = Db() + "User";
        return static_cast<IUser*>(Reflect::CreateInstance(className));
    }

    static IDepartment* CreateDepartment()
    {
        string className = Db() + "Department";
        return static_cast<IDepartment*>(Reflect::CreateInstance(className));
    }

private:
    // 对应 ConfigurationManager.AppSettings["DB"]，从配置文件读取
    static string Db()
    {
        static string db = LoadDbFromConfig();
        return db;
    }

    static string LoadDbFromConfig()
    {
        // 配置文件与本头文件同目录
        string path = string(__FILE__);
        size_t pos = path.find_last_of("/\\");
        if (pos != string::npos)
        {
            path = path.substr(0, pos + 1);
        }
        path += "appsettings.cfg";

        ifstream ifs(path);
        if (!ifs)
        {
            return "Sqlserver"; // 默认
        }

        string line;
        while (getline(ifs, line))
        {
            // 支持: DB=Sqlserver  或  DB = Access
            size_t eq = line.find('=');
            if (eq == string::npos)
            {
                continue;
            }
            string key = Trim(line.substr(0, eq));
            string value = Trim(line.substr(eq + 1));
            if (key == "DB")
            {
                return value;
            }
        }
        return "Sqlserver";
    }

    static string Trim(const string& s)
    {
        size_t b = s.find_first_not_of(" \t\r\n");
        if (b == string::npos)
        {
            return "";
        }
        size_t e = s.find_last_not_of(" \t\r\n");
        return s.substr(b, e - b + 1);
    }
};
