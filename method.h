#ifndef METHOD_H
#define METHOD_H

#include "unit.h"
#include <vector>

class Method : public Unit {
public:
    enum Modifier {
        STATIC = 1, // первый бит = 1 => функция получит STATIC // C++, Java, C#
        CONST = 1 << 1, // второй бит = 1 => функция получит CONST  // C++
        VIRTUAL = 1 <<  2,   // третий бит = 1 => функция получит VIRTUAL    // C++, C#
        FINAL = 1 << 3,     // четвернтый бит = 1 => функция получит FINAL  // Java
        ABSTRACT = 1 << 4   // пятый бит = 1 => функция получит  // Java
    };
protected:
    Method(const std::string& name, const std::string& returnType, Flags flags ) : // конструктор метода
        m_name( name ), m_returnType( returnType ), m_flags( flags ) {};
    std::string m_name; // имя метода
    std::string m_returnType;   // тип возвращаемого значения метода
    Flags m_flags;  // модификаторы метода
    std::vector<std::shared_ptr<Unit>> m_body;  // вектор в который мы добавляем методы

};

#endif // METHOD_H
