arr = [1, 7, 8, 1, 4, 5, 1, 7, 9, 11, 33, 1]
target = 5

for i in range(0, len(arr)):
    if arr[i] == target:
        print("Index: " + str(i))
        exit()

print("Not found")
