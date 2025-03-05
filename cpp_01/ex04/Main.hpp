#ifndef MAIN_HPP
#define MAIN_HPP

#include <string>
#include <iostream>
#include <fstream>

class FileReplacer {
	private:
		std::ifstream _source;
		std::ofstream _dest;
		std::string _s1;
		std::string _s2;
	public:
		FileReplacer(const std::string &filename, const std::string& str1, const std::string& str2);
		~FileReplacer();
		bool open_file(const std::string &filename);
		void edit_file();
};

#endif