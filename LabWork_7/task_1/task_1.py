from jsonschema import validate, ValidationError
import json


def load_json_file(filename):
    with open(filename, 'r', encoding='utf-8') as file:
        return json.load(file)


def validate_json(data, schema):
    try:
        validate(instance=data, schema=schema)
        print("Валидация прошла успешно!")
        return True
    except ValidationError as e:
        print(f"Ошибка валидации: {e.message}")
        return False


schema = load_json_file('schema.json')

print("Валидация исходного файла (ex_1.json):")
original_data = load_json_file('ex_1.json')
validate_json(original_data, schema)

print("Валидация файла с ошибками (ex_1_invalid.json):")
invalid_data = load_json_file('ex_1_invalid.json')
validate_json(invalid_data, schema)
