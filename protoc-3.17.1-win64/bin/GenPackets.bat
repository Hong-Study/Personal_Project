
pushd %~dp0

protoc.exe -I=./ --cpp_out=./ ./CProtocol.proto
protoc.exe -I=./ --csharp_out=./ ./C#Protocol.proto

XCOPY /Y CProtocol.pb.h "../../Personal_Project_HJH\GameServer"
XCOPY /Y CProtocol.pb.cc "../../Personal_Project_HJH\GameServer"
XCOPY /Y CProtocol.cs "../../Personal_Project_LWY\UnityProject\testProject\Assets\Scripts\Network"

IF ERRORLEVEL 1 PAUSE