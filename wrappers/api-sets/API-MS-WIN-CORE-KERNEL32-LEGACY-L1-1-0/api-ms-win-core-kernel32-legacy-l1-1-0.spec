@ stdcall AddLocalAlternateComputerNameW(wstr ptr) kernelbase.AddLocalAlternateComputerNameW
@ stdcall BackupRead(ptr ptr long ptr long long ptr) kernelbase.BackupRead
@ stdcall BackupWrite(ptr ptr long ptr long long ptr) kernelbase.BackupWrite
@ stdcall BindIoCompletionCallback(long ptr long) kernelbase.BindIoCompletionCallback
@ stdcall CopyFileA(str str long) kernelbase.CopyFileA
@ stdcall CopyFileW(wstr wstr long) kernelbase.CopyFileW
@ stdcall CreateFileMappingA(long ptr long long long str) kernelbase.CreateFileMappingA
@ stdcall CreateFileTransactedA(str long long ptr long long ptr ptr ptr ptr) kernelbase.CreateFileTransactedA
@ stdcall CreateFileTransactedW(wstr long long ptr long long ptr ptr ptr ptr) kernelbase.CreateFileTransactedW
@ stdcall CreateMailslotA(str long long ptr) kernelbase.CreateMailslotA
@ stdcall CreateNamedPipeA(str long long long long long long ptr) kernelbase.CreateNamedPipeA
@ stdcall CreateSemaphoreW(ptr long long wstr) kernelbase.CreateSemaphoreW
@ stdcall DnsHostnameToComputerNameW(wstr ptr ptr) kernelbase.DnsHostnameToComputerNameW
@ stdcall DosDateTimeToFileTime(long long ptr) kernelbase.DosDateTimeToFileTime
@ stdcall FatalAppExitA(long str) kernelbase.FatalAppExitA
@ stdcall FatalAppExitW(long wstr) kernelbase.FatalAppExitW
@ stdcall FileTimeToDosDateTime(ptr ptr ptr) kernelbase.FileTimeToDosDateTime
@ stdcall FindResourceA(long str str) kernelbase.FindResourceA
@ stdcall FindResourceExA(long str str long) kernelbase.FindResourceExA
@ stdcall FindResourceW(long wstr wstr) kernelbase.FindResourceW
@ stdcall GetComputerNameA(ptr ptr) kernelbase.GetComputerNameA
@ stdcall GetComputerNameW(ptr ptr) kernelbase.GetComputerNameW
@ stdcall GetConsoleWindow() kernelbase.GetConsoleWindow
@ stdcall GetDurationFormatEx(wstr long ptr long long ptr ptr long) kernelbase.GetDurationFormatEx
@ stdcall GetMaximumProcessorGroupCount() kernelbase.GetMaximumProcessorGroupCount
@ stdcall GetNamedPipeClientProcessId(ptr ptr) kernelbase.GetNamedPipeClientProcessId
@ stdcall GetNamedPipeClientSessionId(ptr ptr) kernelbase.GetNamedPipeClientSessionId
@ stdcall GetShortPathNameA(str ptr long) kernelbase.GetShortPathNameA
@ stdcall GetStartupInfoA(ptr) kernelbase.GetStartupInfoA
@ stdcall GetStringTypeExA(long long str long ptr) kernelbase.GetStringTypeExA
@ stdcall GetSystemPowerStatus(ptr) kernelbase.GetSystemPowerStatus
@ stdcall GetSystemWow64DirectoryA(ptr long) kernelbase.GetSystemWow64DirectoryA
@ stdcall GetSystemWow64DirectoryW(ptr long) kernelbase.GetSystemWow64DirectoryW
@ stdcall GetTapeParameters(ptr long ptr ptr) kernelbase.GetTapeParameters
@ stdcall GetTempPathA(long ptr) kernelbase.GetTempPathA
@ stdcall GetThreadSelectorEntry(long long ptr) kernelbase.GetThreadSelectorEntry
@ stdcall GlobalMemoryStatus(ptr) kernelbase.GlobalMemoryStatus
@ stdcall LoadLibraryA(str) kernelbase.LoadLibraryA
@ stdcall LoadLibraryW(wstr) kernelbase.LoadLibraryW
@ stdcall MoveFileA(str str) kernelbase.MoveFileA
@ stdcall MoveFileExA(str str long) kernelbase.MoveFileExA
@ stdcall MoveFileW(wstr wstr) kernelbase.MoveFileW
@ stdcall MulDiv(long long long) kernelbase.MulDiv
@ stdcall OpenFile(str ptr long) kernelbase.OpenFile
@ stdcall PulseEvent(long) kernelbase.PulseEvent
@ stdcall RaiseFailFastException(ptr ptr long) kernelbase.RaiseFailFastException
@ stdcall RegisterWaitForSingleObject(ptr long ptr ptr long long) kernelbase.RegisterWaitForSingleObject
@ stdcall SetConsoleTitleA(str) kernelbase.SetConsoleTitleA
@ stdcall SetFileCompletionNotificationModes(ptr str) kernelbase.SetFileCompletionNotificationModes
@ stdcall SetHandleCount(long) kernelbase.SetHandleCount
@ stdcall SetMailslotInfo(long long) kernelbase.SetMailslotInfo
@ stdcall SetVolumeLabelW(wstr wstr) kernelbase.SetVolumeLabelW
@ stdcall UnregisterWait(long) kernelbase.UnregisterWait
@ stdcall WTSGetActiveConsoleSessionId() kernelbase.WTSGetActiveConsoleSessionId
@ stdcall WaitForMultipleObjects(long ptr long long) kernelbase.WaitForMultipleObjects
