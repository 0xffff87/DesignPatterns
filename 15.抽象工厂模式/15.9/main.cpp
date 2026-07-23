#include "dataaccess.h"

int main()
{
    User* user = new User();
    Department* dept = new Department();

    // 不再 new 具体工厂，也不再写 if/switch
    // 由配置文件 DB + 类名字符串，通过“反射”创建
    IUser* iu = DataAccess::CreateUser();
    iu->Insert(user);
    iu->GetUser(1);

    IDepartment* id = DataAccess::CreateDepartment();
    id->Insert(dept);
    id->GetDepartment(1);

    delete user;
    delete dept;
    delete iu;
    delete id;
    return 0;
}
