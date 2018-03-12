XCOPY /Y "Bin\x64\Debug\XShaderCompiler.lib" "..\Source\3rdParty\Windows\x64\Debug\"
XCOPY /Y "Bin\x64\Debug\XShaderCompiler.pdb" "..\Source\3rdParty\Windows\x64\Debug\"
XCOPY /Y "Bin\x64\Release\XShaderCompiler.lib" "..\Source\3rdParty\Windows\x64\Release\"

XCOPY /Y "Bin\Win32\Debug\XShaderCompiler.lib" "..\Source\3rdParty\Windows\Win32\Debug\"
XCOPY /Y "Bin\Win32\Debug\XShaderCompiler.pdb" "..\Source\3rdParty\Windows\Win32\Debug\"
XCOPY /Y "Bin\Win32\Release\XShaderCompiler.lib" "..\Source\3rdParty\Windows\Win32\Release\"

xcopy /s /Y "inc" "..\Source\Source\ThirdParty"

pause
