import numpy as np
from scipy.stats import multivariate_normal
import time


def logpdf(X, m, C):
    D = len(m)
    diff = X - m
    inv_C = np.linalg.inv(C)
    det_C = np.linalg.det(C)
    exponent = -0.5 * np.sum(diff @ inv_C * diff, axis=1)
    norm = -0.5 * D * np.log(2 * np.pi) - 0.5 * np.log(det_C)
    return norm + exponent


N, D = 100, 3
X_test = np.random.randn(N, D)
m_test = np.zeros(D)
C_test = np.eye(D)

start_time = time.time()
our_result = logpdf(X_test, m_test, C_test)
our_time = time.time() - start_time

start_time = time.time()
scipy_result = multivariate_normal(m_test, C_test).logpdf(X_test)
scipy_time = time.time() - start_time

max_diff = np.max(np.abs(our_result - scipy_result))

print(f"Наша реализация: {our_time:.6f} сек")
print(f"Scipy: {scipy_time:.6f} сек")
print(f"Разница во времени: {our_time - scipy_time:.6f} сек")
print(f"Максимальная разница в значениях: {max_diff:.2e}")
