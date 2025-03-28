import json

with open('ex_3.json', 'r', encoding='utf-8') as file:
    data = json.load(file)

new_invoice = {
    "id": 3,
    "total": 150.00,
    "items": [
        {
            "name": "item 4",
            "quantity": 3,
            "price": 80.00
        },
        {
            "name": "item 5",
            "quantity": 2,
            "price": 70.00
        }
    ]
}
data['invoices'].append(new_invoice)

with open('ex_3_updated.json', 'w', encoding='utf-8') as file:
    json.dump(data, file, indent=4)
