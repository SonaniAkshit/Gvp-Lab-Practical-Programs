card = int(input("Enter Any Card Number: "))

if card < 1 or card > 25:
    print("-------------------")
    print("Invalid Card Number")
    print("-------------------")
else:
    lucky_numbers = {1, 3, 7, 9, 13, 15, 17, 19, 21, 23}
    if card in lucky_numbers:
        print("------------------")
        print("The Card is lucky!")
        print("------------------")
    else:
        print("----------------------")
        print("The card is not lucky.")
        print("----------------------")