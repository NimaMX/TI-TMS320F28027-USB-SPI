################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/bsp/%.obj: ../src/bsp/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/opt/ti/ccs1011/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/cl2000" -v28 -ml -mt --include_path="/home/nima/workspace_v10/TI-TMS320F28027-USB-TTL/inc" --include_path="/home/nima/workspace_v10/TI-TMS320F28027-USB-TTL" --include_path="/opt/ti/ccs1011/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/include" --include_path="/opt/ti/c2000/C2000Ware_3_03_00_00/device_support/f2802x/common/include" --include_path="/opt/ti/c2000/C2000Ware_3_03_00_00/device_support/f2802x/headers/include" --advice:performance=all --define=_DEBUG --define=_FLASH --define=LARGE_MODEL -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="src/bsp/$(basename $(<F)).d_raw" --obj_directory="src/bsp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


