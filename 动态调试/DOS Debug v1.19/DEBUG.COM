�UT��?b��?������������]���1��b�  ����3
�����	�
��j���������$���i��|n��������������.�����~���G�D��-����- �I��J��J8��M��H���a��_���_���`���_���`8��c|��b���b���c0��`���_���_���a��_���`���c0��b���b���c|��_T��bL��a���`���_��b ��b ��bL��ah��`8��ѯv�=�1H���1����D�����|���-l�������q��<�����;r�@l��@l����D@5�Af��A��A������������n�@l���A���A���A���@����@����@����@����@����A���A���A���A���A���@����@����Ӟ@<�@ ���A ��A���BP��B4���3�d@<�@ ��A����@l��@l���A���S��@5�Af��A��A�����!�����@5�Af��A��A����P����A��A����p����С����-��@l���A���������M����_����@���@l��@l��@l��@l��@l��@l��@l����E����������s��@5�Af��A��A�����A�@l��@l��@l���@l��@l��@l�����������������@l����A���@l���@l��@l����PA��������A����������������BR�5�����@5�Af��A��A����0�a���$@5�Af��A��A��������@l���A���A����A ��A���BP��B4���A���A����@���.�@l��@��@l��@l��@l��@l��Hp��d����������M�N�C�F4������ ���� \�<�=�=(��N`������=t�#{�t �"K�r��!��r��#/�s��!��r����C��"��s<�%��v��%C�u��$��u��%��v4�#/�s��!��r��"K�r��#{�t �"K�r��"��s��%��v4�$��u��%C�u��%��v��!��rX�$��uP�$�t��"��s��!g�r�$_�u�$_�u�$��uP�#��tl�"��s<�E�E8�x��E��/4��L��:������:7���w�����)���;���U�Ａ����ｑ���3���3\�C?���C?�B��B����B����B��B��B����B����B���L����/�0E(d(�)�*S4n6��b�U��V_�V�V��V��W��0����0�����������8���������4�*��������O�����d���DzF��� ����� ����1	wT�|�~q��������.��Ѵ���i�	+�{��~%��������.P����P�ʱ��;Ȝ�����WǸ���ţ���e��Z��������9�9����<D<2��~x�.��Ƈ����I��k����-���J��A��&�.�6�>�d�eƇ����I����4�˕����Q��F�$��3����3���y��w���w���x���w���x+��{o��z���z���{#��x���w���w���y��w���xw��{#��z���z���{o��wG��z?��y���xw��v���y���y���z?��y[��x+�﻽��	��|��}9��L����(����I��K�J��2x���2���u��������}�1�B'4'5��Y�￥�.��N���Z@����*�*��'��'��?��?�����q��*�D���'HC�2�3�4�5 6�6�6HCHCb7�8�9�:;q<�<�=�>�?HC@RA      @                                           
    fUfU                             '              D$D-D"�&                      \   l           ��                                                        AXBXCXDXSPBPSIDIIPFLDSESSSCSFSGS����	���		�� 				   � @    NVUPDIPLNZNAPONCOVDNEINGZRACPECYfg&.6>de�󬭪�������lmno�����蚂���������               BD-:DOS Debug v1.19 help screen
assemble	A [address]
compare		C range address
dump		D [range]
dump MCB chain	DM
enter		E address [list]
fill		F range list
go		G [=address] [breakpts]
hex add/sub	H value1 value2
input		I[W|D] port
load program	L [address]
load sectors	L address drive sector count
move		M range address
80x86 mode	M [x] (x=0..6)
set FPU mode	MC [2|N] (2=287,N=no FPU)
set name	N [[drive:][path]progname [arglist]]
output		O[W|D] port value
proceed		P [=address] [count]
quit		Q
register	R [register [value]]
FPU register	RN
toggle 386 regs	RX
search		S range list
$trace		T [=address] [count]
trace mode	TM [0|1]
unassemble	U [range]
write program	W [address]
write sectors	W address drive sector count
expanded mem	XA/XD/XM/XR/XS,X? for help
$[more]$^ Error
$Write protect error Unknown unit error Drive not ready Unknown command Data error (CRC) Seek error Unknown media type Sector not found Unknown error Write fault Read fault General failure  '7G�Xcv���� read  writ ing drive _ 8086/88 x86  without coprocessor  with coprocessor  with 287 386 regs o   trace mode is   - INTs are  traced processed  (unused) [needs x86][needs math coprocessor][obsolete]Divide error
$Unexpected single-step interrupt
$Unexpected breakpoint interrupt
$Can't write breakpoint
$
Program terminated normally (____)
$EXE and HEX files cannot be written
$Cannot write: no file name given
$Writing $ bytes
$Disk full
$Error ____ opening file
$File not found
$Path not found
$Access denied
$Insufficient memory
$EMS not installed
$EMS internal error Handle not found No free handles Total pages exceeded Free pages exceeded Parameter error Logical page out of range Physical page out of range EMS error __ ��  �  
  /CSmExpanded memory (EMS) commands:
  Allocate	XA count
  Deallocate	XD handle
  Map memory	XM logical-page physical-page handle
  Reallocate	XR handle count
  Show status	XS
$Handle created = ____
$Handle ____ deallocated
$Handle reallocated
$Logical page __ mapped to physical page __
$Handle ____ has ____ pages allocated
$phys. page __ = segment ____  $____ of a total ____ EMS $es have been allocated
$pag$handl$no mappable pages

$no�������ln����� N@ B@ R  BJ JB rz ZT ZR � RZ R"     B \ p"   0 0 0 � t    
 ~ ZR  VZ  ZRP VZP N" N, * "  R r R R NH HN l` \P Z&b Z&r "N ,N T &P &  B( B. B" p b RZ" RZ. ^\ \^ 6 2 < 4 8 : � � � � � � � � �� �� �  � � � � �   AA� AA� AA� AA� AD� AD�* AN�8 ARP�< BOUN�@ BS�D BS�H BSWA�M B�T BT�] BT�f BT�o CAL�x CB�y CWD�} CLÀ CLă CLɆ CLTӊ CMÍ CMOV�� CMOVAŕ CMOV CMOVBŝ CMOVá CMOVť CMOVǩ CMOVGŭ CMOV̱ CMOVLŵ CMOVN�� CMOVNAŽ CMOVN�� CMOVNB�� CMOVN�� CMOVN�� CMOVN�� CMOVNG�� CMOVN�� CMOVNL�� CMOVN�� CMOVN�� CMOVN�� CMOVN�� CMOV�� CMOV�� CMOVP�� CMOVP�� CMOV�CMOV�CM�CMPS�CMPS�CMPS�CMPXCH�CMPXCHG8�!CPUI�%CW�&CD�*DA�-DA�0D�1D�2DE�8DI�;D�<ENTE�@F2XM�DFAB�HFAD�SFADD�ZFIAD�_FBL�bFBST�eFCH�iFCLE�jFNCLE�nFCMOV�sFCMOVA�xFCMOV�}FCMOVBłFCMOVŇFCMOVN��FCMOVNAőFCMOVNFCMOVNBśFCMOVNŠFCMOVNեFCMOVNڪFCMOVկFCMOVڴFCOͿFCOM��FCOMI��FCOM��FCOMP��FCO��FDECST��FDIS��FNDIS��FDI��FDIV� FIDI�FDIV�FDIVR�FIDIV�FEN�FNEN�!FFRE�%FICO�*FICOM�/FIL�6FINCST�:FINI�;FNINI�?FIS�DFIST�KFL�UFLD�YFLDL2�]FLDL2�aFLDP�eFLDLG�iFLDLN�mFLD�qFLDC�rFNLDC�uFLDEN�xFLDENV�yFLDENV�}FMÜFMULЏFIMU̔FNOИFPATAΜFPRE͠FPREM��FPTAΩFRNDINԭFRSTOҰFRSTORױFRSTORĵFSAVŶFNSAVŹFSAVE׺FSAVEľFSCAL��FSETP��FNSETP��FSI��FSINCO��FSQR��FS��FST��FSTC��FNSTC��FSTEN��FNSTEN��FSTENV��FSTENV��FSTS��FNSTS��FSU�FSUB�FISU�FSUB�FSUBR�%FISUB�*FTS�.FUCO�7FUCOM�@FUCOMI�IFUCOM�RFUCOMP�WFWAI�ZFXA�^FXC�eFXTRAC�iFYL2�mFYL2XP�qHL�tIDI�wIMỦIΎINÔINSINSיINSĞINԣINTϦINVĪINVLPǮIREԯIRETĳJ��JAſJ��JB��J��JCX��JECX��J��J��JG��J��JL��JN��JNA� JN�JNB�JN�JN�JN�JNG�$JN�*JNL�0JN�6JN�<JN�BJN�HJ�NJ�TJP�ZJP�`J�fJ�lJM�wLAH�zLA�~LDӁLSӅLEӈLFӌLGӐLE��LEAVŗLGDԛLIDԟLLDԣLMSקLOC˩LODS¬LODS׭LODSıLOOдLOOP׵LOOPĹLOOPڼLOOPſLOOPE��LOOPE��LOOPZ��LOOPZ��LOOPN��LOOPN��LOOPNE��LOOPNE��LOOPNZ��LOOPNZ��LS��LT��MO�MOVS�	MOVS�
MOVS�MOVS�MOVZ�MU�NE�#NO�&NO�*O�8OR�9OU�>OUTS�BOUTS�COUTS�HPO�YPOP�ZPOPA�_POP�`POPF�dPUS�}PUSH�~PUSHAăPUSHƄPUSHFĈRC̐RCҘRO̠ROҨRDMSҬREЮREPŰREPNŲREԷRETƸRETFľRS��SAH��SA��SA��SE��E��C��S��D��F��G��SH��SH��SB�SCAS�SCAS�SCAS�SET�SETA�SET� SETB�$SET�(SET�,SET�0SETG�4SET�8SETL�<SETN�@SETNA�DSETN�HSETNB�LSETN�PSETN�TSETN�XSETNG�\SETN�`SETNL�dSETN�hSETN�lSETN�pSETN�tSET�xSET�|SETPŀSETPτSETӈSETڌSGDԐSIDԔSHLěSHRĢSLDԦSMSתSTíSTİSTɳSTOS¶STOS׷STOSĻSTҿSU��TES��VER��VER��WAI��WBINV��WRMS��XAD��XCH��XLA��XLAT��XO��������



77777777777777777777777777777777



�a�Yssssssssssssssss y|�������/�������������������9�oqqq ssssii��--/sll��
 

������ ������� ������� � 55555555u1u1u uwwwww  UUUUu wU<<<<<<<<@@RR@@@@< <<ULULPR JJJJJJJJ@@@@   J JJ N N@@@@RR >>>>>>>>CC  CCCC> >>U ULP PPRR  LLLLLLLLFF FFFFL LLN3N3    RR   ""������""""""""""""""""    ----------------������������������'����'��"'��'""��%%%%%%%%55****3�W      {\999999{�      {\{\             �M	M	M	M	M	M	��	�	�	�	�	�	 kkkkkk ;;;;;;;;��������{{{{{{{{\\\\\\\\�a+% 450 0{1{1@FGN���|��x�����    R	R			�����>��/							\ �V d	�n�����	pwR	R	3	:	ho&����������������  ��/%  �C��RRWk    �	HXhx��������77BBV 77BB     &| ((g $	q .	l )	�0 9   M	�	k 9   M	�	k����  �����  �����  �R	  4*%1�+;�V V {  )H)V&�&X)^)     ))J&P&)  \&cE����������������J  TY��vfJ  ���������%b6b-bb        =C  J  YQbdbZbmb �d�b  ����������    ����J  TY�  �	  TY�4�4    ��������  (����  =C��C        0�d�b  OU]elt|  ����3�%�MD4�%>4�2  8@ &�&v ]EjI�6�6�6�6�6�6rY�W?aa�`�`da7a�`�`]a/aMaUa�`�`�`�`          �5�5�5|56�5�5x56�566�5�5�5�5�8�8A8:8�8�8G848�8�8�8�8g8`8m8Z8{7\7�QC099{7\7�WQ09915�A�A*6L0469677�G0207077yIyI�<@<@<@<@<@<@<@<@;�C0Q0L0G0�Q\������4�55$��                         	
                                                       !       "      #$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJ  KLMNOP QRSTUVWXY  Z[\]^_`a     bcdefghij                                                kl          mnop q      r       s       t       uv  wx   y      z{|}~          �       "! #]�$_^0���.�-_n��� � � \��^m � � � o a � ` � � � � � a ~����LqvUgt����-A	� � � � � � ������
        ! ���������1�0+*	 	   ( ) ��� � 0 1  
!#%')+-0247:>@BDFIKMQUY]`cegikmpsvy|�����������������������������Ȏ؎Ћ&@�B�&�{u�.��	� �<u��N�!<;t�<?t$ ,a<w����!�㋗��'�fV����<ú�	�9� ��0뛀>s u,� � D�!�t�@ ��&�>� s�����!���!�                       ������$&    a �
�BYWOWODWQWFLDOTBSHLONEFA�B����������B(<t�	���� �|���&@�fV���`,�:��R' �nT�|�հ ��_<tZ<;t��S'  �fVV<ar<zw$ߪ�<t<;t< t<	u�M��� NV�f�ރ��ά"�y���Q+οfV�^t���r�^^���4��7���<�r�,�t8�HtHtHt<sJR'�� �R'@F�� �� ��T'�R'^X�<t�<;t��e���S'< u�^X�<t<;t�N��S'�fV��t�>S' u�^,u��<t���������fV���{)�{)�㋇)�)��<t<<"t<'t�:{) ��)��nWw����<t:�t
���nWv��&���v<uľfV���|��g�;�r��|��   �)�)�)����ëêÉ6U'^�<t<;u��'��6U'^��fV<t<;u��W� 3��_N�%�߀} u3W��'� �_u'�u	�D$�<RuG���وM���$%��=PTu������>T' u&W�VI� �_uV���<:uX���yI+ي�T'�^W�6I�6 �?_ro��]��s������J�5���w&t��r9�R' �2�<(u+��,0<w�E�<)t� ��,0<w��E���u	���� :Et�E< u�����&r6�7�M�]�U
�8��"<:u�+��M�M�]�U
� �� �<[u���<]t�NW�FI� �x_rC��s����} u��N<*uF�]�����-�Q�} u�]�	�} u�]��8�<����<*tM]U
����NW�FI3��_rԀ} uΈ]�|<-t�<+u�h��h��} u-�} t$�= u��� �R'���Et@@�R'�E�������E
E�u%�Eu�R'��E:�w��W�x'� �_uл�j�R'��E
Eu�E�ĉE��} u�M��|�����u<�R'�m���E<t�< u�<|�$
���A�E< u���8<|Y$
�<t:�t� Q�E���Y�e	:�u;E
u� 
]t
�ǀ�@��ɀ�}�MN�i��<t<;t<,u���Vs�Q�������V3��W'� �6U'�,�r<tw�_'���c'����N���3һL ��d'�g'=� w<�r�`'�ଢY'�g'�c'�6U'��f&��|�fV�< t4�=�t�<@r��&f'������.�늇�'�t�с|�VZtσ����a��=�u��c'�t�u�t�6U'�<�t���S'< t!<�u	�c't���d'$�=� w߿u� �u��R't�d'=� wƿl�	 �u��['�t�b'�����Gu��|���R't�����S'< t����R'��t$$Dt	<Dt�g����&R'�c'�@u��t�f����T'< t���<dr�R' �d'����@s= r$�`'$8Y'�$�����$��Y'�狅J�� tP��{�X
a'�s��Y'�c't�f��R't���Z��>W'�t�M� �u�L��>['�t�b'���u�9��>]'�t	�u����(��|�>_'s�R'%u�c'@t�_'�i'�b#��fV���%��O/1/1/1/U/6/E/`/�/�/�/�/�/�/�/ 0V0�0�0�0�0�011,1�0J1p1w1~1~1~1~1~1~1~1~1~1�g�0�E$���Y'�!�E$�a'��>['��uG�>W'��Eu;�c'�f',|2t@��c'�]
�t	�c':�u:b't�b'< u�c'����E<t$r
�a'��E< t<u�c' �	<u׀c'@�b'�c'������'뗰�}
 t�c'@��E�>['�b'�>]'ð	��|@@�R'��At!��t���ᾀɀ�R'� ��
�t��Dt@�3ɋE�U
+�шE���:�u5;�u1�E륋|�~� �>d' r@؃� �U
�E< t<
t<t��u�����c'@� PH؃� X�E�E3�+�щE�U�>]'�X�[���]�=��2�E<w�u�_'<u�}�u�� ��!��E<r�<s�_'�"�]���Y'�c':Et�|�E,<s����Y'À&c'�E�����E� :�uS;E
uN��N �e�E�>]'��c't�c't0�&c'��<"t�c'�b' X���}��}����'�;EtX�!�À} t�8Et�X���u�t�E���R'tH��E<u�E$�	Y'�c'�>W'�<-tP,0<
XrP$�,A<X��<-t�? � �u4
�u2ì�/ ��ʹ t!������� �ƀt:���u�ǀt���u�Àt�AAA�3�3��xr
ج�pr����u� ������������u��tB��tB��t	B��t���UË%��<Eu"P�Ċd���W�FIQ� ��Y_XuF�Ӏ�����u+�K��r��FF������A�j󦟊T�&�u��b�u�JQ�߿fV���!�:��D��{!�  ����y!�  ����p!�  �XP�`!�:��G��W!S�!_Y��ÿfV�PS��P:��H�2!�e!�6c�fV�c �.  � � ���!� ����!� ����!� ����� � �#�tVQR� � ;�tK�$ � ��"���ZY^�rFQ�!Y��Zt���Mt�Ëގ��<u�������s#����<mu�Z��� ����������� ���3���z �:���$�P�o �  �X�]0��;�tP�  ��&�CX@��΀�;�r��+�A�����P�? � �X< r<~v�.&�C���� t�  ��F���6��E�-����R�9 ZN;�sF�fV���l�B������S���E�A<t*R�S�ϺfV+�_��H�r�������L�:�xË���:��nT���ո  ��VS�[�Y��.�SR�Z[�vV3ɀ>s t3V�fU�6x;6zr�Q�r�>su�<
uF�s�ଢs�6x^���!< t3<t/<t<-t��s���er�A���J�fV�F�IN�������+�QR��4��ZY����L�u�B�fV<t��t�у�� ��2��
�����3ɋ���+�AQR��2�ρ�fV_�Ã�t$X3҃��� ���t
�fVQ�YHu�����fV��Y�fV�I�ÿ6�fV���f�f�����F��ð��F�Ê<�t�:Ó�	�������fV3��N�<t���f�f���G�fV��6���?�����P��X<�u�>��u�����<�t�	���	��SR�F���4YX������P���t��X���  ���+�P���t�t�X���ó ����߀�Wt�>mr��Du�d���߀�IuCC������t��t��p���c�f��S�Ì˴P�>k tV�6i�\^ôQ�>k t
�i�_��!áH;J�P���uSR�x�6	�>	Z[X��Nt.�>�r��3��¸s��!��%�����t;	u�� t����� =�� ��s�v	��B3�3��!��u~���HVS&;6 ��ޝs&6 � 3�������+��r;�u;�s
[^���T	�.[^����� B3�3��!� #ױ����?� ����!���;�t�>�!�f�f�	f�&	�P�>�![��t�� �� SR���t���� 3������ �L�����K�� ���!s�����+. =� r�� �F�6�&����6	� 	�6��6	�	�� ��k���H�����H��"%�D�!�H�
 � �|�	W���	�^� ��<u� �d��� ��mu� V�^<t��^<ttN��bQ���Ӌ�����;�u��$�߀�:�Y����s������X���&m<t P��[X<nu�p �<2u�>mu��p�&r��	 <ct�N�Y<t���<w�m�r<s�&n�þ��m< t��0�����>p t���r:mt���u�.HEX.EXE.COM�� <t��t:ut<ar<zw$ߪ��� ��>�WV��� t$��� r�U���9� Q�������Yt�����^�fVWN��<u�^�\ �  ���l � ���fV_WG��<u�X�+�HH�ì<t�st�:tt N�)��P�<t�[t:uu�NX<uHì<t��Ct�� �N�<ar<zw$ߪ�  �����3�����ó ����߀�Wt�>mr��Du�d���߀�OuCC���R����t��t���Z���y��Z���C�SRfXZf���	�	�&���	�Ë	�&����S�چ[��ۋڊù�����<�t���	��Q� �6	�� ��	� �u!�E��t	2���u�� �@t$?��Ƙ� �L<�t� � $�4�8t�}<�s4��u<t%<@r'<�r �<t4�u�t <@r<�r	�i �f �c �` �	��u�� Q�ְ��A�s�����fV����ë�l�fV����������3ҁ>��u�&���	�G��9�u�=Y���'F����	��������� ��؃�����Э����"t#�t
�؊ô%�!�ݾ]�
 ��� �� ���@<t�2�>mr�6n�n u�ff��fV������<t��>p t�X�<u�$�<Xt�<Nt�N�%�߿	� �߿fVu*�< w%�� ��_�<uS��<�G[<t�^���<FuRN�<t< t<	t<,t� �t<u���<t�N�%�߿d	� �u��t	w�E���!	��E�		�;�Ѐ>mrM<EuI�$�<StB�Ĺ �	�u6�߿fV�EG�� ��_�<uSf���[<tS�
��[��
��O�N�W��3��	��
QR��	ZY+ʁ�fVO+�r�������þfV��t�u6QW���_u)�R�����6�:��D��-�
�� �U�S�`[Z����YA����r
<t�4
��v���U
�o�o0�����4�ot�-���Ê���߀�Mt����>�}Q� Y���3���<�uA�w�<t�ot)<u<�	3��^�P�X<�u� �>��t� �ù �e rӋ	�6	����Êط 3���������7��4�:��t�����Ì��6	�	�	�	� 	��FF�7�G�O�	�&	�������4����r���:�t���������� 	�	&�g�Ë�����t�������?<u����s�����  �	���	����AQR�	[Y����+�+�;�s��PSQR���÷ �J� �D�!ZY[X�PSQR���÷ �j� �D�!ZY[X��tZ.�>�r�о`�����s��!�������&���ӎۋ&@��s'<v�����������fV�����������3�E栜�t�	�< u�/�� �fV���r�������V
��<3ɺ� ��ryP�R� ����r3��F�t����F����[�u [�V
� �+~ u;Fr�F��޴@�!;�u3ҁ��)N��^ uОu���d�6 �A�� �"��>�!Ã���t!����t����t����t	�v�%�p�	����<?t <at<dt=<mtw<rtR<su� �������h�U��D�ڴC#�u� Z�"��p���_��B�/����E���~��w��%������
�����ڴQ�� ���q����������R�����XP�D� ����q��X�j���;��� ���K� ��Bv3ҴL�g���t
�t� ��� ��u���M�fV�m #�t������ Ku������� X�fV�O �V�(��Q�������������Y��t������ݺ����B� ��+ûL�s �K� ��� �P�d ��g"�xÊ�<�����㋷��u	������fV�������g5�!���t
�F��"�uú�����i�¿��aR���8�ZÿW� ��)� Z�$������3���8��� �0�u�E� ��Ë΁�hUv��w	A� ��!��������&B�	�	�C� 	P�&	X� ø L�!�L3��ǿ� ��������H�v�����&D+&F�&. ����>mrfa�&	�.	�_^^]]��[ZZYYXX��f�&	�q f�6	f�6	f�6	�	��t�f��.���.��'�ȎЎ��n.��u�.����.����.�	.�	.�	.� 	f.�&	�̎Լ 	�>mr�&	�.	f���	j �f�f`�PPQQRRSS��UVVWW�&D����H�" �x�&	��q�>��u
�M�!��ÿL3��޾� V����_3��ƾ ����À>\ u	W�T� _�PR�E�Y�ZX�V3��޾� ����^�Error in sequence of calls to hack.
$V�\�L�	�\ V�TW3��ǿ� ����_^�V�6e�< ^�SQRP� ���FXZY[ð���� ������  ��:��fV��+ʉv� ���r?��'�z+�t�<t<
t���� s�
��eVrNO�6x�s���ϺfU+�����dU�t�u�
�\�
�t��fU��WBB��� �< t�<�t�<t<t��N�<u�O+��ǋ��E�JJ_��;�t�O�D��ˀ>s u�ÿfU�6x;6zr� r�>su�<
uF����PSQR���?3۹eV��+�t���r	�t������zZY[X��T���3��S+�RQ�;���5Y���r
�����^����	� <tQ��<tGSR�� ��t�	�������R��A�����SRV�J;�s�B�����>� u^Z[�u�X[��[����G�OX�GZ3ɉWI�� �� <t
�c����D��� <=u��	� ������À>� t���	���	���	�� ������R���ZI��Q�? �Q�9 V�4< w^Y��I�s���N�� <ltR�� ��Z;�w��
��r����t���V�<:t^N��X�����ÿfV<t�<'t<"t� �G���:�t<tª���:�t�� <u��PWQ�	� �$%�߀|As�u33ۋ}�F�Y_X�<Eu"�D��%��=IPu�	�
� �u	�}�]F��Y_X����r���4 r��3۬�* r���u� ������
������S���#�[u�����"�u��P,0<	vXP ,a<w
DD��X���+ <u��v��� <,uV� <u^�,Ã�ì$�,A<v�N�< t�<	t��< t<	t
<,t<;t<=�          !$          
	ALCLDLBLAHCHDHBHAXCXDXBXSPBPSIDIESCSSSDSFSGSSTMMCRDRTR�	 	�&.6>de����d	b���*I �&(I3��I�I�%I�$I��_'  �-<�u�I@�!�I� �أI=�r
��>"� ������� �㋟\��ñ��:_'r�_'����r� ��IJ�bM�MOO#O6OiOnOrOvO�O�O�O�O�O�O�O(P8PLPkPvP�P�P�P�P�P1 3 DXCLSTCSDSESFSGSSS�PUJaJhJ�J�J��I� ������À*I�`'��<�r���,��àY'$��ÊÀ�τIuI��$00I��t�>%IX���&V��f���u�t���,I  ^��p�< tc�+I �<@r7�+I <`s<Ps	���It�I�&I����������p�؃����I�����(r��J��� uO���J�< t�,�띠I��"Iu�� � �v%� �@��u � ��%�& ���u� ��%�
 � ��u�!&IW���ܡI�u��5��f��_��B�t-�I�� u�W�	 �l�_u� �gW��V��:�_�I�q��t6$I�I�� u�$�W�u� � t9��u��%�Iu)�+�$���t�W�I�
&�. �u��It���I_� V��^W�&_���,I�� t�*I�u� t�ϋ�� �u�����+��W�fV���
�:����� ��I��V+���;�~+�S��W�~�Y[�fV+ϰ ����k� ��V+�r�_�*It�>�}� uF�W�I�x_���V+�Q�Y��k�*I4�ub�>%Iw[��V�>$I |t��HH��s�:��&I�k�=��%I������lI��&I&�&�g&�W&�w�>$I |t��9��5��7�\�*I�t�u�I��t
=� t=� u�%�À� | ��*It����v�tP�o��X����M����<�r����I�It���:��Y'$ǀI �I t� �*I�&I  <��[�t{����.I��u��t(�BP���Iu�%I��BX���&I���t�+��SI����t�D��&I��Y'�t.�Y'�u��&I< �+}�-�؈%G�+��+��&I��]��<u	�[��I� P$<u�c�Z'X��u�@t�T< }���-G�����Y'$<ub�Z'<$u��W$<u�Y'�u����[EGG���]��Z'������$<tA�[EGG���&Z'���t�*��2�Āt	�4��@t�8��]���[EGG��]���0<�s����#<�r���T��I u@�Y'�e���$�+I*I�� |t	�� t�EG������6I��P�MM�X0�àI�˰ �Ǵ �!�FL��O��AT��DO��UB��LE���+�T���<�s*�&*I�����#t�����FA��R ��&*I��<�s����� P��t�P���:���tX�X������(����t P���Z����I���U��Q�I�FX�Y'$<t�����Y'$��ST��(��0)
ëûCR�� <wu�_'�>Iu$<u �n�� �DR����� <r\<s�_'�TR���0��� <sB<t�&*I�<r�_'���&< ��+}�۰-������MM�j $빀*IX����&(I��JP�I  �I  �$I��_'  �&*I��� �tI�
 �t�I���q À*I�	 +����r��rI� Í�� ���� ���$��I�u�I�� �Y'�Y'ÿ�V���$�"�y�� ����Vr�à%I������VI�È&$I�>,I�Q�� t�� }	�BY��TE�t�D��WO��RD�� P��TR�� ���; P�7 �X�Ø���P��FI�X�ÀI�I�V�6���.6I�^�I�V�6���.6I�^�IË6�����cKu��6�Ã>,I t,I����ρ�VW�NO�_�þH�`'t�D	7�r�>p u�m:_'r�S� ��D	6�m:_'s�_'0�D� þk�E�� �u�w'+�3ɠr:~�
 þ	�fV� �nt��U ���fV�nuV����F ^A�: �v���I V�k��^�fV��' ��	�����	��*I��f�	f����nu��=��\��W� ���ðE���=��\f��8� ����CWSWTWOPC=IP=DP=emptyNaN�fV�3S�fUf�7� ��=���f���P�� ���S����f����%��� � �[�Q����f�f��f���f��>mr�� ��� ���� � �Y�Ӈ��� ]XZ�
��$���ͱ0�fVQ�ST����=�W�� � �t�
��$�_������$tV�CS�<t�HS�<t�0�� �^� �D�\ �.��D�S �D�M �D�G ��B �fV��Y��
����8u�f�&fUþT	� ��	�Dt�D�� ���ì��< u��Pf��� XP��� XPQ���� YX$�'@'��P+�w� �fVY+ϰ ��O�= t�G�
��ϺfV+���u	� �@����V�� ����^ÿ�� 3��H����!��r�H�!ry�	�=�S���������	��X���&� = v3����HH�	�3���U��&�6 ��!&�
 D&� �>� u
��&� ÌH��H��@&� &�  ����  �!�eV0�>� t�"��=�DEBUG version 1.19.  Debugger.

Usage: DEBUG [[drive:][path]progname [arglist]]

  progname (executable) file to debug or examine
  arglist parameters given to program

For a list of debugging commands, run DEBUG and type ? at the prompt.
$Invalid switch - x
$��ȣ������J� D3��!r�⁀��u�s � 0�!��=r��=
r��TX;�u}�m�X �P��X���tj�m�܃��f�fXf��f5   fPf�f�fXf;�tA�mf��f5    fPf�f�fXf;�t'fQf���f3��f��|f3�f@���$<v��m�fQf���m�r�p<sK�p��ZZP���~ X< u7P�~ X%?��?u*�p�>mu����������������P��~ X�u�r�>ms��X� ��������C>�Dϸ 7�!�t��/u�u�� �< t�<	t�:�t!</u0�<?u*�D< t<	t<u�|U�J�� �<?t�V�tV�:�L�!N���� ������5�!��E������%�!��R�!&�G��c�4�!�e�g�]�!��r�6i�k�
 �]���D��&�L�� ��L��H�}Y$���HH�@@@���شJ���66C6E6/81868�C�C�CID�R�RTS`SrS�S�S�S�S=T