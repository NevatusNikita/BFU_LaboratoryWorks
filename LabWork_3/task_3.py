a = list(input().split())
dct = {}
for el in a:
    if dct.get(el) is None:
        dct[el] = 0
    dct[el] += 1
print(*dct.values())
