if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_C_FLAGS "-std=c99")
endif()

list(APPEND src
	"fips202/sha3.c"
	"fips202/shake.c"
	"constructions/sponge.c"
	"keccak/keccakf.c"
	"keccak/keccakf-1600/keccakf-opt64.c"
	)

list(APPEND public_hdrs
	"../keccak.h"
	)

list(APPEND hdr
	"config.h"
	"keccak/keccak-1600.h"
	"../libutil/libutil.h"
	"constructions/sponge.h"
	"fips202/flags.h"
	"rte/check-impl.h"
	"modes/hash/hash-impl.h"
	"constructions/sponge-impl.h"
	"utils/c11shim.h"
	)

set(libtype STATIC)

add_library(libkeccak ${libtype} ${src} ${public_hdrs} ${hdr})

set_target_properties(libkeccak PROPERTIES
	INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/.."
	INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/.."
	COMPILE_DEFINITIONS NO_LIBUTIL
	PUBLIC_HEADER "${public_hdrs}"
#	VERSION 0.6.0
	PREFIX ""
	LIBFILENAME "libkeccak")
