#ifndef METHODCS_H
#define METHODCS_H

#include "method.h"

class MethodCs : public Method {

public:
    MethodCs( const std::string& name, const std::string& returnType, Flags flags ) : Method(name, returnType, flags) {} // конструктор метода
    // В родительском классе член-данные уже инициализируются

    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) override {    // добавление инструкций в список методов подлежащих созданию
        m_body.push_back( unit );
    }
    std::string compile( unsigned int level = 0 ) const override {
        std::string result = generateShift( level );

        if( m_flags & STATIC ) { // проверка на наличие бита соответствующему наличию модификатора STATIC
            result += "static ";
        } else if( m_flags & VIRTUAL ) { // проверка на наличие бита соответствующему наличию модификатора VIRTUAL
            result += "virtual ";
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

#endif // METHODCS_H
