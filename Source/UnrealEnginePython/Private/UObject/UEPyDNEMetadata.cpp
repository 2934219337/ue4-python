#include "UEPyDNEMetadata.h"

#include "Editor/DNEEditor/Public/AssetMetadata/DNEAssetMetadataHelper.h"


#if WITH_EDITOR

PyObject *py_ue_add_dnemetadata_to_object(ue_PyUObject *self, PyObject * args)
{
	ue_py_check(self);

	PyObject *py_metadata_uclass;

	if (!PyArg_ParseTuple(args, "O", &py_metadata_uclass))
	{
		return nullptr;
	}

	UClass *u_metadata_class = ue_py_check_type<UClass>(py_metadata_uclass);
	if (!u_metadata_class)
		return PyErr_Format(PyExc_Exception, "argument is not a UClass");

	UObject *u_object = self->ue_object;
	if (!u_object)
		return PyErr_Format(PyExc_Exception, "argument is not a UObject");

	UAssetUserData *u_asset_metadata_object = DNEAssetMetadataHelper::SetMetadata(u_metadata_class, u_object, false);

	if (!u_asset_metadata_object) {
		Py_RETURN_NONE;
	}

	ue_PyUObject *py_asset_metadata_uobject = ue_get_python_uobject(u_asset_metadata_object);
	if (!py_asset_metadata_uobject) {
		return PyErr_Format(PyExc_Exception, "PyUObject is in invalid state");
	}

	Py_INCREF(py_asset_metadata_uobject);
	return (PyObject *) py_asset_metadata_uobject;
}

#endif

