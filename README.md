# 💾 memory-dumper
- simple tool that dumps the strings of a process/service

## Purpose
- My friend asked me to code this for him for forensic analysis purposes.

## Download 
- Download at [releases section](https://github.com/trxgedy/memory-dumper/releases)

## Usage
```cpp
int __stdcall main( )
{
	const auto dumper_ = std::make_unique<dumper::c_dumper>( );
	dumper_->dump_memory( "process_name.exe" );

	std::cin.get( );
	return EXIT_SUCCESS;
}
```
