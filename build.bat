@echo off
set "SOURCE_FILES=fir.c sample_buffer.c result_buffer.c testbench.c"
set "FLAGS=--clock 50MHz --quartus-compile"

if not "%1"=="" (
  set "TARGET=%1"
) else (
  set "TARGET=emulate"
)

if "%TARGET%" == "emulate" (
  set "CMD=i++ -march=x86-64 -o %TARGET%.exe" 
) else if "%TARGET%" == "fpga" (
  set "CMD=i++ -march=MAX10 %FLAGS% -o %TARGET%.exe"
)
set "CMD=%CMD:""="%"

echo %CMD% %SOURCE_FILES%
echo:
%CMD% %SOURCE_FILES%



