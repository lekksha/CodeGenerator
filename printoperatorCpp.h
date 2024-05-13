#ifndef PRINTOPERATORCPP_H
#define PRINTOPERATORCPP_H
#include "printoperator.h"

/*
 * Данный класс предназначен для добавления функции printf() в генерируемый код
 */

class PrintOperatorCpp : public PrintOperator {
public:
    explicit PrintOperatorCpp(const std::string &text) : PrintOperator(text) { };
    std::string compile( unsigned int level = 0 ) const override {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";  // делаем отступ и выводим printf с текстом. Число level = число отступов
    }
};

#endif // PRINTOPERATORCPP_H
