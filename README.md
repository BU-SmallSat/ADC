#ADC Controller

This repo contains the SIMULINK model for ADC for the MULE. 

## Building
The model must export C code, using the Linaro toolchain, and the current settings in the project, using Simulink's code generation feature. 

Once generated (into `ADC_ert_rtw\`), then: 
```bash
diff python_interop/ert_main.c ADC_ert_rtw/ert_main.c  #and take changes from python_interop! 
cp python_interop/pythonInterface.c ADC_ert_rtw/
```

then build ADC.elf

```bash
cd ADC_ert_rtw
./ADC.mk
```

N.B.: the `LINARO_TOOLCHAIN_4_8` environment variable must be correctly set for this to work.  On @gvoysey's system, the correct value is `C:\MATLAB\SupportPackages\R2016a\Linaro-Toolchain-v4.8\bin`.

The resulting file `ADC.elf` can be moved to a provisioned BBB and executed from the command line, or by using the included python test script (`python_interop/testADC.py`). 

## Provisioning a BBB

In order to be able to run SIMULINK code on a BBB, Matlab has to upload a bunch of header files.  Pester @gvoysey to have this done. 
