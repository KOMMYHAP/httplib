import os

class project_config:
	def __init__(self):
		self._root_dir = os.path.join(os.getcwd(), "../")
		self._build_dir = os.path.join(get_root_dir(), "build")
		self.internal_init()

	def internal_init(self):
		if not os.path.exists(self.build_dir()):
			mkdir(self.build_dir())

	def root_dir(self):
		return self._root_dir

	def build_dir(self):
		return self._build_dir

def get_root_dir():
	return os.path.join(os.getcwd(), "../")

def get_build_dir():
	return os.path.join(get_root_dir(), "build")
