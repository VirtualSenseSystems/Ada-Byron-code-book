// -- Examples on how to use boost::algorithm::string

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm/remove_if.hpp>

#include "aux-raw.h"
#include "algorithm-string-pool.h"

namespace {

void
Output(const std::string& a_description, const std::string& a_value) {
	using Ada_Byron_code_book::raw::pad;
	std::cout << pad << a_description << ": \"" << a_value << "\""
		<< std::endl;
}

void
Output(const std::string& a_description, const std::wstring& a_value) {
	using Ada_Byron_code_book::raw::pad;
	std::cout << pad << a_description << ": \"" << std::flush;
	std::wcout << a_value << std::flush;
	std::cout << "\"" << std::endl;
}

void
ourToLower(std::string& a_text)
{
	std::transform(a_text.begin(), a_text.end(), a_text.begin(), ::tolower);
	for (auto& c : a_text) {
		switch (c) {
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		case '�': c = '�'; break;
		default:;
		}
	}
}
	
} // namespace

void
Ada_Byron_code_book::ExamplesOfAlgorithmsString()
{
	std::clog << __func__ << " started..." << std::endl;
	
	std::string name = "  Alan Turing 42  ";
	Output("name (original)", name);
	name.erase(boost::remove_if(name, ::isdigit), name.end());
	Output("name (after isdigit removal)", name);

	namespace ba = boost::algorithm;
	ba::to_lower(name);
	Output("name (after to_lower)", name);
	ba::to_upper(name);
	Output("name (after to_upper)", name);
	ba::trim_right(name);
	Output("name (after trim_right)", name);
	ba::trim(name);
	Output("name (after trim)", name);
	if (ba::iequals(name, "AlAn TuRiNg"))
		Output("iequals(name, \"AlAn TuRiNg\") returns true, with name", name);
	else
		Output("iequals(name, \"AlAn TuRiNg\") returns false, witn name", name);
	name.erase(remove_if(name.begin(), name.end(), ::isspace), name.end());
	Output("name (after isspace removal)", name);
	name.erase(
		remove_if(name.begin(), name.end(), ba::is_any_of("LN")),
		name.end());
	Output("name (after is_any_of(\"LN\") removal)", name);

	//std::wstring special = L"CAF� BJ�RK ����� ����� ����� ��"; // TODO
	std::string special = "CAF� BJ�RK ����� ����� ����� ��";
	Output(">>> special (original)", special);
	ourToLower(special);
	Output(">>> special (after ourToLower)", special);
	const std::string specialK = "caf� bj�rk ����� ����� ����� ��";
	const bool equal = special == specialK;
	std::cout << raw::pad << ">>> special == \"" << specialK << "\" is "
		<< std::boolalpha << equal << std::endl;

	const std::string line = "aa bb , cc dd , ee , gg,hh, ii ,kk";
	Output("line (original)", line);
	// Split the line a into sections using "," as the delimiter,
	// store result into a vector of strings
	// Code adapted from http://www.panix.com/~jrr/boost/string.htm on 05.26.2015
	std::vector<std::string> tokens;
	ba::split(tokens, line, ba::is_any_of(","));
	struct Trim { void operator()(std::string& a_s) const { ba::trim(a_s); } };
	for_each(tokens.begin(), tokens.end(), Trim());
	const std::string instanceCleaned = ba::join(tokens, ",");
	Output("line (after blanks around commas removal)", instanceCleaned);

	std::clog << __func__ << " finished." << std::endl;
}

// -- eof
