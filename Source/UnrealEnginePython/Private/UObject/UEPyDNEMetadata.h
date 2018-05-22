#pragma once

//#include "UnrealEnginePython.h"
#include "UEPyModule.h"


#if WITH_EDITOR
PyObject *py_ue_add_dnemetadata_to_object(ue_PyUObject *, PyObject *);
#endif