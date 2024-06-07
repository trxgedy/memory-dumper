# 💾 memory-dumper
- simple tool that dumps the strings of a process/service

## 📝 Purpose
- forensic analysis.

## 👨🏽‍💻 Download 
- Download at [releases section](https://github.com/trxgedy/memory-dumper/releases)

## 📘 Usage
```cpp
int __stdcall main( )
{
	std::string proc_to_dump = "process_name.exe";

	const auto dumper_ = std::make_unique<dumper::c_dumper>( );
	dumper_->dump_memory( proc_to_dump );

	std::cin.get( );
	return EXIT_SUCCESS;
}
```

## 🎥 Showcase
https://github.com/trxgedy/memory-dumper/assets/79763373/4ff71d6e-00ba-47c8-a731-e32a877df02e
