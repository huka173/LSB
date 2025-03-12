#include <opencv2\imgcodecs.hpp>
#include <iostream>
#include <bitset>
#include <Windows.h>

void encryptMessage(cv::Mat img, std::string message)
{
    std::string binaryMessage;
    for (char c : message) 
    {
        binaryMessage += std::bitset<8>(c).to_string();
    }

    binaryMessage += "00000000";

    int bitIndex = 0;

    for (int y = 0; y < img.rows; y++) 
    {
        for (int x = 0; x < img.cols; x++) 
        {
            cv::Vec3b& pixel = img.at<cv::Vec3b>(y, x);
            for (int c = 0; c < 3; c++) 
            {
                if (bitIndex < binaryMessage.size()) 
                {
                    pixel[c] = (pixel[c] & 0xFE) | (binaryMessage[bitIndex] - '0');
                    bitIndex++;
                }
                else 
                {
                    return;
                }
            }
        }
    }
}

std::string decryptMessage(cv::Mat img)
{
    std::string binaryMessage;

    for (int y = 0; y < img.rows; y++) 
    {
        for (int x = 0; x < img.cols; x++) 
        {
            cv::Vec3b pixel = img.at<cv::Vec3b>(y, x);

            for (int c = 0; c < 3; c++) 
            {
                binaryMessage += std::to_string(pixel[c] & 1);
            }
        }
    }

    std::string message;
    for (size_t i = 0; i < binaryMessage.size(); i += 8) 
    {
        std::string byteStr = binaryMessage.substr(i, 8);
        char ch = static_cast<char>(std::bitset<8>(byteStr).to_ulong());

        if (ch == '\0')
        {
            break;
        }
        message += ch;
    }

    return message;
}
