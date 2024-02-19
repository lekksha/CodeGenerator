#ifndef PRINTOPERATOR_H
#define PRINTOPERATOR_H

#include "unit.h"

class PrintOperator : public Unit {
public:
    PrintOperator(const std::string& text) : m_text(text) {};
protected:
    std::string m_text; //  текст передаваемый как аргумент генерируемой printf()
};

#endif // PRINTOPERATOR_H
