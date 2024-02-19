#ifndef PRINTOPERATORJAVA_H
#define PRINTOPERATORJAVA_H

#include "printoperator.h"

class PrintOperatorJava : public PrintOperator {
public:
    explicit PrintOperatorJava(const std::string& text) : PrintOperator(text) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift(level) + "System.out.println(\"" + m_text + "\");\n";
    }
};
#endif // PRINTOPERATORJAVA_H
