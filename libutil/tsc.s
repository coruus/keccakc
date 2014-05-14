[bits 64]
[CPU intelnop]

align 32
global tsc
tsc:

  rdtsc
  shl rdx, 32
  or  rax, rdx
  ret	0

align 32
; partially serializing; see Intel 64 reference
global tscp
tscp:
  rdtscp
  shl rdx, 32
  or  rax, rdx
  ret 0

align 32
; totally serializing
global tscm
tscm:
  mfence
  rdtsc
  shl rdx, 32
  or  rax, rdx
  ret 0
