#ifndef DUMPER_HPP
#define DUMPER_HPP

namespace dumper
{
	class c_dumper
	{
	public:
		c_dumper( ) = default;
		~c_dumper( ) = default;

		void dump_memory( std::string );
	};
}

#endif