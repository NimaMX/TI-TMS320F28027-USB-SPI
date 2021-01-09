################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
src/%.obj: ../src/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/cl2000" -v28 -ml -mt --include_path="C:/Users/Nima_/workspace_v10/TI-TMS320F28027-USB-TTL/inc" --include_path="C:/Users/Nima_/workspace_v10/TI-TMS320F28027-USB-TTL" --include_path="C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/include" --include_path="C:/ti/c2000/C2000Ware_3_03_00_00/device_support/f2802x/common/include" --include_path="C:/ti/c2000/C2000Ware_3_03_00_00/device_support/f2802x/headers/include" --advice:performance=all --define=_DEBUG --define=_FLASH --define=LARGE_MODEL -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="src/$(basename $(<F)).d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


