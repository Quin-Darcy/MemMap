#include "../defs/portable_resources.h"

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