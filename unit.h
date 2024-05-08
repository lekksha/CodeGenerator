#ifndef UNIT_H  // включает код между #ifndef и #endif, если UNIT_H не был до этого опеделен
#define UNIT_H


#include <memory>   // позволяет работать с умными указателями (std::shared_ptr)
#include <stdexcept>    // позволяет обрабатывать исключения

class Unit
{
public:
    using Flags = unsigned int; // Создание псевдонима Flags для типа unsigned int

public:
    virtual ~Unit() = default;

    /* add() - Виртуальная функция-член предназначена для добавления вложенных элементов (передача происходит через умный указатель std::shared_ptr).
     * Также эта функция принимает параметр Flags. По умолчанию add() выбрасывает исключение.   */
    virtual void add( const std::shared_ptr< Unit >& , Flags = 0 ) {
        throw std::runtime_error( "Not supported" );
    }

    /* Compile() - Функция генерирует код на C++, соответствующий содержимому элемента. Результат возвращается в виде строки std::string.
     * В качестве аргумента функция принимает параметр level, указывающий на уровень вложенности узла дерева.
     * Это требуется для корректной расстановки отступов в начале строк генерируемого кода. */
    virtual std::string compile( unsigned int level = 0 ) const = 0;    // чисто виртуальная функция

protected:
    /* generateShift() - Вспомогательная функция-член всего лишь возвращает строку, состоящую из нужного числа пробелов.
     * Результат зависит от уровня вложенности. */
    virtual std::string generateShift( unsigned int level ) const   // не изменяет состояние объекта
    {
         const auto DEFAULT_SHIFT = " ";
        std::string result;
        for( unsigned int i = 0; i < level; ++i ) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};


#endif // UNIT_H
