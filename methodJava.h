#ifndef METHODJAVA_H
#define METHODJAVA_H

#include "method.h"

class MethodJava : public Method {

public:
    MethodJava( const std::string& name, const std::string& returnType, Flags flags ) : Method(name, returnType, flags) {} // конструктор метода
    // В родительском классе член-данные уже инициализируются

    std::string compile( unsigned int level = 0 ) const override {
        std::string result = generateShift( level );

        if( m_flags & ABSTRACT ) { // проверка на наличие бита соответствующему наличию модификатора ABSTRACT
            result += "abstract ";
        } else if( m_flags & STATIC ) { // проверка на наличие бита соответствующему наличию модификатора STATIC
            result += "static ";
        } else if( m_flags & FINAL ) { // проверка на наличие бита соответствующему наличию модификатора STATIC
            result += "final ";
        }

        result += m_returnType + " ";
        result += m_name + "()";
        result += " {\n";

        for( const auto& b : m_body ) { // вывод в result тела метода, которое будет состоять из ранее добавленных метода
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";   // закрываем метод с помощью фигурной скобки
        return result;
    }
};


#endif // METHODJAVA_H
