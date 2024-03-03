#include "stdafx.hpp"
#include "dumper\dumper.hpp"

int __stdcall main( )
{
	std::string proc_to_dump {};

	std::cout << "[+] process/service name: ";
	std::cin >> proc_to_dump;

	const auto dumper_ = std::make_unique<dumper::c_dumper>( );
	dumper_->dump_memory( proc_to_dump );

	return EXIT_SUCCESS;
}