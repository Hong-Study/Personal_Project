protoc.exe -I=./ --cpp_out=./ ./CProtocol.proto
protoc.exe -I=./ --csharp_out=./ ./C#Protocol.proto
IF ERRORLEVEL 1 PAUSE