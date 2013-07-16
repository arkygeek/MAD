;try1.nsi

;----------------------------------------------------

; The name of the installer
Name "MACSURadapter1"

; The file to write
Outfile "MACSURadapter1.exe"

; The default installation directory
InstallDir $DESKTOP\MACSURadapter1

; Request application privileges for Windows Vista
RequestExecutionLevel user

;----------------------------------------------------

; Pages

Page directory
Page instfiles

;----------------------------------------------------

; The stuff to install
Section "MAD1"

; Set output path to installation directory
SetOutPath $INSTDIR

; Put file there
File "try1.nsi"
  
; end the section
SectionEnd
