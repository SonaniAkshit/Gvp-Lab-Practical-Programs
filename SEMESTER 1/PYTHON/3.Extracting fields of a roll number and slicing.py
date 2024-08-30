roll = input("Enter roll number : ")
print("---------------------------")

if len(roll) != 9:
    print("------------------------------------------------------------")
    print("Invalid roll number. enter roll number is 9 characters long.")
    print("------------------------------------------------------------")
elif not roll[0:4].isdigit():
    print("------------------------------------------------------------")
    print("Invalid roll number. first four number represent the year.")
    print("------------------------------------------------------------")
elif not roll[4:6].isalpha():
    print("------------------------------------------------------------------------------")
    print("Invalid roll number. next two characters alphabetic represent department name.")
    print("------------------------------------------------------------------------------")
elif not roll[6:].isdigit():
    print("----------------------------------------------------------")
    print("Invalid roll number. last number represent student number.")
    print("----------------------------------------------------------")
else:
    roll[4:6]=='CS' or roll[4:6]=='cs'
    year = roll[0:4]
    dept_code = roll[4:6]
    stu_num = roll[6:]

    print("---------------------------")
    print("Year:", year)
    print("Department:", dept_code)
    print("Student Number:", stu_num)
    print("---------------------------")