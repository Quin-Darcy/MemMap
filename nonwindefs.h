#ifndef _NONWINDEFS_
#define _NONWINDEFS_

#define O_RDONLY    NULL 
#define S_IRUSR     NULL
#define S_IWUSR     NULL
#define PROT_READ   NULL
#define MAP_PRIVATE NULL
#define MAP_FAILED  NULL


#define open(a, b, c)           (0)
#define fstat(a, b)             (0)
#define mmap(a, b, c, d, e, f)  (NULL)

#endif
