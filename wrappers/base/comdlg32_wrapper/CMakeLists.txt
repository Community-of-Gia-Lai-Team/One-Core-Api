
spec2def(comdlg32_wrapper.dll comdlg32_wrapper.spec)

list(APPEND SOURCE
    cdlg32.c
    filedlg.c
    filedlg31.c
    filedlgbrowser.c
    itemdlg.c
    main.c
	version.rc
    ${CMAKE_CURRENT_BINARY_DIR}/comdlg32_wrapper_stubs.c
    ${CMAKE_CURRENT_BINARY_DIR}/comdlg32_wrapper.def)

add_library(comdlg32_wrapper SHARED ${SOURCE})
set_module_type(comdlg32_wrapper win32dll ENTRYPOINT 0)
add_importlibs(comdlg32_wrapper comdlgbase user32 gdi32 advapi32 comctl32 shell32 shlwapi ole32 msvcrt kernel32 ntdll)
target_link_libraries(comdlg32_wrapper uuid wine)
add_cd_file(TARGET comdlg32_wrapper DESTINATION reactos/system32 FOR all)

spec2def(comdlg32_wrapper.dll comdlg32_wrapper.spec)


