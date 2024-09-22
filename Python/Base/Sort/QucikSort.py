# AcWing.785

def swap(array: list, i: int, j: int):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp


def sort(array, low, high):
    if low >= high:
        return
    else:
        i = low
        j = high
        mid = int((low + high) / 2)
        swap(array, i, mid)
        pivot = array[i]
        while i < j:
            while i < j and array[j] > pivot:
                j = j - 1
            if i < j:
                array[i] = array[j]
                i = i + 1
            while i < j and array[i] < pivot:
                i = i + 1
            if i < j:
                array[j] = array[i]
                j = j - 1
        array[i] = pivot
        sort(array, low, i - 1)
        sort(array, j + 1, high)


num = int(input(""))
number = input("")
numbers = list(map(int, number.split()))
sort(numbers, 0, num - 1)
for i in numbers:
    print(i, end=' ')
