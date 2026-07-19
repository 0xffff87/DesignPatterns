#include "resume.h"

using namespace std;

int main()
{
    Resume* a = new Resume("大鸟");
    a->SetPersonalInfo("男", 29);
    a->SetWorkExperience("2020-2022", "公司A");

    Resume* b = new Resume("大鸟");
    b->SetPersonalInfo("男", 29);
    b->SetWorkExperience("2020-2022", "公司A");

    Resume* c = new Resume("大鸟");
    c->SetPersonalInfo("男", 29);
    c->SetWorkExperience("2020-2022", "公司A");

    a->Display();
    b->Display();
    c->Display();

    delete a;
    delete b;
    delete c;
    return 0;
}