#include "waiter.h"

int main()
{
    // 开店前的准备
    Barbecuer boy = Barbecuer();
    Command *bakeMuttonCommand1 = new BakeMuttonCommand(&boy);
    Command *bakeMuttonCommand2 = new BakeMuttonCommand(&boy);
    Command *bakeChickenWingCommand1 = new BakeChickenWingCommand(&boy);
    Waiter girl = Waiter();

    // 开门营业
    girl.SetCommand(bakeMuttonCommand1);
    girl.SetCommand(bakeMuttonCommand2);
    girl.SetCommand(bakeChickenWingCommand1);

    girl.Notify();

    delete bakeMuttonCommand1;
    delete bakeMuttonCommand2;
    delete bakeChickenWingCommand1;

    return 0;
}