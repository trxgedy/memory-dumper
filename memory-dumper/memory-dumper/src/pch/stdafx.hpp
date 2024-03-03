#ifndef STDAFX_HPP
#define STDAFX_HPP

#include <windows.h>
#include <TlHelp32.h>

#include <iostream>
#include <optional>
#include <algorithm>
#include <fstream>
#include <filesystem>

#include "utils\utils.hpp"

using safe_handle = std::unique_ptr<std::remove_pointer<HANDLE>::type, utils::implements::handle_deleter>;

#endif