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