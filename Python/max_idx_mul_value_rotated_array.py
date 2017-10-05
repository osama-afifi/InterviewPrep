arr = [10, 1, 2, 3, 4, 5, 6, 7, 8, 9]
arr_length = len(arr)

max_sum = -(1 << 25)

## O(n^2)
for i in range(0, arr_length):
    temp = arr[0]

    for j in range(0, arr_length - 1):
        arr[j] = arr[j + 1]

    arr[-1] = temp
    current_sum = 0

    for j in range(0, arr_length):
        current_sum += arr[j] * j

    max_sum = max(max_sum, current_sum)

print(max_sum)

## O(n)

arr_sum = 0
current_sum = 0

for i in range(0, arr_length):
    arr_sum += arr[i]
    current_sum += arr[i] * i

max_sum = max(max_sum, current_sum)

for i in range(1, arr_length - 1):
    current_sum += arr_sum - arr_length * arr[arr_length - i]
    max_sum = max(max_sum, current_sum)

print(max_sum)


## O(nlogn)
arr.sort()
print(sum([i * val for i, val in enumerate(arr)]))

