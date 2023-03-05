###########################################################################
## Makefile generated for component 'stm32f4discovery_gettingstarted'. 
## 
## Makefile     : stm32f4discovery_gettingstarted.mk
## Generated on : Sat Mar 04 19:53:41 2023
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/stm32f4discovery_gettingstarted.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file

PRODUCT_NAME              = stm32f4discovery_gettingstarted
MAKEFILE                  = stm32f4discovery_gettingstarted.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2021b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2021b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/eahil/Documents/GitHub/smart-cpr-algo/src/cpr-algo
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ARM Cortex-M
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
COMPILER_COMMAND_FILE     = stm32f4discovery_gettingstarted_comp.rsp
CMD_FILE                  = stm32f4discovery_gettingstarted.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU Tools for ARM Embedded Processors
# Supported Version(s):    
# ToolchainInfo Version:   2021b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# TARGET_LOAD_CMD_ARGS
# TARGET_LOAD_CMD
# MW_GNU_ARM_TOOLS_PATH
# FDATASECTIONS_FLG

#-----------
# MACROS
#-----------

LIBGCC                    = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-libgcc-file-name}
LIBC                      = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libc.a}
LIBM                      = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libm.a}
PRODUCT_NAME_WITHOUT_EXTN = $(basename $(PRODUCT))
PRODUCT_BIN               = $(PRODUCT_NAME_WITHOUT_EXTN).bin
PRODUCT_HEX               = $(PRODUCT_NAME_WITHOUT_EXTN).hex
CPFLAGS                   = -O binary
SHELL                     = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: GNU ARM Assembler
AS_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AS = "$(AS_PATH)/arm-none-eabi-gcc"

# C Compiler: GNU ARM C Compiler
CC_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CC = "$(CC_PATH)/arm-none-eabi-gcc"

# Linker: GNU ARM Linker
LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
LD = "$(LD_PATH)/arm-none-eabi-g++"

# C++ Compiler: GNU ARM C++ Compiler
CPP_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP = "$(CPP_PATH)/arm-none-eabi-g++"

# C++ Linker: GNU ARM C++ Linker
CPP_LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP_LD = "$(CPP_LD_PATH)/arm-none-eabi-g++"

# Archiver: GNU ARM Archiver
AR_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AR = "$(AR_PATH)/arm-none-eabi-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Binary Converter: Binary Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = "$(OBJCOPYPATH)/arm-none-eabi-objcopy"

# Hex Converter: Hex Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = "$(OBJCOPYPATH)/arm-none-eabi-objcopy"

# Executable Size: Executable Size
EXESIZEPATH = $(MW_GNU_ARM_TOOLS_PATH)
EXESIZE = "$(EXESIZEPATH)/arm-none-eabi-size"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /f/q
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
ASFLAGS              = -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = $(FDATASECTIONS_FLG) \
                       -Wall \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -c \
                       -O0
CPPFLAGS             = -std=gnu++14 \
                       -fno-rtti \
                       -fno-exceptions \
                       $(FDATASECTIONS_FLG) \
                       -Wall \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -c \
                       -O0
CPP_LDFLAGS          = -Wl,--gc-sections \
                       -Wl,-Map="$(PRODUCT_NAME).map"
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       =
EXESIZE_FLAGS        = $(PRODUCT)
EXECUTE_FLAGS        =
OBJCOPYFLAGS_HEX     = -O ihex $(PRODUCT) $(PRODUCT_HEX)
LDFLAGS              = -Wl,--gc-sections \
                       -Wl,-Map="$(PRODUCT_NAME).map"
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/stm32f4discovery_gettingstarted.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DUSE_FULL_LL_DRIVER -DSTM32F429xx -DUSE_HAL_DRIVER
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0
DEFINES_SKIPFORSIL = -DXCP_CUSTOM_PLATFORM -DXCP_MEM_DAQ_RESERVED_POOL_BLOCKS_NUMBER=10 -D__FPU_PRESENT=1U -D__FPU_USED=1U -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=stm32f4discovery_gettingstarted -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/stm32f4discovery_gettingstarted_ert_rtw/stm32f4discovery_gettingstarted.c $(START_DIR)/stm32f4discovery_gettingstarted_ert_rtw/stm32f4discovery_gettingstarted_data.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/shared/supportpackages/stm32/src/overrideHALDelay.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/armcortexmbase/scheduler/src/SysTickScheduler.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Core/Src/main.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Core/Src/stm32f4xx_it.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Core/Src/stm32f4xx_hal_msp.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Core/Src/stm32f4xx_hal_timebase_tim.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_tim.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Core/Src/system_stm32f4xx.c C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/startup_stm32f429xx.s C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/syscalls.c

MAIN_SRC = $(START_DIR)/stm32f4discovery_gettingstarted_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = stm32f4discovery_gettingstarted.o stm32f4discovery_gettingstarted_data.o overrideHALDelay.o SysTickScheduler.o m3m4m4f_multitasking.o main.o stm32f4xx_it.o stm32f4xx_hal_msp.o stm32f4xx_hal_timebase_tim.o stm32f4xx_ll_gpio.o stm32f4xx_ll_dma.o stm32f4xx_ll_i2c.o stm32f4xx_ll_rcc.o stm32f4xx_ll_utils.o stm32f4xx_ll_exti.o stm32f4xx_hal_rcc.o stm32f4xx_hal_rcc_ex.o stm32f4xx_hal_flash.o stm32f4xx_hal_flash_ex.o stm32f4xx_hal_flash_ramfunc.o stm32f4xx_hal_gpio.o stm32f4xx_hal_dma_ex.o stm32f4xx_hal_dma.o stm32f4xx_hal_pwr.o stm32f4xx_hal_pwr_ex.o stm32f4xx_hal_cortex.o stm32f4xx_hal.o stm32f4xx_hal_exti.o stm32f4xx_ll_spi.o stm32f4xx_hal_tim.o stm32f4xx_hal_tim_ex.o stm32f4xx_ll_tim.o stm32f4xx_ll_usart.o system_stm32f4xx.o startup_stm32f429xx.o syscalls.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = C:/ProgramData/MATLAB/SupportPackages/R2021b/3P.instrset/cmsis.instrset/CMSIS/DSP/Lib/GCC/libarm_cortexM4lf_math.a

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nano.specs --specs=nosys.specs  -T"C:\ProgramData\MATLAB\SupportPackages\R2021b\toolbox\target\supportpackages\stm32f4discovery\stm32f4discoveryexamples\stm32f4discovery_gettingstarted\SW4STM32\stm32f4discovery_gettingstarted\STM32F429ZITx_FLASH.ld"

CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nano.specs --specs=nosys.specs  -T"C:\ProgramData\MATLAB\SupportPackages\R2021b\toolbox\target\supportpackages\stm32f4discovery\stm32f4discoveryexamples\stm32f4discovery_gettingstarted\SW4STM32\stm32f4discovery_gettingstarted\STM32F429ZITx_FLASH.ld"

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nano.specs --specs=nosys.specs  -T"C:\ProgramData\MATLAB\SupportPackages\R2021b\toolbox\target\supportpackages\stm32f4discovery\stm32f4discoveryexamples\stm32f4discovery_gettingstarted\SW4STM32\stm32f4discovery_gettingstarted\STM32F429ZITx_FLASH.ld"

LDFLAGS += $(LDFLAGS_SKIPFORSIL)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mthumb-interwork -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry Reset_Handler --specs=nano.specs --specs=nosys.specs  -T"C:\ProgramData\MATLAB\SupportPackages\R2021b\toolbox\target\supportpackages\stm32f4discovery\stm32f4discoveryexamples\stm32f4discovery_gettingstarted\SW4STM32\stm32f4discovery_gettingstarted\STM32F429ZITx_FLASH.ld"

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


ALL_DEPS:=$(patsubst %.o,%.dep,$(ALL_OBJS))
all:

ifndef DISABLE_GCC_FUNCTION_DATA_SECTIONS
FDATASECTIONS_FLG := -ffunction-sections -fdata-sections
endif



-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include ../../codertarget_assembly_flags.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)
	@echo "### Invoking postbuild tool "Binary Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_BIN)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "Hex Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_HEX)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "Executable Size" ..."
	$(EXESIZE) $(EXESIZE_FLAGS)
	@echo "### Done invoking postbuild tool."


download : postbuild


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/stm32f4discovery_gettingstarted_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/stm32f4discovery_gettingstarted_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/stm32f4discovery_gettingstarted_ert_rtw/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/stm32f4discovery_gettingstarted_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/stm32f4discovery_gettingstarted_ert_rtw/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/stm32f4discovery_gettingstarted_ert_rtw/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/stm32f4discovery_gettingstarted_ert_rtw/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ert_main.o : $(START_DIR)/stm32f4discovery_gettingstarted_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4discovery_gettingstarted.o : $(START_DIR)/stm32f4discovery_gettingstarted_ert_rtw/stm32f4discovery_gettingstarted.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4discovery_gettingstarted_data.o : $(START_DIR)/stm32f4discovery_gettingstarted_ert_rtw/stm32f4discovery_gettingstarted_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


overrideHALDelay.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/shared/supportpackages/stm32/src/overrideHALDelay.c
	$(CC) $(CFLAGS) -o "$@" "$<"


SysTickScheduler.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/armcortexmbase/scheduler/src/SysTickScheduler.c
	$(CC) $(CFLAGS) -o "$@" "$<"


m3m4m4f_multitasking.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c
	$(CC) $(CFLAGS) -o "$@" "$<"


main.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Core/Src/main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_it.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Core/Src/stm32f4xx_it.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_msp.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Core/Src/stm32f4xx_hal_msp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_timebase_tim.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Core/Src/stm32f4xx_hal_timebase_tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_gpio.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_dma.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_i2c.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_rcc.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_utils.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_exti.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_rcc.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_rcc_ex.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_flash.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_flash_ex.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_flash_ramfunc.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_gpio.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_dma_ex.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_dma.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_pwr.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_pwr_ex.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_cortex.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_exti.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_spi.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_tim.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_hal_tim_ex.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_tim.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_tim.c
	$(CC) $(CFLAGS) -o "$@" "$<"


stm32f4xx_ll_usart.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.c
	$(CC) $(CFLAGS) -o "$@" "$<"


system_stm32f4xx.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/../Core/Src/system_stm32f4xx.c
	$(CC) $(CFLAGS) -o "$@" "$<"


startup_stm32f429xx.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/startup_stm32f429xx.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


syscalls.o : C:/ProgramData/MATLAB/SupportPackages/R2021b/toolbox/target/supportpackages/stm32f4discovery/stm32f4discoveryexamples/stm32f4discovery_gettingstarted/SW4STM32/syscalls.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_BIN = $(OBJCOPYFLAGS_BIN)"
	@echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	@echo "### EXESIZE_FLAGS = $(EXESIZE_FLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *.dep
	$(ECHO) "### Deleted all derived files."


