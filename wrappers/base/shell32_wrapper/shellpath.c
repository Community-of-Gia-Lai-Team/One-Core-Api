/*
 * Path Functions
 *
 * Copyright 1998, 1999, 2000 Juergen Schmied
 * Copyright 2004 Juan Lang
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 *
 * NOTES:
 *
 * Many of these functions are in SHLWAPI.DLL also
 *
 */

#define COBJMACROS

#include <main.h>
#include <userenv.h>

#define GUID_FORMAT "%08lX-%04hX-%04hX-%02hhX%02hhX-%02hhX%02hhX%02hhX%02hhX%02hhX%02hhX"
#define GUID_ARG(guid) guid->Data1, guid->Data2, guid->Data3, guid->Data4[0], guid->Data4[1], guid->Data4[2], guid->Data4[3], guid->Data4[4], guid->Data4[5], guid->Data4[6], guid->Data4[7]
#define GUID_ARG_NO_POINTER(guid) guid.Data1, guid.Data2, guid.Data3, guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]

static const GUID CLSID_UnixDosFolder = 
{0x9d20aae8, 0x0625, 0x44b0, {0x9c, 0xa7, 0x71, 0x88, 0x9c, 0x22, 0x54, 0xd9}};

const GUID FOLDERID_VideosLibrary;
const GUID FOLDERID_UsersLibraries;
const GUID FOLDERID_UsersFiles;
const GUID FOLDERID_UserProgramFilesCommon;
const GUID FOLDERID_UserProgramFiles;
const GUID FOLDERID_UserProfiles;
const GUID FOLDERID_UserPinned;
const GUID FOLDERID_SyncSetupFolder;
const GUID FOLDERID_SyncResultsFolder;
const GUID FOLDERID_SyncManagerFolder;
const GUID FOLDERID_SidebarParts;
const GUID FOLDERID_SidebarDefaultParts;
const GUID FOLDERID_SearchHome;
const GUID FOLDERID_SEARCH_MAPI;
const GUID FOLDERID_SEARCH_CSC;
const GUID FOLDERID_SavedSearches;
const GUID FOLDERID_SampleVideos;
const GUID FOLDERID_SamplePlaylists;
const GUID FOLDERID_SamplePictures;
const GUID FOLDERID_SampleMusic;
const GUID FOLDERID_Ringtones;
const GUID FOLDERID_RecordedTVLibrary;
const GUID FOLDERID_QuickLaunch;
const GUID FOLDERID_PublicRingtones;
const GUID FOLDERID_PublicLibraries;
const GUID FOLDERID_PublicGameTasks;
const GUID FOLDERID_PublicDownloads;
const GUID FOLDERID_Public;
const GUID FOLDERID_ProgramFilesCommonX64;
const GUID FOLDERID_ProgramFilesX64;
const GUID FOLDERID_Playlists;
const GUID FOLDERID_PicturesLibrary;
const GUID FOLDERID_PhotoAlbums;
const GUID FOLDERID_OriginalImages;
const GUID FOLDERID_MusicLibrary;
const GUID FOLDERID_LocalAppDataLow;
const GUID FOLDERID_Links;
const GUID FOLDERID_Libraries;
const GUID FOLDERID_ImplicitAppShortcuts;
const GUID FOLDERID_HomeGroup;
const GUID FOLDERID_GameTasks;
const GUID FOLDERID_Games;
const GUID FOLDERID_Downloads;
const GUID FOLDERID_SavedGames;
const GUID FOLDERID_DocumentsLibrary;
const GUID FOLDERID_DeviceMetadataStore;
const GUID FOLDERID_Contacts;
const GUID FOLDERID_ConflictFolder;
const GUID FOLDERID_ChangeRemovePrograms;
const GUID FOLDERID_AppUpdates;
const GUID FOLDERID_AddNewPrograms;
const GUID FOLDERID_CDBurning;
const GUID FOLDERID_CommonOEMLinks;
const GUID FOLDERID_LocalizedResourcesDir;
const GUID FOLDERID_ResourceDir;
const GUID FOLDERID_PublicVideos;
const GUID FOLDERID_PublicPictures;
const GUID FOLDERID_PublicMusic;
const GUID FOLDERID_ConnectionsFolder;
const GUID FOLDERID_AdminTools;
const GUID FOLDERID_CommonAdminTools;
const GUID FOLDERID_PublicDocuments;
const GUID FOLDERID_CommonTemplates;
const GUID FOLDERID_ProgramFilesCommonX86;
const GUID FOLDERID_ProgramFilesCommon;
const GUID FOLDERID_ProgramFilesX86;
const GUID FOLDERID_SystemX86;
const GUID FOLDERID_Profile;
const GUID FOLDERID_Pictures;
const GUID FOLDERID_ProgramFiles;
const GUID FOLDERID_System;
const GUID FOLDERID_Windows;
const GUID FOLDERID_ProgramData;
const GUID FOLDERID_History;
const GUID FOLDERID_Cookies;
const GUID FOLDERID_InternetCache;
const GUID FOLDERID_LocalAppData;
const GUID FOLDERID_PrintHood;
const GUID FOLDERID_RoamingAppData;
const GUID FOLDERID_PublicDesktop;
const GUID FOLDERID_CommonStartup;
const GUID FOLDERID_CommonPrograms;
const GUID FOLDERID_CommonStartMenu;
const GUID FOLDERID_Templates;
const GUID FOLDERID_Fonts;
const GUID FOLDERID_NetHood;
const GUID FOLDERID_NetworkFolder;
const GUID FOLDERID_ComputerFolder;
const GUID FOLDERID_Videos;
const GUID FOLDERID_Music;
const GUID GUID_NULL;
const GUID FOLDERID_StartMenu;
const GUID FOLDERID_RecycleBinFolder;
const GUID FOLDERID_SendTo;
const GUID FOLDERID_Recent;
const GUID FOLDERID_Startup;
const GUID FOLDERID_Favorites;
const GUID FOLDERID_Documents;
const GUID FOLDERID_PrintersFolder;
const GUID FOLDERID_Programs;
const GUID FOLDERID_InternetFolder;
const GUID FOLDERID_Desktop;
const GUID FOLDERID_ControlPanelFolder;
const GUID CLSID_NetworkPlaces;
const GUID CLSID_MyComputer;
const GUID CLSID_RecycleBin;
const GUID CLSID_Printers;
const GUID CLSID_ControlPanel;
const GUID CLSID_Internet;
const GUID CLSID_MyDocuments;

WINE_DEFAULT_DEBUG_CHANNEL(shell);

HRESULT 
WINAPI 
SHGetKnownFolderItem(
	REFKNOWNFOLDERID rfid, 
	KNOWN_FOLDER_FLAG flags, 
	HANDLE hToken,
    REFIID riid, 
	void **ppv
);

HRESULT 
WINAPI 
SHGetKnownFolderPath(
	REFKNOWNFOLDERID id, 
	DWORD flags, 
	HANDLE token, 
	PWSTR *path
);

HRESULT 
WINAPI
SHSetFolderPathW(
  _In_       int     csidl,
  _In_       HANDLE  hToken,
  _Reserved_ DWORD   dwFlags,
  _In_       LPCTSTR pszPath
);

csidl_from_id( const KNOWNFOLDERID *id );

static const BOOL is_win64 = sizeof(void *) > sizeof(int);

/*
	########## Combining and Constructing paths ##########
*/

static BOOL __inline SHELL_OsIsUnicode 	( 	void  		)
{
    /* if high-bit of version is 0, we are emulating NT */
    return !(GetVersion() & 0x80000000);
}

/* Basic PIDL constructor.  Allocates size + 5 bytes, where:
 * - two bytes are SHITEMID.cb
 * - one byte is PIDLDATA.type
 * - two bytes are the NULL PIDL terminator
 * Sets type of the returned PIDL to type.
 */
static LPITEMIDLIST _ILAlloc(PIDLTYPE type, unsigned int size)
{
    LPITEMIDLIST pidlOut = NULL;

    pidlOut = SHAlloc(size + 5);
    if(pidlOut)
    {
        LPPIDLDATA pData;
        LPITEMIDLIST pidlNext;

        ZeroMemory(pidlOut, size + 5);
        pidlOut->mkid.cb = size + 3;

        pData = _ILGetDataPointer(pidlOut);
        if (pData)
            pData->type = type;

        pidlNext = ILGetNext(pidlOut);
        if (pidlNext)
            pidlNext->mkid.cb = 0x00;
        TRACE("-- (pidl=%p, size=%u)\n", pidlOut, size);
    }

    return pidlOut;
}

LPITEMIDLIST _ILCreateGuid(PIDLTYPE type, REFIID guid)
{
    LPITEMIDLIST pidlOut;

    if (type == PT_SHELLEXT || type == PT_GUID || type == PT_YAGUID)
    {
        pidlOut = _ILAlloc(type, sizeof(GUIDStruct));
        if (pidlOut)
        {
            LPPIDLDATA pData = _ILGetDataPointer(pidlOut);

            pData->u.guid.guid = *guid;
            TRACE("-- create GUID-pidl %s\n",
                  debugstr_guid(&(pData->u.guid.guid)));
        }
    }
    else
    {
        WARN("%d: invalid type for GUID\n", type);
        pidlOut = NULL;
    }
    return pidlOut;
}

LPITEMIDLIST _ILCreateNetwork(void)
{
    TRACE("()\n");
    return _ILCreateGuid(PT_GUID, &CLSID_NetworkPlaces);
}

BOOL _ILIsDesktop(LPCITEMIDLIST pidl)
{
    TRACE("(%p)\n",pidl);

    return !pidl || !pidl->mkid.cb;
}

LPITEMIDLIST _ILCreateMyComputer(void)
{
    TRACE("()\n");
    return _ILCreateGuid(PT_GUID, &CLSID_MyComputer);
}

LPITEMIDLIST _ILCreateBitBucket(void)
{
    TRACE("()\n");
    return _ILCreateGuid(PT_GUID, &CLSID_RecycleBin);
}

LPITEMIDLIST _ILCreateDesktop(void)
{
    LPITEMIDLIST ret;

    TRACE("()\n");
    ret = SHAlloc(2);
    if (ret)
        ret->mkid.cb = 0;
    return ret;
}

LPITEMIDLIST _ILCreatePrinters(void)
{
    LPITEMIDLIST parent = _ILCreateGuid(PT_GUID, &CLSID_MyComputer), ret = NULL;

    TRACE("()\n");
    if (parent)
    {
        LPITEMIDLIST printers = _ILCreateGuid(PT_YAGUID, &CLSID_Printers);

        if (printers)
        {
            ret = ILCombine(parent, printers);
            SHFree(printers);
        }
        SHFree(parent);
    }
    return ret;
}

LPITEMIDLIST _ILCreateControlPanel(void)
{
    LPITEMIDLIST parent = _ILCreateGuid(PT_GUID, &CLSID_MyComputer), ret = NULL;

    TRACE("()\n");
    if (parent)
    {
        LPITEMIDLIST cpl = _ILCreateGuid(PT_SHELLEXT, &CLSID_ControlPanel);

        if (cpl)
        {
            ret = ILCombine(parent, cpl);
            SHFree(cpl);
        }
        SHFree(parent);
    }
    return ret;
}

LPITEMIDLIST _ILCreateIExplore(void)
{
    TRACE("()\n");
    return _ILCreateGuid(PT_GUID, &CLSID_Internet);
}

LPITEMIDLIST _ILCreateMyDocuments(void)
{
    TRACE("()\n");
    return _ILCreateGuid(PT_GUID, &CLSID_MyDocuments);
}

static const WCHAR szCategory[] = {'C','a','t','e','g','o','r','y',0};
static const WCHAR szAttributes[] = {'A','t','t','r','i','b','u','t','e','s',0};
static const WCHAR szName[] = {'N','a','m','e',0};
static const WCHAR szParsingName[] = {'P','a','r','s','i','n','g','N','a','m','e',0};
static const WCHAR szRelativePath[] = {'R','e','l','a','t','i','v','e','P','a','t','h',0};
static const WCHAR szParentFolder[] = {'P','a','r','e','n','t','F','o','l','d','e','r',0};

static const WCHAR szCurrentVersion[] = {'S','o','f','t','w','a','r','e','\\','M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','C','u','r','r','e','n','t','V','e','r','s','i','o','n','\0'};
static const WCHAR AddNewProgramsFolderW[] = {'A','d','d','N','e','w','P','r','o','g','r','a','m','s','F','o','l','d','e','r',0};
static const WCHAR AppUpdatesFolderW[] = {'A','p','p','U','p','d','a','t','e','s','F','o','l','d','e','r',0};
static const WCHAR Administrative_ToolsW[] = {'A','d','m','i','n','i','s','t','r','a','t','i','v','e',' ','T','o','o','l','s','\0'};
static const WCHAR AppDataW[] = {'A','p','p','D','a','t','a','\0'};
static const WCHAR AppData_RoamingW[] = {'A','p','p','D','a','t','a','\\','R','o','a','m','i','n','g','\0'};
static const WCHAR AppData_LocalLowW[] = {'A','p','p','D','a','t','a','\\','L','o','c','a','l','L','o','w','\0'};
static const WCHAR AppData_LocalW[] = {'A','p','p','D','a','t','a','\\','L','o','c','a','l','\0'};
static const WCHAR Application_DataW[] = {'A','p','p','l','i','c','a','t','i','o','n',' ','D','a','t','a','\0'};
static const WCHAR CacheW[] = {'C','a','c','h','e','\0'};
static const WCHAR CD_BurningW[] = {'C','D',' ','B','u','r','n','i','n','g','\0'};
static const WCHAR ChangeRemoveProgramsFolderW[] = {'C','h','a','n','g','e','R','e','m','o','v','e','P','r','o','g','r','a','m','s','F','o','l','d','e','r',0};
static const WCHAR CommonW[] = {'C','o','m','m','o','n',0};
static const WCHAR Common_Administrative_ToolsW[] = {'C','o','m','m','o','n',' ','A','d','m','i','n','i','s','t','r','a','t','i','v','e',' ','T','o','o','l','s','\0'};
static const WCHAR Common_AppDataW[] = {'C','o','m','m','o','n',' ','A','p','p','D','a','t','a','\0'};
static const WCHAR Common_DesktopW[] = {'C','o','m','m','o','n',' ','D','e','s','k','t','o','p','\0'};
static const WCHAR Common_DocumentsW[] = {'C','o','m','m','o','n',' ','D','o','c','u','m','e','n','t','s','\0'};
static const WCHAR CommonDownloadsW[] = {'C','o','m','m','o','n','D','o','w','n','l','o','a','d','s',0};
static const WCHAR Common_FavoritesW[] = {'C','o','m','m','o','n',' ','F','a','v','o','r','i','t','e','s','\0'};
static const WCHAR CommonFilesDirW[] = {'C','o','m','m','o','n','F','i','l','e','s','D','i','r','\0'};
static const WCHAR CommonFilesDirX86W[] = {'C','o','m','m','o','n','F','i','l','e','s','D','i','r',' ','(','x','8','6',')','\0'};
static const WCHAR CommonMusicW[] = {'C','o','m','m','o','n','M','u','s','i','c','\0'};
static const WCHAR CommonPicturesW[] = {'C','o','m','m','o','n','P','i','c','t','u','r','e','s','\0'};
static const WCHAR Common_ProgramsW[] = {'C','o','m','m','o','n',' ','P','r','o','g','r','a','m','s','\0'};
static const WCHAR CommonRingtonesW[] = {'C','o','m','m','o','n','R','i','n','g','t','o','n','e','s',0};
static const WCHAR Common_StartUpW[] = {'C','o','m','m','o','n',' ','S','t','a','r','t','U','p','\0'};
static const WCHAR Common_StartupW[] = {'C','o','m','m','o','n',' ','S','t','a','r','t','u','p','\0'};
static const WCHAR Common_Start_MenuW[] = {'C','o','m','m','o','n',' ','S','t','a','r','t',' ','M','e','n','u','\0'};
static const WCHAR Common_TemplatesW[] = {'C','o','m','m','o','n',' ','T','e','m','p','l','a','t','e','s','\0'};
static const WCHAR CommonVideoW[] = {'C','o','m','m','o','n','V','i','d','e','o','\0'};
static const WCHAR ConflictFolderW[] = {'C','o','n','f','l','i','c','t','F','o','l','d','e','r',0};
static const WCHAR ConnectionsFolderW[] = {'C','o','n','n','e','c','t','i','o','n','s','F','o','l','d','e','r',0};
static const WCHAR ContactsW[] = {'C','o','n','t','a','c','t','s','\0'};
static const WCHAR ControlPanelFolderW[] = {'C','o','n','t','r','o','l','P','a','n','e','l','F','o','l','d','e','r',0};
static const WCHAR CookiesW[] = {'C','o','o','k','i','e','s','\0'};
static const WCHAR CSCFolderW[] = {'C','S','C','F','o','l','d','e','r',0};
static const WCHAR Default_GadgetsW[] = {'D','e','f','a','u','l','t',' ','G','a','d','g','e','t','s',0};
static const WCHAR DesktopW[] = {'D','e','s','k','t','o','p','\0'};
static const WCHAR Device_Metadata_StoreW[] = {'D','e','v','i','c','e',' ','M','e','t','a','d','a','t','a',' ','S','t','o','r','e',0};
static const WCHAR DocumentsW[] = {'D','o','c','u','m','e','n','t','s','\0'};
static const WCHAR DocumentsLibraryW[] = {'D','o','c','u','m','e','n','t','s','L','i','b','r','a','r','y','\0'};
static const WCHAR Documents_librarymsW[] = {'D','o','c','u','m','e','n','t','s','.','l','i','b','r','a','r','y','-','m','s',0};
static const WCHAR DownloadsW[] = {'D','o','w','n','l','o','a','d','s','\0'};
static const WCHAR FavoritesW[] = {'F','a','v','o','r','i','t','e','s','\0'};
static const WCHAR FontsW[] = {'F','o','n','t','s','\0'};
static const WCHAR GadgetsW[] = {'G','a','d','g','e','t','s',0};
static const WCHAR GamesW[] = {'G','a','m','e','s',0};
static const WCHAR GameTasksW[] = {'G','a','m','e','T','a','s','k','s',0};
static const WCHAR HistoryW[] = {'H','i','s','t','o','r','y','\0'};
static const WCHAR HomeGroupFolderW[] = {'H','o','m','e','G','r','o','u','p','F','o','l','d','e','r',0};
static const WCHAR ImplicitAppShortcutsW[] = {'I','m','p','l','i','c','i','t','A','p','p','S','h','o','r','t','c','u','t','s',0};
static const WCHAR InternetFolderW[] = {'I','n','t','e','r','n','e','t','F','o','l','d','e','r',0};
static const WCHAR LibrariesW[] = {'L','i','b','r','a','r','i','e','s',0};
static const WCHAR LinksW[] = {'L','i','n','k','s','\0'};
static const WCHAR Local_AppDataW[] = {'L','o','c','a','l',' ','A','p','p','D','a','t','a','\0'};
static const WCHAR Local_Settings_Application_DataW[] = {'L','o','c','a','l',' ','S','e','t','t','i','n','g','s','\\','A','p','p','l','i','c','a','t','i','o','n',' ','D','a','t','a','\0'};
static const WCHAR Local_Settings_CD_BurningW[] = {'L','o','c','a','l',' ','S','e','t','t','i','n','g','s','\\','A','p','p','l','i','c','a','t','i','o','n',' ','D','a','t','a','\\','M','i','c','r','o','s','o','f','t','\\','C','D',' ','B','u','r','n','i','n','g','\0'};
static const WCHAR Local_Settings_HistoryW[] = {'L','o','c','a','l',' ','S','e','t','t','i','n','g','s','\\','H','i','s','t','o','r','y','\0'};
static const WCHAR Local_Settings_Temporary_Internet_FilesW[] = {'L','o','c','a','l',' ','S','e','t','t','i','n','g','s','\\','T','e','m','p','o','r','a','r','y',' ','I','n','t','e','r','n','e','t',' ','F','i','l','e','s','\0'};
static const WCHAR LocalAppDataLowW[] = {'L','o','c','a','l','A','p','p','D','a','t','a','L','o','w',0};
static const WCHAR LocalizedResourcesDirW[] = {'L','o','c','a','l','i','z','e','d','R','e','s','o','u','r','c','e','s','D','i','r',0};
static const WCHAR MAPIFolderW[] = {'M','A','P','I','F','o','l','d','e','r',0};
static const WCHAR Microsoft_Internet_Explorer_Quick_LaunchW[] = {'M','i','c','r','o','s','o','f','t','\\','I','n','t','e','r','n','e','t',' ','E','x','p','l','o','r','e','r','\\','Q','u','i','c','k',' ','L','a','u','n','c','h',0};
static const WCHAR Microsoft_Windows_Burn_BurnW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','B','u','r','n','\\','B','u','r','n',0};
static const WCHAR Microsoft_Windows_CookiesW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','C','o','o','k','i','e','s',0};
static const WCHAR Microsoft_Windows_GameExplorerW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','G','a','m','e','E','x','p','l','o','r','e','r','\0'};
static const WCHAR Microsoft_Windows_DeviceMetadataStoreW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','D','e','v','i','c','e','M','e','t','a','d','a','t','a','S','t','o','r','e',0};
static const WCHAR Microsoft_Windows_HistoryW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','H','i','s','t','o','r','y',0};
static const WCHAR Microsoft_Windows_LibrariesW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','L','i','b','r','a','r','i','e','s','\0'};
static const WCHAR Microsoft_Windows_Network_ShortcutsW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','N','e','t','w','o','r','k',' ','S','h','o','r','t','c','u','t','s',0};
static const WCHAR Microsoft_Windows_Photo_Gallery_Original_ImagesW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s',' ','P','h','o','t','o',' ','G','a','l','l','e','r','y','\\','O','r','i','g','i','n','a','l',' ','I','m','a','g','e','s',0};
static const WCHAR Microsoft_Windows_Printer_ShortcutsW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','P','r','i','n','t','e','r',' ','S','h','o','r','t','c','u','t','s',0};
static const WCHAR Microsoft_Windows_RecentW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','R','e','c','e','n','t','\0'};
static const WCHAR Microsoft_Windows_RingtonesW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','R','i','n','g','t','o','n','e','s','\0'};
static const WCHAR Microsoft_Windows_SendToW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','S','e','n','d','T','o',0};
static const WCHAR Microsoft_Windows_Sidebar_GadgetsW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s',' ','S','i','d','e','b','a','r','\\','G','a','d','g','e','t','s',0};
static const WCHAR Microsoft_Windows_Start_MenuW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','S','t','a','r','t',' ','M','e','n','u',0};
static const WCHAR Microsoft_Windows_Start_Menu_ProgramsW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','S','t','a','r','t',' ','M','e','n','u','\\','P','r','o','g','r','a','m','s','\0'};
static const WCHAR Microsoft_Windows_Start_Menu_Admin_ToolsW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','S','t','a','r','t',' ','M','e','n','u','\\','P','r','o','g','r','a','m','s','\\','A','d','m','i','n','i','s','t','r','a','t','i','v','e',' ','T','o','o','l','s','\0'};
static const WCHAR Microsoft_Windows_Start_Menu_StartupW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','S','t','a','r','t',' ','M','e','n','u','\\','P','r','o','g','r','a','m','s','\\','S','t','a','r','t','U','p','\0'};
static const WCHAR Microsoft_Windows_TemplatesW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','T','e','m','p','l','a','t','e','s',0};
static const WCHAR Microsoft_Windows_Temporary_Internet_FilesW[] = {'M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','T','e','m','p','o','r','a','r','y',' ','I','n','t','e','r','n','e','t',' ','F','i','l','e','s',0};
static const WCHAR MoviesW[] = {'M','o','v','i','e','s','\0'};
static const WCHAR MusicW[] = {'M','u','s','i','c','\0'};
static const WCHAR MusicLibraryW[] = {'M','u','s','i','c','L','i','b','r','a','r','y',0};
static const WCHAR Music_librarymsW[] = {'M','u','s','i','c','.','l','i','b','r','a','r','y','-','m','s',0};
static const WCHAR Music_PlaylistsW[] = {'M','u','s','i','c','\\','P','l','a','y','l','i','s','t','s','\0'};
static const WCHAR Music_Sample_MusicW[] = {'M','u','s','i','c','\\','S','a','m','p','l','e',' ','M','u','s','i','c','\0'};
static const WCHAR Music_Sample_PlaylistsW[] = {'M','u','s','i','c','\\','S','a','m','p','l','e',' ','P','l','a','y','l','i','s','t','s','\0'};
static const WCHAR My_MusicW[] = {'M','y',' ','M','u','s','i','c','\0'};
static const WCHAR My_PicturesW[] = {'M','y',' ','P','i','c','t','u','r','e','s','\0'};
static const WCHAR My_VideosW[] = {'M','y',' ','V','i','d','e','o','s','\0'};
static const WCHAR My_VideoW[] = {'M','y',' ','V','i','d','e','o','\0'};
static const WCHAR MyComputerFolderW[] = {'M','y','C','o','m','p','u','t','e','r','F','o','l','d','e','r',0};
static const WCHAR NetHoodW[] = {'N','e','t','H','o','o','d','\0'};
static const WCHAR NetworkPlacesFolderW[] = {'N','e','t','w','o','r','k','P','l','a','c','e','s','F','o','l','d','e','r',0};
static const WCHAR OEM_LinksW[] = {'O','E','M',' ','L','i','n','k','s','\0'};
static const WCHAR Original_ImagesW[] = {'O','r','i','g','i','n','a','l',' ','I','m','a','g','e','s',0};
static const WCHAR PersonalW[] = {'P','e','r','s','o','n','a','l','\0'};
static const WCHAR PhotoAlbumsW[] = {'P','h','o','t','o','A','l','b','u','m','s',0};
static const WCHAR PicturesW[] = {'P','i','c','t','u','r','e','s','\0'};
static const WCHAR PicturesLibraryW[] = {'P','i','c','t','u','r','e','s','L','i','b','r','a','r','y',0};
static const WCHAR Pictures_librarymsW[] = {'P','i','c','t','u','r','e','s','.','l','i','b','r','a','r','y','-','m','s',0};
static const WCHAR Pictures_Sample_PicturesW[] = {'P','i','c','t','u','r','e','s','\\','S','a','m','p','l','e',' ','P','i','c','t','u','r','e','s','\0'};
static const WCHAR Pictures_Slide_ShowsW[] = {'P','i','c','t','u','r','e','s','\\','S','l','i','d','e',' ','S','h','o','w','s','\0'};
static const WCHAR PlaylistsW[] = {'P','l','a','y','l','i','s','t','s',0};
static const WCHAR PrintersFolderW[] = {'P','r','i','n','t','e','r','s','F','o','l','d','e','r',0};
static const WCHAR PrintHoodW[] = {'P','r','i','n','t','H','o','o','d','\0'};
static const WCHAR ProfileW[] = {'P','r','o','f','i','l','e',0};
static const WCHAR ProgramDataW[] = {'P','r','o','g','r','a','m','D','a','t','a','\0'};
static const WCHAR Program_FilesW[] = {'P','r','o','g','r','a','m',' ','F','i','l','e','s','\0'};
static const WCHAR ProgramFilesW[] = {'P','r','o','g','r','a','m','F','i','l','e','s','\0'};
static const WCHAR ProgramFilesX86W[] = {'P','r','o','g','r','a','m','F','i','l','e','s','X','8','6','\0'};
static const WCHAR ProgramFilesX64W[] = {'P','r','o','g','r','a','m','F','i','l','e','s','X','6','4','\0'};
static const WCHAR Program_Files_Common_FilesW[] = {'P','r','o','g','r','a','m',' ','F','i','l','e','s','\\','C','o','m','m','o','n',' ','F','i','l','e','s','\0'};
static const WCHAR Program_Files_x86W[] = {'P','r','o','g','r','a','m',' ','F','i','l','e','s',' ','(','x','8','6',')','\0'};
static const WCHAR Program_Files_x86_Common_FilesW[] = {'P','r','o','g','r','a','m',' ','F','i','l','e','s',' ','(','x','8','6',')','\\','C','o','m','m','o','n',' ','F','i','l','e','s','\0'};
static const WCHAR ProgramFilesCommonW[] = {'P','r','o','g','r','a','m','F','i','l','e','s','C','o','m','m','o','n',0};
static const WCHAR ProgramFilesCommonX86W[] = {'P','r','o','g','r','a','m','F','i','l','e','s','C','o','m','m','o','n','X','8','6',0};
static const WCHAR ProgramFilesCommonX64W[] = {'P','r','o','g','r','a','m','F','i','l','e','s','C','o','m','m','o','n','X','6','4',0};
static const WCHAR ProgramFilesDirW[] = {'P','r','o','g','r','a','m','F','i','l','e','s','D','i','r','\0'};
static const WCHAR ProgramFilesDirX86W[] = {'P','r','o','g','r','a','m','F','i','l','e','s','D','i','r',' ','(','x','8','6',')','\0'};
static const WCHAR ProgramsW[] = {'P','r','o','g','r','a','m','s','\0'};
static const WCHAR PublicW[] = {'P','u','b','l','i','c',0};
static const WCHAR PublicGameTasksW[] = {'P','u','b','l','i','c','G','a','m','e','T','a','s','k','s',0};
static const WCHAR PublicLibrariesW[] = {'P','u','b','l','i','c','L','i','b','r','a','r','i','e','s',0};
static const WCHAR Quick_LaunchW[] = {'Q','u','i','c','k',' ','L','a','u','n','c','h',0};
static const WCHAR RecentW[] = {'R','e','c','e','n','t','\0'};
static const WCHAR RecordedTVLibraryW[] = {'R','e','c','o','r','d','e','d','T','V','L','i','b','r','a','r','y',0};
static const WCHAR RecordedTV_librarymsW[] = {'R','e','c','o','r','d','e','d','T','V','.','l','i','b','r','a','r','y','-','m','s',0};
static const WCHAR RecycleBinFolderW[] = {'R','e','c','y','c','l','e','B','i','n','F','o','l','d','e','r',0};
static const WCHAR ResourceDirW[] = {'R','e','s','o','u','r','c','e','D','i','r','\0'};
static const WCHAR ResourcesW[] = {'R','e','s','o','u','r','c','e','s','\0'};
static const WCHAR RingtonesW[] = {'R','i','n','g','t','o','n','e','s',0};
static const WCHAR SampleMusicW[] = {'S','a','m','p','l','e','M','u','s','i','c',0};
static const WCHAR Sample_MusicW[] = {'S','a','m','p','l','e',' ','M','u','s','i','c',0};
static const WCHAR SamplePicturesW[] = {'S','a','m','p','l','e','P','i','c','t','u','r','e','s',0};
static const WCHAR Sample_PicturesW[] = {'S','a','m','p','l','e',' ','P','i','c','t','u','r','e','s',0};
static const WCHAR SamplePlaylistsW[] = {'S','a','m','p','l','e','P','l','a','y','l','i','s','t','s',0};
static const WCHAR Sample_PlaylistsW[] = {'S','a','m','p','l','e',' ','P','l','a','y','l','i','s','t','s',0};
static const WCHAR Sample_VideosW[] = {'S','a','m','p','l','e',' ','V','i','d','e','o','s',0};
static const WCHAR SampleVideosW[] = {'S','a','m','p','l','e','V','i','d','e','o','s',0};
static const WCHAR Saved_GamesW[] = {'S','a','v','e','d',' ','G','a','m','e','s','\0'};
static const WCHAR SavedGamesW[] = {'S','a','v','e','d','G','a','m','e','s','\0'};
static const WCHAR SearchesW[] = {'S','e','a','r','c','h','e','s','\0'};
static const WCHAR SearchHomeFolderW[] = {'S','e','a','r','c','h','H','o','m','e','F','o','l','d','e','r',0};
static const WCHAR SendToW[] = {'S','e','n','d','T','o','\0'};
static const WCHAR Slide_ShowsW[] = {'S','l','i','d','e',' ','S','h','o','w','s',0};
static const WCHAR StartUpW[] = {'S','t','a','r','t','U','p','\0'};
static const WCHAR StartupW[] = {'S','t','a','r','t','u','p','\0'};
static const WCHAR Start_MenuW[] = {'S','t','a','r','t',' ','M','e','n','u','\0'};
static const WCHAR Start_Menu_ProgramsW[] = {'S','t','a','r','t',' ','M','e','n','u','\\','P','r','o','g','r','a','m','s','\0'};
static const WCHAR Start_Menu_Admin_ToolsW[] = {'S','t','a','r','t',' ','M','e','n','u','\\','P','r','o','g','r','a','m','s','\\','A','d','m','i','n','i','s','t','r','a','t','i','v','e',' ','T','o','o','l','s','\0'};
static const WCHAR Start_Menu_StartupW[] = {'S','t','a','r','t',' ','M','e','n','u','\\','P','r','o','g','r','a','m','s','\\','S','t','a','r','t','U','p','\0'};
static const WCHAR SyncCenterFolderW[] = {'S','y','n','c','C','e','n','t','e','r','F','o','l','d','e','r',0};
static const WCHAR SyncResultsFolderW[] = {'S','y','n','c','R','e','s','u','l','t','s','F','o','l','d','e','r',0};
static const WCHAR SyncSetupFolderW[] = {'S','y','n','c','S','e','t','u','p','F','o','l','d','e','r',0};
static const WCHAR SystemW[] = {'S','y','s','t','e','m',0};
static const WCHAR SystemX86W[] = {'S','y','s','t','e','m','X','8','6',0};
static const WCHAR TemplatesW[] = {'T','e','m','p','l','a','t','e','s','\0'};
static const WCHAR User_PinnedW[] = {'U','s','e','r',' ','P','i','n','n','e','d',0};
static const WCHAR UsersW[] = {'U','s','e','r','s','\0'};
static const WCHAR UsersFilesFolderW[] = {'U','s','e','r','s','F','i','l','e','s','F','o','l','d','e','r',0};
static const WCHAR UsersLibrariesFolderW[] = {'U','s','e','r','s','L','i','b','r','a','r','i','e','s','F','o','l','d','e','r',0};
static const WCHAR UserProfilesW[] = {'U','s','e','r','P','r','o','f','i','l','e','s',0};
static const WCHAR UserProgramFilesW[] = {'U','s','e','r','P','r','o','g','r','a','m','F','i','l','e','s',0};
static const WCHAR UserProgramFilesCommonW[] = {'U','s','e','r','P','r','o','g','r','a','m','F','i','l','e','s','C','o','m','m','o','n',0};
static const WCHAR UsersPublicW[] = {'U','s','e','r','s','\\','P','u','b','l','i','c','\0'};
static const WCHAR VideosW[] = {'V','i','d','e','o','s','\0'};
static const WCHAR VideosLibraryW[] = {'V','i','d','e','o','s','L','i','b','r','a','r','y',0};
static const WCHAR Videos_librarymsW[] = {'V','i','d','e','o','s','.','l','i','b','r','a','r','y','-','m','s',0};
static const WCHAR Videos_Sample_VideosW[] = {'V','i','d','e','o','s','\\','S','a','m','p','l','e',' ','V','i','d','e','o','s','\0'};
static const WCHAR WindowsW[] = {'W','i','n','d','o','w','s',0};
static const WCHAR Windows_Sidebar_GadgetsW[] = {'W','i','n','d','o','w','s',' ','S','i','d','e','b','a','r','\\','G','a','d','g','e','t','s',0};
static const WCHAR DefaultW[] = {'.','D','e','f','a','u','l','t','\0'};
static const WCHAR AllUsersProfileW[] = {'%','A','L','L','U','S','E','R','S','P','R','O','F','I','L','E','%','\0'};
static const WCHAR UserProfileW[] = {'%','U','S','E','R','P','R','O','F','I','L','E','%','\0'};
static const WCHAR ProgramDataVarW[] = {'%','P','r','o','g','r','a','m','D','a','t','a','%','\0'};
static const WCHAR SystemDriveW[] = {'%','S','y','s','t','e','m','D','r','i','v','e','%','\0'};
static const WCHAR ProfileListW[] = {'S','o','f','t','w','a','r','e','\\','M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s',' ','N','T','\\','C','u','r','r','e','n','t','V','e','r','s','i','o','n','\\','P','r','o','f','i','l','e','L','i','s','t',0};
static const WCHAR ProfilesDirectoryW[] = {'P','r','o','f','i','l','e','s','D','i','r','e','c','t','o','r','y',0};
static const WCHAR AllUsersProfileValueW[] = {'A','l','l','U','s','e','r','s','P','r','o','f','i','l','e','\0'};
static const WCHAR szSHFolders[] = {'S','o','f','t','w','a','r','e','\\','M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','C','u','r','r','e','n','t','V','e','r','s','i','o','n','\\','E','x','p','l','o','r','e','r','\\','S','h','e','l','l',' ','F','o','l','d','e','r','s','\0'};
static const WCHAR szSHUserFolders[] = {'S','o','f','t','w','a','r','e','\\','M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','C','u','r','r','e','n','t','V','e','r','s','i','o','n','\\','E','x','p','l','o','r','e','r','\\','U','s','e','r',' ','S','h','e','l','l',' ','F','o','l','d','e','r','s','\0'};
static const WCHAR szDefaultProfileDirW[] = {'u','s','e','r','s',0};
static const WCHAR szKnownFolderDescriptions[] = {'S','o','f','t','w','a','r','e','\\','M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','C','u','r','r','e','n','t','V','e','r','s','i','o','n','\\','E','x','p','l','o','r','e','r','\\','F','o','l','d','e','r','D','e','s','c','r','i','p','t','i','o','n','s','\0'};
static const WCHAR szKnownFolderRedirections[] = {'S','o','f','t','w','a','r','e','\\','M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','C','u','r','r','e','n','t','V','e','r','s','i','o','n','\\','E','x','p','l','o','r','e','r','\\','U','s','e','r',' ','S','h','e','l','l',' ','F','o','l','d','e','r','s',0};
static const WCHAR AllUsersW[] = {'P','u','b','l','i','c',0};

#define CHANGEREMOVEPROGRAMS_PARSING_GUID '{','7','b','8','1','b','e','6','a','-','c','e','2','b','-','4','6','7','6','-','a','2','9','e','-','e','b','9','0','7','a','5','1','2','6','c','5','}'
#define SYNCMANAGER_PARSING_GUID '{','9','C','7','3','F','5','E','5','-','7','A','E','7','-','4','E','3','2','-','A','8','E','8','-','8','D','2','3','B','8','5','2','5','5','B','F','}'
#define SYSTEMFOLDERS_PARSING_GUID '{','2','1','E','C','2','0','2','0','-','3','A','E','A','-','1','0','6','9','-','A','2','D','D','-','0','8','0','0','2','B','3','0','3','0','9','D','}'
#define USERFOLDERS_PARSING_GUID '{','5','9','0','3','1','a','4','7','-','3','f','7','2','-','4','4','a','7','-','8','9','c','5','-','5','5','9','5','f','e','6','b','3','0','e','e','}'
#define USERSLIBRARIES_PARSING_GUID '{','0','3','1','E','4','8','2','5','-','7','B','9','4','-','4','d','c','3','-','B','1','3','1','-','E','9','4','6','B','4','4','C','8','D','D','5','}'

static const WCHAR ComputerFolderParsingNameW[] = {':',':','{','2','0','D','0','4','F','E','0','-','3','A','E','A','-','1','0','6','9','-','A','2','D','8','-','0','8','0','0','2','B','3','0','3','0','9','D','}',0};
static const WCHAR ControlPanelFolderParsingNameW[] = {':',':','{','2','6','E','E','0','6','6','8','-','A','0','0','A','-','4','4','D','7','-','9','3','7','1','-','B','E','B','0','6','4','C','9','8','6','8','3','}','\\','0',0};
static const WCHAR ControlPanelFolderRelativePathW[] = {':',':','{','2','1','E','C','2','0','2','0','-','3','A','E','A','-','1','0','6','9','-','A','2','D','D','-','0','8','0','0','2','B','3','0','3','0','9','D','}',0};
static const WCHAR GamesParsingNameW[] = {':',':','{','E','D','2','2','8','F','D','F','-','9','E','A','8','-','4','8','7','0','-','8','3','b','1','-','9','6','b','0','2','C','F','E','0','D','5','2','}',0};
static const WCHAR HomeGroupParsingNameW[] = {':',':','{','B','4','F','B','3','F','9','8','-','C','1','E','A','-','4','2','8','d','-','A','7','8','A','-','D','1','F','5','6','5','9','C','B','A','9','3','}',0};
static const WCHAR InternetFolderParsingNameW[] = {':',':','{','8','7','1','C','5','3','8','0','-','4','2','A','0','-','1','0','6','9','-','A','2','E','A','-','0','8','0','0','2','B','3','0','3','0','9','D','}',0};
static const WCHAR NetworkFolderParsingNameW[] = {':',':','{','F','0','2','C','1','A','0','D','-','B','E','2','1','-','4','3','5','0','-','8','8','B','0','-','7','3','6','7','F','C','9','6','E','F','3','C','}',0};
static const WCHAR PublicParsingNameW[] = {':',':','{','4','3','3','6','a','5','4','d','-','0','3','8','b','-','4','6','8','5','-','a','b','0','2','-','9','9','b','b','5','2','d','3','f','b','8','b','}',0};
static const WCHAR RecycleBinFolderParsingNameW[] = {':',':','{','6','4','5','F','F','0','4','0','-','5','0','8','1','-','1','0','1','B','-','9','F','0','8','-','0','0','A','A','0','0','2','F','9','5','4','E','}',0};
static const WCHAR SearchHomeParsingNameW[] = {':',':','{','9','3','4','3','8','1','2','e','-','1','c','3','7','-','4','a','4','9','-','a','1','2','e','-','4','b','2','d','8','1','0','d','9','5','6','b','}',0};
static const WCHAR SEARCH_CSCParsingNameW[] = {'s','h','e','l','l',':',':',':','{','B','D','7','A','2','E','7','B','-','2','1','C','B','-','4','1','b','2','-','A','0','8','6','-','B','3','0','9','6','8','0','C','6','B','7','E','}','\\','*',0};
static const WCHAR SEARCH_MAPIParsingNameW[] = {'s','h','e','l','l',':',':',':','{','8','9','D','8','3','5','7','6','-','6','B','D','1','-','4','C','8','6','-','9','4','5','4','-','B','E','B','0','4','E','9','4','C','8','1','9','}','\\','*',0};
static const WCHAR UsersFilesParsingNameW[] = {':',':','{','5','9','0','3','1','a','4','7','-','3','f','7','2','-','4','4','a','7','-','8','9','c','5','-','5','5','9','5','f','e','6','b','3','0','e','e','}',0};
static const WCHAR UsersLibrariesParsingNameW[] = {':',':','{','0','3','1','E','4','8','2','5','-','7','B','9','4','-','4','d','c','3','-','B','1','3','1','-','E','9','4','6','B','4','4','C','8','D','D','5','}',0};
static const WCHAR AddNewProgramsParsingNameW[] = {':',':', SYSTEMFOLDERS_PARSING_GUID, '\\',':',':','{','1','5','e','a','e','9','2','e','-','f','1','7','a','-','4','4','3','1','-','9','f','2','8','-','8','0','5','e','4','8','2','d','a','f','d','4','}',0};
static const WCHAR ConnectionsFolderParsingNameW[] = {':',':', SYSTEMFOLDERS_PARSING_GUID, '\\',':',':','{','7','0','0','7','A','C','C','7','-','3','2','0','2','-','1','1','D','1','-','A','A','D','2','-','0','0','8','0','5','F','C','1','2','7','0','E','}',0};
static const WCHAR PrintersFolderParsingNameW[] = {':',':', SYSTEMFOLDERS_PARSING_GUID, '\\',':',':','{','2','2','2','7','A','2','8','0','-','3','A','E','A','-','1','0','6','9','-','A','2','D','E','-','0','8','0','0','2','B','3','0','3','0','9','D','}',0};
static const WCHAR ChangeRemoveProgramsParsingNameW[] = {':',':', SYSTEMFOLDERS_PARSING_GUID, '\\',':',':', CHANGEREMOVEPROGRAMS_PARSING_GUID, 0};
static const WCHAR AppUpdatesParsingNameW[] = {':',':', SYSTEMFOLDERS_PARSING_GUID, '\\',':',':', CHANGEREMOVEPROGRAMS_PARSING_GUID, '\\',':',':','{','d','4','5','0','a','8','a','1','-','9','5','6','8','-','4','5','c','7','-','9','c','0','e','-','b','4','f','9','f','b','4','5','3','7','b','d','}',0};
static const WCHAR SyncManagerFolderParsingNameW[] = {':',':', SYSTEMFOLDERS_PARSING_GUID, '\\',':',':', SYNCMANAGER_PARSING_GUID, 0};
static const WCHAR ConflictFolderParsingNameW[] = {':',':', SYSTEMFOLDERS_PARSING_GUID, '\\',':',':', SYNCMANAGER_PARSING_GUID, '\\',':',':','{','E','4','1','3','D','0','4','0','-','6','7','8','8','-','4','C','2','2','-','9','5','7','E','-','1','7','5','D','1','C','5','1','3','A','3','4','}',',',0};
static const WCHAR SyncResultsFolderParsingNameW[] = {':',':', SYSTEMFOLDERS_PARSING_GUID, '\\',':',':', SYNCMANAGER_PARSING_GUID, '\\',':',':','{','B','C','4','8','B','3','2','F','-','5','9','1','0','-','4','7','F','5','-','8','5','7','0','-','5','0','7','4','A','8','A','5','6','3','6','A','}',',',0};
static const WCHAR SyncSetupFolderParsingNameW[] = {':',':', SYSTEMFOLDERS_PARSING_GUID, '\\',':',':', SYNCMANAGER_PARSING_GUID, '\\',':',':','{','F','1','3','9','0','A','9','A','-','A','3','F','4','-','4','E','5','D','-','9','C','5','F','-','9','8','F','3','B','D','8','D','9','3','5','C','}',',',0};
static const WCHAR ContactsParsingNameW[] = {':',':', USERFOLDERS_PARSING_GUID, '\\','{','5','6','7','8','4','8','5','4','-','C','6','C','B','-','4','6','2','B','-','8','1','6','9','-','8','8','E','3','5','0','A','C','B','8','8','2','}',0};
static const WCHAR DocumentsParsingNameW[] = {':',':', USERFOLDERS_PARSING_GUID, '\\','{','F','D','D','3','9','A','D','0','-','2','3','8','F','-','4','6','A','F','-','A','D','B','4','-','6','C','8','5','4','8','0','3','6','9','C','7','}',0};
static const WCHAR LinksParsingNameW[] = {':',':', USERFOLDERS_PARSING_GUID, '\\','{','b','f','b','9','d','5','e','0','-','c','6','a','9','-','4','0','4','c','-','b','2','b','2','-','a','e','6','d','b','6','a','f','4','9','6','8','}',0};
static const WCHAR MusicParsingNameW[] = {':',':', USERFOLDERS_PARSING_GUID, '\\','{','4','B','D','8','D','5','7','1','-','6','D','1','9','-','4','8','D','3','-','B','E','9','7','-','4','2','2','2','2','0','0','8','0','E','4','3','}',0};
static const WCHAR PicturesParsingNameW[] = {':',':', USERFOLDERS_PARSING_GUID, '\\','{','3','3','E','2','8','1','3','0','-','4','E','1','E','-','4','6','7','6','-','8','3','5','A','-','9','8','3','9','5','C','3','B','C','3','B','B','}',0};
static const WCHAR SavedGamesParsingNameW[] = {':',':', USERFOLDERS_PARSING_GUID, '\\','{','4','C','5','C','3','2','F','F','-','B','B','9','D','-','4','3','b','0','-','B','5','B','4','-','2','D','7','2','E','5','4','E','A','A','A','4','}',0};
static const WCHAR SavedSearchesParsingNameW[] = {':',':', USERFOLDERS_PARSING_GUID, '\\','{','7','d','1','d','3','a','0','4','-','d','e','b','b','-','4','1','1','5','-','9','5','c','f','-','2','f','2','9','d','a','2','9','2','0','d','a','}',0};
static const WCHAR VideosParsingNameW[] = {':',':', USERFOLDERS_PARSING_GUID, '\\','{','1','8','9','8','9','B','1','D','-','9','9','B','5','-','4','5','5','B','-','8','4','1','C','-','A','B','7','C','7','4','E','4','D','D','F','C','}',0};
static const WCHAR DocumentsLibraryParsingNameW[] = {':',':', USERSLIBRARIES_PARSING_GUID, '\\','{','7','b','0','d','b','1','7','d','-','9','c','d','2','-','4','a','9','3','-','9','7','3','3','-','4','6','c','c','8','9','0','2','2','e','7','c','}',0};
static const WCHAR MusicLibraryParsingNameW[] = {':',':', USERSLIBRARIES_PARSING_GUID, '\\','{','2','1','1','2','A','B','0','A','-','C','8','6','A','-','4','f','f','e','-','A','3','6','8','-','0','D','E','9','6','E','4','7','0','1','2','E','}',0};
static const WCHAR PicturesLibraryParsingNameW[] = {':',':', USERSLIBRARIES_PARSING_GUID, '\\','{','A','9','9','0','A','E','9','F','-','A','0','3','B','-','4','e','8','0','-','9','4','B','C','-','9','9','1','2','D','7','5','0','4','1','0','4','}',0};
static const WCHAR VideosLibraryParsingNameW[] = {':',':', USERSLIBRARIES_PARSING_GUID, '\\','{','4','9','1','E','9','2','2','F','-','5','6','4','3','-','4','a','f','4','-','A','7','E','B','-','4','E','7','A','1','3','8','D','8','1','7','4','}',0};

typedef enum _CSIDL_Type {
    CSIDL_Type_User,
    CSIDL_Type_AllUsers,
    CSIDL_Type_CurrVer,
    CSIDL_Type_Disallowed,
    CSIDL_Type_NonExistent,
    CSIDL_Type_WindowsPath,
    CSIDL_Type_SystemPath,
    CSIDL_Type_SystemX86Path,
	CSIDL_Type_ProgramData
} CSIDL_Type;

#define CSIDL_CONTACTS         0x0043
#define CSIDL_DOWNLOADS        0x0047
#define CSIDL_LINKS            0x004d
#define CSIDL_APPDATA_LOCALLOW 0x004e
#define CSIDL_SAVED_GAMES      0x0062
#define CSIDL_SEARCHES         0x0063

typedef struct
{
    const KNOWNFOLDERID *id;
    CSIDL_Type type;
    LPCWSTR    szValueName;
    LPCWSTR    szDefaultPath; /* fallback string or resource ID */

    /* KNOWNFOLDER_DEFINITION fields */
    KF_CATEGORY category;
    const WCHAR *pszName;
    const WCHAR *pszDescription;
    const KNOWNFOLDERID *fidParent;
    const WCHAR *pszRelativePath;
    const WCHAR *pszParsingName;
    const WCHAR *pszTooltip;
    const WCHAR *pszLocalizedName;
    const WCHAR *pszIcon;
    const WCHAR *pszSecurity;
    DWORD dwAttributes;
    KF_DEFINITION_FLAGS kfdFlags;
    const FOLDERTYPEID *ftidType;
} CSIDL_DATA;

static const CSIDL_DATA CSIDL_Data[] =
{
    { /* 0x00 - CSIDL_DESKTOP */
        &FOLDERID_Desktop,
        CSIDL_Type_User,
        DesktopW,
        MAKEINTRESOURCEW(IDS_DESKTOPDIRECTORY),

        KF_CATEGORY_PERUSER, /* category */
        DesktopW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        DesktopW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x01 - CSIDL_INTERNET */
        &FOLDERID_InternetFolder,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        InternetFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        InternetFolderParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x02 - CSIDL_PROGRAMS */
        &FOLDERID_Programs,
        CSIDL_Type_User,
        ProgramsW,
        Start_Menu_ProgramsW,

        KF_CATEGORY_PERUSER, /* category */
        ProgramsW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        ProgramsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x03 - CSIDL_CONTROLS (.CPL files) */
        &FOLDERID_ControlPanelFolder,
        CSIDL_Type_SystemPath,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        ControlPanelFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        ControlPanelFolderRelativePathW, /* relative path */
        ControlPanelFolderParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x04 - CSIDL_PRINTERS */
        &FOLDERID_PrintersFolder,
        CSIDL_Type_SystemPath,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        PrintersFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        PrintersFolderParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x05 - CSIDL_PERSONAL */
        &FOLDERID_Documents,
        CSIDL_Type_User,
        PersonalW,
        MAKEINTRESOURCEW(IDS_PERSONAL),

        KF_CATEGORY_PERUSER, /* category */
        PersonalW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        DocumentsW, /* relative path */
        DocumentsParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_ROAMABLE | KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x06 - CSIDL_FAVORITES */
        &FOLDERID_Favorites,
        CSIDL_Type_User,
        FavoritesW,
        FavoritesW,

        KF_CATEGORY_PERUSER, /* category */
        FavoritesW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        FavoritesW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_ROAMABLE | KFDF_PRECREATE | KFDF_PUBLISHEXPANDEDPATH, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x07 - CSIDL_STARTUP */
        &FOLDERID_Startup,
        CSIDL_Type_User,
        StartUpW,
        Start_Menu_StartupW,

        KF_CATEGORY_PERUSER, /* category */
        StartupW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        StartUpW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x08 - CSIDL_RECENT */
        &FOLDERID_Recent,
        CSIDL_Type_User,
        RecentW,
        RecentW,

        KF_CATEGORY_PERUSER, /* category */
        RecentW, /* name */
        NULL, /* description */
        &FOLDERID_RoamingAppData, /* parent */
        Microsoft_Windows_RecentW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x09 - CSIDL_SENDTO */
        &FOLDERID_SendTo,
        CSIDL_Type_User,
        SendToW,
        SendToW,

        KF_CATEGORY_PERUSER, /* category */
        SendToW, /* name */
        NULL, /* description */
        &FOLDERID_RoamingAppData, /* parent */
        Microsoft_Windows_SendToW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x0a - CSIDL_BITBUCKET - Recycle Bin */
        &FOLDERID_RecycleBinFolder,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        RecycleBinFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        RecycleBinFolderParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x0b - CSIDL_STARTMENU */
        &FOLDERID_StartMenu,
        CSIDL_Type_User,
        Start_MenuW,
        Start_MenuW,

        KF_CATEGORY_PERUSER, /* category */
        Start_MenuW, /* name */
        NULL, /* description */
        &FOLDERID_RoamingAppData, /* parent */
        Microsoft_Windows_Start_MenuW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x0c - CSIDL_MYDOCUMENTS */
        &GUID_NULL,
        CSIDL_Type_Disallowed, /* matches WinXP--can't get its path */
        NULL,
        NULL
    },
    { /* 0x0d - CSIDL_MYMUSIC */
        &FOLDERID_Music,
        CSIDL_Type_User,
        My_MusicW,
        MAKEINTRESOURCEW(IDS_MYMUSIC),

        KF_CATEGORY_PERUSER, /* category */
        My_MusicW, /* name */
        NULL, /* description */
        &FOLDERID_Profile, /* parent */
        MusicW, /* relative path */
        MusicParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_ROAMABLE | KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x0e - CSIDL_MYVIDEO */
        &FOLDERID_Videos,
        CSIDL_Type_User,
        My_VideosW,
        MAKEINTRESOURCEW(IDS_MYVIDEOS),

        KF_CATEGORY_PERUSER, /* category */
        My_VideoW, /* name */
        NULL, /* description */
        &FOLDERID_Profile, /* parent */
        VideosW, /* relative path */
        VideosParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_ROAMABLE | KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x0f - unassigned */
        &GUID_NULL,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,
    },
    { /* 0x10 - CSIDL_DESKTOPDIRECTORY */
        &FOLDERID_Desktop,
        CSIDL_Type_User,
        DesktopW,
        MAKEINTRESOURCEW(IDS_DESKTOPDIRECTORY),

        KF_CATEGORY_PERUSER, /* category */
        DesktopW, /* name */
        NULL, /* description */
        &FOLDERID_Profile, /* parent */
        DesktopW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_ROAMABLE | KFDF_PRECREATE | KFDF_PUBLISHEXPANDEDPATH, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x11 - CSIDL_DRIVES */
        &FOLDERID_ComputerFolder,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        MyComputerFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        ComputerFolderParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x12 - CSIDL_NETWORK */
        &FOLDERID_NetworkFolder,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        NetworkPlacesFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NetworkFolderParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x13 - CSIDL_NETHOOD */
        &FOLDERID_NetHood,
        CSIDL_Type_User,
        NetHoodW,
        NetHoodW,

        KF_CATEGORY_PERUSER, /* category */
        NetHoodW, /* name */
        NULL, /* description */
        &FOLDERID_RoamingAppData, /* parent */
        Microsoft_Windows_Network_ShortcutsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x14 - CSIDL_FONTS */
        &FOLDERID_Fonts,
        CSIDL_Type_WindowsPath,
        FontsW,
        FontsW,

        KF_CATEGORY_FIXED, /* category */
        FontsW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &FOLDERID_Windows/* typeid */
    },
    { /* 0x15 - CSIDL_TEMPLATES */
        &FOLDERID_Templates,
        CSIDL_Type_User,
        TemplatesW,
        TemplatesW,

        KF_CATEGORY_PERUSER, /* category */
        TemplatesW, /* name */
        NULL, /* description */
        &FOLDERID_RoamingAppData, /* parent */
        Microsoft_Windows_TemplatesW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x16 - CSIDL_COMMON_STARTMENU */
        &FOLDERID_CommonStartMenu,
        CSIDL_Type_ProgramData,
        Common_Start_MenuW,
        Microsoft_Windows_Start_MenuW,

        KF_CATEGORY_COMMON, /* category */
        Common_Start_MenuW, /* name */
        NULL, /* description */
        &FOLDERID_ProgramData, /* parent */
        Microsoft_Windows_Start_MenuW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x17 - CSIDL_COMMON_PROGRAMS */
        &FOLDERID_CommonPrograms,
        CSIDL_Type_ProgramData,
        Common_ProgramsW,
        Microsoft_Windows_Start_Menu_ProgramsW,

        KF_CATEGORY_COMMON, /* category */
        Common_ProgramsW, /* name */
        NULL, /* description */
        &FOLDERID_CommonStartMenu, /* parent */
        ProgramsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x18 - CSIDL_COMMON_STARTUP */
        &FOLDERID_CommonStartup,
        CSIDL_Type_ProgramData,
        Common_StartUpW,
        Microsoft_Windows_Start_Menu_StartupW,

        KF_CATEGORY_COMMON, /* category */
        Common_StartupW, /* name */
        NULL, /* description */
        &FOLDERID_CommonPrograms, /* parent */
        StartUpW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x19 - CSIDL_COMMON_DESKTOPDIRECTORY */
        &FOLDERID_PublicDesktop,
        CSIDL_Type_AllUsers,
        Common_DesktopW,
        MAKEINTRESOURCEW(IDS_DESKTOPDIRECTORY),

        KF_CATEGORY_COMMON, /* category */
        Common_DesktopW, /* name */
        NULL, /* description */
        &FOLDERID_Public, /* parent */
        DesktopW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_HIDDEN, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x1a - CSIDL_APPDATA */
        &FOLDERID_RoamingAppData,
        CSIDL_Type_User,
        AppDataW,
        Application_DataW,

        KF_CATEGORY_PERUSER, /* category */
        AppDataW, /* name */
        NULL, /* description */
        &FOLDERID_Profile, /* parent */
        AppData_RoamingW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x1b - CSIDL_PRINTHOOD */
        &FOLDERID_PrintHood,
        CSIDL_Type_User,
        PrintHoodW,
        PrintHoodW,

        KF_CATEGORY_PERUSER, /* category */
        PrintHoodW, /* name */
        NULL, /* description */
        &FOLDERID_RoamingAppData, /* parent */
        Microsoft_Windows_Printer_ShortcutsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x1c - CSIDL_LOCAL_APPDATA */
        &FOLDERID_LocalAppData,
        CSIDL_Type_User,
        Local_AppDataW,
        Local_Settings_Application_DataW,

        KF_CATEGORY_PERUSER, /* category */
        Local_AppDataW, /* name */
        NULL, /* description */
        &FOLDERID_Profile, /* parent */
        AppData_LocalW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        KFDF_LOCAL_REDIRECT_ONLY | KFDF_PUBLISHEXPANDEDPATH, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x1d - CSIDL_ALTSTARTUP */
        &GUID_NULL,
        CSIDL_Type_NonExistent,
        NULL,
        NULL
    },
    { /* 0x1e - CSIDL_COMMON_ALTSTARTUP */
        &GUID_NULL,
        CSIDL_Type_NonExistent,
        NULL,
        NULL
    },
    { /* 0x1f - CSIDL_COMMON_FAVORITES */
        &FOLDERID_Favorites,
        CSIDL_Type_AllUsers,
        Common_FavoritesW,
        FavoritesW,

        KF_CATEGORY_PERUSER, /* category */
        FavoritesW, /* name */
        NULL, /* description */
        &FOLDERID_Profile, /* parent */
        FavoritesW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_ROAMABLE | KFDF_PRECREATE | KFDF_PUBLISHEXPANDEDPATH, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x20 - CSIDL_INTERNET_CACHE */
        &FOLDERID_InternetCache,
        CSIDL_Type_User,
        CacheW,
        Local_Settings_Temporary_Internet_FilesW,

        KF_CATEGORY_PERUSER, /* category */
        CacheW, /* name */
        NULL, /* description */
        &FOLDERID_LocalAppData, /* parent */
        Microsoft_Windows_Temporary_Internet_FilesW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        KFDF_LOCAL_REDIRECT_ONLY, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x21 - CSIDL_COOKIES */
        &FOLDERID_Cookies,
        CSIDL_Type_User,
        CookiesW,
        CookiesW,

        KF_CATEGORY_PERUSER, /* category */
        CookiesW, /* name */
        NULL, /* description */
        &FOLDERID_RoamingAppData, /* parent */
        Microsoft_Windows_CookiesW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x22 - CSIDL_HISTORY */
        &FOLDERID_History,
        CSIDL_Type_User,
        HistoryW,
        Local_Settings_HistoryW,

        KF_CATEGORY_PERUSER, /* category */
        HistoryW, /* name */
        NULL, /* description */
        &FOLDERID_LocalAppData, /* parent */
        Microsoft_Windows_HistoryW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        KFDF_LOCAL_REDIRECT_ONLY, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x23 - CSIDL_COMMON_APPDATA */
        &FOLDERID_ProgramData,
        CSIDL_Type_ProgramData,
        Common_AppDataW,
        NULL,

        KF_CATEGORY_FIXED, /* category */
        Common_AppDataW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x24 - CSIDL_WINDOWS */
        &FOLDERID_Windows,
        CSIDL_Type_WindowsPath,
        NULL,
        NULL,

        KF_CATEGORY_FIXED, /* category */
        WindowsW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x25 - CSIDL_SYSTEM */
        &FOLDERID_System,
        CSIDL_Type_SystemPath,
        NULL,
        NULL,

        KF_CATEGORY_FIXED, /* category */
        SystemW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x26 - CSIDL_PROGRAM_FILES */
        &FOLDERID_ProgramFiles,
        CSIDL_Type_CurrVer,
        ProgramFilesDirW,
        Program_FilesW,

        KF_CATEGORY_FIXED, /* category */
        ProgramFilesW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x27 - CSIDL_MYPICTURES */
        &FOLDERID_Pictures,
        CSIDL_Type_User,
        My_PicturesW,
        MAKEINTRESOURCEW(IDS_MYPICTURES),

        KF_CATEGORY_PERUSER, /* category */
        My_PicturesW, /* name */
        NULL, /* description */
        &FOLDERID_Profile, /* parent */
        PicturesW, /* relative path */
        PicturesParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_ROAMABLE | KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x28 - CSIDL_PROFILE */
        &FOLDERID_Profile,
        CSIDL_Type_User,
        NULL,
        NULL,

        KF_CATEGORY_FIXED, /* category */
        ProfileW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x29 - CSIDL_SYSTEMX86 */
        &FOLDERID_SystemX86,
        CSIDL_Type_SystemX86Path,
        NULL,
        NULL,

        KF_CATEGORY_FIXED, /* category */
        SystemX86W, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x2a - CSIDL_PROGRAM_FILESX86 */
        &FOLDERID_ProgramFilesX86,
        CSIDL_Type_CurrVer,
        ProgramFilesDirX86W,
        Program_Files_x86W,

        KF_CATEGORY_FIXED, /* category */
        ProgramFilesX86W, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x2b - CSIDL_PROGRAM_FILES_COMMON */
        &FOLDERID_ProgramFilesCommon,
        CSIDL_Type_CurrVer,
        CommonFilesDirW,
        Program_Files_Common_FilesW,

        KF_CATEGORY_FIXED, /* category */
        ProgramFilesCommonW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x2c - CSIDL_PROGRAM_FILES_COMMONX86 */
        &FOLDERID_ProgramFilesCommonX86,
        CSIDL_Type_CurrVer,
        CommonFilesDirX86W,
        Program_Files_x86_Common_FilesW,

        KF_CATEGORY_FIXED, /* category */
        ProgramFilesCommonX86W, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x2d - CSIDL_COMMON_TEMPLATES */
        &FOLDERID_CommonTemplates,
        CSIDL_Type_ProgramData,
        Common_TemplatesW,
        Microsoft_Windows_TemplatesW,

        KF_CATEGORY_COMMON, /* category */
        Common_TemplatesW, /* name */
        NULL, /* description */
        &FOLDERID_ProgramData, /* parent */
        Microsoft_Windows_TemplatesW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x2e - CSIDL_COMMON_DOCUMENTS */
        &FOLDERID_PublicDocuments,
        CSIDL_Type_AllUsers,
        Common_DocumentsW,
        DocumentsW,

        KF_CATEGORY_COMMON, /* category */
        Common_DocumentsW, /* name */
        NULL, /* description */
        &FOLDERID_Public, /* parent */
        DocumentsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x2f - CSIDL_COMMON_ADMINTOOLS */
        &FOLDERID_CommonAdminTools,
        CSIDL_Type_ProgramData,
        Common_Administrative_ToolsW,
        Microsoft_Windows_Start_Menu_Admin_ToolsW,

        KF_CATEGORY_COMMON, /* category */
        Common_Administrative_ToolsW, /* name */
        NULL, /* description */
        &FOLDERID_CommonPrograms, /* parent */
        Administrative_ToolsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x30 - CSIDL_ADMINTOOLS */
        &FOLDERID_AdminTools,
        CSIDL_Type_User,
        Administrative_ToolsW,
        Start_Menu_Admin_ToolsW,

        KF_CATEGORY_PERUSER, /* category */
        Administrative_ToolsW, /* name */
        NULL, /* description */
        &FOLDERID_Programs, /* parent */
        Administrative_ToolsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x31 - CSIDL_CONNECTIONS */
        &FOLDERID_ConnectionsFolder,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        ConnectionsFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        Administrative_ToolsW, /* relative path */
        ConnectionsFolderParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x32 - unassigned */
        &GUID_NULL,
        CSIDL_Type_Disallowed,
        NULL,
        NULL
    },
    { /* 0x33 - unassigned */
        &GUID_NULL,
        CSIDL_Type_Disallowed,
        NULL,
        NULL
    },
    { /* 0x34 - unassigned */
        &GUID_NULL,
        CSIDL_Type_Disallowed,
        NULL,
        NULL
    },
    { /* 0x35 - CSIDL_COMMON_MUSIC */
        &FOLDERID_PublicMusic,
        CSIDL_Type_AllUsers,
        CommonMusicW,
        MusicW,

        KF_CATEGORY_COMMON, /* category */
        CommonMusicW, /* name */
        NULL, /* description */
        &FOLDERID_Public, /* parent */
        MusicW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x36 - CSIDL_COMMON_PICTURES */
        &FOLDERID_PublicPictures,
        CSIDL_Type_AllUsers,
        CommonPicturesW,
        PicturesW,

        KF_CATEGORY_COMMON, /* category */
        CommonPicturesW, /* name */
        NULL, /* description */
        &FOLDERID_Public, /* parent */
        PicturesW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x37 - CSIDL_COMMON_VIDEO */
        &FOLDERID_PublicVideos,
        CSIDL_Type_AllUsers,
        CommonVideoW,
        VideosW,

        KF_CATEGORY_COMMON, /* category */
        CommonVideoW, /* name */
        NULL, /* description */
        &FOLDERID_Public, /* parent */
        VideosW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x38 - CSIDL_RESOURCES */
        &FOLDERID_ResourceDir,
        CSIDL_Type_WindowsPath,
        NULL,
        ResourcesW,

        KF_CATEGORY_FIXED, /* category */
        ResourceDirW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x39 - CSIDL_RESOURCES_LOCALIZED */
        &FOLDERID_LocalizedResourcesDir,
        CSIDL_Type_NonExistent,
        NULL,
        NULL,

        KF_CATEGORY_FIXED, /* category */
        LocalizedResourcesDirW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x3a - CSIDL_COMMON_OEM_LINKS */
        &FOLDERID_CommonOEMLinks,
        CSIDL_Type_ProgramData,
        NULL,
        OEM_LinksW,

        KF_CATEGORY_COMMON, /* category */
        OEM_LinksW, /* name */
        NULL, /* description */
        &FOLDERID_ProgramData, /* parent */
        OEM_LinksW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x3b - CSIDL_CDBURN_AREA */
        &FOLDERID_CDBurning,
        CSIDL_Type_User,
        CD_BurningW,
        Local_Settings_CD_BurningW,

        KF_CATEGORY_PERUSER, /* category */
        CD_BurningW, /* name */
        NULL, /* description */
        &FOLDERID_LocalAppData, /* parent */
        Microsoft_Windows_Burn_BurnW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_LOCAL_REDIRECT_ONLY, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x3c unassigned */
        &GUID_NULL,
        CSIDL_Type_Disallowed,
        NULL,
        NULL
    },
    { /* 0x3d - CSIDL_COMPUTERSNEARME */
        &GUID_NULL,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL
    },
    { /* 0x3e - CSIDL_PROFILES */
        &GUID_NULL,
        CSIDL_Type_Disallowed, /* oddly, this matches WinXP */
        NULL,
        NULL
    },
    { /* 0x3f */
        &FOLDERID_AddNewPrograms,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        AddNewProgramsFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        AddNewProgramsParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x40 */
        &FOLDERID_AppUpdates,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        AppUpdatesFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        AppUpdatesParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x41 */
        &FOLDERID_ChangeRemovePrograms,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        ChangeRemoveProgramsFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        ChangeRemoveProgramsParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x42 */
        &FOLDERID_ConflictFolder,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        ConflictFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        ConflictFolderParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x43 - CSIDL_CONTACTS */
        &FOLDERID_Contacts,
        CSIDL_Type_User,
        NULL,
        ContactsW,

        KF_CATEGORY_PERUSER, /* category */
        ContactsW, /* name */
        NULL, /* description */
        &FOLDERID_Profile, /* parent */
        ContactsW, /* relative path */
        ContactsParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_ROAMABLE | KFDF_PRECREATE | KFDF_PUBLISHEXPANDEDPATH, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x44 */
        &FOLDERID_DeviceMetadataStore,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_COMMON, /* category */
        Device_Metadata_StoreW, /* name */
        NULL, /* description */
        &FOLDERID_ProgramData, /* parent */
        Microsoft_Windows_DeviceMetadataStoreW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x45 */
        &GUID_NULL,
        CSIDL_Type_User,
        NULL,
        DocumentsW
    },
    { /* 0x46 */
        &FOLDERID_DocumentsLibrary,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_PERUSER, /* category */
        DocumentsLibraryW, /* name */
        NULL, /* description */
        &FOLDERID_Libraries, /* parent */
        Documents_librarymsW, /* relative path */
        DocumentsLibraryParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        KFDF_PRECREATE | KFDF_STREAM, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x47 - CSIDL_DOWNLOADS */
        &FOLDERID_Downloads,
        CSIDL_Type_User,
        NULL,
        DownloadsW,

        KF_CATEGORY_PERUSER, /* category */
        DownloadsW, /* name */
        NULL, /* description */
        &FOLDERID_Profile, /* parent */
        DownloadsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_ROAMABLE | KFDF_PRECREATE | KFDF_PUBLISHEXPANDEDPATH, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x48 */
        &FOLDERID_Games,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        GamesW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        GamesParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x49 */
        &FOLDERID_GameTasks,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_PERUSER, /* category */
        GameTasksW, /* name */
        NULL, /* description */
        &FOLDERID_LocalAppData, /* parent */
        Microsoft_Windows_GameExplorerW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        KFDF_LOCAL_REDIRECT_ONLY, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x4a */
        &FOLDERID_HomeGroup,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        HomeGroupFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        HomeGroupParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x4b */
        &FOLDERID_ImplicitAppShortcuts,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_PERUSER, /* category */
        ImplicitAppShortcutsW, /* name */
        NULL, /* description */
        &FOLDERID_UserPinned, /* parent */
        ImplicitAppShortcutsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x4c */
        &FOLDERID_Libraries,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_PERUSER, /* category */
        LibrariesW, /* name */
        NULL, /* description */
        &FOLDERID_RoamingAppData, /* parent */
        Microsoft_Windows_LibrariesW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        KFDF_PRECREATE | KFDF_PUBLISHEXPANDEDPATH, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x4d - CSIDL_LINKS */
        &FOLDERID_Links,
        CSIDL_Type_User,
        NULL,
        LinksW,

        KF_CATEGORY_PERUSER, /* category */
        LinksW, /* name */
        NULL, /* description */
        &FOLDERID_Profile, /* parent */
        LinksW, /* relative path */
        LinksParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_ROAMABLE | KFDF_PRECREATE | KFDF_PUBLISHEXPANDEDPATH, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x4e - CSIDL_APPDATA_LOCALLOW */
        &FOLDERID_LocalAppDataLow,
        CSIDL_Type_User,
        NULL,
        AppData_LocalLowW,

        KF_CATEGORY_PERUSER, /* category */
        LocalAppDataLowW, /* name */
        NULL, /* description */
        &FOLDERID_Profile, /* parent */
        AppData_LocalLowW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_NOT_CONTENT_INDEXED, /* attributes */
        KFDF_LOCAL_REDIRECT_ONLY | KFDF_PRECREATE | KFDF_PUBLISHEXPANDEDPATH, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x4f */
        &FOLDERID_MusicLibrary,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_PERUSER, /* category */
        MusicLibraryW, /* name */
        NULL, /* description */
        &FOLDERID_Libraries, /* parent */
        Music_librarymsW, /* relative path */
        MusicLibraryParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        KFDF_PRECREATE | KFDF_STREAM, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x50 */
        &FOLDERID_OriginalImages,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_PERUSER, /* category */
        Original_ImagesW, /* name */
        NULL, /* description */
        &FOLDERID_LocalAppData, /* parent */
        Microsoft_Windows_Photo_Gallery_Original_ImagesW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x51 */
        &FOLDERID_PhotoAlbums,
        CSIDL_Type_User,
        NULL,
        Pictures_Slide_ShowsW,

        KF_CATEGORY_PERUSER, /* category */
        PhotoAlbumsW, /* name */
        NULL, /* description */
        &FOLDERID_Pictures, /* parent */
        Slide_ShowsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x52 */
        &FOLDERID_PicturesLibrary,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_PERUSER, /* category */
        PicturesLibraryW, /* name */
        NULL, /* description */
        &FOLDERID_Libraries, /* parent */
        Pictures_librarymsW, /* relative path */
        PicturesLibraryParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        KFDF_PRECREATE | KFDF_STREAM, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x53 */
        &FOLDERID_Playlists,
        CSIDL_Type_User,
        NULL,
        Music_PlaylistsW,

        KF_CATEGORY_PERUSER, /* category */
        PlaylistsW, /* name */
        NULL, /* description */
        &FOLDERID_Music, /* parent */
        PlaylistsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x54 */
        &FOLDERID_ProgramFilesX64,
        CSIDL_Type_NonExistent,
        NULL,
        NULL,

        KF_CATEGORY_FIXED, /* category */
        ProgramFilesX64W, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x55 */
        &FOLDERID_ProgramFilesCommonX64,
        CSIDL_Type_NonExistent,
        NULL,
        NULL,

        KF_CATEGORY_FIXED, /* category */
        ProgramFilesCommonX64W, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x56 */
        &FOLDERID_Public,
        CSIDL_Type_CurrVer, /* FIXME */
        NULL,
        UsersPublicW,

        KF_CATEGORY_FIXED, /* category */
        PublicW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        PublicParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x57 */
        &FOLDERID_PublicDownloads,
        CSIDL_Type_AllUsers,
        NULL,
        DownloadsW,

        KF_CATEGORY_COMMON, /* category */
        CommonDownloadsW, /* name */
        NULL, /* description */
        &FOLDERID_Public, /* parent */
        DownloadsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x58 */
        &FOLDERID_PublicGameTasks,
        CSIDL_Type_ProgramData,
        NULL,
        Microsoft_Windows_GameExplorerW,

        KF_CATEGORY_COMMON, /* category */
        PublicGameTasksW, /* name */
        NULL, /* description */
        &FOLDERID_ProgramData, /* parent */
        Microsoft_Windows_GameExplorerW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        KFDF_LOCAL_REDIRECT_ONLY, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x59 */
        &FOLDERID_PublicLibraries,
        CSIDL_Type_AllUsers,
        NULL,
        Microsoft_Windows_LibrariesW,

        KF_CATEGORY_COMMON, /* category */
        PublicLibrariesW, /* name */
        NULL, /* description */
        &FOLDERID_Public, /* parent */
        LibrariesW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_HIDDEN, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x5a */
        &FOLDERID_PublicRingtones,
        CSIDL_Type_ProgramData,
        NULL,
        Microsoft_Windows_RingtonesW,

        KF_CATEGORY_COMMON, /* category */
        CommonRingtonesW, /* name */
        NULL, /* description */
        &FOLDERID_ProgramData, /* parent */
        Microsoft_Windows_RingtonesW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x5b */
        &FOLDERID_QuickLaunch,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_PERUSER, /* category */
        Quick_LaunchW, /* name */
        NULL, /* description */
        &FOLDERID_RoamingAppData, /* parent */
        Microsoft_Internet_Explorer_Quick_LaunchW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x5c */
        &FOLDERID_RecordedTVLibrary,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_COMMON, /* category */
        RecordedTVLibraryW, /* name */
        NULL, /* description */
        &FOLDERID_PublicLibraries, /* parent */
        RecordedTV_librarymsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        KFDF_PRECREATE | KFDF_STREAM, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x5d */
        &FOLDERID_Ringtones,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_PERUSER, /* category */
        RingtonesW, /* name */
        NULL, /* description */
        &FOLDERID_LocalAppData, /* parent */
        Microsoft_Windows_RingtonesW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x5e */
        &FOLDERID_SampleMusic,
        CSIDL_Type_AllUsers,
        NULL,
        Music_Sample_MusicW,

        KF_CATEGORY_COMMON, /* category */
        SampleMusicW, /* name */
        NULL, /* description */
        &FOLDERID_PublicMusic, /* parent */
        Sample_MusicW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x5f */
        &FOLDERID_SamplePictures,
        CSIDL_Type_AllUsers,
        NULL,
        Pictures_Sample_PicturesW,

        KF_CATEGORY_COMMON, /* category */
        SamplePicturesW, /* name */
        NULL, /* description */
        &FOLDERID_PublicPictures, /* parent */
        Sample_PicturesW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x60 */
        &FOLDERID_SamplePlaylists,
        CSIDL_Type_AllUsers,
        NULL,
        Music_Sample_PlaylistsW,

        KF_CATEGORY_COMMON, /* category */
        SamplePlaylistsW, /* name */
        NULL, /* description */
        &FOLDERID_PublicMusic, /* parent */
        Sample_PlaylistsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x61 */
        &FOLDERID_SampleVideos,
        CSIDL_Type_AllUsers,
        NULL,
        Videos_Sample_VideosW,

        KF_CATEGORY_COMMON, /* category */
        SampleVideosW, /* name */
        NULL, /* description */
        &FOLDERID_PublicVideos, /* parent */
        Sample_VideosW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x62 - CSIDL_SAVED_GAMES */
        &FOLDERID_SavedGames,
        CSIDL_Type_User,
        NULL,
        Saved_GamesW,

        KF_CATEGORY_PERUSER, /* category */
        SavedGamesW, /* name */
        NULL, /* description */
        &FOLDERID_Profile, /* parent */
        Saved_GamesW, /* relative path */
        SavedGamesParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_ROAMABLE | KFDF_PRECREATE | KFDF_PUBLISHEXPANDEDPATH, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x63 - CSIDL_SEARCHES */
        &FOLDERID_SavedSearches,
        CSIDL_Type_User,
        NULL,
        SearchesW,

        KF_CATEGORY_PERUSER, /* category */
        SearchesW, /* name */
        NULL, /* description */
        &FOLDERID_Profile, /* parent */
        SearchesW, /* relative path */
        SavedSearchesParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE | KFDF_PUBLISHEXPANDEDPATH, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x64 */
        &FOLDERID_SEARCH_CSC,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        CSCFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        SEARCH_CSCParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x65 */
        &FOLDERID_SEARCH_MAPI,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        MAPIFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        SEARCH_MAPIParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x66 */
        &FOLDERID_SearchHome,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        SearchHomeFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        SearchHomeParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x67 */
        &FOLDERID_SidebarDefaultParts,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_COMMON, /* category */
        Default_GadgetsW, /* name */
        NULL, /* description */
        &FOLDERID_ProgramFiles, /* parent */
        Windows_Sidebar_GadgetsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x68 */
        &FOLDERID_SidebarParts,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_PERUSER, /* category */
        GadgetsW, /* name */
        NULL, /* description */
        &FOLDERID_LocalAppData, /* parent */
        Microsoft_Windows_Sidebar_GadgetsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x69 */
        &FOLDERID_SyncManagerFolder,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        SyncCenterFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        SyncManagerFolderParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x6a */
        &FOLDERID_SyncResultsFolder,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        SyncResultsFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        SyncResultsFolderParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x6b */
        &FOLDERID_SyncSetupFolder,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        SyncSetupFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        SyncSetupFolderParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x6c */
        &FOLDERID_UserPinned,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_PERUSER, /* category */
        User_PinnedW, /* name */
        NULL, /* description */
        &FOLDERID_QuickLaunch, /* parent */
        User_PinnedW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_HIDDEN, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x6d */
        &FOLDERID_UserProfiles,
        CSIDL_Type_CurrVer,
        UsersW,
        UsersW,

        KF_CATEGORY_FIXED, /* category */
        UserProfilesW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        FILE_ATTRIBUTE_READONLY, /* attributes */
        KFDF_PRECREATE, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x6e */
        &FOLDERID_UserProgramFiles,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_PERUSER, /* category */
        UserProgramFilesW, /* name */
        NULL, /* description */
        &FOLDERID_LocalAppData, /* parent */
        ProgramsW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x6f */
        &FOLDERID_UserProgramFilesCommon,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_PERUSER, /* category */
        UserProgramFilesCommonW, /* name */
        NULL, /* description */
        &FOLDERID_UserProgramFiles, /* parent */
        CommonW, /* relative path */
        NULL, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x70 */
        &FOLDERID_UsersFiles,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        UsersFilesFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        UsersFilesParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x71 */
        &FOLDERID_UsersLibraries,
        CSIDL_Type_Disallowed,
        NULL,
        NULL,

        KF_CATEGORY_VIRTUAL, /* category */
        UsersLibrariesFolderW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        NULL, /* relative path */
        UsersLibrariesParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    },
    { /* 0x72 */
        &FOLDERID_VideosLibrary,
        CSIDL_Type_Disallowed, /* FIXME */
        NULL,
        NULL,

        KF_CATEGORY_PERUSER, /* category */
        VideosLibraryW, /* name */
        NULL, /* description */
        &GUID_NULL, /* parent */
        Videos_librarymsW, /* relative path */
        VideosLibraryParsingNameW, /* parsing */
        NULL, /* tooltip */
        NULL, /* localized */
        NULL, /* icon */
        NULL, /* security */
        0, /* attributes */
        0, /* flags */
        &GUID_NULL /* typeid */
    }
};

static HRESULT _SHExpandEnvironmentStrings(LPCWSTR szSrc, LPWSTR szDest);

/* Gets the value named value from the registry key
 * rootKey\Software\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders
 * (or from rootKey\userPrefix\... if userPrefix is not NULL) into path, which
 * is assumed to be MAX_PATH WCHARs in length.
 * If it exists, expands the value and writes the expanded value to
 * rootKey\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders
 * Returns successful error code if the value was retrieved from the registry,
 * and a failure otherwise.
 */
static HRESULT _SHGetUserShellFolderPath(HKEY rootKey, LPCWSTR userPrefix,
 LPCWSTR value, LPWSTR path)
{
    HRESULT hr;
    WCHAR shellFolderPath[MAX_PATH], userShellFolderPath[MAX_PATH];
    LPCWSTR pShellFolderPath, pUserShellFolderPath;
    DWORD dwType, dwPathLen = MAX_PATH;
    HKEY userShellFolderKey, shellFolderKey;

    TRACE("%p,%s,%s,%p\n",rootKey, debugstr_w(userPrefix), debugstr_w(value),
     path);

    if (userPrefix)
    {
        strcpyW(shellFolderPath, userPrefix);
        PathAddBackslashW(shellFolderPath);
        strcatW(shellFolderPath, szSHFolders);
        pShellFolderPath = shellFolderPath;
        strcpyW(userShellFolderPath, userPrefix);
        PathAddBackslashW(userShellFolderPath);
        strcatW(userShellFolderPath, szSHUserFolders);
        pUserShellFolderPath = userShellFolderPath;
    }
    else
    {
        pUserShellFolderPath = szSHUserFolders;
        pShellFolderPath = szSHFolders;
    }

    if (RegCreateKeyW(rootKey, pShellFolderPath, &shellFolderKey))
    {
        TRACE("Failed to create %s\n", debugstr_w(pShellFolderPath));
        return E_FAIL;
    }
    if (RegCreateKeyW(rootKey, pUserShellFolderPath, &userShellFolderKey))
    {
        TRACE("Failed to create %s\n",
         debugstr_w(pUserShellFolderPath));
        RegCloseKey(shellFolderKey);
        return E_FAIL;
    }

    if (!RegQueryValueExW(userShellFolderKey, value, NULL, &dwType,
     (LPBYTE)path, &dwPathLen) && (dwType == REG_EXPAND_SZ || dwType == REG_SZ))
    {
        LONG ret;

        path[dwPathLen / sizeof(WCHAR)] = '\0';
        if (dwType == REG_EXPAND_SZ && path[0] == '%')
        {
            WCHAR szTemp[MAX_PATH];

            _SHExpandEnvironmentStrings(path, szTemp);
            lstrcpynW(path, szTemp, MAX_PATH);
        }
        ret = RegSetValueExW(shellFolderKey, value, 0, REG_SZ, (LPBYTE)path,
         (strlenW(path) + 1) * sizeof(WCHAR));
        if (ret != ERROR_SUCCESS)
            hr = HRESULT_FROM_WIN32(ret);
        else
            hr = S_OK;
    }
    else
        hr = E_FAIL;
    RegCloseKey(shellFolderKey);
    RegCloseKey(userShellFolderKey);
    TRACE("returning 0x%08x\n", hr);
    return hr;
}

/* Gets a 'semi-expanded' default value of the CSIDL with index folder into
 * pszPath, based on the entries in CSIDL_Data.  By semi-expanded, I mean:
 * - The entry's szDefaultPath may be either a string value or an integer
 *   resource identifier.  In the latter case, the string value of the resource
 *   is written.
 * - Depending on the entry's type, the path may begin with an (unexpanded)
 *   environment variable name.  The caller is responsible for expanding
 *   environment strings if so desired.
 *   The types that are prepended with environment variables are:
 *   CSIDL_Type_User:     %USERPROFILE%
 *   CSIDL_Type_AllUsers: %ALLUSERSPROFILE%
 *   CSIDL_Type_CurrVer:  %SystemDrive%
 *   (Others might make sense too, but as yet are unneeded.)
 */
static HRESULT _SHGetDefaultValue(BYTE folder, LPWSTR pszPath)
{
    HRESULT hr;
    WCHAR resourcePath[MAX_PATH];
    LPCWSTR pDefaultPath = NULL;

    TRACE("0x%02x,%p\n", folder, pszPath);

    if (folder >= sizeof(CSIDL_Data) / sizeof(CSIDL_Data[0]))
        return E_INVALIDARG;
    if (!pszPath)
        return E_INVALIDARG;

    if (!is_win64)
    {
        BOOL is_wow64;

        switch (folder)
        {
        case CSIDL_PROGRAM_FILES:
        case CSIDL_PROGRAM_FILESX86:
            IsWow64Process( GetCurrentProcess(), &is_wow64 );
            folder = is_wow64 ? CSIDL_PROGRAM_FILESX86 : CSIDL_PROGRAM_FILES;
            break;
        case CSIDL_PROGRAM_FILES_COMMON:
        case CSIDL_PROGRAM_FILES_COMMONX86:
            IsWow64Process( GetCurrentProcess(), &is_wow64 );
            folder = is_wow64 ? CSIDL_PROGRAM_FILES_COMMONX86 : CSIDL_PROGRAM_FILES_COMMON;
            break;
        }
    }

    if (CSIDL_Data[folder].szDefaultPath &&
     IS_INTRESOURCE(CSIDL_Data[folder].szDefaultPath))
    {
        if (LoadStringW(shell32_hInstance,
         LOWORD(CSIDL_Data[folder].szDefaultPath), resourcePath, MAX_PATH))
        {
            hr = S_OK;
            pDefaultPath = resourcePath;
        }
        else
        {
            FIXME("(%d,%s), LoadString failed, missing translation?\n", folder,
             debugstr_w(pszPath));
            hr = E_FAIL;
        }
    }
    else
    {
        hr = S_OK;
        pDefaultPath = CSIDL_Data[folder].szDefaultPath;
    }
    if (SUCCEEDED(hr))
    {
        switch (CSIDL_Data[folder].type)
        {
            case CSIDL_Type_User:
                strcpyW(pszPath, UserProfileW);
                break;
            case CSIDL_Type_AllUsers:
                strcpyW(pszPath, AllUsersProfileW);
                break;
            case CSIDL_Type_CurrVer:
                strcpyW(pszPath, SystemDriveW);
                break;
            default:
                ; /* no corresponding env. var, do nothing */
        }
        if (pDefaultPath)
        {
            PathAddBackslashW(pszPath);
            strcatW(pszPath, pDefaultPath);
        }
    }
    TRACE("returning 0x%08x\n", hr);
    return hr;
}

/* Gets the (unexpanded) value of the folder with index folder into pszPath.
 * The folder's type is assumed to be CSIDL_Type_CurrVer.  Its default value
 * can be overridden in the HKLM\\szCurrentVersion key.
 * If dwFlags has SHGFP_TYPE_DEFAULT set or if the value isn't overridden in
 * the registry, uses _SHGetDefaultValue to get the value.
 */
static HRESULT _SHGetCurrentVersionPath(DWORD dwFlags, BYTE folder,
 LPWSTR pszPath)
{
    HRESULT hr;

    TRACE("0x%08x,0x%02x,%p\n", dwFlags, folder, pszPath);

    if (folder >= sizeof(CSIDL_Data) / sizeof(CSIDL_Data[0]))
        return E_INVALIDARG;
    if (CSIDL_Data[folder].type != CSIDL_Type_CurrVer)
        return E_INVALIDARG;
    if (!pszPath)
        return E_INVALIDARG;

    if (dwFlags & SHGFP_TYPE_DEFAULT)
        hr = _SHGetDefaultValue(folder, pszPath);
    else
    {
        HKEY hKey;

        if (RegCreateKeyW(HKEY_LOCAL_MACHINE, szCurrentVersion, &hKey))
            hr = E_FAIL;
        else
        {
            DWORD dwType, dwPathLen = MAX_PATH * sizeof(WCHAR);

            if (RegQueryValueExW(hKey, CSIDL_Data[folder].szValueName, NULL,
             &dwType, (LPBYTE)pszPath, &dwPathLen) ||
             (dwType != REG_SZ && dwType != REG_EXPAND_SZ))
            {
                hr = _SHGetDefaultValue(folder, pszPath);
                dwType = REG_EXPAND_SZ;
                switch (folder)
                {
                case CSIDL_PROGRAM_FILESX86:
                case CSIDL_PROGRAM_FILES_COMMONX86:
                    /* these two should never be set on 32-bit setups */
                    if (!is_win64)
                    {
                        BOOL is_wow64;
                        IsWow64Process( GetCurrentProcess(), &is_wow64 );
                        if (!is_wow64) break;
                    }
                    /* fall through */
                default:
                    RegSetValueExW(hKey, CSIDL_Data[folder].szValueName, 0, dwType,
                                   (LPBYTE)pszPath, (strlenW(pszPath)+1)*sizeof(WCHAR));
                }
            }
            else
            {
                pszPath[dwPathLen / sizeof(WCHAR)] = '\0';
                hr = S_OK;
            }
            RegCloseKey(hKey);
        }
    }
    TRACE("returning 0x%08x (output path is %s)\n", hr, debugstr_w(pszPath));
    return hr;
}

static LPWSTR _GetUserSidStringFromToken(HANDLE Token)
{
    char InfoBuffer[64];
    PTOKEN_USER UserInfo;
    DWORD InfoSize;
    LPWSTR SidStr;

    UserInfo = (PTOKEN_USER) InfoBuffer;
    if (! GetTokenInformation(Token, TokenUser, InfoBuffer, sizeof(InfoBuffer),
                              &InfoSize))
    {
        if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
            return NULL;
        UserInfo = HeapAlloc(GetProcessHeap(), 0, InfoSize);
        if (UserInfo == NULL)
            return NULL;
        if (! GetTokenInformation(Token, TokenUser, UserInfo, InfoSize,
                                  &InfoSize))
        {
            HeapFree(GetProcessHeap(), 0, UserInfo);
            return NULL;
        }
    }

    if (! ConvertSidToStringSidW(UserInfo->User.Sid, &SidStr))
        SidStr = NULL;

    if (UserInfo != (PTOKEN_USER) InfoBuffer)
        HeapFree(GetProcessHeap(), 0, UserInfo);

    return SidStr;
}

/* Gets the user's path (unexpanded) for the CSIDL with index folder:
 * If SHGFP_TYPE_DEFAULT is set, calls _SHGetDefaultValue for it.  Otherwise
 * calls _SHGetUserShellFolderPath for it.  Where it looks depends on hToken:
 * - if hToken is -1, looks in HKEY_USERS\.Default
 * - otherwise looks first in HKEY_CURRENT_USER, followed by HKEY_LOCAL_MACHINE
 *   if HKEY_CURRENT_USER doesn't contain any entries.  If both fail, finally
 *   calls _SHGetDefaultValue for it.
 */
static HRESULT _SHGetUserProfilePath(HANDLE hToken, DWORD dwFlags, BYTE folder,
 LPWSTR pszPath)
{
    const WCHAR *szValueName;
    WCHAR buffer[40];
    HRESULT hr;

    TRACE("%p,0x%08x,0x%02x,%p\n", hToken, dwFlags, folder, pszPath);

    if (folder >= sizeof(CSIDL_Data) / sizeof(CSIDL_Data[0]))
        return E_INVALIDARG;
    if (CSIDL_Data[folder].type != CSIDL_Type_User)
        return E_INVALIDARG;
    if (!pszPath)
        return E_INVALIDARG;

    if (dwFlags & SHGFP_TYPE_DEFAULT)
    {
        if (hToken != NULL && hToken != (HANDLE)-1)
        {
            FIXME("unsupported for user other than current or default\n");
            return E_FAIL;
        }
        hr = _SHGetDefaultValue(folder, pszPath);
    }
    else
    {
        LPCWSTR userPrefix = NULL;
        HKEY hRootKey;

        if (hToken == (HANDLE)-1)
        {
            hRootKey = HKEY_USERS;
            userPrefix = DefaultW;
        }
        else if (hToken == NULL)
            hRootKey = HKEY_CURRENT_USER;
        else
        {
            hRootKey = HKEY_USERS;
            userPrefix = _GetUserSidStringFromToken(hToken);
            if (userPrefix == NULL)
            {
                hr = E_FAIL;
                goto error;
            }
        }

        /* For CSIDL_Type_User we also use the GUID if no szValueName is provided */
        szValueName = CSIDL_Data[folder].szValueName;
        if (!szValueName)
        {
            StringFromGUID2( CSIDL_Data[folder].id, buffer, 39 );
            szValueName = &buffer[0];
        }

        hr = _SHGetUserShellFolderPath(hRootKey, userPrefix, szValueName, pszPath);
        if (FAILED(hr) && hRootKey != HKEY_LOCAL_MACHINE)
            hr = _SHGetUserShellFolderPath(HKEY_LOCAL_MACHINE, NULL, szValueName, pszPath);
        if (FAILED(hr))
            hr = _SHGetDefaultValue(folder, pszPath);
        if (userPrefix != NULL && userPrefix != DefaultW)
            LocalFree((HLOCAL) userPrefix);
    }
error:
    TRACE("returning 0x%08x (output path is %s)\n", hr, debugstr_w(pszPath));
    return hr;
}

/* Gets the (unexpanded) path for the CSIDL with index folder.  If dwFlags has
 * SHGFP_TYPE_DEFAULT set, calls _SHGetDefaultValue.  Otherwise calls
 * _SHGetUserShellFolderPath for it, looking only in HKEY_LOCAL_MACHINE.
 * If this fails, falls back to _SHGetDefaultValue.
 */
static HRESULT _SHGetAllUsersProfilePath(DWORD dwFlags, BYTE folder,
 LPWSTR pszPath)
{
    HRESULT hr;

    TRACE("0x%08x,0x%02x,%p\n", dwFlags, folder, pszPath);

    if (folder >= sizeof(CSIDL_Data) / sizeof(CSIDL_Data[0]))
        return E_INVALIDARG;
    if (CSIDL_Data[folder].type != CSIDL_Type_AllUsers)
        return E_INVALIDARG;
    if (!pszPath)
        return E_INVALIDARG;

    if (dwFlags & SHGFP_TYPE_DEFAULT)
        hr = _SHGetDefaultValue(folder, pszPath);
    else
    {
        hr = _SHGetUserShellFolderPath(HKEY_LOCAL_MACHINE, NULL,
         CSIDL_Data[folder].szValueName, pszPath);
        if (FAILED(hr))
            hr = _SHGetDefaultValue(folder, pszPath);
    }
    TRACE("returning 0x%08x (output path is %s)\n", hr, debugstr_w(pszPath));
    return hr;
}

static HRESULT _SHOpenProfilesKey(PHKEY pKey)
{
    LONG lRet;
    DWORD disp;

    lRet = RegCreateKeyExW(HKEY_LOCAL_MACHINE, ProfileListW, 0, NULL, 0,
     KEY_ALL_ACCESS, NULL, pKey, &disp);
    return HRESULT_FROM_WIN32(lRet);
}

/* Reads the value named szValueName from the key profilesKey (assumed to be
 * opened by _SHOpenProfilesKey) into szValue, which is assumed to be MAX_PATH
 * WCHARs in length.  If it doesn't exist, returns szDefault (and saves
 * szDefault to the registry).
 */
static HRESULT _SHGetProfilesValue(HKEY profilesKey, LPCWSTR szValueName,
 LPWSTR szValue, LPCWSTR szDefault)
{
    HRESULT hr;
    DWORD type, dwPathLen = MAX_PATH * sizeof(WCHAR);
    LONG lRet;

    TRACE("%p,%s,%p,%s\n", profilesKey, debugstr_w(szValueName), szValue,
     debugstr_w(szDefault));
    lRet = RegQueryValueExW(profilesKey, szValueName, NULL, &type,
     (LPBYTE)szValue, &dwPathLen);
    if (!lRet && (type == REG_SZ || type == REG_EXPAND_SZ) && dwPathLen
     && *szValue)
    {
        dwPathLen /= sizeof(WCHAR);
        szValue[dwPathLen] = '\0';
        hr = S_OK;
    }
    else
    {
        /* Missing or invalid value, set a default */
        lstrcpynW(szValue, szDefault, MAX_PATH);
        TRACE("Setting missing value %s to %s\n", debugstr_w(szValueName),
                                                  debugstr_w(szValue));
        lRet = RegSetValueExW(profilesKey, szValueName, 0, REG_EXPAND_SZ,
                              (LPBYTE)szValue,
                              (strlenW(szValue) + 1) * sizeof(WCHAR));
        if (lRet)
            hr = HRESULT_FROM_WIN32(lRet);
        else
            hr = S_OK;
    }
    TRACE("returning 0x%08x (output value is %s)\n", hr, debugstr_w(szValue));
    return hr;
}

/* Attempts to expand environment variables from szSrc into szDest, which is
 * assumed to be MAX_PATH characters in length.  Before referring to the
 * environment, handles a few variables directly, because the environment
 * variables may not be set when this is called (as during Wine's installation
 * when default values are being written to the registry).
 * The directly handled environment variables, and their source, are:
 * - ALLUSERSPROFILE, USERPROFILE: reads from the registry
 * - SystemDrive: uses GetSystemDirectoryW and uses the drive portion of its
 *   path
 * If one of the directly handled environment variables is expanded, only
 * expands a single variable, and only in the beginning of szSrc.
 */
static HRESULT _SHExpandEnvironmentStrings(LPCWSTR szSrc, LPWSTR szDest)
{
    HRESULT hr;
    WCHAR szTemp[MAX_PATH], szProfilesPrefix[MAX_PATH] = { 0 };
    HKEY key = NULL;

    TRACE("%s, %p\n", debugstr_w(szSrc), szDest);

    if (!szSrc || !szDest) return E_INVALIDARG;

    /* short-circuit if there's nothing to expand */
    if (szSrc[0] != '%')
    {
        strcpyW(szDest, szSrc);
        hr = S_OK;
        goto end;
    }
    /* Get the profile prefix, we'll probably be needing it */
    hr = _SHOpenProfilesKey(&key);
    if (SUCCEEDED(hr))
    {
        WCHAR def_val[MAX_PATH];

        /* get the system drive */
        GetSystemDirectoryW(def_val, MAX_PATH);
        if (def_val[1] == ':') strcpyW( def_val + 3, szDefaultProfileDirW );
        else FIXME("non-drive system paths unsupported\n");

        hr = _SHGetProfilesValue(key, ProfilesDirectoryW, szProfilesPrefix, def_val );
    }

    *szDest = 0;
    strcpyW(szTemp, szSrc);
    while (SUCCEEDED(hr) && szTemp[0] == '%')
    {
        if (!strncmpiW(szTemp, AllUsersProfileW, strlenW(AllUsersProfileW)))
        {
            WCHAR szAllUsers[MAX_PATH];

            strcpyW(szDest, szProfilesPrefix);
            hr = _SHGetProfilesValue(key, AllUsersProfileValueW,
             szAllUsers, AllUsersW);
            PathAppendW(szDest, szAllUsers);
            PathAppendW(szDest, szTemp + strlenW(AllUsersProfileW));
        }
        else if (!strncmpiW(szTemp, UserProfileW, strlenW(UserProfileW)))
        {
            WCHAR userName[MAX_PATH];
            DWORD userLen = MAX_PATH;

            strcpyW(szDest, szProfilesPrefix);
            GetUserNameW(userName, &userLen);
            PathAppendW(szDest, userName);
            PathAppendW(szDest, szTemp + strlenW(UserProfileW));
        }
        else if (!strncmpiW(szTemp, SystemDriveW, strlenW(SystemDriveW)))
        {
            GetSystemDirectoryW(szDest, MAX_PATH);
            if (szDest[1] != ':')
            {
                FIXME("non-drive system paths unsupported\n");
                hr = E_FAIL;
            }
            else
            {
                strcpyW(szDest + 3, szTemp + strlenW(SystemDriveW) + 1);
                hr = S_OK;
            }
        }
        else
        {
            DWORD ret = ExpandEnvironmentStringsW(szSrc, szDest, MAX_PATH);

            if (ret > MAX_PATH)
                hr = HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
            else if (ret == 0)
                hr = HRESULT_FROM_WIN32(GetLastError());
            else
                hr = S_OK;
        }
        if (SUCCEEDED(hr) && szDest[0] == '%')
            strcpyW(szTemp, szDest);
        else
        {
            /* terminate loop */
            szTemp[0] = '\0';
        }
    }
end:
    if (key)
        RegCloseKey(key);
    TRACE("returning 0x%08x (input was %s, output is %s)\n", hr,
     debugstr_w(szSrc), debugstr_w(szDest));
    return hr;
}

/* For each folder in folders, if its value has not been set in the registry,
 * calls _SHGetUserProfilePath or _SHGetAllUsersProfilePath (depending on the
 * folder's type) to get the unexpanded value first.
 * Writes the unexpanded value to User Shell Folders, and queries it with
 * SHGetFolderPathW to force the creation of the directory if it doesn't
 * already exist.  SHGetFolderPathW also returns the expanded value, which
 * this then writes to Shell Folders.
 */
static HRESULT _SHRegisterFolders(HKEY hRootKey, HANDLE hToken,
 LPCWSTR szUserShellFolderPath, LPCWSTR szShellFolderPath, const UINT folders[],
 UINT foldersLen)
{
    const WCHAR *szValueName;
    WCHAR buffer[40];
    UINT i;
    WCHAR path[MAX_PATH];
    HRESULT hr = S_OK;
    HKEY hUserKey = NULL, hKey = NULL;
    DWORD dwType, dwPathLen;
    LONG ret;

    TRACE("%p,%p,%s,%p,%u\n", hRootKey, hToken,
     debugstr_w(szUserShellFolderPath), folders, foldersLen);

    ret = RegCreateKeyW(hRootKey, szUserShellFolderPath, &hUserKey);
    if (ret)
        hr = HRESULT_FROM_WIN32(ret);
    else
    {
        ret = RegCreateKeyW(hRootKey, szShellFolderPath, &hKey);
        if (ret)
            hr = HRESULT_FROM_WIN32(ret);
    }
    for (i = 0; SUCCEEDED(hr) && i < foldersLen; i++)
    {
        dwPathLen = MAX_PATH * sizeof(WCHAR);

        /* For CSIDL_Type_User we also use the GUID if no szValueName is provided */
        szValueName = CSIDL_Data[folders[i]].szValueName;
        if (!szValueName && CSIDL_Data[folders[i]].type == CSIDL_Type_User)
        {
            StringFromGUID2( CSIDL_Data[folders[i]].id, buffer, 39 );
            szValueName = &buffer[0];
        }

        if (RegQueryValueExW(hUserKey, szValueName, NULL,
         &dwType, (LPBYTE)path, &dwPathLen) || (dwType != REG_SZ &&
         dwType != REG_EXPAND_SZ))
        {
            *path = '\0';
            if (CSIDL_Data[folders[i]].type == CSIDL_Type_User)
                _SHGetUserProfilePath(hToken, SHGFP_TYPE_DEFAULT, folders[i],
                 path);
            else if (CSIDL_Data[folders[i]].type == CSIDL_Type_AllUsers)
                _SHGetAllUsersProfilePath(SHGFP_TYPE_DEFAULT, folders[i], path);
            else if (CSIDL_Data[folders[i]].type == CSIDL_Type_WindowsPath)
            {
                GetWindowsDirectoryW(path, MAX_PATH);
                if (CSIDL_Data[folders[i]].szDefaultPath &&
                    !IS_INTRESOURCE(CSIDL_Data[folders[i]].szDefaultPath))
                {
                    PathAddBackslashW(path);
                    strcatW(path, CSIDL_Data[folders[i]].szDefaultPath);
                }
            }
            else
                hr = E_FAIL;
            if (*path)
            {
                ret = RegSetValueExW(hUserKey, szValueName, 0, REG_EXPAND_SZ,
                 (LPBYTE)path, (strlenW(path) + 1) * sizeof(WCHAR));
                if (ret)
                    hr = HRESULT_FROM_WIN32(ret);
                else
                {
                    hr = SHGetFolderPathW(NULL, folders[i] | CSIDL_FLAG_CREATE,
                     hToken, SHGFP_TYPE_DEFAULT, path);
                    ret = RegSetValueExW(hKey, szValueName, 0, REG_SZ,
                     (LPBYTE)path, (strlenW(path) + 1) * sizeof(WCHAR));
                    if (ret)
                        hr = HRESULT_FROM_WIN32(ret);
                }
            }
        }
    }
    if (hUserKey)
        RegCloseKey(hUserKey);
    if (hKey)
        RegCloseKey(hKey);

    TRACE("returning 0x%08x\n", hr);
    return hr;
}

static HRESULT _SHRegisterUserShellFolders(BOOL bDefault)
{
    static const UINT folders[] = {
     CSIDL_PROGRAMS,
     CSIDL_PERSONAL,
     CSIDL_FAVORITES,
     CSIDL_APPDATA,
     CSIDL_STARTUP,
     CSIDL_RECENT,
     CSIDL_SENDTO,
     CSIDL_STARTMENU,
     CSIDL_MYMUSIC,
     CSIDL_MYVIDEO,
     CSIDL_DESKTOPDIRECTORY,
     CSIDL_NETHOOD,
     CSIDL_TEMPLATES,
     CSIDL_PRINTHOOD,
     CSIDL_LOCAL_APPDATA,
     CSIDL_INTERNET_CACHE,
     CSIDL_COOKIES,
     CSIDL_HISTORY,
     CSIDL_MYPICTURES,
     CSIDL_FONTS,
     CSIDL_ADMINTOOLS,
     CSIDL_CONTACTS,
     CSIDL_DOWNLOADS,
     CSIDL_LINKS,
     CSIDL_APPDATA_LOCALLOW,
     CSIDL_SAVED_GAMES,
     CSIDL_SEARCHES
    };
    WCHAR userShellFolderPath[MAX_PATH], shellFolderPath[MAX_PATH];
    LPCWSTR pUserShellFolderPath, pShellFolderPath;
    HRESULT hr = S_OK;
    HKEY hRootKey;
    HANDLE hToken;

    TRACE("%s\n", bDefault ? "TRUE" : "FALSE");
    if (bDefault)
    {
        hToken = (HANDLE)-1;
        hRootKey = HKEY_USERS;
        strcpyW(userShellFolderPath, DefaultW);
        PathAddBackslashW(userShellFolderPath);
        strcatW(userShellFolderPath, szSHUserFolders);
        pUserShellFolderPath = userShellFolderPath;
        strcpyW(shellFolderPath, DefaultW);
        PathAddBackslashW(shellFolderPath);
        strcatW(shellFolderPath, szSHFolders);
        pShellFolderPath = shellFolderPath;
    }
    else
    {
        hToken = NULL;
        hRootKey = HKEY_CURRENT_USER;
        pUserShellFolderPath = szSHUserFolders;
        pShellFolderPath = szSHFolders;
    }

    hr = _SHRegisterFolders(hRootKey, hToken, pUserShellFolderPath,
     pShellFolderPath, folders, sizeof(folders) / sizeof(folders[0]));
    TRACE("returning 0x%08x\n", hr);
    return hr;
}

static HRESULT _SHRegisterCommonShellFolders(void)
{
    static const UINT folders[] = {
     CSIDL_COMMON_STARTMENU,
     CSIDL_COMMON_PROGRAMS,
     CSIDL_COMMON_STARTUP,
     CSIDL_COMMON_DESKTOPDIRECTORY,
     CSIDL_COMMON_FAVORITES,
     CSIDL_COMMON_APPDATA,
     CSIDL_COMMON_TEMPLATES,
     CSIDL_COMMON_DOCUMENTS,
     CSIDL_COMMON_ADMINTOOLS,
     CSIDL_COMMON_MUSIC,
     CSIDL_COMMON_PICTURES,
     CSIDL_COMMON_VIDEO,
    };
    HRESULT hr;

    TRACE("\n");
    hr = _SHRegisterFolders(HKEY_LOCAL_MACHINE, NULL, szSHUserFolders,
     szSHFolders, folders, sizeof(folders) / sizeof(folders[0]));
    TRACE("returning 0x%08x\n", hr);
    return hr;
}

/******************************************************************************
 * create_extra_folders  [Internal]
 *
 * Create some extra folders that don't have a standard CSIDL definition.
 */
static HRESULT create_extra_folders(void)
{
    static const WCHAR environW[] = {'E','n','v','i','r','o','n','m','e','n','t',0};
    static const WCHAR microsoftW[] = {'M','i','c','r','o','s','o','f','t',0};
    static const WCHAR TempW[]    = {'T','e','m','p',0};
    static const WCHAR TEMPW[]    = {'T','E','M','P',0};
    static const WCHAR TMPW[]     = {'T','M','P',0};
    WCHAR path[MAX_PATH+5];
    HRESULT hr;
    HKEY hkey;
    DWORD type, size, ret;

    ret = RegCreateKeyW( HKEY_CURRENT_USER, environW, &hkey );
    if (ret) return HRESULT_FROM_WIN32( ret );

    /* FIXME: should be under AppData, but we don't want spaces in the temp path */
    hr = SHGetFolderPathAndSubDirW( 0, CSIDL_PROFILE | CSIDL_FLAG_CREATE, NULL,
                                    SHGFP_TYPE_DEFAULT, TempW, path );
    if (SUCCEEDED(hr))
    {
        size = sizeof(path);
        if (RegQueryValueExW( hkey, TEMPW, NULL, &type, (LPBYTE)path, &size ))
            RegSetValueExW( hkey, TEMPW, 0, REG_SZ, (LPBYTE)path, (strlenW(path) + 1) * sizeof(WCHAR) );
        size = sizeof(path);
        if (RegQueryValueExW( hkey, TMPW, NULL, &type, (LPBYTE)path, &size ))
            RegSetValueExW( hkey, TMPW, 0, REG_SZ, (LPBYTE)path, (strlenW(path) + 1) * sizeof(WCHAR) );
    }
    RegCloseKey( hkey );

    if (SUCCEEDED(hr))
    {
        hr = SHGetFolderPathAndSubDirW( 0, CSIDL_COMMON_APPDATA | CSIDL_FLAG_CREATE, NULL,
                                        SHGFP_TYPE_DEFAULT, microsoftW, path );
    }
    return hr;
}


/*
 * Internal function to convert known folder identifier to path of registry key
 * associated with known folder.
 *
 * Parameters:
 *  rfid            [I] pointer to known folder identifier (may be NULL)
 *  lpStringGuid    [I] string with known folder identifier (used when rfid is NULL)
 *  lpPath          [O] place to store string address. String should be
 *                      later freed using HeapFree(GetProcessHeap(),0, ... )
 */
static HRESULT get_known_folder_registry_path(
    REFKNOWNFOLDERID rfid,
    LPWSTR lpStringGuid,
    LPWSTR *lpPath)
{
    static const WCHAR sBackslash[] = {'\\',0};
    HRESULT hr = S_OK;
    int length;
    WCHAR sGuid[50];

    TRACE("(%s, %s, %p)\n", debugstr_guid(rfid), debugstr_w(lpStringGuid), lpPath);

    if(rfid)
        StringFromGUID2(rfid, sGuid, sizeof(sGuid)/sizeof(sGuid[0]));
    else
        lstrcpyW(sGuid, lpStringGuid);

    length = lstrlenW(szKnownFolderDescriptions)+51;
    *lpPath = HeapAlloc(GetProcessHeap(), 0, length*sizeof(WCHAR));
    if(!(*lpPath))
        hr = E_OUTOFMEMORY;

    if(SUCCEEDED(hr))
    {
        lstrcpyW(*lpPath, szKnownFolderDescriptions);
        lstrcatW(*lpPath, sBackslash);
        lstrcatW(*lpPath, sGuid);
    }

    return hr;
}

/*
 * Internal function to get place where folder redirection information are stored.
 *
 * Parameters:
 *  rfid            [I] pointer to known folder identifier (may be NULL)
 *  rootKey         [O] root key where the redirection information are stored
 *                      It can be HKLM for COMMON folders, and HKCU for PERUSER folders.
 *                      However, besides root key, path is always that same, and is stored
 *                      as "szKnownFolderRedirections" constant
 */
static HRESULT get_known_folder_redirection_place(
    REFKNOWNFOLDERID rfid,
    HKEY *rootKey)
{
    HRESULT hr;
    LPWSTR lpRegistryPath = NULL;
    KF_CATEGORY category;
    DWORD dwSize;

    /* first, get known folder's category */
    hr = get_known_folder_registry_path(rfid, NULL, &lpRegistryPath);

    if(SUCCEEDED(hr))
    {
        dwSize = sizeof(category);
        hr = HRESULT_FROM_WIN32(RegGetValueW(HKEY_LOCAL_MACHINE, lpRegistryPath, szCategory, RRF_RT_DWORD, NULL, &category, &dwSize));
    }

    if(SUCCEEDED(hr))
    {
        if(category == KF_CATEGORY_COMMON)
        {
            *rootKey = HKEY_LOCAL_MACHINE;
            hr = S_OK;
        }
        else if(category == KF_CATEGORY_PERUSER)
        {
            *rootKey = HKEY_CURRENT_USER;
            hr = S_OK;
        }
        else
            hr = E_FAIL;
    }

    HeapFree(GetProcessHeap(), 0, lpRegistryPath);
    return hr;
}

static HRESULT get_known_folder_path_by_id(REFKNOWNFOLDERID folderId, LPWSTR lpRegistryPath, DWORD dwFlags, LPWSTR *ppszPath);

static HRESULT get_known_folder_category(
    LPWSTR registryPath,
    KF_CATEGORY* pCategory)
{
    DWORD dwSize = sizeof(DWORD);
    DWORD dwType;
    return HRESULT_FROM_WIN32(RegGetValueW(HKEY_LOCAL_MACHINE, registryPath, szCategory, RRF_RT_DWORD, &dwType, pCategory, &dwSize));
}

static HRESULT redirect_known_folder(
    REFKNOWNFOLDERID rfid,
    HWND hwnd,
    KF_REDIRECT_FLAGS flags,
    LPCWSTR pszTargetPath,
    UINT cFolders,
    KNOWNFOLDERID const *pExclusion,
    LPWSTR *ppszError)
{
    HRESULT hr;
    HKEY rootKey = HKEY_LOCAL_MACHINE, hKey;
    WCHAR sGuid[39];
    LPWSTR lpRegistryPath = NULL, lpSrcPath = NULL;
    TRACE("(%s, %p, 0x%08x, %s, %d, %p, %p)\n", debugstr_guid(rfid), hwnd, flags, debugstr_w(pszTargetPath), cFolders, pExclusion, ppszError);

    if (ppszError) *ppszError = NULL;

    hr = get_known_folder_registry_path(rfid, NULL, &lpRegistryPath);

    if(SUCCEEDED(hr))
        hr = get_known_folder_path_by_id(rfid, lpRegistryPath, 0, &lpSrcPath);

    HeapFree(GetProcessHeap(), 0, lpRegistryPath);

    /* get path to redirection storage */
    if(SUCCEEDED(hr))
        hr = get_known_folder_redirection_place(rfid, &rootKey);

    /* write redirection information */
    if(SUCCEEDED(hr))
        hr = HRESULT_FROM_WIN32(RegCreateKeyExW(rootKey, szKnownFolderRedirections, 0, NULL, 0, KEY_WRITE, NULL, &hKey, NULL));

    if(SUCCEEDED(hr))
    {
        StringFromGUID2(rfid, sGuid, sizeof(sGuid)/sizeof(sGuid[0]));

        hr = HRESULT_FROM_WIN32(RegSetValueExW(hKey, sGuid, 0, REG_SZ, (LPBYTE)pszTargetPath, (lstrlenW(pszTargetPath)+1)*sizeof(WCHAR)));

        RegCloseKey(hKey);
    }

    /* make sure destination path exists */
    SHCreateDirectory(NULL, pszTargetPath);

    /* copy content if required */
    if(SUCCEEDED(hr) && (flags & KF_REDIRECT_COPY_CONTENTS) )
    {
        static const WCHAR sWildcard[] = {'\\','*',0};
        WCHAR srcPath[MAX_PATH+1], dstPath[MAX_PATH+1];
        SHFILEOPSTRUCTW fileOp;

        ZeroMemory(srcPath, sizeof(srcPath));
        lstrcpyW(srcPath, lpSrcPath);
        lstrcatW(srcPath, sWildcard);

        ZeroMemory(dstPath, sizeof(dstPath));
        lstrcpyW(dstPath, pszTargetPath);

        ZeroMemory(&fileOp, sizeof(fileOp));

        if(flags & KF_REDIRECT_DEL_SOURCE_CONTENTS)
            fileOp.wFunc = FO_MOVE;
        else
            fileOp.wFunc = FO_COPY;

        fileOp.pFrom = srcPath;
        fileOp.pTo = dstPath;
        fileOp.fFlags = FOF_NO_UI;

        hr = (SHFileOperationW(&fileOp)==0 ? S_OK : E_FAIL);

        if(flags & KF_REDIRECT_DEL_SOURCE_CONTENTS)
        {
            ZeroMemory(srcPath, sizeof(srcPath));
            lstrcpyW(srcPath, lpSrcPath);

            ZeroMemory(&fileOp, sizeof(fileOp));
            fileOp.wFunc = FO_DELETE;
            fileOp.pFrom = srcPath;
            fileOp.fFlags = FOF_NO_UI;

            hr = (SHFileOperationW(&fileOp)==0 ? S_OK : E_FAIL);
        }
    }

    CoTaskMemFree(lpSrcPath);

    return hr;
}

struct knownfolder
{
    IKnownFolder IKnownFolder_iface;
    LONG refs;
    KNOWNFOLDERID id;
    LPWSTR registryPath;
};

static inline struct knownfolder *impl_from_IKnownFolder( IKnownFolder *iface )
{
    return CONTAINING_RECORD( iface, struct knownfolder, IKnownFolder_iface );
}

static ULONG WINAPI knownfolder_AddRef(
    IKnownFolder *iface )
{
    struct knownfolder *knownfolder = impl_from_IKnownFolder( iface );
    return InterlockedIncrement( &knownfolder->refs );
}

static ULONG WINAPI knownfolder_Release(
    IKnownFolder *iface )
{
    struct knownfolder *knownfolder = impl_from_IKnownFolder( iface );
    LONG refs = InterlockedDecrement( &knownfolder->refs );
    if (!refs)
    {
        TRACE("destroying %p\n", knownfolder);
        HeapFree( GetProcessHeap(), 0, knownfolder->registryPath);
        HeapFree( GetProcessHeap(), 0, knownfolder );
    }
    return refs;
}

static HRESULT WINAPI knownfolder_QueryInterface(
    IKnownFolder *iface,
    REFIID riid,
    void **ppv )
{
    struct knownfolder *This = impl_from_IKnownFolder( iface );

    TRACE("%p %s %p\n", This, debugstr_guid( riid ), ppv );

    if ( IsEqualGUID( riid, &IID_IKnownFolder ) ||
         IsEqualGUID( riid, &IID_IUnknown ) )
    {
        *ppv = iface;
    }
    else
    {
        FIXME("interface %s not implemented\n", debugstr_guid(riid));
        return E_NOINTERFACE;
    }
    IKnownFolder_AddRef( iface );
    return S_OK;
}

static HRESULT knownfolder_set_id(
    struct knownfolder *knownfolder,
    const KNOWNFOLDERID *kfid)
{
    HKEY hKey;
    HRESULT hr;

    TRACE("%s\n", debugstr_guid(kfid));

    knownfolder->id = *kfid;

    /* check is it registry-registered folder */
    hr = get_known_folder_registry_path(kfid, NULL, &knownfolder->registryPath);
    if(SUCCEEDED(hr))
        hr = HRESULT_FROM_WIN32(RegOpenKeyExW(HKEY_LOCAL_MACHINE, knownfolder->registryPath, 0, 0, &hKey));

    if(SUCCEEDED(hr))
    {
        hr = S_OK;
        RegCloseKey(hKey);
    }
    else
    {
        /* This known folder is not registered. To mark it, we set registryPath to NULL */
        HeapFree(GetProcessHeap(), 0, knownfolder->registryPath);
        knownfolder->registryPath = NULL;
        hr = S_OK;
    }

    return hr;
}

static HRESULT WINAPI knownfolder_GetId(
    IKnownFolder *iface,
    KNOWNFOLDERID *pkfid)
{
    struct knownfolder *knownfolder = impl_from_IKnownFolder( iface );

    TRACE("%p\n", pkfid);

    *pkfid = knownfolder->id;
    return S_OK;
}

static HRESULT WINAPI knownfolder_GetCategory(
    IKnownFolder *iface,
    KF_CATEGORY *pCategory)
{
    struct knownfolder *knownfolder = impl_from_IKnownFolder(iface);
    HRESULT hr = S_OK;

    TRACE("%p, %p\n", knownfolder, pCategory);

    /* we cannot get a category for a folder which is not registered */
    if(!knownfolder->registryPath)
        hr = E_FAIL;

    if(SUCCEEDED(hr))
        hr = get_known_folder_category(knownfolder->registryPath, pCategory);

    return hr;
}

static HRESULT WINAPI knownfolder_GetShellItem(
    IKnownFolder *iface,
    DWORD flags,
    REFIID riid,
    void **ppv)
{
    struct knownfolder *knownfolder = impl_from_IKnownFolder(iface);
    TRACE("(%p, 0x%08x, %s, %p)\n", knownfolder, flags, debugstr_guid(riid), ppv);
    return SHGetKnownFolderItem(&knownfolder->id, flags, NULL, riid, ppv);
}

static HRESULT get_known_folder_path(
    LPWSTR sFolderId,
    LPWSTR registryPath,
    LPWSTR *ppszPath)
{
    static const WCHAR sBackslash[] = {'\\',0};
    HRESULT hr;
    DWORD dwSize, dwType;
    WCHAR path[MAX_PATH] = {0};
    WCHAR parentGuid[39];
    KF_CATEGORY category;
    LPWSTR parentRegistryPath, parentPath;
    HKEY hRedirectionRootKey = NULL;

    TRACE("(%s, %p)\n", debugstr_w(registryPath), ppszPath);
    *ppszPath = NULL;

    /* check if folder has parent */
    dwSize = sizeof(parentGuid);
    hr = HRESULT_FROM_WIN32(RegGetValueW(HKEY_LOCAL_MACHINE, registryPath, szParentFolder, RRF_RT_REG_SZ, &dwType, parentGuid, &dwSize));
    if(hr == HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)) hr = S_FALSE;

    if(hr == S_OK)
    {
        /* get parent's known folder path (recursive) */
        hr = get_known_folder_registry_path(NULL, parentGuid, &parentRegistryPath);
        if(FAILED(hr)) return hr;

        hr = get_known_folder_path(parentGuid, parentRegistryPath, &parentPath);
        if(FAILED(hr)) {
            HeapFree(GetProcessHeap(), 0, parentRegistryPath);
            return hr;
        }

        lstrcatW(path, parentPath);
        lstrcatW(path, sBackslash);

        HeapFree(GetProcessHeap(), 0, parentRegistryPath);
        HeapFree(GetProcessHeap(), 0, parentPath);
    }

    /* check, if folder was redirected */
    if(SUCCEEDED(hr))
        hr = HRESULT_FROM_WIN32(RegGetValueW(HKEY_LOCAL_MACHINE, registryPath, szCategory, RRF_RT_REG_DWORD, NULL, &category, &dwSize));

    if(SUCCEEDED(hr))
    {
        if(category == KF_CATEGORY_COMMON)
            hRedirectionRootKey = HKEY_LOCAL_MACHINE;
        else if(category == KF_CATEGORY_PERUSER)
            hRedirectionRootKey = HKEY_CURRENT_USER;

        if(hRedirectionRootKey)
        {
            hr = HRESULT_FROM_WIN32(RegGetValueW(hRedirectionRootKey, szKnownFolderRedirections, sFolderId, RRF_RT_REG_SZ, NULL, NULL, &dwSize));

            if(SUCCEEDED(hr))
            {
                *ppszPath = CoTaskMemAlloc(dwSize+(lstrlenW(path)+1)*sizeof(WCHAR));
                if(!*ppszPath) hr = E_OUTOFMEMORY;
            }

            if(SUCCEEDED(hr))
            {
                lstrcpyW(*ppszPath, path);
                hr = HRESULT_FROM_WIN32(RegGetValueW(hRedirectionRootKey, szKnownFolderRedirections, sFolderId, RRF_RT_REG_SZ, NULL, *ppszPath + lstrlenW(path), &dwSize));
            }
        }

        if(!*ppszPath)
        {
            /* no redirection, use previous way - read the relative path from folder definition */
            hr = HRESULT_FROM_WIN32(RegGetValueW(HKEY_LOCAL_MACHINE, registryPath, szRelativePath, RRF_RT_REG_SZ, &dwType, NULL, &dwSize));

            if(SUCCEEDED(hr))
            {
                *ppszPath = CoTaskMemAlloc(dwSize+(lstrlenW(path)+1)*sizeof(WCHAR));
                if(!*ppszPath) hr = E_OUTOFMEMORY;
            }

            if(SUCCEEDED(hr))
            {
                lstrcpyW(*ppszPath, path);
                hr = HRESULT_FROM_WIN32(RegGetValueW(HKEY_LOCAL_MACHINE, registryPath, szRelativePath, RRF_RT_REG_SZ, &dwType, *ppszPath + lstrlenW(path), &dwSize));
            }
        }
    }

    TRACE("returning path: %s\n", debugstr_w(*ppszPath));
    return hr;
}

static HRESULT get_known_folder_path_by_id(
    REFKNOWNFOLDERID folderId,
    LPWSTR lpRegistryPath,
    DWORD dwFlags,
    LPWSTR *ppszPath)
{
    HRESULT hr;
    WCHAR sGuid[39];
    DWORD dwAttributes;

    TRACE("(%s, %s, 0x%08x, %p)\n", debugstr_guid(folderId), debugstr_w(lpRegistryPath), dwFlags, ppszPath);

    /* if this is registry-registered known folder, get path from registry */
    if(lpRegistryPath)
    {
        StringFromGUID2(folderId, sGuid, sizeof(sGuid)/sizeof(sGuid[0]));

        hr = get_known_folder_path(sGuid, lpRegistryPath, ppszPath);
    }
    /* in other case, use older way */
    else
        hr = SHGetKnownFolderPath( folderId, dwFlags, NULL, ppszPath );

    if (FAILED(hr)) return hr;

    /* check if known folder really exists */
    dwAttributes = GetFileAttributesW(*ppszPath);
    if(dwAttributes == INVALID_FILE_ATTRIBUTES || !(dwAttributes & FILE_ATTRIBUTE_DIRECTORY) )
    {
        TRACE("directory %s not found\n", debugstr_w(*ppszPath));
        CoTaskMemFree(*ppszPath);
        *ppszPath = NULL;
        hr = HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND);
    }

    return hr;
}

static HRESULT WINAPI knownfolder_GetPath(
    IKnownFolder *iface,
    DWORD dwFlags,
    LPWSTR *ppszPath)
{
    struct knownfolder *knownfolder = impl_from_IKnownFolder( iface );
    TRACE("(%p, 0x%08x, %p)\n", knownfolder, dwFlags, ppszPath);

    return get_known_folder_path_by_id(&knownfolder->id, knownfolder->registryPath, dwFlags, ppszPath);
}

static HRESULT WINAPI knownfolder_SetPath(
    IKnownFolder *iface,
    DWORD dwFlags,
    LPCWSTR pszPath)
{
    struct knownfolder *knownfolder = impl_from_IKnownFolder( iface );
    HRESULT hr = S_OK;

    TRACE("(%p, 0x%08x, %s)\n", knownfolder, dwFlags, debugstr_w(pszPath));

    /* check if the known folder is registered */
    if(!knownfolder->registryPath)
        hr = E_FAIL;

    if(SUCCEEDED(hr))
        hr = redirect_known_folder(&knownfolder->id, NULL, 0, pszPath, 0, NULL, NULL);

    return hr;
}

static HRESULT WINAPI knownfolder_GetIDList(
    IKnownFolder *iface,
    DWORD flags,
    PIDLIST_ABSOLUTE *ppidl)
{
    struct knownfolder *knownfolder = impl_from_IKnownFolder( iface );
    TRACE("(%p, 0x%08x, %p)\n", knownfolder, flags, ppidl);
    return SHGetKnownFolderIDList(&knownfolder->id, flags, NULL, ppidl);
}

static HRESULT WINAPI knownfolder_GetFolderType(
    IKnownFolder *iface,
    FOLDERTYPEID *pftid)
{
    FIXME("%p\n", pftid);
    return E_NOTIMPL;
}

static HRESULT WINAPI knownfolder_GetRedirectionCapabilities(
    IKnownFolder *iface,
    KF_REDIRECTION_CAPABILITIES *pCapabilities)
{
    FIXME("%p\n", pCapabilities);
    return E_NOTIMPL;
}

static HRESULT WINAPI knownfolder_GetFolderDefinition(
    IKnownFolder *iface,
    KNOWNFOLDER_DEFINITION *pKFD)
{
    struct knownfolder *knownfolder = impl_from_IKnownFolder( iface );
    HRESULT hr;
    DWORD dwSize;
    TRACE("(%p, %p)\n", knownfolder, pKFD);

    if(!pKFD) return E_INVALIDARG;

    ZeroMemory(pKFD, sizeof(*pKFD));

    hr = get_known_folder_category(knownfolder->registryPath, &pKFD->category);

    if(SUCCEEDED(hr))
        hr = HRESULT_FROM_WIN32(RegGetValueW(HKEY_LOCAL_MACHINE, knownfolder->registryPath, szName, RRF_RT_REG_SZ, NULL, NULL, &dwSize));

    if(SUCCEEDED(hr))
    {
        pKFD->pszName = CoTaskMemAlloc(dwSize);
        if(!pKFD->pszName) hr = E_OUTOFMEMORY;
    }

    if(SUCCEEDED(hr))
        hr = HRESULT_FROM_WIN32(RegGetValueW(HKEY_LOCAL_MACHINE, knownfolder->registryPath, szName, RRF_RT_REG_SZ, NULL, pKFD->pszName, &dwSize));

    return hr;
}

static const struct IKnownFolderVtbl knownfolder_vtbl =
{
    knownfolder_QueryInterface,
    knownfolder_AddRef,
    knownfolder_Release,
    knownfolder_GetId,
    knownfolder_GetCategory,
    knownfolder_GetShellItem,
    knownfolder_GetPath,
    knownfolder_SetPath,
    knownfolder_GetIDList,
    knownfolder_GetFolderType,
    knownfolder_GetRedirectionCapabilities,
    knownfolder_GetFolderDefinition
};

static HRESULT knownfolder_create( struct knownfolder **knownfolder )
{
    struct knownfolder *kf;

    kf = HeapAlloc( GetProcessHeap(), 0, sizeof(*kf) );
    if (!kf) return E_OUTOFMEMORY;

    kf->IKnownFolder_iface.lpVtbl = &knownfolder_vtbl;
    kf->refs = 1;
    memset( &kf->id, 0, sizeof(kf->id) );
    kf->registryPath = NULL;

    *knownfolder = kf;

    TRACE("returning iface %p\n", &kf->IKnownFolder_iface);
    return S_OK;
}

struct foldermanager
{
    IKnownFolderManager IKnownFolderManager_iface;
    LONG refs;
    UINT num_ids;
    KNOWNFOLDERID *ids;
};

static inline struct foldermanager *impl_from_IKnownFolderManager( IKnownFolderManager *iface )
{
    return CONTAINING_RECORD( iface, struct foldermanager, IKnownFolderManager_iface );
}

static ULONG WINAPI foldermanager_AddRef(
    IKnownFolderManager *iface )
{
    struct foldermanager *foldermanager = impl_from_IKnownFolderManager( iface );
    return InterlockedIncrement( &foldermanager->refs );
}

static ULONG WINAPI foldermanager_Release(
    IKnownFolderManager *iface )
{
    struct foldermanager *foldermanager = impl_from_IKnownFolderManager( iface );
    LONG refs = InterlockedDecrement( &foldermanager->refs );
    if (!refs)
    {
        TRACE("destroying %p\n", foldermanager);
        HeapFree( GetProcessHeap(), 0, foldermanager->ids );
        HeapFree( GetProcessHeap(), 0, foldermanager );
    }
    return refs;
}

static HRESULT WINAPI foldermanager_QueryInterface(
    IKnownFolderManager *iface,
    REFIID riid,
    void **ppv )
{
    struct foldermanager *This = impl_from_IKnownFolderManager( iface );

    TRACE("%p %s %p\n", This, debugstr_guid( riid ), ppv );

    if ( IsEqualGUID( riid, &IID_IKnownFolderManager ) ||
         IsEqualGUID( riid, &IID_IUnknown ) )
    {
        *ppv = iface;
    }
    else
    {
        FIXME("interface %s not implemented\n", debugstr_guid(riid));
        return E_NOINTERFACE;
    }
    IKnownFolderManager_AddRef( iface );
    return S_OK;
}

static HRESULT WINAPI foldermanager_FolderIdFromCsidl(
    IKnownFolderManager *iface,
    int nCsidl,
    KNOWNFOLDERID *pfid)
{
    TRACE("%d, %p\n", nCsidl, pfid);

    if (nCsidl >= sizeof(CSIDL_Data) / sizeof(CSIDL_Data[0]))
        return E_INVALIDARG;
    *pfid = *CSIDL_Data[nCsidl].id;
    return S_OK;
}

static HRESULT WINAPI foldermanager_FolderIdToCsidl(
    IKnownFolderManager *iface,
    REFKNOWNFOLDERID rfid,
    int *pnCsidl)
{
    int csidl;

    TRACE("%s, %p\n", debugstr_guid(rfid), pnCsidl);

    csidl = csidl_from_id( rfid );
    if (csidl == -1) return E_INVALIDARG;
    *pnCsidl = csidl;
    return S_OK;
}

static HRESULT WINAPI foldermanager_GetFolderIds(
    IKnownFolderManager *iface,
    KNOWNFOLDERID **ppKFId,
    UINT *pCount)
{
    struct foldermanager *fm = impl_from_IKnownFolderManager( iface );

    TRACE("%p, %p\n", ppKFId, pCount);

    *ppKFId = fm->ids;
    *pCount = fm->num_ids;
    return S_OK;
}

static BOOL is_knownfolder( struct foldermanager *fm, const KNOWNFOLDERID *id )
{
    UINT i;
    HRESULT hr;
    LPWSTR registryPath = NULL;
    HKEY hKey;

    /* TODO: move all entries from "CSIDL_Data" static array to registry known folder descriptions */
    for (i = 0; i < fm->num_ids; i++)
        if (IsEqualGUID( &fm->ids[i], id )) return TRUE;

    hr = get_known_folder_registry_path(id, NULL, &registryPath);
    if(SUCCEEDED(hr))
    {
        hr = HRESULT_FROM_WIN32(RegOpenKeyExW(HKEY_LOCAL_MACHINE, registryPath, 0, 0, &hKey));
        HeapFree(GetProcessHeap(), 0, registryPath);
    }

    if(SUCCEEDED(hr))
    {
        hr = S_OK;
        RegCloseKey(hKey);
    }

    return hr == S_OK;
}

static HRESULT WINAPI foldermanager_GetFolder(
    IKnownFolderManager *iface,
    REFKNOWNFOLDERID rfid,
    IKnownFolder **ppkf)
{
    struct foldermanager *fm = impl_from_IKnownFolderManager( iface );
    struct knownfolder *kf;
    HRESULT hr;

    TRACE("%s, %p\n", debugstr_guid(rfid), ppkf);

    if (!is_knownfolder( fm, rfid ))
    {
        WARN("unknown folder\n");
        return E_INVALIDARG;
    }
    hr = knownfolder_create( &kf );
    if (SUCCEEDED( hr ))
    {
        hr = knownfolder_set_id( kf, rfid );
        *ppkf = &kf->IKnownFolder_iface;
    }
    else
        *ppkf = NULL;

    return hr;
}

static HRESULT get_known_folder_wstr(const WCHAR *regpath, const WCHAR *value, WCHAR **out)
{
    DWORD size = 0;
    HRESULT hr;

    size = 0;
    hr = HRESULT_FROM_WIN32(RegGetValueW(HKEY_LOCAL_MACHINE, regpath, value, RRF_RT_REG_SZ, NULL, NULL, &size));
    if(FAILED(hr))
        return hr;

    *out = CoTaskMemAlloc(size);
    if(!*out)
        return E_OUTOFMEMORY;

    hr = HRESULT_FROM_WIN32(RegGetValueW(HKEY_LOCAL_MACHINE, regpath, value, RRF_RT_REG_SZ, NULL, *out, &size));
    if(FAILED(hr)){
        CoTaskMemFree(*out);
        *out = NULL;
    }

    return hr;
}

static HRESULT WINAPI foldermanager_GetFolderByName(
    IKnownFolderManager *iface,
    LPCWSTR pszCanonicalName,
    IKnownFolder **ppkf)
{
    struct foldermanager *fm = impl_from_IKnownFolderManager( iface );
    struct knownfolder *kf;
    BOOL found = FALSE;
    HRESULT hr;
    UINT i;

    TRACE( "%s, %p\n", debugstr_w(pszCanonicalName), ppkf );

    for (i = 0; i < fm->num_ids; i++)
    {
        WCHAR *path, *name;
        hr = get_known_folder_registry_path( &fm->ids[i], NULL, &path );
        if (FAILED( hr )) return hr;

        hr = get_known_folder_wstr( path, szName, &name );
        HeapFree( GetProcessHeap(), 0, path );
        if (FAILED( hr )) return hr;

        found = !strcmpiW( pszCanonicalName, name );
        CoTaskMemFree( name );
        if (found) break;
    }

    if (found)
    {
        hr = knownfolder_create( &kf );
        if (FAILED( hr )) return hr;

        hr = knownfolder_set_id( kf, &fm->ids[i] );
        if (FAILED( hr ))
        {
            IKnownFolder_Release( &kf->IKnownFolder_iface );
            return hr;
        }
        *ppkf = &kf->IKnownFolder_iface;
    }
    else
    {
        hr = HRESULT_FROM_WIN32( ERROR_FILE_NOT_FOUND );
        *ppkf = NULL;
    }

    return hr;
}

static HRESULT WINAPI foldermanager_RegisterFolder(
    IKnownFolderManager *iface,
    REFKNOWNFOLDERID rfid,
    KNOWNFOLDER_DEFINITION const *pKFD)
{
    HRESULT hr;
    HKEY hKey = NULL;
    DWORD dwDisp;
    LPWSTR registryPath = NULL;
    TRACE("(%p, %s, %p)\n", iface, debugstr_guid(rfid), pKFD);

    hr = get_known_folder_registry_path(rfid, NULL, &registryPath);
    TRACE("registry path: %s\n", debugstr_w(registryPath));

    if(SUCCEEDED(hr))
        hr = HRESULT_FROM_WIN32(RegCreateKeyExW(HKEY_LOCAL_MACHINE, registryPath, 0, NULL, 0, KEY_WRITE, 0, &hKey, &dwDisp));

    if(SUCCEEDED(hr))
    {
        if(dwDisp == REG_OPENED_EXISTING_KEY)
            hr = E_FAIL;

        if(SUCCEEDED(hr))
            hr = HRESULT_FROM_WIN32(RegSetValueExW(hKey, szCategory, 0, REG_DWORD, (LPBYTE)&pKFD->category, sizeof(pKFD->category)));

        if(SUCCEEDED(hr))
            hr = HRESULT_FROM_WIN32(RegSetValueExW(hKey, szName, 0, REG_SZ, (LPBYTE)pKFD->pszName, (lstrlenW(pKFD->pszName)+1)*sizeof(WCHAR) ));

        if(SUCCEEDED(hr) && !IsEqualGUID(&pKFD->fidParent, &GUID_NULL))
        {
            WCHAR sParentGuid[39];
            StringFromGUID2(&pKFD->fidParent, sParentGuid, sizeof(sParentGuid)/sizeof(sParentGuid[0]));

            /* this known folder has parent folder */
            hr = HRESULT_FROM_WIN32(RegSetValueExW(hKey, szParentFolder, 0, REG_SZ, (LPBYTE)sParentGuid, sizeof(sParentGuid)));
        }

        if(SUCCEEDED(hr) && pKFD->category != KF_CATEGORY_VIRTUAL)
        {
            if(!pKFD->pszRelativePath)
                hr = E_INVALIDARG;

            if(SUCCEEDED(hr))
                hr = HRESULT_FROM_WIN32(RegSetValueExW(hKey, szRelativePath, 0, REG_SZ, (LPBYTE)pKFD->pszRelativePath, (lstrlenW(pKFD->pszRelativePath)+1)*sizeof(WCHAR) ));
        }

        RegCloseKey(hKey);

        if(FAILED(hr))
            SHDeleteKeyW(HKEY_LOCAL_MACHINE, registryPath);
    }

    HeapFree(GetProcessHeap(), 0, registryPath);
    return hr;
}

static HRESULT WINAPI foldermanager_UnregisterFolder(
    IKnownFolderManager *iface,
    REFKNOWNFOLDERID rfid)
{
    HRESULT hr;
    LPWSTR registryPath = NULL;
    TRACE("(%p, %s)\n", iface, debugstr_guid(rfid));

    hr = get_known_folder_registry_path(rfid, NULL, &registryPath);

    if(SUCCEEDED(hr))
        hr = HRESULT_FROM_WIN32(SHDeleteKeyW(HKEY_LOCAL_MACHINE, registryPath));

    HeapFree(GetProcessHeap(), 0, registryPath);
    return hr;
}

static HRESULT WINAPI foldermanager_FindFolderFromPath(
    IKnownFolderManager *iface,
    LPCWSTR pszPath,
    FFFP_MODE mode,
    IKnownFolder **ppkf)
{
    FIXME("%s, 0x%08x, %p\n", debugstr_w(pszPath), mode, ppkf);
    return E_NOTIMPL;
}

static HRESULT WINAPI foldermanager_FindFolderFromIDList(
    IKnownFolderManager *iface,
    PCIDLIST_ABSOLUTE pidl,
    IKnownFolder **ppkf)
{
    FIXME("%p, %p\n", pidl, ppkf);
    return E_NOTIMPL;
}

static HRESULT WINAPI foldermanager_Redirect(
    IKnownFolderManager *iface,
    REFKNOWNFOLDERID rfid,
    HWND hwnd,
    KF_REDIRECT_FLAGS flags,
    LPCWSTR pszTargetPath,
    UINT cFolders,
    KNOWNFOLDERID const *pExclusion,
    LPWSTR *ppszError)
{
    return redirect_known_folder(rfid, hwnd, flags, pszTargetPath, cFolders, pExclusion, ppszError);
}

static const struct IKnownFolderManagerVtbl foldermanager_vtbl =
{
    foldermanager_QueryInterface,
    foldermanager_AddRef,
    foldermanager_Release,
    foldermanager_FolderIdFromCsidl,
    foldermanager_FolderIdToCsidl,
    foldermanager_GetFolderIds,
    foldermanager_GetFolder,
    foldermanager_GetFolderByName,
    foldermanager_RegisterFolder,
    foldermanager_UnregisterFolder,
    foldermanager_FindFolderFromPath,
    foldermanager_FindFolderFromIDList,
    foldermanager_Redirect
};

static HRESULT foldermanager_create( void **ppv )
{
    UINT i, j;
    struct foldermanager *fm;

    fm = HeapAlloc( GetProcessHeap(), 0, sizeof(*fm) );
    if (!fm) return E_OUTOFMEMORY;

    fm->IKnownFolderManager_iface.lpVtbl = &foldermanager_vtbl;
    fm->refs = 1;
    fm->num_ids = 0;

    for (i = 0; i < sizeof(CSIDL_Data) / sizeof(CSIDL_Data[0]); i++)
    {
        if (!IsEqualGUID( CSIDL_Data[i].id, &GUID_NULL )) fm->num_ids++;
    }
    fm->ids = HeapAlloc( GetProcessHeap(), 0, fm->num_ids * sizeof(KNOWNFOLDERID) );
    if (!fm->ids)
    {
        HeapFree( GetProcessHeap(), 0, fm );
        return E_OUTOFMEMORY;
    }
    for (i = j = 0; i < sizeof(CSIDL_Data) / sizeof(CSIDL_Data[0]); i++)
    {
        if (!IsEqualGUID( CSIDL_Data[i].id, &GUID_NULL ))
        {
            fm->ids[j] = *CSIDL_Data[i].id;
            j++;
        }
    }
    TRACE("found %u known folders\n", fm->num_ids);
    *ppv = &fm->IKnownFolderManager_iface;

    TRACE("returning iface %p\n", *ppv);
    return S_OK;
}

HRESULT WINAPI KnownFolderManager_Constructor( IUnknown *punk, REFIID riid, void **ppv )
{
    TRACE("%p, %s, %p\n", punk, debugstr_guid(riid), ppv);

    if (!ppv)
        return E_POINTER;
    if (punk)
        return CLASS_E_NOAGGREGATION;

    return foldermanager_create( ppv );
}

static int convertWinVistaFolderToWinXPFolder(KNOWNFOLDERID *id){
	if(IsEqualGUID( id , &FOLDERID_Windows ))
		return CSIDL_WINDOWS;			
	if(IsEqualGUID( id , &FOLDERID_Videos ))
		return CSIDL_MYVIDEO;			
	if(IsEqualGUID( id , &FOLDERID_Templates ))
		return CSIDL_TEMPLATES;			
	if(IsEqualGUID( id , &FOLDERID_SystemX86 ))
		return CSIDL_SYSTEMX86;			
	if(IsEqualGUID( id , &FOLDERID_System ))
		return CSIDL_SYSTEM;		
	if(IsEqualGUID( id , &FOLDERID_Startup ))
		return CSIDL_STARTUP;			
	if(IsEqualGUID( id , &FOLDERID_StartMenu ))
		return CSIDL_STARTMENU;			
	if(IsEqualGUID( id , &FOLDERID_SendTo ))
		return CSIDL_SENDTO;			
	if(IsEqualGUID( id , &FOLDERID_RoamingAppData ))
		return CSIDL_APPDATA;			
	if(IsEqualGUID( id , &FOLDERID_ResourceDir ))
		return CSIDL_RESOURCES;			
	if(IsEqualGUID( id , &FOLDERID_RecycleBinFolder ))
		return CSIDL_BITBUCKET;			
	if(IsEqualGUID( id , &FOLDERID_Recent ))
		return CSIDL_RECENT;			
	if(IsEqualGUID( id , &FOLDERID_PublicVideos ))
		return CSIDL_COMMON_VIDEO;			
	if(IsEqualGUID( id , &FOLDERID_PublicPictures ))
		return CSIDL_COMMON_PICTURES;			
	if(IsEqualGUID( id , &FOLDERID_PublicMusic ))
		return CSIDL_COMMON_MUSIC;		
	if(IsEqualGUID( id , &FOLDERID_PublicDocuments ))
		return CSIDL_COMMON_DOCUMENTS;			
	if(IsEqualGUID( id , &FOLDERID_PublicDesktop ))
		return CSIDL_COMMON_DESKTOPDIRECTORY;			
	if(IsEqualGUID( id , &FOLDERID_Programs ))
		return CSIDL_PROGRAMS;		
	if(IsEqualGUID( id , &FOLDERID_ProgramFilesCommonX86 ))
		return CSIDL_PROGRAM_FILES_COMMONX86;			
	if(IsEqualGUID( id , &FOLDERID_ProgramFilesCommon ))
		return CSIDL_PROGRAM_FILES_COMMON;			
	if(IsEqualGUID( id , &FOLDERID_ProgramFilesCommonX64 ))
		return CSIDL_PROGRAM_FILES_COMMON;			
	if(IsEqualGUID( id , &FOLDERID_ProgramFilesX86 ))
		return CSIDL_PROGRAM_FILESX86;			
	if(IsEqualGUID( id , &FOLDERID_ProgramFilesX64 ))
		return CSIDL_PROGRAM_FILES;			
	if(IsEqualGUID( id , &FOLDERID_ProgramFiles ))
		return CSIDL_PROGRAM_FILES;		
	if(IsEqualGUID( id , &FOLDERID_Profile ))
		return CSIDL_PROFILE;				
	if(IsEqualGUID( id , &FOLDERID_PrintHood ))
		return CSIDL_PRINTHOOD;			
	if(IsEqualGUID( id , &FOLDERID_PrintersFolder ))
		return CSIDL_PRINTERS;		
	if(IsEqualGUID( id , &FOLDERID_Pictures ))
		return CSIDL_MYPICTURES;		
	if(IsEqualGUID( id , &FOLDERID_NetworkFolder ))
		return CSIDL_NETWORK;			
	if(IsEqualGUID( id , &FOLDERID_NetHood ))
		return CSIDL_NETHOOD;			
	if(IsEqualGUID( id , &FOLDERID_Music ))
		return CSIDL_MYMUSIC;			
	if(IsEqualGUID( id , &FOLDERID_LocalizedResourcesDir ))
		return CSIDL_RESOURCES_LOCALIZED;		
	if(IsEqualGUID( id , &FOLDERID_LocalAppDataLow ))
		return CSIDL_LOCAL_APPDATA;			
	if(IsEqualGUID( id , &FOLDERID_InternetCache ))
		return CSIDL_INTERNET_CACHE;	
	if(IsEqualGUID( id , &FOLDERID_InternetFolder ))
		return CSIDL_INTERNET;		
	if(IsEqualGUID( id , &FOLDERID_History ))
		return CSIDL_HISTORY;			
	if(IsEqualGUID( id , &FOLDERID_Fonts ))
		return CSIDL_FONTS;		
	if(IsEqualGUID( id , &FOLDERID_Favorites ))
		return CSIDL_FAVORITES;		
	if(IsEqualGUID( id , &FOLDERID_Documents ))
		return CSIDL_MYDOCUMENTS;			
	if(IsEqualGUID( id , &FOLDERID_ControlPanelFolder ))
		return CSIDL_CONTROLS;		
	if(IsEqualGUID( id , &FOLDERID_Desktop ))
		return CSIDL_DESKTOP;	
	if(IsEqualGUID( id , &FOLDERID_Cookies ))
		return CSIDL_COOKIES;	
	if(IsEqualGUID( id , &FOLDERID_CommonPrograms ))
		return CSIDL_COMMON_PROGRAMS;
	if(IsEqualGUID( id , &FOLDERID_CommonStartMenu ))
		return CSIDL_COMMON_STARTMENU;	
	if(IsEqualGUID( id , &FOLDERID_CommonStartup ))
		return CSIDL_COMMON_STARTUP;	
	if(IsEqualGUID( id , &FOLDERID_CommonTemplates ))
		return CSIDL_COMMON_TEMPLATES;
	if(IsEqualGUID( id , &FOLDERID_ComputerFolder ))
		return CSIDL_DRIVES;
	if(IsEqualGUID( id , &FOLDERID_ConnectionsFolder ))
		return CSIDL_CONNECTIONS;		
	if(IsEqualGUID( id , &FOLDERID_CommonOEMLinks ))
		return CSIDL_COMMON_OEM_LINKS;	
	if(IsEqualGUID( id , &FOLDERID_CDBurning ))
		return CSIDL_CDBURN_AREA;
	if(IsEqualGUID( id , &FOLDERID_CommonAdminTools ))
		return CSIDL_COMMON_ADMINTOOLS;	
	if(IsEqualGUID( id , &FOLDERID_ProgramData ))
		return CSIDL_COMMON_APPDATA;
	if(IsEqualGUID( id , &FOLDERID_LocalAppData ))
		return CSIDL_LOCAL_APPDATA;
	if(IsEqualGUID( id , &FOLDERID_UserProgramFiles ))
		return CSIDL_LOCAL_APPDATA;
	if(IsEqualGUID( id , &FOLDERID_VideosLibrary ))
		return CSIDL_COMMON_VIDEO;
	if(IsEqualGUID( id , &FOLDERID_UsersLibraries ))
		return CSIDL_PROFILE;
	if(IsEqualGUID( id , &FOLDERID_UserProgramFilesCommon ))
		return CSIDL_LOCAL_APPDATA;
	if(IsEqualGUID( id , &FOLDERID_SampleVideos ))
		return CSIDL_MYVIDEO;
	if(IsEqualGUID( id , &FOLDERID_PicturesLibrary ))
		return CSIDL_MYPICTURES;
	if(IsEqualGUID( id , &FOLDERID_OriginalImages ))
		return CSIDL_MYPICTURES;
	if(IsEqualGUID( id , &FOLDERID_MusicLibrary ))
		return CSIDL_MYMUSIC;
	if(IsEqualGUID( id , &FOLDERID_DocumentsLibrary ))
		return CSIDL_PERSONAL;	
	if(IsEqualGUID( id , &FOLDERID_Downloads ))
		return CSIDL_PERSONAL;	
	if(IsEqualGUID( id , &FOLDERID_AdminTools ))
		return CSIDL_ADMINTOOLS;
	if(IsEqualGUID( id , &FOLDERID_AddNewPrograms ))
		return CSIDL_Type_Disallowed;
	if(IsEqualGUID( id , &FOLDERID_AppUpdates ))
		return CSIDL_Type_Disallowed;	
	if(IsEqualGUID( id , &FOLDERID_ChangeRemovePrograms ))
		return CSIDL_Type_Disallowed;		
	if(IsEqualGUID( id , &FOLDERID_ComputerFolder ))
		return CSIDL_Type_Disallowed;	
	if(IsEqualGUID( id , &FOLDERID_ConflictFolder ))
		return CSIDL_Type_Disallowed;		
	return 0;
}

static int csidl_from_id( const KNOWNFOLDERID *id )
{
    int i;
	int special = 0;
    for (i = 0; i < sizeof(CSIDL_Data) / sizeof(CSIDL_Data[0]); i++)
	{
		special = convertWinVistaFolderToWinXPFolder(id);
		if(special)
			return special;			
        if (IsEqualGUID( CSIDL_Data[i].id, id )) 
			return i;		
	}
    return -1;
}

HRESULT 
WINAPI 
SHGetKnownFolderIDList(
	REFKNOWNFOLDERID rfid, 
	DWORD flags, 
	HANDLE token, 
	PIDLIST_ABSOLUTE *pidl
)
{
    TRACE("%s, 0x%08x, %p, %p\n", debugstr_guid(rfid), flags, token, pidl);

    if (!pidl)
        return E_INVALIDARG;

    if (flags)
        FIXME("unsupported flags: 0x%08x\n", flags);

    if (token)
        FIXME("user token is not used.\n");

    *pidl = NULL;
    if (IsEqualIID(rfid, &FOLDERID_Desktop))
        *pidl = _ILCreateDesktop();
    else if (IsEqualIID(rfid, &FOLDERID_RecycleBinFolder))
        *pidl = _ILCreateBitBucket();
    else if (IsEqualIID(rfid, &FOLDERID_ComputerFolder))
        *pidl = _ILCreateMyComputer();
    else if (IsEqualIID(rfid, &FOLDERID_PrintersFolder))
        *pidl = _ILCreatePrinters();
    else if (IsEqualIID(rfid, &FOLDERID_ControlPanelFolder))
        *pidl = _ILCreateControlPanel();
    else if (IsEqualIID(rfid, &FOLDERID_NetworkFolder))
        *pidl = _ILCreateNetwork();
    else if (IsEqualIID(rfid, &FOLDERID_Documents))
        *pidl = _ILCreateMyDocuments();
    else
    {
        DWORD attributes = 0;
        WCHAR *pathW;
        HRESULT hr;

        hr = SHGetKnownFolderPath(rfid, flags, token, &pathW);
        if (FAILED(hr))
            return hr;

        hr = SHILCreateFromPath(pathW, pidl, &attributes);
        CoTaskMemFree(pathW);
        return hr;
    }

    return *pidl ? S_OK : E_FAIL;
}

HRESULT 
WINAPI 
SHGetKnownFolderItem(
	REFKNOWNFOLDERID rfid, 
	KNOWN_FOLDER_FLAG flags, 
	HANDLE hToken,
    REFIID riid, 
	void **ppv
)
{
    PIDLIST_ABSOLUTE pidl;
    HRESULT hr;

    TRACE("%s, 0x%08x, %p, %s, %p\n", debugstr_guid(rfid), flags, hToken, debugstr_guid(riid), ppv);

    hr = SHGetKnownFolderIDList(rfid, flags, hToken, &pidl);
    if (FAILED(hr))
    {
        *ppv = NULL;
        return hr;
    }

    hr = SHCreateItemFromIDList(pidl, riid, ppv);
    CoTaskMemFree(pidl);
    return hr;
}

HRESULT 
WINAPI 
SHSetKnownFolderPath(
  _In_  REFKNOWNFOLDERID rfid,
  _In_  DWORD dwFlags,
  _In_  HANDLE hToken,
  _In_  PCWSTR pszPath
)
{
    int index = csidl_from_id( rfid );
	
	 
    if (index < 0)
        return HRESULT_FROM_WIN32( ERROR_FILE_NOT_FOUND );	
	return SHSetFolderPathW(index, hToken, dwFlags, (LPCSTR)pszPath);
}

/*************************************************************************
 * SHGetKnownFolderPath           [SHELL32.@]
 */
HRESULT 
WINAPI 
SHGetKnownFolderPath(
	REFKNOWNFOLDERID rfid, 
	DWORD dwflags, 
	HANDLE token, 
	PWSTR *path
)
{
    wchar_t folder[512+1] = {0};
    int index = csidl_from_id( rfid );
	DWORD flags = SHGFP_TYPE_CURRENT;
	DWORD Size;
	 
    DbgPrint("SHGetKnownFolderPath REFKNOWNFOLDERID GUID = {" GUID_FORMAT "}\n",  GUID_ARG(rfid));	 
	 
    if (index < 0)
        return HRESULT_FROM_WIN32( ERROR_FILE_NOT_FOUND );
	if( dwflags & KF_FLAG_DEFAULT_PATH)
		flags = SHGFP_TYPE_DEFAULT;
	if (dwflags & KF_FLAG_CREATE)
        index |= CSIDL_FLAG_CREATE;

    if (dwflags & KF_FLAG_CREATE)
        index |= CSIDL_FLAG_CREATE;

    if (dwflags & KF_FLAG_DONT_VERIFY)
        index |= CSIDL_FLAG_DONT_VERIFY;

    if (dwflags & KF_FLAG_NO_ALIAS)
        index |= CSIDL_FLAG_NO_ALIAS;

    if (dwflags & KF_FLAG_INIT)
        index |= CSIDL_FLAG_PER_USER_INIT;

    if (dwflags & ~(KF_FLAG_CREATE|KF_FLAG_DONT_VERIFY|KF_FLAG_NO_ALIAS|KF_FLAG_INIT))
    {
        FIXME("SHGetKnownFolderPath::dwflags 0x%08x not supported\n", dwflags);
        return E_INVALIDARG;
    }
	
	//FOLDERID_QuickLaunch
	//FOLDERID_SampleMusic
	//FOLDERID_SamplePictures
	//FOLDERID_SampleVideos
	//FOLDERID_SavedGames
	//DbgPrint("SHGetKnownFolderPath the CSLD is %d\n",index);
	DbgPrint("SHGetKnownFolderPath:: index is: %d\n", index);
	SHGetFolderPathW(NULL, index, token, flags, folder);	
	DbgPrint("SHGetKnownFolderPath: Folder is: %s\n",folder);
	
	if(IsEqualGUID( rfid , &FOLDERID_Public ))
	{
		Size = ARRAY_SIZE(folder);
		GetAllUsersProfileDirectoryW(*path, &Size);
		// ExpandEnvironmentStringsW(L"%ALLUSERSPROFILE%", *path, MAX_PATH);
	}else 
	if(IsEqualGUID( rfid , &FOLDERID_QuickLaunch )){
		ExpandEnvironmentStringsW(L"%APPDATA%", *path , MAX_PATH);
		strcatW(*path, L"Microsoft\\Internet Explorer\\Quick");
	}else if(IsEqualGUID( rfid , &FOLDERID_UserProfiles )){
		GetProfilesDirectoryW(*path, NULL);
	}else if(IsEqualGUID( rfid , &FOLDERID_Downloads )){
		return HRESULT_FROM_WIN32( ERROR_FILE_NOT_FOUND );
	}else{
		*path = folder;
	}

    return S_OK;
}

/*************************************************************************
 * SHGetFolderPathEx           [SHELL32.@]
 */
HRESULT 
WINAPI 
SHGetFolderPathEx(
	REFKNOWNFOLDERID rfid, 
	DWORD flags, 
	HANDLE token, 
	LPWSTR path, 
	DWORD len
)
{
    HRESULT hr;
    WCHAR *buffer;

    TRACE("%s, 0x%08x, %p, %p, %u\n", debugstr_guid(rfid), flags, token, path, len);

    if (!path || !len) return E_INVALIDARG;

    hr = SHGetKnownFolderPath( rfid, flags, token, &buffer );
    if (SUCCEEDED( hr ))
    {
        if (strlenW( buffer ) + 1 > len)
        {
            CoTaskMemFree( buffer );
            return HRESULT_FROM_WIN32( ERROR_INSUFFICIENT_BUFFER );
        }
        strcpyW( path, buffer );
        CoTaskMemFree( buffer );
    }
    return hr;
}