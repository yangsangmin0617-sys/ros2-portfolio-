// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from erp42_msgs:msg/StanleyError.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "erp42_msgs/msg/detail/stanley_error__struct.h"
#include "erp42_msgs/msg/detail/stanley_error__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool erp42_msgs__msg__stanley_error__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("erp42_msgs.msg._stanley_error.StanleyError", full_classname_dest, 42) == 0);
  }
  erp42_msgs__msg__StanleyError * ros_message = _ros_message;
  {  // ctr
    PyObject * field = PyObject_GetAttrString(_pymsg, "ctr");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ctr = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // hdr
    PyObject * field = PyObject_GetAttrString(_pymsg, "hdr");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->hdr = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * erp42_msgs__msg__stanley_error__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of StanleyError */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("erp42_msgs.msg._stanley_error");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "StanleyError");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  erp42_msgs__msg__StanleyError * ros_message = (erp42_msgs__msg__StanleyError *)raw_ros_message;
  {  // ctr
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ctr);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ctr", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hdr
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->hdr);
    {
      int rc = PyObject_SetAttrString(_pymessage, "hdr", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
