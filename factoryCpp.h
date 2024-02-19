#ifndef FACTORYCPP_H
#define FACTORYCPP_H

#include "factoryAbstract.h"
#include "classCpp.h"
#include "methodCpp.h"
#include "printoperatorCpp.h"

class FactoryCpp : public FactoryAbstract{
public:
    std::shared_ptr<Class> createClass(const std::string& name) const override {
        return std::make_shared<ClassCpp>(name); // переводим обычный указатель в умный
    }

    std::shared_ptr<Method> createMethod(const std::string& name, const std::string& returnType, Class::Flags flags) const override {
        return std::make_shared<MethodCpp>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperator> createPrintOperator(const std::string& text) const override{
        return std::make_shared<PrintOperatorСpp>(text);
    };
};

#endif // FACTORYCPP_H
