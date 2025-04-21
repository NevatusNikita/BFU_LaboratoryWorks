import numpy as np

x = np.array([6, 2, 0, 3, 0, 0, 5, 7, 0])
zero_positions = np.where(x[:-1] == 0)[0]
max_after_zero = np.max(x[zero_positions + 1])

print(max_after_zero)
