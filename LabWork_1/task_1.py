def choose_min_max(x1, x2, x3):
    mx = x1
    mn = x2
    if x2 > mx:
        mx = x2
    if x3 > mx:
        mx = x3
    if x1 < mn:
        mn = x1
    if x3 < mn:
        mn = x3
    return mx, mn


a, b, c = map(int, input().split())
print(*choose_min_max(a, b, c))
