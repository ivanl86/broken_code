
int ival = 1.01; // a normal declaration
int &rval1 = 1.01; // invalid, it must bound to an object
int &rval2 = ival; // a proper reference
int &rval3; // invalid, needs an initializer