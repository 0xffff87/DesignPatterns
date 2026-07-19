#include "person.h"

using namespace std;

int main()
{
    Person* p = new Person("小菜");

    cout << "第一种装扮：" << endl;
    p->WearTShirts();
    p->WearBigTrouser();
    p->WearSneakers();
    p->Show();

    cout << endl;

    cout << "第二种装扮：" << endl;
    p->WearSuit();
    p->WearTie();
    p->WearLeatherShoes();
    p->Show();

    delete p;
    return 0;
}
