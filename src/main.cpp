#include "../includes/defs/portable_resources.h"
#include "../includes/memmap/memmap.h"


int main(int argc, char* argv[])
{
	LPCSTR source_file_name;

	if (argc == 2)
	{
		source_file_name = argv[1];
	}
	else 
	{
		printf("[USAGE] .\\memmap <source_file_path>\n");
		return -1;
	}

	MemMap mapped_file(source_file_name);

	printf("Base Address: 0x%x\n\n", mapped_file.base_address);

	return 0;
}