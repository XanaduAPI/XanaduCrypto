# Explain
message("using FindXanaduCrypto.cmake find")

# Find XANADU_CRYPTO_INCLUDE
if (WIN32)
	find_path(XANADU_CRYPTO_INCLUDE XanaduCrypto/ C:/Xanadu/include/)
elseif (MINGW)
	find_path(XANADU_CRYPTO_INCLUDE XanaduCrypto/ /usr/include/)
elseif (APPLE)
	find_path(XANADU_CRYPTO_INCLUDE XanaduCrypto/ /usr/local/include/)
elseif (UNIX)
	find_path(XANADU_CRYPTO_INCLUDE XanaduCrypto/ /usr/include/)
endif ()

# Find XANADU_CRYPTO_LIBRARY
if (WIN32)
	find_path(XANADU_CRYPTO_LIBRARY XanaduCrypto.lib C:/Xanadu/lib/)
elseif (MINGW)
	find_path(XANADU_CRYPTO_LIBRARY XanaduCrypto.dll.a /usr/lib/)
elseif (APPLE)
	find_path(XANADU_CRYPTO_LIBRARY libXanaduCrypto.dylib /usr/local/lib/)
elseif (UNIX)
	find_path(XANADU_CRYPTO_LIBRARY libXanaduCrypto.so /usr/lib/)
endif ()

message("XANADU_CRYPTO_INCLUDE: ${XANADU_CRYPTO_INCLUDE}")
message("XANADU_CRYPTO_LIBRARY: ${XANADU_CRYPTO_LIBRARY}")

# Setting
if(XANADU_CRYPTO_INCLUDE AND XANADU_CRYPTO_LIBRARY)
	set(XANADU_CRYPTO_FOUND TRUE)
endif()
