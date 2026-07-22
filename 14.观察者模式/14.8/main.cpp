#include "person.h"
#include <functional>

using namespace std;

int main()
{
    Boss* huhansan = new Boss();

    StockObserver* tongshi1 = new StockObserver("魏关姹", huhansan);
    NBAObserver* tongshi2 = new NBAObserver("易管查", huhansan);

    // 对应 C#: huhansan.Update += new EventHandler(tongshi1.CloseStockMarket);
    huhansan->Update += bind(&StockObserver::CloseStockMarket, tongshi1);
    huhansan->Update += bind(&NBAObserver::CloseNBADirectSeeding, tongshi2);

    huhansan->SetSubjectAction("我胡汉三回来了！");
    huhansan->Notify();

    delete tongshi1;
    delete tongshi2;
    delete huhansan;
    return 0;
}
