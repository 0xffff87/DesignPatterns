#include "handsetbrand.h"

int main()
{
    HandsetBrand* ab = new HandsetBrandN();

    ab->SetHandsetSoft(new HandsetGame());
    ab->Run();

    ab->SetHandsetSoft(new HandsetAddressList());
    ab->Run();

    ab = new HandsetBrandM();

    ab->SetHandsetSoft(new HandsetGame());
    ab->Run();

    ab->SetHandsetSoft(new HandsetAddressList());
    ab->Run();

    delete ab;
    return 0;
}