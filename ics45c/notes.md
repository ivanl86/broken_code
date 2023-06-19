## C++ Basics
- sizeof(char) ≤ sizeof(short) ≤ sizeof(int) ≤ sizeof(long) ≤ sizeof(long long)
- sizeof(float) ≤ sizeof(double)
- The bodies of functions are made up of statements, which can, in turn, contain expressions.
- Expression statements, compound statements, and control structures
- An expression statement simply evaluates its expression and then discards the value afterward
- A compound statement, also called a block statement or a block, is a sequence of statements surrounded by curly braces.
- Control structures are statements that affect the control flow of a program
- Assignment is an expression in C++
conditional expression
- A subsequent use of that variable before assigning a value to it would be what is called undefined behavior, which means that we can't know what will happen next.
- Assignments, lvalues, and rvalues
a = 3       // legal  
a = 3 + 4   // legal  
a = b       // legal  
a = b + c   // legal  
3 = a       // not legal  
b + c = a   // not legal  
- An "lvalue" refers to an expression that would be legal on the left-hand side
- An "rvalue" refers to an expression that would only be legal on the right-hand side
- A function is a sequence of statements that can be called, accepting a sequence of parameters, and returning a result.
- A declaration introduces a name into a C++ program. The goal of a declaration is to state that something exists and to give it a type, though it does not necessarily provide all of the other relevant details.
- A definition gives a declared name a unique, specific meaning; it "gives that name life," so to speak.
- The compiler on the ICS 45C VM has been configured to treat all warnings as though they were errors, so that no program can be compiled successfully and run if it causes any warnings to be emitted.

## Strings
- In both Python and Java, string objects are immutable
- A std::string object represents a sequence of characters (i.e., a sequence of char objects)
- A std::string variable in C++ is not a reference, a pointer, or anything else; it's actually a string.
- A std::string objects in C++ are mutable (i.e., their sequence of characters can be changed throughout their lifetimes).
- Bounds checking is not done by default on strings
- One way to do that with C++ std::strings is to use the member function at() instead of the [ ] (indexing) operator
- If you've ever programmed in C, you may have also seen another, more primitive form of string, implemented as a pointer to an array of characters, commonly written with the type char*
- We'll generally avoid C-style strings in this course altogether.

## Standard Input and Output
- An object called std::cin, which represents the program's standard input.
- An object called std::cout, which represents the program's standard output.
- An object called std::endl, which you can think of as a constant representing an end-of-line sequence that you'd like to write to the standard output.
- int variable, initial whitespace is skipped, then (optionally) a − (minus sign) might be consumed, followed by however many digits appear.
    - If the input buffer had three spaces followed by -407alex followed by a newline character, the spaces would be thrown away, -407 would be consumed, the input buffer's cursor would point to the a in alex, and the int value -407 would be stored in the variable.
- double variable, the rules are similar: initial whitespace is skipped, then a number is consumed, but that number might have a decimal point and more digits after it.
- std::string variable, the next "word" (i.e., after skipping whitespace, all characters up to but not including the next whitespace) is stored.
- You can call on std::cin called ignore, which you can use to skip a certain number of characters in the input buffer.
    - For example, std::cin.ignore(1) would skip one character in the input buffer (i.e., move the input buffer's cursor forward one character).

## Separate Compilation
