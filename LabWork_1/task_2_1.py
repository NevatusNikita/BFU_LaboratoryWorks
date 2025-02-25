n = int(input())
s = list(x for x in range(1, n + 1))
for i in range(n):
    print(*s[:n - i], sep='')
