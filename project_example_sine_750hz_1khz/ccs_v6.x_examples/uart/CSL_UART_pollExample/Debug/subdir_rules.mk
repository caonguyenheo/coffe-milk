################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
aic3204_loop_mic_in.obj: ../aic3204_loop_mic_in.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/bin/cl55" -v5505 --memory_model=large -g --include_path="C:/ti/ccsv8/tools/compiler/c5500_4.4.1/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c5500" --include_path="D:/coffe-milk/project_example_sine_750hz_1khz/inc" --include_path="D:/coffe-milk/project_example_sine_750hz_1khz/ccs_v6.x_examples/uart/CSL_UART_pollExample/Debug" --define="_DEBUG" --define=c5505 --diag_warning=225 --ptrdiff_size=16 --algebraic --asm_source=algebraic --preproc_with_compile --preproc_dependency="aic3204_loop_mic_in.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

aic3204_loop_stereo_in1.obj: ../aic3204_loop_stereo_in1.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/bin/cl55" -v5505 --memory_model=large -g --include_path="C:/ti/ccsv8/tools/compiler/c5500_4.4.1/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c5500" --include_path="D:/coffe-milk/project_example_sine_750hz_1khz/inc" --include_path="D:/coffe-milk/project_example_sine_750hz_1khz/ccs_v6.x_examples/uart/CSL_UART_pollExample/Debug" --define="_DEBUG" --define=c5505 --diag_warning=225 --ptrdiff_size=16 --algebraic --asm_source=algebraic --preproc_with_compile --preproc_dependency="aic3204_loop_stereo_in1.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

aic3204_loop_stereo_in2.obj: ../aic3204_loop_stereo_in2.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/bin/cl55" -v5505 --memory_model=large -g --include_path="C:/ti/ccsv8/tools/compiler/c5500_4.4.1/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c5500" --include_path="D:/coffe-milk/project_example_sine_750hz_1khz/inc" --include_path="D:/coffe-milk/project_example_sine_750hz_1khz/ccs_v6.x_examples/uart/CSL_UART_pollExample/Debug" --define="_DEBUG" --define=c5505 --diag_warning=225 --ptrdiff_size=16 --algebraic --asm_source=algebraic --preproc_with_compile --preproc_dependency="aic3204_loop_stereo_in2.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

aic3204_test.obj: ../aic3204_test.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/bin/cl55" -v5505 --memory_model=large -g --include_path="C:/ti/ccsv8/tools/compiler/c5500_4.4.1/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c5500" --include_path="D:/coffe-milk/project_example_sine_750hz_1khz/inc" --include_path="D:/coffe-milk/project_example_sine_750hz_1khz/ccs_v6.x_examples/uart/CSL_UART_pollExample/Debug" --define="_DEBUG" --define=c5505 --diag_warning=225 --ptrdiff_size=16 --algebraic --asm_source=algebraic --preproc_with_compile --preproc_dependency="aic3204_test.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

aic3204_tone_headphone.obj: ../aic3204_tone_headphone.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/bin/cl55" -v5505 --memory_model=large -g --include_path="C:/ti/ccsv8/tools/compiler/c5500_4.4.1/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c5500" --include_path="D:/coffe-milk/project_example_sine_750hz_1khz/inc" --include_path="D:/coffe-milk/project_example_sine_750hz_1khz/ccs_v6.x_examples/uart/CSL_UART_pollExample/Debug" --define="_DEBUG" --define=c5505 --diag_warning=225 --ptrdiff_size=16 --algebraic --asm_source=algebraic --preproc_with_compile --preproc_dependency="aic3204_tone_headphone.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

aic3204_tone_stereo_out.obj: ../aic3204_tone_stereo_out.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/bin/cl55" -v5505 --memory_model=large -g --include_path="C:/ti/ccsv8/tools/compiler/c5500_4.4.1/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c5500" --include_path="D:/coffe-milk/project_example_sine_750hz_1khz/inc" --include_path="D:/coffe-milk/project_example_sine_750hz_1khz/ccs_v6.x_examples/uart/CSL_UART_pollExample/Debug" --define="_DEBUG" --define=c5505 --diag_warning=225 --ptrdiff_size=16 --algebraic --asm_source=algebraic --preproc_with_compile --preproc_dependency="aic3204_tone_stereo_out.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv8/tools/compiler/c5500_4.4.1/bin/cl55" -v5505 --memory_model=large -g --include_path="C:/ti/ccsv8/tools/compiler/c5500_4.4.1/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c5500" --include_path="D:/coffe-milk/project_example_sine_750hz_1khz/inc" --include_path="D:/coffe-milk/project_example_sine_750hz_1khz/ccs_v6.x_examples/uart/CSL_UART_pollExample/Debug" --define="_DEBUG" --define=c5505 --diag_warning=225 --ptrdiff_size=16 --algebraic --asm_source=algebraic --preproc_with_compile --preproc_dependency="main.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


