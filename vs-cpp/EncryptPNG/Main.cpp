#include "stdafx.h"

#include <iostream>
#include "Classes/Files.h"
#include "Classes/Encrypt.h"

/**
 * 加密方法：
 * 将本程序放置在需要加密的文件夹根目录，运行并输入密钥和新扩展名。
 */

int main()
{
	std::cout << "===============================================" << std::endl;
	std::cout << ">> 请将本程序放置在需要加密的文件夹根目录，  <<" << std::endl;
	std::cout << ">> 输入密钥和扩展名后，将对PNG图片进行加密， <<" << std::endl;
	std::cout << ">> 输出文件在源目录下，扩展名为输入的扩展名。<<" << std::endl;
	std::cout << "===============================================" << std::endl;

	// 输入密钥
	aes_key key = { 0 };
	std::cout << std::endl << ">> 请输入16位密钥（AES）：" << std::endl;
	std::cin.get((char *)&key[0], key.size());

	// 输入扩展名
	std::string exten = "";
	std::cout << std::endl << ">> 请输入新扩展名（.fox）：" << std::endl;
	std::cin >> exten;
	
	// 寻找所有png图片
	std::vector<std::string> pngfiles;
	auto all_files = path::walk(path::curdir());
	for (auto filename : all_files)
	{
		if (path::splitext(filename)[1] == ".png")
		{
			pngfiles.push_back(filename);
		}
	}

	// 取相对路径
	auto absolute_path = path::curdir() + "\\";
	for (auto &filename : pngfiles)
	{
		filename = filename.substr(absolute_path.size(), filename.size());
	}

	std::cout << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << ">> 加密开始..." << std::endl << std::endl;

	// 图片加密操作
	EncryptPNG(pngfiles, key, exten);

	std::cout << std::endl;
	std::cout << ">> 加密已完成" << std::endl;
	std::cout << "===============================================" << std::endl << std::endl;
	
	system("pause");

	return 0;
}