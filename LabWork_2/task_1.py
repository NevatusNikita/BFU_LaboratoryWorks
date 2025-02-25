s = input()
dct = dict()
for sym in s:
    if sym not in dct.keys():
        dct[sym] = 1
    else:
        dct[sym] += 1
ans = ''
for key, value in dct.items():
    ans += key
    if value != 1:
        ans += str(value)
print(ans)