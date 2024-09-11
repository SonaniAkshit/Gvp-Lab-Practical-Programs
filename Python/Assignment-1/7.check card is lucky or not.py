print("\n")
card = int(input("Enter Any Card Number: "))

if card < 1 or card > 25:
    print("\n")
    print("Invalid Card Number")
else:
    lucky_numbers = {1, 3, 7, 9, 13, 15, 17, 19, 21, 23}
    if card in lucky_numbers:
        print("\n")
        print("The Card is lucky!")
    else:
        print("\n")
        print("The card is not lucky.")
        print("\n")