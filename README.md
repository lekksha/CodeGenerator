# Code Generator
## Постановка задачи:
Реализована некоторая система, которая способна генерировать код на языке **С++**, причем, программы только определенного вида (пример кода прилагается) [lab_2.pdf]

Требуется реализовать подобную генерацию программ на С# и Java, путем  расширения возможностей предложенной реализации используя фабричные подходы (_абстрактная фабрика_).

При реализации требуется добавить модификаторы классов и методов, которых нет в C++, но есть в C# (  [https://metanit.com/sharp/tutorial/3.2.php](https://metanit.com/sharp/tutorial/3.2.php) ) и Java  ( [http://proglang.su/java/modifiers](http://proglang.su/java/modifiers)  - до п.3.4, **synchronized, transient, volatile** можно не включать).

## Пример генерируемого кода:
```cpp
class MyClass 
{ 
public: 
    void testFunc1() { } 
    virtual void testFunc3() const { } 

protected: 
    static void testFunc4() 
    { 
        printf("Hello, world!\n"); 
    } 
private: 
    static void testFunc2() { } 
};
```