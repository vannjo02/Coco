#ifndef PYCOMPLEXTYPE_H
#define	PYCOMPLEXTYPE_H

#include "PyType.h"
#include <string>
using namespace std;

class PyComplexType : public PyType {
public:
    PyComplexType(string typeString, PyTypeId id);
    virtual ~PyComplexType();
    bool allowableArgCount(int count);
    
protected:
    PyObject* __call__(vector<PyObject*>* args);
};

#endif	/* PYRANGETYPE_H */
