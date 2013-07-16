;try2b.nsi

;----------------------------------------------------

; The name of the installer
Name "MACSURadapter2"

; The file to write
Outfile "MACSURadapter2.exe"

; The default installation directory
InstallDir $DESKTOP\MACSURadapter2

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\MACSURadapter2" "Install_Dir"

; Request application privileges for Windows Vista
RequestExecutionLevel user

;----------------------------------------------------

; Pages

Page components
Page directory
Page instfiles

UninstPage uninstConfirm
UninstPage instfiles

;----------------------------------------------------

; The stuff to install
Section "MAD2"

; Set output path to installation directory
SetOutPath $INSTDIR

; Put file there
File "try2.nsi"
  
  ; Write the installation path into the registry
  WriteRegStr HKLM SOFTWARE\MACSURadapter2 "Install_Dir" "$INSTDIR"
  
  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\MAD2" "DisplayName" "MACSUR adapter2"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\MAD2" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\MAD2" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\MAD2" "NoRepair" 1
  WriteUninstaller "uninstall.exe"
  
; end the section
SectionEnd

; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"

  CreateDirectory "$SMPROGRAMS\MAD2"
  CreateShortCut "$SMPROGRAMS\MAD2\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  CreateShortCut "$SMPROGRAMS\MAD2\MAD2 (MakeMAD2).lnk" "$INSTDIR\try2.nsi" "" "$INSTDIR\try2.nsi" 0
  
SectionEnd

;--------------------------------------------------------

; Uninstaller

Section "Uninstall"
  
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\MAD2"
  DeleteRegKey HKLM SOFTWARE\MACSURadapter2

  ; Remove files and uninstaller
  Delete $INSTDIR\try2.nsi
  Delete $INSTDIR\uninstall.exe

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\MAD2\*.*"

  ; Remove directories used
  RMDir "$SMPROGRAMS\MAD2"
  RMDir "$INSTDIR"

SectionEnd