.SUFFIXES: .$(EXT) .asm
COMP=../diy # compiler
EXT=diy # file extension: .$(EXT)
LIB=diy # runtime library: lib$(LIB).a
RUN=../run # runtime directory
AS=nasm -felf32 # assembler command
LD=ld -melf_i386 # loader command

SRC= basic.diy basic2.diy basic3.diy basic4.diy basic5.diy basic6.diy basic7.diy basic8.diy basic9.diy basic10.diy basic11.diy \
	basic12.diy basic13.diy optm.diy optm2.diy optm3.diy optm4.diy basic14.diy basic15.diy
EXE=$(SRC:%.diy=%)

all:: compiler runtime $(EXE)

compiler::
	make -C ..

runtime::
	make -C $(RUN)

%:%.$(EXT)
	$(COMP) $<
	$(AS) $*.asm -o $*.o
	$(LD) -o $@ $*.o -L$(RUN) -l$(LIB)

clean::
	rm -f *.o *.asm *.s *~ $(EXE)
