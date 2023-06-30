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
- One technique enabled by this discovery is pipelining, where a processor can be in different stages of executing different instructions simultaneously.
- CPUs will quite often take a guess, using a technique called *branch prediction*. Some CPUs allow compilers to encode a reasonable guess (e.g., in a loop, always guess that we'll stay in the loop, since that's true much more often than not in practice); other times, the CPU will use heuristics.
- CPUs nowadays also use another technique called *out-of-order execution*, which is to say that they are permitted to execute instructions in a different order than the order they're written in the program.
    - One reason they do this is to avoid pipeline stalls (e.g., if instruction 1 stores a value, instruction 2 uses it, and the next several instructions 3-10 don't use it and are otherwise independent, the CPU could do better by executing instruction 1, then instructions 3-10, and finally instruction 2). Of course, they're only permitted to do this when the observable result would be the same, so they have to be aware of where the dependencies between the instructions are (i.e., which instructions need the results of which others).
- Branch prediction and out-of-order execution sounds like a low-level detail that you'd never need to be concerned with, but it's actually quite important, particularly in programs that run on multi-core CPUs that share caches and/or memory. To write code that makes proper use of more than one core simultaneously, it's sometimes necessary to take steps to manually prevent certain kinds of out-of-order execution; compilers can handle some of it, but, as it turns out, not nearly all of it. The most recent C++ standard includes library support for tools to make this job easier, but it's exacting stuff!
## More About Functions
- A reference in C++ is said to be "an alternative name for a value." A reference is said to refer to a value, and it then acts in every way just like the value it refers to; all you've done, in effect, is establish a synonym for that value.
- To be clear, the kinds of references we're talking about here actually have a longer name in the C++ Standard: lvalue references.
int& ir = 3; // not legal, reference type must initialize with lvalue
int i = 3;
int& r = i; // legal, i is a lvalue
- References must be initialized explicitly when they're defined, so that they refer to something of the appropriate type.
- Once a reference is initialized, it cannot be changed to refer to something else; a reference will refer to the same location for its entire lifetime.
    - For the duration of the function's execution, a parameter of a reference type will refer to the corresponding argument.
- **For a pass-by-value parameter, as long as the corresponding argument is a compatible type** (i.e., they're the same, or there's an implicit conversion between them), it will be legal to pass it.
- **For a pass-by-reference parameter, the types actually have to match**. Because the reference is referring to the actual location in memory, it's important that this location is treated identically, otherwise assigning to it might give a radically different result than you expected.
- t's possible to declare a function with default arguments, so that parameters that have common values can be substituted by defaults if they're not specified in calls to that function.
double vectorLength(double x, double y, double z = 0.0)  
{  
    <ul>
    return std::sqrt(x * x + y * y + z * z);  
    </ul>
    <ul>
}  
</ul>  

## Pointers and the Heap
- Things that are said to be *static* are often understood to be things that happen before a program runs (e.g., things that are determined by a compiler), - while *dynamic* things are things that happen while a program runs.
- *Static allocation* is done before a program runs. In the case of C++, that means the compiler determines the object's size and (relative) position in memory (e.g., if it's a local variable of a function, where in that function's activation record the object will be stored).
- *Dynamic allocation* is done while a program runs. As the program is executing, an object might need to be created on the fly, only to be destroyed at some other time. In the case of C++, dynamic allocation is done using the keywords **new** and **delete**, which, respectively, allocate and deallocate an object dynamically. (If you've written programs in Python or Java before, it should be noted that most allocation in these languages is actually dynamic, but that the deallocation is done automatically by a *garbage collector*. In C++, by contrast, both allocation and deallocation are the programmer's responsibility.)
- In the heap, anything goes:
    - Your program decides when memory will be allocated, how much of it will be allocated, and what types of objects will be stored there. That memory is allocated only when the program explicitly asks to do so.
    - Your program decides when memory will be deallocated, making that memory available to be reused elsewhere. That deallocation happens only when the program explicitly asks to do so, and the memory is not available to any other part of the program until that deallocation has been done.
- A pointer in C++ is a very thinly-veiled abstraction for a memory location. A pointer is actually a combination of two things:
    - A memory address, in a literal sense. As we've seen, every tiny block of memory — often, every single byte — generally has a numeric address, which you can think of as being like an index into a giant array. So if you want to keep track of the location of something in memory, you need only keep track of its address.
    - A type. Every pointer knows what type of object it's pointing to.
- As declarations begin to become more complex, it becomes important that we establish a good way to read and understand them. A good rule of thumb that works in many cases is to read them in a **right-to-left manner**.  
int* x; // x is a pointer to an integer  
- It's often called the *address-of operator*, and is indicated by an **&**.  
int i = 3;  
int* p = &i; // p stores the address where i is located  
- you can have pointers to pointers, though this isn't something I find myself doing very often — but it's also not something I've never done. For example:  
int i = 3;  
int* p = &i; // p is a pointer to an integer
int** q = &p; // q is a pointer to a pointer to an integer  
- you use an operator called the *dereference operator* (so we often call this dereferencing a pointer), which is represented by __*__. When the * operator precedes a pointer in an expression, you're asking for the object that the pointer points to.
- In general, if you have an int* p:
    - p is an expression that evaluates to the pointer itself (i.e., a memory address where you would find an int)
    - *p is an expression that evaluates to the object that the pointer points to (i.e., an int)
- As you might imagine, then, **&** (address-of) and __*__ (dereference) are the inverse of one another.
int i = 3;  
int* p = &i;  
std::cout << i << std::endl; // i = 3  
*p = 4;
std::cout << i << std::endl; // i = 4  
- References are implicit synonyms for objects, whereas pointers explicitly store the location of another object.  
int* p = new int;  
*p = 3;  
int*& s = p; // s is a reference to a pointer to an ineger  
*s = 6;  
- **There are no pointers to references in C++**.       
    -References are treated identically to the objects they refer to, so a pointer to reference would have no useful meaning; it would be no different from a pointer to the object that the reference referred to. For that reason, C++ simply disallows them.
- When you allocate, say, a new int, you've asked for your program to do three things, right then and there:
    - Find a block of memory on the heap that's not already allocated, one that is big enough to store an **int**. (So, for example, on the ICS 45C VM, that would be four bytes.)
    - Provided that a block of memory was found — and we'll talk another time about the consequences of running out of memory and how you deal with them, but we currently lack the techniques in C++ to do so — that block of memory is allocated, which means that it will be "cordoned off," in a sense, so that it can't be allocated anywhere else until after you explicitly deallocate it later.
    - The location of that allocated memory on the heap is returned to you. Since we're talking about an address in memory, what you get back is a pointer, with the type of that pointer determined by the type of object that you asked for, so **new int** would give you back an __int*__.
-  The presence of an automatic garbage collector has two positive effects:
    - It makes it much more difficult (though still not impossible) to suffer from *memory leaks*. When you allocate memory dynamically, it is considered to be "in use" and can't be allocated again until it's been deallocated first. **A memory leak is simply allocation without subsequent deallocation**, meaning that a program (particularly a long-running program) gradually uses more and more memory until it suffers serious consequences such as a major slowdown or even a crash. Provided that you don't keep pointers/references to objects that you no longer need, running out of memory is not something you have to think about very much in a garbage-collected language, unless your program needs to actually use a lot of memory at a time.
    - Garbage collectors are generally conservative about deleting objects, opting to do so only when they are provably inaccessible, so they make it impossible to have a *dangling pointer* or *dangling reference*, which is a pointer/reference to deallocated memory. If you can access an object, you know it's a "live" object.
- You can think of the **delete** operator as being a kind of inverse of the **new** operator.
    - The **new** operator allocates an object on the heap and returns a pointer to it.
    - The **delete** operator takes that same pointer and deallocates the object that it points to.  
- You can read delete p as meaning "Delete the object that the pointer p points to."  
int* p = new int;  
*p = 3  
delete p;  
- After the point where we say **delete p**, the pointer **p** is still in scope, but dereferencing it (i.e., following it to the now-deallocated memory it points to) results in undefined behavior.
- Every time you create an object with **new**, think about what part of your program should be responsible for deleting it. If the answer is "the same function in which it was created," what you probably want is a statically-allocated local variable instead, *unless* the object is particularly large or has an indeterminate size. If the answer is anything else, now you have some design work to do.

## Single-Dimension Arrays
- An array is a sequence of cells that live contiguously — one directly following another — in memory.
    - The cells are all of the same type (e.g., int, std::string, or whatever) and, hence, they all have the same size.
    - Additionally, there is no standard, generally-applicable construct in C++ to ask an array its size; if you want to keep track of an array's size, you'll have to do so separately.
- Statically-allocated arrays
void foo()
{
    int arr[10];
}
- Dynamically-allocated arrays  
int* arr = new int[10];  
delete[] arr;  
- address of cell i = (address of cell 0) + (sizeof(int) * i)
- Pointer arithmetic  
int a[10];                           // a is effectively a pointer to the first element of the array  
int b[10];                           // b is also effectively a pointer  
std::cout << a << std::endl;         // writes the address of a[0]  
std::cout << (a + 1) << std::endl;   // writes the address of a[1]  
*(a + 1) = 3;                        // stores 3 in a[1]  
std::cout << (a - 1) << std::endl;   // writes the address of a[-1]  
std::cout << (a - b) << std::endl;   // writes the distance in memory between a[0] and b[0] (divided by the size of an int)  
- Pointer arithmetic is very much like array indexing and, in fact, the array-indexing operations you write are ultimately translated by a compiler into the corresponding pointer arithemtic operations instead.

## Constness
- Declaring a variable whose value can't be changed is as simple as prepending the word const to its type. Note that const is actually part of the variable's type. For example, consider these two declarations:  
const int x = 3;  
- it's easiest to read these from right to left, so we would say that "x is an integer constant"  
- Let's consider some of the following declarations and decide whether they're legal or illegal.
const int x = 3;  
int& r = x; // Referring r to x is illegal, because it would introduce the possibility of assigning into r, which would, in turn, change the constant value of x.  
int* p = &x; // Pointing p to x is illegal, because it would introduce the possibility of assigning into *p, which would, in turn, change the constant value of x.  
int x = 3;  
const int& y = x;  
- The key thing to understand is that a reference to a constant doesn't necessarily guarantee that the value it refers to will never change; it simply guarantees that the reference itself will never be used to change the value.  
- The ability to declare a reference to a constant solves a problem we had earlier: how to point a reference to a variable that's already const. The solution is to use a reference with const in its type also.  
const int x = 3;  
const int& y = x;  
- Consider, for example, a function that prints the characters of a string in reverse. One way to implement that function might look like this:  
void printInReverse(const std::string& s)  
{  
    <ul>
    for (int i = s.length() - 1; i >= 0; --i)  

    {  
        std::cout << s[i];  
    }  
    </ul>
    <ul>
}  
</ul>

- There's no reason why this function should need to operate on a copy of the string passed into it, which might be quite large. But there's also no reason why the function would ever make any change to the string that's passed to it. The type const std::string& captures this idea perfectly.
- There's one more useful wrinkle. As we saw before, one thing you give up when you use pass-by-reference parameter passing is the ability to pass an rvalue as an argument. This restriction is lifted for parameters with const reference types, since the problematic operation — changing an rvalue, which has no storage associated with it — is not an issue if the value can never be changed.
- When you consider the effect that const might have on a pointer's type, you realize that there are four possibilities for what you might like to hold constant:
    - Nothing; either p or *p can change. (This is the default for a pointer, when you don't specify const anywhere in the pointer's type.)
    - Hold the pointer p constant (i.e., you can't point it somewhere else), but allow *p to change.
    - Hold *p constant (i.e., you can't change the value the pointer points to), but allow p to be pointed somewhere else.
    - Hold both the pointer p and the value *p to be constant (i.e., you can't change the value the pointer points to, and you can't point it somewhere else).  

__int* p; // a pointer to an int  
const int* q; // a pointer to an int constant  
int const* r; // a pointer to an constant int (equivalent to q)  
int* const s; // a constant pointer to an int  
const int* const t; // a const pointer to an int constant__  
- p is a pointer to an int. Neither the pointer nor the value it points to are const-protected.
- q is a pointer to an int constant. The value that q points to cannot be changed via q (e.g., attempting to assign to *q will be an error), but q can be pointed somewhere else.
- r is a pointer to a constant int. This turns out to mean exactly the same thing we said when we declared q. const int and int const are two syntaxes for saying the same thing. (In fact, you'll find disagreement in the C++ community about which of these is the proper thing to say. Those that prefer const int are sometimes said to prefer "west const" (i.e., the word const on the left) and those that prefer int const are sometimes said to prefer "east const." It seems I have a preference for west const, but I don't feel especially strongly about it; I think consistency across a large code base is probably more important than which of these you prefer.
- s is a constant pointer to an int. It will be possible to modify the value s points to, but s cannot be pointed anywhere else.
- t is a constant pointer to an int constant. It will be illegal to change both t and *t.

## Structures
- *homogeneous data structures* — collections of some number of elements of the same type
- *heterogeneous data structures* — where we bring together multiple values of potentially different types into a single entity.
- We can initialize a struct's members at the point where we create it using C++'s *uniform initialization* syntax — which, as we'll see, standardizes the way that objects of most types can be initialized.

void foo()  
{  
    <ul>
    Date today{2016, 10, 2};  
    ...  
    </ul>
}  

- The construct **{2016, 10, 2}** is called an *initializer list*, which specifies a sequence of values that are to be used to initialize today.
- A middle ground called *designated initializers* will be introduced in C++20, which would allow you to name the members you're initializing.

void foo()  
{  
    <ul>
    // Not legal yet, but will be legal in C++20  
    Date d{.year = 2016, .month = 10, .day = 2};  
    ...  
    </ul>
}  

d.year = 2005;     // Illegal, because d is a pointer; it has no member called year  
*d.year = 2005;    // Also illegal, because "." has a higher precedence than "*"  
(*d).year = 2005;  // Legal, but ugly as sin!  
d->year = 2005;    // Much nicer!  

- Similar to statically-allocated structs, you can use an initializer list to give values to the struct's members at the time of creation.  
Date* d = new Date{2016, 10, 2};

- Syntactically, passing a struct as a parameter is unsurprising.

void foo(Date d)  
{  
    <ul>
    // d is a copy of the struct passed as a parameter  
    </ul>
}  

void bar(Date& d)  
{  
    <ul>
    // modifications to d take effect in the caller  
    </ul>
}  

var baz(const Date& d)  
{  
    <ul>
    // d is not a copy, but it can't be modified  
    </ul>
}  

- Accessing any single byte is generally about as fast as accessing any other one.
- Accessing two bytes is best done on a two-byte boundary (i.e., a memory address that is a multiple of 2).
- Accessing four bytes is best done on a four-byte boundary (i.e., a memory address that is a multiple of 4).
- Accessing eight bytes is best done on a eight-byte boundary (i.e., a memory address that is a multiple of 8).
- Consider, then, where the members of an X would be stored if one was placed immediately after another:

- a would be at the beginning of the struct (i.e., at an offset of 0 bytes from the beginning)
- b would be just after a, so at an offset of 1 byte from the beginning, since a is 1 byte
- c would be just after b, so at an offset of 5 bytes from the beginning, since b is 4 bytes
- d would be just after c, so at an offset of 7 bytes from the beginning, since c is 2 bytes
- The problem is that accessing the four-byte value of b, the two-byte value of c, and the eight-byte value of d would all be significantly slower than they need to be, because none of them are aligned on a proper boundary. 
- So C++ compilers quite often introduce *padding* into a structure, bytes that are intentionally left unused, but that serve to improve access speeds to the individual members by placing them at the appropriate boundaries.

## Illuminating the Dark Corners
- The first tool that will be handy for us is called *Valgrind*.
- Valgrind is actually a whole collection of tools for monitoring a program and watching for different kinds of issues that can be indicative of problems;
- However, we'll only be using one of Valgrind's tools, which is called *Memcheck*.
- Memcheck monitors a C++ program while it runs — watching as memory allocation and deallocation happens, as pointers are followed, arrays are indexed, and so on — and reports various errors as they're detected.
- Some examples of things that Memcheck can detect are these.
    - Decisions being made (e.g., conditions that drive if statements or loops) on the basis of variables whose values have never been assigned, which means the outcome is undefined.
    - Attempting to use memory that's never been allocated, such as following an uninitialized pointer to where it points, which means that the result you get is undefined.
    - Attempting to use memory beyond the boundaries of memory that's been allocated (e.g., using array cells outside the boundaries of the array), which is undefined behavior, as well.
    - Attempting to deallocate memory that was never allocated, or deallocate the same memory twice, which is also undefined behavior.
    - When a program ends, any memory that's been dynamically allocated and never deallocated is reported as a memory leak.
    - One very useful mistake that Memcheck can catch is the use of values that have been uninitialized.
        - Remember that using an uninitialized value is considered undefined behavior in C++, which means that it's technically legal (in the sense that a program can compile with this problem) but that you can't count on what the outcome will be. In some circumstances, compilers will warn you about these things, such as in this example.

- If we forget to deallocate something, Memcheck will report it as a memory leak. But what happens if we deallocate the same memory twice?

void foo(int* a)  
{  
    <ul>
    delete a;  
    delete a;  
    </ul>
}  

- Another potential mistake is deleting stack-allocated memory.

void foo(int* a)  
{  
    <ul>
    delete a;  
    </ul>
}  

void bar()  
{  
    <ul>
    int x;  
    foo(&x);  
    </ul>
}  

- First, we should clear up a misnomer: A debugger doesn't actually debug anything. You debug programs by using one.
- The job of a debugger is to make visible the inner workings of your program — the values of variables, the contents of the run-time stack, and so on — along with the ability to pause your program at opportune times and then inch forward slowly, so you can see the effect of individual lines of your code as they run, asking questions about its "paused" state before inching it forward some more.
- Some debuggers even let you "rewind" a program backward instead of just pausing and moving forward — a technique that's cleverly called time-travel debugging — though ours doesn't have that particular ability.
- When we break on line 7, we break before line 7 runs.
- Step "over" to the next line of code in this function, regardless of whether it calls into a function (i.e., if there's a call to a function on this line, finish running that whole function, because I don't want to step through it).
We do this in LLDB using the command thread step-over or the command next.
- Step "into" this line of code, so that if it calls a function, we pause at the first line of code within that function. This lets me step through that function line by line, as well, if I want to see the details about how it works. (On a line of code containing no function calls, this is no different from stepping over.)
We do this in LLDB using the command thread step-in or the command step.
- Step "out" of the current function, pausing at the point where we've returned to its caller.
We do this in LLDB using the command thread step-out or the command finish.

## Classes
- In C++, a class is a blueprint for a new type of object.
- For example, we've seen that a *std::string* holds, among other things, a pointer to a dynamically-allocated array of *chars*.
- An interface, which specifies what information is stored by objects of a type and what those objects are able to do.
- An implementation, which specifies precisely what happens when objects of a type are asked to do things.
- A class' interface consists, broadly, of a set of members. There are two kinds of members we'll use for now — though I should point out that there are others that we'll see later.
    - Member variables, which specify data that are stored by objects of the class. These are analogous to the members that we saw in structs previously.
    - Member functions (also sometimes called methods), which specify operations that can be performed by objects of the class. Like regular functions, member functions specify a sequence of parameters and a return type. Unlike regular functions, though, they're called on a particular object (i.e., when we call them, we're asking some particular object to be the one to do that job).
- Some members are declared *public*, which means they are intended to be used by code outside of the class they're declared in.
- Others are declared *private*, meaning that they are only accessible to code within the class (e.g., private member variables in a class can only by accessed by the member functions in that class).
- In general, you should tend to want to make details of a class' implementation private whenever possible — or leave them out of the interface altogether, using local variables (or other constructs we've yet to see, such as the unnamed namespace) instead.
    - The fewer details you reveal to other parts of a program, the more of those details you can change without breaking the other parts;
    - This is the essence of how you write very large programs so that they can still be maintained over time. 
    - It's not about security; it's about writing each piece so that it relies on as few details of the other pieces as possible, so that changes are as controlled and localized as possible.
- A *class declaration* is how we specify the existence of a class. A class declaration is used to specify how objects of a class are used, and has two audiences:
    - A human reader, who will use the class declaration in order to understand how to write code that makes use of the class.
    - A compiler, which will use the class declaration in order to know how much memory to allocate to objects of the class, how its member variables are laid out, and what member functions can legally be called on objects of the class.

## Functions and Lambdas
- In C++, an object is called a function object if it can be called like a function (i.e., its name can be followed by parentheses surrounding a list of arguments separated by commas).