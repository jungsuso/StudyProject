//
// daytime_client.cpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
	try
	{
		if (argc != 2) // 접속할 주소 입력 안한 경우
		{
			std::cerr << "Usage: client <host>" << std::endl;
			return 1;
		}

		tcp::iostream stream(argv[1], std::to_string(int(13)));
		if (!stream) // 하드웨어적으로 연결이 안된 경우
		{
			std::cout << "Unable to connect: " << stream.error().message() << std::endl;
			return 1;
		}

		for (;;)
		{
			// 서버에게 보내는 메세지
			std::string client_message;
			getline(std::cin, client_message);
			stream << client_message;
			stream << std::endl;

			// 서버로부터 받은 메세지
			std::string line;
			std::getline(stream, line);
			std::cout << "Server : " << line << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}