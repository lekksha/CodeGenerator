#ifndef PRINTOPERATORCS_H
#define PRINTOPERATORCS_H

#include "printoperator.h"

class PrintOperatorCs : public PrintOperator {
public:
    explicit PrintOperatorCs(const std::string& text) : PrintOperator(text) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift(level) + "Console.WriteLine(\"" + m_text + "\");\n";
    }
};

#endif // PRINTOPERATORCS_H
