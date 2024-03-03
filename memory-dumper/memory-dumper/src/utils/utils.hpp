#ifndef UTILS_HPP
#define UTILS_HPP

#include "stdafx.hpp"

namespace utils
{
	namespace string
	{
		__inline std::string to_lower( std::string &str )
		{
			std::transform( str.begin( ), str.end( ), str.begin( ), ::tolower );
			return str;
		}
	}

	namespace implements
	{
		struct handle_deleter
		{
			void operator()( HANDLE handle ) const
			{
				if ( handle != nullptr && handle != INVALID_HANDLE_VALUE )
				{
					CloseHandle( handle );
				}
			}
		};
	}

	namespace process
	{
		__inline std::optional<int> get_pid( std::string &proc_name )
		{
			// checks if the target is a process or a service
			if ( proc_name.find( ".exe" ) != std::string::npos )
			{
				const auto handle = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );

				if ( handle != nullptr || handle != INVALID_HANDLE_VALUE )
				{
					PROCESSENTRY32 entry;
					entry.dwSize = sizeof( entry );

					do
					{
						if ( string::to_lower( proc_name ).compare( entry.szExeFile ) == 0 )
						{
							CloseHandle( handle );
							return entry.th32ProcessID;
						}

					} while ( Process32Next( handle, &entry ) );
				}

				CloseHandle( handle );
				return 0;
			}
			else
			{
				const auto service_manager = OpenSCManager( nullptr, nullptr, NULL );
				const auto service_handle = OpenService( service_manager, string::to_lower( proc_name ).c_str( ), SERVICE_QUERY_STATUS );

				SERVICE_STATUS_PROCESS service = {};
				DWORD bytes = 0;

				QueryServiceStatusEx( service_handle, SC_STATUS_PROCESS_INFO, reinterpret_cast< LPBYTE >( &service ), sizeof( service ), &bytes );
				CloseServiceHandle( service_handle );
				CloseServiceHandle( service_manager );

				return service.dwProcessId;
			}
		}
	}
}

#endif