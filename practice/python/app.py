first = "John"
last = "Smith"
course = "python for beginners"
# print(course.replace("Beginners", "Absolute Beginners"))
# print("Python" in course)
# birth_year = input("Enter your birth year: ")
# age = 2023 - int(birth_year)
# print("Your age is " + str(age))
# print(str(age)[:])
formated_msg = f"{first} [{last}] is a coder"
print(formated_msg)
print(f"{first} [{last}] is a coder")
print(course.replace("n", "m"))
print(course.title())
is_hot = True
is_cold = True
if is_hot:
    print("It's a hot day")
    print("Drink plenty of water")
elif is_cold:
    print("It's a cold day")
    print("Wear warm clothes")
else:
    print("It's a lovely day")
print("Enjoy your day")

has_high_income = True
has_good_credit = True
has_criminal_record = False
if has_good_credit and not has_criminal_record:
    print("Eligible for low interest loan")
elif has_high_income or has_good_credit:
    print("Eligible for loan")

temperature = 31

if temperature > 30:
    print("It's a hot day")
else:
    print("It's not a hot day")

i = 0
while i < 5:
    print('*' * i)
    i = i + 1
print("Done")

for x in range(4):
    for y in range(3):
        print(f"({x}, {y})")

numbers = [5, 2, 5, 2, 2]
for number in numbers:
    print("*" * number)

for number in numbers:
    output = ""
    for num in range(number):
        output += "*"
    print(output)

names = ["John", "Bob", "Mosh", "Sarah", "Mary"]
print(names[2:4])

matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

print(matrix[:][0])

for row in matrix:
    for item in row:
        print(item)

def greet_user(first_name, last_name):
    print(f"Hi {first_name} {last_name}!")
    print("Welcome aboard!")


# Leave 2 blank lines after class or function defintion
def square(number):
    return number * number


# Leave 2 blank lines after class or function defintion
greet_user(last_name = "John", first_name = "Smith")
print(square(4))
