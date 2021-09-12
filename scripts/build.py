#!/usr/bin/python3

import subprocess
import os
from internal_config import *

def main():
	config = project_config()
	try:
		args = [
			'meson',
			'compile',
			'-C', config.build_dir(),
		]
		subprocess.run(args, check=True)
	except subprocess.CalledProcessError as err:
		print("Failed to build project. Details: " + str(err))

main()
