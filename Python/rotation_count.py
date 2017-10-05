
## O(n)
arr = [15,18,2,3,6,12]

idx = -1
for i in range(1, len(arr)):
    if arr[i - 1] > arr[i]:
        idx = len(arr) - (len(arr) - i)
        break

if idx == -1:
    print(0)
else:
    print(idx)