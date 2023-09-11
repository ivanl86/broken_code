guess_limit = 3
guess_count = 0
guess_number = 0
sercet_number = 9
while guess_count < guess_limit:
    guess_number = int(input("Guess: "))
    guess_count += 1
    if (guess_number == sercet_number):
        print("You won!")
        break
else:
    print("Sorry, you failed...")