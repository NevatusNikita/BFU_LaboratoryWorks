import numpy as np
import matplotlib.pyplot as plt
from scipy.special import legendre

x = np.linspace(-1, 1, 500)

plt.figure(figsize=(10, 6))

for n in range(1, 8):
    Pn = legendre(n)
    y = Pn(x)
    plt.plot(x, y, label=f'n = {n}')

plt.title('Полиномы Лежандра', fontsize=16)
plt.xlabel('x', fontsize=12)
plt.ylabel('P_n(x)', fontsize=12)
plt.grid(True)
plt.legend(loc='best')

plt.tight_layout()
plt.show()
