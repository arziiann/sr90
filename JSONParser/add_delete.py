import my_json

def add_or_modify_field(user_input, new_value, data, file_path):
    keys = user_input.split('.')
    current_data = data
    for index, key in enumerate(keys):
        if key not in current_data:
            if index == len(keys) - 1:
                current_data[key] = new_value
                print(f"'{user_input}' created with value '{new_value}'.")
            else:
                current_data[key] = {}
                current_data = current_data[key]
                print(f"Created new key '{key}'.")
        else:
            if index == len(keys) - 1:
                current_data[key] = new_value
                print(f"'{user_input}' updated to '{new_value}'.")
            else:
                current_data = current_data[key]
    my_json.dump(data, file_path)
    print("Data saved.")
    
    

def delete_field(file_path, user_input):
    data = my_json.load_json(file_path)
    print("Original data:", data)

    field_to_delete = user_input
    keys = field_to_delete.split('.')
    current_data = data
    for index, key in enumerate(keys):
        if key not in current_data:
            print(f"Key '{key}' not found!")
            break
        if index == len(keys) - 1:
            del current_data[key]
            print(f"Field '{field_to_delete}' removed from JSON.")
        else:
            current_data = current_data[key]

    my_json.dump(data, file_path)
    print("Data saved.")

def parse_json_file(file_path):
    while True:
        data = my_json.load_json(file_path)
        print("Original data:", my_json.serialize(data))
        user_input = input("Enter the full key name you want to modify: ")
        operation_input = input("Select Operation 'add'  or 'delete' or 'exit': ")

        if operation_input == 'add':
            new_value = input("Value: ")
            add_or_modify_field(user_input, new_value, data, file_path)
        elif operation_input == 'delete':
            delete_field(file_path, user_input)
        elif operation_input == 'exit':
            break