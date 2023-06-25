import add_delete

def generate_json_files(count):
    i = 1
    base_filename = "data"
    file_extension = ".json"

    data = {}
    local_count = 0
    key = "key"
    value = "value"

    counter = 0

    while i != count + 1:
        template_data = add_delete.load_json("template.json")
        while local_count != count:
            data[key] = value
            key = "key" + str(i)
            value = "value" + str(i)
            file_path = base_filename + str(i) + file_extension
            add_delete.dump_json(eval(add_delete.serialize(data)), file_path)
            local_count += 1
            if counter < 2:
                data[key] = template_data
        key = "key"
        value = "value"
        local_count = 0
        i += 1
        counter += 1

def test():
    generate_json_files(2)
    file_path = "data1.json"
    local_data = add_delete.load_json(file_path)
    add_delete.add_or_modify_field("key1", "new_value", local_data, file_path)
    add_delete.add_or_modify_field("key2", "new_value2", local_data, file_path)
    if local_data["key1"] != "new_value" or local_data["key2"] != "new_value2":
        return False
    add_delete.delete_field("data1.json", "key2")
    local_data = add_delete.load_json("data1.json")
    if "key2" in local_data:
        return False
    
    file_path = "data2.json"
    local_data = add_delete.load_json(file_path)
    add_delete.add_or_modify_field("key1.address.street", "new_value", local_data, file_path)
    if local_data["key1"]["address"]["street"] != "new_value":
        return False
    add_delete.delete_field(file_path, "key1")
    local_data = add_delete.load_json(file_path)
    if "key1" in local_data:
        return False
    
    return True
