birthdays = {"Akshit": "06/08/04","Hardik": "03/12/04","Om": "15/02/04","Chintan": "07/03/03","Priyank": "06/04/04",
             "Jaydip": "23/05/04","Utsav": "15/06/04","Monit": "07/07/03","Yash": "06/08/04","Rutvik": "23/09/04",
             "Dhrmesh": "15/10/04","Aryan": "07/11/03"}
print("--------------------------")
month = int(input("Enter the month:"))
print("--------------------------")
print("Birthdays in month", month,)
print("--------------------------")

if(month<=12):
    for name, birthday in birthdays.items():
        day, month1, year = birthday.split("/")
        if int(month1) == month:
            print(name, ":", birthday)
            print("--------------------------")
        elif int(month1)!=month:
            print("Birthday Not Available..!")
            break
else:
    print("You Enterd Wrong Month..!")
    print("--------------------------")