arr = [1, 2, 3, 4, 5, 6, 7]
rotated_arr = []
n = int(input())

for i in range(n, len(arr)):
    rotated_arr.append(arr[i])

for i in range(0, n):
    rotated_arr.append(arr[i])
