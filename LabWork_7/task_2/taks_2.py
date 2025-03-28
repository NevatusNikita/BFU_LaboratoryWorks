# В файл добавлены недостающие квадратные скобки, jsonformatter не удалось применить
# так как есть некоторые несостыковки
import json

with open('ex_2.json', 'r', encoding='utf-8') as file:
    try:
        data = json.load(file)
    except Exception as e:
        print(f'Ошибка: {e}')

with open('out_ex_2.json', 'w', encoding='utf-8') as file:
    json.dump(data, file, indent=4)

for user in data:
    print(f"{user['name']}: {user['phoneNumber']}")
