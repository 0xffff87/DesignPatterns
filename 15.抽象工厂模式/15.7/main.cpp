#include "factory.h"
#include "dataaccess.h"

int main()
{
    User *user = new User();
    Department *dept = new Department();

    //IFactory *factory = new SqlserverFactory();
    IFactory *factory = new AccessFactory();

    IUser *iu = DataAccess::CreateUser();

    iu->Insert(user);
    iu->GetUser(1);

    IDepartment *id = DataAccess::CreateDepartment();
    id->Insert(dept);
    id->GetDepartment(1);

    delete factory;
    delete user;
    delete dept;
    delete iu;
    delete id;

    return 0;
}