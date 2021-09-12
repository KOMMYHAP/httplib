#include "httplib/utils.h"

#include <regex>
#include <iostream>
#include <iomanip>

namespace httplib::utils
{
	bool IsHttp(std::string_view link)
	{
		std::regex httpRegex(R"delim((http?:\/\/.)?(www\.)?[-a-zA-Z0-9@:%._\+~#=]{2,256}\.[a-z]{2,6}\b([-a-zA-Z0-9@:%_\+.~#?&//=]*))delim");
		std::cmatch m;
		return std::regex_match(link.begin(), link.end(), m, httpRegex);
	}

	// void PrintUsage(std::string_view executableName)
	// {
	// 	std::cout
	// 		<< "Usage: " << std::quoted(executableName.data()) << " (url)" << '\n'
	// 		<< "    , where the url is a reference to a file via http protocol." << std::endl;
	// }
}
