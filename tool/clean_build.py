#!/usr/bin/env python3

import subprocess
import shlex
import pathlib
from tqdm.auto import tqdm

plugin_root = pathlib.Path(__file__).parent.parent
mapvina_root = plugin_root / 'third-party/mapvina-native'
mapvina_flutter_root = mapvina_root / 'platform/flutter'

folders_to_clean = []
for item in mapvina_root.iterdir():
    if item.is_dir() and item.name.startswith('build-'):
        folders_to_clean.append(item)

if mapvina_flutter_root.exists():
  folders_to_clean.append(mapvina_flutter_root)

if not folders_to_clean:
    print('No build folders found to clean.')
    exit(0)

print('Cleaning: ')
for folder in folders_to_clean:
    print(f' - {folder}')

print()
print('Are you sure you want to proceed? (y/N): ', end='')
response = input().strip().lower()
if response != 'y':
    print('Aborting.')
    exit(0)

for folder in tqdm(folders_to_clean, desc="Cleaning build folders"):
    if folder.exists() and folder.is_dir():
        subprocess.run(shlex.split(f'rm -rf "{folder}"'))
