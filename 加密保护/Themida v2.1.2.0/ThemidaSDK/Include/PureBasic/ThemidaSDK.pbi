; include file to use the Themida macros in PureBasic applications

Macro CODEREPLACE_START 
!DB 0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20
EndMacro

Macro CODEREPLACE_END 
  !DB 0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20
EndMacro

Macro ENCODE_START 
  !DB 0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20
EndMacro

Macro ENCODE_END 
  !DB 0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20
EndMacro

Macro CLEAR_START 
  !DB 0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20
EndMacro

Macro CLEAR_END 
  !DB 0xEB, 0x15, 0x57, 0x4C, 0x20, 0x20, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0
EndMacro

Macro VM_START 
  !DB 0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20
EndMacro

Macro VM_END 
  !DB 0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x0D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20
EndMacro

Macro UNREGISTERED_START 
  !DB 0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20
EndMacro

Macro UNREGISTERED_END 
  !DB 0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20
EndMacro

Macro REGISTERED_START 
  !DB 0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20
EndMacro

Macro REGISTERED_END 
  !DB 0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20
EndMacro

Macro UNPROTECTED_START 
  !DB 0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20
EndMacro

Macro UNPROTECTED_END 
  !DB 0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20
EndMacro

Macro CHECK_PROTECTION(var, val)
!DB 0xEB, 0x10, 0x67, 0x31, 0xAB, 0x91, 0x7A, 0x71, 0x8B, 0x8A, 0xBD, 0x7A, 0x11, 0xBC, 0x00, 0x00, 0x00, 0x00
!push val
!pop dword [var]
!DB 0xEB, 0x0C, 0xBD, 0x7A, 0x11, 0xBC, 0x7A, 0x71, 0x8B, 0x8A, 0x67, 0x31,0xAB, 0x91
EndMacro

Macro CHECK_CODE_INTEGRITY(var, val)
!DB 0xEB, 0x10, 0x67, 0x31, 0xAB, 0x91, 0x7A, 0x71, 0x8B, 0x8A, 0xBD, 0x7A, 0x11, 0xBC, 0x01, 0x00, 0x00, 0x00
!push val
!pop dword [var]
!DB 0xEB, 0x0C, 0xBD, 0x7A, 0x11, 0xBC, 0x7A, 0x71, 0x8B, 0x8A, 0x67, 0x31,0xAB, 0x91
EndMacro

Macro CHECK_REGISTRATION(var, val)
!DB 0xEB, 0x10, 0x67, 0x31, 0xAB, 0x91, 0x7A, 0x71, 0x8B, 0x8A, 0xBD, 0x7A, 0x11, 0xBC, 0x02, 0x00, 0x00, 0x00
!push val
!pop dword [var]
!DB 0xEB, 0x0C, 0xBD, 0x7A, 0x11, 0xBC, 0x7A, 0x71, 0x8B, 0x8A, 0x67, 0x31,0xAB, 0x91
EndMacro

Macro CHECK_VIRTUAL_PC(var, val)
!DB 0xEB, 0x10, 0x67, 0x31, 0xAB, 0x91, 0x7A, 0x71, 0x8B, 0x8A, 0xBD, 0x7A, 0x11, 0xBC, 0x03, 0x00, 0x00, 0x00
!push val
!pop dword [var]
!DB 0xEB, 0x0C, 0xBD, 0x7A, 0x11, 0xBC, 0x7A, 0x71, 0x8B, 0x8A, 0x67, 0x31,0xAB, 0x91
EndMacro

