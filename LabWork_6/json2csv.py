import argparse
import json


def json_to_csv(json_filename):
    try:
        with open(json_filename, 'r', encoding='utf8') as json_file:
            data = json.load(json_file)
        if not isinstance(data, dict) or len(data) != 1:
            raise ValueError('Файл должен содержать один ключ с данными.')
        csv_filename, records = next(iter(data.items()))
        if not isinstance(records, list):
            raise ValueError('Записи в файле должны быть списком.')
        csv_keys = list(records[0].keys())
        csv_dct = {key: list() for key in csv_keys}
        for dct in records:
            for key, value in dct.items():
                csv_dct[key].append(value)
        csv_filepath = f'{csv_filename}.csv'
        with open(csv_filepath, 'w', encoding='utf8') as csv_file:
            csv_file.write(','.join(csv_keys))
            csv_file.write('\n')
            for i in range(len(csv_dct[csv_keys[0]])):
                csv_file.write(','.join(csv_dct[key][i] for key in csv_keys))
                csv_file.write('\n')
        print(f'Файл {csv_filepath} успешно создан.')
    except FileNotFoundError:
        print(f'Ошибка: Файл {json_filename} не найден.')
    except json.JSONDecodeError:
        print(f'Ошибка: Файл {json_filename} не является подходящим.')


parser = argparse.ArgumentParser()
parser.add_argument('json_file')
args = parser.parse_args()
json_to_csv(args.json_file)
