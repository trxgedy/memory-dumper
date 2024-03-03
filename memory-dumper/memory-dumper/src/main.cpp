#include "stdafx.hpp"
#include "dumper\dumper.hpp"

int __stdcall main( )
{
	const auto dumper_ = std::make_unique<dumper::c_dumper>( );
	dumper_->dump_memory( "lsass.exe" );	

	return EXIT_SUCCESS;
}