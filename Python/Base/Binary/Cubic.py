# AcWing.790

def search(num: float):
    i = -10000
    j = 10000

    while j - i >= 1e-8:
        mid = (i + j) / 2

        # ���������֣��൱���������ģ��������ֵĻ���Ҫ+1 -1
        if mid ** 3 > num:
            j = mid
        elif mid ** 3 < num:
            i = mid
        else:
            break
    return mid

number = float(input())
print(f'{search(number):.6f}')
