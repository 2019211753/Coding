# AcWing.792

def sub(a: str, b: str):
    if len(a) < len(b) or (len(a) == len(b) and a < b):
        if len(a) < len(b):
            a = '0' * (len(b) - len(a)) + a
        a, b = b, a
        is_negative = True
    else:
        is_negative = False
        if len(a) > len(b):
            b = '0' * (len(a) - len(b)) + b
    a = [int(x) for x in a]
    b = [int(x) for x in b]
    length = len(a)
    result = []
    borrow = 0
    for i in range(length - 1, -1, -1):
        sub = a[i] - b[i] - borrow
        if sub < 0:
            sub = 10 + sub
            result.append(sub)
            borrow = 1
        else:
            result.append(sub)
            borrow = 0

    for i in range(length - 1, -1, -1):
        if result[i] == 0:
            result.pop(i)
        else:
            break
    if is_negative:
        return '-' + ''.join(map(str, result))[::-1] or '0'
    else:
        return ''.join(map(str, result))[::-1] or '0'


a = input()
b = input()
print(sub(a, b))
