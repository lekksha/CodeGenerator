#ifndef FACTORYJAVA_H
#define FACTORYJAVA_H

#include "factoryAbstract.h"
#include "classJava.h"
#include "methodJava.h"
#include "printoperatorJava.h"


class FactoryJava : public FactoryAbstract{
public:
    std::shared_ptr<Class> createClass(const std::string& name) const override {
        return std::make_shared<ClassJava>(name); // переводим обычный указатель в умный
    }

    std::shared_ptr<Method> createMethod(const std::string& name, const std::string& returnType, Class::Flags flags) const override {
        return std::make_shared<MethodJava>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperator> createPrintOperator(const std::string& text) const override{
        return std::make_shared<PrintOperatorJava>(text);
    };
};

#endif // FACTORYJAVA_H
