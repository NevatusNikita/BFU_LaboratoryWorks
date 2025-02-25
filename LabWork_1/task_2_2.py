n = int(input())
for i in range(n, 0, -1):
    step = (' ' * (n - i) + ''.join(str(x) for x in range(1, i + 1)) +
            ''.join(str(x) for x in range(i - 1, 0, -1)) + ' ' * (n - i))
    print(step)
