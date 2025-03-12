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
	std::cout << "������, ��� ��������� ��� ���������� � ������������� ��������� � ��������.\n"
		<< "��� ���������� �������� LSB\n"
		<< "�������: ��� ����� ������ ��������� ���������� �������\n"
		<< "������ ��� �����: <��� �����>.<����������>\n"
		<< "������������� ����� ������ ���������� �����"
		<< std::endl << std::endl;

	for (;;)
	{
		std::string filename = getNameFile();
		cv::Mat img = cv::imread(filename);

		if (img.empty())
		{
			system("cls");
			std::cerr << "������ ����� ���" << std::endl;
			std::cerr << "��������� � ����� ����� ������ ���������� �����" << std::endl;
			continue;
		}

		for (;;)
		{
			std::cout << "��� �� ������ �������:" << std::endl;
			std::cout << "����������� ���������: 1" << std::endl;
			std::cout << "������������ ���������: 2" << std::endl;

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
				std::cout << "���� ���� " << "new_" + filename << " ����������" << std::endl;
				break;
			}
			else if (choose == 2)
			{
				std::string message = decryptMessage(img);
				system("cls");
				std::cout << "���� ���������: " << std::endl;
				std::cout << message << std::endl;
				break;
			}
			else
			{
				std::cout << "�� ���� �� ���������� �����\n�������� �����" << std::endl;
				continue;
			}
		}

		int num;
		std::cin >> num;
		cv::waitKey(0);
		return 0;
	}
}