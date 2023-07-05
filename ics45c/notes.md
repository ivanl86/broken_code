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
        <ul>
        std::cout << s[i];
        </ul>  
    }  
    </ul>
}  

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
- Suppose we have this simple C++ function:  

int square(int n)  
{  
    <ul>
    return n * n;  
    </ul>
}  

- But what happens if we write the expression square, without writing parentheses and parameters after it?
    - This turns out to be legal in C++, and the result is a function object — technically, a pointer to the function
    - (which you can think of as the address where that function's compiled code begins), though this turns out to be less important in C++11 than it was in older versions of C++.
- If there are function objects, there must also be a way to do the same kinds of things to them that we expect to be able to do to other objects, such as these:
    - Store them in variables
    - Pass them as arguments to other functions
    - Return them as the result of other functions
    - Store them in member variables of a class and initialize them in a constructor
- Given a variable of type std::function<int(int)>, we could store any function in it, as long as that function had a compatible signature (i.e., it could be called with an int argument and return an int result).

int square(int n)  
{  
    <ul>
    return n * n;  
    </ul>
}  

// This is how you assign a function into a std::function variable.  Note  
// that there are no parentheses and parameters after "square".  This is  
// intentional, because the goal here is to assign the function itself into  
// "f", not the result of *calling* the function into "f".  
std::function<int(int)> f = square;  
// This is how we would call the function object held by a std::function  
// variable.  Note that the syntax is identical to how you would call any  
// other function!  A function object can be treated like a function.  
std::cout << f(3) << std::endl;  
- So what can you do with a std::function<int(int)> variable? Lots of things! For example:
    - Copy its value into another std::function variable of the same type (i.e., with the same signature)
    - Call the function it stores (by following its name with parentheses and arguments) and get back a result
    - Pass it as an argument to some other function
    - Return it as a result from another function
    - Store it in a member variable of an object of a class

- For example, consider the following function:

void transform(int* a, unsigned int size, std::function<int(int)> f)  
{  
    <ul>
    for (unsigned int i = 0; i < size; i++)  
    {  
        <ul>
        a[i] = f(a[i]);  
        </ul>
    }  
    </ul>
}  
- This makes transform an amazingly powerful function. Instead of being a function that does only a particular thing to every element, it's instead a more abstract function that can do any particular thing to every element, and you get to tell it what that particular thing is each time you call it!

- Languages that allow you to treat functions this way — that consider functions to be data, in the sense that you can pass them as arguments, store them in variables, return them as results, etc. — are said to (at least partially) support *functional programming*.
- (This is only part of what is technically called "functional programming," but a useful part, even in a language that doesn't support the rest.)
- C++ supports lambda expressions, though the syntax is a bit cumbersome. It helps to start with an example, so here's an example:  

transform(a, 10, [](int i) { return i + i; });  

- A pair of brackets at the beginning of an expression indicates that the following will be a lambda expression (i.e., a function literal).
- This is followed by parameters listed in parentheses, which is, in turn, followed by a body for the function.
- This particular lambda expression builds a function that takes an integer and returns the result of adding that integer to itself (i.e., doubling it).

- There are a couple of things to note here:
    - The return type does not need to be specified, since C++ is able to determine its type based on the body of the function. In this case, for example, since the body of the function adds i to itself and then returns the result, C++ can determine definitively that the return type is int.
        - (There are some more complex cases where the return type can't be determined, and C++ provides a syntax for specifying it in those cases where you need to.)
    - The brackets actually serve as more than just a way for the compiler to detect the beginning of a lambda expression. Additionally, you can specify how variables from the lambda's surrounding scope should be treated.
        - For example, in the example below, the **=** says "Make a copy of any variables from outside the function that are used in the function." Not surprisingly, you can also use an **&**, which means "Variables from outside the function that are used in the function should be treated as references to the variables outside the function."
- How member functions are different from other functions
- We've talked before about how member functions in classes are different from other functions. For example, consider this class:  

class Person  
{  
public:  
    <ul>
    ...  
    void setFirstName(const std::string& newFirstName);  
    ...  
    </ul>
};  

- It's important to note that the type of **setFirstName** is not **std::function<void(const std::string&)>**, because **setFirstName** actually takes two parameters:
    - The implicit this parameter that is the first parameter of every member function. (In this case, the type of this would be Person*, a pointer to the Person object on which the function is being called.)
    - The string parameter newFirstName.
- However, it does turn out that **setFirstName** has a type: it's **std::function<void(Person*, const std::string&)>**.

- For a member function that's const, such as this one:

class Person  
{  
public: 
    <ul>
    ...  
    std::string getFirstName() const;  
    ...  
    </ul>
};  

- the const would affect the type of that this parameter, so **getFirstName** would have the type **std::function<std::string(const Person*)>**.

## Linked Data Structures
- As a very simple starting point, the design of a LinkedList class might start out looking like the one below; I'm assuming here that each element of the list is an int value.  

class LinkedList  
{  
public:  
    <ul>
    LinkedList();  
    LinkedList(const LinkedList& list);  
    LinkedList& operator=(const LinkedList& list);  
    ~LinkedList();  
    // ...  
    </ul>
private:  
    <ul>
    struct Node  
    {  
        <ul>
        int value;  
        Node* next;  
        </ul>
    };  
    Node* head;     // pointer to the first node  
    </ul>
};  

- Notice that the Node struct has been declared as a private member of the LinkedList class, and that the next member variable is also private; this means that code outside of the LinkedList class won't even be able to say Node.
- In this way, there's no way to use the nodes of our linked list except within our LinkedList class, which is a good design choice, since it prevents us from spreading an implementation detail (how nodes are structured and linked) throughout our program.

- How we iterate through a linked list's nodes is to keep track of the location of a "current" node at any given time. We can use that current node's value in any way we need to, then use its next to make the next node be our "current" one. We're using pointers to keep track of locations, so this implies that our "current" node's location would be a variable of type Node*. We can use that pointer's "nullness" as a way to know that we've reached the end of the list.

int LinkedList::sum() const  
{  
    <ul>
    int total = 0;  
    // Begin by pointing 'current' to the first node in the list, which is the  
    // node that 'head' points to.  Note that if the list is empty, 'current'  
    // will now be nullptr.  Note, too, that the "const" here promises that we  
    // won't change the node that 'current' points to, not that we won't change  
    // the 'current' pointer.  Remember that we can read these kinds of type  
    // declarations from right-to-left: "current is a pointer to a Node that  
    // is constant".  
    const Node* current = head;  
    // When 'current' is nullptr, that tells us to stop (i.e., we've "fallen  
    // off" the end of the list.  So we'll loop while 'current' *isn't* nullptr.  
    while (current != nullptr)  
    {  
        <ul>
        // Add the current node's value to our running total  
        total += current->value;  
        // Update our current node to be the one that follows the current node.  
        // This moves us one node closer to the end of the list.  
        current = current->next;  
        </ul>
    }  
    // When we've iterated through the entire list and added every value to our  
    // running total, we can return the total; that's our sum.  
    return total;
    </ul>  
}  

- One important thing to understand about this example is that we haven't changed anything about any of the nodes. The current pointer has been made to temporarily point to each one, and we've updated that pointer along the way. When the member function ends, the current pointer (a local variable) dies, as it should. But none of the nodes has been changed.
- By way of contrast, consider another somewhat nonsensical example of a member function we might add to our LinkedList class: one that doubles every node's value.

void LinkedList::doubleAll()
{
    <ul>
    Node* current = head;
    while (current != nullptr)
    {
        <ul>
        current->value = current->value * 2;
        current = current->next;
        </ul>
    }
    </ul>
}

- There is one other minor syntactic issue that crops up in our design, which I'd like to warn you about if you want to go this route. Notice that we declared the Node struct as a member of the LinkedList class. This means that, from outside of the LinkedList class, its name is actually LinkedList::Node. This may seem irrelevant — if Node is private within LinkedList, when would we ever need to say its name from outside of LinkedList? — but it turns out to be important for one reason.
- Suppose you wanted to write a member function in LinkedList that takes a pointer to a Node as a parameter and returns a pointer to a Node. (It's not important what the function does; I just want to show you how to deal with its signature.) You might declare that member function like this:

class LinkedList  
{  
    <ul>
    ...  
    </ul>
private:
    <ul>
    ...  
    Node* foo(Node* n);  
    </ul>
};  

- When you implement that in a source file, you might be inclined to try to write it this way:

Node* LinkedList::foo(Node* n)  
{  
    <ul>
    ...  
    </ul>
}  

- But, unfortunately, this will turn out not to work. Node has no meaning outside of the scope of LinkedList and, technically, while the C++ compiler is reading your code, it doesn't consider itself to be in the scope of LinkedList until after it passes the part of your code where you've said LinkedList::. This means that the first use of Node in the function's signature will return a perplexing error message saying that Node has not been declared, even though the second use of Node (in the function's parameter) will be fine, because it follows where you said LinkedList::.

- The solution to this problem is to qualify Node's name where necessary:

LinkedList::Node* LinkedList::foo(Node* n)  
{  
    <ul>
    ...  
    </ul>
}  

- Note that we only have to do this to the return value, but not to the parameter, because the parameter appears after the name of the function and, hence, is considered to be in the scope of LinkedList.

## Unit Testing
- This kind of testing, where we focus on a single, small piece of a program — a single class, a single module, sometimes even a single function — in isolation from the others is called *unit testing*.
- There are some who would say that every line of code in a program should be covered by at least one unit test; this can be difficult to achieve in practice, but is a worthy goal if you can achieve it. It should be noted, though, that fully unit testing a program requires techniques we've not yet learned, so it's probably beyond the limits of what we can accomplish in this course. How you design a program is an important part of whether you can write unit tests for it.
- A test begins with the word **TEST** (all uppercase), followed by two names in parentheses, followed by the test's body between curly braces. So it looks like a function, though it has no declared return type, and the name of the test is actually specified within the parentheses.
- In every other way, you can think of these as C++ functions and, more or less, be right about it. (Technically, **TEST** is what's called a *macro*; it gets translated, behind the scenes, to a function and some other bits and pieces that help Google Test to find it and call it for you.)
- Individual tests are grouped together into what are called *test cases* (a slightly odd name, but you can think of them as test groups if it helps).
- For each test you write, you specify the name of the test case first, then the name of the individual test. So the test above is a test called **testName** in a test case called **TestCaseName**.
- Each test you write is intended to focus on one *behavior* of the code you're testing.
    - Note that I didn't say one function or one member function, for the simple reason that you quite often can't test one function without using others.
    - Behaviors are *sequences* of calls to functions for which there are known results. It's often the case that you need a sequence of calls before you have a result you can verify.
- Each test should focus on a single behavior, not a single function.
    - The goal is this: When a test fails, you should know exactly what scenario failed, rather than having to look through a long sequence of test code to try to decide what part of it is wrong.
    - If you want to test three different behaviors involving the same function, write three separate tests.
- When writing a Google Test, there are two ways to specify results that should be checked by your test: assertions and expectations. They are nearly the same, with one key difference:
    - An assertion specifies something that must be true at the point where it's written (e.g., the return value of the function blah() must be zero). If it's not, the test is aborted and is considered to have failed, and the report will show why.
    - An expectation specifies something that must be true at the point where it's written, similar to an assertion. If it's not, the test is considered to have failed, but the test continues executing anyway, so you can see if other expectations also fail in the same test, and the report will show all expectations that failed and why.
- You might argue that you could also just as easily check the title in that same test, but I would argue that this is a different behavior, so it should be a different test.

## Well-Behaved Classes
- Here are some things that objects of a well-behaved class do.
     - The statically-allocated portion of them is compact enough that it is possible to store objects of a well-behaved class on the run-time stack, so we can get the benefit of their automatically deletion when they fall out of scope. If these objects manage large amounts of memory, it's dynamically-allocated by the object behind the scenes.
    - They clean up after themselves automatically when they die, meaning that deleting an object is all that needs to be done to ensure that no other resources (memory, open files, etc.) associated with that object have leaked.
    - They can be passed to functions by value and preserve the usual semantics (i.e., changing the object within the function does not have any effect on the original). In cases where this doesn't make sense, this should be disallowed altogether, rather than silently behaving badly.
    - They can be assigned into existing objects of the same type, with the appropriate copying and cleanup, again, done automatically. In cases where this doesn't make sense, this should be disallowed altogether, rather than silently behaving badly.
    - They can be const, while preserving the ability to perform all operations that do not violate the promise of const. In other words, operations that do not change the publicly observable state of the object are legal; those that do potentially change it are illegal.
    - They shouldn't do unnecessary work or use memory or other resources unnecessarily; they should be efficient. (Note that the term "unnecessarily" is in the eye of the beholder; the goal isn't always to be absolutely as fast as possible, when that goal trades off against other desirable properties like readability, maintainability, or separation of concerns.)
- Classes whose objects manage resources that live outside of themselves — such as dynamically-allocated memory, open files, open connections to networks, etc. — generally require three new kinds of functions to be implemented.
    - A *destructor*. We've seen previously that constructors are called just after an object is created; their job is to initialize the newly-created object. Destructors are called just before an object's death, and they perform whatever cleanup is necessary (aside from the destruction of the member variables, which is handled automatically).
    - A *copy constructor*, which is used to initialize new objects that are created as copies of existing ones (e.g., because an object has been passed by value, or because one object has been used to explicitly initialize another).
    - An *assignment operator*, which is called every time an existing object is assigned into another existing object. Note that this is distinct from what a copy constructor does; copy constructors initialize newly-created objects, while the assignment operator is invoked when you have two objects already and one is being assigned into the other.
- These three functions, together, are sometimes called **The Big Three**, because the need to write one of them usually implies the need to write all three of them, and because they play a vital role in allowing many kinds of objects to manage resources properly.

- A default destructor has an empty body, meaning that the only thing destroyed are the member variables.
- By default, creating a copy of an object copies its member variables, one by one, into the new object. If those member variables are all well-behaved, they support the appropriate copying semantics already, so nothing special needs to be done.
- By default, assigning an object assigns its member variables one by one from the source object into the target object, in place of the original member variables in the target object. If those member variables are well-behaved, they support assignment already.
- Note, also, that the Big Three became the Big Five in the C++11 standard, because of the inclusion of a new feature called *moving*. I left that out of this example for the sake of simplicity, but moving does offer a significant performance optimization for some kinds of objects. We may see the tools for this — *move constructors* and *move assignment operators* — later in this course, but we'll wait on them for now; all things in time.

## C++ Standard Library
- The C++ Standard Library provides its data structures and algorithms in a portion of the library that is split, roughly, into three interlocking parts: *containers*, *generic algorithms*, and *iterators*.
- The C++ Standard Library provides a set of what are called containers (or data structures), some examples of which include:
    - std::vector, an array-based sequence, in the same spirit as the ArrayList class we wrote in a previous example
    - std::list, a doubly-linked list with head and tail pointers
    - std::map, a balanced binary search tree of key/value pairs
- Since a vector's elements are stored, behind the scenes, in a dynamically-allocated array, some things become immediately apparent:
    - A vector must have a notion of a capacity, which is to say that the array must have been created with a particular number of cells.
    - A vector stores its elements in array cells, so each element has an index.
    - Accessing an element, given its index, is a constant-time operation (i.e., it runs in O(1) time).
    - Inserting elements at the beginning of the sequence, removing elements from the middle of the sequence, and so on, are more expensive, requiring a linear number of operations (i.e., O(n), if there are n elements in the vector).
- The size of a vector is determined by how many things we're currently storing in it; 
- Its capacity is determined by how many things we can store in it without running out of space in the array.
- You can also initialize a vector to contain a predefined sequence of elements, using the same initializer list syntax we saw when we learned about structs previously. The objects in the initializer list become the vector's elements, while the size of the vector is the number of objects in the initializer list.  

std::vector<int> v{1, 2, 3, 4, 5};  

- For example, this variant creates a vector containing 10 elements that all have the value 100.  

std::vector<int> v(10, 100);  

- There is a bounds-checked alternative: a member function called at(), which throws an exception when an attempt is made to access an element outside of the boundaries of the vector's size (i.e., outside of the index range [0, size-1]).

for (unsigned int i = 0; i < 10; i++)  
{  
    <ul>
    v.at(i) += 10;  
    std::cout << v.at(i) << std::endl;  
    </ul>
}  

- If it looks strange to you that you can assign to the result of calling a function, this isn't as crazy as it looks. The at() member function returns a reference to the cell in question, as opposed to a copy of it, so that assigning to the result of calling at() is actually assigning directly into a cell of the array.
- Of course, if the vector is const, you won't be able to assign into its cells, since that would constitute a change to the vector's publicly observable state; in fact, anything that changes any element of the vector will be disallowed.  

void foo(const std::vector\<int>& v)  
{  
    <ul>
    v.push_back(15);   // illegal  
    v[3] = 50;         // illegal  
    v.at(3) = 50;      // illegal  
    for (unsigned int i = 0; i < v.size(); i++)      // legal  
    {  
        <ul>
        std::cout << v.at(i) << std::endl;     // legal  
        </ul>
    }  
    </ul>
}

- The C++ Standard Library provides a set of generic algorithms, which generalize commonly-occurring operations that you might like to perform, such as these:
    - Apply the same function to each of a range of values
    - Find a value in a range of values that has a particular, interesting property (e.g., is a positive number, is a student whose age is greater than 21, etc.)
    - Remove from a range of values those that have a particular, interesting property
    - Shuffle the values in a range of values randomly, so they appear in a different (randomly-determined) order than they did before
    - Sort the values in a range of values, possibly given an arbitrary function to compare pairs of values to see which should come first

- Iterators are the glue between the containers and the generic algorithms. An iterator is an abstraction for a position in a container, whose main role is the provide access to the value stored at that position (e.g., in a particular cell of a std::vector), while hiding all of the details about the container's underlying implementation.
- Syntactically, iterators behave a lot like pointers. In some cases, that's what they actually are; in others, they're more complex. But they support the same basic operators either way.
    - You can use the * operator to dereference an iterator, just like you can use the * operator to dereference a pointer. The effect is the same: Given an iterator i pointing to a position containing a value v, *i would give you access to the value v. As with pointers, you could do this on either side of an assignment, so you could read the value of *i or you could change it. Also similar to pointers, the -> operator is available if the values have members.
    - The ++ operator moves an iterator forward (i.e., to the next position in the container).
    - The -- operator moves an iterator backward (i.e., to the previous position in the container).
    - You can sometimes use other kinds of arithmetic (e.g., given an iterator i, writing i + 3 or i += 3 can be legal), which mirrors the pointer arithmetic we've seen previously.
- Iterators support whichever operations are sensible for the kind of container they're iterating, and they are categorized on the basis of which operations they support. A few examples of those categorizations are:
    - Forward iterators, which are able to iterate through a container in one direction (forward, one position at a time) but no other. This means they support * (dereferencing) and ++ (iterating forward).
    - Bidirectional iterators, which are able to do everything that forward iterators can do, plus iterate backward (i.e., they also support --).
    - Random access iterators, which are able to do everything that bidirectional iterators can do, plus arbitrary jumps using pointer-arithmetic-like syntax.

- Recall a loop that we wrote previously to iterate over an array using a technique called pointer arithmetic.  

int a[10];  
for (int* p = a; p != a + 10; p++)  
{  
    <ul>
    *p = 0;
    </ul>  
}  

- Recall what's being done here.
    - The pointer a points to the start of the array (i.e., the array's first cell).
    - We calculate an "end position" from our knowledge of the array's size: a + 10 is a pointer to the cell directly following the last cell in the array.
    - We move the traversal pointer p forward by using ++ (i.e., more pointer arithmetic).
    - When we want to access one of the values in the array, we dereference the traversal pointer using the * operator.

- While one could argue that this is a fairly obtuse piece of syntax, it turns out to be important to understand it, because iterators in the C++ Standard Library work the same way. Iterators behave a lot like pointers do. We use * to dereference them, ++ to advance them, and calculate "begin" and "end" positions as a way to traverse the elements. The only difference is the types at work.  

std::vector\<std::string> s;  
// ...  
for (std::vector\std::string>::iterator i = s.begin(); i != s.end(); i++)  
{  
    <ul>
    std::cout << *i << std::endl;  
    </ul>
}  

- And since iterators behave like pointers, we can also use the -> operator to access members of the values they point to, just like pointers.  

for (std::vector\<std::string>::iterator i = s.begin(); i != s.end(); i++)  
{  
    <ul>
    std::cout << i->length() << std::endl;  
    </ul>
}  

- Beginning in C++11, C++ compilers include a new feature called type inference, which allows the compiler to deduce the proper type for you automatically, instead of you having to say it. The way you ask for this behavior is simple: specify the type as auto.  

for (auto i = s.begin(); i != s.end(); i++)  
{  
    <ul>
    std::cout << i->length() << std::endl;  
    </ul>
}  

- Let's consider a function that prints all of the elements in a vector of strings.  

void printAll(const std::vector\<std::string>& v)  
{  
    <ul>
    // What would be the appropriate type for i?  
    for (??? i = v.begin(); i != v.end(); i++)  
    {  
        <ul>
        std::cout << *i << std::endl;  
        </ul>
    }  
    </ul>
}  

- As we've seen, the word const can be used in different places and mean different things. Let's think about some possible ways to write the correct type for i.
    - std::vector\<std::string>::iterator would be incorrect, because the iterator type implies that values can be either read or written, which would violate the constness of the vector. (Because the vector is const, anything that introduces the possibility of changing the vector will be illegal; an iterator introduces that possibility.)
    - const std::vector\<std::string>::iterator would also be incorrect, because it implies that the iterator itself can't be changed (i.e., you wouldn't be able to advance it forward using ++), and that you could still use it to modify the elements of the vector, which would violate the vector's constness. We don't want the iterator to be constant; we want the elements in the vector to remain constant.
- Unfortunately, there isn't anywhere else we could legally add the keyword const to this type declaration to mean something different. But there is a way to say what we want to say here: use the type const_iterator instead of the type iterator. A const_iterator is one that can be used to read values from a container but not change them. So, the proper type for i would be std::vector\<std::string>::const_iterator.  

void printAll(const std::vector\<std::string>& v)  
{  
    <ul>
    for (std::vector\<std::string>::const_iterator i = v.begin(); i != v.end(); i++)  
    {  
        <ul>
        std::cout << *i << std::endl;
        </ul>  
    }  
    </ul>
}  

- Note, too, that the auto keyword would deduce this automatically, because of the vector's constness, making this code equivalent. (It's in matters like this where auto really shines.)  

void printAll(const std::vector\<std::string>& v)  
{  
    <ul>
    for (auto i = v.begin(); i != v.end(); i++)  
    {  
        <ul>
        std::cout << *i << std::endl;  
        </ul>
    }  
    </ul>
}  

- You may have noticed that there is a recurring pattern in these examples:
    - Start an iterator where begin() points.
    - Obtain each value the iterator points to.
    - Advance the iterator forward once per loop iteration until it points where end() points.

- In this pattern, the only reason we need the iterator is to track our position as we iterate; it's an implementation detail of our pattern, but is otherwise boilerplate. For this reason, another kind of for loop — called a range-based for loop — was introduced into C++. The range-based for loop automates precisely this pattern.  

std::vector<int> v{1, 2, 3, 4, 5};  
for (int i : v)  
{  
    <ul>
    std::cout << i << std::endl;  
    </ul>
}  

- Behind the scenes, the range-based for loop is turned into this equivalent:  

std::vector<int> v{1, 2, 3, 4, 5};  
for (std::vector\<int>::iterator v_iterator = v.begin(); v_iterator != v.end(); v_iterator++)  
{  
    <ul>
    int i = *v_iterator;  
    std::cout << i << std::endl;  
    </ul>
}  

- It should be noted, too, that the range-based for loop doesn't work only on vectors; it works on anything that looks like a C++ Standard Library container (i.e., it has begin() and end() that return iterators).
- As with the use of auto that we saw previously, constness is handled properly and automatically. And we can even avoid copying the vector's elements into our loop variable by using techniques like const references.

void printAll(const std::vector\<std::string>& v)  
{  
    <ul>
    for (const std::string& s : v)  
    {  
        <ul>
        std::cout << s << std::endl;  
        </ul>
    }  
    </ul>
}  

- For example, suppose we wanted to print all of the values in a std::vector\<std::string> to the standard output, one per line. The std::for_each algorithm will make that very simple, indeed.  

#include \<algorithm>   // This is where the generic algorithms are declared  
#include \<string>  
#include \<vector>  

void printStringLine(const std::string& s)  
{  
    <ul>
    std::cout << s << std::endl;  
    </ul>
}  
// ...  
std::vector\<std::string> v;  
// ...  
std::for_each(v.begin(), v.end(), printStringLine);  

- The first two arguments to std::for_each specify the range of values that we want to operate on; in this case, we're passing the entire contents of the vector v by using the begin() and end() member functions. The third argument specifies the function that we want to apply to every value; in this case, we've passed our own printStringLine function, which prints a single string value on a line by itself.
- Note, too, that the generic algorithms that accept functions as arguments actually accept function objects, which means that we can pass anything that can be called as a function, including not only functions that we've written, but also arbitrary objects with overloaded function call operators, including the ones built by lambdas.

std::vector\<std::string> v;  
// ...  
std::for_each(  
    <ul>
    v.begin(), v.end(),  
    <ul>
    [](const std::string& s) { std::cout << s << std::endl; }); 
    </ul>
    </ul> 

## Inheritance and Polymorphism
- It's often said that object-oriented programming is characterized by three main features:
    - Classes, which give you the ability to describe new kinds of objects, which encapsulate a set of data along with a set of operations that safely manipulate that data.
    - Inheritance, which gives you the ability to describe new classes that are extensions or updates of existing ones, allowing you to write many similar classes without having to manually duplicate code between them.
    - Polymorphism, which, broadly, gives you the ability to write code that can take on different meanings at run-time depending on context. Most notably, in object-oriented languages, this means that calls to member functions on objects will be resolved in favor of the kind of object the function was called on. (In short, when you ask a particular object to do a job, the "right thing" happens automatically.)
- We can introduce an inheritance relationship between two classes X and Y, in which Y is said to be a derived class of X and, in turn, X is said to be a base class of Y. The way you introduce that relationship is to describe it in the declaration of the derived class, like this:

<p>
class X { ... };

class Y : public X { ... };
</p>

- The : operator in this context can be read as *derives from* or *inherits from*. The word **public** in this context means that the inheritance relationship is known throughout the program (i.e., code anywhere in the program can make use of this fact); while there are other ways to express inheritance relationships, ours will be public much more often than not, so we'll reserve a conversation about other ways for later.
- Conceptually, inheritance indicates what we often call an *is a* relationship (i.e., a Y object is an X). This concept makes more sense given a specific example, like a Student class that inherits from Person; in that case, we would be saying logically that "a Student is a Person," which makes good conceptual sense. Almost everything that's true of a person is also true of a student, but students have additional qualities and are in certain ways different from other people.
- Once this relationship is introduced in C++, it has a few effects:
    - The class Y automatically has all of the members — e.g., member functions, member variables — declared in the class X, except for constructors and destructors. This is where the "inheritance" comes in: Y is said to inherit these things from X, so that we don't have to rewrite them in Y.
    - You can introduce additional members into Y, different from the ones inherited from X, by simply declaring them within Y's class declaration. This is how you give Y objects new abilities that X objects don't have.
    - You can replace existing member functions inherited from X with new implementations that are specific to Y, by re-declaring them in Y's class declaration with the same signature as those inherited from X, and then defining the new member function (i.e., giving it a body). This is called *overriding* one of X's member functions. This doesn't give Y objects any new abilities, but it does change how certain abilities inherited from X behave.
- First of all, we'll be able to declare and define objects of each of these classes, X and Y.  

<p>
X x;<br>
Y y;  
</p>

- We'll also be able to dynamically allocate objects of both classes and point like-typed pointers to them, as you would with any other class.

<p>
X* px = new X; <br>
Y* py = new Y;
</p>

- And, similarly, we'll be able to use like-typed references to refer to these objects. (I'm assuming all of the code in this section is part of the same function.)

<p>
X& rx = x; <br>
Y& ry = y;
</p>

- Our first attempt at mixing types is to assign (or copy construct) a value of one type into a variable of a related type. Consider these possibilities, again assuming that the code earlier in this section has already executed.

<p>
Y y2 = x; // illegal<br>
X x2 = y; // legal
</p>

- Which of these do we expect will be legal? Let's consider them in turn:
    - We should expect that assigning **x** into **y2** will fail, because an **X** object does not contain enough information to properly initialize a **Y** object. Or, spoken more simply, **X**'s aren't necessarily kinds of **Y**'s.
    - On the other hand, we should expect that assigning y into **x2** could succeed. Based on the notion of inheritance as an "is a" relationship, "a **Y** is an **X**." **Y** objects are kinds of **X**'s, so it makes at least some sense that it should be possible to assign a **Y** object into an **X** variable.
        - It does bring up an interesting question, though. What happens? An **X** object is only big enough to store all of the member variables declared in the **X** class. A **Y** object is bigger, assuming that it contains additional member variables (in addition to the ones inherited from **X**). The answer is what's called *slicing*. The member variables that **Y** inherited from **X** would be copied into the variable **x2**, while the others would be "sliced away" (i.e., they would be lost).
        - Notably, when all is said and done in this case, **x2** contains an **X** object, not a **Y** object, albeit one that was "sliced" from a **Y** originally.
- Pointers and references make for some more interesting behavior. Which of these do we expect will be legal?

<p>
X xx;<br>
Y yy;<br>
X& rxx = yy; // legal<br>
Y& ryy = xx; // illegal<br>
X* px = new X;<br>
Y* py = new Y;<br>
X* px2 = py; // legal<br>
Y* py2 = px; // illegal<br>
</p>

- The answer lies in the basic philosophical assumption that "a Y is an X."
- We expect, in general, that X pointers and X references can legally point to objects that are X's. But, because of the inheritance relationship between the two classes, Y's are X's.
    - So we can reasonably expect X pointers and X references to be able to point to Y objects.
    -   However, we don't expect the reverse to be true. An X is not necessarily a Y, so we don't expect to be able to point Y pointers or Y references to X objects.
- If we have a pointer of one type pointing to an object of a different type, we have another interesting question to consider. Suppose that the following member function is declared in both X and Y (i.e., Y has a version that overrides the version from X).

<p>
class X<br>
{<br>
public:<br>
    <ul>
    void foo();<br>
    </ul>
};<br>

class Y : public X<br>
{<br>
public:<br>
    <ul>
    void foo();<br>
    </ul>
};<br>
</p>

- Given the declarations above, what do we expect will happen in these cases?

<p>
rxx.foo();<br>
px2->foo();
</p>

- There are two possibilities.
    - X's version of foo() will be called, because the pointer and reference have type X.
    - Y's version of foo() will be called, because the objects are actually Y objects.
- Which of these possibilities holds true depends on how the **foo()** function is declared. The latter behavior — determining the version based on the type of the object — is an example of what's called *polymorphism*, where the same pointer might be used to call different versions of **foo()** at run time, depending on the kind of object the pointer points to.
- But polymorphism has a run-time cost (i.e., the cost of looking up the appropriate version of the function at run time, based on the type of the object), so this behavior is not the default in C++. You have to opt in, on a member-function-by-member-function basis, by declaring particular member functions to be virtual. We declare a member function to be virtual by putting the keyword **virtual** at the beginning of its signature in the class declaration.

<p>
class X<br>
{<br>
public:<br>
    <ul>
    virtual void foo();<br>
    </ul>
};<br>
<br>
class Y : public X<br>
{<br>
public:<br>
    <ul>
    void foo();<br>
    </ul>
};<br>
</p>

- Note that declaring foo() to be a virtual function in the class X automatically makes it virtual in all of the classes derived from X, so we don't need to mark foo() as virtual in the class Y. It's wise to be clear about the fact that you intend to be overriding a member function from a base class, though; there's more to be said about that in the next section.
- If foo() is virtual, then our calls to foo() using rxx and px2 will both call Y's version of foo(). If foo() is not virtual, then they would call X's version (i.e., the version corresponding to the pointer's or reference's type) instead.
- Member functions that are intended to override a member function from a base class are best marked with an override specifier, which means that the word **override** should be added to the end of their signature:

<p>
class Y : public X <br>
{<br>
public:<br>
    <ul>
    void foo() override;<br>
    </ul>
};<br>
</p>

- While this is not strictly necessary in C++ — technically, what makes Y::foo() override X::foo() is the fact that their signatures match (and what makes it useful is the fact that the member function is virtual) — it is a good habit to get into, for at least a couple of reasons:
    - Your code reads more clearly, because the word **override** in its signature alerts the reader to the relationship between the member function and a corresponding one from a base class.
    - More importantly, if you specify that this is your intent, the compiler will now check your intent, meaning that you'll be able to get back a compile-time error in any case where that intent isn't met, such as these:
        - You mark a member function with **override** in a class whose base class doesn't have a member function with that name.
        - You mark a member function with **override** in a class whose base class does have a member function with that name, but whose signature doesn't match.
        - You mark a member function with **override**, but that member function was not declared virtual.
    - In any of these cases, what you would get without the word override is a program that compiles and exhibits behavior other than what you were expecting. In other words, in none of these cases would your member function actually override a member function from the base class, but if you expected that it had, you would be misunderstanding your own program. Eliminating possible mistakes, by turning them into compile-time errors, is always a good thing.
- Note, too, that this argument is especially true of programs that evolve over time. If you were to change the signature of a member function in a class, any class derived from it would have to change. With **override** on the derived class' member functions, these issues would manifest themselves as compile-time errors and be quickly fixed. Without it, they would be issues that wouldn't surface until run-time, which might very well mean that they would be problems that you wouldn't notice right away, perhaps not until users of the program were affected.

## Abstract Base Classes
- We could begin with relatively straightforward implementations of Circle and Rectangle classes (and whatever other shapes we'd like to implement; feel free to practice by adding additional shapes to this example).

<p>
class Circle<br>
{<br>
public:<br>
    <ul>
    double area() const;<br>
    </ul>
};<br>
<br>
class Rectangle<br>
{<br>
public:<br>
    <ul>
    double area() const;<br>
    </ul>
};<br>
</p>

- One way to relate C++ classes that share the same interface (i.e., that have one or more member functions with identical signatures and identical meanings) is to make that relationship explicit using inheritance. We do that by introducing a base class that's general — not specific to any particular kind of shape — and then derive our Circle and Rectangle classes from it. A good name for that class might be Shape.

<p>
class Shape<br>
{<br>
public:<br>
    <ul>
    virtual double area() const;<br>
    </ul>
};<br>

class Circle : public Shape<br>
{<br>
public:<br>
    <ul>
    double area() const override;<br>
    </ul>
};<br>

class Rectangle : public Shape<br>
{<br>
public:<br>
    <ul>
    double area() const override;<br>
    </ul>
};<br>
</p>

- The trouble, though, is that there is no reasonable implementation for Shape's area() member function. What does it mean to ask a shape for its area? It depends on what kind of shape it is. The Shape class represents the abstract notion of a shape without being any particular kind of shape. And if we don't know what kind of shape we have, we don't know how to calculate its area.
- This issue arises in designs like this quite often, so C++ offers a way to establish the important fact about our design — namely, that all shapes can calculate an area the same way — while leaving the implementation details to be filled in by derived classes. We do this by declaring area() in the Shape class to be a pure virtual function, by using the rather bizarre-looking = 0 notation at the end of its signature. (You can read that as the word "pure" if it helps it to make more sense.)

<p>
class Shape<br>
{<br>
public:<br>
    <ul>
    virtual double area() const = 0;<br>
    </ul>
};<br>
</p>

- Doing this has two consequences:
    - **Shape::area()** has no body. It's not a function, but merely a placeholder for functions that will be defined in derived classes.
    - **Shape**, by virtue of having at least one pure virtual function, is a class that has member functions that are unimplemented. It would be dangerous to have **Shape** objects, because you might call one of these missing member functions on it, and the compiler wouldn't be able to prevent this from happening in all cases. So as soon as a class has at least one pure virtual function, it becomes a special kind of class called an abstract base class. It is not possible to create objects of an abstract base class — to protect you from inadvertently calling a pure virtual function — but it is possible to have pointers or references of these types, which is what makes polymorphism possible.
- Now that we have the Shape class, there's a natural way to express the idea that we want a variable that can potentially store any kind of shape. Of course, we can't use the type Shape for such a variable, but we can use a pointer or a reference instead. So, for example, we could implement a function in C++ that's analogous to our print_area Python function this way:

<p>
void printArea(const Shape& s)<br>
{<br>
    <ul>
    std::cout << "The area of the shape is " << s.area() << std::endl;<br>
    </ul>
}<br>
</p>

- The parameter s can be referred to any type of object that inherits from Shape. Meanwhile, because area() is a virtual function in Shape, the appropriate version of area() will be called based on the type of shape we have.
- We can also store collections of shapes, though we would now need to use pointers rather than references, since collections can change over their lifetime. For example, we could have a vector of Shape pointers, each able to point to any type of object that inherits from Shape.

<p>
double calculateSumOfAreas(const std::vector<\Shape*>& shapes)<br>
{<br>
    <ul>
    double total = 0.0;<br>
    <br>
    for (const Shape* s : shapes)<br>
    {<br>
        <ul>
        total += s->area();<br>
        </ul>
    }<br>
    <br>
    return total;<br>
    </ul>
}<br>
</p>

## Type Conversions
- In C++, values of many of the built-in types can be *implicitly* converted to other built-in types. By *implicitly*, I mean that it is not necessary for you to ask for the conversion to take place; it simply happens, with the compiler deducing automatically that it's necessary based on context. The most obvious example arises in the various integral types, which we've seen before are implicitly convertible to one another.
- In C, it is legal to cast values of most types to values of most other types, simply by asking for the conversion to be done. We'll call these C-style casts. An example will drive the discussion:

<p>
int i = 3;<br>
int* p = (int*) i;<br>
<br>
std::cout << i << std::endl;   // prints <strong>3</strong><br>
std::cout << p << std::endl;   // prints <strong>0x3</strong><br>
</p>

- Not all C-style casts are so insidious, though. For example, if you have two int values and you want to divide one by another and get back a double result, it's not as easy as it sounds.

<p>
int i = 3;<br>
int j = 4;<br>
double k = i / j;<br>

std::cout << k << std::endl;   // prints <strong>0</strong><br>
</p>

- The reason that k's value is 0 is that division of two integers in C++ is defined as integer division, which is to say that we divide the two integers, discard whatever fractional part there might be, and return the result. So, rather than k having the value 0.75 that you might expect, it has the value 0 instead.
- One solution to this problem is to explicit convert one value or the other to a **double**. As long as one of them is **double**, even if the other is **int**, C++ will perform floating-point division and give you a **double** as a result. So one way to write that would be like this:

<p>
int i = 3;<br>
int j = 4;<br>
double k = i / (double) j;<br>
<br>
std::cout << k << std::endl;   // prints <strong>0.75</strong><br>
</p>

- Note, too, that parenthesization matters here, and in ways you might not expect. C-style casting has a higher precedence than most other operators, meaning that it binds more tightly to operands than, say, a division operator does. So, for example: **(double) i / j** technically means "Cast **i** to **double**, then divide that by the **int j**." Meanwhile, **(double) (i / j)** means "Divide the **int i** by the **int j** (yielding an integer), then cast the result to a double."

- You can use C-style casts to cast pointers from one type to another, which is occasionally useful when you want to do downcasting in an inheritance hierarchy (i.e., you have a <strong>Shape*</strong> pointing to an object that you know is a **Circle** and want to cast the pointer to <strong>Circle*</strong> instead). And C-style casts will do that, too.

<p>
Shape* ps = new Circle{3.0};<br>
Circle* pc = (Circle*) ps;<br>
</p>

- Though it should be noted that this cast will succeed whether the pointer really points to a **Circle** object or not. What you'll want is a pointer to an object that you'll now be able to treat as a **Circle**; if it's something else, you'll very likely end up with undefined behavior, or even a program crash. In fact, you can even use C-style casts to convert between pointers of completely unrelated types.

<p>
struct A<br>
{<br>
    <ul>
    int a;<br>
    </ul>
};<br>
<br>
struct B<br>
{<br>
    <ul>
    double b;<br>
    </ul>
};<br>
<br>
A* a = new A{3};<br>
B* b = (B*) a;<br>
std::cout << b->b << std::endl;   // on the ICS 45C VM, prints <strong>1.4822e-323</strong><br>
</p>

- C-style casts, ultimately, have two shortcomings, which means that they're best avoided in modern C++ programs.
    - Their syntax is difficult for human readers to parse, especially in complex expressions. Parentheses have too many other meanings already — function calls, constructor calls, overriding precedence and associativity of operators — which means that it's difficult to glance at an expression and recognize that it has a cast in it. But casts are places where potential danger lies, so we should want them to be obvious when they appear.
    - C-style casts can be used to accomplish very different goals: converting between numeric types, downcasting in an inheritance hierarchy, or even converting between values of unrelated types. However, there's no differentiation in the syntax; one syntax can do any of these things, which means that a small mistake won't always lead to a compile time error, but will instead compile into code that means something very different from what you intended.
- A *dynamic cast* is one that casts a pointer or reference of one type to a pointer or reference of a related type. In particular, by related type, I mean that they're class types that are related by inheritance, and that your goal is to downcast in an inheritance hierarchy (which is to say that you have a pointer of a base class type and you want to cast it to a derived class type). Consider the Shape example we've seen previously; this would be a legal use of **dynamic_cast**.

<p>
void foo(Shape* s)<br>
{<br>
    <ul>
    Circle* c = dynamic_cast<\Circle*>(s);<br>
    // ...<br>
    </ul>
}<br>
</p>

- Note the syntax here; the use of dynamic_cast looks very much like a call to a function template. As it turns out, **dynamic_cast** isn't really a function, but it doesn't hurt to think of it that way.
- The compiler will emit code that checks whether s is really pointing to a Circle object. If so, the cast succeeds and c will be a Circle* pointing to it; if not, the cast fails and **c** will instead be **nullptr**.
- There's one more small wrinkle: **dynamic_cast** will only work when the types involved have at least one virtual member function. It should be noted that this is generally the only circumstance where you'd typically want to use it, anyway.

- A *static cast* is one that is entirely resolved at compile time. That means there is an inherent risk involved, since the compiler can't necessarily be sure what the run-time type of an object is, given only a pointer to it. For example, if we rewrote our **foo()** function above this way:

void foo(Shape* s)<br>
{<br>
    Circle* c = static_cast<Circle*>(s);<br>
    // ...<br>
}<br>

- The cast will succeed regardless of what kind of object s points to, though subsequent use of the pointer c will lead to undefined behavior if the object isn't really a **Circle**. In a case like this, one reason you might choose **static_cast** over **dynamic_cast** is a performance reason (i.e., avoiding the cost of the type check at run time). As is often the case, there is a tradeoff here between safety and speed.
- But, at the very least, the compiler can check whether there's some chance of the cast succeeding (e.g., by checking whether there is an inheritance relationship between the types) and report an error at compile time if you try to use it for a conversion between unrelated types. And, additionally, you can use **static_cast** to invoke built-in conversions between non-pointer types, such as this one.

<p>
double d = 3.5;<br>
int i = static_cast<int>(d);   // legal, because such a conversion exists<br>
</p>

- A *reinterpret cast* is a very scary instrument, indeed. You can use **reinterpret_cast** to convert just about anything into just about anything else, similar to the C-style casts we saw previously. For example, a **reinterpret_cast** will allow you to convert between pointers of unrelated types, between integers and pointers, and so on.
- It's not often you need something like this — and it's best avoided if you don't have the absolute need, since it's so dangerous in practice — but it does come in handy once in a while to be able to make conversions in a completely unrestricted way. One such use is to cast pointers to <strong>void*</strong> and back, where void* is an untyped pointer: an address without a type. A void* doesn't let you do anything with the object it points to (since it's unknown what the object's type is), but a reinterpret_cast would let you cast the pointer to a different type, provided that you knew what the right type was. This is the kind of thing that's done in extremely low-level code, such as memory allocators, but if you find yourself doing this often in higher-level programs, your design is probably lacking.
- All of the C++ casts we've seen so far, including reinterpret_cast, are respectful of const, in the sense that none of those casts can be used to change a const type to a corresponding non-const type (e.g., to cast from const std::string& to std::string&). (On the other hand, C-style casts will let you do this, whether you meant to do it or not; this is one of many reasons they're best avoided.)
- In general, this is a good thing; we don't want const protections to be thrown away indiscriminately. But sometimes we have to remove it temporarily; for example, if we need to interoperate with someone else's C++ code and they didn't make proper use of const (e.g., they have a class with member functions that should be marked const but aren't), we may not have the ability to change their code, so we'll have to work around the problem if we want to make use of it. A const cast can be used to remove the const from a type, while introducing no other changes to it. (If you also wanted to change the type in some other way, you'd have to do two casts: a const_cast to remove the const and another one such as a static_cast or dynamic_cast to change the type.) A simple example:

<p>
void blah(const Blah& b)<br>
{<br>
    <ul>
    Blah& bb = const_cast<Blah&>(b);<br>
    bb.someMemberFunctionThatIsNotConst();<br>
    </ul>
}<br>
</p>

- As a rule, **const_cast** is something that should make you feel uncomfortable to use, because it represents a way to subvert invariants about how a program is supposed to behave. Once in a while, you have no choice, but it's very much a tool of last resort.

- Suppose we have a class called Transaction, where a Transaction has an ID that is initialized when it's constructed. (There might well be other interesting things about transactions in the context of the program we're writing, but we'll leave them out of this example to keep things simple.) We might write such a class this way.

<p>
class Transaction<br>
{<br>
public:<br>
    <ul>
    Transaction(int id): id{id} { }<br>
    int getId() const { return id; }<br>
    </ul>
<br>
private:<br>
    <ul>
    int id;<br>
    </ul>
};<br>
</p>

- Now suppose that you had the following two functions that take a Transaction as a parameter, one by value and the other by reference.

<p>
void val(Transaction t) { ... }
void ref(Transaction& t) { ... }
</p>

- Which of the following lines of code would you expect to be legal? (Take a moment to decide what you think before proceeding with reading this section.)

<p>
Transaction t1{14}; // legal<br>
Transaction t2 = 17; // legal<br>
int i3 = 555; Transaction t3 = i3; // legal<br>
val(72); // legal<br>
ref(89); // illegal<br>
</p>

- Let's consider them individually:
    - Transaction t1{14} will be legal, because this is clearly a call to Transaction's constructor, with a single parameter of type int. Transaction has such a constructor, so this one is fine.
    - Transaction t2 = 17 will be legal, as well. At first blush, it looks a bit ridiculous, but when you consider that copy constructors work this way, it's not entirely surprising; if assigning a value of the same type when constructing an object calls a one-argument copy constructor, maybe it's not so crazy that assigning a value of a different type works, as long as there's a one-argument constructor that accepts that type.

<p>
<ul>
Transaction t4{998};<br>
Transaction t5 = t4;   // calls the copy constructor<br>
</ul>
</p>

-
    - i3 = 555; Transaction t3 = i3 is legal for the same reason that Transaction t2 = 17 is legal.
    - val(72) looks entirely ridiculous. We're calling a function that accepts a Transaction by value, but we're passing it an int. And yet, oddly, this line is also legal, for the same reason as Transaction t2 = 17.
    - ref(89) is illegal, because a Transaction reference can't be made to refer to an object of the incompatible type int.

- One could certainly argue that this is not a sensible default — and plenty of folks much more well-known in the C++ community than me think so! — but it's long been the rule in C++, so it's not a rule that can be changed now without breaking a lot of existing code. Still, we don't have to live with this default; we just have to know how to turn it off.

- A constructor that is marked with the **explicit** keyword at the beginning of its signature is one that can only be called explicitly, which is to say that it can never be used to invoke an implicit type conversion. It's not a word you can use in the signature of anything but a constructor, and it only really makes sense to use it on a constructor that takes a single argument — the only circumstance where it will otherwise be easy to make a mistake like passing a parameter of one type and having it be implicitly converted to another type without us realizing it. But when you write a constructor that can be called with one argument, you should consider whether you want the implicit conversion to be a possibility; in my experience, the answer is more often than not "No!", but it's worth thinking about each time.

- So we could refine our **Transaction** example above like this:

<p>
class Transaction<br>
{<br>
public:<br>
    <ul>
    explicit Transaction(int id): id{id} { }<br>
    int getId() const { return id; }<br>
    </ul>
<br>
private:<br>
    <ul>
    int id;<br>
    </ul>
};<br>
</p>

- The one-word change, adding **explicit** to the constructor's signature, is enough to clean up our design, so that the things that seemed crazy now become illegal.

<p>
Transaction t1{14}; // legal<br>
// all illegal below
Transaction t2 = 17;<br>
int i3 = 555; Transaction t3 = i3;<br>
val(72);<br>
ref(89);<br>
</p>

- Of these examples, the only one that will now be legal is the first one. For a design like this, I would argue that it's the only one that made sense! One of the hallmarks of a good C++ design is one in which a program doesn't compile when you do something you shouldn't; much of what's been added to the language over the years has been added with the goal of making it possible for compilers to catch more of our mistakes for us automatically. But compilers can't do that unless we can communicate our intent; explicit is another in a long list of C++ features we've seen that allow us to do that.

## Static Members
- The static members of a class are the ones that belong to the entire class, instead of belonging to individual objects of that class. Static member variables exist whether you have objects of the class or not, independent of the individual objects of that class. Static member functions are called on the class, rather than being called on an object of the class; you don't even need an object of the class to call them, and they don't have access to non-static member variables unless you qualify them with an object of the class.
- An example of that would be implementing a feature to keep track of how many objects of some class exist. The code example below explores that idea by implementing a class called Widget. Widgets aren't especially interesting on their own — they store an integer ID and nothing else — but what is interesting about them is that it's possible, at any given time, to find out how many Widget objects exist (i.e., have been allocated but not yet deallocated). The trick is to add two things to the Widget class:
    - A static member variable that keeps track of how many Widget objects there are. This member variable needs to be static because there's only one such count; each Widget doesn't keep track of this count separately.
    - A static member function that makes it possible to ask how many Widget objects there are. This is best implemented as a static member function for two reasons:
        - Conceptually, it makes sense, since this is a question you are asking of the Widget class — "How many of you are there?" — instead of one particular Widget.
        - Having been implemented as a static member function, it will be possible to call it without first creating a Widget object, simply by saying Widget::getWidgetCount(). You shouldn't need a Widget in order to find out how many Widgets there are.

## Contracts and Exceptions
- To formalize what it means to "think a function's design all the way through," we can say that functions (including member functions of classes) have a contract associated with them.
- Part of that contract is specified formally as the function's signature; in C++, that signature lists the name of the function, the names and types of its parameters, and the type of its result.
- But a contract is more than a signature; to understand a function's contract, you have to finish your thought about its design. A function's contract consists, additionally, of (at least) the following:
    - *Preconditions*, which are the things that must be true before you can call the function and see it succeed. Some of these preconditions might be the values of its parameter (e.g., the sqrt function might require its parameter to be non-negative). Some of them might require other things to be true (e.g., other functions have been called successfully or, in the case of member functions, the object's member variables have to have certain values already).
    - *Postconditions*, which are the things that will be true once the function has completed successfully, assuming that the preconditions were all true. In the case of the sqrt function, we would expect to get a return value of type double if the preconditions pass; we would also expect that if we squared that value, we would get a result very close to the parameter's value (allowing some tolerance for the imprecision of doubles).
    - *Side effects*, which are the things that happen other than the function computing and returning a result. Examples include dynamically allocating or deallocating memory, writing output to the console or to a file, establishing a connection across a network, popping up a GUI window, and so on.
- Classes, too, have a contract associated with them. As with functions' contracts, the contract of a class is partly made up of what's written in the class declaration, as well as the contract associated with each member function. But, additionally, there is one other thing that is included:
    - *Class invariants*, which are the things that must always be true about the members of a class after each member function has completed successfully, above and beyond what's specified in the class declaration.
- The ArrayList class that I wrote in the Well-Behaved Classes example has a couple of invariants, beyond just the types specified in the declaration:
    - An ArrayList's capacity will always be at least as large as its size.
    - The capacity of an ArrayList will always match the number of elements in its underlying array.

- There would be two benefits if we could encode this information in C++, rather than in comments:
    - Specifying things like preconditions, postconditions, and class invariants in code instead of in a natural language like English would leave them less open to the ambiguity of natural language, which would improve a human reader's understanding of a program.
    - Being able to write actual C++ code that describes preconditions, postconditions, and class invariants would allow a compiler to perform some checking at compile time — though, in reality, there would be relatively few such violations that a compiler could reasonably catch — and also to (optionally) generate code that performs the checks at run-time. For example, a call to a function where the preconditions aren't met could simply cause the function to fail with a meaningful error message, rather than trying to muddle through with bad input.

- Our sqrt function might be declared this way:

<p>
double sqrt(double n)<br>
    <ul>
    [[expects: n >= 0.0]]<br>
    [[ensures: sqrt(n) >= 0.0 && std::abs(sqrt(n) * sqrt(n) - n) < 0.0001]];<br>
    </ul>
</p>

- Notice that we've explicitly specified that the parameter **n** has to be non-negative; the **expects** attribute is suggested as a way to specify preconditions. Meanwhile, we've specified that the result of calling the function, assuming that the preconditions are met, will be non-negative, and that the square of the result will be very nearly equal to the parameter **n**; the **ensures** attribute is intended as a way to specify postconditions.

- The proposal includes nothing specifically about class invariants, but you could certainly imagine such a syntax. For example, our ArrayList class might be declared this way:

<p>
class ArrayList<br>
{<br>
    <ul>
    // ...<br>
    </ul>
<br>
private:<br>
    <ul>
    std::string* items;<br>
    unsigned int sz;<br>
    unsigned int cap;<br>
    </ul>
}<br>
[[ensures: items != nullptr && cap >= sz]];<br>
</p>

- Where an **ensures** attribute on the class could be interpreted as a class invariant. (Why I chose the ensures syntax is that a class invariant can be thought of as a postcondition of all member functions.)
- Of course, it's not possible to write these kinds of things today in C++, but even though there is no syntax to support it, we have to be thinking about these things either way.
    - Whether your language lets you encode these things explicitly or not, functions have preconditions, postconditions, and side effects; classes have invariants.
    - **Part of how we understand our own designs (and each other's) is to understand these preconditions, postconditions, side effects, and invariants.**

- In any programming language, when you call a function (or the equivalent), you're asking that function to do a job for you, given a set of parameters that configure that job. There are two possible outcomes:
    - The function succeeds and returns some kind of result and/or has some kind of side effect.
    - The function fails to complete its job, in which case it needs to inform you of the failure in some way.
- There are different mechanisms for reporting failure in different programming languages, and there is not steadfast agreement in the programming language design community about how best to approach this problem, but one common approach — which appears not just in C++, but in a number of other programming languages, as well — is called an *exception*.

- In C++, the notion of failure is handled separately from success; functions that fail don't return a value at all, but instead throw an exception. (If you've previously programmed in Python, this idea will sound familiar, as it is more or less the same as raising an exception in Python.) How you handle an exception is entirely different from how you handle the return value of a function. The basic model works this way:
    - Functions either return successfully (and give back a return value, unless their return type is **void**) or they fail. When they fail, they do so by throwing an exception. The function has no return value in this case; failure is a completely separate mechanism.
    - C++ guarantees that any local variables in a function that have been initialized will be destroyed when a function ends by throwing an exception. So one large part of ensuring that exceptions don't cause memory or other resource leaks is to favor static allocation over dynamic allocation. If the local variables are pointers, they will be deallocated like any other local variables, but the objects they point to will not.
    - When a function fails with an exception, its caller will either handle the exception by catching it, or it will fail, too, in which case its caller's caller will have the same choice, and so on. If every function on the call stack, including **main()**, fails to catch the exception, the program will terminate. (We don't generally want programs to crash, but note that, as a practical matter, there are many fewer places where you'll catch exceptions than throw them; it's much more often the case that the failure of a function also implies the failure of its caller, though there are usually some places in a program where handling the exception can be done appropriately.)
    - Exceptions are objects and, in C++, they do not have to be particularly special. Any kind of object, including those of the built-in types like int or a pointer, can be thrown. By and large, we don't end up throwing built-in values like that very often, though; better to throw objects that capture the notion of what kind of failure happened and, if necessary, carry more information about the failure with them. The C++ Standard Library even provides base classes such as **std::exception** that you can inherit from, which can give all exceptions a handful of shared characteristics, such as a (C-style) string containing an error message.
    - Exceptions are caught on the basis of their type. A function doesn't just say "I know how to handle any error!" Instead, it says "I know how to handle *this particular kind* of error!" This is why it's important to give an exception a meaningful type; the type is how we distinguish one kind of failure from another.
- Syntactically, there are two things you will need to be able to do to use exceptions in a C++ program: throw them and catch them.
- Throwing an exception is best done by simply creating an object of the exception's type and using it as the argument in a throw statement. For example, if you had a class called MyException that had a default constructor, we could throw a MyException this way:

<p>
throw MyException{};<br>
</p>

- Note that we're best off allocating the object statically. If we allocated it dynamically using the new operator, what we'd actually be throwing is a pointer to that object, and, even worse, we'd also be obligating the code that handles the exception to delete it.
- Catching an exception is done by specifying a block of code in which you expect an exception may occur, along with an indication of what should happen if it does. This is done with a try block, which, structurally, looks like this:

<p>
try<br>
{<br>
    <ul>
    functionThatThrowsMyExceptionSometimes();<br>
    </ul>
}<br>
catch (MyException&)<br>
{<br>
    <ul>
    std::cout << "Doh!" << std::endl;<br>
    </ul>
}<br>
</p>

- If an exception is thrown in a catch, it's just like any other exception being thrown. Unless there is a try block inside the catch, the exception will be handled by a surrounding try block, or the call stack will be unwound as usual.
- Exceptions can be re-thrown in a catch by simply issuing the statement throw;, which is a way to say "I did some work, but this exception isn't completely handled yet; I just wanted to clean some things up before I failed, too." This is actually not all that uncommon, especially in code that has to do a lot of manual clean-up; this technique is sometimes called catch-and-rethrow. (Simplfying this is one of the reasons we should want to less of that kind of clean-up in the first place; we'll have more to say about that a little later in this course.)
- It is possible to write a catch handler that is capable of catching anything. You would write it this way:

<p>
catch (...)<br>
{<br>
    <ul>
    // Do anything you'd like here<br>
    </ul>
}<br>
</p>

It's important to note, though, that you will not have access to the exception object itself in the catch handler, because it hasn't been given a name, and because there is no single type that encompasses all possible exceptions that might be thrown. Where this technique is primarily of value is when using the "catch-and-rethrow" technique:

<p>
catch (...)<br>
{<br>
    <ul>
    // Do cleanup because of the exception, then rethrow it to be handled by the caller<br>
<br>
    throw;<br>
    </ul>
}
</p>

- You may have noticed that, in the examples above, exceptions are being caught by reference. This is the typical practice in C++, as it addresses two problems:

- It avoids copies of the exception being made, which can be a performance drag if those copies are expensive to make.
- More importantly, it allows us to catch exceptions of derived types without them being "sliced." It's not uncommon for exception types to be specified as an inheritance hierarchy, with less specific types of exceptions acting as the base classes for more specific ones (e.g., something less specific like IOException being the base class for a more specific FileNotFoundException) so the ability to catch a broader type of exception, but still have it behave polymorphically if you call a virtual function on it, is very useful indeed.
- Some people also advocate catching exceptions by const reference, like this:

<p>
catch (const MyException& e)<br>
</p>

- which makes clear that you won't be modifying the exception within the catch handler. I haven't picked up that style myself, but I can see at least some benefit to it.

- But this does bring up an interesting question. What happens if an exception is thrown, a local variable is destroyed automatically (which means that its destructor will be called), and its destructor throws an exception? We now have two exceptions that have occurred: the one we were propagating before, as well as the additional one thrown by some destructor in the process of propagating the first one. While the details here can be subtle, the usual outcome in this case is that the program terminates immediately.
- All in all, the best advice is that we should never throw exceptions in destructors, because destructors can be called in circumstances (such as the stack unwinding that happens while exceptions propagate) that will cause a program to crash immediately if the destructor throws an exception. Designing our classes so that destruction cannot fail turns out to be paramount.
- Why this fact makes our life simpler is that we can make a basic assumption:
    - If we use the delete or delete[ ] operators, it's safe to assume that they won't throw an exception. This can make it easier to design code that handles exceptions correctly and safely.
- This can be an overwhelming thing to think about if you've never considered it before, but, particularly in the case of member functions of classes, the C++ Standard Library provides a good mental model of how to think about these kinds of issues. Member functions of classes like std::vector are documented to make one of the following four guarantees about what happens when an exception is thrown. (The guarantees get progressively stronger as you read further down the list.)
    - No guarantee, which means that if a member function throws an exception, all bets are off. Class invariants may no longer hold, memory may have leaked or been corrupted arbitrarily, and so on. It may be a good idea for the program to attempt the most graceful exit possible at this point, since there is no way to know the extent of the damage that might have been done.
    - The basic guarantee, which means that if a member function throws an exception, the object that the member function was called on will be left in a consistent state (i.e., all of its class invariants will be met), though the object may have been altered. Furthermore, if an exception is thrown, memory and other resources will not have leaked.
    - The strong guarantee, which means that if a member function throws an exception, the object's state will be identical to what it was before the function was called. (This is also sometimes called the rollback guarantee.) As with the basic guarantee, memory and other resources will not have leaked. In general, this is a better guarantee to make than the basic guarantee, but is sometimes impractical because of cost.
    - The nothrow guarantee, which means that the member function guarantees that it can never throw an exception. It is unavoidable for some functions to throw exceptions sometimes — e.g., any function that dynamically allocates memory might throw a std::bad_alloc if that allocation fails — but plenty of functions (like the ArrayList::size member function in the ArrayList example from the Well-Behaved Classes notes) can be written in a way that guarantees they won't.
- Ideally, our goal should be to provide the strongest of these guarantees that we can, provided that it's possible and that the cost doesn't outweigh the benefit.
    - The nothrow guarantee is clearly not something we can provide all the time. A lot of functions, even perfectly-written ones, throw exceptions in some cases, because, for example, they may rely on external resources like heap memory, files, networks, and so on.
    - The strong guarantee can be an expensive guarantee to provide, sometimes resulting in an operation that has different complexity characteristics (e.g., O(n) instead of O(1) running time, or O(n) instead of O(1) memory). In a case like that, it's usually better not to provide the guarantee, but instead to design a way that the guarantee can be obtained when needed (e.g., by copying a data structure, modifying the copy, then swapping it back into place with the original one if everything succeeded).
    - We should always endeavor to provide the basic guarantee, though. There are few excuses for giving up on this one, because the alternative is unpredictable or undefined behavior or even program crashes in the event that an exception is thrown. Exceptions happen, whether we like it or not, so best not to have them mushroom into much bigger problems that are more difficult to diagnose and fix.

## RAII
- Let's assume that the doTheJob function can't be considered to have succeeded if any of the functions it calls fail; a failure of any of these functions means that doTheJob has failed, as well. (More often than not in real designs, this is the case. We generally catch exceptions in many fewer places than you might imagine.) In that case, we don't want this function to catch exceptions and fully handle them, yet we also have to ensure that we don't leak memory here. These needs lead to the following, rather contorted-looking logic:

<p>
void doTheJob()<br>
{<br>
    <ul>
    A* a = nullptr;<br>
    B* b = nullptr;<br>
<br>
    try<br>
    {<br>
        <ul>
        a = buildA();<br>
        b = buildB();<br>
<br>
        doThings(a, b);<br>
        doMoreThings(a);<br>
        doYetMoreThings(b);<br>
<br>
        delete b;<br>
        delete a;<br>
        </ul>
    } <br>
    catch (...)<br>
    {<br>
        <ul>
        // It's safe to pass nullptr to delete, so we don't technically<br>
        // need to check for nullptr here.<br>
        delete b;<br>
        delete a;<br>
<br>
        // Re-throw the exception, since we haven't handled it; we've just made<br>
        // sure to do some cleaning up before our function fails.<br>
        throw;<br>
        </ul>
    }<br>
    </ul>
}<br>
</p>

