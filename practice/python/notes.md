## I/O
### Input
price = input("Enter the price: ")<br>

### Output
print(price)<br>

## Type Conversion
birth_year = input("Enter your birth year: ") # All inputs are string<br>
age = 2023 - int(birth_year) # Must convert to int for arithmetic operation<br>
print("Your age is " + str(age)) # Must convert to string to concatenate to another string<br>

## Strings
Strings are imutable in Python<br>
### String Index
course = "Python for Beginners"<br>
course_1 = "Python's Beginner Course"<br>
course_2 = 'Python for "Beginners"'<br>
course_3 = '''<br>
Hi Coder,<br>
<br>
This is a Python course<br>
for Beginners.<br>
<br>
Thank you,<br>
Python<br>
'''<br>

print(course[0]) # Prints the first character in course<br>
print(course[-1]) # Prints the last character or first character from the last in course<br>
print(course[0:3]) # Prints the characters start from index 0 to 2 (index 3 is not included)<br>
print(course[1:]) # Prints the characters start from index 1<br>
print(course[:4]) # Prints the characters start from index 0 to 3<br>
print(course[:]) # Prints all characters in course<br>
print(course[1:-1]) # Prints the characters start from index 1 tto second character from the last<br>
### Formated String
first = "John"<br>
last = "Smith"<br>
message = first + " [" + last + "] is a coder"<br>
formated_message = f"{first} [{last}] is a coder" # formated string starts with the letter f and followed by quotation marks: f""<br>
### String Methods
course = "Python for Beginners"<br>
print(len(course)) # Prints the total number of characters in course<br>
- len() is like print() is a general purpose function

print(course.upper()) # Prints course in upper case without modifiying the variable course<br>
print(course.find("Beginners")) # Prints the first index if "Beginners" is found, otherwise prints -1<br>
print(course.replace("Beginners", "Absolute Beginners")) # Replace "Beginners" with "Absolute Beginners"<br>
print(course.replace("n", "m")) # Replace all "n" with "m"<br>
"Python" in course # Returns true if "Python" is found in variable course, otherwise returns false<br>

## Arithmetic Operations
print(10 / 3) # Returns a floating point number or prints 3.3333333<br>
print(10 // 3) # Returns an integer or prints 3<br>
print(10 % 3) # Returns an remainder of the division<br>
print(10 ** 3) # Returns 10 to the third power<br>
x = 10<br>
x += 3 # x = x + 3<br>
x -= 3 # x = x - 3<br>
x = 10 + 3 * 2 ** 2 # All arithmetic operations follow the order of operation
### Arithmetic Methods
x = 2.9
y = -2.9
print(round(x)) # Rounds up x and prints 3
print(abs(y)) # Prints the absolute value of y which is 2.9
### Math Module
import math
x = 2.1
y = 2.9
print(math.ceil(x)) # Rounds up x and prints 3
print(math.floor(y)) # Rounds down y and prints 2

## If Statement
is_hot = True<br>
if is_hot:<br>
    <ul>
    print("It's a hot day")<br>
    print("Drink plenty of water")<br>
    </ul>
elif is_cold:<br>
    <ul>
    print("It's a cold day")<br>
    print("Wear warm clothes")<br>
    </ul>
else:
    <ul>
    Print("It's a lovely day")<br>
    </ul>
print("Enjoy your day")<br>

## Logical Operators
has_high_income = True<br>
has_good_credit = True<br>
<br>
if has_high_income and has_good_credit:<br>
    <ul>
    print("Eligible for low interest loan")<br>
    </ul>
if has_high_income or has_good_credit:<br>
    <ul>
    print("Eligible for loan")<br>
    </ul>
<br>
has_criminal_record = False<br>
<br>
if has_good_credit and not has_criminal_record<br>
    <ul>
    print("Eligible for loan")<br>
    </ul>

## Comparison Operators
temperature = 30<br>
if temperature > 30:<br>
    <ul>
    print("It's a not hot day")<br>
    </ul>
else:<br>
    <ul>
    print("It's not a hot day")<br>
    </ul>
<br>
List of operators<br>
# > --> greater than<br>
# < --> less than<br>
# >= --> greater or equal to <br>
# <= --> less or equal to<br>
# == --> equal to<br>
# != --> not equal to<br>

## While Loops
i = 1<br>
while i <= 5:<br>
    <ul>
    print(i)<br>
    i = i + 1<br>
    </ul>
print("done")<br>
<br>
i = 1<br>
while i <= 5:<br>
    <ul>
    print('*' * i)<br>
    i = i + 1<br>
    </ul>
print("done")<br>

## For Loops
for item in "Python":<br>
    <ul>
    print(item)<br>
    </ul>
for item in ["Mosh", "John", "Sarah"]:<br>
    <ul>
    print(item)<br>
    </ul>
for item in [1, 2, 3, 4, 5, 6]:<br>
    <ul>
    print(item)<br>
    </ul>
for item in range(10): # range from 1 to 9 excluding 10<br>
    <ul>
    print(item)<br>
    </ul>
for item in range(5, 10): # range from 5 to 9 excluding 10<br>
    <ul>
    print(item)<br>
    </ul>
for item in range(5, 10, 2): # range from 5 to 9 in two numbers forward<br>
    <ul>
    print(item)<br>
    </ul>

## Nested Loops
for x in range(4):<br>
    <ul>
    for y in range(3):<br>
        <ul>
        print(f"({x}, {y})")<br>
        </ul>
    </ul>

## Lists
names = ["John", "Bob", "Mosh", "Sarah", "Mary"]<br>
print(names[2:])<br>

## 2D Lists
matrix = [<br>
    <ul>
    [1, 2, 3],<br>
    [4, 5, 6],<br>
    [7, 8, 9]<br>
    </ul>
]<br>

## List Methods
numbers = [5, 2, 1, 7, 4]
numbers.append(20) # Adds the number '20' to the end of the list
numbers.insert(0, 10) # The first number indicates the index in the list and the second number indicates what number is adding to the list
numbers.remove(5) # Removes the number '5' in the list
numbers.clear() # Clear all items in the list
numbers.pop() # Remove the last item in the list
numbers.index(5) # Return the index number if the number '50' is in the list
50 in numbers # Returns true if the number '50' is the list, otherwise returns false
numbers.sort() # Sorts the numbers in the list in ascending order
numbers.reverse() # Reverse the order of the numbers in the list
numbers2 = numbers.copy() # Creates a copy of new independant list and assign it to numbers2

## Functions
def greet_user():<br>
    <ul>
    print("Hi there!")<br>
    print("Welcome aboard")<br>
    </ul>
<br>
<br># Leave 2 blank lines after class or function defintion<br>

## Paraments
def greet_user(first_name, last_name):<br>
    <ul>
    print(f"Hi {first_name} {last_name}!")<br>
    print("Welcome aboard")<br>
    </ul>
<br>
<br># Leave 2 blank lines after class or function defintion<br>

## Keyword Arguments
def greet_user(first_name, last_name):<br>
    <ul>
    print(f"Hi {first_name} {last_name}!")<br>
    print("Welcome aboard")<br>
    </ul>
<br>
<br># Leave 2 blank lines after class or function defintion<br>
<br>
<br>
greet_user(last_name = "Smith", first_name = "John")<br>

- position arguments should be placed after keyword arguments
greet_user("John", last_name = "Smith")<br>

## Return Statement
def square(number):<br>
    <ul>
    return number * number<br>
    </ul>

## Exceptions
try:<br>
    <ul>
    age = int(input("Age: "))<br>
    income = 2000<br>
    risk = income / age<br>
    print(age)<br>
    </ul>
except ZeroDivisionError:
    <ul>
    print("Age cannot be 0")
    </ul>
except ValueError:<br>
    <ul>
    print("Invalid value")<br>
    </ul>

## Classes

class Point:<br>
    <ul>
    def move(self):<br>
        <ul>
        print("move")<br>
        </ul>
    def draw(self):<br>
        <ul>
        print("draw")<br>
        </ul></ul>

point1 = Point()<br>
point1.x = 10<br>
point1.y = 20<br>
print(point1.x)<br>
point1.draw()<br>

point2 = Point()<br>
point2.x = 5<br>
print(point2.x)<br>
point2.move()<br>

## Constructors
class Point:<br>
    <ul>
    def __init__(self, x, y)<br>
        <ul>
        self.x = x<br>
        self.y = y<br>
        </ul>
    def move(self):<br>
        <ul>
        print("move")<br>
        </ul>
    def draw(self):<br>
        <ul>
        print("draw")<br>
        </ul></ul>

point1 = Point(10, 20)<br>

## Inheritance
class Pet:<br>
    <ul>
    def walk(self) -> None:<br>
        <ul>
        print("walk")<br>
        </ul></ul>


class Dog(Pet):<br>
    <ul>
    def bark(self):<br>
        <ul>
        print("bark")<br>
        </ul></ul>


class Cat(Pet):<br>
    <ul>
    pass<br>
    </ul>


dog = Dog()<br>
dog.walk()<br>
dog.bark()<br>
cat = Cat()<br>
cat.walk()<br>

## Modules
import weight_converters<br>
from weight_converters import kg_to_lbs<br>


print(kg_to_lbs(70)) # when importing an individual function, prefix of said function is not needed<br>
print(weight_converters.lbs_to_kg(156))<br>

## Packages
    - creates a directory with a Python file named __init__.py in it
    - all Python files store in this directory are in the same package
    - ecommerce is the name of the directory
    - shipping is the name of the Python file stored in ecommerce
    - calc_shipping() is the function in shipping

import ecommerce.shipping<br>
ecommerce.shipping.calc_shipping()<br>
<br>
from ecommerce import shipping<br>
shipping.calc_shipping()<br>
<br>
from ecommerce.shipping import calc_shipping<br>
calc_shipping()<br>
<br>

## Build In Modules
import random<br>
<br>
for i in range(3):<br>
    <ul>
    print(random.random())<br>
    print(random.randint(0, 10)) # generate a random integer between 0 to 10, inclusive<br>
    </ul>
<br>
members = ["John", "Mary", "Bob", "Mosh"]<br>
print(random.choice(members)) # return a random object from the list<br>