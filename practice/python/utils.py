def find_max(numbers) -> int:
    max = numbers[0]
    for number in numbers[1:]:
        if number > max:
            max = number

    return max