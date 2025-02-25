n = int(input())
pascals_triangle = []
for i in range(n):
    row = [1] * (i + 1)
    for j in range(1, i):
        row[j] = pascals_triangle[i - 1][j - 1] + pascals_triangle[i - 1][j]
    pascals_triangle.append(row)
max_width = len(' '.join(map(str, pascals_triangle[-1])))
for row in pascals_triangle:
    print(' '.join(map(str, row)).center(max_width))
