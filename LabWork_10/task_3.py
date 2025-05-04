import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

t = np.linspace(0, 2 * np.pi, 1000)
frequency_ratio = np.linspace(0, 1, 100)

fig, ax = plt.subplots()
line, = ax.plot([], [], lw=2)

ax.set_xlim(-2, 2)
ax.set_ylim(-2, 2)
ax.set_aspect('equal', adjustable='box')
ax.set_title('Анимация вращения фигуры Лисажу')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.grid(True)


def init():
    line.set_data([], [])
    return line,


def animate(i):
    f = frequency_ratio[i]
    x = np.sin(2 * np.pi * t)
    y = np.sin(2 * np.pi * f * t)
    line.set_data(x, y)
    return line,


ani = FuncAnimation(fig, animate, init_func=init, frames=len(frequency_ratio), interval=100, blit=True)

plt.show()
