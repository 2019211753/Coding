# AcWing.791

def add(a: str, b: str):
    a = [int(x) for x in a]
    b = [int(x) for x in b]
    l1 = len(a) - 1
    l2 = len(b) - 1
    result = []
    flag = 0
    while l1 >= 0 and l2 >= 0:
        sum = a[l1] + b[l2] + flag
        if sum >= 10:
            result.append(sum % 10)
            flag = 1
        else:
            result.append(sum)
            flag = 0
        l1 = l1 - 1
        l2 = l2 - 1

    while l1 >= 0:
        sum = a[l1] + flag
        if sum >= 10:
            result.append(sum % 10)
            flag = 1
        else:
            result.append(sum)
            flag = 0
        l1 = l1 -1

    while l2 >= 0:
        sum = b[l2] + flag
        if sum >= 10:
            result.append(sum % 10)
            flag = 1
        else:
            result.append(sum)
            flag = 0
        l2 = l2 - 1

    if flag == 1:
        result.append(1)
    return ''.join(map(str, result))[::-1]


a = input()
b = input()
print(add(a, b))
