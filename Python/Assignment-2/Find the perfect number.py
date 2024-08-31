number=int(input("Enter any number: "))
count=0
for i in range(1,(number // 2) + 1):
    if number%i==0:
        count=count+i
        print(i,end=" ")

if count==number:
    print("\nPerfact:",number)
else:
    print("\nNot Perfact:",number)
