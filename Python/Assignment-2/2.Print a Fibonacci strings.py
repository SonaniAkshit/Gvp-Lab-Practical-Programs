n = int(input("Enter the number: "))
n1 = "A"
n2 = "B"
for i in range(1,n +1):
    print(n1,end=" ")
    temp = n2 + n1
    n1 = n2
    n2 = temp