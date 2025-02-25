s = input()
dct = dict()
for el in s:
    if el not in dct.keys():
        dct[el] = 1
    else:
        dct[el] += 1
dct = sorted(dct.items(), key=lambda x: x[1], reverse=True)
for el in dct[:3]:
    print(*el)
