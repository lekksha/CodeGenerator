#ifndef FACTORYCPP_H
#define FACTORYCPP_H

#include "factoryAbstract.h"
#include "classCpp.h"

class FactoryCpp : public FactoryAbstract{
public:
    std::shared_ptr<Class> createClass(const std::string& name) const {
        return std::make_shared<ClassCpp>(name); // переводим обычный указатель в умный
    }

    std::shared_ptr<Method> createMethod(const std::string& name, const std::string& returnType, Class::Flags flags) const {

    }

    std::shared_ptr<PrintOperator> createPrintOperator(const std::string& name) const {

    };
};

#endif // FACTORYCPP_H
