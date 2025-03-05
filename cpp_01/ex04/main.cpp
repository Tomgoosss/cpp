#include "Main.hpp"

bool FileReplacer::open_file(const std::string &filename)
{
	_source.open(filename, std::fstream::in);
	if (!_source.is_open())
	return (false);

	std::string new_filename = filename + ".replace";
	// std::string new_filename = "../" + filename + ".replace";
	_dest.open(new_filename, std::fstream::out);

	return _dest.is_open();
}

void FileReplacer::edit_file()
{
	std::string line;
	std::string temp_line;
	std::size_t found_last;
	std::size_t found;

	while (std::getline(_source, line))
	{
		temp_line.clear();
		found_last = 0;
		found = 0;
		while ((found = line.find(_s1, found_last)) != std::string::npos)
		{
			temp_line.append(line, found_last, found - found_last);
			temp_line.append(_s2);
			found_last = found + _s1.length();
		}
		temp_line.append(line, found_last, line.length() - found_last);
		_dest << temp_line << std::endl;
	}
}

FileReplacer::FileReplacer(const std::string &filename, const std::string &str1, const std::string &str2) : _s1(str1), _s2(str2)
{
	if (!open_file(filename))
	{
		std::cerr << "could not make or open files" << std::endl;
		return;
	}
	edit_file();
}

// not necessary but just to show what a default destructor automatically does
FileReplacer::~FileReplacer()
{
	if (_source.is_open())
		_source.close();
	if (_dest.is_open())
		_dest.close();
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "incorrect amound of arguments you want this <./program file str1 str2>" << std::endl;
		return(1);
	}
	std::string file_name = argv[1];
	std::string paste = argv[2];
	std::string del = argv[3];
	FileReplacer(file_name, del, paste);
	return (0);
}