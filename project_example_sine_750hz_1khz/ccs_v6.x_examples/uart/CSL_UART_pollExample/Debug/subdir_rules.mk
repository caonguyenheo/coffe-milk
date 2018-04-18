################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
csl_uart_polled_example.obj: ../csl_uart_polled_example.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/bin/cl55" -v5505 --memory_model=large -g --include_path="C:/ti/ccsv8/tools/compiler/c5500_4.4.1/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c5500" --include_path="D:/Digital signal process_TMS320C5517/HUONG_DAN_SU_DUNG_BOARD/project_example_sine_750hz_1khz/inc" --include_path="D:/Digital signal process_TMS320C5517/HUONG_DAN_SU_DUNG_BOARD/project_example_sine_750hz_1khz/ccs_v6.x_examples/uart/CSL_UART_pollExample/Debug" --define="_DEBUG" --define=c5505 --diag_warning=225 --ptrdiff_size=16 --algebraic --asm_source=algebraic --preproc_with_compile --preproc_dependency="csl_uart_polled_example.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


