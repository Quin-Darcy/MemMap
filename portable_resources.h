#if defined(_WIN32)

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x600
#endif 
#include <windows.h>

#else

#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdint>
#include "windefs.h"

#endif

#include <stdio.h>
