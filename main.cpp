#include "classCpp.h"
#include "methodCpp.h"
#include "printoperatorCpp.h"
#include "factoryCpp.h"
#include <QCoreApplication>
#include <iostream>

std::string generateProgram() { // NOW: проверить создание с++ класса
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
    FactoryAbstract* fact = new FactoryCpp();
    auto cls = fact->createClass("prikol");
    return cls->compile();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << generateProgram() << std::endl;

    return a.exec();
}
