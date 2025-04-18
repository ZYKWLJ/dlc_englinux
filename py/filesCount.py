import os

def count_file_types(directory):
    file_type_count = {}
    for root, dirs, files in os.walk(directory):
        for file in files:
            file_extension = os.path.splitext(file)[1]
            if file_extension not in file_type_count:
                file_type_count[file_extension] = 1
            else:
                file_type_count[file_extension] += 1
    return file_type_count

directory = '/home/eyk/1code/重构对流层/英语'
result = count_file_types(directory)
for file_type, count in result.items():
    if file_type == ".c" or file_type == ".h":
        print(f"{file_type} file, {count}")