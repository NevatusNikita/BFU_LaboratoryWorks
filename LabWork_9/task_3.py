import numpy as np

arr = np.random.normal(size=(10, 4))

min_val = np.min(arr)
max_val = np.max(arr)
mean_val = np.mean(arr)
std_val = np.std(arr)

first_5 = arr[:5]

print(f"Минимум: {min_val}\nМаксимум: {max_val}\n"
      f"Среднее занчение: {mean_val}\nСтандартное отклонение: {std_val}\n")
