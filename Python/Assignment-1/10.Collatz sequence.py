n =int(input("Enter Any Number:"))
#print(n)

while n != 1:
    if n % 2 == 0:  
        n = n // 2
    else:
        n = 3 * n + 1
    if n != 1:
        print(n)
    else:
        print(n)