#include "PyComplexType.h"
#include "PyComplex.h"
#include "PyType.h"
#include "PyStr.h"
#include "PyInt.h"
#include <sstream>

using namespace std;

PyComplexType::PyComplexType(string typeString, PyTypeId id) : PyType(typeString, id) {
}

PyComplexType::~PyComplexType() {
}

PyObject* PyComplexType::__call__(vector<PyObject*>* args) {
    
    ostringstream msg;
   
    switch (args->size()) {
        case 1:
            return new PyComplex((*args)[0])
                
            }
            
           
            break;
        case 2:
            return new PyComplex((*args)[0], (*args)[1])
           
            break;
        
        default:
            throw new PyException(PYILLEGALOPERATIONEXCEPTION,"Incorrect number of arguments");
            break;
    }
}