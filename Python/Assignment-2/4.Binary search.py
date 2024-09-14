def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

arr = []
print("\n")
for target in range(5):
    target = int(input(f"Enter Values:"))
    arr.append(target)
# arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
target = int(input("enter target value:-"))
index = binary_search(arr, target)
if index != -1:
    print(f"element {target} found at index {index}.")
else:
    print(f"element {target} not found in the array.")