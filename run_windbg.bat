REM modify below path to where windbg exists folder
SET PATH=%PATH%;"C:\Program Files (x86)\Windows Kits\10\Debuggers\x64"

windbg -g -o uv.exe
