import os

# 定义要遍历的目录列表
directories = [
    "/home/eyk/1code/重构对流层/英语/include",
    "/home/eyk/1code/重构对流层/英语/src"
]

# 打开总文件，用于写入内容
with open("total_file.txt", "w", encoding="utf-8") as total_file:
    for directory in directories:
        for root, dirs, files in os.walk(directory):
            for file in files:
                file_path = os.path.join(root, file)
                try:
                    with open(file_path, "r", encoding="utf-8") as f:
                        content = f.read()
                        relative_path = os.path.relpath(file_path, start=directory)
                        size = len(content)
                        
                        # 写入文件头
                        total_file.write(f"=== File: {file} ({relative_path}) ===\n")
                        total_file.write(f"Content size: {size} bytes\n")
                        total_file.write("----------------------------------------\n")
                        
                        # 写入文件内容
                        total_file.write(content)
                        
                        # 写入文件尾
                        total_file.write("----------------------------------------\n\n")
                except UnicodeDecodeError:
                    print(f"无法解码文件: {file_path}，跳过该文件。")
                except Exception as e:
                    print(f"处理文件 {file_path} 时出错: {e}")

print("所有文件内容已成功写入 total_file.txt")