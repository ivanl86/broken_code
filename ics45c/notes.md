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
- Declarations allow you to tell the compiler about the existence of something, associating a name with a type.
    - There are different kinds of declarations — variable declarations, function declarations, class declarations 
- Definitions give full meaning to something; they are said to "fully elaborate" the meaning of a name.
    - Like declarations, there are different kinds of definitions — variable definitions, function definitions, etc.
    - In the case of a variable, the declaration is the definition, because the declaration includes the type, and the type is sufficient information for the compiler to know how much memory to allocate for it.
    - In the case of a function, on the other hand, the declaration is the function's signature (i.e., its name, parameters, and return type), while the definition includes its body.
- The process of building a C++ program occurs, broadly, in two phases: compilation and linking.
- Compilation is done one source file at a time, with the compiler starting fresh each time, having forgotten everything it knew about other source files.
    - Part of the job of compilation is type checking, but type checking can only be done if each source file contains a declaration of every name it uses, even those that are defined in other source files.
    - Each source file is generally compiled into a single object file, which we can think of as being "mostly" machine code, but with certain things left as placeholders — most especially, uses of things defined in other source files are left out, to be filled in later.
- Linking is the process of taking all of the object files built by the compiler, along with any libraries (the C++ Standard Library or other third-party libraries) required by the program, and stitching them together into a single executable program.
    - A big part of what linkers do is resolving the placeholders left behind by the compilation process; if a.cpp calls a function defined in b.cpp, it's the linker that replaces an "unresolved" call to that function in a's object file to an actual call to b's function.
- Three rules that we'll need to follow:
    - No entity (e.g., a variable, a function, etc.) in C++ can be used in a source file without a declaration for that name appearing in that source file first. (Remember that a declaration is not the same thing as a definition.)
    - In a particular source file in C++, some kinds of declarations are not allowed to be repeated, though others can be. (For example, function declarations can be repeated multiple times, but, as we'll see later this quarter, class declarations cannot.) As a general rule, we're best off preventing multiple declarations of all entities, just to be safe.
    - No entity in C++ can be defined more than once, not even in separate source files. This rule has a name in C++; it's known as the One Definition Rule, and it exists for a good reason. Suppose that a function f() is defined (i.e., its body appears) in both a.cpp and b.cpp, and that the function is declared and called in c.cpp. When the linker tries to resolve c.cpp's call to f(), it won't know whether to resolve it as a call to the version of f() defined in a.cpp or b.cpp, so it will instead trigger a link-time error and the program will fail to build.
- To divide our C++ programs into what you might call "modules" — separate groupings of closely-related functions, classes, etc. — we write our code in two kinds of files: source files and header files.
    - **A source file contains the definitions of everything necessary to implement a module**. If a module is a collection of functions — say, a collection of mathematical utility functions — those functions would all be defined in the module's source file. For reasons we'll see later, each module has only one source file.
    - **A header file contains the declarations of those entities that are intended to be visible to other modules**. Notably, though, header files do not contain definitions. So, for example, our module of mathematical utility functions would have a header file that contained the declarations of those utility functions (i.e., their signatures) but not their definitions (i.e., no bodies). Also, if there were functions in the module that were helpers, but were not intended to be "public" and available to other modules, we would simply leave their declarations out of the header file. Generally speaking, each module consists of one header file (or none if the module doesn't make anything publicly available to other modules).
- **Header files contain a set of declarations that would be needed in one source file in order to use the entities defined by another**. This avoids the problem of having to copy and paste the declarations into many source files, which would require cascading changes in many places whenever one of these declarations needed to change (e.g., a parameter is added to a commonly-used function).
- **Header files are *included* in source files when needed**. If a source file includes a header file, the declarations in that header file become available in the source file. Note, too, that the header file is included in a specific place in a source file, so the rules about the order in which declarations are written are important to remember.
- **We never write definitions in header files, so that we avoid the problem of creating multiple copies of the same definition** (i.e., one in every source file that includes a header file), which can quite easily cause link-time errors. (As we'll discover later in the quarter, there are exceptions to this rule, but nothing we've seen so far in the course can be defined in a header file without causing potential link-time errors.)
- Because some kinds of declarations are not allowed to be repeated in the same source file, we should prevent the same header file from ever being included more than once in the same source file. There's a relatively simple pattern that we can use to solve this problem, which we must use in every header file to be safe. We'll call this pattern **the multiple inclusion prevention pattern**.
- In this course, when we write source files, their names will end in .**cpp**, while header files will have names that end in .**hpp**.
- One of the hallmarks of well-written software is what is sometimes called *separation of concerns*, **the principle that you should handle separate issues in separate parts of a program, rather than munging everything together into fewer, larger, more complex functions**. (This is one of the reasons that global variables are often said to be so problematic; they munge things together by their nature, spreading a part of your program's knowledge throughout the entire program.)
- **Functions should be relatively short, and each of them should have a single job**. If you were to write a comment describing a function's purpose, that description shouldn't be very long, or what you're probably describing is more than one function.
- **Functions that are strongly related to one another should be placed in the same source file**. (This is what software engineers often call high cohesion, the idea that things that are near one another belong together.)
- **Functions that are strongly related to one another should be placed in the same source file**. (This is what software engineers often call *high cohesion*, the idea that things that are near one another belong together.)
- **We need header files so that functions in one source file can be "seen" by others**. If there is a function in one source file **X.cpp** that needs to be called by functions in other source files, then we need a header file **X.hpp** that declares it. Most source files have a corresponding header file, because most source files "export" at least one function to others.
- **Not all functions written in a source file need to be declared in a corresponding header file**; only the ones that need to be called from within other source files need to be declared in a header.

## Behind the Scenes
- One of the keys to understanding a programming language, then, is to understand what the abstraction layer provided by your language looks like. There are lots of questions you need to ask in order to fully understand that abstraction layer:
    - What are you allowed to say in the language?
    - In terms of the language's abstraction layer, what are the semantics of the various language constructs?
    -To the extent that it's important in the context of the work you're doing, what effect does the use of various language constructs have on the performance of the program?
    - How do you decompose a larger program into smaller ones? How do you achieve code reuse?
    - Who decides how values are organized in memory? Who decides when storage is allocated? Who decides when it's deallocated?
    - How do you interact with devices other than the processor and memory (e.g., peripheral devices like external storage, hardware like GPUs)?
- The CPU, fundamentally, cycles through a sequence of events:
    - Read an instruction from memory
    - Decode the instruction (i.e., decide what it's supposed to do, and what data is needed in order to do it)
    - Read operands (e.g., if it's an ADD instruction, go find the two values that need to be added)
    - Execute the instruction, by performing the appropriate operation on the operands
    - Store any results, if needed (e.g., into registers or into main memory)
- The job of a C++ compiler is twofold
    - **Verify that the program is syntactically and semantically legal**, meaning that it is structured properly and it passes various static checks (e.g., static type checking) that are intended to prevent obviously erroneous programs from being able to run.
    - **Emit machine instructions that have the same observable effect as the C++ program being compiled**. In other words, to someone running the program, the program's output and effects should be what would be expected given the abstractions provided by C++.
        - One minor, but interesting, point is that there's no law that says the machine instructions have to faithfully follow what the program says, as long as the observable effect is the same. This allows compilers to perform optimizations, which are intended to make programs run faster, use less memory, consume less power, and so on. For example, if a compiler can determine that some statement can't be reached, because, say, it's in an if statement whose condition must always be false, the compiler can simply not emit any code for that statement at all. Since the statement couldn't be reached, emitting no code has no effect on the outcome of running the program.

- The stack pointer would keep track of where the top of the stack is