# weight = int(input("Weight: "))
# converted_weight = 0
# unit = input("(L)bs or (K)g: ")
# if unit.lower() == "l":
#     converted_weight = weight * 0.45
#     print(f"You are {converted_weight} kilos")
# if unit.lower() == "k":
#     converted_weight = weight / 0.45
#     print(f"You are {converted_weight} pounds")

def lbs_to_kg(weight) -> int:
    return weight * 0.45

def kg_to_lbs(weight) -> int:
    return weight / 0.45