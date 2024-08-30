price = int(input('Enter Price: '))

curuncy1 = int(input('Enter Currency 1: '))
curuncy2 = int(input('Enter Currency 2: '))
curuncy3 = int(input('Enter Currency 3: '))

count = 0

print(curuncy1, curuncy2, curuncy3)

for c1 in range(price // curuncy1 + 1):
    for c2 in range(price // curuncy2 + 1):
        for c3 in range(price // curuncy3 + 1):
            if c1 * curuncy1 + c2 * curuncy2 + c3 * curuncy3 == price:
                print(c1,c2,c3)
                count+=1
print("Total Combinations:",count)