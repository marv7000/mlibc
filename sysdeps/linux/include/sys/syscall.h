#ifndef _SYS_SYSCALL_H
#define _SYS_SYSCALL_H

/* On GNU/Linux, this header provides includes __NR_-prefixed syscall numbers,
 * and their SYS_ aliases. We defer to kernel headers for the numbers
 * (linux-headers, or an autogenerated stub while building), and an
 * autogenerated file containing SYS_ defines.
 */
#include <linux/unistd.h>
#include <bits/syscall_aliases.h>

#endif /* _SYS_SYSCALL_H */
