#include "factoryCpp.h"
#include "factoryJava.h"
#include "factoryCs.h"
#include <QCoreApplication>
#include <iostream>

std::string generateCppProgram(){
    auto fact = std::make_shared<FactoryCpp>();

    auto clsCpp = fact->createClass("ExampleCppClass");
    auto mthCppVC = fact->createMethod("ExampleMethodCppVC", "void",  Method::VIRTUAL | Method::CONST);
    auto prntCppVC = fact->createPrintOperator("VC");
    mthCppVC->add(prntCppVC, 0);
    clsCpp->add(mthCppVC, Class::PUBLIC);

    auto mthCppS = fact->createMethod("ExampleMethodCppS", "void", Method::STATIC);
    auto prntCppS = fact->createPrintOperator("S");
    mthCppS->add(prntCppS, Method::STATIC);
    clsCpp->add(mthCppS, Class::PRIVATE);

    return clsCpp->compile();
}


std::string generateJavaProgram() {
    // Java code

    auto fact = std::make_shared<FactoryJava>();

    auto clsJava = fact->createClass("ExampleJavaClass");
    auto mthJavaVC = fact->createMethod("ExampleMethodJavaVC", "void",  Method::CONST | Method::ABSTRACT);
    auto prntJavaVC = fact->createPrintOperator("VC");
    mthJavaVC->add(prntJavaVC, Class::PUBLIC);
    clsJava->add(mthJavaVC, Class::PUBLIC);

    auto mthJavaFS = fact->createMethod("ExampleMethodJavaS", "void", Method::FINAL);
    auto prntJavaFS = fact->createPrintOperator("S");
    mthJavaFS->add(prntJavaFS, Class::PRIVATE);
    clsJava->add(mthJavaFS, Class::PRIVATE);

    return clsJava->compile();
}


std::string generateCsProgram() {
    auto fact = std::make_shared<FactoryCs>();

    auto clsCs = fact->createClass("ExampleCsClass");
    auto mthCsV = fact->createMethod("ExampleMethodCsV", "void",  Method::VIRTUAL);
    auto prntCsV = fact->createPrintOperator("V");
    mthCsV->add(prntCsV, Class::INTERNAL);
    clsCs->add(mthCsV, Class::INTERNAL);

    auto mthCsC = fact->createMethod("ExampleMethodCsS", "void", Method::CONST);
    auto prntCsC = fact->createPrintOperator("S");
    mthCsC->add(prntCsC, Class::PROTECTED_INTERNAL);
    clsCs->add(mthCsC, Class::PROTECTED_INTERNAL);

    return clsCs->compile();
}


//std::string generateProgram() {

//     // Starting Code
////    ClassUnit myClass( "MyClass" );
////    myClass.add( std::make_shared<MethodUnit>( "testFunc1", "void", 0 ), ClassUnit::PUBLIC );
////    myClass.add( std::make_shared<MethodUnit>( "testFunc2", "void", MethodUnit::STATIC ), ClassUnit::PRIVATE );
////    myClass.add( std::make_shared<MethodUnit>( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ), ClassUnit::PUBLIC );
////    auto method = std::make_shared<MethodUnit>( "testFunc4", "void", MethodUnit::STATIC );
////    method->add( std::make_shared<PrintOperatorUnit>(R"(Hello, world!\n)" ));
////    myClass.add( method, ClassUnit::PROTECTED );
////    return myClass.compile();

//}

template <typename T>
std::string generateForTask(std::shared_ptr<T> factory) {
    auto cls = factory->createClass("MyClass");
    auto mth1 = factory->createMethod("testFunc1", "void", 0);
    cls->add(mth1, Class::PUBLIC);
    auto mth2 = factory->createMethod("testFunc2", "void", Method::STATIC);
    cls->add(mth2, Class::PRIVATE);
    auto mth3 = factory->createMethod("testFunc3", "void", Method::VIRTUAL | Method::CONST);
    cls->add(mth3, Class::PUBLIC);
    auto mth4 = factory->createMethod("testFunc4", "void", Method::VIRTUAL | Method::CONST);
    cls->add(mth4, Class::PROTECTED);
    auto print = factory->createPrintOperator("Hello World!");
    mth4->add(print);

    return cls->compile();
}


template <typename T>
std::string generateForTest(std::shared_ptr<T> factory) {
    auto cls = factory->createClass("TestClass");

    // Создаем функции
    // Абстрактной финальной функции не может существовать (JAVA), а в С++ и С# таких определений нет.
    auto mth1 = factory->createMethod("M1", "void", Method::FINAL | Method::ABSTRACT);

    // В JAVA нет VIRTUAL, а в С++ и C# не бывает STATIC и VIRTUAL метода одновременно
    auto mth2 = factory->createMethod("M2", "int", Method::VIRTUAL | Method::STATIC);

    // Создадим оператор вывода
    auto print = factory->createPrintOperator("F1");
    auto print2 = factory->createPrintOperator("F2");

    // Тест различных вложений
    // Просто вкладываем функции как положено
    cls->add(mth1, Class::PRIVATE_PROTECTED);
    cls->add(mth2, Class::PRIVATE);
    mth1->add(print);
    mth2->add(print2);


    // Вкладываем класс в класс (создадим еще один)
    // Языки позволяют вкладывать класс в класс
    //auto cls2 = factory->createClass("TestClass2");
    //cls->add(cls2, Class::PUBLIC);

    // Вкладываем оператор печати в класс
    //cls->add(print, Class::PUBLIC);   // Вложился

    //Вкладываем класс в метод  // Программа не работает
    //mth2->add(cls);

    //Вкладываем метод в метод  // Вложился
    //mth2->add(mth1);

    //Вкладываем класс в оператор печати    // Получаем ошибку определенную в unit
    //print->add(cls, 0);

    //Вкладываем оператор печати в оператор печати  // Получаем ошибку определенную в unit
    //print -> add(print, 0);

    return cls->compile();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << generateForTask(std::make_shared<FactoryCpp>());
    std::cout << std::endl << "// C++ is shown above. Press \"Enter\" to continue";
    getchar(); system("cls");

    std::cout << generateForTask(std::make_shared<FactoryJava>());
    std::cout << std::endl << "// Java is shown above. Press \"Enter\" to continue";
    getchar(); system("cls");

    std::cout << generateForTask(std::make_shared<FactoryCs>());
    std::cout << std::endl << "// C# is shown above. Press \"Enter\" to continue";
    getchar(); system("cls");

//    std::cout << generateForTest(std::make_shared<FactoryCpp>());
//    std::cout << std::endl << "// C++ is shown above. Press enter to continue";
//    getchar(); system("cls");

//    std::cout << generateForTest(std::make_shared<FactoryJava>());
//    std::cout << std::endl << "// Java is shown above. Press enter to continue";
//    getchar(); system("cls");

//    std::cout << generateForTest(std::make_shared<FactoryCs>());
//    std::cout << std::endl << "// C# is shown above. Press enter to continue";
//    getchar(); system("cls");

    return a.exec();
}
