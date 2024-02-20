#include "factoryCpp.h"
#include "factoryJava.h"
#include "factoryCs.h"
#include <QCoreApplication>
#include <iostream>

std::string generateProgram() {
    /* Starting Code
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
    /* */

    /* // Java code
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
    /* */

    /* // C# code
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
    /* */
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << generateProgram() << std::endl;

    return a.exec();
}
