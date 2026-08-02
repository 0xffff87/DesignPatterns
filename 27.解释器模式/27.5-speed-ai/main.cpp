#include <iostream>
#include "expression.h"

using namespace std;

int main()
{
    PlayContext *context = new PlayContext();
    cout << "上海滩" << endl;
    context->m_text = " T 500 O 2 E 0.5 G 0.5 A 3 E 0.5 G 0.5 D 3 E 0.5 G 0.5 A 0.5 O 3 C 1 O 2 A 0.5 G 1 C 0.5 E 0.5 D 3 ";

    try {
        while (!context->m_text.empty())
        {
            string str = context->m_text.substr(0, 1);
            if (str == " ")
            {
                context->m_text = context->m_text.substr(1);
                continue;
            }

            auto &factory = ExpressionFactory::Instance();
            if (!factory.IsSupported(str))
            {
                context->m_text = context->m_text.substr(1);
                continue;
            }

            auto expression = factory.Create(str);
            if (!expression)
            {
                context->m_text = context->m_text.substr(1);
                continue;
            }

            expression->Interpret(context);
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception occurred." << std::endl;
    }

    delete context;
    return 0;
}