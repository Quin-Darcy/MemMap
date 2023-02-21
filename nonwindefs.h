#ifndef _NONWINDEFS_
#define _NONWINDEFS_

#define O_RDONLY NULL 
#define S_IRUSR NULL
#define S_IWUSR NULL
#define PROT_READ NULL
#define MAP_PRIVATE NULL

#define off_t VOID
#define file_size NULL
#define stat nullptr
#define stat_buffer NULL

#define open(a, b, c) (NULL)
#define fstat(a, b) (NULL)
#define mmap(a, b, c, d, e, f) (NULL)

#endif
