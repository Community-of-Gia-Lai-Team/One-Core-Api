
include_directories(BEFORE ${REACTOS_SOURCE_DIR}/sdk/include/reactos/wine)

spec2def(API-MS-WIN-CORE-FILE-L1-1-0.dll API-MS-WIN-CORE-FILE-L1-1-0.spec)

list(APPEND SOURCE
	main.c
    API-MS-WIN-CORE-FILE-L1-1-0.rc
    ${CMAKE_CURRENT_BINARY_DIR}/API-MS-WIN-CORE-FILE-L1-1-0_stubs.c
    ${CMAKE_CURRENT_BINARY_DIR}/API-MS-WIN-CORE-FILE-L1-1-0.def)

add_library(API-MS-WIN-CORE-FILE-L1-1-0 SHARED ${SOURCE})

set_module_type(API-MS-WIN-CORE-FILE-L1-1-0 win32dll ENTRYPOINT 0)
add_importlibs(API-MS-WIN-CORE-FILE-L1-1-0 kernelbase ntdll)
add_dependencies(API-MS-WIN-CORE-FILE-L1-1-0 psdk)
add_cd_file(TARGET API-MS-WIN-CORE-FILE-L1-1-0 DESTINATION reactos/system32 FOR all)
