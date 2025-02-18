@ stdcall AcceptSecurityContext(ptr ptr ptr long long ptr ptr ptr ptr) secur32.AcceptSecurityContext
@ stdcall AcquireCredentialsHandleA(str str long ptr ptr ptr ptr ptr ptr) secur32.AcquireCredentialsHandleA
@ stdcall AcquireCredentialsHandleW(wstr wstr long ptr ptr ptr ptr ptr ptr) secur32.AcquireCredentialsHandleW
@ stdcall AddCredentialsA(ptr str str long ptr ptr ptr ptr) secur32.AddCredentialsA
@ stdcall AddCredentialsW(ptr wstr wstr long ptr ptr ptr ptr) secur32.AddCredentialsW
@ stdcall AddSecurityPackageA(str ptr) secur32.AddSecurityPackageA
@ stdcall AddSecurityPackageW(wstr ptr) secur32.AddSecurityPackageW
@ stdcall ApplyControlToken(ptr ptr) secur32.ApplyControlToken
@ stdcall -stub ChangeAccountPasswordA(wstr wstr wstr wstr wstr long long ptr)
@ stdcall -stub ChangeAccountPasswordW(wstr wstr wstr wstr wstr long long ptr)
@ stdcall CompleteAuthToken(ptr ptr) secur32.CompleteAuthToken
@ stdcall CredMarshalTargetInfo(ptr ptr ptr) secur32.CredMarshalTargetInfo
@ stdcall CredUnmarshalTargetInfo(long long long long) secur32.CredUnmarshalTargetInfo
@ stdcall DecryptMessage(ptr ptr long ptr) secur32.DecryptMessage
@ stdcall DeleteSecurityContext(ptr) secur32.DeleteSecurityContext
@ stdcall DeleteSecurityPackageA(str) secur32.DeleteSecurityPackageA
@ stdcall DeleteSecurityPackageW(wstr) secur32.DeleteSecurityPackageW
@ stdcall EncryptMessage(ptr long ptr long) secur32.EncryptMessage
@ stdcall EnumerateSecurityPackagesA(ptr ptr) secur32.EnumerateSecurityPackagesA
@ stdcall EnumerateSecurityPackagesW(ptr ptr) secur32.EnumerateSecurityPackagesW
@ stdcall ExportSecurityContext(ptr long ptr ptr) secur32.ExportSecurityContext
@ stdcall FreeContextBuffer(ptr) secur32.FreeContextBuffer
@ stdcall FreeCredentialsHandle(ptr) secur32.FreeCredentialsHandle
@ stdcall GetSecurityUserInfo(ptr long ptr) secur32.GetSecurityUserInfo
@ stdcall GetUserNameExA(long ptr ptr) secur32.GetUserNameExA
@ stdcall GetUserNameExW(long ptr ptr) secur32.GetUserNameExW
@ stdcall ImpersonateSecurityContext(ptr) secur32.ImpersonateSecurityContext
@ stdcall ImportSecurityContextA(str ptr ptr ptr) secur32.ImportSecurityContextA
@ stdcall ImportSecurityContextW(wstr ptr ptr ptr) secur32.ImportSecurityContextW
@ stdcall InitializeSecurityContextA(ptr ptr str long long long ptr long ptr ptr ptr ptr) secur32.InitializeSecurityContextA
@ stdcall InitializeSecurityContextW(ptr ptr wstr long long long ptr long ptr ptr ptr ptr) secur32.InitializeSecurityContextW
@ stdcall InitSecurityInterfaceA() secur32.InitSecurityInterfaceA
@ stdcall InitSecurityInterfaceW() secur32.InitSecurityInterfaceW
@ stub LogonUserExExW
@ stdcall LsaCallAuthenticationPackage(long long ptr long ptr ptr ptr) secur32.LsaCallAuthenticationPackage
@ stdcall LsaConnectUntrusted(ptr) secur32.LsaConnectUntrusted
@ stdcall LsaDeregisterLogonProcess(long) secur32.LsaDeregisterLogonProcess
@ stdcall LsaEnumerateLogonSessions(ptr ptr) secur32.LsaEnumerateLogonSessions
@ stdcall LsaFreeReturnBuffer(ptr) secur32.LsaFreeReturnBuffer
@ stdcall LsaGetLogonSessionData(ptr ptr) secur32.LsaGetLogonSessionData
@ stdcall LsaLogonUser(ptr ptr long long ptr long ptr ptr ptr ptr ptr ptr ptr ptr) secur32.LsaLogonUser
@ stdcall LsaLookupAuthenticationPackage(ptr ptr ptr) secur32.LsaLookupAuthenticationPackage
@ stdcall LsaRegisterLogonProcess(ptr ptr ptr) secur32.LsaRegisterLogonProcess
@ stdcall LsaRegisterPolicyChangeNotification(long ptr) secur32.LsaRegisterPolicyChangeNotification
@ stdcall LsaUnregisterPolicyChangeNotification(long ptr) secur32.LsaUnregisterPolicyChangeNotification
@ stdcall MakeSignature(ptr long ptr long) secur32.MakeSignature
@ stdcall QueryContextAttributesA(ptr long ptr) secur32.QueryContextAttributesA
@ stub QueryContextAttributesExA
@ stub QueryContextAttributesExW
@ stdcall QueryContextAttributesW(ptr long ptr) secur32.QueryContextAttributesW
@ stdcall QueryCredentialsAttributesA(ptr long ptr) secur32.QueryCredentialsAttributesA
@ stub QueryCredentialsAttributesExA
@ stub QueryCredentialsAttributesExW
@ stdcall QueryCredentialsAttributesW(ptr long ptr) secur32.QueryCredentialsAttributesW
@ stdcall QuerySecurityContextToken(ptr ptr) secur32.QuerySecurityContextToken
@ stdcall QuerySecurityPackageInfoA(str ptr) secur32.QuerySecurityPackageInfoA
@ stdcall QuerySecurityPackageInfoW(wstr ptr) secur32.QuerySecurityPackageInfoW
@ stdcall RevertSecurityContext(ptr) secur32.RevertSecurityContext
@ stdcall SaslAcceptSecurityContext(ptr ptr ptr long long ptr ptr long ptr) secur32.SaslAcceptSecurityContext
@ stdcall SaslEnumerateProfilesA(str ptr) secur32.SaslEnumerateProfilesA
@ stdcall SaslEnumerateProfilesW(wstr ptr) secur32.SaslEnumerateProfilesW
@ stdcall -stub SaslGetContextOption(ptr long ptr long ptr) secur32.SaslGetContextOption
@ stdcall SaslGetProfilePackageA(str ptr) secur32.SaslGetProfilePackageA
@ stdcall SaslGetProfilePackageW(wstr ptr) secur32.SaslGetProfilePackageW
@ stdcall SaslIdentifyPackageA(ptr ptr) secur32.SaslIdentifyPackageA
@ stdcall SaslIdentifyPackageW(ptr ptr) secur32.SaslIdentifyPackageW
@ stdcall SaslInitializeSecurityContextA(ptr ptr str long long long ptr long ptr ptr long ptr) secur32.SaslInitializeSecurityContextA
@ stdcall SaslInitializeSecurityContextW(ptr ptr wstr long long long ptr long ptr ptr long ptr) secur32.SaslInitializeSecurityContextW
@ stdcall -stub SaslSetContextOption(ptr long ptr long long) secur32.SaslSetContextOption
@ stdcall SealMessage(ptr long ptr long) secur32.SealMessage
@ stdcall SecCacheSspiPackages() secur32.SecCacheSspiPackages
@ stdcall SecDeleteUserModeContext(ptr) secur32.SecDeleteUserModeContext
@ stdcall -stub SeciAllocateAndSetCallFlags(ptr long) secur32.SeciAllocateAndSetCallFlags
@ stdcall -stub SeciAllocateAndSetIPAddress(ptr long long) secur32.SeciAllocateAndSetIPAddress
@ stdcall -stub SeciFreeCallContext() secur32.SeciFreeCallContext
@ stub SeciIsProtectedUser
@ stdcall SecInitUserModeContext(ptr ptr) secur32.SecInitUserModeContext
@ stdcall SetContextAttributesA(ptr long ptr long) secur32.SetContextAttributesA
@ stdcall SetContextAttributesW(ptr long ptr long) secur32.SetContextAttributesW
@ stdcall -stub SetCredentialsAttributesA(ptr long ptr long) secur32.SetCredentialsAttributesA
@ stdcall -stub SetCredentialsAttributesW(ptr long ptr long) secur32.SetCredentialsAttributesW
@ stub SspiCompareAuthIdentities
@ stub SspiCopyAuthIdentity
@ stub SspiDecryptAuthIdentity
@ stub SspiDecryptAuthIdentityEx
@ stdcall SspiEncodeAuthIdentityAsStrings(ptr ptr ptr ptr)
@ stdcall SspiEncodeStringsAsAuthIdentity(wstr wstr wstr ptr)
@ stub SspiEncryptAuthIdentity
@ stub SspiEncryptAuthIdentityEx
@ stub SspiExcludePackage
@ stdcall SspiFreeAuthIdentity(ptr)
@ stub SspiGetComputerNameForSPN
@ stub SspiGetTargetHostName
@ stub SspiIsAuthIdentityEncrypted
@ stdcall SspiLocalFree(ptr)
@ stub SspiMarshalAuthIdentity
@ stub SspiPrepareForCredRead
@ stdcall SspiPrepareForCredWrite(ptr wstr ptr ptr ptr ptr ptr)
@ stub SspiUnmarshalAuthIdentity
@ stub SspiUnmarshalAuthIdentityInternal
@ stub SspiValidateAuthIdentity
@ stdcall SspiZeroAuthIdentity(ptr)
@ stdcall UnsealMessage(ptr ptr long ptr) secur32.UnsealMessage
@ stdcall VerifySignature(ptr ptr long ptr) secur32.VerifySignature
