;MACSUR adapter
;try3.nsi

;NSIS Modern User Interface

;____________________________________________________
; Include Modern UI

  !include "MUI2.nsh"

;----------------------------------------------------
; General

  ; The name of the installer
  Name "MACSURadapter3"

  ; The file to write
  Outfile "MACSURadapter3.exe"

  ; The default installation directory
  InstallDir $DESKTOP\MACSURadapter3

  ; Registry key to check for directory (so if you install again, it will 
  ; overwrite the old one automatically)
  InstallDirRegKey HKLM "Software\MACSURadapter3" "Install_Dir"

  ; Request application privileges for Windows Vista
  RequestExecutionLevel user

;---------------------------------------------------- 
; Interface Settings
  
  !define MUI_ABORTWARNING  

;----------------------------------------------------
; Pages

  !insertmacro MUI_PAGE_LICENSE "${NSISDIR}\Docs\Modern UI\License.txt"
  !insertmacro MUI_PAGE_COMPONENTS
  !insertmacro MUI_PAGE_DIRECTORY
  !insertmacro MUI_PAGE_INSTFILES
  
  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_INSTFILES

;----------------------------------------------------
; Languages (chooses automatically right language?)

  !insertmacro MUI_LANGUAGE "English"
  !insertmacro MUI_LANGUAGE "German"
  !insertmacro MUI_LANGUAGE "Dutch"
  !insertmacro MUI_LANGUAGE "French"

;----------------------------------------------------
; Installer Sections

; The stuff to install
Section "MAD3"

  ; Set output path to installation directory
  SetOutPath "$INSTDIR"

  ; Put file there
  File "try3.nsi"
  
  ; Write the installation path into the registry
  WriteRegStr HKLM SOFTWARE\MACSURadapter3 "Install_Dir" "$INSTDIR"
  
  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\MAD3" "DisplayName" "MACSUR adapter3"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\MAD3" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\MAD3" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\MAD3" "NoRepair" 1
  WriteUninstaller "uninstall.exe"
  
; end the section
SectionEnd

; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"

  CreateDirectory "$SMPROGRAMS\MAD3"
  CreateShortCut "$SMPROGRAMS\MAD3\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  CreateShortCut "$SMPROGRAMS\MAD3\MAD3 (MakeMAD3).lnk" "$INSTDIR\try3.nsi" "" "$INSTDIR\try3.nsi" 0
  
SectionEnd

;--------------------------------------------------------
; Uninstaller Section

Section "Uninstall"
  
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\MAD3"
  DeleteRegKey HKLM SOFTWARE\MACSURadapter3

  ; Remove files and uninstaller
  Delete $INSTDIR\try3.nsi
  Delete $INSTDIR\uninstall.exe

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\MAD3\*.*"

  ; Remove directories used
  RMDir "$SMPROGRAMS\MAD3"
  RMDir "$INSTDIR"

SectionEnd