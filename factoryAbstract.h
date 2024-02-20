#ifndef FACTORYABSTRACT_H
#define FACTORYABSTRACT_H

#include <memory>
#include "class.h"
#include "method.h"
#include "printoperator.h"


class FactoryAbstract {
public:

    virtual std::shared_ptr<Class> createClass(const std::string& name) const = 0;
    virtual std::shared_ptr<Method> createMethod(const std::string& name, const std::string& returnType, Class::Flags flags) const = 0;
    virtual std::shared_ptr<PrintOperator> createPrintOperator(const std::string& text) const = 0;
};

#endif // FACTORYABSTRACT_H
