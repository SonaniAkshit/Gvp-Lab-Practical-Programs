bg1 = input("Enter Blood Group 1 (A, B, AB, O): ").upper().strip()
bg2 = input("Enter Blood Group 2 (A, B, AB, O): ").upper().strip()

if bg1 not in ["A", "B", "AB", "O"] or bg2 not in ["A", "B", "AB", "O"]:
    print("---------------------")
    print("Invalid Blood Group's")
    print("---------------------")
    exit()
    
if bg1 == "O":
    match = True
elif bg1 == "A":
    match = bg2 in ["A", "AB"]
elif bg1 == "B":
    match = bg2 in ["B", "AB"]
elif bg1 == "AB":
    match = bg2 == "AB"

bg1_factor = input("Enter bg1 factor : ").upper().strip()
bg2_factor = input("Enter bg2 factor : ").upper().strip()
if bg1_factor not in ["+", "-"] or bg2_factor not in ["+", "-"]:
    print("----------------")
    print("Invalid Factor's")
    print("----------------")
    exit()

if bg1_factor == "-" and bg2_factor == "+":
    match = False

if match:
    print("------------------------")
    print("Blood Groups Matched...!")
    print("------------------------")
else:
    print("----------------------------")
    print("Blood Groups Not Matched...!")
    print("----------------------------")
