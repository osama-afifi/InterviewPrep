arr = [4, 5, 6, 7, 8, 9, 1, 2, 3]
arr_len = len(arr)
target = 6


def search(arr, start, end, target):
    if start > end:
        return -1

    mid = (start + end) // 2

    if arr[mid] == target:
        return mid

    if arr[start] <= arr[mid]:
        if arr[start] <= target <= arr[mid]:
            return search(arr, start, mid - 1, target)
        else:
            return search(arr, mid + 1, end, target)

    elif arr[start] > arr[mid]:
        if arr[mid] <= target <= arr[end]:
            return search(arr, mid + 1, end, target)
        else:
            return search(arr, start, mid - 1, target)

print(search(arr, 0, arr_len - 1, target))
