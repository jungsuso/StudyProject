//
// daytime_server.cpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main()
{
	try
	{
		boost::asio::io_service io_service;

		tcp::endpoint endpoint(tcp::v4(), 13); // endpoint : 통신을 하는 끝 점, tcp::v4 : tcp 버전 4 (* 버전 6도 있음), 13 : port number
		tcp::acceptor acceptor(io_service, endpoint); // acceptor 생성

		std::cout << "Server Started" << std::endl;

		for (;;) // 여러사람이 들어왔다 나갔다를 반복하기 때문에 무한루프를 사용하는 경우가 많음
		{
			std::string message_to_send;

			boost::asio::ip::tcp::iostream stream;

			std::cout << "Server Connected" << std::endl;

			boost::system::error_code ec;
			acceptor.accept(*stream.rdbuf(), ec);

			std::cout << "Client Connected" << std::endl;

			if (!ec)
			{
				for (;;)
				{
					// 클라이언트로부터 받은 메세지
					std::string line;
					std::getline(stream, line);
					std::cout << "Client : " << line << std::endl;

					// 클라이언트에게 보내는 메세지
					getline(std::cin, message_to_send);
					stream << message_to_send;
					stream << std::endl; // getline으로 메세지를 주고받기 때문에 마지막에 endl이 필요함
				}
			}
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}