import os

# 源目录
source_dir = '/home/eyk/1code/重构对流层/英语/include/shellText'
# 目标文件
target_file = '/home/eyk/1code/重构对流层/英语/include/shellText/include.h'

# 查找源目录下的所有头文件
header_files = []
for root, dirs, files in os.walk(source_dir):
    for file in files:
        if file.endswith('.h'):
            # 获取相对路径
            relative_path = os.path.relpath(os.path.join(root, file), os.path.dirname(target_file))
            header_files.append(relative_path)

# 生成包含语句
include_statements = [f'#include "{header}"' for header in header_files]

# 将包含语句写入目标文件
with open(target_file, 'w', encoding='utf-8') as f:
    for statement in include_statements:
        f.write(statement + '\n')

print(f"所有头文件已包含在 {target_file} 中。")
    