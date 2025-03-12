from pathlib import Path
import shutil

inp = input()
if inp == '':
    inp = '.'
folder_dir = Path(inp)
if not folder_dir.is_dir():
    print('Папки не существует')
    exit()

small_files = [f for f in folder_dir.iterdir() if f.is_file() and f.stat().st_size < 2 ** 11]
if small_files:
    print('Файлы меньше 2K')
    for f in small_files:
        print(f.name)
else:
    print('Нет файлов меньше 2K')
    exit()
small_folder = folder_dir / 'small'
small_folder.mkdir(exist_ok=True)
for f in small_files:
    shutil.copy(f, small_folder / f.name)

print(f"Файлы скопировны в папку '{small_folder}'")
