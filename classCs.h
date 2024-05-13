#ifndef CLASSCS_H
#define CLASSCS_H

#include <vector>
#include "class.h"

class ClassCs : public Class
{
public:
    //static const std::vector< std::string > ACCESS_MODIFIERS ;   // инициализирован вне класса

    explicit ClassCs(const std::string &name): Class(name, ACCESS_MODIFIERS.size())  {    // конструктор.  инициализирует имя класса
        m_fields.resize( ACCESS_MODIFIERS.size() );     // изменяет размер вектора на размер равный количеству модификаторов доступа
        m_name = name;
    }

    void add( const std::shared_ptr< Unit >& unit, Flags flags ) override    // функция для добавления член-данного или член-функции с своим модификатором доступа
    {
        int accessModifier = INTERNAL;   // по умолчанию internal
        if (flags & PRIVATE) {
            accessModifier = PRIVATE;
        }
        else if (flags & PROTECTED) {
            accessModifier = PROTECTED;
        }
        else if (flags & PUBLIC) {
            accessModifier = PUBLIC;
        }
        else if (flags & PROTECTED_INTERNAL) {
            accessModifier = PROTECTED_INTERNAL;
        }
        else if (flags & PRIVATE_PROTECTED) {
            accessModifier = PRIVATE_PROTECTED;
        }
        m_fields[ accessModifier ].push_back( unit );
        /*
        int accessModifier = PRIVATE;   // = 0
        if( flags < ACCESS_MODIFIERS.size() )   // ? Проверяем что модификатор доступа является корректным
        {
            accessModifier = flags; // Ставим соответствующий модификатор доступа
        }

        m_fields[ accessModifier ].push_back( unit );   // Заготавливаем для компиляции под определенный модификатор доступа
        /*
        * В условии и последующей строчке с push_back реализовано добавление член-данных и член-функций под определеннным модификатором.
        * Если отказаться от них, то перед каждым член-данным и член-функцией будет писаться модификатор доступа. Это как миниммум не похоже
        * на нормальный код и как максимум вредит читаемости кода.
        */
    }

    std::string compile( unsigned int level = 0 ) const override
    {
        std::string result = generateShift( level ) + "class " + m_name + " {\n";   // делаем отступ и выводим инициализацию класса
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
        {
            if( m_fields[ i ].empty() ) {
                continue;   // Пропускаем вывод модификатора доступа, если не было добавлено.
                            // ни одной члена-данных/члена-функции с соотвествующим модификатором доступа.
            }

            for( const auto& f : m_fields[ i ] )    // проход по каждому модификатору доступа
            {
                result += generateShift(level+1) + ACCESS_MODIFIERS[ i ] + f->compile( level + 1 );  // добавляем в result текст член-функции/член-данные c соответствуюзщим отступом
            }

            result += "\n";
        }

        result += generateShift( level ) + "};\n";
        return result;
    }
private:
    std::string m_name; // имя класса
    using Fields = std::vector<std::shared_ptr<Unit>>;  // вектор член-функций/член-данных.
    std::vector<Fields> m_fields;   // вектор, характеризующий модификаторы достпа и член-функции/член-данные, которые соответствуют определенному
                                    // модификатору доступа.
};

//const std::vector< std::string > ClassCs::ACCESS_MODIFIERS = { "public", "protected", "private", "internal", "protected internal", "private protected" };

#endif // CLASSCS_H
