import numpy as np
import matplotlib.pyplot as plt

t = np.linspace(0, 2 * np.pi, 1000)
ratios = [(3, 2), (3, 4), (5, 4), (5, 6)]

fig, axes = plt.subplots(2, 2, figsize=(10, 10))
fig.suptitle('Фигуры Лисажу с разными соотношениями частот', fontsize=16)

for ax, (a, b) in zip(axes.flat, ratios):
    x = np.sin(a * t)
    y = np.sin(b * t)

    ax.plot(x, y)
    ax.set_title(f'Соотношение частот {a}:{b}')
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.grid(True)
    ax.axis('equal')