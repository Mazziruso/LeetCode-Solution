# n = 123

# res = []
# a = n
#
# while 1 not in res:
#     a = [pow(int(i), 2) for i in str(a)]
#     a = sum(a)
#     if a in res:
#         print(False)
#         break
#     res = res + [a]
# else:
#     print(True)

def sum_square(n, array):
    a = [pow(int(i), 2) for i in str(n)]
    n = sum(a)

    if 1 in array:
        return True
    elif n in array:
        return False

    array += [n]

    return sum_square(n, array)

array = []
n = 19
print(sum_square(n, array))
