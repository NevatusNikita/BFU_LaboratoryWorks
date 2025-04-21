import numpy as np


def rle(x):
    changes = np.where(x[:-1] != x[1:])[0] + 1
    values = x[np.concatenate(([0], changes))]
    counts = np.diff(np.concatenate(([0], changes, [len(x)])))
    return (values, counts)


x_test = np.array([2, 2, 2, 3, 3, 3, 5])
print(rle(x_test))
