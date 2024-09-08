number1=int(input("Enter any Number: "))
number=int(number1)
if(number>1):
    for i in range(2,(number//2)+1):
        if(number%i)==0:
            print("Not Prime.")
            break
    else:
        print("Prime.")