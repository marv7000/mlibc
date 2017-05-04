#ifndef _SYS_RESOURCE_H
#define _SYS_RESOURCE_H

#include <mlibc/id_t.h>
#include <mlibc/suseconds_t.h>
#include <mlibc/time_t.h>
#include <mlibc/timeval.h>

#define PRIO_PROCESS 1
#define PRIO_PGRP 2
#define PRIO_USER 3

#define RLIM_INFINITY ((rlim_t)-1)
#define RLIM_SAVED_MAX ((rlim_t)-1)
#define RLIM_SAVED_CUR ((rlim_t)-1)

#define RUSAGE_SELF 1
#define RUSAGE_CHILDREN 2

#define RLIMIT_CORE 1
#define RLIMIT_CPU 2
#define RLIMIT_DATA 3
#define RLIMIT_FSIZE 4
#define RLIMIT_NOFILE 5
#define RLIMIT_STACK 6
#define RLIMIT_AS 7

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned long rlim_t;

struct rlimit {
	rlim_t rlim_cur;
	rlim_t rlim_max;
};

struct rusage {
	struct timeval ru_utime;
	struct timeval ru_stime;
};

int getpriority(int, id_t);
int getrlimit(int, struct rlimit *);
int getrusage(int, struct rusage *);
int setpriority(int, id_t, int);
int setrlimit(int, const struct rlimit *);

#ifdef __cplusplus
}
#endif

#endif // _SYS_RESOURCE_H
