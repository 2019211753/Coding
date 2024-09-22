# AcWing.789

def search(array: list, length: int, num: int):
    i = 0
    j = length - 1

    while i <= j:
        mid = int((i + j) / 2)
        if array[mid] > num:
            j = mid - 1
        elif array[mid] < num:
            i = mid + 1
        else:
            break
    if array[mid] == num:
        m = mid
        n = mid
        while m >= 0 and array[m] == num:
            m = m - 1
        m = m + 1
        while n <= length - 1 and array[n] == num:
            n = n + 1
        n = n - 1
        return [m, n]
    else:
        return [-1, -1]


len, nums = map(int, input().split())
arr = list(map(int, input().split()))
numbers = [int(input()) for _ in range(nums)]
for num in numbers:
    print(' '.join(map(str, search(arr, len, num))))