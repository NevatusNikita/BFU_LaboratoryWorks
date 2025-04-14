import csv
import os
import random


class CSVTools:
    def __init__(self, filename: str):
        self.filename = filename
        self.data = []
        self.headers = []
        self._load_file()

    def _load_file(self):
        # Загрузка данных из файла
        with open(self.filename, 'r', encoding='utf-8') as file:
            reader = csv.reader(file)
            self.headers = next(reader)
            self.data = [row for row in reader]

    def show(self, display_type: str = 'top', rows: int = 5, separator: str = ','):
        """Вывод данных в определенном формате
        display_type: 'top', 'bottom', 'random' - из какой части файла брать данные
        rows: количество строк, которые необходимо отобразить
        separator: символ разделения колонок"""
        if rows <= 0:
            print('Количество строк должно быть положительным числом')
            return

        if len(self.data) < rows:
            print(f'Внимание: в файле только {len(self.data)} строк, '
                  f'что меньше запрошенного количества {rows}')
            rows = len(self.data)

        if display_type == 'top':
            display_data = self.data[:rows]
        elif display_type == 'bottom':
            display_data = self.data[-rows:]
        elif display_type == 'random':
            display_data = random.sample(self.data, min(rows, len(self.data)))
        else:
            print(f'Неизвестный тип отображения: {display_type}. Используется "top"')
            display_data = self.data[:rows]

        col_widths = [max(len(str(item)) for item in col)
                      for col in zip(*([self.headers] + display_data))]

        header = separator.join(f'{h:<{w}}' for h, w in zip(self.headers, col_widths))
        print(header)
        print('-' * len(header))

        for row in display_data:
            print(separator.join(f'{str(item):<{w}}' for item, w in zip(row, col_widths)))

    def info(self):
        # Вывод статистических данных
        print(f'Размер данных: {len(self.data)}x{len(self.headers)}')
        print('\nИнформация о колонках:')

        for i, header in enumerate(self.headers):
            non_empty = 0
            col_types = set()

            for row in self.data:
                if i < len(row) and row[i].strip():
                    non_empty += 1
                    value = row[i]
                    if value.isdigit():
                        col_types.add(int)
                    else:
                        try:
                            float(value)
                            col_types.add(float)
                        except ValueError:
                            col_types.add(str)

            if len(col_types) == 0:
                data_type = "empty"
            elif len(col_types) == 1:
                data_type = col_types.pop().__name__
            else:
                data_type = "string"

            print(f"{header:<15} {non_empty:<7} {data_type}")

    def del_nan(self):
        # Удаление строк с пустыми значениями
        self.data = [row for row in self.data if all(field.strip() for field in row)]

    def make_ds(self):
        # Разбиение данных на обучающую и тестовую выборки
        random.shuffle(self.data)

        split_idx = int(0.8 * len(self.data))
        train_data = self.data[:split_idx]
        test_data = self.data[split_idx:]

        os.makedirs("WorkData/Learning", exist_ok=True)
        os.makedirs("WorkData/Testing", exist_ok=True)

        with open("WorkData/Learning/train.csv", 'w', encoding='utf-8', newline='') as file:
            writer = csv.writer(file)
            writer.writerow(self.headers)
            writer.writerows(train_data)

        with open("WorkData/Testing/test.csv", 'w', encoding='utf-8', newline='') as file:
            writer = csv.writer(file)
            writer.writerow(self.headers)
            writer.writerows(test_data)

        print(f"Данные разделены: {len(train_data)} записей в обучающей выборке, {len(test_data)} в тестовой")


processor = CSVTools('example.csv')

print("Показать первые 5 строк")
processor.show(separator=' ')

print("\nПоказать 3 случайные строки")
processor.show(display_type='random', rows=3)

print("\nИнформация о данных")
processor.info()

print("\nУдаление строк с пустыми значениями")
processor.del_nan()
processor.info()

print("\nРазделение данных на обучающую и тестовую выборки")
processor.make_ds()
