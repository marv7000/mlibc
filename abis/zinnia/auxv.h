#ifndef _ABIBITS_AUXV_H
#define _ABIBITS_AUXV_H

#define AT_HWCAP 16
#define AT_SECURE 23
#define AT_RANDOM 25
#define AT_EXECFN 31
#define AT_SYSINFO_EHDR 33

/* Zinnia specific auxvector entries. */

#define AT_INIT_HANDLE 0x1000
#define AT_POSIX_HANDLE 0x1001

#endif /* _ABIBITS_AUXV_H */
