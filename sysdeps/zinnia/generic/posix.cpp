#include <abi-bits/limits.h>
#include <abi-bits/pid_t.h>
#include <errno.h>
#include <frg/logging.hpp>
#include <mlibc/debug.hpp>
#include <mlibc/posix-sysdeps.hpp>
#include <mlibc/tcb.hpp>
#include <net/if.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>

#include <zinnia/log.h>

namespace mlibc {

[[noreturn]] void sys_exit(int status) {
	// TODO
	zn_panic(ZN_ERR_UNSUPPORTED);
	__builtin_trap();
}

int sys_write(int fd, const void *buf, size_t count, ssize_t *bytes_written) {
	zn_panic(ZN_ERR_UNSUPPORTED);
}

int sys_clock_get(int clock, time_t *secs, long *nanos) { zn_panic(ZN_ERR_UNSUPPORTED); }

} // namespace mlibc
