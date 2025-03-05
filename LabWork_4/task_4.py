fibs = input()


def frequently_encountered(s):
    dct = dict()
    for el in s:
        if dct.get(int(el)) is None:
            dct[int(el)] = 0
        dct[int(el)] += 1
    new_dct = dict(sorted(dct.items(), key=lambda item: item[1], reverse=True)[:3])
    return new_dct


print(frequently_encountered(fibs))
