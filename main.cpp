#include "factoryCpp.h"
#include "factoryJava.h"
#include <QCoreApplication>
#include <iostream>

std::string generateProgram() {
    /*
    ClassUnit myClass( "MyClass" );
    myClass.add( std::make_shared<MethodUnit>( "testFunc1", "void", 0 ), ClassUnit::PUBLIC );
    myClass.add( std::make_shared<MethodUnit>( "testFunc2", "void", MethodUnit::STATIC ), ClassUnit::PRIVATE );
    myClass.add( std::make_shared<MethodUnit>( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ), ClassUnit::PUBLIC );
    auto method = std::make_shared<MethodUnit>( "testFunc4", "void", MethodUnit::STATIC );
    method->add( std::make_shared<PrintOperatorUnit>(R"(Hello, world!\n)" ));
    myClass.add( method, ClassUnit::PROTECTED );
    return myClass.compile();
    */

    /* // C++ code
    auto fact = std::make_shared<FactoryCpp>();
    auto clsC = fact->createClass("prikol");
    auto mthC = fact->createMethod("rzhaka", "void", Method::VIRTUAL);
    auto prntC = fact->createPrintOperator("lol");
    mthC->add(prntC, 0);
    clsC->add(mthC, Class::PUBLIC);
    return clsC->compile();
    */

    /* // Java code
    auto fact = std::make_shared<FactoryJava>();
    auto clsJ = fact->createClass("prikol");
    auto mthJ = fact->createMethod("rzhaka", "void", Method::VIRTUAL);
    auto prntJ = fact->createPrintOperator("lol");
    mthJ->add(prntJ, 0);
    clsJ->add(mthJ, Class::PUBLIC);
    return clsJ->compile();
    */
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << generateProgram() << std::endl;

    return a.exec();
}
