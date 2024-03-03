# 💾 memory-dumper
- simple tool that dumps the strings of a process/service

## 📝 Purpose
- My friend asked me to code this for him for forensic analysis purposes.

##![image](https://github.com/trxgedy/memory-dumper/assets/79763373/7ee88b25-eb35-48ea-92f3-2cfcba0e6bca)
 Download 
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
