使用"RsaD.N.Patch" 技术.

1.劫持Dll:VProtect.dll

2.VProtect
-Hook GetAdaptersInfo 解码.
-Hook DWORD(Base+0x12B450)+0x3DFD.
-修改RsaD.N.