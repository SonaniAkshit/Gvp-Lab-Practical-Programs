n = input("Enter the number: ")

t1 = 0
t2 = 1
count = 0

if n.isdigit() and int(n) >= 0:
   
   m=int(n)
   print("Fibonacci sequence:")
   while count < m:
       print(t1)
       temp = t1 + t2
       t1 = t2
       t2 = temp
       count += 1
else:
   print("Please enter a positive integer")