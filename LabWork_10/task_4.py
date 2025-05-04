import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider

fig = plt.figure(figsize=(12, 8))
plt.subplots_adjust(bottom=0.3)

ax1 = plt.subplot2grid((2, 2), (0, 0))
ax2 = plt.subplot2grid((2, 2), (0, 1))
ax3 = plt.subplot2grid((2, 2), (1, 0), colspan=2)

init_amp1, init_freq1 = 1.0, 1.0
init_amp2, init_freq2 = 0.5, 2.0
x = np.linspace(0, 4 * np.pi, 1000)

line1, = ax1.plot(x, init_amp1 * np.sin(init_freq1 * x), 'b-', lw=2)
line2, = ax2.plot(x, init_amp2 * np.sin(init_freq2 * x), 'r-', lw=2)
line_sum, = ax3.plot(x, init_amp1 * np.sin(init_freq1 * x) + init_amp2 * np.sin(init_freq2 * x), 'g-', lw=2)

for ax in [ax1, ax2, ax3]:
    ax.set_xlim(0, 4 * np.pi)
    ax.set_ylim(-2, 2)
    ax.grid(True)

ax1.set_title('Волна 1')
ax2.set_title('Волна 2')
ax3.set_title('Сумма волн')

ax_amp1 = plt.axes([0.2, 0.20, 0.65, 0.03])
ax_freq1 = plt.axes([0.2, 0.15, 0.65, 0.03])
ax_amp2 = plt.axes([0.2, 0.10, 0.65, 0.03])
ax_freq2 = plt.axes([0.2, 0.05, 0.65, 0.03])

slider_amp1 = Slider(ax_amp1, 'Амплитуда 1', 0.1, 2.0, valinit=init_amp1)
slider_freq1 = Slider(ax_freq1, 'Частота 1', 0.1, 5.0, valinit=init_freq1)
slider_amp2 = Slider(ax_amp2, 'Амплитуда 2', 0.1, 2.0, valinit=init_amp2)
slider_freq2 = Slider(ax_freq2, 'Частота 2', 0.1, 5.0, valinit=init_freq2)


def update(val):
    amp1 = slider_amp1.val
    freq1 = slider_freq1.val
    amp2 = slider_amp2.val
    freq2 = slider_freq2.val

    wave1 = amp1 * np.sin(freq1 * x)
    wave2 = amp2 * np.sin(freq2 * x)

    line1.set_ydata(wave1)
    line2.set_ydata(wave2)
    line_sum.set_ydata(wave1 + wave2)

    for ax in [ax1, ax2, ax3]:
        ax.set_ylim(-max(amp1, amp2, amp1 + amp2) - 0.5, max(amp1, amp2, amp1 + amp2) + 0.5)

    fig.canvas.draw_idle()


slider_amp1.on_changed(update)
slider_freq1.on_changed(update)
slider_amp2.on_changed(update)
slider_freq2.on_changed(update)

plt.show()
