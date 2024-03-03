#include "stdafx.hpp"
#include "dumper.hpp"

namespace dumper
{
    void c_dumper::dump_memory( std::string &proc_name )
    {
        try
        {
            const int pid = utils::process::get_pid( proc_name ).value( );

            if ( !pid )
                throw std::runtime_error( "process not found" );

            const safe_handle handle( OpenProcess( PROCESS_ALL_ACCESS, false, pid ) ); // safe_handle is from utils\utils.hpp

            if ( !handle || handle == nullptr )
                throw std::runtime_error( "failed to open process" );

            MEMORY_BASIC_INFORMATION mbi {};

            std::filesystem::create_directory( "C:\\Windows\\Temp\\Dumps" );
            std::ofstream outfile( "C:\\Windows\\Temp\\Dumps\\" + proc_name + ".txt", std::ios::binary );

            for ( size_t addr = 0; VirtualQueryEx( handle.get( ), reinterpret_cast< LPVOID >( addr ), &mbi, sizeof( mbi ) ); addr += mbi.RegionSize )
            {
                if ( !( mbi.State == MEM_COMMIT && mbi.Protect != PAGE_NOACCESS && mbi.Protect != PAGE_GUARD ) )
                    continue;

                std::vector<char> buffer( mbi.RegionSize );

                if ( !ReadProcessMemory( handle.get( ), reinterpret_cast< LPVOID >( addr ), &buffer[ 0 ], mbi.RegionSize, nullptr ) )
                    continue;

                outfile.write( buffer.data( ), buffer.size( ) );
            }

            std::cout << "[+] strings dumped successfully";
            ShellExecuteA( nullptr, "explore", "C:\\Windows\\Temp\\Dumps", nullptr, nullptr, SW_SHOWNORMAL );
        }
        catch ( const std::exception &e )
        {
            MessageBox( nullptr, e.what( ), "error", MB_ICONERROR | MB_OK );
        }
    }
}