import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-5, 5, 100)
y = np.linspace(-5, 5, 100)
X, Y = np.meshgrid(x, y)


def mse(a, b):
    return a ** 2 + b ** 2


Z = mse(X, Y)

fig = plt.figure(figsize=(16, 7))
plt.subplots_adjust(left=0.05, right=0.95, bottom=0.1, top=0.9, wspace=0.3)

ax1 = fig.add_subplot(121, projection='3d')
surf1 = ax1.plot_surface(X, Y, Z, alpha=0.8)
ax1.set_title('MSE в линейном масштабе', pad=15)
ax1.set_xlabel('X', labelpad=10)
ax1.set_ylabel('Y', labelpad=10)
ax1.set_zlabel('MSE', labelpad=10)
ax1.tick_params(axis='both', which='major', pad=5)

ax2 = fig.add_subplot(122, projection='3d')

Z_log = np.log10(Z + 1e-10)

surf2 = ax2.plot_surface(X, Y, Z_log, alpha=0.8)
ax2.set_title('MSE в логарифмическом масштабе (log10)', pad=15)
ax2.set_xlabel('X', labelpad=10)
ax2.set_ylabel('Y', labelpad=10)
ax2.set_zlabel('log10(MSE)', labelpad=10)
ax2.tick_params(axis='both', which='major', pad=5)

for ax in [ax1, ax2]:
    ax.xaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
    ax.yaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
    ax.zaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
    ax.grid(True, linestyle='--', alpha=0.5)

plt.show()
