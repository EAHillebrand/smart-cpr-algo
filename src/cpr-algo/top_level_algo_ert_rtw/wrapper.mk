###########################################################################
## Makefile for calling other makefiles
###########################################################################

###########################################################################
## MACROS
###########################################################################
###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################
## Toolchain Name:          Arduino ARM MBED


###########################################################################
## TOOLCHAIN MACROS
###########################################################################
# ARDUINO_ROOT = Intrinsically defined
# ARDUINO_PACKAGES_TOOLS_ROOT = Intrinsically defined
# ARDUINO_PORT = Intrinsically defined
# ARDUINO_MCU = Intrinsically defined
# ARDUINO_BAUD = Intrinsically defined
# ARDUINO_PROTOCOL = Intrinsically defined
# ARDUINO_F_CPU = Intrinsically defined
SHELL = %SystemRoot%/system32/cmd.exe
PRODUCT_HEX = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_BIN = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).bin
ARDUINO_TOOLS = $(ARDUINO_PACKAGES_TOOLS_ROOT)/tools/arm-none-eabi-gcc/7-2017q4/bin
SLIB_PATH = C:/Users/eahil/DOCUME~1/MATLAB/R2021b/ARDUIN~1/ARDUIN~2/FASTER~1


#-------------------------
# Directives/Utilities
#-------------------------
RM                        = 
ECHO                      = echo
MV                        = 


#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Arduino ARM Assembler
AS_PATH := $(ARDUINO_TOOLS)
AS := $(AS_PATH)/arm-none-eabi-gcc

# C Compiler: Arduino ARM C Compiler
CC_PATH := $(ARDUINO_TOOLS)
CC := $(CC_PATH)/arm-none-eabi-gcc

# Linker: Arduino ARM Linker
LD_PATH = $(ARDUINO_TOOLS)
LD := $(LD_PATH)/arm-none-eabi-g++


# C++ Compiler: Arduino ARM C++ Compiler
CPP_PATH := $(ARDUINO_TOOLS)
CPP := $(CPP_PATH)/arm-none-eabi-g++

# C++ Linker: Arduino ARM C++ Linker
CPP_LD_PATH = $(ARDUINO_TOOLS)
CPP_LD := $(CPP_LD_PATH)/arm-none-eabi-g++

# Archiver: Arduino ARM Archiver
AR_PATH := $(ARDUINO_TOOLS)
AR := $(AR_PATH)/arm-none-eabi-ar

# Indexing: Arduino ARM MBED Ranlib
RANLIB_PATH := $(ARDUINO_TOOLS)
RANLIB := $(RANLIB_PATH)/arm-none-eabi-ranlib

# Execute: Execute
EXECUTE = $(PRODUCT)


# Builder: GMAKE Utility
MAKE_PATH = C:/Program Files/MATLAB/R2021b/bin/win64
MAKE = $(MAKE_PATH)/gmake


#--------------------------------------
# Faster Runs Build Configuration
#--------------------------------------
ARFLAGS              = ruvs
ASFLAGS              = -MMD -MP  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = -c -w -g -Os -nostdlib \
                       -MMD -MP 
CPPFLAGS             = -c -w -g -Os -nostdlib \
                       -MMD -MP 
CPP_LDFLAGS          =  -Os -Wl,-Map="$(PRODUCT_NAME).map" -Wl,--gc-sections
CPP_SHAREDLIB_LDFLAGS =
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -Os -Wl,-Map="$(PRODUCT_NAME).map" -Wl,--gc-sections
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =


###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################
#---------------
# C Compiler
#---------------
CFLAGS_SKIPFORSIL = "@$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/defines.txt" "@$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/cxxflags.txt"  -DARDUINO_ARCH_NRF52840 -MMD -mcpu=cortex-m4 -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -DARDUINO=108019 -DARDUINO_ARDUINO_NANO33BLE -DARDUINO_ARCH_MBED "-I$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/cores/arduino" "-I$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE" "-I$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/cores/arduino/api/deprecated" -g3  "-iprefix$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/cores/arduino" "@$(ARDUINO_TARGET_ROOT)/include/MW_arduinoBLESense_Incl.txt" 
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)
CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)
#-----------------
# C++ Compiler
#-----------------
CPPFLAGS_SKIPFORSIL = "@$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/defines.txt" "@$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/cxxflags.txt"  -DARDUINO_ARCH_NRF52840 -MMD -mcpu=cortex-m4 -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -DARDUINO=108019 -DARDUINO_ARDUINO_NANO33BLE -DARDUINO_ARCH_MBED "-I$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/cores/arduino" "-I$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE" "-I$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/cores/arduino/api/deprecated" -g3  "-iprefix$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/cores/arduino" "@$(ARDUINO_TARGET_ROOT)/include/MW_arduinoBLESense_Incl.txt" 
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)
CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)
#---------------
# C++ Linker
#---------------
CPP_LDFLAGS_SKIPFORSIL = -Wl,--gc-sections -w -Wl,--as-needed "@$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/ldflags.txt" "-T$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/linker_script.ld" --specs=nano.specs --specs=nosys.specs -Wl,--whole-archive "$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/libs/libcc_310_core.a" "$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/libs/libcc_310_ext.a" "$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/libs/libcc_310_trng.a" "$(ARDUINO_TARGET_ROOT)/src/MW_libmbed.a" -Wl,--no-whole-archive -Wl,--start-group -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys -Wl,--end-group
CPP_LDFLAGS += $(CPP_LDFLAGS_SKIPFORSIL)
#------------------------------
# C++ Shared Library Linker
#------------------------------
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -Wl,--gc-sections -w -Wl,--as-needed "@$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/ldflags.txt" "-T$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/linker_script.ld" --specs=nano.specs --specs=nosys.specs -Wl,--whole-archive "$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/libs/libcc_310_core.a" "$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/libs/libcc_310_ext.a" "$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/libs/libcc_310_trng.a" "$(ARDUINO_TARGET_ROOT)/src/MW_libmbed.a" -Wl,--no-whole-archive -Wl,--start-group -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys -Wl,--end-group
CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)
#-----------
# Linker
#-----------
LDFLAGS_SKIPFORSIL = -Wl,--gc-sections -w -Wl,--as-needed "@$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/ldflags.txt" "-T$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/linker_script.ld" --specs=nano.specs --specs=nosys.specs -Wl,--whole-archive "$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/libs/libcc_310_core.a" "$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/libs/libcc_310_ext.a" "$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/libs/libcc_310_trng.a" "$(ARDUINO_TARGET_ROOT)/src/MW_libmbed.a" -Wl,--no-whole-archive -Wl,--start-group -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys -Wl,--end-group
LDFLAGS += $(LDFLAGS_SKIPFORSIL)
#--------------------------
# Shared Library Linker
#--------------------------
SHAREDLIB_LDFLAGS_SKIPFORSIL = -Wl,--gc-sections -w -Wl,--as-needed "@$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/ldflags.txt" "-T$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/linker_script.ld" --specs=nano.specs --specs=nosys.specs -Wl,--whole-archive "$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/libs/libcc_310_core.a" "$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/libs/libcc_310_ext.a" "$(ARDUINO_MBED_ROOT)/hardware/mbed/$(MBED_LIB_VERSION)/variants/ARDUINO_NANO33BLE/libs/libcc_310_trng.a" "$(ARDUINO_TARGET_ROOT)/src/MW_libmbed.a" -Wl,--no-whole-archive -Wl,--start-group -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys -Wl,--end-group
SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_SKIPFORSIL)


-include codertarget_assembly_flags.mk


###########################################################################
## Define Macros
###########################################################################
SLMKPATH=C:/PROGRA~3/MATLAB/SUPPOR~1/R2021b/toolbox/target/SUPPOR~1/ARDUIN~2/STATIC~1
MODELMK=top_level_algo.mk
SLIB_PATH=C:/Users/eahil/DOCUME~1/MATLAB/R2021b/ARDUIN~1/ARDUIN~2/FASTER~1
VARIANT_HEADER_PATH=$(ARDUINO_MBED_ROOT)/hardware/mbed/1.3.2/variants/ARDUINO_NANO33BLE
ARDUINO_SKETCHBOOK_ROOT=C:/PROGRA~3/MATLAB/SUPPOR~1/R2021b/aIDE/portable/SKETCH~1/LIBRAR~1
ARDUINO_BASESUPPORTPKG_ROOT=C:/PROGRA~3/MATLAB/SUPPOR~1/R2021b/toolbox/target/SUPPOR~1/ARDUIN~2
ARDUINO_MBED_BOARDS=1


###########################################################################
## Export Variables
###########################################################################
export AR
export RANLIB
export AS
export CC
export CPP
export ASFLAGS
export CFLAGS
export CPPFLAGS
export ARFLAGS
export SLIB_PATH
export VARIANT_HEADER_PATH
export ARDUINO_SKETCHBOOK_ROOT
export ARDUINO_BASESUPPORTPKG_ROOT
export ARDUINO_MBED_BOARDS


###########################################################################
## PHONY TARGETS
###########################################################################
.PHONY : all
all : 
	@echo "### Generating static library."
	"$(MAKE)" -j7 -C "$(SLMKPATH)" SHELL="$(SHELL)" -f mbedcore.mk all
	"$(MAKE)" -j7 SHELL="$(SHELL)" -f "$(MODELMK)" all

