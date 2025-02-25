a = sorted(map(int, input().split()))
b = sorted(map(int, input().split()))
c = set()
for i in range(len(a)):
    for j in range(len(b)):
        if a[i] == b[j]:
            c.add(a[i])
        elif a[i] < b[j]:
            break
print(len(c))
