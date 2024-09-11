print("\n")
roll = input("Enter roll number : ")

if len(roll) != 9:
    print("\n")
    print("Invalid roll number. enter roll number is 9 characters long.")
elif not roll[0:4].isdigit():
    print("\n")
    print("Invalid roll number. first four number represent the year.")
elif not roll[4:6].isalpha():
    print("\n")
    print("Invalid roll number. next two characters alphabetic represent department name.")
elif not roll[6:].isdigit():
    print("\n")
    print("Invalid roll number. last number represent student number.")
else:
    roll[4:6]=='CS' or roll[4:6]=='cs'
    year = roll[0:4]
    dept_code = roll[4:6]
    stu_num = roll[6:]

    print("\n")
    print("Year:", year)
    print("Department:", dept_code)
    print("Student Number:", stu_num)
    print("\n")