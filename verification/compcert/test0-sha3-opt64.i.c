typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;
typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;
typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;
typedef char __int8_t;
typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long long __int64_t;
typedef unsigned long long __uint64_t;
typedef long __darwin_intptr_t;
typedef unsigned int __darwin_natural_t;
typedef int __darwin_ct_rune_t;
typedef union {
  char __mbstate8[128];
  long long _mbstateL;
} __mbstate_t;
typedef __mbstate_t __darwin_mbstate_t;
typedef int __darwin_ptrdiff_t;
typedef long unsigned int __darwin_size_t;
typedef void* __darwin_va_list;
typedef int __darwin_wchar_t;
typedef __darwin_wchar_t __darwin_rune_t;
typedef int __darwin_wint_t;
typedef unsigned long __darwin_clock_t;
typedef __uint32_t __darwin_socklen_t;
typedef long __darwin_ssize_t;
typedef long __darwin_time_t;
struct __darwin_pthread_handler_rec {
  void (*__routine)(void*);
  void* __arg;
  struct __darwin_pthread_handler_rec* __next;
};
struct _opaque_pthread_attr_t {
  long __sig;
  char __opaque[36];
};
struct _opaque_pthread_cond_t {
  long __sig;
  char __opaque[24];
};
struct _opaque_pthread_condattr_t {
  long __sig;
  char __opaque[4];
};
struct _opaque_pthread_mutex_t {
  long __sig;
  char __opaque[40];
};
struct _opaque_pthread_mutexattr_t {
  long __sig;
  char __opaque[8];
};
struct _opaque_pthread_once_t {
  long __sig;
  char __opaque[4];
};
struct _opaque_pthread_rwlock_t {
  long __sig;
  char __opaque[124];
};
struct _opaque_pthread_rwlockattr_t {
  long __sig;
  char __opaque[12];
};
struct _opaque_pthread_t {
  long __sig;
  struct __darwin_pthread_handler_rec* __cleanup_stack;
  char __opaque[596];
};
typedef __int64_t __darwin_blkcnt_t;
typedef __int32_t __darwin_blksize_t;
typedef __int32_t __darwin_dev_t;
typedef unsigned int __darwin_fsblkcnt_t;
typedef unsigned int __darwin_fsfilcnt_t;
typedef __uint32_t __darwin_gid_t;
typedef __uint32_t __darwin_id_t;
typedef __uint64_t __darwin_ino64_t;
typedef __darwin_ino64_t __darwin_ino_t;
typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t __darwin_mode_t;
typedef __int64_t __darwin_off_t;
typedef __int32_t __darwin_pid_t;
typedef struct _opaque_pthread_attr_t __darwin_pthread_attr_t;
typedef struct _opaque_pthread_cond_t __darwin_pthread_cond_t;
typedef struct _opaque_pthread_condattr_t __darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;
typedef struct _opaque_pthread_mutex_t __darwin_pthread_mutex_t;
typedef struct _opaque_pthread_mutexattr_t __darwin_pthread_mutexattr_t;
typedef struct _opaque_pthread_once_t __darwin_pthread_once_t;
typedef struct _opaque_pthread_rwlock_t __darwin_pthread_rwlock_t;
typedef struct _opaque_pthread_rwlockattr_t __darwin_pthread_rwlockattr_t;
typedef struct _opaque_pthread_t* __darwin_pthread_t;
typedef __uint32_t __darwin_sigset_t;
typedef __int32_t __darwin_suseconds_t;
typedef __uint32_t __darwin_uid_t;
typedef __uint32_t __darwin_useconds_t;
typedef unsigned char __darwin_uuid_t[16];
typedef char __darwin_uuid_string_t[37];
typedef __darwin_intptr_t intptr_t;
typedef unsigned long uintptr_t;
typedef long long int intmax_t;
typedef long long unsigned int uintmax_t;
typedef int __darwin_nl_item;
typedef int __darwin_wctrans_t;
typedef unsigned long __darwin_wctype_t;
typedef enum { P_ALL, P_PID, P_PGID } idtype_t;
typedef __darwin_pid_t pid_t;
typedef __darwin_id_t id_t;
typedef int sig_atomic_t;
struct __darwin_i386_thread_state {
  unsigned int __eax;
  unsigned int __ebx;
  unsigned int __ecx;
  unsigned int __edx;
  unsigned int __edi;
  unsigned int __esi;
  unsigned int __ebp;
  unsigned int __esp;
  unsigned int __ss;
  unsigned int __eflags;
  unsigned int __eip;
  unsigned int __cs;
  unsigned int __ds;
  unsigned int __es;
  unsigned int __fs;
  unsigned int __gs;
};
struct __darwin_fp_control {
  unsigned short __invalid : 1, __denorm : 1, __zdiv : 1, __ovrfl : 1, __undfl : 1,
      __precis : 1, : 2, __pc : 2, __rc : 2, : 1, : 3;
};
typedef struct __darwin_fp_control __darwin_fp_control_t;
struct __darwin_fp_status {
  unsigned short __invalid : 1, __denorm : 1, __zdiv : 1, __ovrfl : 1, __undfl : 1,
      __precis : 1, __stkflt : 1, __errsumm : 1, __c0 : 1, __c1 : 1, __c2 : 1, __tos : 3,
      __c3 : 1, __busy : 1;
};
typedef struct __darwin_fp_status __darwin_fp_status_t;
struct __darwin_mmst_reg {
  char __mmst_reg[10];
  char __mmst_rsrv[6];
};
struct __darwin_xmm_reg {
  char __xmm_reg[16];
};
struct __darwin_i386_float_state {
  int __fpu_reserved[2];
  struct __darwin_fp_control __fpu_fcw;
  struct __darwin_fp_status __fpu_fsw;
  __uint8_t __fpu_ftw;
  __uint8_t __fpu_rsrv1;
  __uint16_t __fpu_fop;
  __uint32_t __fpu_ip;
  __uint16_t __fpu_cs;
  __uint16_t __fpu_rsrv2;
  __uint32_t __fpu_dp;
  __uint16_t __fpu_ds;
  __uint16_t __fpu_rsrv3;
  __uint32_t __fpu_mxcsr;
  __uint32_t __fpu_mxcsrmask;
  struct __darwin_mmst_reg __fpu_stmm0;
  struct __darwin_mmst_reg __fpu_stmm1;
  struct __darwin_mmst_reg __fpu_stmm2;
  struct __darwin_mmst_reg __fpu_stmm3;
  struct __darwin_mmst_reg __fpu_stmm4;
  struct __darwin_mmst_reg __fpu_stmm5;
  struct __darwin_mmst_reg __fpu_stmm6;
  struct __darwin_mmst_reg __fpu_stmm7;
  struct __darwin_xmm_reg __fpu_xmm0;
  struct __darwin_xmm_reg __fpu_xmm1;
  struct __darwin_xmm_reg __fpu_xmm2;
  struct __darwin_xmm_reg __fpu_xmm3;
  struct __darwin_xmm_reg __fpu_xmm4;
  struct __darwin_xmm_reg __fpu_xmm5;
  struct __darwin_xmm_reg __fpu_xmm6;
  struct __darwin_xmm_reg __fpu_xmm7;
  char __fpu_rsrv4[14 * 16];
  int __fpu_reserved1;
};
struct __darwin_i386_avx_state {
  int __fpu_reserved[2];
  struct __darwin_fp_control __fpu_fcw;
  struct __darwin_fp_status __fpu_fsw;
  __uint8_t __fpu_ftw;
  __uint8_t __fpu_rsrv1;
  __uint16_t __fpu_fop;
  __uint32_t __fpu_ip;
  __uint16_t __fpu_cs;
  __uint16_t __fpu_rsrv2;
  __uint32_t __fpu_dp;
  __uint16_t __fpu_ds;
  __uint16_t __fpu_rsrv3;
  __uint32_t __fpu_mxcsr;
  __uint32_t __fpu_mxcsrmask;
  struct __darwin_mmst_reg __fpu_stmm0;
  struct __darwin_mmst_reg __fpu_stmm1;
  struct __darwin_mmst_reg __fpu_stmm2;
  struct __darwin_mmst_reg __fpu_stmm3;
  struct __darwin_mmst_reg __fpu_stmm4;
  struct __darwin_mmst_reg __fpu_stmm5;
  struct __darwin_mmst_reg __fpu_stmm6;
  struct __darwin_mmst_reg __fpu_stmm7;
  struct __darwin_xmm_reg __fpu_xmm0;
  struct __darwin_xmm_reg __fpu_xmm1;
  struct __darwin_xmm_reg __fpu_xmm2;
  struct __darwin_xmm_reg __fpu_xmm3;
  struct __darwin_xmm_reg __fpu_xmm4;
  struct __darwin_xmm_reg __fpu_xmm5;
  struct __darwin_xmm_reg __fpu_xmm6;
  struct __darwin_xmm_reg __fpu_xmm7;
  char __fpu_rsrv4[14 * 16];
  int __fpu_reserved1;
  char __avx_reserved1[64];
  struct __darwin_xmm_reg __fpu_ymmh0;
  struct __darwin_xmm_reg __fpu_ymmh1;
  struct __darwin_xmm_reg __fpu_ymmh2;
  struct __darwin_xmm_reg __fpu_ymmh3;
  struct __darwin_xmm_reg __fpu_ymmh4;
  struct __darwin_xmm_reg __fpu_ymmh5;
  struct __darwin_xmm_reg __fpu_ymmh6;
  struct __darwin_xmm_reg __fpu_ymmh7;
};
struct __darwin_i386_exception_state {
  __uint16_t __trapno;
  __uint16_t __cpu;
  __uint32_t __err;
  __uint32_t __faultvaddr;
};
struct __darwin_x86_debug_state32 {
  unsigned int __dr0;
  unsigned int __dr1;
  unsigned int __dr2;
  unsigned int __dr3;
  unsigned int __dr4;
  unsigned int __dr5;
  unsigned int __dr6;
  unsigned int __dr7;
};
struct __darwin_x86_thread_state64 {
  __uint64_t __rax;
  __uint64_t __rbx;
  __uint64_t __rcx;
  __uint64_t __rdx;
  __uint64_t __rdi;
  __uint64_t __rsi;
  __uint64_t __rbp;
  __uint64_t __rsp;
  __uint64_t __r8;
  __uint64_t __r9;
  __uint64_t __r10;
  __uint64_t __r11;
  __uint64_t __r12;
  __uint64_t __r13;
  __uint64_t __r14;
  __uint64_t __r15;
  __uint64_t __rip;
  __uint64_t __rflags;
  __uint64_t __cs;
  __uint64_t __fs;
  __uint64_t __gs;
};
struct __darwin_x86_float_state64 {
  int __fpu_reserved[2];
  struct __darwin_fp_control __fpu_fcw;
  struct __darwin_fp_status __fpu_fsw;
  __uint8_t __fpu_ftw;
  __uint8_t __fpu_rsrv1;
  __uint16_t __fpu_fop;
  __uint32_t __fpu_ip;
  __uint16_t __fpu_cs;
  __uint16_t __fpu_rsrv2;
  __uint32_t __fpu_dp;
  __uint16_t __fpu_ds;
  __uint16_t __fpu_rsrv3;
  __uint32_t __fpu_mxcsr;
  __uint32_t __fpu_mxcsrmask;
  struct __darwin_mmst_reg __fpu_stmm0;
  struct __darwin_mmst_reg __fpu_stmm1;
  struct __darwin_mmst_reg __fpu_stmm2;
  struct __darwin_mmst_reg __fpu_stmm3;
  struct __darwin_mmst_reg __fpu_stmm4;
  struct __darwin_mmst_reg __fpu_stmm5;
  struct __darwin_mmst_reg __fpu_stmm6;
  struct __darwin_mmst_reg __fpu_stmm7;
  struct __darwin_xmm_reg __fpu_xmm0;
  struct __darwin_xmm_reg __fpu_xmm1;
  struct __darwin_xmm_reg __fpu_xmm2;
  struct __darwin_xmm_reg __fpu_xmm3;
  struct __darwin_xmm_reg __fpu_xmm4;
  struct __darwin_xmm_reg __fpu_xmm5;
  struct __darwin_xmm_reg __fpu_xmm6;
  struct __darwin_xmm_reg __fpu_xmm7;
  struct __darwin_xmm_reg __fpu_xmm8;
  struct __darwin_xmm_reg __fpu_xmm9;
  struct __darwin_xmm_reg __fpu_xmm10;
  struct __darwin_xmm_reg __fpu_xmm11;
  struct __darwin_xmm_reg __fpu_xmm12;
  struct __darwin_xmm_reg __fpu_xmm13;
  struct __darwin_xmm_reg __fpu_xmm14;
  struct __darwin_xmm_reg __fpu_xmm15;
  char __fpu_rsrv4[6 * 16];
  int __fpu_reserved1;
};
struct __darwin_x86_avx_state64 {
  int __fpu_reserved[2];
  struct __darwin_fp_control __fpu_fcw;
  struct __darwin_fp_status __fpu_fsw;
  __uint8_t __fpu_ftw;
  __uint8_t __fpu_rsrv1;
  __uint16_t __fpu_fop;
  __uint32_t __fpu_ip;
  __uint16_t __fpu_cs;
  __uint16_t __fpu_rsrv2;
  __uint32_t __fpu_dp;
  __uint16_t __fpu_ds;
  __uint16_t __fpu_rsrv3;
  __uint32_t __fpu_mxcsr;
  __uint32_t __fpu_mxcsrmask;
  struct __darwin_mmst_reg __fpu_stmm0;
  struct __darwin_mmst_reg __fpu_stmm1;
  struct __darwin_mmst_reg __fpu_stmm2;
  struct __darwin_mmst_reg __fpu_stmm3;
  struct __darwin_mmst_reg __fpu_stmm4;
  struct __darwin_mmst_reg __fpu_stmm5;
  struct __darwin_mmst_reg __fpu_stmm6;
  struct __darwin_mmst_reg __fpu_stmm7;
  struct __darwin_xmm_reg __fpu_xmm0;
  struct __darwin_xmm_reg __fpu_xmm1;
  struct __darwin_xmm_reg __fpu_xmm2;
  struct __darwin_xmm_reg __fpu_xmm3;
  struct __darwin_xmm_reg __fpu_xmm4;
  struct __darwin_xmm_reg __fpu_xmm5;
  struct __darwin_xmm_reg __fpu_xmm6;
  struct __darwin_xmm_reg __fpu_xmm7;
  struct __darwin_xmm_reg __fpu_xmm8;
  struct __darwin_xmm_reg __fpu_xmm9;
  struct __darwin_xmm_reg __fpu_xmm10;
  struct __darwin_xmm_reg __fpu_xmm11;
  struct __darwin_xmm_reg __fpu_xmm12;
  struct __darwin_xmm_reg __fpu_xmm13;
  struct __darwin_xmm_reg __fpu_xmm14;
  struct __darwin_xmm_reg __fpu_xmm15;
  char __fpu_rsrv4[6 * 16];
  int __fpu_reserved1;
  char __avx_reserved1[64];
  struct __darwin_xmm_reg __fpu_ymmh0;
  struct __darwin_xmm_reg __fpu_ymmh1;
  struct __darwin_xmm_reg __fpu_ymmh2;
  struct __darwin_xmm_reg __fpu_ymmh3;
  struct __darwin_xmm_reg __fpu_ymmh4;
  struct __darwin_xmm_reg __fpu_ymmh5;
  struct __darwin_xmm_reg __fpu_ymmh6;
  struct __darwin_xmm_reg __fpu_ymmh7;
  struct __darwin_xmm_reg __fpu_ymmh8;
  struct __darwin_xmm_reg __fpu_ymmh9;
  struct __darwin_xmm_reg __fpu_ymmh10;
  struct __darwin_xmm_reg __fpu_ymmh11;
  struct __darwin_xmm_reg __fpu_ymmh12;
  struct __darwin_xmm_reg __fpu_ymmh13;
  struct __darwin_xmm_reg __fpu_ymmh14;
  struct __darwin_xmm_reg __fpu_ymmh15;
};
struct __darwin_x86_exception_state64 {
  __uint16_t __trapno;
  __uint16_t __cpu;
  __uint32_t __err;
  __uint64_t __faultvaddr;
};
struct __darwin_x86_debug_state64 {
  __uint64_t __dr0;
  __uint64_t __dr1;
  __uint64_t __dr2;
  __uint64_t __dr3;
  __uint64_t __dr4;
  __uint64_t __dr5;
  __uint64_t __dr6;
  __uint64_t __dr7;
};
struct __darwin_mcontext32 {
  struct __darwin_i386_exception_state __es;
  struct __darwin_i386_thread_state __ss;
  struct __darwin_i386_float_state __fs;
};
struct __darwin_mcontext_avx32 {
  struct __darwin_i386_exception_state __es;
  struct __darwin_i386_thread_state __ss;
  struct __darwin_i386_avx_state __fs;
};
struct __darwin_mcontext64 {
  struct __darwin_x86_exception_state64 __es;
  struct __darwin_x86_thread_state64 __ss;
  struct __darwin_x86_float_state64 __fs;
};
struct __darwin_mcontext_avx64 {
  struct __darwin_x86_exception_state64 __es;
  struct __darwin_x86_thread_state64 __ss;
  struct __darwin_x86_avx_state64 __fs;
};
typedef struct __darwin_mcontext32* mcontext_t;
struct __darwin_sigaltstack {
  void* ss_sp;
  __darwin_size_t ss_size;
  int ss_flags;
};
typedef struct __darwin_sigaltstack stack_t;
struct __darwin_ucontext {
  int uc_onstack;
  __darwin_sigset_t uc_sigmask;
  struct __darwin_sigaltstack uc_stack;
  struct __darwin_ucontext* uc_link;
  __darwin_size_t uc_mcsize;
  struct __darwin_mcontext32* uc_mcontext;
};
typedef struct __darwin_ucontext ucontext_t;
typedef __darwin_pthread_attr_t pthread_attr_t;
typedef __darwin_sigset_t sigset_t;
typedef __darwin_size_t size_t;
typedef __darwin_uid_t uid_t;
union sigval {
  int sival_int;
  void* sival_ptr;
};
struct sigevent {
  int sigev_notify;
  int sigev_signo;
  union sigval sigev_value;
  void (*sigev_notify_function)(union sigval);
  pthread_attr_t* sigev_notify_attributes;
};
typedef struct __siginfo {
  int si_signo;
  int si_errno;
  int si_code;
  pid_t si_pid;
  uid_t si_uid;
  int si_status;
  void* si_addr;
  union sigval si_value;
  long si_band;
  unsigned long __pad[7];
} siginfo_t;
union __sigaction_u {
  void (*__sa_handler)(int);
  void (*__sa_sigaction)(int, struct __siginfo*, void*);
};
struct __sigaction {
  union __sigaction_u __sigaction_u;
  void (*sa_tramp)(void*, int, int, siginfo_t*, void*);
  sigset_t sa_mask;
  int sa_flags;
};
struct sigaction {
  union __sigaction_u __sigaction_u;
  sigset_t sa_mask;
  int sa_flags;
};
typedef void (*sig_t)(int);
struct sigvec {
  void (*sv_handler)(int);
  int sv_mask;
  int sv_flags;
};
struct sigstack {
  char* ss_sp;
  int ss_onstack;
};

void (*signal(int, void (*)(int)))(int);

struct timeval {
  __darwin_time_t tv_sec;
  __darwin_suseconds_t tv_usec;
};
typedef __uint64_t rlim_t;
struct rusage {
  struct timeval ru_utime;
  struct timeval ru_stime;
  long ru_maxrss;
  long ru_ixrss;
  long ru_idrss;
  long ru_isrss;
  long ru_minflt;
  long ru_majflt;
  long ru_nswap;
  long ru_inblock;
  long ru_oublock;
  long ru_msgsnd;
  long ru_msgrcv;
  long ru_nsignals;
  long ru_nvcsw;
  long ru_nivcsw;
};
typedef void* rusage_info_t;
struct rusage_info_v0 {
  uint8_t ri_uuid[16];
  uint64_t ri_user_time;
  uint64_t ri_system_time;
  uint64_t ri_pkg_idle_wkups;
  uint64_t ri_interrupt_wkups;
  uint64_t ri_pageins;
  uint64_t ri_wired_size;
  uint64_t ri_resident_size;
  uint64_t ri_phys_footprint;
  uint64_t ri_proc_start_abstime;
  uint64_t ri_proc_exit_abstime;
};
struct rusage_info_v1 {
  uint8_t ri_uuid[16];
  uint64_t ri_user_time;
  uint64_t ri_system_time;
  uint64_t ri_pkg_idle_wkups;
  uint64_t ri_interrupt_wkups;
  uint64_t ri_pageins;
  uint64_t ri_wired_size;
  uint64_t ri_resident_size;
  uint64_t ri_phys_footprint;
  uint64_t ri_proc_start_abstime;
  uint64_t ri_proc_exit_abstime;
  uint64_t ri_child_user_time;
  uint64_t ri_child_system_time;
  uint64_t ri_child_pkg_idle_wkups;
  uint64_t ri_child_interrupt_wkups;
  uint64_t ri_child_pageins;
  uint64_t ri_child_elapsed_abstime;
};
struct rusage_info_v2 {
  uint8_t ri_uuid[16];
  uint64_t ri_user_time;
  uint64_t ri_system_time;
  uint64_t ri_pkg_idle_wkups;
  uint64_t ri_interrupt_wkups;
  uint64_t ri_pageins;
  uint64_t ri_wired_size;
  uint64_t ri_resident_size;
  uint64_t ri_phys_footprint;
  uint64_t ri_proc_start_abstime;
  uint64_t ri_proc_exit_abstime;
  uint64_t ri_child_user_time;
  uint64_t ri_child_system_time;
  uint64_t ri_child_pkg_idle_wkups;
  uint64_t ri_child_interrupt_wkups;
  uint64_t ri_child_pageins;
  uint64_t ri_child_elapsed_abstime;
  uint64_t ri_diskio_bytesread;
  uint64_t ri_diskio_byteswritten;
};
struct rlimit {
  rlim_t rlim_cur;
  rlim_t rlim_max;
};
struct proc_rlimit_control_wakeupmon {
  uint32_t wm_flags;
  int32_t wm_rate;
};

int getpriority(int, id_t);
int getiopolicy_np(int, int);
int getrlimit(int, struct rlimit*) __asm(
    "_"
    "getrlimit"
    "$UNIX2003");
int getrusage(int, struct rusage*);
int setpriority(int, id_t, int);
int setiopolicy_np(int, int, int);
int setrlimit(int, const struct rlimit*) __asm(
    "_"
    "setrlimit"
    "$UNIX2003");

static inline uint16_t _OSSwapInt16(uint16_t data) {
  return ((__uint16_t)((((__uint16_t)(data)&0xff00) >> 8) |
                       (((__uint16_t)(data)&0x00ff) << 8)));
}
static inline uint32_t _OSSwapInt32(uint32_t data) {
  return ((__uint32_t)(
      (((__uint32_t)(data)&0xff000000) >> 24) | (((__uint32_t)(data)&0x00ff0000) >> 8) |
      (((__uint32_t)(data)&0x0000ff00) << 8) | (((__uint32_t)(data)&0x000000ff) << 24)));
}
static inline uint64_t _OSSwapInt64(uint64_t data) {
  return ((__uint64_t)((((__uint64_t)(data)&0xff00000000000000ULL) >> 56) |
                       (((__uint64_t)(data)&0x00ff000000000000ULL) >> 40) |
                       (((__uint64_t)(data)&0x0000ff0000000000ULL) >> 24) |
                       (((__uint64_t)(data)&0x000000ff00000000ULL) >> 8) |
                       (((__uint64_t)(data)&0x00000000ff000000ULL) << 8) |
                       (((__uint64_t)(data)&0x0000000000ff0000ULL) << 24) |
                       (((__uint64_t)(data)&0x000000000000ff00ULL) << 40) |
                       (((__uint64_t)(data)&0x00000000000000ffULL) << 56)));
}
union wait {
  int w_status;
  struct {
    unsigned int w_Termsig : 7, w_Coredump : 1, w_Retcode : 8, w_Filler : 16;
  } w_T;
  struct {
    unsigned int w_Stopval : 8, w_Stopsig : 8, w_Filler : 16;
  } w_S;
};

pid_t wait(int*) __asm(
    "_"
    "wait"
    "$UNIX2003");
pid_t waitpid(pid_t, int*, int) __asm(
    "_"
    "waitpid"
    "$UNIX2003");
int waitid(idtype_t, id_t, siginfo_t*, int) __asm(
    "_"
    "waitid"
    "$UNIX2003");
pid_t wait3(int*, int, struct rusage*);
pid_t wait4(pid_t, int*, int, struct rusage*);

void* alloca(size_t);

typedef __darwin_ct_rune_t ct_rune_t;
typedef __darwin_rune_t rune_t;
typedef __darwin_wchar_t wchar_t;
typedef struct {
  int quot;
  int rem;
} div_t;
typedef struct {
  long quot;
  long rem;
} ldiv_t;
typedef struct {
  long long quot;
  long long rem;
} lldiv_t;
extern int __mb_cur_max;

void abort(void);
int abs(int);
int atexit(void (*)(void));
double atof(const char*);
int atoi(const char*);
long atol(const char*);
long long atoll(const char*);
void* bsearch(const void*,
              const void*,
              size_t,
              size_t,
              int (*)(const void*, const void*));
void* calloc(size_t, size_t);
div_t div(int, int);
void exit(int);
void free(void*);
char* getenv(const char*);
long labs(long);
ldiv_t ldiv(long, long);
long long llabs(long long);
lldiv_t lldiv(long long, long long);
void* malloc(size_t);
int mblen(const char*, size_t);
size_t mbstowcs(wchar_t*, const char*, size_t);
int mbtowc(wchar_t*, const char*, size_t);
int posix_memalign(void**, size_t, size_t);
void qsort(void*, size_t, size_t, int (*)(const void*, const void*));
int rand(void);
void* realloc(void*, size_t);
void srand(unsigned);
double strtod(const char*, char**) __asm(
    "_"
    "strtod"
    "$UNIX2003");
float strtof(const char*, char**) __asm(
    "_"
    "strtof"
    "$UNIX2003");
long strtol(const char*, char**, int);
long double strtold(const char*, char**);
long long strtoll(const char*, char**, int);
unsigned long strtoul(const char*, char**, int);
unsigned long long strtoull(const char*, char**, int);
int system(const char*) __asm(
    "_"
    "system"
    "$UNIX2003");
size_t wcstombs(char*, const wchar_t*, size_t);
int wctomb(char*, wchar_t);
void _Exit(int);
long a64l(const char*);
double drand48(void);
char* ecvt(double, int, int*, int*);
double erand48(unsigned short[3]);
char* fcvt(double, int, int*, int*);
char* gcvt(double, int, char*);
int getsubopt(char**, char* const*, char**);
int grantpt(int);
char* initstate(unsigned, char*, size_t);
long jrand48(unsigned short[3]);
char* l64a(long);
void lcong48(unsigned short[7]);
long lrand48(void);
char* mktemp(char*);
int mkstemp(char*);
long mrand48(void);
long nrand48(unsigned short[3]);
int posix_openpt(int);
char* ptsname(int);
int putenv(char*) __asm(
    "_"
    "putenv"
    "$UNIX2003");
long random(void);
int rand_r(unsigned*);
char* realpath(const char*, char*) __asm(
    "_"
    "realpath"
    "$DARWIN_EXTSN");
unsigned short* seed48(unsigned short[3]);
int setenv(const char*, const char*, int) __asm(
    "_"
    "setenv"
    "$UNIX2003");
void setkey(const char*) __asm(
    "_"
    "setkey"
    "$UNIX2003");
char* setstate(const char*);
void srand48(long);
void srandom(unsigned);
int unlockpt(int);
int unsetenv(const char*) __asm(
    "_"
    "unsetenv"
    "$UNIX2003");
typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long u_int64_t;
typedef int32_t register_t;
typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;
typedef u_int64_t syscall_arg_t;
typedef __darwin_dev_t dev_t;
typedef __darwin_mode_t mode_t;
u_int32_t arc4random(void);
void arc4random_addrandom(unsigned char*, int);
void arc4random_buf(void*, size_t);
void arc4random_stir(void);
u_int32_t arc4random_uniform(u_int32_t);
char* cgetcap(char*, const char*, int);
int cgetclose(void);
int cgetent(char**, char**, const char*);
int cgetfirst(char**, char**);
int cgetmatch(const char*, const char*);
int cgetnext(char**, char**);
int cgetnum(char*, const char*, long*);
int cgetset(const char*);
int cgetstr(char*, const char*, char**);
int cgetustr(char*, const char*, char**);
int daemon(int, int) __asm(
    "_"
    "daemon"
    "$1050");
char* devname(dev_t, mode_t);
char* devname_r(dev_t, mode_t, char* buf, int len);
char* getbsize(int*, long*);
int getloadavg(double[], int);
const char* getprogname(void);
int heapsort(void*, size_t, size_t, int (*)(const void*, const void*));
int mergesort(void*, size_t, size_t, int (*)(const void*, const void*));
void psort(void*, size_t, size_t, int (*)(const void*, const void*));
void psort_r(void*, size_t, size_t, void*, int (*)(void*, const void*, const void*));
void qsort_r(void*, size_t, size_t, void*, int (*)(void*, const void*, const void*));
int radixsort(const unsigned char**, int, const unsigned char*, unsigned);
void setprogname(const char*);
int sradixsort(const unsigned char**, int, const unsigned char*, unsigned);
void sranddev(void);
void srandomdev(void);
void* reallocf(void*, size_t);
long long strtoq(const char*, char**, int);
unsigned long long strtouq(const char*, char**, int);
extern char* suboptarg;
void* valloc(size_t);

void* memset(void* dest, int val, size_t len) {
  uint8_t* bytes = dest;
  for (size_t i = 0; i < len; i++) {
    bytes[i] = (uint8_t)val;
  }
  return ((void*)0);
}
void* memcpy(void* dest, const void* src, size_t len) {
  for (size_t i = 0; i < len; i++) {
    ((uint8_t*)dest)[i] = ((uint8_t*)src)[i];
  }
  return ((void*)0);
}
int memcmp(const void* in1, const void* in2, size_t len) {
  for (size_t i = 0; i < len; i++) {
    uint8_t c1 = ((uint8_t*)in1)[i];
    uint8_t c2 = ((uint8_t*)in2)[i];
    if (c1 != c2) {
      return -1;
    }
  }
  return 0;
}
typedef int ptrdiff_t;
static const char* err_ptrnull = "NULL passed as pointer";
static const int errno_ptrnull = -1;
static const char* err_rsize = "size > RSIZE_MAX";
static const int errno_rsize = -2;
static const char* err_sponge_invariant = "sponge invariant violated";
static const int errno_sponge_invariant = -3;
static const char* err_digestlen =
    "SHA3 fixed-output-length functions must be called with outlen == digestlen";
static const int errno_digestlen = -4;
static const char* err_sha3 = "error encountered in sha3 fixed-output-length function";
static const int errno_sha3 = -5;
static const char* err_hash_flags = "hash flags wrong";
static const int errno_hash_flags = -6;
static const char* err_hash_finalized = "hash already finalized";
static const int errno_hash_finalized = -7;
static const char* err_hash_not_finalized = "hash not finalized";
static const int errno_hash_not_finalized = -8;
typedef __darwin_va_list va_list;
typedef __darwin_off_t fpos_t;
struct __sbuf {
  unsigned char* _base;
  int _size;
};
struct __sFILEX;
typedef struct __sFILE {
  unsigned char* _p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;
  void* _cookie;
  int (*_close)(void*);
  int (*_read)(void*, char*, int);
  fpos_t (*_seek)(void*, fpos_t, int);
  int (*_write)(void*, const char*, int);
  struct __sbuf _ub;
  struct __sFILEX* _extra;
  int _ur;
  unsigned char _ubuf[3];
  unsigned char _nbuf[1];
  struct __sbuf _lb;
  int _blksize;
  fpos_t _offset;
} FILE;

extern FILE* __stdinp;
extern FILE* __stdoutp;
extern FILE* __stderrp;

void clearerr(FILE*);
int fclose(FILE*);
int feof(FILE*);
int ferror(FILE*);
int fflush(FILE*);
int fgetc(FILE*);
int fgetpos(FILE*, fpos_t*);
char* fgets(char*, int, FILE*);
FILE* fopen(const char*, const char*) __asm(
    "_"
    "fopen"
    "$UNIX2003");
int fprintf(FILE*, const char*, ...);
int fputc(int, FILE*);
int fputs(const char*, FILE*) __asm(
    "_"
    "fputs"
    "$UNIX2003");
size_t fread(void*, size_t, size_t, FILE*);
FILE* freopen(const char*, const char*, FILE*) __asm(
    "_"
    "freopen"
    "$UNIX2003");
int fscanf(FILE*, const char*, ...);
int fseek(FILE*, long, int);
int fsetpos(FILE*, const fpos_t*);
long ftell(FILE*);
size_t fwrite(const void*, size_t, size_t, FILE*) __asm(
    "_"
    "fwrite"
    "$UNIX2003");
int getc(FILE*);
int getchar(void);
char* gets(char*);
void perror(const char*);
int printf(const char*, ...);
int putc(int, FILE*);
int putchar(int);
int puts(const char*);
int remove(const char*);
int rename(const char*, const char*);
void rewind(FILE*);
int scanf(const char*, ...);
void setbuf(FILE*, char*);
int setvbuf(FILE*, char*, int, size_t);
int sprintf(char*, const char*, ...);
int sscanf(const char*, const char*, ...);
FILE* tmpfile(void);

char* tmpnam(char*);
int ungetc(int, FILE*);
int vfprintf(FILE*, const char*, va_list);
int vprintf(const char*, va_list);
int vsprintf(char*, const char*, va_list);

char* ctermid(char*);
FILE* fdopen(int, const char*) __asm(
    "_"
    "fdopen"
    "$UNIX2003");
int fileno(FILE*);

int pclose(FILE*);
FILE* popen(const char*, const char*) __asm(
    "_"
    "popen"
    "$UNIX2003");

int __srget(FILE*);
int __svfscanf(FILE*, const char*, va_list);
int __swbuf(int, FILE*);

void flockfile(FILE*);
int ftrylockfile(FILE*);
void funlockfile(FILE*);
int getc_unlocked(FILE*);
int getchar_unlocked(void);
int putc_unlocked(int, FILE*);
int putchar_unlocked(int);
int getw(FILE*);
int putw(int, FILE*);

char* tempnam(const char*, const char*) __asm(
    "_"
    "tempnam"
    "$UNIX2003");

typedef __darwin_off_t off_t;

int fseeko(FILE*, off_t, int);
off_t ftello(FILE*);

int snprintf(char*, size_t, const char*, ...);
int vfscanf(FILE*, const char*, va_list);
int vscanf(const char*, va_list);
int vsnprintf(char*, size_t, const char*, va_list);
int vsscanf(const char*, const char*, va_list);

typedef __darwin_ssize_t ssize_t;

int dprintf(int, const char*, ...);
int vdprintf(int, const char*, va_list);
ssize_t getdelim(char**, size_t*, int, FILE*);
ssize_t getline(char**, size_t*, FILE*);

extern const int sys_nerr;
extern const char* const sys_errlist[];
int asprintf(char**, const char*, ...);
char* ctermid_r(char*);
char* fgetln(FILE*, size_t*);
const char* fmtcheck(const char*, const char*);
int fpurge(FILE*);
void setbuffer(FILE*, char*, int);
int setlinebuf(FILE*);
int vasprintf(char**, const char*, va_list);
FILE* zopen(const char*, const char*, int);
FILE* funopen(const void*,
              int (*)(void*, char*, int),
              int (*)(void*, const char*, int),
              fpos_t (*)(void*, fpos_t, int),
              int (*)(void*));

void* memchr(const void*, int, size_t);
int memcmp(const void*, const void*, size_t);
void* memcpy(void*, const void*, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);
char* strcat(char*, const char*);
char* strchr(const char*, int);
int strcmp(const char*, const char*);
int strcoll(const char*, const char*);
char* strcpy(char*, const char*);
size_t strcspn(const char*, const char*);
char* strerror(int) __asm(
    "_"
    "strerror"
    "$UNIX2003");
size_t strlen(const char*);
char* strncat(char*, const char*, size_t);
int strncmp(const char*, const char*, size_t);
char* strncpy(char*, const char*, size_t);
char* strpbrk(const char*, const char*);
char* strrchr(const char*, int);
size_t strspn(const char*, const char*);
char* strstr(const char*, const char*);
char* strtok(char*, const char*);
size_t strxfrm(char*, const char*, size_t);

char* strtok_r(char*, const char*, char**);

int strerror_r(int, char*, size_t);
char* strdup(const char*);
void* memccpy(void*, const void*, int, size_t);

char* stpcpy(char*, const char*);
char* stpncpy(char*, const char*, size_t);
char* strndup(const char*, size_t);
size_t strnlen(const char*, size_t);
char* strsignal(int sig);

typedef __darwin_size_t rsize_t;
typedef int errno_t;

errno_t memset_s(void*, rsize_t, int, rsize_t);

void* memmem(const void*, size_t, const void*, size_t);
void memset_pattern4(void*, const void*, size_t);
void memset_pattern8(void*, const void*, size_t);
void memset_pattern16(void*, const void*, size_t);
char* strcasestr(const char*, const char*);
char* strnstr(const char*, const char*, size_t);
size_t strlcat(char*, const char*, size_t);
size_t strlcpy(char*, const char*, size_t);
void strmode(int, char*);
char* strsep(char**, const char*);
void swab(const void*, void*, ssize_t);

int bcmp(const void*, const void*, size_t);
void bcopy(const void*, void*, size_t);
void bzero(void*, size_t);
char* index(const char*, int);
char* rindex(const char*, int);
int ffs(int);
int strcasecmp(const char*, const char*);
int strncasecmp(const char*, const char*, size_t);

int ffsl(long);
int ffsll(long long);
int fls(int);
int flsl(long);
int flsll(long long);

typedef struct sponge {
  uint64_t a[25];
  uint64_t padding[7];
  uint64_t absorbed;
  uint64_t squeezed;
  uint64_t rate;
  uint64_t flags;
} keccak_sponge;
static const size_t sponge_bytelen = 200;
int keccak_sponge_init(register keccak_sponge* const restrict sponge,
                       register const size_t rate);
int keccak_sponge_checkinv(register const keccak_sponge* const sponge);
int keccak_sponge_absorb(register keccak_sponge* const restrict sponge,
                         register const uint8_t* const restrict in,
                         register const size_t inlen);
int keccak_sponge_squeeze(register keccak_sponge* const restrict sponge,
                          register uint8_t* const restrict out,
                          register const size_t outlen);
static inline int _sponge_init(register keccak_sponge* const restrict sponge,
                               register const size_t rate) {
  if (sponge == ((void*)0)) {
    return -2;
  }
  if ((rate >= 200) || (rate == 0)) {
    return -1;
  }
  sponge->rate = rate;
  sponge->absorbed = 0;
  sponge->squeezed = 0;
  sponge->flags = 0;
  for (size_t i = 0; i < 25; i++) {
    sponge->a[i] = 0;
  }
  return 0;
}
static inline int _sponge_checkinv(register const keccak_sponge* const sponge) {
  register int ret = 0;
  if (sponge == ((void*)0)) {
    return -2;
  }
  if ((sponge->absorbed != 0) && (sponge->squeezed != 0)) {
    goto err;
  }
  if ((sponge->rate > 199) || (sponge->rate < 1)) {
    goto err;
  }
  if (sponge->absorbed >= sponge->rate) {
    goto err;
  }
  if (sponge->squeezed >= sponge->rate) {
    goto err;
  }
  goto okay;
err:
  ret = -1;
okay:
  return ret;
}
void keccakf(register void* const state);
void _keccakf_aligned(uint64_t* state);
static const uint64_t round_constants[24] = {0x0000000000000001ULL,
                                             0x0000000000008082ULL,
                                             0x800000000000808aULL,
                                             0x8000000080008000ULL,
                                             0x000000000000808bULL,
                                             0x0000000080000001ULL,
                                             0x8000000080008081ULL,
                                             0x8000000000008009ULL,
                                             0x000000000000008aULL,
                                             0x0000000000000088ULL,
                                             0x0000000080008009ULL,
                                             0x000000008000000aULL,
                                             0x000000008000808bULL,
                                             0x800000000000008bULL,
                                             0x8000000000008089ULL,
                                             0x8000000000008003ULL,
                                             0x8000000000008002ULL,
                                             0x8000000000000080ULL,
                                             0x000000000000800aULL,
                                             0x800000008000000aULL,
                                             0x8000000080008081ULL,
                                             0x8000000000008080ULL,
                                             0x0000000080000001ULL,
                                             0x8000000080008008ULL};
static inline int _xorinto(uint8_t* const restrict dest,
                           const uint8_t* const restrict in,
                           const size_t oplen) {
  switch (oplen) {
    case 168:
      dest[0] ^= in[0];
      dest[1] ^= in[1];
      dest[2] ^= in[2];
      dest[3] ^= in[3];
      dest[4] ^= in[4];
      dest[5] ^= in[5];
      dest[6] ^= in[6];
      dest[7] ^= in[7];
      dest[8] ^= in[8];
      dest[9] ^= in[9];
      dest[10] ^= in[10];
      dest[11] ^= in[11];
      dest[12] ^= in[12];
      dest[13] ^= in[13];
      dest[14] ^= in[14];
      dest[15] ^= in[15];
      dest[16] ^= in[16];
      dest[17] ^= in[17];
      dest[18] ^= in[18];
      dest[19] ^= in[19];
      dest[20] ^= in[20];
      dest[21] ^= in[21];
      dest[22] ^= in[22];
      dest[23] ^= in[23];
      dest[24] ^= in[24];
      dest[25] ^= in[25];
      dest[26] ^= in[26];
      dest[27] ^= in[27];
      dest[28] ^= in[28];
      dest[29] ^= in[29];
      dest[30] ^= in[30];
      dest[31] ^= in[31];
      dest[32] ^= in[32];
      dest[33] ^= in[33];
      dest[34] ^= in[34];
      dest[35] ^= in[35];
      dest[36] ^= in[36];
      dest[37] ^= in[37];
      dest[38] ^= in[38];
      dest[39] ^= in[39];
      dest[40] ^= in[40];
      dest[41] ^= in[41];
      dest[42] ^= in[42];
      dest[43] ^= in[43];
      dest[44] ^= in[44];
      dest[45] ^= in[45];
      dest[46] ^= in[46];
      dest[47] ^= in[47];
      dest[48] ^= in[48];
      dest[49] ^= in[49];
      dest[50] ^= in[50];
      dest[51] ^= in[51];
      dest[52] ^= in[52];
      dest[53] ^= in[53];
      dest[54] ^= in[54];
      dest[55] ^= in[55];
      dest[56] ^= in[56];
      dest[57] ^= in[57];
      dest[58] ^= in[58];
      dest[59] ^= in[59];
      dest[60] ^= in[60];
      dest[61] ^= in[61];
      dest[62] ^= in[62];
      dest[63] ^= in[63];
      dest[64] ^= in[64];
      dest[65] ^= in[65];
      dest[66] ^= in[66];
      dest[67] ^= in[67];
      dest[68] ^= in[68];
      dest[69] ^= in[69];
      dest[70] ^= in[70];
      dest[71] ^= in[71];
      dest[72] ^= in[72];
      dest[73] ^= in[73];
      dest[74] ^= in[74];
      dest[75] ^= in[75];
      dest[76] ^= in[76];
      dest[77] ^= in[77];
      dest[78] ^= in[78];
      dest[79] ^= in[79];
      dest[80] ^= in[80];
      dest[81] ^= in[81];
      dest[82] ^= in[82];
      dest[83] ^= in[83];
      dest[84] ^= in[84];
      dest[85] ^= in[85];
      dest[86] ^= in[86];
      dest[87] ^= in[87];
      dest[88] ^= in[88];
      dest[89] ^= in[89];
      dest[90] ^= in[90];
      dest[91] ^= in[91];
      dest[92] ^= in[92];
      dest[93] ^= in[93];
      dest[94] ^= in[94];
      dest[95] ^= in[95];
      dest[96] ^= in[96];
      dest[97] ^= in[97];
      dest[98] ^= in[98];
      dest[99] ^= in[99];
      dest[100] ^= in[100];
      dest[101] ^= in[101];
      dest[102] ^= in[102];
      dest[103] ^= in[103];
      dest[104] ^= in[104];
      dest[105] ^= in[105];
      dest[106] ^= in[106];
      dest[107] ^= in[107];
      dest[108] ^= in[108];
      dest[109] ^= in[109];
      dest[110] ^= in[110];
      dest[111] ^= in[111];
      dest[112] ^= in[112];
      dest[113] ^= in[113];
      dest[114] ^= in[114];
      dest[115] ^= in[115];
      dest[116] ^= in[116];
      dest[117] ^= in[117];
      dest[118] ^= in[118];
      dest[119] ^= in[119];
      dest[120] ^= in[120];
      dest[121] ^= in[121];
      dest[122] ^= in[122];
      dest[123] ^= in[123];
      dest[124] ^= in[124];
      dest[125] ^= in[125];
      dest[126] ^= in[126];
      dest[127] ^= in[127];
      dest[128] ^= in[128];
      dest[129] ^= in[129];
      dest[130] ^= in[130];
      dest[131] ^= in[131];
      dest[132] ^= in[132];
      dest[133] ^= in[133];
      dest[134] ^= in[134];
      dest[135] ^= in[135];
      dest[136] ^= in[136];
      dest[137] ^= in[137];
      dest[138] ^= in[138];
      dest[139] ^= in[139];
      dest[140] ^= in[140];
      dest[141] ^= in[141];
      dest[142] ^= in[142];
      dest[143] ^= in[143];
      dest[144] ^= in[144];
      dest[145] ^= in[145];
      dest[146] ^= in[146];
      dest[147] ^= in[147];
      dest[148] ^= in[148];
      dest[149] ^= in[149];
      dest[150] ^= in[150];
      dest[151] ^= in[151];
      dest[152] ^= in[152];
      dest[153] ^= in[153];
      dest[154] ^= in[154];
      dest[155] ^= in[155];
      dest[156] ^= in[156];
      dest[157] ^= in[157];
      dest[158] ^= in[158];
      dest[159] ^= in[159];
      dest[160] ^= in[160];
      dest[161] ^= in[161];
      dest[162] ^= in[162];
      dest[163] ^= in[163];
      dest[164] ^= in[164];
      dest[165] ^= in[165];
      dest[166] ^= in[166];
      dest[167] ^= in[167];
      break;
    case 144:
      dest[0] ^= in[0];
      dest[1] ^= in[1];
      dest[2] ^= in[2];
      dest[3] ^= in[3];
      dest[4] ^= in[4];
      dest[5] ^= in[5];
      dest[6] ^= in[6];
      dest[7] ^= in[7];
      dest[8] ^= in[8];
      dest[9] ^= in[9];
      dest[10] ^= in[10];
      dest[11] ^= in[11];
      dest[12] ^= in[12];
      dest[13] ^= in[13];
      dest[14] ^= in[14];
      dest[15] ^= in[15];
      dest[16] ^= in[16];
      dest[17] ^= in[17];
      dest[18] ^= in[18];
      dest[19] ^= in[19];
      dest[20] ^= in[20];
      dest[21] ^= in[21];
      dest[22] ^= in[22];
      dest[23] ^= in[23];
      dest[24] ^= in[24];
      dest[25] ^= in[25];
      dest[26] ^= in[26];
      dest[27] ^= in[27];
      dest[28] ^= in[28];
      dest[29] ^= in[29];
      dest[30] ^= in[30];
      dest[31] ^= in[31];
      dest[32] ^= in[32];
      dest[33] ^= in[33];
      dest[34] ^= in[34];
      dest[35] ^= in[35];
      dest[36] ^= in[36];
      dest[37] ^= in[37];
      dest[38] ^= in[38];
      dest[39] ^= in[39];
      dest[40] ^= in[40];
      dest[41] ^= in[41];
      dest[42] ^= in[42];
      dest[43] ^= in[43];
      dest[44] ^= in[44];
      dest[45] ^= in[45];
      dest[46] ^= in[46];
      dest[47] ^= in[47];
      dest[48] ^= in[48];
      dest[49] ^= in[49];
      dest[50] ^= in[50];
      dest[51] ^= in[51];
      dest[52] ^= in[52];
      dest[53] ^= in[53];
      dest[54] ^= in[54];
      dest[55] ^= in[55];
      dest[56] ^= in[56];
      dest[57] ^= in[57];
      dest[58] ^= in[58];
      dest[59] ^= in[59];
      dest[60] ^= in[60];
      dest[61] ^= in[61];
      dest[62] ^= in[62];
      dest[63] ^= in[63];
      dest[64] ^= in[64];
      dest[65] ^= in[65];
      dest[66] ^= in[66];
      dest[67] ^= in[67];
      dest[68] ^= in[68];
      dest[69] ^= in[69];
      dest[70] ^= in[70];
      dest[71] ^= in[71];
      dest[72] ^= in[72];
      dest[73] ^= in[73];
      dest[74] ^= in[74];
      dest[75] ^= in[75];
      dest[76] ^= in[76];
      dest[77] ^= in[77];
      dest[78] ^= in[78];
      dest[79] ^= in[79];
      dest[80] ^= in[80];
      dest[81] ^= in[81];
      dest[82] ^= in[82];
      dest[83] ^= in[83];
      dest[84] ^= in[84];
      dest[85] ^= in[85];
      dest[86] ^= in[86];
      dest[87] ^= in[87];
      dest[88] ^= in[88];
      dest[89] ^= in[89];
      dest[90] ^= in[90];
      dest[91] ^= in[91];
      dest[92] ^= in[92];
      dest[93] ^= in[93];
      dest[94] ^= in[94];
      dest[95] ^= in[95];
      dest[96] ^= in[96];
      dest[97] ^= in[97];
      dest[98] ^= in[98];
      dest[99] ^= in[99];
      dest[100] ^= in[100];
      dest[101] ^= in[101];
      dest[102] ^= in[102];
      dest[103] ^= in[103];
      dest[104] ^= in[104];
      dest[105] ^= in[105];
      dest[106] ^= in[106];
      dest[107] ^= in[107];
      dest[108] ^= in[108];
      dest[109] ^= in[109];
      dest[110] ^= in[110];
      dest[111] ^= in[111];
      dest[112] ^= in[112];
      dest[113] ^= in[113];
      dest[114] ^= in[114];
      dest[115] ^= in[115];
      dest[116] ^= in[116];
      dest[117] ^= in[117];
      dest[118] ^= in[118];
      dest[119] ^= in[119];
      dest[120] ^= in[120];
      dest[121] ^= in[121];
      dest[122] ^= in[122];
      dest[123] ^= in[123];
      dest[124] ^= in[124];
      dest[125] ^= in[125];
      dest[126] ^= in[126];
      dest[127] ^= in[127];
      dest[128] ^= in[128];
      dest[129] ^= in[129];
      dest[130] ^= in[130];
      dest[131] ^= in[131];
      dest[132] ^= in[132];
      dest[133] ^= in[133];
      dest[134] ^= in[134];
      dest[135] ^= in[135];
      dest[136] ^= in[136];
      dest[137] ^= in[137];
      dest[138] ^= in[138];
      dest[139] ^= in[139];
      dest[140] ^= in[140];
      dest[141] ^= in[141];
      dest[142] ^= in[142];
      dest[143] ^= in[143];
      break;
    case 136:
      dest[0] ^= in[0];
      dest[1] ^= in[1];
      dest[2] ^= in[2];
      dest[3] ^= in[3];
      dest[4] ^= in[4];
      dest[5] ^= in[5];
      dest[6] ^= in[6];
      dest[7] ^= in[7];
      dest[8] ^= in[8];
      dest[9] ^= in[9];
      dest[10] ^= in[10];
      dest[11] ^= in[11];
      dest[12] ^= in[12];
      dest[13] ^= in[13];
      dest[14] ^= in[14];
      dest[15] ^= in[15];
      dest[16] ^= in[16];
      dest[17] ^= in[17];
      dest[18] ^= in[18];
      dest[19] ^= in[19];
      dest[20] ^= in[20];
      dest[21] ^= in[21];
      dest[22] ^= in[22];
      dest[23] ^= in[23];
      dest[24] ^= in[24];
      dest[25] ^= in[25];
      dest[26] ^= in[26];
      dest[27] ^= in[27];
      dest[28] ^= in[28];
      dest[29] ^= in[29];
      dest[30] ^= in[30];
      dest[31] ^= in[31];
      dest[32] ^= in[32];
      dest[33] ^= in[33];
      dest[34] ^= in[34];
      dest[35] ^= in[35];
      dest[36] ^= in[36];
      dest[37] ^= in[37];
      dest[38] ^= in[38];
      dest[39] ^= in[39];
      dest[40] ^= in[40];
      dest[41] ^= in[41];
      dest[42] ^= in[42];
      dest[43] ^= in[43];
      dest[44] ^= in[44];
      dest[45] ^= in[45];
      dest[46] ^= in[46];
      dest[47] ^= in[47];
      dest[48] ^= in[48];
      dest[49] ^= in[49];
      dest[50] ^= in[50];
      dest[51] ^= in[51];
      dest[52] ^= in[52];
      dest[53] ^= in[53];
      dest[54] ^= in[54];
      dest[55] ^= in[55];
      dest[56] ^= in[56];
      dest[57] ^= in[57];
      dest[58] ^= in[58];
      dest[59] ^= in[59];
      dest[60] ^= in[60];
      dest[61] ^= in[61];
      dest[62] ^= in[62];
      dest[63] ^= in[63];
      dest[64] ^= in[64];
      dest[65] ^= in[65];
      dest[66] ^= in[66];
      dest[67] ^= in[67];
      dest[68] ^= in[68];
      dest[69] ^= in[69];
      dest[70] ^= in[70];
      dest[71] ^= in[71];
      dest[72] ^= in[72];
      dest[73] ^= in[73];
      dest[74] ^= in[74];
      dest[75] ^= in[75];
      dest[76] ^= in[76];
      dest[77] ^= in[77];
      dest[78] ^= in[78];
      dest[79] ^= in[79];
      dest[80] ^= in[80];
      dest[81] ^= in[81];
      dest[82] ^= in[82];
      dest[83] ^= in[83];
      dest[84] ^= in[84];
      dest[85] ^= in[85];
      dest[86] ^= in[86];
      dest[87] ^= in[87];
      dest[88] ^= in[88];
      dest[89] ^= in[89];
      dest[90] ^= in[90];
      dest[91] ^= in[91];
      dest[92] ^= in[92];
      dest[93] ^= in[93];
      dest[94] ^= in[94];
      dest[95] ^= in[95];
      dest[96] ^= in[96];
      dest[97] ^= in[97];
      dest[98] ^= in[98];
      dest[99] ^= in[99];
      dest[100] ^= in[100];
      dest[101] ^= in[101];
      dest[102] ^= in[102];
      dest[103] ^= in[103];
      dest[104] ^= in[104];
      dest[105] ^= in[105];
      dest[106] ^= in[106];
      dest[107] ^= in[107];
      dest[108] ^= in[108];
      dest[109] ^= in[109];
      dest[110] ^= in[110];
      dest[111] ^= in[111];
      dest[112] ^= in[112];
      dest[113] ^= in[113];
      dest[114] ^= in[114];
      dest[115] ^= in[115];
      dest[116] ^= in[116];
      dest[117] ^= in[117];
      dest[118] ^= in[118];
      dest[119] ^= in[119];
      dest[120] ^= in[120];
      dest[121] ^= in[121];
      dest[122] ^= in[122];
      dest[123] ^= in[123];
      dest[124] ^= in[124];
      dest[125] ^= in[125];
      dest[126] ^= in[126];
      dest[127] ^= in[127];
      dest[128] ^= in[128];
      dest[129] ^= in[129];
      dest[130] ^= in[130];
      dest[131] ^= in[131];
      dest[132] ^= in[132];
      dest[133] ^= in[133];
      dest[134] ^= in[134];
      dest[135] ^= in[135];
      break;
    case 104:
      dest[0] ^= in[0];
      dest[1] ^= in[1];
      dest[2] ^= in[2];
      dest[3] ^= in[3];
      dest[4] ^= in[4];
      dest[5] ^= in[5];
      dest[6] ^= in[6];
      dest[7] ^= in[7];
      dest[8] ^= in[8];
      dest[9] ^= in[9];
      dest[10] ^= in[10];
      dest[11] ^= in[11];
      dest[12] ^= in[12];
      dest[13] ^= in[13];
      dest[14] ^= in[14];
      dest[15] ^= in[15];
      dest[16] ^= in[16];
      dest[17] ^= in[17];
      dest[18] ^= in[18];
      dest[19] ^= in[19];
      dest[20] ^= in[20];
      dest[21] ^= in[21];
      dest[22] ^= in[22];
      dest[23] ^= in[23];
      dest[24] ^= in[24];
      dest[25] ^= in[25];
      dest[26] ^= in[26];
      dest[27] ^= in[27];
      dest[28] ^= in[28];
      dest[29] ^= in[29];
      dest[30] ^= in[30];
      dest[31] ^= in[31];
      dest[32] ^= in[32];
      dest[33] ^= in[33];
      dest[34] ^= in[34];
      dest[35] ^= in[35];
      dest[36] ^= in[36];
      dest[37] ^= in[37];
      dest[38] ^= in[38];
      dest[39] ^= in[39];
      dest[40] ^= in[40];
      dest[41] ^= in[41];
      dest[42] ^= in[42];
      dest[43] ^= in[43];
      dest[44] ^= in[44];
      dest[45] ^= in[45];
      dest[46] ^= in[46];
      dest[47] ^= in[47];
      dest[48] ^= in[48];
      dest[49] ^= in[49];
      dest[50] ^= in[50];
      dest[51] ^= in[51];
      dest[52] ^= in[52];
      dest[53] ^= in[53];
      dest[54] ^= in[54];
      dest[55] ^= in[55];
      dest[56] ^= in[56];
      dest[57] ^= in[57];
      dest[58] ^= in[58];
      dest[59] ^= in[59];
      dest[60] ^= in[60];
      dest[61] ^= in[61];
      dest[62] ^= in[62];
      dest[63] ^= in[63];
      dest[64] ^= in[64];
      dest[65] ^= in[65];
      dest[66] ^= in[66];
      dest[67] ^= in[67];
      dest[68] ^= in[68];
      dest[69] ^= in[69];
      dest[70] ^= in[70];
      dest[71] ^= in[71];
      dest[72] ^= in[72];
      dest[73] ^= in[73];
      dest[74] ^= in[74];
      dest[75] ^= in[75];
      dest[76] ^= in[76];
      dest[77] ^= in[77];
      dest[78] ^= in[78];
      dest[79] ^= in[79];
      dest[80] ^= in[80];
      dest[81] ^= in[81];
      dest[82] ^= in[82];
      dest[83] ^= in[83];
      dest[84] ^= in[84];
      dest[85] ^= in[85];
      dest[86] ^= in[86];
      dest[87] ^= in[87];
      dest[88] ^= in[88];
      dest[89] ^= in[89];
      dest[90] ^= in[90];
      dest[91] ^= in[91];
      dest[92] ^= in[92];
      dest[93] ^= in[93];
      dest[94] ^= in[94];
      dest[95] ^= in[95];
      dest[96] ^= in[96];
      dest[97] ^= in[97];
      dest[98] ^= in[98];
      dest[99] ^= in[99];
      dest[100] ^= in[100];
      dest[101] ^= in[101];
      dest[102] ^= in[102];
      dest[103] ^= in[103];
      break;
    case 72:
      dest[0] ^= in[0];
      dest[1] ^= in[1];
      dest[2] ^= in[2];
      dest[3] ^= in[3];
      dest[4] ^= in[4];
      dest[5] ^= in[5];
      dest[6] ^= in[6];
      dest[7] ^= in[7];
      dest[8] ^= in[8];
      dest[9] ^= in[9];
      dest[10] ^= in[10];
      dest[11] ^= in[11];
      dest[12] ^= in[12];
      dest[13] ^= in[13];
      dest[14] ^= in[14];
      dest[15] ^= in[15];
      dest[16] ^= in[16];
      dest[17] ^= in[17];
      dest[18] ^= in[18];
      dest[19] ^= in[19];
      dest[20] ^= in[20];
      dest[21] ^= in[21];
      dest[22] ^= in[22];
      dest[23] ^= in[23];
      dest[24] ^= in[24];
      dest[25] ^= in[25];
      dest[26] ^= in[26];
      dest[27] ^= in[27];
      dest[28] ^= in[28];
      dest[29] ^= in[29];
      dest[30] ^= in[30];
      dest[31] ^= in[31];
      dest[32] ^= in[32];
      dest[33] ^= in[33];
      dest[34] ^= in[34];
      dest[35] ^= in[35];
      dest[36] ^= in[36];
      dest[37] ^= in[37];
      dest[38] ^= in[38];
      dest[39] ^= in[39];
      dest[40] ^= in[40];
      dest[41] ^= in[41];
      dest[42] ^= in[42];
      dest[43] ^= in[43];
      dest[44] ^= in[44];
      dest[45] ^= in[45];
      dest[46] ^= in[46];
      dest[47] ^= in[47];
      dest[48] ^= in[48];
      dest[49] ^= in[49];
      dest[50] ^= in[50];
      dest[51] ^= in[51];
      dest[52] ^= in[52];
      dest[53] ^= in[53];
      dest[54] ^= in[54];
      dest[55] ^= in[55];
      dest[56] ^= in[56];
      dest[57] ^= in[57];
      dest[58] ^= in[58];
      dest[59] ^= in[59];
      dest[60] ^= in[60];
      dest[61] ^= in[61];
      dest[62] ^= in[62];
      dest[63] ^= in[63];
      dest[64] ^= in[64];
      dest[65] ^= in[65];
      dest[66] ^= in[66];
      dest[67] ^= in[67];
      dest[68] ^= in[68];
      dest[69] ^= in[69];
      dest[70] ^= in[70];
      dest[71] ^= in[71];
      break;
    default:
      for (size_t i = 0; i < oplen; i++) {
        dest[i] = dest[i] ^ in[i];
      }
  }
  return 0;
}
static inline size_t _sponge_absorb_once(register keccak_sponge* const restrict sponge,
                                         register const uint8_t* const restrict in,
                                         register const size_t inlen) {
  register size_t canabsorb = sponge->rate - sponge->absorbed;
  register uint8_t* state = ((uint8_t*)sponge->a) + sponge->absorbed;
  if (canabsorb > inlen) {
    _xorinto(state, in, inlen);
    sponge->absorbed += inlen;
    return inlen;
  } else {
    _xorinto(state, in, canabsorb);
    keccakf(sponge->a);
    sponge->absorbed = 0;
    return canabsorb;
  }
}
static inline size_t _sponge_squeeze_once(register keccak_sponge* const restrict sponge,
                                          register uint8_t* const restrict out,
                                          register const size_t outlen) {
  register size_t cansqueeze = sponge->rate - sponge->squeezed;
  register uint8_t* state = ((uint8_t*)sponge->a) + sponge->squeezed;
  register size_t squeezed;
  if (cansqueeze > outlen) {
    memcpy(out,
           state,
           (((((outlen < 200) ? outlen : 200) < outlen) ? ((outlen < 200) ? outlen : 200)
                                                        : outlen)));
    sponge->squeezed += outlen;
    squeezed = outlen;
  } else {
    memcpy(
        out,
        state,
        (((((outlen < 200) ? outlen : 200) < cansqueeze) ? ((outlen < 200) ? outlen : 200)
                                                         : cansqueeze)));
    keccakf(sponge->a);
    sponge->squeezed = 0;
    squeezed = cansqueeze;
  }
  return squeezed;
}
static inline int _sponge_squeeze(register keccak_sponge* const restrict sponge,
                                  register uint8_t* const restrict out,
                                  register const size_t outlen) {
  register size_t remaining = outlen;
  register size_t outpos = 0;
  while (remaining) {
    register size_t squeezed = _sponge_squeeze_once(sponge, &out[outpos], remaining);
    remaining -= squeezed;
    outpos += squeezed;
  }
  return (int)remaining;
}
static inline int _sponge_absorb(register keccak_sponge* const restrict sponge,
                                 register const uint8_t* const restrict in,
                                 register const size_t inlen) {
  register size_t remaining = inlen;
  register size_t inpos = 0;
  while (remaining) {
    register size_t absorbed = _sponge_absorb_once(sponge, &in[inpos], remaining);
    remaining -= absorbed;
    inpos += absorbed;
  }
  return (int)remaining;
}
int keccak_sponge_init(register keccak_sponge* const restrict sponge,
                       register const size_t rate) {
  return _sponge_init(sponge, rate);
}
int keccak_sponge_checkinv(register const keccak_sponge* const sponge) {
  return _sponge_checkinv(sponge);
}
int keccak_sponge_absorb(register keccak_sponge* const restrict sponge,
                         register const uint8_t* const restrict in,
                         register const size_t inlen) {
  if ((in == ((void*)0)) || (inlen > (4294967295UL >> 1))) {
    do {
      fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 99, err_rsize);
      return errno_rsize;
    } while (0);
  }
  do {
    int err = _sponge_checkinv(sponge);
    if (err != 0) {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 101, err_sponge_invariant);
        return errno_sponge_invariant;
      } while (0);
    }
  } while (0);
  if (sponge->squeezed != 0) {
    keccakf(sponge->a);
    sponge->squeezed = 0;
  }
  return _sponge_absorb(sponge, in, inlen);
}
int keccak_sponge_squeeze(register keccak_sponge* const restrict sponge,
                          register uint8_t* const restrict out,
                          register const size_t outlen) {
  if ((out == ((void*)0)) || (outlen > (4294967295UL >> 1))) {
    do {
      fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 114, err_rsize);
      return errno_rsize;
    } while (0);
  }
  do {
    int err = _sponge_checkinv(sponge);
    if (err != 0) {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 116, err_sponge_invariant);
        return errno_sponge_invariant;
      } while (0);
    }
  } while (0);
  if (sponge->absorbed != 0) {
    keccakf(sponge->a);
    sponge->absorbed = 0;
  }
  return _sponge_squeeze(sponge, out, outlen);
}
extern void memclear(void* const, const size_t);
extern uint64_t tsc(void);
extern uint64_t tscp(void);
extern uint64_t tscm(void);
void keccakf(register void* const istate) {
  uint64_t state[25];
  memcpy(state, istate, 200);
  _keccakf_aligned((uint64_t*)state);
  memcpy(istate, state, 200);
  memclear(state, 200);
}
void _keccakf_aligned(uint64_t* state) {
  uint64_t Aba, Abe, Abi, Abo, Abu;
  uint64_t Aga, Age, Agi, Ago, Agu;
  uint64_t Aka, Ake, Aki, Ako, Aku;
  uint64_t Ama, Ame, Ami, Amo, Amu;
  uint64_t Asa, Ase, Asi, Aso, Asu;
  uint64_t Bba, Bbe, Bbi, Bbo, Bbu;
  uint64_t Bga, Bge, Bgi, Bgo, Bgu;
  uint64_t Bka, Bke, Bki, Bko, Bku;
  uint64_t Bma, Bme, Bmi, Bmo, Bmu;
  uint64_t Bsa, Bse, Bsi, Bso, Bsu;
  uint64_t Ca, Ce, Ci, Co, Cu;
  uint64_t Da, De, Di, Do, Du;
  uint64_t Eba, Ebe, Ebi, Ebo, Ebu;
  uint64_t Ega, Ege, Egi, Ego, Egu;
  uint64_t Eka, Eke, Eki, Eko, Eku;
  uint64_t Ema, Eme, Emi, Emo, Emu;
  uint64_t Esa, Ese, Esi, Eso, Esu;
  Aba = state[0];
  Abe = state[1];
  Abi = state[2];
  Abo = state[3];
  Abu = state[4];
  Aga = state[5];
  Age = state[6];
  Agi = state[7];
  Ago = state[8];
  Agu = state[9];
  Aka = state[10];
  Ake = state[11];
  Aki = state[12];
  Ako = state[13];
  Aku = state[14];
  Ama = state[15];
  Ame = state[16];
  Ami = state[17];
  Amo = state[18];
  Amu = state[19];
  Asa = state[20];
  Ase = state[21];
  Asi = state[22];
  Aso = state[23];
  Asu = state[24];
  Ca = Aba ^ Aga ^ Aka ^ Ama ^ Asa;
  Ce = Abe ^ Age ^ Ake ^ Ame ^ Ase;
  Ci = Abi ^ Agi ^ Aki ^ Ami ^ Asi;
  Co = Abo ^ Ago ^ Ako ^ Amo ^ Aso;
  Cu = Abu ^ Agu ^ Aku ^ Amu ^ Asu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Aba ^= Da;
  Bba = Aba;
  Age ^= De;
  Bbe = ((((uint64_t)Age) << 44) ^ (((uint64_t)Age) >> (64 - 44)));
  Aki ^= Di;
  Bbi = ((((uint64_t)Aki) << 43) ^ (((uint64_t)Aki) >> (64 - 43)));
  Amo ^= Do;
  Bbo = ((((uint64_t)Amo) << 21) ^ (((uint64_t)Amo) >> (64 - 21)));
  Asu ^= Du;
  Bbu = ((((uint64_t)Asu) << 14) ^ (((uint64_t)Asu) >> (64 - 14)));
  Eba = Bba ^ ((~Bbe) & Bbi);
  Eba ^= round_constants[0];
  Ca = Eba;
  Ebe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Ebe;
  Ebi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Ebi;
  Ebo = Bbo ^ ((~Bbu) & Bba);
  Co = Ebo;
  Ebu = Bbu ^ ((~Bba) & Bbe);
  Cu = Ebu;
  Abo ^= Do;
  Bga = ((((uint64_t)Abo) << 28) ^ (((uint64_t)Abo) >> (64 - 28)));
  Agu ^= Du;
  Bge = ((((uint64_t)Agu) << 20) ^ (((uint64_t)Agu) >> (64 - 20)));
  Aka ^= Da;
  Bgi = ((((uint64_t)Aka) << 3) ^ (((uint64_t)Aka) >> (64 - 3)));
  Ame ^= De;
  Bgo = ((((uint64_t)Ame) << 45) ^ (((uint64_t)Ame) >> (64 - 45)));
  Asi ^= Di;
  Bgu = ((((uint64_t)Asi) << 61) ^ (((uint64_t)Asi) >> (64 - 61)));
  Ega = Bga ^ ((~Bge) & Bgi);
  Ca ^= Ega;
  Ege = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Ege;
  Egi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Egi;
  Ego = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ego;
  Egu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Egu;
  Abe ^= De;
  Bka = ((((uint64_t)Abe) << 1) ^ (((uint64_t)Abe) >> (64 - 1)));
  Agi ^= Di;
  Bke = ((((uint64_t)Agi) << 6) ^ (((uint64_t)Agi) >> (64 - 6)));
  Ako ^= Do;
  Bki = ((((uint64_t)Ako) << 25) ^ (((uint64_t)Ako) >> (64 - 25)));
  Amu ^= Du;
  Bko = ((((uint64_t)Amu) << 8) ^ (((uint64_t)Amu) >> (64 - 8)));
  Asa ^= Da;
  Bku = ((((uint64_t)Asa) << 18) ^ (((uint64_t)Asa) >> (64 - 18)));
  Eka = Bka ^ ((~Bke) & Bki);
  Ca ^= Eka;
  Eke = Bke ^ ((~Bki) & Bko);
  Ce ^= Eke;
  Eki = Bki ^ ((~Bko) & Bku);
  Ci ^= Eki;
  Eko = Bko ^ ((~Bku) & Bka);
  Co ^= Eko;
  Eku = Bku ^ ((~Bka) & Bke);
  Cu ^= Eku;
  Abu ^= Du;
  Bma = ((((uint64_t)Abu) << 27) ^ (((uint64_t)Abu) >> (64 - 27)));
  Aga ^= Da;
  Bme = ((((uint64_t)Aga) << 36) ^ (((uint64_t)Aga) >> (64 - 36)));
  Ake ^= De;
  Bmi = ((((uint64_t)Ake) << 10) ^ (((uint64_t)Ake) >> (64 - 10)));
  Ami ^= Di;
  Bmo = ((((uint64_t)Ami) << 15) ^ (((uint64_t)Ami) >> (64 - 15)));
  Aso ^= Do;
  Bmu = ((((uint64_t)Aso) << 56) ^ (((uint64_t)Aso) >> (64 - 56)));
  Ema = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ema;
  Eme = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Eme;
  Emi = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Emi;
  Emo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Emo;
  Emu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Emu;
  Abi ^= Di;
  Bsa = ((((uint64_t)Abi) << 62) ^ (((uint64_t)Abi) >> (64 - 62)));
  Ago ^= Do;
  Bse = ((((uint64_t)Ago) << 55) ^ (((uint64_t)Ago) >> (64 - 55)));
  Aku ^= Du;
  Bsi = ((((uint64_t)Aku) << 39) ^ (((uint64_t)Aku) >> (64 - 39)));
  Ama ^= Da;
  Bso = ((((uint64_t)Ama) << 41) ^ (((uint64_t)Ama) >> (64 - 41)));
  Ase ^= De;
  Bsu = ((((uint64_t)Ase) << 2) ^ (((uint64_t)Ase) >> (64 - 2)));
  Esa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Esa;
  Ese = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ese;
  Esi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Esi;
  Eso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Eso;
  Esu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Esu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Eba ^= Da;
  Bba = Eba;
  Ege ^= De;
  Bbe = ((((uint64_t)Ege) << 44) ^ (((uint64_t)Ege) >> (64 - 44)));
  Eki ^= Di;
  Bbi = ((((uint64_t)Eki) << 43) ^ (((uint64_t)Eki) >> (64 - 43)));
  Emo ^= Do;
  Bbo = ((((uint64_t)Emo) << 21) ^ (((uint64_t)Emo) >> (64 - 21)));
  Esu ^= Du;
  Bbu = ((((uint64_t)Esu) << 14) ^ (((uint64_t)Esu) >> (64 - 14)));
  Aba = Bba ^ ((~Bbe) & Bbi);
  Aba ^= round_constants[1];
  Ca = Aba;
  Abe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Abe;
  Abi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Abi;
  Abo = Bbo ^ ((~Bbu) & Bba);
  Co = Abo;
  Abu = Bbu ^ ((~Bba) & Bbe);
  Cu = Abu;
  Ebo ^= Do;
  Bga = ((((uint64_t)Ebo) << 28) ^ (((uint64_t)Ebo) >> (64 - 28)));
  Egu ^= Du;
  Bge = ((((uint64_t)Egu) << 20) ^ (((uint64_t)Egu) >> (64 - 20)));
  Eka ^= Da;
  Bgi = ((((uint64_t)Eka) << 3) ^ (((uint64_t)Eka) >> (64 - 3)));
  Eme ^= De;
  Bgo = ((((uint64_t)Eme) << 45) ^ (((uint64_t)Eme) >> (64 - 45)));
  Esi ^= Di;
  Bgu = ((((uint64_t)Esi) << 61) ^ (((uint64_t)Esi) >> (64 - 61)));
  Aga = Bga ^ ((~Bge) & Bgi);
  Ca ^= Aga;
  Age = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Age;
  Agi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Agi;
  Ago = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ago;
  Agu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Agu;
  Ebe ^= De;
  Bka = ((((uint64_t)Ebe) << 1) ^ (((uint64_t)Ebe) >> (64 - 1)));
  Egi ^= Di;
  Bke = ((((uint64_t)Egi) << 6) ^ (((uint64_t)Egi) >> (64 - 6)));
  Eko ^= Do;
  Bki = ((((uint64_t)Eko) << 25) ^ (((uint64_t)Eko) >> (64 - 25)));
  Emu ^= Du;
  Bko = ((((uint64_t)Emu) << 8) ^ (((uint64_t)Emu) >> (64 - 8)));
  Esa ^= Da;
  Bku = ((((uint64_t)Esa) << 18) ^ (((uint64_t)Esa) >> (64 - 18)));
  Aka = Bka ^ ((~Bke) & Bki);
  Ca ^= Aka;
  Ake = Bke ^ ((~Bki) & Bko);
  Ce ^= Ake;
  Aki = Bki ^ ((~Bko) & Bku);
  Ci ^= Aki;
  Ako = Bko ^ ((~Bku) & Bka);
  Co ^= Ako;
  Aku = Bku ^ ((~Bka) & Bke);
  Cu ^= Aku;
  Ebu ^= Du;
  Bma = ((((uint64_t)Ebu) << 27) ^ (((uint64_t)Ebu) >> (64 - 27)));
  Ega ^= Da;
  Bme = ((((uint64_t)Ega) << 36) ^ (((uint64_t)Ega) >> (64 - 36)));
  Eke ^= De;
  Bmi = ((((uint64_t)Eke) << 10) ^ (((uint64_t)Eke) >> (64 - 10)));
  Emi ^= Di;
  Bmo = ((((uint64_t)Emi) << 15) ^ (((uint64_t)Emi) >> (64 - 15)));
  Eso ^= Do;
  Bmu = ((((uint64_t)Eso) << 56) ^ (((uint64_t)Eso) >> (64 - 56)));
  Ama = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ama;
  Ame = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Ame;
  Ami = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Ami;
  Amo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Amo;
  Amu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Amu;
  Ebi ^= Di;
  Bsa = ((((uint64_t)Ebi) << 62) ^ (((uint64_t)Ebi) >> (64 - 62)));
  Ego ^= Do;
  Bse = ((((uint64_t)Ego) << 55) ^ (((uint64_t)Ego) >> (64 - 55)));
  Eku ^= Du;
  Bsi = ((((uint64_t)Eku) << 39) ^ (((uint64_t)Eku) >> (64 - 39)));
  Ema ^= Da;
  Bso = ((((uint64_t)Ema) << 41) ^ (((uint64_t)Ema) >> (64 - 41)));
  Ese ^= De;
  Bsu = ((((uint64_t)Ese) << 2) ^ (((uint64_t)Ese) >> (64 - 2)));
  Asa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Asa;
  Ase = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ase;
  Asi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Asi;
  Aso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Aso;
  Asu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Asu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Aba ^= Da;
  Bba = Aba;
  Age ^= De;
  Bbe = ((((uint64_t)Age) << 44) ^ (((uint64_t)Age) >> (64 - 44)));
  Aki ^= Di;
  Bbi = ((((uint64_t)Aki) << 43) ^ (((uint64_t)Aki) >> (64 - 43)));
  Amo ^= Do;
  Bbo = ((((uint64_t)Amo) << 21) ^ (((uint64_t)Amo) >> (64 - 21)));
  Asu ^= Du;
  Bbu = ((((uint64_t)Asu) << 14) ^ (((uint64_t)Asu) >> (64 - 14)));
  Eba = Bba ^ ((~Bbe) & Bbi);
  Eba ^= round_constants[2];
  Ca = Eba;
  Ebe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Ebe;
  Ebi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Ebi;
  Ebo = Bbo ^ ((~Bbu) & Bba);
  Co = Ebo;
  Ebu = Bbu ^ ((~Bba) & Bbe);
  Cu = Ebu;
  Abo ^= Do;
  Bga = ((((uint64_t)Abo) << 28) ^ (((uint64_t)Abo) >> (64 - 28)));
  Agu ^= Du;
  Bge = ((((uint64_t)Agu) << 20) ^ (((uint64_t)Agu) >> (64 - 20)));
  Aka ^= Da;
  Bgi = ((((uint64_t)Aka) << 3) ^ (((uint64_t)Aka) >> (64 - 3)));
  Ame ^= De;
  Bgo = ((((uint64_t)Ame) << 45) ^ (((uint64_t)Ame) >> (64 - 45)));
  Asi ^= Di;
  Bgu = ((((uint64_t)Asi) << 61) ^ (((uint64_t)Asi) >> (64 - 61)));
  Ega = Bga ^ ((~Bge) & Bgi);
  Ca ^= Ega;
  Ege = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Ege;
  Egi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Egi;
  Ego = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ego;
  Egu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Egu;
  Abe ^= De;
  Bka = ((((uint64_t)Abe) << 1) ^ (((uint64_t)Abe) >> (64 - 1)));
  Agi ^= Di;
  Bke = ((((uint64_t)Agi) << 6) ^ (((uint64_t)Agi) >> (64 - 6)));
  Ako ^= Do;
  Bki = ((((uint64_t)Ako) << 25) ^ (((uint64_t)Ako) >> (64 - 25)));
  Amu ^= Du;
  Bko = ((((uint64_t)Amu) << 8) ^ (((uint64_t)Amu) >> (64 - 8)));
  Asa ^= Da;
  Bku = ((((uint64_t)Asa) << 18) ^ (((uint64_t)Asa) >> (64 - 18)));
  Eka = Bka ^ ((~Bke) & Bki);
  Ca ^= Eka;
  Eke = Bke ^ ((~Bki) & Bko);
  Ce ^= Eke;
  Eki = Bki ^ ((~Bko) & Bku);
  Ci ^= Eki;
  Eko = Bko ^ ((~Bku) & Bka);
  Co ^= Eko;
  Eku = Bku ^ ((~Bka) & Bke);
  Cu ^= Eku;
  Abu ^= Du;
  Bma = ((((uint64_t)Abu) << 27) ^ (((uint64_t)Abu) >> (64 - 27)));
  Aga ^= Da;
  Bme = ((((uint64_t)Aga) << 36) ^ (((uint64_t)Aga) >> (64 - 36)));
  Ake ^= De;
  Bmi = ((((uint64_t)Ake) << 10) ^ (((uint64_t)Ake) >> (64 - 10)));
  Ami ^= Di;
  Bmo = ((((uint64_t)Ami) << 15) ^ (((uint64_t)Ami) >> (64 - 15)));
  Aso ^= Do;
  Bmu = ((((uint64_t)Aso) << 56) ^ (((uint64_t)Aso) >> (64 - 56)));
  Ema = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ema;
  Eme = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Eme;
  Emi = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Emi;
  Emo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Emo;
  Emu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Emu;
  Abi ^= Di;
  Bsa = ((((uint64_t)Abi) << 62) ^ (((uint64_t)Abi) >> (64 - 62)));
  Ago ^= Do;
  Bse = ((((uint64_t)Ago) << 55) ^ (((uint64_t)Ago) >> (64 - 55)));
  Aku ^= Du;
  Bsi = ((((uint64_t)Aku) << 39) ^ (((uint64_t)Aku) >> (64 - 39)));
  Ama ^= Da;
  Bso = ((((uint64_t)Ama) << 41) ^ (((uint64_t)Ama) >> (64 - 41)));
  Ase ^= De;
  Bsu = ((((uint64_t)Ase) << 2) ^ (((uint64_t)Ase) >> (64 - 2)));
  Esa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Esa;
  Ese = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ese;
  Esi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Esi;
  Eso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Eso;
  Esu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Esu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Eba ^= Da;
  Bba = Eba;
  Ege ^= De;
  Bbe = ((((uint64_t)Ege) << 44) ^ (((uint64_t)Ege) >> (64 - 44)));
  Eki ^= Di;
  Bbi = ((((uint64_t)Eki) << 43) ^ (((uint64_t)Eki) >> (64 - 43)));
  Emo ^= Do;
  Bbo = ((((uint64_t)Emo) << 21) ^ (((uint64_t)Emo) >> (64 - 21)));
  Esu ^= Du;
  Bbu = ((((uint64_t)Esu) << 14) ^ (((uint64_t)Esu) >> (64 - 14)));
  Aba = Bba ^ ((~Bbe) & Bbi);
  Aba ^= round_constants[3];
  Ca = Aba;
  Abe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Abe;
  Abi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Abi;
  Abo = Bbo ^ ((~Bbu) & Bba);
  Co = Abo;
  Abu = Bbu ^ ((~Bba) & Bbe);
  Cu = Abu;
  Ebo ^= Do;
  Bga = ((((uint64_t)Ebo) << 28) ^ (((uint64_t)Ebo) >> (64 - 28)));
  Egu ^= Du;
  Bge = ((((uint64_t)Egu) << 20) ^ (((uint64_t)Egu) >> (64 - 20)));
  Eka ^= Da;
  Bgi = ((((uint64_t)Eka) << 3) ^ (((uint64_t)Eka) >> (64 - 3)));
  Eme ^= De;
  Bgo = ((((uint64_t)Eme) << 45) ^ (((uint64_t)Eme) >> (64 - 45)));
  Esi ^= Di;
  Bgu = ((((uint64_t)Esi) << 61) ^ (((uint64_t)Esi) >> (64 - 61)));
  Aga = Bga ^ ((~Bge) & Bgi);
  Ca ^= Aga;
  Age = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Age;
  Agi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Agi;
  Ago = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ago;
  Agu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Agu;
  Ebe ^= De;
  Bka = ((((uint64_t)Ebe) << 1) ^ (((uint64_t)Ebe) >> (64 - 1)));
  Egi ^= Di;
  Bke = ((((uint64_t)Egi) << 6) ^ (((uint64_t)Egi) >> (64 - 6)));
  Eko ^= Do;
  Bki = ((((uint64_t)Eko) << 25) ^ (((uint64_t)Eko) >> (64 - 25)));
  Emu ^= Du;
  Bko = ((((uint64_t)Emu) << 8) ^ (((uint64_t)Emu) >> (64 - 8)));
  Esa ^= Da;
  Bku = ((((uint64_t)Esa) << 18) ^ (((uint64_t)Esa) >> (64 - 18)));
  Aka = Bka ^ ((~Bke) & Bki);
  Ca ^= Aka;
  Ake = Bke ^ ((~Bki) & Bko);
  Ce ^= Ake;
  Aki = Bki ^ ((~Bko) & Bku);
  Ci ^= Aki;
  Ako = Bko ^ ((~Bku) & Bka);
  Co ^= Ako;
  Aku = Bku ^ ((~Bka) & Bke);
  Cu ^= Aku;
  Ebu ^= Du;
  Bma = ((((uint64_t)Ebu) << 27) ^ (((uint64_t)Ebu) >> (64 - 27)));
  Ega ^= Da;
  Bme = ((((uint64_t)Ega) << 36) ^ (((uint64_t)Ega) >> (64 - 36)));
  Eke ^= De;
  Bmi = ((((uint64_t)Eke) << 10) ^ (((uint64_t)Eke) >> (64 - 10)));
  Emi ^= Di;
  Bmo = ((((uint64_t)Emi) << 15) ^ (((uint64_t)Emi) >> (64 - 15)));
  Eso ^= Do;
  Bmu = ((((uint64_t)Eso) << 56) ^ (((uint64_t)Eso) >> (64 - 56)));
  Ama = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ama;
  Ame = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Ame;
  Ami = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Ami;
  Amo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Amo;
  Amu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Amu;
  Ebi ^= Di;
  Bsa = ((((uint64_t)Ebi) << 62) ^ (((uint64_t)Ebi) >> (64 - 62)));
  Ego ^= Do;
  Bse = ((((uint64_t)Ego) << 55) ^ (((uint64_t)Ego) >> (64 - 55)));
  Eku ^= Du;
  Bsi = ((((uint64_t)Eku) << 39) ^ (((uint64_t)Eku) >> (64 - 39)));
  Ema ^= Da;
  Bso = ((((uint64_t)Ema) << 41) ^ (((uint64_t)Ema) >> (64 - 41)));
  Ese ^= De;
  Bsu = ((((uint64_t)Ese) << 2) ^ (((uint64_t)Ese) >> (64 - 2)));
  Asa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Asa;
  Ase = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ase;
  Asi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Asi;
  Aso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Aso;
  Asu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Asu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Aba ^= Da;
  Bba = Aba;
  Age ^= De;
  Bbe = ((((uint64_t)Age) << 44) ^ (((uint64_t)Age) >> (64 - 44)));
  Aki ^= Di;
  Bbi = ((((uint64_t)Aki) << 43) ^ (((uint64_t)Aki) >> (64 - 43)));
  Amo ^= Do;
  Bbo = ((((uint64_t)Amo) << 21) ^ (((uint64_t)Amo) >> (64 - 21)));
  Asu ^= Du;
  Bbu = ((((uint64_t)Asu) << 14) ^ (((uint64_t)Asu) >> (64 - 14)));
  Eba = Bba ^ ((~Bbe) & Bbi);
  Eba ^= round_constants[4];
  Ca = Eba;
  Ebe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Ebe;
  Ebi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Ebi;
  Ebo = Bbo ^ ((~Bbu) & Bba);
  Co = Ebo;
  Ebu = Bbu ^ ((~Bba) & Bbe);
  Cu = Ebu;
  Abo ^= Do;
  Bga = ((((uint64_t)Abo) << 28) ^ (((uint64_t)Abo) >> (64 - 28)));
  Agu ^= Du;
  Bge = ((((uint64_t)Agu) << 20) ^ (((uint64_t)Agu) >> (64 - 20)));
  Aka ^= Da;
  Bgi = ((((uint64_t)Aka) << 3) ^ (((uint64_t)Aka) >> (64 - 3)));
  Ame ^= De;
  Bgo = ((((uint64_t)Ame) << 45) ^ (((uint64_t)Ame) >> (64 - 45)));
  Asi ^= Di;
  Bgu = ((((uint64_t)Asi) << 61) ^ (((uint64_t)Asi) >> (64 - 61)));
  Ega = Bga ^ ((~Bge) & Bgi);
  Ca ^= Ega;
  Ege = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Ege;
  Egi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Egi;
  Ego = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ego;
  Egu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Egu;
  Abe ^= De;
  Bka = ((((uint64_t)Abe) << 1) ^ (((uint64_t)Abe) >> (64 - 1)));
  Agi ^= Di;
  Bke = ((((uint64_t)Agi) << 6) ^ (((uint64_t)Agi) >> (64 - 6)));
  Ako ^= Do;
  Bki = ((((uint64_t)Ako) << 25) ^ (((uint64_t)Ako) >> (64 - 25)));
  Amu ^= Du;
  Bko = ((((uint64_t)Amu) << 8) ^ (((uint64_t)Amu) >> (64 - 8)));
  Asa ^= Da;
  Bku = ((((uint64_t)Asa) << 18) ^ (((uint64_t)Asa) >> (64 - 18)));
  Eka = Bka ^ ((~Bke) & Bki);
  Ca ^= Eka;
  Eke = Bke ^ ((~Bki) & Bko);
  Ce ^= Eke;
  Eki = Bki ^ ((~Bko) & Bku);
  Ci ^= Eki;
  Eko = Bko ^ ((~Bku) & Bka);
  Co ^= Eko;
  Eku = Bku ^ ((~Bka) & Bke);
  Cu ^= Eku;
  Abu ^= Du;
  Bma = ((((uint64_t)Abu) << 27) ^ (((uint64_t)Abu) >> (64 - 27)));
  Aga ^= Da;
  Bme = ((((uint64_t)Aga) << 36) ^ (((uint64_t)Aga) >> (64 - 36)));
  Ake ^= De;
  Bmi = ((((uint64_t)Ake) << 10) ^ (((uint64_t)Ake) >> (64 - 10)));
  Ami ^= Di;
  Bmo = ((((uint64_t)Ami) << 15) ^ (((uint64_t)Ami) >> (64 - 15)));
  Aso ^= Do;
  Bmu = ((((uint64_t)Aso) << 56) ^ (((uint64_t)Aso) >> (64 - 56)));
  Ema = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ema;
  Eme = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Eme;
  Emi = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Emi;
  Emo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Emo;
  Emu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Emu;
  Abi ^= Di;
  Bsa = ((((uint64_t)Abi) << 62) ^ (((uint64_t)Abi) >> (64 - 62)));
  Ago ^= Do;
  Bse = ((((uint64_t)Ago) << 55) ^ (((uint64_t)Ago) >> (64 - 55)));
  Aku ^= Du;
  Bsi = ((((uint64_t)Aku) << 39) ^ (((uint64_t)Aku) >> (64 - 39)));
  Ama ^= Da;
  Bso = ((((uint64_t)Ama) << 41) ^ (((uint64_t)Ama) >> (64 - 41)));
  Ase ^= De;
  Bsu = ((((uint64_t)Ase) << 2) ^ (((uint64_t)Ase) >> (64 - 2)));
  Esa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Esa;
  Ese = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ese;
  Esi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Esi;
  Eso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Eso;
  Esu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Esu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Eba ^= Da;
  Bba = Eba;
  Ege ^= De;
  Bbe = ((((uint64_t)Ege) << 44) ^ (((uint64_t)Ege) >> (64 - 44)));
  Eki ^= Di;
  Bbi = ((((uint64_t)Eki) << 43) ^ (((uint64_t)Eki) >> (64 - 43)));
  Emo ^= Do;
  Bbo = ((((uint64_t)Emo) << 21) ^ (((uint64_t)Emo) >> (64 - 21)));
  Esu ^= Du;
  Bbu = ((((uint64_t)Esu) << 14) ^ (((uint64_t)Esu) >> (64 - 14)));
  Aba = Bba ^ ((~Bbe) & Bbi);
  Aba ^= round_constants[5];
  Ca = Aba;
  Abe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Abe;
  Abi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Abi;
  Abo = Bbo ^ ((~Bbu) & Bba);
  Co = Abo;
  Abu = Bbu ^ ((~Bba) & Bbe);
  Cu = Abu;
  Ebo ^= Do;
  Bga = ((((uint64_t)Ebo) << 28) ^ (((uint64_t)Ebo) >> (64 - 28)));
  Egu ^= Du;
  Bge = ((((uint64_t)Egu) << 20) ^ (((uint64_t)Egu) >> (64 - 20)));
  Eka ^= Da;
  Bgi = ((((uint64_t)Eka) << 3) ^ (((uint64_t)Eka) >> (64 - 3)));
  Eme ^= De;
  Bgo = ((((uint64_t)Eme) << 45) ^ (((uint64_t)Eme) >> (64 - 45)));
  Esi ^= Di;
  Bgu = ((((uint64_t)Esi) << 61) ^ (((uint64_t)Esi) >> (64 - 61)));
  Aga = Bga ^ ((~Bge) & Bgi);
  Ca ^= Aga;
  Age = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Age;
  Agi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Agi;
  Ago = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ago;
  Agu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Agu;
  Ebe ^= De;
  Bka = ((((uint64_t)Ebe) << 1) ^ (((uint64_t)Ebe) >> (64 - 1)));
  Egi ^= Di;
  Bke = ((((uint64_t)Egi) << 6) ^ (((uint64_t)Egi) >> (64 - 6)));
  Eko ^= Do;
  Bki = ((((uint64_t)Eko) << 25) ^ (((uint64_t)Eko) >> (64 - 25)));
  Emu ^= Du;
  Bko = ((((uint64_t)Emu) << 8) ^ (((uint64_t)Emu) >> (64 - 8)));
  Esa ^= Da;
  Bku = ((((uint64_t)Esa) << 18) ^ (((uint64_t)Esa) >> (64 - 18)));
  Aka = Bka ^ ((~Bke) & Bki);
  Ca ^= Aka;
  Ake = Bke ^ ((~Bki) & Bko);
  Ce ^= Ake;
  Aki = Bki ^ ((~Bko) & Bku);
  Ci ^= Aki;
  Ako = Bko ^ ((~Bku) & Bka);
  Co ^= Ako;
  Aku = Bku ^ ((~Bka) & Bke);
  Cu ^= Aku;
  Ebu ^= Du;
  Bma = ((((uint64_t)Ebu) << 27) ^ (((uint64_t)Ebu) >> (64 - 27)));
  Ega ^= Da;
  Bme = ((((uint64_t)Ega) << 36) ^ (((uint64_t)Ega) >> (64 - 36)));
  Eke ^= De;
  Bmi = ((((uint64_t)Eke) << 10) ^ (((uint64_t)Eke) >> (64 - 10)));
  Emi ^= Di;
  Bmo = ((((uint64_t)Emi) << 15) ^ (((uint64_t)Emi) >> (64 - 15)));
  Eso ^= Do;
  Bmu = ((((uint64_t)Eso) << 56) ^ (((uint64_t)Eso) >> (64 - 56)));
  Ama = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ama;
  Ame = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Ame;
  Ami = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Ami;
  Amo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Amo;
  Amu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Amu;
  Ebi ^= Di;
  Bsa = ((((uint64_t)Ebi) << 62) ^ (((uint64_t)Ebi) >> (64 - 62)));
  Ego ^= Do;
  Bse = ((((uint64_t)Ego) << 55) ^ (((uint64_t)Ego) >> (64 - 55)));
  Eku ^= Du;
  Bsi = ((((uint64_t)Eku) << 39) ^ (((uint64_t)Eku) >> (64 - 39)));
  Ema ^= Da;
  Bso = ((((uint64_t)Ema) << 41) ^ (((uint64_t)Ema) >> (64 - 41)));
  Ese ^= De;
  Bsu = ((((uint64_t)Ese) << 2) ^ (((uint64_t)Ese) >> (64 - 2)));
  Asa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Asa;
  Ase = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ase;
  Asi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Asi;
  Aso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Aso;
  Asu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Asu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Aba ^= Da;
  Bba = Aba;
  Age ^= De;
  Bbe = ((((uint64_t)Age) << 44) ^ (((uint64_t)Age) >> (64 - 44)));
  Aki ^= Di;
  Bbi = ((((uint64_t)Aki) << 43) ^ (((uint64_t)Aki) >> (64 - 43)));
  Amo ^= Do;
  Bbo = ((((uint64_t)Amo) << 21) ^ (((uint64_t)Amo) >> (64 - 21)));
  Asu ^= Du;
  Bbu = ((((uint64_t)Asu) << 14) ^ (((uint64_t)Asu) >> (64 - 14)));
  Eba = Bba ^ ((~Bbe) & Bbi);
  Eba ^= round_constants[6];
  Ca = Eba;
  Ebe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Ebe;
  Ebi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Ebi;
  Ebo = Bbo ^ ((~Bbu) & Bba);
  Co = Ebo;
  Ebu = Bbu ^ ((~Bba) & Bbe);
  Cu = Ebu;
  Abo ^= Do;
  Bga = ((((uint64_t)Abo) << 28) ^ (((uint64_t)Abo) >> (64 - 28)));
  Agu ^= Du;
  Bge = ((((uint64_t)Agu) << 20) ^ (((uint64_t)Agu) >> (64 - 20)));
  Aka ^= Da;
  Bgi = ((((uint64_t)Aka) << 3) ^ (((uint64_t)Aka) >> (64 - 3)));
  Ame ^= De;
  Bgo = ((((uint64_t)Ame) << 45) ^ (((uint64_t)Ame) >> (64 - 45)));
  Asi ^= Di;
  Bgu = ((((uint64_t)Asi) << 61) ^ (((uint64_t)Asi) >> (64 - 61)));
  Ega = Bga ^ ((~Bge) & Bgi);
  Ca ^= Ega;
  Ege = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Ege;
  Egi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Egi;
  Ego = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ego;
  Egu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Egu;
  Abe ^= De;
  Bka = ((((uint64_t)Abe) << 1) ^ (((uint64_t)Abe) >> (64 - 1)));
  Agi ^= Di;
  Bke = ((((uint64_t)Agi) << 6) ^ (((uint64_t)Agi) >> (64 - 6)));
  Ako ^= Do;
  Bki = ((((uint64_t)Ako) << 25) ^ (((uint64_t)Ako) >> (64 - 25)));
  Amu ^= Du;
  Bko = ((((uint64_t)Amu) << 8) ^ (((uint64_t)Amu) >> (64 - 8)));
  Asa ^= Da;
  Bku = ((((uint64_t)Asa) << 18) ^ (((uint64_t)Asa) >> (64 - 18)));
  Eka = Bka ^ ((~Bke) & Bki);
  Ca ^= Eka;
  Eke = Bke ^ ((~Bki) & Bko);
  Ce ^= Eke;
  Eki = Bki ^ ((~Bko) & Bku);
  Ci ^= Eki;
  Eko = Bko ^ ((~Bku) & Bka);
  Co ^= Eko;
  Eku = Bku ^ ((~Bka) & Bke);
  Cu ^= Eku;
  Abu ^= Du;
  Bma = ((((uint64_t)Abu) << 27) ^ (((uint64_t)Abu) >> (64 - 27)));
  Aga ^= Da;
  Bme = ((((uint64_t)Aga) << 36) ^ (((uint64_t)Aga) >> (64 - 36)));
  Ake ^= De;
  Bmi = ((((uint64_t)Ake) << 10) ^ (((uint64_t)Ake) >> (64 - 10)));
  Ami ^= Di;
  Bmo = ((((uint64_t)Ami) << 15) ^ (((uint64_t)Ami) >> (64 - 15)));
  Aso ^= Do;
  Bmu = ((((uint64_t)Aso) << 56) ^ (((uint64_t)Aso) >> (64 - 56)));
  Ema = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ema;
  Eme = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Eme;
  Emi = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Emi;
  Emo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Emo;
  Emu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Emu;
  Abi ^= Di;
  Bsa = ((((uint64_t)Abi) << 62) ^ (((uint64_t)Abi) >> (64 - 62)));
  Ago ^= Do;
  Bse = ((((uint64_t)Ago) << 55) ^ (((uint64_t)Ago) >> (64 - 55)));
  Aku ^= Du;
  Bsi = ((((uint64_t)Aku) << 39) ^ (((uint64_t)Aku) >> (64 - 39)));
  Ama ^= Da;
  Bso = ((((uint64_t)Ama) << 41) ^ (((uint64_t)Ama) >> (64 - 41)));
  Ase ^= De;
  Bsu = ((((uint64_t)Ase) << 2) ^ (((uint64_t)Ase) >> (64 - 2)));
  Esa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Esa;
  Ese = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ese;
  Esi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Esi;
  Eso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Eso;
  Esu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Esu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Eba ^= Da;
  Bba = Eba;
  Ege ^= De;
  Bbe = ((((uint64_t)Ege) << 44) ^ (((uint64_t)Ege) >> (64 - 44)));
  Eki ^= Di;
  Bbi = ((((uint64_t)Eki) << 43) ^ (((uint64_t)Eki) >> (64 - 43)));
  Emo ^= Do;
  Bbo = ((((uint64_t)Emo) << 21) ^ (((uint64_t)Emo) >> (64 - 21)));
  Esu ^= Du;
  Bbu = ((((uint64_t)Esu) << 14) ^ (((uint64_t)Esu) >> (64 - 14)));
  Aba = Bba ^ ((~Bbe) & Bbi);
  Aba ^= round_constants[7];
  Ca = Aba;
  Abe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Abe;
  Abi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Abi;
  Abo = Bbo ^ ((~Bbu) & Bba);
  Co = Abo;
  Abu = Bbu ^ ((~Bba) & Bbe);
  Cu = Abu;
  Ebo ^= Do;
  Bga = ((((uint64_t)Ebo) << 28) ^ (((uint64_t)Ebo) >> (64 - 28)));
  Egu ^= Du;
  Bge = ((((uint64_t)Egu) << 20) ^ (((uint64_t)Egu) >> (64 - 20)));
  Eka ^= Da;
  Bgi = ((((uint64_t)Eka) << 3) ^ (((uint64_t)Eka) >> (64 - 3)));
  Eme ^= De;
  Bgo = ((((uint64_t)Eme) << 45) ^ (((uint64_t)Eme) >> (64 - 45)));
  Esi ^= Di;
  Bgu = ((((uint64_t)Esi) << 61) ^ (((uint64_t)Esi) >> (64 - 61)));
  Aga = Bga ^ ((~Bge) & Bgi);
  Ca ^= Aga;
  Age = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Age;
  Agi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Agi;
  Ago = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ago;
  Agu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Agu;
  Ebe ^= De;
  Bka = ((((uint64_t)Ebe) << 1) ^ (((uint64_t)Ebe) >> (64 - 1)));
  Egi ^= Di;
  Bke = ((((uint64_t)Egi) << 6) ^ (((uint64_t)Egi) >> (64 - 6)));
  Eko ^= Do;
  Bki = ((((uint64_t)Eko) << 25) ^ (((uint64_t)Eko) >> (64 - 25)));
  Emu ^= Du;
  Bko = ((((uint64_t)Emu) << 8) ^ (((uint64_t)Emu) >> (64 - 8)));
  Esa ^= Da;
  Bku = ((((uint64_t)Esa) << 18) ^ (((uint64_t)Esa) >> (64 - 18)));
  Aka = Bka ^ ((~Bke) & Bki);
  Ca ^= Aka;
  Ake = Bke ^ ((~Bki) & Bko);
  Ce ^= Ake;
  Aki = Bki ^ ((~Bko) & Bku);
  Ci ^= Aki;
  Ako = Bko ^ ((~Bku) & Bka);
  Co ^= Ako;
  Aku = Bku ^ ((~Bka) & Bke);
  Cu ^= Aku;
  Ebu ^= Du;
  Bma = ((((uint64_t)Ebu) << 27) ^ (((uint64_t)Ebu) >> (64 - 27)));
  Ega ^= Da;
  Bme = ((((uint64_t)Ega) << 36) ^ (((uint64_t)Ega) >> (64 - 36)));
  Eke ^= De;
  Bmi = ((((uint64_t)Eke) << 10) ^ (((uint64_t)Eke) >> (64 - 10)));
  Emi ^= Di;
  Bmo = ((((uint64_t)Emi) << 15) ^ (((uint64_t)Emi) >> (64 - 15)));
  Eso ^= Do;
  Bmu = ((((uint64_t)Eso) << 56) ^ (((uint64_t)Eso) >> (64 - 56)));
  Ama = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ama;
  Ame = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Ame;
  Ami = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Ami;
  Amo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Amo;
  Amu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Amu;
  Ebi ^= Di;
  Bsa = ((((uint64_t)Ebi) << 62) ^ (((uint64_t)Ebi) >> (64 - 62)));
  Ego ^= Do;
  Bse = ((((uint64_t)Ego) << 55) ^ (((uint64_t)Ego) >> (64 - 55)));
  Eku ^= Du;
  Bsi = ((((uint64_t)Eku) << 39) ^ (((uint64_t)Eku) >> (64 - 39)));
  Ema ^= Da;
  Bso = ((((uint64_t)Ema) << 41) ^ (((uint64_t)Ema) >> (64 - 41)));
  Ese ^= De;
  Bsu = ((((uint64_t)Ese) << 2) ^ (((uint64_t)Ese) >> (64 - 2)));
  Asa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Asa;
  Ase = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ase;
  Asi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Asi;
  Aso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Aso;
  Asu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Asu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Aba ^= Da;
  Bba = Aba;
  Age ^= De;
  Bbe = ((((uint64_t)Age) << 44) ^ (((uint64_t)Age) >> (64 - 44)));
  Aki ^= Di;
  Bbi = ((((uint64_t)Aki) << 43) ^ (((uint64_t)Aki) >> (64 - 43)));
  Amo ^= Do;
  Bbo = ((((uint64_t)Amo) << 21) ^ (((uint64_t)Amo) >> (64 - 21)));
  Asu ^= Du;
  Bbu = ((((uint64_t)Asu) << 14) ^ (((uint64_t)Asu) >> (64 - 14)));
  Eba = Bba ^ ((~Bbe) & Bbi);
  Eba ^= round_constants[8];
  Ca = Eba;
  Ebe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Ebe;
  Ebi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Ebi;
  Ebo = Bbo ^ ((~Bbu) & Bba);
  Co = Ebo;
  Ebu = Bbu ^ ((~Bba) & Bbe);
  Cu = Ebu;
  Abo ^= Do;
  Bga = ((((uint64_t)Abo) << 28) ^ (((uint64_t)Abo) >> (64 - 28)));
  Agu ^= Du;
  Bge = ((((uint64_t)Agu) << 20) ^ (((uint64_t)Agu) >> (64 - 20)));
  Aka ^= Da;
  Bgi = ((((uint64_t)Aka) << 3) ^ (((uint64_t)Aka) >> (64 - 3)));
  Ame ^= De;
  Bgo = ((((uint64_t)Ame) << 45) ^ (((uint64_t)Ame) >> (64 - 45)));
  Asi ^= Di;
  Bgu = ((((uint64_t)Asi) << 61) ^ (((uint64_t)Asi) >> (64 - 61)));
  Ega = Bga ^ ((~Bge) & Bgi);
  Ca ^= Ega;
  Ege = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Ege;
  Egi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Egi;
  Ego = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ego;
  Egu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Egu;
  Abe ^= De;
  Bka = ((((uint64_t)Abe) << 1) ^ (((uint64_t)Abe) >> (64 - 1)));
  Agi ^= Di;
  Bke = ((((uint64_t)Agi) << 6) ^ (((uint64_t)Agi) >> (64 - 6)));
  Ako ^= Do;
  Bki = ((((uint64_t)Ako) << 25) ^ (((uint64_t)Ako) >> (64 - 25)));
  Amu ^= Du;
  Bko = ((((uint64_t)Amu) << 8) ^ (((uint64_t)Amu) >> (64 - 8)));
  Asa ^= Da;
  Bku = ((((uint64_t)Asa) << 18) ^ (((uint64_t)Asa) >> (64 - 18)));
  Eka = Bka ^ ((~Bke) & Bki);
  Ca ^= Eka;
  Eke = Bke ^ ((~Bki) & Bko);
  Ce ^= Eke;
  Eki = Bki ^ ((~Bko) & Bku);
  Ci ^= Eki;
  Eko = Bko ^ ((~Bku) & Bka);
  Co ^= Eko;
  Eku = Bku ^ ((~Bka) & Bke);
  Cu ^= Eku;
  Abu ^= Du;
  Bma = ((((uint64_t)Abu) << 27) ^ (((uint64_t)Abu) >> (64 - 27)));
  Aga ^= Da;
  Bme = ((((uint64_t)Aga) << 36) ^ (((uint64_t)Aga) >> (64 - 36)));
  Ake ^= De;
  Bmi = ((((uint64_t)Ake) << 10) ^ (((uint64_t)Ake) >> (64 - 10)));
  Ami ^= Di;
  Bmo = ((((uint64_t)Ami) << 15) ^ (((uint64_t)Ami) >> (64 - 15)));
  Aso ^= Do;
  Bmu = ((((uint64_t)Aso) << 56) ^ (((uint64_t)Aso) >> (64 - 56)));
  Ema = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ema;
  Eme = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Eme;
  Emi = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Emi;
  Emo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Emo;
  Emu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Emu;
  Abi ^= Di;
  Bsa = ((((uint64_t)Abi) << 62) ^ (((uint64_t)Abi) >> (64 - 62)));
  Ago ^= Do;
  Bse = ((((uint64_t)Ago) << 55) ^ (((uint64_t)Ago) >> (64 - 55)));
  Aku ^= Du;
  Bsi = ((((uint64_t)Aku) << 39) ^ (((uint64_t)Aku) >> (64 - 39)));
  Ama ^= Da;
  Bso = ((((uint64_t)Ama) << 41) ^ (((uint64_t)Ama) >> (64 - 41)));
  Ase ^= De;
  Bsu = ((((uint64_t)Ase) << 2) ^ (((uint64_t)Ase) >> (64 - 2)));
  Esa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Esa;
  Ese = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ese;
  Esi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Esi;
  Eso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Eso;
  Esu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Esu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Eba ^= Da;
  Bba = Eba;
  Ege ^= De;
  Bbe = ((((uint64_t)Ege) << 44) ^ (((uint64_t)Ege) >> (64 - 44)));
  Eki ^= Di;
  Bbi = ((((uint64_t)Eki) << 43) ^ (((uint64_t)Eki) >> (64 - 43)));
  Emo ^= Do;
  Bbo = ((((uint64_t)Emo) << 21) ^ (((uint64_t)Emo) >> (64 - 21)));
  Esu ^= Du;
  Bbu = ((((uint64_t)Esu) << 14) ^ (((uint64_t)Esu) >> (64 - 14)));
  Aba = Bba ^ ((~Bbe) & Bbi);
  Aba ^= round_constants[9];
  Ca = Aba;
  Abe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Abe;
  Abi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Abi;
  Abo = Bbo ^ ((~Bbu) & Bba);
  Co = Abo;
  Abu = Bbu ^ ((~Bba) & Bbe);
  Cu = Abu;
  Ebo ^= Do;
  Bga = ((((uint64_t)Ebo) << 28) ^ (((uint64_t)Ebo) >> (64 - 28)));
  Egu ^= Du;
  Bge = ((((uint64_t)Egu) << 20) ^ (((uint64_t)Egu) >> (64 - 20)));
  Eka ^= Da;
  Bgi = ((((uint64_t)Eka) << 3) ^ (((uint64_t)Eka) >> (64 - 3)));
  Eme ^= De;
  Bgo = ((((uint64_t)Eme) << 45) ^ (((uint64_t)Eme) >> (64 - 45)));
  Esi ^= Di;
  Bgu = ((((uint64_t)Esi) << 61) ^ (((uint64_t)Esi) >> (64 - 61)));
  Aga = Bga ^ ((~Bge) & Bgi);
  Ca ^= Aga;
  Age = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Age;
  Agi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Agi;
  Ago = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ago;
  Agu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Agu;
  Ebe ^= De;
  Bka = ((((uint64_t)Ebe) << 1) ^ (((uint64_t)Ebe) >> (64 - 1)));
  Egi ^= Di;
  Bke = ((((uint64_t)Egi) << 6) ^ (((uint64_t)Egi) >> (64 - 6)));
  Eko ^= Do;
  Bki = ((((uint64_t)Eko) << 25) ^ (((uint64_t)Eko) >> (64 - 25)));
  Emu ^= Du;
  Bko = ((((uint64_t)Emu) << 8) ^ (((uint64_t)Emu) >> (64 - 8)));
  Esa ^= Da;
  Bku = ((((uint64_t)Esa) << 18) ^ (((uint64_t)Esa) >> (64 - 18)));
  Aka = Bka ^ ((~Bke) & Bki);
  Ca ^= Aka;
  Ake = Bke ^ ((~Bki) & Bko);
  Ce ^= Ake;
  Aki = Bki ^ ((~Bko) & Bku);
  Ci ^= Aki;
  Ako = Bko ^ ((~Bku) & Bka);
  Co ^= Ako;
  Aku = Bku ^ ((~Bka) & Bke);
  Cu ^= Aku;
  Ebu ^= Du;
  Bma = ((((uint64_t)Ebu) << 27) ^ (((uint64_t)Ebu) >> (64 - 27)));
  Ega ^= Da;
  Bme = ((((uint64_t)Ega) << 36) ^ (((uint64_t)Ega) >> (64 - 36)));
  Eke ^= De;
  Bmi = ((((uint64_t)Eke) << 10) ^ (((uint64_t)Eke) >> (64 - 10)));
  Emi ^= Di;
  Bmo = ((((uint64_t)Emi) << 15) ^ (((uint64_t)Emi) >> (64 - 15)));
  Eso ^= Do;
  Bmu = ((((uint64_t)Eso) << 56) ^ (((uint64_t)Eso) >> (64 - 56)));
  Ama = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ama;
  Ame = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Ame;
  Ami = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Ami;
  Amo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Amo;
  Amu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Amu;
  Ebi ^= Di;
  Bsa = ((((uint64_t)Ebi) << 62) ^ (((uint64_t)Ebi) >> (64 - 62)));
  Ego ^= Do;
  Bse = ((((uint64_t)Ego) << 55) ^ (((uint64_t)Ego) >> (64 - 55)));
  Eku ^= Du;
  Bsi = ((((uint64_t)Eku) << 39) ^ (((uint64_t)Eku) >> (64 - 39)));
  Ema ^= Da;
  Bso = ((((uint64_t)Ema) << 41) ^ (((uint64_t)Ema) >> (64 - 41)));
  Ese ^= De;
  Bsu = ((((uint64_t)Ese) << 2) ^ (((uint64_t)Ese) >> (64 - 2)));
  Asa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Asa;
  Ase = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ase;
  Asi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Asi;
  Aso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Aso;
  Asu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Asu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Aba ^= Da;
  Bba = Aba;
  Age ^= De;
  Bbe = ((((uint64_t)Age) << 44) ^ (((uint64_t)Age) >> (64 - 44)));
  Aki ^= Di;
  Bbi = ((((uint64_t)Aki) << 43) ^ (((uint64_t)Aki) >> (64 - 43)));
  Amo ^= Do;
  Bbo = ((((uint64_t)Amo) << 21) ^ (((uint64_t)Amo) >> (64 - 21)));
  Asu ^= Du;
  Bbu = ((((uint64_t)Asu) << 14) ^ (((uint64_t)Asu) >> (64 - 14)));
  Eba = Bba ^ ((~Bbe) & Bbi);
  Eba ^= round_constants[10];
  Ca = Eba;
  Ebe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Ebe;
  Ebi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Ebi;
  Ebo = Bbo ^ ((~Bbu) & Bba);
  Co = Ebo;
  Ebu = Bbu ^ ((~Bba) & Bbe);
  Cu = Ebu;
  Abo ^= Do;
  Bga = ((((uint64_t)Abo) << 28) ^ (((uint64_t)Abo) >> (64 - 28)));
  Agu ^= Du;
  Bge = ((((uint64_t)Agu) << 20) ^ (((uint64_t)Agu) >> (64 - 20)));
  Aka ^= Da;
  Bgi = ((((uint64_t)Aka) << 3) ^ (((uint64_t)Aka) >> (64 - 3)));
  Ame ^= De;
  Bgo = ((((uint64_t)Ame) << 45) ^ (((uint64_t)Ame) >> (64 - 45)));
  Asi ^= Di;
  Bgu = ((((uint64_t)Asi) << 61) ^ (((uint64_t)Asi) >> (64 - 61)));
  Ega = Bga ^ ((~Bge) & Bgi);
  Ca ^= Ega;
  Ege = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Ege;
  Egi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Egi;
  Ego = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ego;
  Egu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Egu;
  Abe ^= De;
  Bka = ((((uint64_t)Abe) << 1) ^ (((uint64_t)Abe) >> (64 - 1)));
  Agi ^= Di;
  Bke = ((((uint64_t)Agi) << 6) ^ (((uint64_t)Agi) >> (64 - 6)));
  Ako ^= Do;
  Bki = ((((uint64_t)Ako) << 25) ^ (((uint64_t)Ako) >> (64 - 25)));
  Amu ^= Du;
  Bko = ((((uint64_t)Amu) << 8) ^ (((uint64_t)Amu) >> (64 - 8)));
  Asa ^= Da;
  Bku = ((((uint64_t)Asa) << 18) ^ (((uint64_t)Asa) >> (64 - 18)));
  Eka = Bka ^ ((~Bke) & Bki);
  Ca ^= Eka;
  Eke = Bke ^ ((~Bki) & Bko);
  Ce ^= Eke;
  Eki = Bki ^ ((~Bko) & Bku);
  Ci ^= Eki;
  Eko = Bko ^ ((~Bku) & Bka);
  Co ^= Eko;
  Eku = Bku ^ ((~Bka) & Bke);
  Cu ^= Eku;
  Abu ^= Du;
  Bma = ((((uint64_t)Abu) << 27) ^ (((uint64_t)Abu) >> (64 - 27)));
  Aga ^= Da;
  Bme = ((((uint64_t)Aga) << 36) ^ (((uint64_t)Aga) >> (64 - 36)));
  Ake ^= De;
  Bmi = ((((uint64_t)Ake) << 10) ^ (((uint64_t)Ake) >> (64 - 10)));
  Ami ^= Di;
  Bmo = ((((uint64_t)Ami) << 15) ^ (((uint64_t)Ami) >> (64 - 15)));
  Aso ^= Do;
  Bmu = ((((uint64_t)Aso) << 56) ^ (((uint64_t)Aso) >> (64 - 56)));
  Ema = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ema;
  Eme = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Eme;
  Emi = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Emi;
  Emo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Emo;
  Emu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Emu;
  Abi ^= Di;
  Bsa = ((((uint64_t)Abi) << 62) ^ (((uint64_t)Abi) >> (64 - 62)));
  Ago ^= Do;
  Bse = ((((uint64_t)Ago) << 55) ^ (((uint64_t)Ago) >> (64 - 55)));
  Aku ^= Du;
  Bsi = ((((uint64_t)Aku) << 39) ^ (((uint64_t)Aku) >> (64 - 39)));
  Ama ^= Da;
  Bso = ((((uint64_t)Ama) << 41) ^ (((uint64_t)Ama) >> (64 - 41)));
  Ase ^= De;
  Bsu = ((((uint64_t)Ase) << 2) ^ (((uint64_t)Ase) >> (64 - 2)));
  Esa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Esa;
  Ese = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ese;
  Esi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Esi;
  Eso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Eso;
  Esu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Esu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Eba ^= Da;
  Bba = Eba;
  Ege ^= De;
  Bbe = ((((uint64_t)Ege) << 44) ^ (((uint64_t)Ege) >> (64 - 44)));
  Eki ^= Di;
  Bbi = ((((uint64_t)Eki) << 43) ^ (((uint64_t)Eki) >> (64 - 43)));
  Emo ^= Do;
  Bbo = ((((uint64_t)Emo) << 21) ^ (((uint64_t)Emo) >> (64 - 21)));
  Esu ^= Du;
  Bbu = ((((uint64_t)Esu) << 14) ^ (((uint64_t)Esu) >> (64 - 14)));
  Aba = Bba ^ ((~Bbe) & Bbi);
  Aba ^= round_constants[11];
  Ca = Aba;
  Abe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Abe;
  Abi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Abi;
  Abo = Bbo ^ ((~Bbu) & Bba);
  Co = Abo;
  Abu = Bbu ^ ((~Bba) & Bbe);
  Cu = Abu;
  Ebo ^= Do;
  Bga = ((((uint64_t)Ebo) << 28) ^ (((uint64_t)Ebo) >> (64 - 28)));
  Egu ^= Du;
  Bge = ((((uint64_t)Egu) << 20) ^ (((uint64_t)Egu) >> (64 - 20)));
  Eka ^= Da;
  Bgi = ((((uint64_t)Eka) << 3) ^ (((uint64_t)Eka) >> (64 - 3)));
  Eme ^= De;
  Bgo = ((((uint64_t)Eme) << 45) ^ (((uint64_t)Eme) >> (64 - 45)));
  Esi ^= Di;
  Bgu = ((((uint64_t)Esi) << 61) ^ (((uint64_t)Esi) >> (64 - 61)));
  Aga = Bga ^ ((~Bge) & Bgi);
  Ca ^= Aga;
  Age = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Age;
  Agi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Agi;
  Ago = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ago;
  Agu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Agu;
  Ebe ^= De;
  Bka = ((((uint64_t)Ebe) << 1) ^ (((uint64_t)Ebe) >> (64 - 1)));
  Egi ^= Di;
  Bke = ((((uint64_t)Egi) << 6) ^ (((uint64_t)Egi) >> (64 - 6)));
  Eko ^= Do;
  Bki = ((((uint64_t)Eko) << 25) ^ (((uint64_t)Eko) >> (64 - 25)));
  Emu ^= Du;
  Bko = ((((uint64_t)Emu) << 8) ^ (((uint64_t)Emu) >> (64 - 8)));
  Esa ^= Da;
  Bku = ((((uint64_t)Esa) << 18) ^ (((uint64_t)Esa) >> (64 - 18)));
  Aka = Bka ^ ((~Bke) & Bki);
  Ca ^= Aka;
  Ake = Bke ^ ((~Bki) & Bko);
  Ce ^= Ake;
  Aki = Bki ^ ((~Bko) & Bku);
  Ci ^= Aki;
  Ako = Bko ^ ((~Bku) & Bka);
  Co ^= Ako;
  Aku = Bku ^ ((~Bka) & Bke);
  Cu ^= Aku;
  Ebu ^= Du;
  Bma = ((((uint64_t)Ebu) << 27) ^ (((uint64_t)Ebu) >> (64 - 27)));
  Ega ^= Da;
  Bme = ((((uint64_t)Ega) << 36) ^ (((uint64_t)Ega) >> (64 - 36)));
  Eke ^= De;
  Bmi = ((((uint64_t)Eke) << 10) ^ (((uint64_t)Eke) >> (64 - 10)));
  Emi ^= Di;
  Bmo = ((((uint64_t)Emi) << 15) ^ (((uint64_t)Emi) >> (64 - 15)));
  Eso ^= Do;
  Bmu = ((((uint64_t)Eso) << 56) ^ (((uint64_t)Eso) >> (64 - 56)));
  Ama = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ama;
  Ame = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Ame;
  Ami = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Ami;
  Amo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Amo;
  Amu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Amu;
  Ebi ^= Di;
  Bsa = ((((uint64_t)Ebi) << 62) ^ (((uint64_t)Ebi) >> (64 - 62)));
  Ego ^= Do;
  Bse = ((((uint64_t)Ego) << 55) ^ (((uint64_t)Ego) >> (64 - 55)));
  Eku ^= Du;
  Bsi = ((((uint64_t)Eku) << 39) ^ (((uint64_t)Eku) >> (64 - 39)));
  Ema ^= Da;
  Bso = ((((uint64_t)Ema) << 41) ^ (((uint64_t)Ema) >> (64 - 41)));
  Ese ^= De;
  Bsu = ((((uint64_t)Ese) << 2) ^ (((uint64_t)Ese) >> (64 - 2)));
  Asa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Asa;
  Ase = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ase;
  Asi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Asi;
  Aso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Aso;
  Asu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Asu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Aba ^= Da;
  Bba = Aba;
  Age ^= De;
  Bbe = ((((uint64_t)Age) << 44) ^ (((uint64_t)Age) >> (64 - 44)));
  Aki ^= Di;
  Bbi = ((((uint64_t)Aki) << 43) ^ (((uint64_t)Aki) >> (64 - 43)));
  Amo ^= Do;
  Bbo = ((((uint64_t)Amo) << 21) ^ (((uint64_t)Amo) >> (64 - 21)));
  Asu ^= Du;
  Bbu = ((((uint64_t)Asu) << 14) ^ (((uint64_t)Asu) >> (64 - 14)));
  Eba = Bba ^ ((~Bbe) & Bbi);
  Eba ^= round_constants[12];
  Ca = Eba;
  Ebe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Ebe;
  Ebi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Ebi;
  Ebo = Bbo ^ ((~Bbu) & Bba);
  Co = Ebo;
  Ebu = Bbu ^ ((~Bba) & Bbe);
  Cu = Ebu;
  Abo ^= Do;
  Bga = ((((uint64_t)Abo) << 28) ^ (((uint64_t)Abo) >> (64 - 28)));
  Agu ^= Du;
  Bge = ((((uint64_t)Agu) << 20) ^ (((uint64_t)Agu) >> (64 - 20)));
  Aka ^= Da;
  Bgi = ((((uint64_t)Aka) << 3) ^ (((uint64_t)Aka) >> (64 - 3)));
  Ame ^= De;
  Bgo = ((((uint64_t)Ame) << 45) ^ (((uint64_t)Ame) >> (64 - 45)));
  Asi ^= Di;
  Bgu = ((((uint64_t)Asi) << 61) ^ (((uint64_t)Asi) >> (64 - 61)));
  Ega = Bga ^ ((~Bge) & Bgi);
  Ca ^= Ega;
  Ege = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Ege;
  Egi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Egi;
  Ego = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ego;
  Egu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Egu;
  Abe ^= De;
  Bka = ((((uint64_t)Abe) << 1) ^ (((uint64_t)Abe) >> (64 - 1)));
  Agi ^= Di;
  Bke = ((((uint64_t)Agi) << 6) ^ (((uint64_t)Agi) >> (64 - 6)));
  Ako ^= Do;
  Bki = ((((uint64_t)Ako) << 25) ^ (((uint64_t)Ako) >> (64 - 25)));
  Amu ^= Du;
  Bko = ((((uint64_t)Amu) << 8) ^ (((uint64_t)Amu) >> (64 - 8)));
  Asa ^= Da;
  Bku = ((((uint64_t)Asa) << 18) ^ (((uint64_t)Asa) >> (64 - 18)));
  Eka = Bka ^ ((~Bke) & Bki);
  Ca ^= Eka;
  Eke = Bke ^ ((~Bki) & Bko);
  Ce ^= Eke;
  Eki = Bki ^ ((~Bko) & Bku);
  Ci ^= Eki;
  Eko = Bko ^ ((~Bku) & Bka);
  Co ^= Eko;
  Eku = Bku ^ ((~Bka) & Bke);
  Cu ^= Eku;
  Abu ^= Du;
  Bma = ((((uint64_t)Abu) << 27) ^ (((uint64_t)Abu) >> (64 - 27)));
  Aga ^= Da;
  Bme = ((((uint64_t)Aga) << 36) ^ (((uint64_t)Aga) >> (64 - 36)));
  Ake ^= De;
  Bmi = ((((uint64_t)Ake) << 10) ^ (((uint64_t)Ake) >> (64 - 10)));
  Ami ^= Di;
  Bmo = ((((uint64_t)Ami) << 15) ^ (((uint64_t)Ami) >> (64 - 15)));
  Aso ^= Do;
  Bmu = ((((uint64_t)Aso) << 56) ^ (((uint64_t)Aso) >> (64 - 56)));
  Ema = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ema;
  Eme = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Eme;
  Emi = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Emi;
  Emo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Emo;
  Emu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Emu;
  Abi ^= Di;
  Bsa = ((((uint64_t)Abi) << 62) ^ (((uint64_t)Abi) >> (64 - 62)));
  Ago ^= Do;
  Bse = ((((uint64_t)Ago) << 55) ^ (((uint64_t)Ago) >> (64 - 55)));
  Aku ^= Du;
  Bsi = ((((uint64_t)Aku) << 39) ^ (((uint64_t)Aku) >> (64 - 39)));
  Ama ^= Da;
  Bso = ((((uint64_t)Ama) << 41) ^ (((uint64_t)Ama) >> (64 - 41)));
  Ase ^= De;
  Bsu = ((((uint64_t)Ase) << 2) ^ (((uint64_t)Ase) >> (64 - 2)));
  Esa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Esa;
  Ese = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ese;
  Esi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Esi;
  Eso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Eso;
  Esu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Esu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Eba ^= Da;
  Bba = Eba;
  Ege ^= De;
  Bbe = ((((uint64_t)Ege) << 44) ^ (((uint64_t)Ege) >> (64 - 44)));
  Eki ^= Di;
  Bbi = ((((uint64_t)Eki) << 43) ^ (((uint64_t)Eki) >> (64 - 43)));
  Emo ^= Do;
  Bbo = ((((uint64_t)Emo) << 21) ^ (((uint64_t)Emo) >> (64 - 21)));
  Esu ^= Du;
  Bbu = ((((uint64_t)Esu) << 14) ^ (((uint64_t)Esu) >> (64 - 14)));
  Aba = Bba ^ ((~Bbe) & Bbi);
  Aba ^= round_constants[13];
  Ca = Aba;
  Abe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Abe;
  Abi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Abi;
  Abo = Bbo ^ ((~Bbu) & Bba);
  Co = Abo;
  Abu = Bbu ^ ((~Bba) & Bbe);
  Cu = Abu;
  Ebo ^= Do;
  Bga = ((((uint64_t)Ebo) << 28) ^ (((uint64_t)Ebo) >> (64 - 28)));
  Egu ^= Du;
  Bge = ((((uint64_t)Egu) << 20) ^ (((uint64_t)Egu) >> (64 - 20)));
  Eka ^= Da;
  Bgi = ((((uint64_t)Eka) << 3) ^ (((uint64_t)Eka) >> (64 - 3)));
  Eme ^= De;
  Bgo = ((((uint64_t)Eme) << 45) ^ (((uint64_t)Eme) >> (64 - 45)));
  Esi ^= Di;
  Bgu = ((((uint64_t)Esi) << 61) ^ (((uint64_t)Esi) >> (64 - 61)));
  Aga = Bga ^ ((~Bge) & Bgi);
  Ca ^= Aga;
  Age = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Age;
  Agi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Agi;
  Ago = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ago;
  Agu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Agu;
  Ebe ^= De;
  Bka = ((((uint64_t)Ebe) << 1) ^ (((uint64_t)Ebe) >> (64 - 1)));
  Egi ^= Di;
  Bke = ((((uint64_t)Egi) << 6) ^ (((uint64_t)Egi) >> (64 - 6)));
  Eko ^= Do;
  Bki = ((((uint64_t)Eko) << 25) ^ (((uint64_t)Eko) >> (64 - 25)));
  Emu ^= Du;
  Bko = ((((uint64_t)Emu) << 8) ^ (((uint64_t)Emu) >> (64 - 8)));
  Esa ^= Da;
  Bku = ((((uint64_t)Esa) << 18) ^ (((uint64_t)Esa) >> (64 - 18)));
  Aka = Bka ^ ((~Bke) & Bki);
  Ca ^= Aka;
  Ake = Bke ^ ((~Bki) & Bko);
  Ce ^= Ake;
  Aki = Bki ^ ((~Bko) & Bku);
  Ci ^= Aki;
  Ako = Bko ^ ((~Bku) & Bka);
  Co ^= Ako;
  Aku = Bku ^ ((~Bka) & Bke);
  Cu ^= Aku;
  Ebu ^= Du;
  Bma = ((((uint64_t)Ebu) << 27) ^ (((uint64_t)Ebu) >> (64 - 27)));
  Ega ^= Da;
  Bme = ((((uint64_t)Ega) << 36) ^ (((uint64_t)Ega) >> (64 - 36)));
  Eke ^= De;
  Bmi = ((((uint64_t)Eke) << 10) ^ (((uint64_t)Eke) >> (64 - 10)));
  Emi ^= Di;
  Bmo = ((((uint64_t)Emi) << 15) ^ (((uint64_t)Emi) >> (64 - 15)));
  Eso ^= Do;
  Bmu = ((((uint64_t)Eso) << 56) ^ (((uint64_t)Eso) >> (64 - 56)));
  Ama = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ama;
  Ame = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Ame;
  Ami = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Ami;
  Amo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Amo;
  Amu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Amu;
  Ebi ^= Di;
  Bsa = ((((uint64_t)Ebi) << 62) ^ (((uint64_t)Ebi) >> (64 - 62)));
  Ego ^= Do;
  Bse = ((((uint64_t)Ego) << 55) ^ (((uint64_t)Ego) >> (64 - 55)));
  Eku ^= Du;
  Bsi = ((((uint64_t)Eku) << 39) ^ (((uint64_t)Eku) >> (64 - 39)));
  Ema ^= Da;
  Bso = ((((uint64_t)Ema) << 41) ^ (((uint64_t)Ema) >> (64 - 41)));
  Ese ^= De;
  Bsu = ((((uint64_t)Ese) << 2) ^ (((uint64_t)Ese) >> (64 - 2)));
  Asa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Asa;
  Ase = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ase;
  Asi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Asi;
  Aso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Aso;
  Asu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Asu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Aba ^= Da;
  Bba = Aba;
  Age ^= De;
  Bbe = ((((uint64_t)Age) << 44) ^ (((uint64_t)Age) >> (64 - 44)));
  Aki ^= Di;
  Bbi = ((((uint64_t)Aki) << 43) ^ (((uint64_t)Aki) >> (64 - 43)));
  Amo ^= Do;
  Bbo = ((((uint64_t)Amo) << 21) ^ (((uint64_t)Amo) >> (64 - 21)));
  Asu ^= Du;
  Bbu = ((((uint64_t)Asu) << 14) ^ (((uint64_t)Asu) >> (64 - 14)));
  Eba = Bba ^ ((~Bbe) & Bbi);
  Eba ^= round_constants[14];
  Ca = Eba;
  Ebe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Ebe;
  Ebi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Ebi;
  Ebo = Bbo ^ ((~Bbu) & Bba);
  Co = Ebo;
  Ebu = Bbu ^ ((~Bba) & Bbe);
  Cu = Ebu;
  Abo ^= Do;
  Bga = ((((uint64_t)Abo) << 28) ^ (((uint64_t)Abo) >> (64 - 28)));
  Agu ^= Du;
  Bge = ((((uint64_t)Agu) << 20) ^ (((uint64_t)Agu) >> (64 - 20)));
  Aka ^= Da;
  Bgi = ((((uint64_t)Aka) << 3) ^ (((uint64_t)Aka) >> (64 - 3)));
  Ame ^= De;
  Bgo = ((((uint64_t)Ame) << 45) ^ (((uint64_t)Ame) >> (64 - 45)));
  Asi ^= Di;
  Bgu = ((((uint64_t)Asi) << 61) ^ (((uint64_t)Asi) >> (64 - 61)));
  Ega = Bga ^ ((~Bge) & Bgi);
  Ca ^= Ega;
  Ege = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Ege;
  Egi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Egi;
  Ego = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ego;
  Egu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Egu;
  Abe ^= De;
  Bka = ((((uint64_t)Abe) << 1) ^ (((uint64_t)Abe) >> (64 - 1)));
  Agi ^= Di;
  Bke = ((((uint64_t)Agi) << 6) ^ (((uint64_t)Agi) >> (64 - 6)));
  Ako ^= Do;
  Bki = ((((uint64_t)Ako) << 25) ^ (((uint64_t)Ako) >> (64 - 25)));
  Amu ^= Du;
  Bko = ((((uint64_t)Amu) << 8) ^ (((uint64_t)Amu) >> (64 - 8)));
  Asa ^= Da;
  Bku = ((((uint64_t)Asa) << 18) ^ (((uint64_t)Asa) >> (64 - 18)));
  Eka = Bka ^ ((~Bke) & Bki);
  Ca ^= Eka;
  Eke = Bke ^ ((~Bki) & Bko);
  Ce ^= Eke;
  Eki = Bki ^ ((~Bko) & Bku);
  Ci ^= Eki;
  Eko = Bko ^ ((~Bku) & Bka);
  Co ^= Eko;
  Eku = Bku ^ ((~Bka) & Bke);
  Cu ^= Eku;
  Abu ^= Du;
  Bma = ((((uint64_t)Abu) << 27) ^ (((uint64_t)Abu) >> (64 - 27)));
  Aga ^= Da;
  Bme = ((((uint64_t)Aga) << 36) ^ (((uint64_t)Aga) >> (64 - 36)));
  Ake ^= De;
  Bmi = ((((uint64_t)Ake) << 10) ^ (((uint64_t)Ake) >> (64 - 10)));
  Ami ^= Di;
  Bmo = ((((uint64_t)Ami) << 15) ^ (((uint64_t)Ami) >> (64 - 15)));
  Aso ^= Do;
  Bmu = ((((uint64_t)Aso) << 56) ^ (((uint64_t)Aso) >> (64 - 56)));
  Ema = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ema;
  Eme = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Eme;
  Emi = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Emi;
  Emo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Emo;
  Emu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Emu;
  Abi ^= Di;
  Bsa = ((((uint64_t)Abi) << 62) ^ (((uint64_t)Abi) >> (64 - 62)));
  Ago ^= Do;
  Bse = ((((uint64_t)Ago) << 55) ^ (((uint64_t)Ago) >> (64 - 55)));
  Aku ^= Du;
  Bsi = ((((uint64_t)Aku) << 39) ^ (((uint64_t)Aku) >> (64 - 39)));
  Ama ^= Da;
  Bso = ((((uint64_t)Ama) << 41) ^ (((uint64_t)Ama) >> (64 - 41)));
  Ase ^= De;
  Bsu = ((((uint64_t)Ase) << 2) ^ (((uint64_t)Ase) >> (64 - 2)));
  Esa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Esa;
  Ese = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ese;
  Esi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Esi;
  Eso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Eso;
  Esu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Esu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Eba ^= Da;
  Bba = Eba;
  Ege ^= De;
  Bbe = ((((uint64_t)Ege) << 44) ^ (((uint64_t)Ege) >> (64 - 44)));
  Eki ^= Di;
  Bbi = ((((uint64_t)Eki) << 43) ^ (((uint64_t)Eki) >> (64 - 43)));
  Emo ^= Do;
  Bbo = ((((uint64_t)Emo) << 21) ^ (((uint64_t)Emo) >> (64 - 21)));
  Esu ^= Du;
  Bbu = ((((uint64_t)Esu) << 14) ^ (((uint64_t)Esu) >> (64 - 14)));
  Aba = Bba ^ ((~Bbe) & Bbi);
  Aba ^= round_constants[15];
  Ca = Aba;
  Abe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Abe;
  Abi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Abi;
  Abo = Bbo ^ ((~Bbu) & Bba);
  Co = Abo;
  Abu = Bbu ^ ((~Bba) & Bbe);
  Cu = Abu;
  Ebo ^= Do;
  Bga = ((((uint64_t)Ebo) << 28) ^ (((uint64_t)Ebo) >> (64 - 28)));
  Egu ^= Du;
  Bge = ((((uint64_t)Egu) << 20) ^ (((uint64_t)Egu) >> (64 - 20)));
  Eka ^= Da;
  Bgi = ((((uint64_t)Eka) << 3) ^ (((uint64_t)Eka) >> (64 - 3)));
  Eme ^= De;
  Bgo = ((((uint64_t)Eme) << 45) ^ (((uint64_t)Eme) >> (64 - 45)));
  Esi ^= Di;
  Bgu = ((((uint64_t)Esi) << 61) ^ (((uint64_t)Esi) >> (64 - 61)));
  Aga = Bga ^ ((~Bge) & Bgi);
  Ca ^= Aga;
  Age = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Age;
  Agi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Agi;
  Ago = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ago;
  Agu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Agu;
  Ebe ^= De;
  Bka = ((((uint64_t)Ebe) << 1) ^ (((uint64_t)Ebe) >> (64 - 1)));
  Egi ^= Di;
  Bke = ((((uint64_t)Egi) << 6) ^ (((uint64_t)Egi) >> (64 - 6)));
  Eko ^= Do;
  Bki = ((((uint64_t)Eko) << 25) ^ (((uint64_t)Eko) >> (64 - 25)));
  Emu ^= Du;
  Bko = ((((uint64_t)Emu) << 8) ^ (((uint64_t)Emu) >> (64 - 8)));
  Esa ^= Da;
  Bku = ((((uint64_t)Esa) << 18) ^ (((uint64_t)Esa) >> (64 - 18)));
  Aka = Bka ^ ((~Bke) & Bki);
  Ca ^= Aka;
  Ake = Bke ^ ((~Bki) & Bko);
  Ce ^= Ake;
  Aki = Bki ^ ((~Bko) & Bku);
  Ci ^= Aki;
  Ako = Bko ^ ((~Bku) & Bka);
  Co ^= Ako;
  Aku = Bku ^ ((~Bka) & Bke);
  Cu ^= Aku;
  Ebu ^= Du;
  Bma = ((((uint64_t)Ebu) << 27) ^ (((uint64_t)Ebu) >> (64 - 27)));
  Ega ^= Da;
  Bme = ((((uint64_t)Ega) << 36) ^ (((uint64_t)Ega) >> (64 - 36)));
  Eke ^= De;
  Bmi = ((((uint64_t)Eke) << 10) ^ (((uint64_t)Eke) >> (64 - 10)));
  Emi ^= Di;
  Bmo = ((((uint64_t)Emi) << 15) ^ (((uint64_t)Emi) >> (64 - 15)));
  Eso ^= Do;
  Bmu = ((((uint64_t)Eso) << 56) ^ (((uint64_t)Eso) >> (64 - 56)));
  Ama = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ama;
  Ame = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Ame;
  Ami = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Ami;
  Amo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Amo;
  Amu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Amu;
  Ebi ^= Di;
  Bsa = ((((uint64_t)Ebi) << 62) ^ (((uint64_t)Ebi) >> (64 - 62)));
  Ego ^= Do;
  Bse = ((((uint64_t)Ego) << 55) ^ (((uint64_t)Ego) >> (64 - 55)));
  Eku ^= Du;
  Bsi = ((((uint64_t)Eku) << 39) ^ (((uint64_t)Eku) >> (64 - 39)));
  Ema ^= Da;
  Bso = ((((uint64_t)Ema) << 41) ^ (((uint64_t)Ema) >> (64 - 41)));
  Ese ^= De;
  Bsu = ((((uint64_t)Ese) << 2) ^ (((uint64_t)Ese) >> (64 - 2)));
  Asa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Asa;
  Ase = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ase;
  Asi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Asi;
  Aso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Aso;
  Asu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Asu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Aba ^= Da;
  Bba = Aba;
  Age ^= De;
  Bbe = ((((uint64_t)Age) << 44) ^ (((uint64_t)Age) >> (64 - 44)));
  Aki ^= Di;
  Bbi = ((((uint64_t)Aki) << 43) ^ (((uint64_t)Aki) >> (64 - 43)));
  Amo ^= Do;
  Bbo = ((((uint64_t)Amo) << 21) ^ (((uint64_t)Amo) >> (64 - 21)));
  Asu ^= Du;
  Bbu = ((((uint64_t)Asu) << 14) ^ (((uint64_t)Asu) >> (64 - 14)));
  Eba = Bba ^ ((~Bbe) & Bbi);
  Eba ^= round_constants[16];
  Ca = Eba;
  Ebe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Ebe;
  Ebi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Ebi;
  Ebo = Bbo ^ ((~Bbu) & Bba);
  Co = Ebo;
  Ebu = Bbu ^ ((~Bba) & Bbe);
  Cu = Ebu;
  Abo ^= Do;
  Bga = ((((uint64_t)Abo) << 28) ^ (((uint64_t)Abo) >> (64 - 28)));
  Agu ^= Du;
  Bge = ((((uint64_t)Agu) << 20) ^ (((uint64_t)Agu) >> (64 - 20)));
  Aka ^= Da;
  Bgi = ((((uint64_t)Aka) << 3) ^ (((uint64_t)Aka) >> (64 - 3)));
  Ame ^= De;
  Bgo = ((((uint64_t)Ame) << 45) ^ (((uint64_t)Ame) >> (64 - 45)));
  Asi ^= Di;
  Bgu = ((((uint64_t)Asi) << 61) ^ (((uint64_t)Asi) >> (64 - 61)));
  Ega = Bga ^ ((~Bge) & Bgi);
  Ca ^= Ega;
  Ege = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Ege;
  Egi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Egi;
  Ego = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ego;
  Egu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Egu;
  Abe ^= De;
  Bka = ((((uint64_t)Abe) << 1) ^ (((uint64_t)Abe) >> (64 - 1)));
  Agi ^= Di;
  Bke = ((((uint64_t)Agi) << 6) ^ (((uint64_t)Agi) >> (64 - 6)));
  Ako ^= Do;
  Bki = ((((uint64_t)Ako) << 25) ^ (((uint64_t)Ako) >> (64 - 25)));
  Amu ^= Du;
  Bko = ((((uint64_t)Amu) << 8) ^ (((uint64_t)Amu) >> (64 - 8)));
  Asa ^= Da;
  Bku = ((((uint64_t)Asa) << 18) ^ (((uint64_t)Asa) >> (64 - 18)));
  Eka = Bka ^ ((~Bke) & Bki);
  Ca ^= Eka;
  Eke = Bke ^ ((~Bki) & Bko);
  Ce ^= Eke;
  Eki = Bki ^ ((~Bko) & Bku);
  Ci ^= Eki;
  Eko = Bko ^ ((~Bku) & Bka);
  Co ^= Eko;
  Eku = Bku ^ ((~Bka) & Bke);
  Cu ^= Eku;
  Abu ^= Du;
  Bma = ((((uint64_t)Abu) << 27) ^ (((uint64_t)Abu) >> (64 - 27)));
  Aga ^= Da;
  Bme = ((((uint64_t)Aga) << 36) ^ (((uint64_t)Aga) >> (64 - 36)));
  Ake ^= De;
  Bmi = ((((uint64_t)Ake) << 10) ^ (((uint64_t)Ake) >> (64 - 10)));
  Ami ^= Di;
  Bmo = ((((uint64_t)Ami) << 15) ^ (((uint64_t)Ami) >> (64 - 15)));
  Aso ^= Do;
  Bmu = ((((uint64_t)Aso) << 56) ^ (((uint64_t)Aso) >> (64 - 56)));
  Ema = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ema;
  Eme = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Eme;
  Emi = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Emi;
  Emo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Emo;
  Emu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Emu;
  Abi ^= Di;
  Bsa = ((((uint64_t)Abi) << 62) ^ (((uint64_t)Abi) >> (64 - 62)));
  Ago ^= Do;
  Bse = ((((uint64_t)Ago) << 55) ^ (((uint64_t)Ago) >> (64 - 55)));
  Aku ^= Du;
  Bsi = ((((uint64_t)Aku) << 39) ^ (((uint64_t)Aku) >> (64 - 39)));
  Ama ^= Da;
  Bso = ((((uint64_t)Ama) << 41) ^ (((uint64_t)Ama) >> (64 - 41)));
  Ase ^= De;
  Bsu = ((((uint64_t)Ase) << 2) ^ (((uint64_t)Ase) >> (64 - 2)));
  Esa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Esa;
  Ese = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ese;
  Esi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Esi;
  Eso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Eso;
  Esu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Esu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Eba ^= Da;
  Bba = Eba;
  Ege ^= De;
  Bbe = ((((uint64_t)Ege) << 44) ^ (((uint64_t)Ege) >> (64 - 44)));
  Eki ^= Di;
  Bbi = ((((uint64_t)Eki) << 43) ^ (((uint64_t)Eki) >> (64 - 43)));
  Emo ^= Do;
  Bbo = ((((uint64_t)Emo) << 21) ^ (((uint64_t)Emo) >> (64 - 21)));
  Esu ^= Du;
  Bbu = ((((uint64_t)Esu) << 14) ^ (((uint64_t)Esu) >> (64 - 14)));
  Aba = Bba ^ ((~Bbe) & Bbi);
  Aba ^= round_constants[17];
  Ca = Aba;
  Abe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Abe;
  Abi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Abi;
  Abo = Bbo ^ ((~Bbu) & Bba);
  Co = Abo;
  Abu = Bbu ^ ((~Bba) & Bbe);
  Cu = Abu;
  Ebo ^= Do;
  Bga = ((((uint64_t)Ebo) << 28) ^ (((uint64_t)Ebo) >> (64 - 28)));
  Egu ^= Du;
  Bge = ((((uint64_t)Egu) << 20) ^ (((uint64_t)Egu) >> (64 - 20)));
  Eka ^= Da;
  Bgi = ((((uint64_t)Eka) << 3) ^ (((uint64_t)Eka) >> (64 - 3)));
  Eme ^= De;
  Bgo = ((((uint64_t)Eme) << 45) ^ (((uint64_t)Eme) >> (64 - 45)));
  Esi ^= Di;
  Bgu = ((((uint64_t)Esi) << 61) ^ (((uint64_t)Esi) >> (64 - 61)));
  Aga = Bga ^ ((~Bge) & Bgi);
  Ca ^= Aga;
  Age = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Age;
  Agi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Agi;
  Ago = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ago;
  Agu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Agu;
  Ebe ^= De;
  Bka = ((((uint64_t)Ebe) << 1) ^ (((uint64_t)Ebe) >> (64 - 1)));
  Egi ^= Di;
  Bke = ((((uint64_t)Egi) << 6) ^ (((uint64_t)Egi) >> (64 - 6)));
  Eko ^= Do;
  Bki = ((((uint64_t)Eko) << 25) ^ (((uint64_t)Eko) >> (64 - 25)));
  Emu ^= Du;
  Bko = ((((uint64_t)Emu) << 8) ^ (((uint64_t)Emu) >> (64 - 8)));
  Esa ^= Da;
  Bku = ((((uint64_t)Esa) << 18) ^ (((uint64_t)Esa) >> (64 - 18)));
  Aka = Bka ^ ((~Bke) & Bki);
  Ca ^= Aka;
  Ake = Bke ^ ((~Bki) & Bko);
  Ce ^= Ake;
  Aki = Bki ^ ((~Bko) & Bku);
  Ci ^= Aki;
  Ako = Bko ^ ((~Bku) & Bka);
  Co ^= Ako;
  Aku = Bku ^ ((~Bka) & Bke);
  Cu ^= Aku;
  Ebu ^= Du;
  Bma = ((((uint64_t)Ebu) << 27) ^ (((uint64_t)Ebu) >> (64 - 27)));
  Ega ^= Da;
  Bme = ((((uint64_t)Ega) << 36) ^ (((uint64_t)Ega) >> (64 - 36)));
  Eke ^= De;
  Bmi = ((((uint64_t)Eke) << 10) ^ (((uint64_t)Eke) >> (64 - 10)));
  Emi ^= Di;
  Bmo = ((((uint64_t)Emi) << 15) ^ (((uint64_t)Emi) >> (64 - 15)));
  Eso ^= Do;
  Bmu = ((((uint64_t)Eso) << 56) ^ (((uint64_t)Eso) >> (64 - 56)));
  Ama = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ama;
  Ame = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Ame;
  Ami = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Ami;
  Amo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Amo;
  Amu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Amu;
  Ebi ^= Di;
  Bsa = ((((uint64_t)Ebi) << 62) ^ (((uint64_t)Ebi) >> (64 - 62)));
  Ego ^= Do;
  Bse = ((((uint64_t)Ego) << 55) ^ (((uint64_t)Ego) >> (64 - 55)));
  Eku ^= Du;
  Bsi = ((((uint64_t)Eku) << 39) ^ (((uint64_t)Eku) >> (64 - 39)));
  Ema ^= Da;
  Bso = ((((uint64_t)Ema) << 41) ^ (((uint64_t)Ema) >> (64 - 41)));
  Ese ^= De;
  Bsu = ((((uint64_t)Ese) << 2) ^ (((uint64_t)Ese) >> (64 - 2)));
  Asa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Asa;
  Ase = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ase;
  Asi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Asi;
  Aso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Aso;
  Asu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Asu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Aba ^= Da;
  Bba = Aba;
  Age ^= De;
  Bbe = ((((uint64_t)Age) << 44) ^ (((uint64_t)Age) >> (64 - 44)));
  Aki ^= Di;
  Bbi = ((((uint64_t)Aki) << 43) ^ (((uint64_t)Aki) >> (64 - 43)));
  Amo ^= Do;
  Bbo = ((((uint64_t)Amo) << 21) ^ (((uint64_t)Amo) >> (64 - 21)));
  Asu ^= Du;
  Bbu = ((((uint64_t)Asu) << 14) ^ (((uint64_t)Asu) >> (64 - 14)));
  Eba = Bba ^ ((~Bbe) & Bbi);
  Eba ^= round_constants[18];
  Ca = Eba;
  Ebe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Ebe;
  Ebi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Ebi;
  Ebo = Bbo ^ ((~Bbu) & Bba);
  Co = Ebo;
  Ebu = Bbu ^ ((~Bba) & Bbe);
  Cu = Ebu;
  Abo ^= Do;
  Bga = ((((uint64_t)Abo) << 28) ^ (((uint64_t)Abo) >> (64 - 28)));
  Agu ^= Du;
  Bge = ((((uint64_t)Agu) << 20) ^ (((uint64_t)Agu) >> (64 - 20)));
  Aka ^= Da;
  Bgi = ((((uint64_t)Aka) << 3) ^ (((uint64_t)Aka) >> (64 - 3)));
  Ame ^= De;
  Bgo = ((((uint64_t)Ame) << 45) ^ (((uint64_t)Ame) >> (64 - 45)));
  Asi ^= Di;
  Bgu = ((((uint64_t)Asi) << 61) ^ (((uint64_t)Asi) >> (64 - 61)));
  Ega = Bga ^ ((~Bge) & Bgi);
  Ca ^= Ega;
  Ege = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Ege;
  Egi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Egi;
  Ego = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ego;
  Egu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Egu;
  Abe ^= De;
  Bka = ((((uint64_t)Abe) << 1) ^ (((uint64_t)Abe) >> (64 - 1)));
  Agi ^= Di;
  Bke = ((((uint64_t)Agi) << 6) ^ (((uint64_t)Agi) >> (64 - 6)));
  Ako ^= Do;
  Bki = ((((uint64_t)Ako) << 25) ^ (((uint64_t)Ako) >> (64 - 25)));
  Amu ^= Du;
  Bko = ((((uint64_t)Amu) << 8) ^ (((uint64_t)Amu) >> (64 - 8)));
  Asa ^= Da;
  Bku = ((((uint64_t)Asa) << 18) ^ (((uint64_t)Asa) >> (64 - 18)));
  Eka = Bka ^ ((~Bke) & Bki);
  Ca ^= Eka;
  Eke = Bke ^ ((~Bki) & Bko);
  Ce ^= Eke;
  Eki = Bki ^ ((~Bko) & Bku);
  Ci ^= Eki;
  Eko = Bko ^ ((~Bku) & Bka);
  Co ^= Eko;
  Eku = Bku ^ ((~Bka) & Bke);
  Cu ^= Eku;
  Abu ^= Du;
  Bma = ((((uint64_t)Abu) << 27) ^ (((uint64_t)Abu) >> (64 - 27)));
  Aga ^= Da;
  Bme = ((((uint64_t)Aga) << 36) ^ (((uint64_t)Aga) >> (64 - 36)));
  Ake ^= De;
  Bmi = ((((uint64_t)Ake) << 10) ^ (((uint64_t)Ake) >> (64 - 10)));
  Ami ^= Di;
  Bmo = ((((uint64_t)Ami) << 15) ^ (((uint64_t)Ami) >> (64 - 15)));
  Aso ^= Do;
  Bmu = ((((uint64_t)Aso) << 56) ^ (((uint64_t)Aso) >> (64 - 56)));
  Ema = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ema;
  Eme = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Eme;
  Emi = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Emi;
  Emo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Emo;
  Emu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Emu;
  Abi ^= Di;
  Bsa = ((((uint64_t)Abi) << 62) ^ (((uint64_t)Abi) >> (64 - 62)));
  Ago ^= Do;
  Bse = ((((uint64_t)Ago) << 55) ^ (((uint64_t)Ago) >> (64 - 55)));
  Aku ^= Du;
  Bsi = ((((uint64_t)Aku) << 39) ^ (((uint64_t)Aku) >> (64 - 39)));
  Ama ^= Da;
  Bso = ((((uint64_t)Ama) << 41) ^ (((uint64_t)Ama) >> (64 - 41)));
  Ase ^= De;
  Bsu = ((((uint64_t)Ase) << 2) ^ (((uint64_t)Ase) >> (64 - 2)));
  Esa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Esa;
  Ese = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ese;
  Esi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Esi;
  Eso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Eso;
  Esu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Esu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Eba ^= Da;
  Bba = Eba;
  Ege ^= De;
  Bbe = ((((uint64_t)Ege) << 44) ^ (((uint64_t)Ege) >> (64 - 44)));
  Eki ^= Di;
  Bbi = ((((uint64_t)Eki) << 43) ^ (((uint64_t)Eki) >> (64 - 43)));
  Emo ^= Do;
  Bbo = ((((uint64_t)Emo) << 21) ^ (((uint64_t)Emo) >> (64 - 21)));
  Esu ^= Du;
  Bbu = ((((uint64_t)Esu) << 14) ^ (((uint64_t)Esu) >> (64 - 14)));
  Aba = Bba ^ ((~Bbe) & Bbi);
  Aba ^= round_constants[19];
  Ca = Aba;
  Abe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Abe;
  Abi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Abi;
  Abo = Bbo ^ ((~Bbu) & Bba);
  Co = Abo;
  Abu = Bbu ^ ((~Bba) & Bbe);
  Cu = Abu;
  Ebo ^= Do;
  Bga = ((((uint64_t)Ebo) << 28) ^ (((uint64_t)Ebo) >> (64 - 28)));
  Egu ^= Du;
  Bge = ((((uint64_t)Egu) << 20) ^ (((uint64_t)Egu) >> (64 - 20)));
  Eka ^= Da;
  Bgi = ((((uint64_t)Eka) << 3) ^ (((uint64_t)Eka) >> (64 - 3)));
  Eme ^= De;
  Bgo = ((((uint64_t)Eme) << 45) ^ (((uint64_t)Eme) >> (64 - 45)));
  Esi ^= Di;
  Bgu = ((((uint64_t)Esi) << 61) ^ (((uint64_t)Esi) >> (64 - 61)));
  Aga = Bga ^ ((~Bge) & Bgi);
  Ca ^= Aga;
  Age = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Age;
  Agi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Agi;
  Ago = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ago;
  Agu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Agu;
  Ebe ^= De;
  Bka = ((((uint64_t)Ebe) << 1) ^ (((uint64_t)Ebe) >> (64 - 1)));
  Egi ^= Di;
  Bke = ((((uint64_t)Egi) << 6) ^ (((uint64_t)Egi) >> (64 - 6)));
  Eko ^= Do;
  Bki = ((((uint64_t)Eko) << 25) ^ (((uint64_t)Eko) >> (64 - 25)));
  Emu ^= Du;
  Bko = ((((uint64_t)Emu) << 8) ^ (((uint64_t)Emu) >> (64 - 8)));
  Esa ^= Da;
  Bku = ((((uint64_t)Esa) << 18) ^ (((uint64_t)Esa) >> (64 - 18)));
  Aka = Bka ^ ((~Bke) & Bki);
  Ca ^= Aka;
  Ake = Bke ^ ((~Bki) & Bko);
  Ce ^= Ake;
  Aki = Bki ^ ((~Bko) & Bku);
  Ci ^= Aki;
  Ako = Bko ^ ((~Bku) & Bka);
  Co ^= Ako;
  Aku = Bku ^ ((~Bka) & Bke);
  Cu ^= Aku;
  Ebu ^= Du;
  Bma = ((((uint64_t)Ebu) << 27) ^ (((uint64_t)Ebu) >> (64 - 27)));
  Ega ^= Da;
  Bme = ((((uint64_t)Ega) << 36) ^ (((uint64_t)Ega) >> (64 - 36)));
  Eke ^= De;
  Bmi = ((((uint64_t)Eke) << 10) ^ (((uint64_t)Eke) >> (64 - 10)));
  Emi ^= Di;
  Bmo = ((((uint64_t)Emi) << 15) ^ (((uint64_t)Emi) >> (64 - 15)));
  Eso ^= Do;
  Bmu = ((((uint64_t)Eso) << 56) ^ (((uint64_t)Eso) >> (64 - 56)));
  Ama = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ama;
  Ame = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Ame;
  Ami = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Ami;
  Amo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Amo;
  Amu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Amu;
  Ebi ^= Di;
  Bsa = ((((uint64_t)Ebi) << 62) ^ (((uint64_t)Ebi) >> (64 - 62)));
  Ego ^= Do;
  Bse = ((((uint64_t)Ego) << 55) ^ (((uint64_t)Ego) >> (64 - 55)));
  Eku ^= Du;
  Bsi = ((((uint64_t)Eku) << 39) ^ (((uint64_t)Eku) >> (64 - 39)));
  Ema ^= Da;
  Bso = ((((uint64_t)Ema) << 41) ^ (((uint64_t)Ema) >> (64 - 41)));
  Ese ^= De;
  Bsu = ((((uint64_t)Ese) << 2) ^ (((uint64_t)Ese) >> (64 - 2)));
  Asa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Asa;
  Ase = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ase;
  Asi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Asi;
  Aso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Aso;
  Asu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Asu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Aba ^= Da;
  Bba = Aba;
  Age ^= De;
  Bbe = ((((uint64_t)Age) << 44) ^ (((uint64_t)Age) >> (64 - 44)));
  Aki ^= Di;
  Bbi = ((((uint64_t)Aki) << 43) ^ (((uint64_t)Aki) >> (64 - 43)));
  Amo ^= Do;
  Bbo = ((((uint64_t)Amo) << 21) ^ (((uint64_t)Amo) >> (64 - 21)));
  Asu ^= Du;
  Bbu = ((((uint64_t)Asu) << 14) ^ (((uint64_t)Asu) >> (64 - 14)));
  Eba = Bba ^ ((~Bbe) & Bbi);
  Eba ^= round_constants[20];
  Ca = Eba;
  Ebe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Ebe;
  Ebi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Ebi;
  Ebo = Bbo ^ ((~Bbu) & Bba);
  Co = Ebo;
  Ebu = Bbu ^ ((~Bba) & Bbe);
  Cu = Ebu;
  Abo ^= Do;
  Bga = ((((uint64_t)Abo) << 28) ^ (((uint64_t)Abo) >> (64 - 28)));
  Agu ^= Du;
  Bge = ((((uint64_t)Agu) << 20) ^ (((uint64_t)Agu) >> (64 - 20)));
  Aka ^= Da;
  Bgi = ((((uint64_t)Aka) << 3) ^ (((uint64_t)Aka) >> (64 - 3)));
  Ame ^= De;
  Bgo = ((((uint64_t)Ame) << 45) ^ (((uint64_t)Ame) >> (64 - 45)));
  Asi ^= Di;
  Bgu = ((((uint64_t)Asi) << 61) ^ (((uint64_t)Asi) >> (64 - 61)));
  Ega = Bga ^ ((~Bge) & Bgi);
  Ca ^= Ega;
  Ege = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Ege;
  Egi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Egi;
  Ego = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ego;
  Egu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Egu;
  Abe ^= De;
  Bka = ((((uint64_t)Abe) << 1) ^ (((uint64_t)Abe) >> (64 - 1)));
  Agi ^= Di;
  Bke = ((((uint64_t)Agi) << 6) ^ (((uint64_t)Agi) >> (64 - 6)));
  Ako ^= Do;
  Bki = ((((uint64_t)Ako) << 25) ^ (((uint64_t)Ako) >> (64 - 25)));
  Amu ^= Du;
  Bko = ((((uint64_t)Amu) << 8) ^ (((uint64_t)Amu) >> (64 - 8)));
  Asa ^= Da;
  Bku = ((((uint64_t)Asa) << 18) ^ (((uint64_t)Asa) >> (64 - 18)));
  Eka = Bka ^ ((~Bke) & Bki);
  Ca ^= Eka;
  Eke = Bke ^ ((~Bki) & Bko);
  Ce ^= Eke;
  Eki = Bki ^ ((~Bko) & Bku);
  Ci ^= Eki;
  Eko = Bko ^ ((~Bku) & Bka);
  Co ^= Eko;
  Eku = Bku ^ ((~Bka) & Bke);
  Cu ^= Eku;
  Abu ^= Du;
  Bma = ((((uint64_t)Abu) << 27) ^ (((uint64_t)Abu) >> (64 - 27)));
  Aga ^= Da;
  Bme = ((((uint64_t)Aga) << 36) ^ (((uint64_t)Aga) >> (64 - 36)));
  Ake ^= De;
  Bmi = ((((uint64_t)Ake) << 10) ^ (((uint64_t)Ake) >> (64 - 10)));
  Ami ^= Di;
  Bmo = ((((uint64_t)Ami) << 15) ^ (((uint64_t)Ami) >> (64 - 15)));
  Aso ^= Do;
  Bmu = ((((uint64_t)Aso) << 56) ^ (((uint64_t)Aso) >> (64 - 56)));
  Ema = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ema;
  Eme = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Eme;
  Emi = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Emi;
  Emo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Emo;
  Emu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Emu;
  Abi ^= Di;
  Bsa = ((((uint64_t)Abi) << 62) ^ (((uint64_t)Abi) >> (64 - 62)));
  Ago ^= Do;
  Bse = ((((uint64_t)Ago) << 55) ^ (((uint64_t)Ago) >> (64 - 55)));
  Aku ^= Du;
  Bsi = ((((uint64_t)Aku) << 39) ^ (((uint64_t)Aku) >> (64 - 39)));
  Ama ^= Da;
  Bso = ((((uint64_t)Ama) << 41) ^ (((uint64_t)Ama) >> (64 - 41)));
  Ase ^= De;
  Bsu = ((((uint64_t)Ase) << 2) ^ (((uint64_t)Ase) >> (64 - 2)));
  Esa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Esa;
  Ese = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ese;
  Esi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Esi;
  Eso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Eso;
  Esu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Esu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Eba ^= Da;
  Bba = Eba;
  Ege ^= De;
  Bbe = ((((uint64_t)Ege) << 44) ^ (((uint64_t)Ege) >> (64 - 44)));
  Eki ^= Di;
  Bbi = ((((uint64_t)Eki) << 43) ^ (((uint64_t)Eki) >> (64 - 43)));
  Emo ^= Do;
  Bbo = ((((uint64_t)Emo) << 21) ^ (((uint64_t)Emo) >> (64 - 21)));
  Esu ^= Du;
  Bbu = ((((uint64_t)Esu) << 14) ^ (((uint64_t)Esu) >> (64 - 14)));
  Aba = Bba ^ ((~Bbe) & Bbi);
  Aba ^= round_constants[21];
  Ca = Aba;
  Abe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Abe;
  Abi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Abi;
  Abo = Bbo ^ ((~Bbu) & Bba);
  Co = Abo;
  Abu = Bbu ^ ((~Bba) & Bbe);
  Cu = Abu;
  Ebo ^= Do;
  Bga = ((((uint64_t)Ebo) << 28) ^ (((uint64_t)Ebo) >> (64 - 28)));
  Egu ^= Du;
  Bge = ((((uint64_t)Egu) << 20) ^ (((uint64_t)Egu) >> (64 - 20)));
  Eka ^= Da;
  Bgi = ((((uint64_t)Eka) << 3) ^ (((uint64_t)Eka) >> (64 - 3)));
  Eme ^= De;
  Bgo = ((((uint64_t)Eme) << 45) ^ (((uint64_t)Eme) >> (64 - 45)));
  Esi ^= Di;
  Bgu = ((((uint64_t)Esi) << 61) ^ (((uint64_t)Esi) >> (64 - 61)));
  Aga = Bga ^ ((~Bge) & Bgi);
  Ca ^= Aga;
  Age = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Age;
  Agi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Agi;
  Ago = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ago;
  Agu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Agu;
  Ebe ^= De;
  Bka = ((((uint64_t)Ebe) << 1) ^ (((uint64_t)Ebe) >> (64 - 1)));
  Egi ^= Di;
  Bke = ((((uint64_t)Egi) << 6) ^ (((uint64_t)Egi) >> (64 - 6)));
  Eko ^= Do;
  Bki = ((((uint64_t)Eko) << 25) ^ (((uint64_t)Eko) >> (64 - 25)));
  Emu ^= Du;
  Bko = ((((uint64_t)Emu) << 8) ^ (((uint64_t)Emu) >> (64 - 8)));
  Esa ^= Da;
  Bku = ((((uint64_t)Esa) << 18) ^ (((uint64_t)Esa) >> (64 - 18)));
  Aka = Bka ^ ((~Bke) & Bki);
  Ca ^= Aka;
  Ake = Bke ^ ((~Bki) & Bko);
  Ce ^= Ake;
  Aki = Bki ^ ((~Bko) & Bku);
  Ci ^= Aki;
  Ako = Bko ^ ((~Bku) & Bka);
  Co ^= Ako;
  Aku = Bku ^ ((~Bka) & Bke);
  Cu ^= Aku;
  Ebu ^= Du;
  Bma = ((((uint64_t)Ebu) << 27) ^ (((uint64_t)Ebu) >> (64 - 27)));
  Ega ^= Da;
  Bme = ((((uint64_t)Ega) << 36) ^ (((uint64_t)Ega) >> (64 - 36)));
  Eke ^= De;
  Bmi = ((((uint64_t)Eke) << 10) ^ (((uint64_t)Eke) >> (64 - 10)));
  Emi ^= Di;
  Bmo = ((((uint64_t)Emi) << 15) ^ (((uint64_t)Emi) >> (64 - 15)));
  Eso ^= Do;
  Bmu = ((((uint64_t)Eso) << 56) ^ (((uint64_t)Eso) >> (64 - 56)));
  Ama = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ama;
  Ame = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Ame;
  Ami = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Ami;
  Amo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Amo;
  Amu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Amu;
  Ebi ^= Di;
  Bsa = ((((uint64_t)Ebi) << 62) ^ (((uint64_t)Ebi) >> (64 - 62)));
  Ego ^= Do;
  Bse = ((((uint64_t)Ego) << 55) ^ (((uint64_t)Ego) >> (64 - 55)));
  Eku ^= Du;
  Bsi = ((((uint64_t)Eku) << 39) ^ (((uint64_t)Eku) >> (64 - 39)));
  Ema ^= Da;
  Bso = ((((uint64_t)Ema) << 41) ^ (((uint64_t)Ema) >> (64 - 41)));
  Ese ^= De;
  Bsu = ((((uint64_t)Ese) << 2) ^ (((uint64_t)Ese) >> (64 - 2)));
  Asa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Asa;
  Ase = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ase;
  Asi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Asi;
  Aso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Aso;
  Asu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Asu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Aba ^= Da;
  Bba = Aba;
  Age ^= De;
  Bbe = ((((uint64_t)Age) << 44) ^ (((uint64_t)Age) >> (64 - 44)));
  Aki ^= Di;
  Bbi = ((((uint64_t)Aki) << 43) ^ (((uint64_t)Aki) >> (64 - 43)));
  Amo ^= Do;
  Bbo = ((((uint64_t)Amo) << 21) ^ (((uint64_t)Amo) >> (64 - 21)));
  Asu ^= Du;
  Bbu = ((((uint64_t)Asu) << 14) ^ (((uint64_t)Asu) >> (64 - 14)));
  Eba = Bba ^ ((~Bbe) & Bbi);
  Eba ^= round_constants[22];
  Ca = Eba;
  Ebe = Bbe ^ ((~Bbi) & Bbo);
  Ce = Ebe;
  Ebi = Bbi ^ ((~Bbo) & Bbu);
  Ci = Ebi;
  Ebo = Bbo ^ ((~Bbu) & Bba);
  Co = Ebo;
  Ebu = Bbu ^ ((~Bba) & Bbe);
  Cu = Ebu;
  Abo ^= Do;
  Bga = ((((uint64_t)Abo) << 28) ^ (((uint64_t)Abo) >> (64 - 28)));
  Agu ^= Du;
  Bge = ((((uint64_t)Agu) << 20) ^ (((uint64_t)Agu) >> (64 - 20)));
  Aka ^= Da;
  Bgi = ((((uint64_t)Aka) << 3) ^ (((uint64_t)Aka) >> (64 - 3)));
  Ame ^= De;
  Bgo = ((((uint64_t)Ame) << 45) ^ (((uint64_t)Ame) >> (64 - 45)));
  Asi ^= Di;
  Bgu = ((((uint64_t)Asi) << 61) ^ (((uint64_t)Asi) >> (64 - 61)));
  Ega = Bga ^ ((~Bge) & Bgi);
  Ca ^= Ega;
  Ege = Bge ^ ((~Bgi) & Bgo);
  Ce ^= Ege;
  Egi = Bgi ^ ((~Bgo) & Bgu);
  Ci ^= Egi;
  Ego = Bgo ^ ((~Bgu) & Bga);
  Co ^= Ego;
  Egu = Bgu ^ ((~Bga) & Bge);
  Cu ^= Egu;
  Abe ^= De;
  Bka = ((((uint64_t)Abe) << 1) ^ (((uint64_t)Abe) >> (64 - 1)));
  Agi ^= Di;
  Bke = ((((uint64_t)Agi) << 6) ^ (((uint64_t)Agi) >> (64 - 6)));
  Ako ^= Do;
  Bki = ((((uint64_t)Ako) << 25) ^ (((uint64_t)Ako) >> (64 - 25)));
  Amu ^= Du;
  Bko = ((((uint64_t)Amu) << 8) ^ (((uint64_t)Amu) >> (64 - 8)));
  Asa ^= Da;
  Bku = ((((uint64_t)Asa) << 18) ^ (((uint64_t)Asa) >> (64 - 18)));
  Eka = Bka ^ ((~Bke) & Bki);
  Ca ^= Eka;
  Eke = Bke ^ ((~Bki) & Bko);
  Ce ^= Eke;
  Eki = Bki ^ ((~Bko) & Bku);
  Ci ^= Eki;
  Eko = Bko ^ ((~Bku) & Bka);
  Co ^= Eko;
  Eku = Bku ^ ((~Bka) & Bke);
  Cu ^= Eku;
  Abu ^= Du;
  Bma = ((((uint64_t)Abu) << 27) ^ (((uint64_t)Abu) >> (64 - 27)));
  Aga ^= Da;
  Bme = ((((uint64_t)Aga) << 36) ^ (((uint64_t)Aga) >> (64 - 36)));
  Ake ^= De;
  Bmi = ((((uint64_t)Ake) << 10) ^ (((uint64_t)Ake) >> (64 - 10)));
  Ami ^= Di;
  Bmo = ((((uint64_t)Ami) << 15) ^ (((uint64_t)Ami) >> (64 - 15)));
  Aso ^= Do;
  Bmu = ((((uint64_t)Aso) << 56) ^ (((uint64_t)Aso) >> (64 - 56)));
  Ema = Bma ^ ((~Bme) & Bmi);
  Ca ^= Ema;
  Eme = Bme ^ ((~Bmi) & Bmo);
  Ce ^= Eme;
  Emi = Bmi ^ ((~Bmo) & Bmu);
  Ci ^= Emi;
  Emo = Bmo ^ ((~Bmu) & Bma);
  Co ^= Emo;
  Emu = Bmu ^ ((~Bma) & Bme);
  Cu ^= Emu;
  Abi ^= Di;
  Bsa = ((((uint64_t)Abi) << 62) ^ (((uint64_t)Abi) >> (64 - 62)));
  Ago ^= Do;
  Bse = ((((uint64_t)Ago) << 55) ^ (((uint64_t)Ago) >> (64 - 55)));
  Aku ^= Du;
  Bsi = ((((uint64_t)Aku) << 39) ^ (((uint64_t)Aku) >> (64 - 39)));
  Ama ^= Da;
  Bso = ((((uint64_t)Ama) << 41) ^ (((uint64_t)Ama) >> (64 - 41)));
  Ase ^= De;
  Bsu = ((((uint64_t)Ase) << 2) ^ (((uint64_t)Ase) >> (64 - 2)));
  Esa = Bsa ^ ((~Bse) & Bsi);
  Ca ^= Esa;
  Ese = Bse ^ ((~Bsi) & Bso);
  Ce ^= Ese;
  Esi = Bsi ^ ((~Bso) & Bsu);
  Ci ^= Esi;
  Eso = Bso ^ ((~Bsu) & Bsa);
  Co ^= Eso;
  Esu = Bsu ^ ((~Bsa) & Bse);
  Cu ^= Esu;
  Da = Cu ^ ((((uint64_t)Ce) << 1) ^ (((uint64_t)Ce) >> (64 - 1)));
  De = Ca ^ ((((uint64_t)Ci) << 1) ^ (((uint64_t)Ci) >> (64 - 1)));
  Di = Ce ^ ((((uint64_t)Co) << 1) ^ (((uint64_t)Co) >> (64 - 1)));
  Do = Ci ^ ((((uint64_t)Cu) << 1) ^ (((uint64_t)Cu) >> (64 - 1)));
  Du = Co ^ ((((uint64_t)Ca) << 1) ^ (((uint64_t)Ca) >> (64 - 1)));
  Eba ^= Da;
  Bba = Eba;
  Ege ^= De;
  Bbe = ((((uint64_t)Ege) << 44) ^ (((uint64_t)Ege) >> (64 - 44)));
  Eki ^= Di;
  Bbi = ((((uint64_t)Eki) << 43) ^ (((uint64_t)Eki) >> (64 - 43)));
  Emo ^= Do;
  Bbo = ((((uint64_t)Emo) << 21) ^ (((uint64_t)Emo) >> (64 - 21)));
  Esu ^= Du;
  Bbu = ((((uint64_t)Esu) << 14) ^ (((uint64_t)Esu) >> (64 - 14)));
  Aba = Bba ^ ((~Bbe) & Bbi);
  Aba ^= round_constants[23];
  Abe = Bbe ^ ((~Bbi) & Bbo);
  Abi = Bbi ^ ((~Bbo) & Bbu);
  Abo = Bbo ^ ((~Bbu) & Bba);
  Abu = Bbu ^ ((~Bba) & Bbe);
  Ebo ^= Do;
  Bga = ((((uint64_t)Ebo) << 28) ^ (((uint64_t)Ebo) >> (64 - 28)));
  Egu ^= Du;
  Bge = ((((uint64_t)Egu) << 20) ^ (((uint64_t)Egu) >> (64 - 20)));
  Eka ^= Da;
  Bgi = ((((uint64_t)Eka) << 3) ^ (((uint64_t)Eka) >> (64 - 3)));
  Eme ^= De;
  Bgo = ((((uint64_t)Eme) << 45) ^ (((uint64_t)Eme) >> (64 - 45)));
  Esi ^= Di;
  Bgu = ((((uint64_t)Esi) << 61) ^ (((uint64_t)Esi) >> (64 - 61)));
  Aga = Bga ^ ((~Bge) & Bgi);
  Age = Bge ^ ((~Bgi) & Bgo);
  Agi = Bgi ^ ((~Bgo) & Bgu);
  Ago = Bgo ^ ((~Bgu) & Bga);
  Agu = Bgu ^ ((~Bga) & Bge);
  Ebe ^= De;
  Bka = ((((uint64_t)Ebe) << 1) ^ (((uint64_t)Ebe) >> (64 - 1)));
  Egi ^= Di;
  Bke = ((((uint64_t)Egi) << 6) ^ (((uint64_t)Egi) >> (64 - 6)));
  Eko ^= Do;
  Bki = ((((uint64_t)Eko) << 25) ^ (((uint64_t)Eko) >> (64 - 25)));
  Emu ^= Du;
  Bko = ((((uint64_t)Emu) << 8) ^ (((uint64_t)Emu) >> (64 - 8)));
  Esa ^= Da;
  Bku = ((((uint64_t)Esa) << 18) ^ (((uint64_t)Esa) >> (64 - 18)));
  Aka = Bka ^ ((~Bke) & Bki);
  Ake = Bke ^ ((~Bki) & Bko);
  Aki = Bki ^ ((~Bko) & Bku);
  Ako = Bko ^ ((~Bku) & Bka);
  Aku = Bku ^ ((~Bka) & Bke);
  Ebu ^= Du;
  Bma = ((((uint64_t)Ebu) << 27) ^ (((uint64_t)Ebu) >> (64 - 27)));
  Ega ^= Da;
  Bme = ((((uint64_t)Ega) << 36) ^ (((uint64_t)Ega) >> (64 - 36)));
  Eke ^= De;
  Bmi = ((((uint64_t)Eke) << 10) ^ (((uint64_t)Eke) >> (64 - 10)));
  Emi ^= Di;
  Bmo = ((((uint64_t)Emi) << 15) ^ (((uint64_t)Emi) >> (64 - 15)));
  Eso ^= Do;
  Bmu = ((((uint64_t)Eso) << 56) ^ (((uint64_t)Eso) >> (64 - 56)));
  Ama = Bma ^ ((~Bme) & Bmi);
  Ame = Bme ^ ((~Bmi) & Bmo);
  Ami = Bmi ^ ((~Bmo) & Bmu);
  Amo = Bmo ^ ((~Bmu) & Bma);
  Amu = Bmu ^ ((~Bma) & Bme);
  Ebi ^= Di;
  Bsa = ((((uint64_t)Ebi) << 62) ^ (((uint64_t)Ebi) >> (64 - 62)));
  Ego ^= Do;
  Bse = ((((uint64_t)Ego) << 55) ^ (((uint64_t)Ego) >> (64 - 55)));
  Eku ^= Du;
  Bsi = ((((uint64_t)Eku) << 39) ^ (((uint64_t)Eku) >> (64 - 39)));
  Ema ^= Da;
  Bso = ((((uint64_t)Ema) << 41) ^ (((uint64_t)Ema) >> (64 - 41)));
  Ese ^= De;
  Bsu = ((((uint64_t)Ese) << 2) ^ (((uint64_t)Ese) >> (64 - 2)));
  Asa = Bsa ^ ((~Bse) & Bsi);
  Ase = Bse ^ ((~Bsi) & Bso);
  Asi = Bsi ^ ((~Bso) & Bsu);
  Aso = Bso ^ ((~Bsu) & Bsa);
  Asu = Bsu ^ ((~Bsa) & Bse);
  state[0] = Aba;
  state[1] = Abe;
  state[2] = Abi;
  state[3] = Abo;
  state[4] = Abu;
  state[5] = Aga;
  state[6] = Age;
  state[7] = Agi;
  state[8] = Ago;
  state[9] = Agu;
  state[10] = Aka;
  state[11] = Ake;
  state[12] = Aki;
  state[13] = Ako;
  state[14] = Aku;
  state[15] = Ama;
  state[16] = Ame;
  state[17] = Ami;
  state[18] = Amo;
  state[19] = Amu;
  state[20] = Asa;
  state[21] = Ase;
  state[22] = Asi;
  state[23] = Aso;
  state[24] = Asu;
}
void memclear(void* const mem, const size_t len);
void memclear(void* const mem, const size_t len) {
  memset((uint8_t*)mem, 0, len);
}
static const uint64_t hash_absorbing = (0x37f0ec3b0aadfa9dULL);
static const uint64_t hash_squeezing = (0x8a6fe7c7dc8e8693ULL);
static const uint64_t flag_sha3_224 = (0x554b0edefdab2bdcULL);
static const uint64_t flag_sha3_256 = (0xa1368f2074321d98ULL);
static const uint64_t flag_sha3_384 = (0x66bd6e1188927c1bULL);
static const uint64_t flag_sha3_512 = (0xc5ed05c8db10db4eULL);
static const uint64_t flag_shake128 = (0xf4266a546a491160ULL);
static const uint64_t flag_shake256 = (0x129ad6509bc9bb8fULL);
int sha3_224_init(register keccak_sponge* const restrict sponge);
int sha3_224_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen);
int sha3_224_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen);
int sha3_224(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen);
int sha3_256_init(register keccak_sponge* const restrict sponge);
int sha3_256_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen);
int sha3_256_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen);
int sha3_256(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen);
int sha3_384_init(register keccak_sponge* const restrict sponge);
int sha3_384_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen);
int sha3_384_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen);
int sha3_384(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen);
int sha3_512_init(register keccak_sponge* const restrict sponge);
int sha3_512_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen);
int sha3_512_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen);
int sha3_512(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen);
static const uint8_t pad_end = 0x80;
static const uint8_t pad_shake = 0x1f;
static const uint8_t pad_sha = 0x06;
static inline int _hash_init(register keccak_sponge* const restrict sponge,
                             register const size_t rate,
                             register const uint64_t flags) {
  int err = _sponge_init(sponge, rate);
  if (err != 0) {
    return err;
  }
  sponge->flags = flags;
  return 0;
}
static inline int _hash_update(register keccak_sponge* const restrict sponge,
                               register const uint8_t* const restrict in,
                               register const size_t inlen,
                               register const uint64_t flags) {
  if (sponge->flags != flags) {
    do {
      fprintf(__stderrp,
              "%s:%u: soft rte: %s\n",
              "keccak/modes/hash/hash-impl.h",
              29,
              err_hash_flags);
      return errno_hash_flags;
    } while (0);
  }
  return keccak_sponge_absorb(sponge, in, inlen);
}
static inline int _hash_finalize(register keccak_sponge* const restrict sponge,
                                 register const uint8_t lastbyte,
                                 register const uint64_t oldflags,
                                 register const uint64_t newflags) {
  int err = _sponge_checkinv(sponge);
  if (err != 0) {
    return err;
  } else if (sponge->squeezed != 0) {
    do {
      fprintf(__stderrp,
              "%s:%u: soft rte: %s\n",
              "keccak/modes/hash/hash-impl.h",
              42,
              err_hash_finalized);
      return errno_hash_finalized;
    } while (0);
  } else if (sponge->flags != oldflags) {
    do {
      fprintf(__stderrp,
              "%s:%u: soft rte: %s\n",
              "keccak/modes/hash/hash-impl.h",
              44,
              err_hash_flags);
      return errno_hash_flags;
    } while (0);
  }
  register uint8_t* state = (uint8_t*)sponge->a;
  state[sponge->rate - 1] ^= pad_end;
  uint8_t byte = lastbyte;
  err = keccak_sponge_absorb(sponge, &byte, 1);
  keccakf(sponge->a);
  sponge->absorbed = 0;
  sponge->flags = newflags;
  return 0;
}
static inline int _hash_squeeze(register keccak_sponge* const restrict sponge,
                                register uint8_t* const restrict out,
                                register size_t outlen,
                                register const uint64_t flags) {
  int err = _sponge_checkinv(sponge);
  if (err != 0) {
    return err;
  } else if (sponge->absorbed != 0) {
    do {
      fprintf(__stderrp,
              "%s:%u: soft rte: %s\n",
              "keccak/modes/hash/hash-impl.h",
              78,
              err_hash_not_finalized);
      return errno_hash_not_finalized;
    } while (0);
  } else if (sponge->flags != flags) {
    do {
      fprintf(__stderrp,
              "%s:%u: soft rte: %s\n",
              "keccak/modes/hash/hash-impl.h",
              80,
              err_hash_flags);
      return errno_hash_flags;
    } while (0);
  }
  return keccak_sponge_squeeze(sponge, out, outlen);
}
int sha3_224_init(register keccak_sponge* const restrict sponge) {
  do {
    if (sponge == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 2813, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  int err = _hash_init(sponge, 200 - (28 * 2), flag_sha3_224 ^ hash_absorbing);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 2816, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  return 0;
}
int sha3_224_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen) {
  do {
    if (sponge == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 2841, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (in == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 2842, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  int err = _hash_update(sponge, in, inlen, flag_sha3_224 ^ hash_absorbing);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 2845, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  return 0;
}
int sha3_224_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen) {
  do {
    if (outlen != 28) {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 2876, err_digestlen);
        return errno_digestlen;
      } while (0);
    }
  } while (0);
  do {
    if (sponge == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 2877, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (out == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 2878, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  int err = _hash_finalize(
      sponge, pad_sha, flag_sha3_224 ^ hash_absorbing, flag_sha3_224 ^ hash_squeezing);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 2883, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  memclear((uint8_t*)sponge->a + 64, 200 - 64);
  err = _hash_squeeze(sponge, out, 28, flag_sha3_224 ^ hash_squeezing);
  memclear(sponge, 32 * 8);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 2891, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  return 0;
}
int sha3_224(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen) {
  do {
    if (out == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 2914, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (in == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 2915, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (outlen != 28) {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 2916, err_digestlen);
        return errno_digestlen;
      } while (0);
    }
  } while (0);
  keccak_sponge sponge;
  int err = 0;
  err = sha3_224_init(&sponge);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 2922, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  err = sha3_224_update(&sponge, in, inlen);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 2925, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  err = sha3_224_digest(&sponge, out, outlen);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 2928, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  memclear(&sponge, sizeof(sponge));
  return err;
}
int sha3_256_init(register keccak_sponge* const restrict sponge) {
  do {
    if (sponge == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 2965, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  int err = _hash_init(sponge, 200 - (32 * 2), flag_sha3_256 ^ hash_absorbing);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 2968, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  return 0;
}
int sha3_256_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen) {
  do {
    if (sponge == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 2993, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (in == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 2994, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  int err = _hash_update(sponge, in, inlen, flag_sha3_256 ^ hash_absorbing);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 2997, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  return 0;
}
int sha3_256_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen) {
  do {
    if (outlen != 32) {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3028, err_digestlen);
        return errno_digestlen;
      } while (0);
    }
  } while (0);
  do {
    if (sponge == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3029, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (out == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3030, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  int err = _hash_finalize(
      sponge, pad_sha, flag_sha3_256 ^ hash_absorbing, flag_sha3_256 ^ hash_squeezing);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3035, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  memclear((uint8_t*)sponge->a + 64, 200 - 64);
  err = _hash_squeeze(sponge, out, 32, flag_sha3_256 ^ hash_squeezing);
  memclear(sponge, 32 * 8);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3043, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  return 0;
}
int sha3_256(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen) {
  do {
    if (out == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3066, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (in == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3067, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (outlen != 32) {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3068, err_digestlen);
        return errno_digestlen;
      } while (0);
    }
  } while (0);
  keccak_sponge sponge;
  int err = 0;
  err = sha3_256_init(&sponge);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3074, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  err = sha3_256_update(&sponge, in, inlen);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3077, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  err = sha3_256_digest(&sponge, out, outlen);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3080, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  memclear(&sponge, sizeof(sponge));
  return err;
}
int sha3_384_init(register keccak_sponge* const restrict sponge) {
  do {
    if (sponge == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3117, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  int err = _hash_init(sponge, 200 - (48 * 2), flag_sha3_384 ^ hash_absorbing);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3120, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  return 0;
}
int sha3_384_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen) {
  do {
    if (sponge == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3145, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (in == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3146, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  int err = _hash_update(sponge, in, inlen, flag_sha3_384 ^ hash_absorbing);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3149, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  return 0;
}
int sha3_384_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen) {
  do {
    if (outlen != 48) {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3180, err_digestlen);
        return errno_digestlen;
      } while (0);
    }
  } while (0);
  do {
    if (sponge == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3181, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (out == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3182, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  int err = _hash_finalize(
      sponge, pad_sha, flag_sha3_384 ^ hash_absorbing, flag_sha3_384 ^ hash_squeezing);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3187, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  memclear((uint8_t*)sponge->a + 64, 200 - 64);
  err = _hash_squeeze(sponge, out, 48, flag_sha3_384 ^ hash_squeezing);
  memclear(sponge, 32 * 8);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3195, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  return 0;
}
int sha3_384(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen) {
  do {
    if (out == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3218, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (in == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3219, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (outlen != 48) {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3220, err_digestlen);
        return errno_digestlen;
      } while (0);
    }
  } while (0);
  keccak_sponge sponge;
  int err = 0;
  err = sha3_384_init(&sponge);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3226, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  err = sha3_384_update(&sponge, in, inlen);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3229, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  err = sha3_384_digest(&sponge, out, outlen);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3232, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  memclear(&sponge, sizeof(sponge));
  return err;
}
int sha3_512_init(register keccak_sponge* const restrict sponge) {
  do {
    if (sponge == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3269, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  int err = _hash_init(sponge, 200 - (64 * 2), flag_sha3_512 ^ hash_absorbing);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3272, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  return 0;
}
int sha3_512_update(register keccak_sponge* const restrict sponge,
                    register const uint8_t* const restrict in,
                    register const size_t inlen) {
  do {
    if (sponge == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3297, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (in == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3298, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  int err = _hash_update(sponge, in, inlen, flag_sha3_512 ^ hash_absorbing);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3301, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  return 0;
}
int sha3_512_digest(register keccak_sponge* const restrict sponge,
                    register uint8_t* const restrict out,
                    register const size_t outlen) {
  do {
    if (outlen != 64) {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3332, err_digestlen);
        return errno_digestlen;
      } while (0);
    }
  } while (0);
  do {
    if (sponge == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3333, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (out == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3334, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  int err = _hash_finalize(
      sponge, pad_sha, flag_sha3_512 ^ hash_absorbing, flag_sha3_512 ^ hash_squeezing);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3339, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  memclear((uint8_t*)sponge->a + 64, 200 - 64);
  err = _hash_squeeze(sponge, out, 64, flag_sha3_512 ^ hash_squeezing);
  memclear(sponge, 32 * 8);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3347, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  return 0;
}
int sha3_512(register uint8_t* const restrict out,
             register const size_t outlen,
             register const uint8_t* const restrict in,
             register const size_t inlen) {
  do {
    if (out == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3370, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (in == ((void*)0)) {
      do {
        fprintf(__stderrp, "%s:%u: hard rte: %s\n", "<stdin>", 3371, err_ptrnull);
        return errno_ptrnull;
      } while (0);
    }
  } while (0);
  do {
    if (outlen != 64) {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3372, err_digestlen);
        return errno_digestlen;
      } while (0);
    }
  } while (0);
  keccak_sponge sponge;
  int err = 0;
  err = sha3_512_init(&sponge);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3378, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  err = sha3_512_update(&sponge, in, inlen);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3381, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  err = sha3_512_digest(&sponge, out, outlen);
  do {
    if (err == 0) {
      break;
    } else {
      do {
        fprintf(__stderrp, "%s:%u: soft rte: %s\n", "<stdin>", 3384, err_sha3);
        return errno_sha3;
      } while (0);
    }
  } while (0);
  memclear(&sponge, sizeof(sponge));
  return err;
}
static inline int checktest(const char* const restrict description,
                            const uint8_t* const restrict known_answer,
                            const uint8_t* const restrict result,
                            const size_t bytelen) {
  printf("%s: ", description);
  if (memcmp(known_answer, result, bytelen) == 0) {
    printf("OKAY\n");
    return 0;
  } else {
    printf("FAIL\n");
    return -1;
  }
}
static inline void printkat(const uint8_t* const restrict msg,
                            const size_t msgbytelen,
                            const uint8_t* const restrict md,
                            const size_t mdlen) {
  printf("Len = %zu\n", msgbytelen * 8);
  printf("Msg = ");
  if (msgbytelen != 0) {
    for (size_t i = 0; i < msgbytelen; i++) {
      printf("%02X", msg[i]);
    }
  } else {
    printf("00");
  }
  printf("\n");
  printf("MD = ");
  for (size_t i = 0; i < mdlen; i++) {
    printf("%02X", md[i]);
  }
  printf("\n");
}
static const uint8_t sha3_224_len0[28] = {0x6b,
                                          0x4e,
                                          0x03,
                                          0x42,
                                          0x36,
                                          0x67,
                                          0xdb,
                                          0xb7,
                                          0x3b,
                                          0x6e,
                                          0x15,
                                          0x45,
                                          0x4f,
                                          0x0e,
                                          0xb1,
                                          0xab,
                                          0xd4,
                                          0x59,
                                          0x7f,
                                          0x9a,
                                          0x1b,
                                          0x07,
                                          0x8e,
                                          0x3f,
                                          0x5b,
                                          0x5a,
                                          0x6b,
                                          0xc7};
static const uint8_t sha3_256_len0[32] = {0xa7,
                                          0xff,
                                          0xc6,
                                          0xf8,
                                          0xbf,
                                          0x1e,
                                          0xd7,
                                          0x66,
                                          0x51,
                                          0xc1,
                                          0x47,
                                          0x56,
                                          0xa0,
                                          0x61,
                                          0xd6,
                                          0x62,
                                          0xf5,
                                          0x80,
                                          0xff,
                                          0x4d,
                                          0xe4,
                                          0x3b,
                                          0x49,
                                          0xfa,
                                          0x82,
                                          0xd8,
                                          0x0a,
                                          0x4b,
                                          0x80,
                                          0xf8,
                                          0x43,
                                          0x4a};
static const uint8_t sha3_384_len0[48] = {0x0c,
                                          0x63,
                                          0xa7,
                                          0x5b,
                                          0x84,
                                          0x5e,
                                          0x4f,
                                          0x7d,
                                          0x01,
                                          0x10,
                                          0x7d,
                                          0x85,
                                          0x2e,
                                          0x4c,
                                          0x24,
                                          0x85,
                                          0xc5,
                                          0x1a,
                                          0x50,
                                          0xaa,
                                          0xaa,
                                          0x94,
                                          0xfc,
                                          0x61,
                                          0x99,
                                          0x5e,
                                          0x71,
                                          0xbb,
                                          0xee,
                                          0x98,
                                          0x3a,
                                          0x2a,
                                          0xc3,
                                          0x71,
                                          0x38,
                                          0x31,
                                          0x26,
                                          0x4a,
                                          0xdb,
                                          0x47,
                                          0xfb,
                                          0x6b,
                                          0xd1,
                                          0xe0,
                                          0x58,
                                          0xd5,
                                          0xf0,
                                          0x04};
static const uint8_t sha3_512_len0[64] = {0xa6,
                                          0x9f,
                                          0x73,
                                          0xcc,
                                          0xa2,
                                          0x3a,
                                          0x9a,
                                          0xc5,
                                          0xc8,
                                          0xb5,
                                          0x67,
                                          0xdc,
                                          0x18,
                                          0x5a,
                                          0x75,
                                          0x6e,
                                          0x97,
                                          0xc9,
                                          0x82,
                                          0x16,
                                          0x4f,
                                          0xe2,
                                          0x58,
                                          0x59,
                                          0xe0,
                                          0xd1,
                                          0xdc,
                                          0xc1,
                                          0x47,
                                          0x5c,
                                          0x80,
                                          0xa6,
                                          0x15,
                                          0xb2,
                                          0x12,
                                          0x3a,
                                          0xf1,
                                          0xf5,
                                          0xf9,
                                          0x4c,
                                          0x11,
                                          0xe3,
                                          0xe9,
                                          0x40,
                                          0x2c,
                                          0x3a,
                                          0xc5,
                                          0x58,
                                          0xf5,
                                          0x00,
                                          0x19,
                                          0x9d,
                                          0x95,
                                          0xb6,
                                          0xd3,
                                          0xe3,
                                          0x01,
                                          0x75,
                                          0x85,
                                          0x86,
                                          0x28,
                                          0x1d,
                                          0xcd,
                                          0x26};
int test_sha3_224_len0(void);
int test_sha3_224_len0(void) {
  keccak_sponge sponge;
  uint8_t out[(224 / 8)] = {0};
  int err = 0;
  err |= sha3_224_init(&sponge);
  err |= sha3_224_digest(&sponge, out, (224 / 8));
  printkat(((void*)0), 0, out, (224 / 8));
  return err | checktest(
                   "SHA3-"
                   "224"
                   "('')",
                   sha3_224_len0,
                   out,
                   (224 / 8));
}
int test_sha3_256_len0(void);
int test_sha3_256_len0(void) {
  keccak_sponge sponge;
  uint8_t out[(256 / 8)] = {0};
  int err = 0;
  err |= sha3_256_init(&sponge);
  err |= sha3_256_digest(&sponge, out, (256 / 8));
  printkat(((void*)0), 0, out, (256 / 8));
  return err | checktest(
                   "SHA3-"
                   "256"
                   "('')",
                   sha3_256_len0,
                   out,
                   (256 / 8));
}
int test_sha3_384_len0(void);
int test_sha3_384_len0(void) {
  keccak_sponge sponge;
  uint8_t out[(384 / 8)] = {0};
  int err = 0;
  err |= sha3_384_init(&sponge);
  err |= sha3_384_digest(&sponge, out, (384 / 8));
  printkat(((void*)0), 0, out, (384 / 8));
  return err | checktest(
                   "SHA3-"
                   "384"
                   "('')",
                   sha3_384_len0,
                   out,
                   (384 / 8));
}
int test_sha3_512_len0(void);
int test_sha3_512_len0(void) {
  keccak_sponge sponge;
  uint8_t out[(512 / 8)] = {0};
  int err = 0;
  err |= sha3_512_init(&sponge);
  err |= sha3_512_digest(&sponge, out, (512 / 8));
  printkat(((void*)0), 0, out, (512 / 8));
  return err | checktest(
                   "SHA3-"
                   "512"
                   "('')",
                   sha3_512_len0,
                   out,
                   (512 / 8));
}
int main(void) {
  int err = 0;
  do {
    err |= test_sha3_224_len0();
    ((void)0);
  } while (0);
  do {
    err |= test_sha3_256_len0();
    ((void)0);
  } while (0);
  do {
    err |= test_sha3_384_len0();
    ((void)0);
  } while (0);
  do {
    err |= test_sha3_512_len0();
    ((void)0);
  } while (0);
  return err;
}
