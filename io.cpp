#include <opencv2\highgui.hpp>
#include <opencv2\imgcodecs.hpp>
#include <iostream>
#include <Windows.h>

std::string getNameFile()
{
	std::cout << "¬ведите название файла (<им€ файла>.<расширение>): ";

	std::string filename;
	std::cin >> filename;
	std::cin.clear();
	std::cin.ignore();

	return filename;
}

std::string inputLargeMessage()
{
	std::ostringstream messageStream;
	std::cout << "¬ведите сообщение (нажмите CTRL+Z и Enter дл€ завершени€ ввода):" << std::endl;

	std::string line;
	while (std::getline(std::cin, line))
	{
		messageStream << line << '\n';
	}

	if (std::cin.eof())
	{
		std::cin.clear();
	}

	return messageStream.str();
}