#include <string_view>
#include "httplib/utils.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		// utils::PrintUsage(argv[0]);
		return -1;
	}

	const std::string_view url = argv[1];
	if (!httplib::utils::IsHttp(url))
	{
		// utils::PrintUsage(argv[0]);
		return -1;
	}

	return 0;
}
