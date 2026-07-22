#include "person.h"

int main()
{
    Boss* huhansan = new Boss();
    StockObserver* tongshi1 = new StockObserver("魏关姹", huhansan);
    NBAObserver* tongshi2 = new NBAObserver("易管查", huhansan);
    
    huhansan->Attach(tongshi1);
    huhansan->Attach(tongshi2);

    huhansan->Detach(tongshi1);
    
    huhansan->SetSubjectAction("我胡汉三回来了！");
    huhansan->Notify();

    delete tongshi1;
    delete tongshi2;
    delete huhansan;
    return 0;
}