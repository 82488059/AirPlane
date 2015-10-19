@echo on
for /f "tokens=*" %%a in ('dir /ad /b /s^|sort /r') do (
if /i "%%~na"=="debug.win32" rd /q /s "%%~fsa"
)

pause