a = list(map(int, input().split()))
mn = a[0]
mn_ind = 0
mx = a[1]
mx_ind = 1
for i in range(len(a)):
    if a[i] > mx:
        mx = a[i]
        mx_ind = i
    elif a[i] < mn:
        mn = a[i]
        mn_ind = i
b = a.copy()
b[mx_ind] = mn
b[mn_ind] = mx
print(*b)
