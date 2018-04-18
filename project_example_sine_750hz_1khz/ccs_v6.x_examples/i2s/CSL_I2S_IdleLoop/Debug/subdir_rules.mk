################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
IdleLoop.obj: ../IdleLoop.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/bin/cl55" -vcore:3.3 --memory_model=large -g --include_path="C:/ti/ccsv8/tools/compiler/c5500_4.4.1/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c5500" --include_path="D:/Digital signal process_TMS320C5517/HUONG_DAN_SU_DUNG_BOARD/project_example_sine_750hz_1khz/inc" --include_path="D:/Digital signal process_TMS320C5517/HUONG_DAN_SU_DUNG_BOARD/project_example_sine_750hz_1khz/ccs_v6.x_examples/i2s/CSL_I2S_IdleLoop/Debug" --define="_DEBUG" --define=c5505 --diag_warning=225 --gen_func_subsections=on --ptrdiff_size=16 --algebraic --asm_source=algebraic --preproc_with_compile --preproc_dependency="IdleLoop.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

codec_aic3254.obj: ../codec_aic3254.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/bin/cl55" -vcore:3.3 --memory_model=large -g --include_path="C:/ti/ccsv8/tools/compiler/c5500_4.4.1/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c5500" --include_path="D:/Digital signal process_TMS320C5517/HUONG_DAN_SU_DUNG_BOARD/project_example_sine_750hz_1khz/inc" --include_path="D:/Digital signal process_TMS320C5517/HUONG_DAN_SU_DUNG_BOARD/project_example_sine_750hz_1khz/ccs_v6.x_examples/i2s/CSL_I2S_IdleLoop/Debug" --define="_DEBUG" --define=c5505 --diag_warning=225 --gen_func_subsections=on --ptrdiff_size=16 --algebraic --asm_source=algebraic --preproc_with_compile --preproc_dependency="codec_aic3254.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

csl_i2c_ioExpander.obj: ../csl_i2c_ioExpander.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/bin/cl55" -vcore:3.3 --memory_model=large -g --include_path="C:/ti/ccsv8/tools/compiler/c5500_4.4.1/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c5500" --include_path="D:/Digital signal process_TMS320C5517/HUONG_DAN_SU_DUNG_BOARD/project_example_sine_750hz_1khz/inc" --include_path="D:/Digital signal process_TMS320C5517/HUONG_DAN_SU_DUNG_BOARD/project_example_sine_750hz_1khz/ccs_v6.x_examples/i2s/CSL_I2S_IdleLoop/Debug" --define="_DEBUG" --define=c5505 --diag_warning=225 --gen_func_subsections=on --ptrdiff_size=16 --algebraic --asm_source=algebraic --preproc_with_compile --preproc_dependency="csl_i2c_ioExpander.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

pll_control.obj: ../pll_control.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/bin/cl55" -vcore:3.3 --memory_model=large -g --include_path="C:/ti/ccsv8/tools/compiler/c5500_4.4.1/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c5500" --include_path="D:/Digital signal process_TMS320C5517/HUONG_DAN_SU_DUNG_BOARD/project_example_sine_750hz_1khz/inc" --include_path="D:/Digital signal process_TMS320C5517/HUONG_DAN_SU_DUNG_BOARD/project_example_sine_750hz_1khz/ccs_v6.x_examples/i2s/CSL_I2S_IdleLoop/Debug" --define="_DEBUG" --define=c5505 --diag_warning=225 --gen_func_subsections=on --ptrdiff_size=16 --algebraic --asm_source=algebraic --preproc_with_compile --preproc_dependency="pll_control.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


