# AcWing.788

def sort_list(array: list, start: int, l1: int, l2: int):
    count = 0
    i = start
    j = start + l1
    new_array = []
    while i < start + l1 and j < start + l1 + l2:
        while array[j] >= array[i] and i < start + l1:
            new_array.append(array[i])
            i = i + 1
        new_array.append(array[j])
        j = j + 1
        if i < start + l1:
            count = count + start + l1 - i
    if i == start + l1:
        while j < start + l1 + l2:
            new_array.append(array[j])
            j = j + 1
    else:
        while i < start + l1:
            new_array.append(array[i])
            i = i + 1
    array[start: start + l1 + l2] = new_array
    return count


def merge(array: list, begin: int, end: int):
    if begin >= end:
        return 0
    mid = int((begin + end) / 2)
    l_count = merge(array, begin, mid)
    r_count = merge(array, mid + 1, end)

    count = l_count + r_count + sort_list(array, begin, mid - begin + 1, end - mid)
    return count


num = int(input())
numbers = list(map(int, input().split()))
count = merge(numbers, 0, num - 1)
print(count)