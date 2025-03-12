import argparse
from pathlib import Path

parser = argparse.ArgumentParser()
parser.add_argument('--dirpath', type=str, required=True)
parser.add_argument('--missing_files', type=str, default='missing_files.txt')
args = parser.parse_args()

dirpath = Path(args.dirpath)
missing_files_path = Path(args.missing_files)

if not missing_files_path.exists() or not missing_files_path.is_file():
    print(f"Ошибка: файл '{missing_files_path}' не существует.")
    exit()

with open(missing_files_path, 'r') as f:
    missing_files = f.read().splitlines()

for file in missing_files:
    file_path = dirpath / file
    if not file_path.exists():
        with open(file_path, 'w') as f:
            pass
        print(f"Создан файл: {file_path}")
    else:
        print(f"Файл уже существует: {file_path}")
