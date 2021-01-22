# 辅助输出信息
message("using FindXanaduCrypto.cmake find")

# 将头文件路径赋值给 XANADU_CRYPTO_INCLUDE
if (WIN32)
	FIND_PATH(XANADU_CRYPTO_INCLUDE XanaduCrypto/ C:/Xanadu/include/)
elseif (MINGW)
	FIND_PATH(XANADU_CRYPTO_INCLUDE XanaduCrypto/ /usr/include/)
elseif (APPLE)
	FIND_PATH(XANADU_CRYPTO_INCLUDE XanaduCrypto/ /usr/local/include/)
elseif (UNIX)
	FIND_PATH(XANADU_CRYPTO_INCLUDE XanaduCrypto/ /usr/include/)
endif ()

# 将库文件路径赋值给 XANADU_CRYPTO_LIBRARY
if (WIN32)
	FIND_PATH(XANADU_CRYPTO_LIBRARY XanaduCrypto.lib C:/Xanadu/lib/)
elseif (MINGW)
	FIND_PATH(XANADU_CRYPTO_LIBRARY XanaduCrypto.dll.a /usr/lib/)
elseif (APPLE)
	FIND_PATH(XANADU_CRYPTO_LIBRARY libXanaduCrypto.dylib /usr/local/lib/)
elseif (UNIX)
	FIND_PATH(XANADU_CRYPTO_LIBRARY libXanaduCrypto.so /usr/lib/)
endif ()

message("XANADU_CRYPTO_INCLUDE: ${XANADU_CRYPTO_INCLUDE}")
message("XANADU_CRYPTO_LIBRARY: ${XANADU_CRYPTO_LIBRARY}")

if(XANADU_CRYPTO_INCLUDE AND XANADU_CRYPTO_LIBRARY)
	# 设置变量结果
	set(XANADU_CRYPTO_FOUND TRUE)
endif(XANADU_CRYPTO_INCLUDE AND XANADU_CRYPTO_LIBRARY)
