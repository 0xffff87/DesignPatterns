#include "flyweight.h"

int main()
{
    int extrinsicState = 22;

    FlyweightFactory *f = new FlyweightFactory();

    Flyweight *fx = f->GetFlyweight("X");
    fx->Operation(--extrinsicState);

    Flyweight *fy = f->GetFlyweight("Y");
    fy->Operation(--extrinsicState);

    Flyweight *fz = f->GetFlyweight("Z");
    fz->Operation(--extrinsicState);

    UnsharedConcreteFlyweight *uf = new UnsharedConcreteFlyweight();

    uf->Operation(--extrinsicState);

    delete f;
    delete fx;
    delete fy;
    delete fz;
    delete uf;
    
    return 0;
}