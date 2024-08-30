n = input("Enter a Positive Numbers: ")

if n.isdigit() and int(n) >= 0:
    m = int(n)
    sum = m * (m + 1) // 2
    print("------------------------------------------------")
    print("The Sum of The First", m, "Positive Integers is:", sum)
    print("------------------------------------------------")
else:
    print("------------------------------------------------")
    print("Invalid Input ! Please Enter a Positive Numbers.")
    print("------------------------------------------------")