import os

def FlagsForFile(filename, **kwargs):
    return {
        'flags': [
            '-Wall',
            '-Wextra',
            '-Werror',
            '-std=c++11',
            '-x', 'c++',
            '-isystem', '/usr/include/c++/8.2.1',
            '-I', 'include',
            '-I', '/usr/include'],
        'include_paths_relative_to_dir' : os.path.dirname(
            os.path.abspath(__file__))
    }
