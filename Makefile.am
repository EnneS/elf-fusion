ACLOCAL_AMFLAGS = -I m4

AM_CFLAGS=-Wall -Werror -g -std=c99
AM_CFLAGS+=-D DEBUG
AM_CFLAGS+=-D WARNING
AM_CFLAGS+=-D BIG_ENDIAN_SIMULATOR
# Uncomment if performance when running with -DDEBUG is an issue
# Warning, if uncommented, issuing calls to debug functions during options
# parsing might result in debug flag incorrectly set to 0 for some files
#AM_CFLAGS+=-D CACHE_DEBUG_FLAG

LDADD=-lpthread


SUBDIRS=
SUBDIRS+=. Examples_loader

bin_PROGRAMS=
bin_PROGRAMS+=ARM_runner_example
bin_PROGRAMS+=fusion
bin_PROGRAMS+=affichage_executable

COMMON=debug.h debug.c util.h util.c

EXTRA_DIST=filtre.pl
SIMULATOR_INTERFACE=csapp.h csapp.c scanner.h scanner.l gdb_protocol.h gdb_protocol.c arm_simulator_interface.h arm_simulator_interface.c

ARM_runner_example_SOURCES=$(COMMON) $(SIMULATOR_INTERFACE) ARM_runner_example.c
fusion_SOURCES=$(COMMON) fusion.c elf_reader.h elf_reader.c elf_file.h elf_file.c affichage_elf.h affichage_elf.c elf_fusion.h elf_fusion.c hashtable.h hashtable.c elf_file_reverse.h elf_file_reverse.c elf_writer.h elf_writer.c
affichage_executable_SOURCES=$(COMMON) affichage_executable.c affichage_elf.h affichage_elf.c elf_reader.c elf_reader.h hashtable.h hashtable.c elf_file.h elf_file.c elf_file_reverse.h elf_file_reverse.c elf_writer.h elf_writer.c

EXTRA_DIST+=sample_run.sh

