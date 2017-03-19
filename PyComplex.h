#ifndef PYCOMPLEX_H
#define PYCOMPLEX_H

#include "PyCallable.h"
#include <vector>
using namespace std;

class PyComplex : public PyObject {
public: 
    PyComplex(PyObject* real);
    PyComplex(PyObject* real, PyObject* imag);
    PyComplex(const PyComplex& orig);
    virtual ~PyComplex();
    PyType* getType();
    string toString();
    

protected:
    PyObject* real;
    PyObject* imag;
    
    virtual PyObject* __add__(vector<PyObject*>* args);
    virtual PyObject* __sub__(vector<PyObject*>* args);
    virtual PyObject* __mul__(vector<PyObject*>* args);
    virtual PyObject* __truediv__(vector<PyObject*>* args);
    virtual PyObject* __eq__(vector<PyObject*>* args);
    
};

#endif /* PYCOMPLEX_ */

