#ifndef TYPECONTROLLER_H
#define TYPECONTROLLER_H
#include "dao/typedao.h"
#include <vector>
class TypeController
{
private:
    TypeDAO typeDAO;
public:
    TypeController();
    bool getAllType(vector<Type> & types);
    Type getTypeById(int id);
};

#endif // TYPECONTROLLER_H
