#pragma once
#include "factory.h"
#include "user.h"

using namespace std;

class DataAccess
{
public:
    static IUser *CreateUser()
    {
        IUser *result = nullptr;
        if (m_db == "Sqlserver")
        {
            result = new SqlserverUser();
        }
        else if (m_db == "Access")
        {
            result = new AccessUser();
        }
        return result;
    }
    static IDepartment *CreateDepartment()
    {
        IDepartment *result = nullptr;
        if (m_db == "Sqlserver")
        {
            result = new SqlserverDepartment();
        }
        else if (m_db == "Access")
        {
            result = new AccessDepartment();
        }
        return result;
    }
private:
    inline static const string m_db = "Sqlserver";
    // inline static constexpr string m_db = "Access";
};