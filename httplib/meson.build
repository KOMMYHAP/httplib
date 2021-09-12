subdir('sources')
subdir('include')

httplib = library(
	'httplib',
	httplib_sources,
	cpp_pch: httplib_pch_file,
	include_directories: httplib_include_dirs)

httplib_dep = declare_dependency(
	link_with: httplib,
	include_directories: include_directories('include/'),
)

if httplib_test_enabled
	subdir('tests')
	foreach test : httplib_tests
		exe = executable(test[0], test[1], dependencies: httplib_dep)
		test(test[0], exe)
	endforeach
endif
