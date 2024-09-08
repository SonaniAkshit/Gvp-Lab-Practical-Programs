price = int(input('Enter Price: '))
curuncy1 = int(input('Enter Currency 1: '))
count = 0
if curuncy1 > price:
    print("Enter Curuncy1 less then price")
else:
    curuncy2 = int(input('Enter Currency 2: '))
    if curuncy2 > price:
        print("Enter Curuncy2 less then price")
    else:
        curuncy3 = int(input('Enter Currency 3: '))
        if curuncy3 > price:
            print("Enter Curuncy3 less then price")
        else:
            print(curuncy1, curuncy2, curuncy3)

            for c1 in range(price // curuncy1 + 1):
                for c2 in range(price // curuncy2 + 1):
                    for c3 in range(price // curuncy3 + 1):
                        if c1 * curuncy1 + c2 * curuncy2 + c3 * curuncy3 == price:
                            print(c1,c2,c3)
                            count+=1
        print("Total Combinations:",count)