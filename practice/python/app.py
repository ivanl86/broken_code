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
    Print("It's a lovely day")
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