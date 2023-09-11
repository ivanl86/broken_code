numbers = [10, 3, 6, 2, 8, 4]
largest = numbers[0]
for item in numbers:
    if item > largest:
        largest = item
print(f"largest: {largest}")