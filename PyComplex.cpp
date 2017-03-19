
#include "PyComplex.h"
#include "PyComplexType.h"
#include "PyObject.h"
#include "PyType.h"
#include "PyInt.h"
#include "PyStr.h"
#include "PyBool.h"
#include "PyFloat.h"
#include "PyException.h"
#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;



PyInt::PyComplex(int val): PyObject() {
    this->val = val;
    dict["__add__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyInt::__add__);
    dict["__sub__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyInt::__sub__);
    dict["__mul__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyInt::__mul__);
    dict["__truediv__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyInt::__truediv__);
    dict["__eq__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyInt::__eq__);


}



string PyComplex::toString() {

    stringstream ss;
   
    



    PyObject* realPart;
    PyObject* imagPart;

    if (realPart != 0.0 && imagPart != 0.0)
        ss << "(";

    if (realPart > 0.0)
        ss << real->toString();

    if (imagPart > 0.0)
        ss << "+";

    if (imagPart != 0.0)
        ss << imag->toString() << "j";

    if (realPart != 0.0 && imagPart != 0.0)
        ss << ")";

    return ss.str();


}




PyObject* PyComplex::__add__(vector<PyObject*>* args) {
    PyComplex* z;
    ostringstream msg;
    vector<PyObject*> reals;
    vector<PyObject*> imags;
    
    if (args->size() !=1) {
        msg << "TypeError: expected 1 args, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,msg.str());
    }
    
    PyObject* arg = (*args)[0];
    
    switch (arg->getType()->typeId()) {
        case PyComplexTypeId:
            x = (PyComplex*) arg;
            reals.push_back(x->real);
            imags.push_back(x->imag);
            
            w = x->callMethod("__add__", arg);
            
    }
}

PyObject* PyInt::__sub__(vector<PyObject*>* args) {
    PyComplex* z;
    ostringstream msg;
    vector<PyObject*> reals;
    vector<PyObject*> imags;
    
    if (args->size() != 1) {
        msg << "TypeError: expected 1 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,msg.str());  
    }
    
    PyObject* arg = (*args)[0];

    switch (arg->getType()->typeId()) {
        case PyIntType:
            x = (PyInt*) arg;
            return new PyInt(this->val - x->val);
        case PyFloatType:
            y = (PyFloat*) arg;
            return new PyFloat(this->val - y->getVal());
        default:
            throw new PyException(PYILLEGALOPERATIONEXCEPTION, "Invalid types for -: int and " + arg->getType()->toString());
    }
}

PyObject* PyInt::__mul__(vector<PyObject*>* args) {
    PyComplex* z;
    ostringstream msg;
    vector<PyObject*> reals;
    vector<PyObject*> imags;

    if (args->size() != 1) {
        msg << "TypeError: expected 1 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,msg.str());  
    }
    
    PyObject* arg = (*args)[0];

    switch (arg->getType()->typeId()) {
        case PyIntType:
            x = (PyInt*) arg;
            return new PyInt(this->val * x->val);

        case PyFloatType:
            y = (PyFloat*) arg;
            return new PyFloat(this->val * y->getVal());

        default:
            throw new PyException(PYILLEGALOPERATIONEXCEPTION, "Invalid types for *: int and " + arg->getType()->toString());
    }
}

PyObject* PyInt::__truediv__(vector<PyObject*>* args) {
    PyComplex* z;
    ostringstream msg;
    vector<PyObject*> reals;
    vector<PyObject*> imags;

    if (args->size() != 1) {
        msg << "TypeError: expected 1 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,msg.str());  
    }
    
    PyObject* arg = (*args)[0];

    switch (arg->getType()->typeId()) {
        case PyIntType:
            x = (PyInt*) arg;
            if (x->val == 0)
                throw new PyException(PYILLEGALOPERATIONEXCEPTION, "ZeroDivisionError: integer division or modulo by zero");
            return new PyFloat(this->val / x->val);

        case PyFloatType:
            y = (PyFloat*) arg;
            if (y->getVal() == 0)
                throw new PyException(PYILLEGALOPERATIONEXCEPTION, "ZeroDivisionError: integer division or modulo by zero");
            return new PyFloat(this->val / y->getVal());

        default:
            throw new PyException(PYILLEGALOPERATIONEXCEPTION, "Invalid types for *: int and " + arg->getType()->toString());
    }
}


PyObject* PyInt::__eq__(vector<PyObject*>* args) {
    PyComplex* z;
    ostringstream msg;
    vector<PyObject*> reals;
    vector<PyObject*> imags;
    
    if (args->size() != 1) {
        msg << "TypeError: expected 1 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,msg.str());  
    }
    
    //We should check the type of args[0] before casting it. 
    PyInt* other = (PyInt*) (*args)[0];

    return new PyBool(val == other->val);
}