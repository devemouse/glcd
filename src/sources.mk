###########################################################################
# Dawid Bazan <dawidbazan@gmail.com>
# Dariusz Synowiec <devemouse@gmail.com>
# 
# sources.mk
###########################################################################


###########################################################################
# All subdirectories where source code exists must be defined here
###########################################################################
SUBDIRS = $(sort \
			 src/app \
			 src/lib/CMSIS/Core \
			 src/lib/system \
			 src/lib/lamp \
			 src/lib/SystemTick \
			 src/lib/drv/LPC176x \
			 src/lib/drv/LPC176x/spi \
			 src/lib/drv/LPC176x/ssp \
			 src/lib/drv/LPC176x/pinsel \
			 src/lib/drv/LPC176x/clkpwr \
			 )

###########################################################################
# Sources to be build
###########################################################################
# List C source fies. File suffix must be *.c with case sensitive
CSRCS =  $(sort \
			 core_cm3.c \
			 system_LPC17xx.c \
			 syscalls.c \
			)

# List C++ source files. File suffix must be *.cpp with case sensitive
CPPSRCS = $(sort \
			 main.cpp \
			 spi.cpp \
			 ssp.cpp \
			 pinsel.cpp \
			 lamp.cpp \
			 SystemTick.cpp \
			 startup_LPC17xx.cpp \
			 lgdp4531.cpp \
			 clkpwr.cpp \
			 )

# List Assembler source files. File suffix must be *.s with case sensitive
ASRCS = $(sort \
		  )

###########################################################################
# Linker script
###########################################################################
LINKERSCRIPT = LPC1769.ld

