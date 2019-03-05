import os
import sys

ignore_files = sys.argv[1:]
gitignore = './.gitignore'

if os.path.isfile(gitignore):
    lines = open(gitignore).readlines()
    with open(gitignore, 'a') as ignore:
        for file in ignore_files:
            file = file + '\n'
            if file not in lines:
                ignore.write(file)
else:
    with open(gitignore, 'w') as ignore:
        for file in ignore_files:
            ignore.write(file + '\n')
