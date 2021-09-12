#include <iostream>
#include <iomanip>

#include "httplib/utils.h"

using namespace std;

template <size_t Size>
auto DoTesting(const array<const char *, Size> & testset)
{
	// intiialises array with all false values
	array<bool, Size> result = {};

	size_t i = 0;
	for (auto sample : testset)
	{
		result[i++] = utils::IsHttp(sample);
	}

	return result;
}

template <size_t Size>
bool AnalyseResult(const array<const char *, Size> & testSet, const array<bool, Size> & resultSet, bool expected)
{
	cerr << "Checks test set on " << boolalpha << expected << noboolalpha << "\n";

	bool ok = true;
	size_t i = 0;
	for (auto v : resultSet)
	{
		if (v != expected)
		{
			cerr << i + 1 << ". " << quoted(testSet[i]) << '\n';
			ok = false;
		}
		++i;
	}

	cerr << (ok ? "Success!" : "Failed.") << '\n';
	return ok;
};

int main()
{
	array testset_ok = {
		R"(http://google.ru)",
		R"(http://google.com)",
		R"(http://google.com)",
	};

	array testset_fail = {
		R"(ftp://google.ru)",
		R"(https://google.ru)",
	};

	auto result_ok = DoTesting(testset_ok);
	auto result_fail = DoTesting(testset_fail);

	cerr << "Processing..." << '\n';
	bool checked_ok = AnalyseResult(testset_ok, result_ok, true);
	cerr << '\n';
	bool checked_fail = AnalyseResult(testset_fail, result_fail, false);
	cerr << endl;

	bool ok = checked_ok && checked_fail;
	return ok ? 0 : -1;
}
