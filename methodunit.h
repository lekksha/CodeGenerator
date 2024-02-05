#ifndef METHODUNIT_H
#define METHODUNIT_H
#include "unit.h"
#include <vector>
#include <unit.h>


class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1, // первый бит = 1 => функция получит STATIC
        CONST = 1 << 1, // второй бит = 1 => функция получит CONST
        VIRTUAL = 1 <<  2   // третий бит = 1 => функция получит VIRTUAL
    };
public:
    MethodUnit( const std::string& name, const std::string& returnType, Flags flags ) : // конструктор метода
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) {    // добавление инструкций в список методов подлежащих созданию
        m_body.push_back( unit );
    }
    std::string compile( unsigned int level = 0 ) const {
        std::string result = generateShift( level );
        if( m_flags & STATIC ) { // проверка на наличие бита соответствующему наличию модификатора STATIC
            result += "static ";
        } else if( m_flags & VIRTUAL ) { // проверка на наличие бита соответствующему наличию модификатора VIRTUAL
            result += "virtual ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        if( m_flags & CONST ) { // проверка на наличие бита соответствующему наличию модификатора CONST
            result += " const";
        }
        result += " {\n";
        for( const auto& b : m_body ) { // вывод в result тела метода, которое будет состоять из ранее добавленных метода
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";   // закрываем метод с помощью фигурной скобки
        return result;
    }
private:
    std::string m_name; // имя метода
    std::string m_returnType;   // тип возвращаемого значения метода
    Flags m_flags;  // модификаторы метода
    std::vector<std::shared_ptr<Unit>> m_body;  // вектор суще
};

#endif // METHODUNIT_H
