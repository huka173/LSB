#include <opencv2\highgui.hpp>
#include <opencv2\imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <Windows.h>
#include <iostream>
#include "io.h"
#include "lsb.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	std::cout << "Привет, это программа для шифрования и расшифрования сообщений в картинке.\n"
		<< "Она использует алгоритм LSB\n"
		<< "Справка: имя файла должно содержать английские символы\n"
		<< "Пример для файла: <имя файла>.<расширение>\n"
		<< "Зашифровывать можно только английские буквы"
		<< std::endl << std::endl;

	for (;;)
	{
		std::string filename = getNameFile();
		cv::Mat img = cv::imread(filename);

		if (img.empty())
		{
			system("cls");
			std::cerr << "Такого файла нет" << std::endl;
			std::cerr << "Используй в имени файла только английские буквы" << std::endl;
			continue;
		}

		for (;;)
		{
			std::cout << "Что ты хочешь сделать:" << std::endl;
			std::cout << "Зашифровать сообщение: 1" << std::endl;
			std::cout << "Разшифровать сообщение: 2" << std::endl;

			int choose;
			std::cin >> choose;
			std::cin.clear();
			std::cin.ignore();


			if (choose == 1)
			{
				std::string message = inputLargeMessage();
				encryptMessage(img, message);
				cv::imwrite("new_" + filename, img);
				system("cls");
				std::cout << "Твой файл " << "new_" + filename << " зашифрован" << std::endl;
				break;
			}
			else if (choose == 2)
			{
				std::string message = decryptMessage(img);
				system("cls");
				std::cout << "Твое сообщение: " << std::endl;
				std::cout << message << std::endl;
				break;
			}
			else
			{
				std::cout << "Ты ввел не правильное число\nПопробуй снова" << std::endl;
				continue;
			}
		}

		int num;
		std::cin >> num;
		cv::waitKey(0);
		return 0;
	}
}