# AcWing.787

def sort_list(array: list, start: int, l1: int, l2: int):
    i = start
    j = start + l1
    new_array = []
    while i < start + l1 and j < start + l1 + l2:
        while array[j] > array[i] and i < start + l1:
            new_array.append(array[i])
            i = i + 1
        new_array.append(array[j])
        j = j + 1
    if i == start + l1:
        while j < start + l1 + l2:
            new_array.append(array[j])
            j = j + 1
    else:
        while i < start + l1:
            new_array.append(array[i])
            i = i + 1
    array[start: start + l1 + l2] = new_array


def merge(array: list, begin: int, end: int):
    if begin >= end:
        return
    mid = int((begin + end) / 2)
    merge(array, begin, mid)
    merge(array, mid + 1, end)
    sort_list(array, begin, mid - begin + 1, end - mid)


num = int(input())
numbers = list(map(int, input().split()))
merge(numbers, 0, num - 1)
for x in numbers:
    print(x, end=' ')
