from pathlib import Path
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--dirpath', type=str, default='.')
parser.add_argument('--files', nargs='*', default=[])
args = parser.parse_args()
print(args.files)
dirpath = Path(args.dirpath)
if not dirpath.is_dir():
    print('Такоей папки не существует')
    exit()
if args.files:
    existing_files = []
    missing_files = []
    for file in args.files:
        file_path = dirpath / file
        if file_path.exists() and file_path.is_file():
            existing_files.append(file)
        else:
            missing_files.append(file)

    with open('existing_files.txt', 'w') as f:
        for file in existing_files:
            f.write(file + '\n')

    with open('missing_files.txt', 'w') as f:
        for file in missing_files:
            f.write(file + '\n')

    print('Найденные файлы:')
    for file in existing_files:
        print(file)
    print('Отсутствующие файлы:')
    for file in missing_files:
        print(file)
else:
    total_files = 0
    total_size = 0
    for entry in dirpath.iterdir():
        if entry.is_file():
            total_files += 1
            total_size += entry.stat().st_size
    print(f"Информация о папке '{dirpath}':")
    print(f"Количество файлов: {total_files}")
    print(f"Общий размер файлов: {total_size} байт")
