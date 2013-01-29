//#####################################################################
// Function repr
//#####################################################################
#include <other/core/python/repr.h>
#include <other/core/python/from_python.h>
#include <cstdio>
namespace other {

string repr(PyObject& x) {
  return from_python<string>(steal_ref_check(PyObject_Repr(&x)));
}

string repr(const float x) {
  static char buffer[40];
  sprintf(buffer,"%.9g",x);
  return buffer;
}

string repr(const double x) {
  static char buffer[40];
  sprintf(buffer,"%.17g",x);
  return buffer;
}

string repr(const long double x) {
  static char buffer[40];
  sprintf(buffer,"%.21Lg",x);
  return buffer;
}

}
