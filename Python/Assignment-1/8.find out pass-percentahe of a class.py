marks = []

for mark in range(10):
    mark = int(input("Enter marks : "))
    marks.append(mark)

students = len(marks)

passed = sum(mark >= 40 for mark in marks)
failed = sum(mark < 40 for mark in marks)

pass_per = (passed / students) * 100
fail_per = (failed / students) * 100

print("------------------")
print(f"Pass percentage:{pass_per:.2f}")
print(f"Fail percentage: {fail_per:.2f}")
print("---------------------------------------------------")
print("The Out Of {0} Student's,{1} Student's is Passed,And {2} Student's is Failed".format(students,passed,failed))
print("---------------------------------------------------")