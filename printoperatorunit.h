#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include "unit.h"

/*
 * Данный класс предназначен для добавления функции printf() в генерируемый код
 */

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";  // делаем отступ и выводим printf с текстом. Число level = число отступов
    }
private:
    std::string m_text; //  текст передаваемый как аргумент генерируемой printf()
};

#endif // PRINTOPERATORUNIT_H
