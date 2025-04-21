import numpy as np

with open('matrix.txt', 'w') as f:
    f.write("3,4,17,-3\n5,11,-1,6\n0,2,-5,8")

matrix = np.loadtxt('matrix.txt', delimiter=',')

total_sum = np.sum(matrix)
max_val = np.max(matrix)
min_val = np.min(matrix)

print(f"Сумма: {total_sum}, Максимум: {max_val}, Минимум: {min_val}")
