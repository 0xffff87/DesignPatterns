#include "person.h"

int main()
{
    Secretary* tongzizhe = new Secretary();

    StockObserver* tongshi1 = new StockObserver("魏关姹", tongzizhe);
    StockObserver* tongshi2 = new StockObserver("易童学", tongzizhe);

    tongzizhe->Attach(tongshi1);
    tongzizhe->Attach(tongshi2);

    tongzizhe->SetSecretaryAction("老板回来了！");
    tongzizhe->Notify();

    delete tongshi1;
    delete tongshi2;
    delete tongzizhe;
    return 0;
}
