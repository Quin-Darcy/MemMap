#include "portable_resources.h"

#if defined(_WIN32)
struct stat {
	off_t st_size = 0;
};
#endif

class MemMap {
private:
	int open_file_descriptor;
	HANDLE open_handles[2];

public:
	LPCSTR 	source_file_name;
	LPVOID  base_address;

	MemMap() {};
	MemMap(LPCSTR _file_name);
	~MemMap();

	void MapToMem();
	void MapToMem_Win32();
};

MemMap::MemMap(LPCSTR _file_name) {
	source_file_name = _file_name;

#if defined(_WIN32)
	MapToMem_Win32();
#else
	MapToMem();
#endif
}

void MemMap::MapToMem() {
	printf("Openeing file: %s\n", source_file_name);
	int file_descriptor = open(source_file_name, O_RDONLY, S_IRUSR | S_IWUSR);
	struct stat stat_buffer;

	if (fstat(file_descriptor, &stat_buffer) == -1)
	{
		perror("Couldn't get file size with fstat()\n");
		return;
	}
	else
	{
		open_file_descriptor = file_descriptor;
	}
	printf("File opened with file descriptor: %d\n", file_descriptor);
	off_t file_size = stat_buffer.st_size;

	printf("Mapping open file into memory...\n");
	base_address = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, file_descriptor, 0);

	if (base_address == MAP_FAILED) 
	{
		perror("Failed to map open file with mmap()\n");
		return;
	}

	return;
}

void MemMap::MapToMem_Win32() {
	HANDLE open_file;
	HANDLE file_mapping;

	printf("Creating file: %s\n", source_file_name);
	open_file = CreateFileA(source_file_name, GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if (open_file == INVALID_HANDLE_VALUE) {
		printf("Could not open file with CreateFile()\n");
		return;
	}
	else {
		open_handles[0] = open_file;
	}
	printf("File created with handle: %d\n", open_file);

	printf("Creating file mapping ...\n");
	file_mapping = CreateFileMappingA(open_file, NULL, PAGE_READONLY, 0, 0, NULL);
	if (file_mapping == NULL)
	{
		CloseHandle(open_file);
		printf("Could not create file mapping with CreateFileA()\n");
		return;
	}
	else
	{
		open_handles[1] = file_mapping;
	}
	printf("Mapping created with handle: %d\n", file_mapping);

	printf("Mapping view of file ...\n");
	base_address = MapViewOfFile(file_mapping, FILE_MAP_READ, 0, 0, 0);
	if (base_address == NULL)
	{
		printf("Could not map view of file with MapViewOfFile()\n");
		CloseHandle(file_mapping);
		CloseHandle(open_file);
		return;
	}

	return;
}

MemMap::~MemMap() {
	#if defined(_WIN32)
		CloseHandle(open_handles[1]);
		CloseHandle(open_handles[0]);
	#else
		close(open_file_descriptor);
	#endif
}


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
