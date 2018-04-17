################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv8/tools/compiler/c5500_4.4.1

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./IdleLoop.obj" \
"./codec_aic3254.obj" \
"./csl_i2c_ioExpander.obj" \
"./pll_control.obj" \
"../VC5505_I2S.cmd" \
$(GEN_CMDS__FLAG) \
-l"Debug/C55XXCSL_LP.lib" \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
CSL_I2S_IdleLoop_Out.out \

EXE_OUTPUTS__QUOTED += \
"CSL_I2S_IdleLoop_Out.out" \

BIN_OUTPUTS += \
CSL_I2S_IdleLoop_Out.hex \

BIN_OUTPUTS__QUOTED += \
"CSL_I2S_IdleLoop_Out.hex" \


# All Target
all: CSL_I2S_IdleLoop_Out.out

# Tool invocations
CSL_I2S_IdleLoop_Out.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C5500 Linker'
	"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/bin/cl55" -vcore:3.3 --memory_model=large -g --define="_DEBUG" --define=c5505 --diag_warning=225 --gen_func_subsections=on --ptrdiff_size=16 --algebraic --asm_source=algebraic -z -m"CSL_I2S_IdleLoop_Out.map" --stack_size=0x200 --heap_size=0x400 -i"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/lib" -i"D:/Digital signal process_TMS320C5517/HUONG_DAN_SU_DUNG_BOARD/project_example_sine_750hz_1khz/build" -i"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/include" -i"C:/ti/bios_5_42_02_10/packages/ti/rtdx/lib/c5500" -i"C:/ti/bios_5_42_02_10/packages/ti/bios/lib" -i"D:/Digital signal process_TMS320C5517/HUONG_DAN_SU_DUNG_BOARD/project_example_sine_750hz_1khz/ccs_v6.x_examples/C55XXCSL_LP" -i"D:/Digital signal process_TMS320C5517/HUONG_DAN_SU_DUNG_BOARD/project_example_sine_750hz_1khz/ccs_v6.x_examples/i2s/CSL_I2S_IdleLoop" --reread_libs --warn_sections --xml_link_info="CSL_I2S_IdleLoop_Out_linkInfo.xml" --rom_model --sys_stacksize=0x200 -o "CSL_I2S_IdleLoop_Out.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

CSL_I2S_IdleLoop_Out.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: C5500 Hex Utility'
	"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/bin/hex55"  -o "CSL_I2S_IdleLoop_Out.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_CMDS__QUOTED)$(GEN_MISC_FILES__QUOTED)$(BIN_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)$(GEN_HDRS__QUOTED)
	-$(RM) "IdleLoop.obj" "codec_aic3254.obj" "csl_i2c_ioExpander.obj" "pll_control.obj" 
	-$(RM) "IdleLoop.d" "codec_aic3254.d" "csl_i2c_ioExpander.d" "pll_control.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

