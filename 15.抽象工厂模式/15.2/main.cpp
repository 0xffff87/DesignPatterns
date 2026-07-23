#include "user.h"

int main()
{
    User *user = new User();

    SqlserverUser *su = new SqlserverUser();

    su->Insert(user);
    su->GetUser(1);

    delete user;
    delete su;

    return 0;
}