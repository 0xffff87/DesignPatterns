#include "factory.h"

int main()
{
    User *user = new User();

    IFactory *factory = new SqlserverFactory();

    IUser *iu = factory->CreateUser();
    
    iu->Insert(user);
    iu->GetUser(1);

    delete factory;
    delete user;
    delete iu;
    return 0;
}