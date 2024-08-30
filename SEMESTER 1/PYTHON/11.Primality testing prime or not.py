num = int(input("Enter a positive Number: "))

if num <= 1:
    print(num, "is not prime")
elif num <= 3:
    print(num, "is prime")
else:
    if num % 2 == 0 or num % 3 == 0:
        print(num, "is not prime")
    else:
        i = 5
        while i * i <= num:
            if num % i == 0 or num % (i + 2) == 0:
                print(num, "is not prime")
                break
            i += 6
        else:
            print(num, "is prime")
