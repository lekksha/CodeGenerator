#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <vector>
#include "unit.h"

class Class : public Unit{
public:
    enum AccessModifier // Здесь определены всевозможные спецификаторы доступа
    {
        PUBLIC,             // 0 C# C++ Java
        PROTECTED,          // 1 C# C++ Java
        PRIVATE,            // 2 C# C++ Java
        INTERNAL,           // 3 C#
        PROTECTED_INTERNAL, // 4 C#
        PRIVATE_PROTECTED,  // 5 C#
    };

    explicit Class(const std::string &name, size_t field_size) : m_name(name), m_fields(field_size) {}

protected:
    std::string m_name; // имя класса
    using Fields = std::vector<std::shared_ptr<Unit>>;  // вектор член-функций/член-данных.
    std::vector<Fields> m_fields;   // вектор, характеризующий модификаторы достпа и член-функции/член-данные, которые соответствуют определенному
                                    // модификатору доступа.

};



#endif // CLASS_H
