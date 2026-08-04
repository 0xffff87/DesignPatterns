#include <iostream>
#include "action.h"


using namespace std;

void Success::GetManConclusion(Man* concreteElementA)
{
    cout << concreteElementA->GetActionName() << " " << GetActionName() 
    << " 时，背后多半有一个伟大的女人" << endl;
}


void Success::GetWomanConclusion(Woman* concreteElementB)
{
    cout << concreteElementB->GetActionName() << " " << GetActionName() 
    << " 时，背后多半有一个不成功的男人" << endl;
}

void Failing::GetManConclusion(Man* concreteElementA)
{
    cout << concreteElementA->GetActionName() << " " << GetActionName() 
    << " 时，闷头喝酒，谁也拦不住" << endl;
}


void Failing::GetWomanConclusion(Woman* concreteElementB)
{
    cout << concreteElementB->GetActionName() << " " << GetActionName() 
    << " 时，眼泪汪汪，谁也劝不住" << endl;
}

void Amativeness::GetManConclusion(Man* concreteElementA)
{
    cout << concreteElementA->GetActionName() << " " << GetActionName() 
    << " 时，凡事不懂也要装懂" << endl;
}


void Amativeness::GetWomanConclusion(Woman* concreteElementB)
{
    cout << concreteElementB->GetActionName() << " " << GetActionName() 
    << " 时，遇事懂也装不懂" << endl;
}