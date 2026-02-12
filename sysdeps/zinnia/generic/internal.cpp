#include <abi-bits/fcntl.h>
#include <abi-bits/pid_t.h>
#include <errno.h>
#include <mlibc/internal-sysdeps.hpp>
#include <mlibc/tcb.hpp>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <syslog.h>

#include <zinnia/archctl.h>
#include <zinnia/system.h>
#include <zinnia/thread.h>

namespace mlibc {

void sys_libc_log(const char *message) {
	zn_log(message);
	zn_log("\n");
}

[[noreturn]] void sys_libc_panic() {
	sys_libc_log("mlibc panic!");
	zn_thread_exit();
	__builtin_unreachable();
}

int sys_tcb_set(void *pointer) {
#if defined(__x86_64__)
	return zn_archctl(ZN_ARCHCTL_SET_FSBASE, pointer);
#elif defined(__aarch64__)
	uintptr_t thread_data = reinterpret_cast<uintptr_t>(pointer) + sizeof(Tcb) - 0x10;
	asm volatile("msr tpidr_el0, %0" ::"r"(thread_data));
	return 0;
#elif defined(__riscv)
	uintptr_t thread_data = reinterpret_cast<uintptr_t>(pointer) + sizeof(Tcb);
	asm volatile("mv tp, %0" ::"r"(thread_data));
	return 0;
#elif defined(__loongarch64)
	uintptr_t thread_data = reinterpret_cast<uintptr_t>(pointer) + sizeof(Tcb);
	asm volatile("move $tp, %0" ::"r"(thread_data));
	return 0;
#else
#error "Unsupported architecture!"
#endif
}

int sys_futex_tid() { return 0; }

int sys_futex_wait(int *pointer, int expected, const struct timespec *time) { return ENOSYS; }

int sys_futex_wake(int *pointer, bool) { return ENOSYS; }

int sys_anon_allocate(size_t size, void **pointer) { return ENOSYS; }

int sys_anon_free(void *pointer, size_t size) { return ENOSYS; }

int sys_openat(int dirfd, const char *path, int flags, mode_t mode, int *fd) { return ENOSYS; }

int sys_open(const char *pathname, int flags, mode_t mode, int *fd) { return ENOSYS; }

int sys_read(int fd, void *buf, size_t count, ssize_t *bytes_read) { return ENOSYS; }

int sys_seek(int fd, off_t offset, int whence, off_t *new_offset) { return ENOSYS; }

int sys_close(int fd) { return ENOSYS; }

int sys_stat(fsfd_target fsfdt, int fd, const char *path, int flags, struct stat *statbuf) {
	return ENOSYS;
}

int sys_vm_map(void *hint, size_t size, int prot, int flags, int fd, off_t offset, void **window) {
	return ENOSYS;
}

int sys_vm_unmap(void *pointer, size_t size) { return ENOSYS; }

int sys_vm_protect(void *pointer, size_t size, int prot) { return ENOSYS; }

} // namespace mlibc
