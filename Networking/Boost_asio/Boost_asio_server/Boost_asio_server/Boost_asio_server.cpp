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

		tcp::endpoint endpoint(tcp::v4(), 13); // endpoint : ����� �ϴ� �� ��, tcp::v4 : tcp ���� 4 (* ���� 6�� ����), 13 : port number
		tcp::acceptor acceptor(io_service, endpoint); // acceptor ����

		std::cout << "Server Started" << std::endl;

		for (;;) // ��������� ���Դ� �����ٸ� �ݺ��ϱ� ������ ���ѷ����� ����ϴ� ��찡 ����
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
					// Ŭ���̾�Ʈ�κ��� ���� �޼���
					std::string line;
					std::getline(stream, line);
					std::cout << "Client : " << line << std::endl;

					// Ŭ���̾�Ʈ���� ������ �޼���
					getline(std::cin, message_to_send);
					stream << message_to_send;
					stream << std::endl; // getline���� �޼����� �ְ�ޱ� ������ �������� endl�� �ʿ���
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