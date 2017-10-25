

def binary_search_iterative(arr, start, end, target):
    while start <= end:
        mid = (start + end) // 2

        if arr[mid] == target:
            return mid

        if arr[mid] < target:
            start = mid + 1
        else:
            end = mid - 1

    return -1


def binary_search_recursive(arr, start, end, target):
    if start > end:
        return -1

    else:
        mid = (start + end) // 2

        if arr[mid] == target:
            return mid

        if arr[mid] < target:
            return binary_search_recursive(arr, mid + 1, end, target)
        else:
            return binary_search_recursive(arr, start, mid - 1, target)

arr = [1, 7, 8, 1, 4, 5, 1, 7, 9, 11, 33, 1]
target = 4

arr.sort()
print(arr)
print("Index: " + str(binary_search_recursive(arr, 0, len(arr) - 1, target)))

