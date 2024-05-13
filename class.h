#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <vector>
#include "unit.h"

class Class : public Unit{
public:
    enum AccessModifier // Здесь определены всевозможные спецификаторы доступа
    {
        PUBLIC,                     // C# C++ Java
        PROTECTED,             // C# C++ Java
        PRIVATE,               // C# C++ Java
        INTERNAL,              // C#
        PROTECTED_INTERNAL,    // C#
        PRIVATE_PROTECTED,     // C#
    };

    static const std::vector< std::string > ACCESS_MODIFIERS;   // инициализирован вне класса

    explicit Class(const std::string &name, size_t field_size) : m_name(name), m_fields(field_size) {}


protected:
    std::string m_name; // имя класса
    using Fields = std::vector<std::shared_ptr<Unit>>;  // вектор член-функций/член-данных.
    std::vector<Fields> m_fields;   // вектор, характеризующий модификаторы достпа и член-функции/член-данные, которые соответствуют определенному
                                    // модификатору доступа.

};

const std::vector< std::string > Class::ACCESS_MODIFIERS = { "public", "protected", "private", "internal", "protected internal", "private protected" };


#endif // CLASS_H
