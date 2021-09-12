#!/usr/bin/python3

import subprocess
import os
from internal_config import *

def main():
	config = project_config()
	try:
		args = [
			'meson',
			'setup',
			config.build_dir(),
			config.root_dir(),
			'--default-library', 'static',
			'--backend', 'ninja',
		]
		subprocess.run(args, check=True)
	except subprocess.CalledProcessError as err:
		print("Failed to setup project. Details: " + str(err))

main()
