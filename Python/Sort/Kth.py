# AcWing.786

def kth(array: list, k: int):
    return


def swap(array: list, i: int, j: int):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp


def sort(array: list, low: int, high: int, k: int):
    global flag
    if low >= high or flag:
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
        if i == k:
            flag = True
        sort(array, low, i - 1, k)
        sort(array, j + 1, high, k)


flag = False
num = input("")
num = list(map(int, num.split()))
numbers = input("")
numbers = list(map(int, numbers.split()))
sort(numbers, 0, num[0] - 1, num[1])
print(numbers[num[1]])