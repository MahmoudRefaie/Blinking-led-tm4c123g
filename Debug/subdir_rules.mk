################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/ti/ccs1120/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/LEARNING/udacity-advanced-embedded/project-1/Blinking-led-tm4c123g" --include_path="D:/LEARNING/udacity-advanced-embedded/project-1/Blinking-led-tm4c123g/APPLICATION" --include_path="D:/LEARNING/udacity-advanced-embedded/project-1/Blinking-led-tm4c123g/APPLICATION/Inc" --include_path="D:/LEARNING/udacity-advanced-embedded/project-1/Blinking-led-tm4c123g/Config" --include_path="D:/LEARNING/udacity-advanced-embedded/project-1/Blinking-led-tm4c123g/HAL/Inc" --include_path="D:/LEARNING/udacity-advanced-embedded/project-1/Blinking-led-tm4c123g/MCAL/Inc" --include_path="D:/LEARNING/udacity-advanced-embedded/project-1/Blinking-led-tm4c123g/SERVICE" --include_path="D:/ti/ccs1120/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


