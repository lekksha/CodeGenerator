#ifndef FACTORYCS_H
#define FACTORYCS_H

#include "factoryAbstract.h"
#include "classCs.h"
#include "methodCs.h"
#include "printoperatorCs.h"


class FactoryCs : public FactoryAbstract{
public:
    std::shared_ptr<Class> createClass(const std::string& name) const override {
        return std::make_shared<ClassCs>(name); // переводим обычный указатель в умный
    }

    std::shared_ptr<Method> createMethod(const std::string& name, const std::string& returnType, Class::Flags flags) const override {
        return std::make_shared<MethodCs>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperator> createPrintOperator(const std::string& text) const override{
        return std::make_shared<PrintOperatorCs>(text);
    };
};

#endif // FACTORYCS_H
