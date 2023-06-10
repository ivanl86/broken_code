sizeof(char) ≤ sizeof(short) ≤ sizeof(int) ≤ sizeof(long) ≤ sizeof(long long)
sizeof(float) ≤ sizeof(double)

The bodies of functions are made up of statements, which can, in turn, contain expressions.

Expression statements, compound statements, and control structures
An expression statement simply evaluates its expression and then discards the value afterward
A compound statement, also called a block statement or a block, is a sequence of statements surrounded by curly braces.
Control structures are statements that affect the control flow of a program
Assignment is an expression in C++
conditional expression

A subsequent use of that variable before assigning a value to it would be what is called undefined behavior, which means that we can't know what will happen next.

Assignments, lvalues, and rvalues
a = 3       // legal
a = 3 + 4   // legal
a = b       // legal
a = b + c   // legal
3 = a       // not legal
b + c = a   // not legal

an "lvalue" refers to an expression that would be legal on the left-hand side
an "rvalue" refers to an expression that would only be legal on the right-hand side

a function is a sequence of statements that can be called, accepting a sequence of parameters, and returning a result.

the compiler on the ICS 45C VM has been configured to treat all warnings as though they were errors, so that no program can be compiled successfully and run if it causes any warnings to be emitted.