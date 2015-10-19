@echo on

del *.aps /f/s/q /a
del *.old /f/s/q /a
del *.suo /f/s/q /a
del *.sdf /f/s/q /a
del UpgradeLog.XML /f/s/q /a

for /f "tokens=*" %%a in ('dir /ad /b /s^|sort /r') do (
if /i "%%~na"=="_UpgradeReport_Files" rd /q /s "%%~fsa"
)

for /f "tokens=*" %%a in ('dir /ad /b /s^|sort /r') do (
if /i "%%~na"=="debug" rd /q /s "%%~fsa"
)

for /f "tokens=*" %%a in ('dir /ad /b /s^|sort /r') do (
if /i "%%~na"=="ipch" rd /q /s "%%~fsa"
)

for /f "tokens=*" %%a in ('dir /ad /b /s^|sort /r') do (
if /i "%%~na"=="Release" rd /q /s "%%~fsa"
)

pause
