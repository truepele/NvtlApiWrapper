/**
*
* Copyright 2008 Novatel Wireless Inc.
*
*/

#ifndef _SDK_WRAPPER_H
#define _SDK_WRAPPER_H

#include "platform_inc.h"
#include "NvtlApiDefinitions.h"

#if defined(_NVTL_WINDOWS_)
#include <windows.h>
#include <stdio.h>
#include <wtypes.h>

#define LOAD_OBJECT(x)		LoadLibraryA(x)
#define UNLOAD_OBJECT		FreeLibrary
#define LOAD_PROC			GetProcAddress
#define OBJECT_TYPE			HMODULE

#define BASESDK_OBJECT_NAME		"NvtlSdk.dll"
#define Activation_OBJECT_NAME	"NvtlActv.dll"
#define Connection_OBJECT_NAME	"NvtlConn.dll"
#define Diagnostics_OBJECT_NAME	"NvtlDiag.dll"
#define Gps_OBJECT_NAME	        "NvtlGps.dll"
#define FileManager_OBJECT_NAME	"NvtlFile.dll"
#define SmsEncoder_OBJECT_NAME	"NvtlEnc.dll"
#define Gobi_OBJECT_NAME		"NvtlGobi.dll"

#define LOAD_FUNCTION_PTR( funcPtr, funcType, funcName , handle ) \
    if( ! funcPtr ) { \
        funcPtr = (funcType)GetProcAddress( handle, funcName ); \
        if( ! funcPtr ) { \
            return 1; \
		        } \
	    }

#elif DEFINED_MAC

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dlfcn.h>
#include <time.h>

#define LOAD_OBJECT(x)		dlopen( x, RTLD_LAZY )
#define UNLOAD_OBJECT		dlclose
#define LOAD_PROC			dlsym
#define OBJECT_TYPE			void*

#define BASESDK_OBJECT_NAME         "@executable_path/../Frameworks/NvtlSdk.framework/NvtlSdk"
//#define BASESDK_OBJECT_NAME		"NvtlSdk.dylib"
#define Activation_OBJECT_NAME         "@executable_path/../Frameworks/NvtlActivation.framework/NvtlActivation"
//#define Activation_OBJECT_NAME  "NvtlActivation.dylib"
#define Connection_OBJECT_NAME         "@executable_path/../Frameworks/NvtlConnection.framework/NvtlConnection"
//#define Connection_OBJECT_NAME  "NvtlConnection.dylib"
#define Diagnostics_OBJECT_NAME         "@executable_path/../Frameworks/NvtlDiagnostics.framework/NvtlDiagnostics"
//#define Diagnostics_OBJECT_NAME  "NvtlDiagnostics.dylib"
#define Gps_OBJECT_NAME         "@executable_path/../Frameworks/NvtlGps.framework/NvtlGps"
//#define Gps_OBJECT_NAME         "NvtlGps.dylib"
#define FileManager_OBJECT_NAME         "@executable_path/../Frameworks/NvtlFileManager.framework/NvtlFileManager"
//#define FileManager_OBJECT_NAME  "NvtlFileManager.dylib"
#define SmsEncoder_OBJECT_NAME         "@executable_path/../Frameworks/NvtlSms.framework/NvtlSms"
//#define SmsEncoder_OBJECT_NAME  "NvtlSms.dylib"
#define Gobi_OBJECT_NAME         "@executable_path/../Frameworks/NvtlGobi.framework/NvtlGobi"
//#define Gobi_OBJECT_NAME  "NvtlGobi.dylib"

#ifndef MAX_PATH
#define MAX_PATH 255
#endif

#define LOAD_FUNCTION_PTR( funcPtr, funcType, funcName , handle ) \
    if( ! funcPtr ) { \
        funcPtr = (funcType)dlsym( handle, funcName ); \
        if( ! funcPtr ) { \
            return -1; \
		        } \
	    }


#else

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dlfcn.h>
#include <time.h>

#define LOAD_OBJECT(x)		dlopen( x, RTLD_LAZY)
#define UNLOAD_OBJECT		dlclose
#define LOAD_PROC			dlsym
#define OBJECT_TYPE			void*

#define BASESDK_OBJECT_NAME		"nvtlsdk.so"
#define Activation_OBJECT_NAME  "nvtlactv.so"
#define Connection_OBJECT_NAME  "nvtlconn.so"
#define Diagnostics_OBJECT_NAME "nvtldiag.so"
#define Gps_OBJECT_NAME         "nvtlgps.so"
#define FileManager_OBJECT_NAME "nvtlfile.so"
#define SmsEncoder_OBJECT_NAME  "nvtlenc.so"
#define Gobi_OBJECT_NAME		"nvtlgobi.so"

#define LOAD_FUNCTION_PTR( funcPtr, funcType, funcName , handle ) \
    if( ! funcPtr ) { \
        funcPtr = (funcType)dlsym( handle, funcName ); \
        if( ! funcPtr ) { \
            return -1; \
		        } \
	    }

#endif

namespace NvtlApiWrapper
{
	typedef SdkHandle(NOVATEL_CALL *Func_NvtlCommon_CreateSession)();
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_ReleaseSession)(SdkHandle);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetSdkVersion)(char* buffer, unsigned short buffer_len);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_SetSdkMode)(NvtlSdkModeType sdk_mode, const char* szAccessKey);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetDeviceInfo)(SdkHandle, DeviceInfoStruct^ pDevInfo);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetNetworkInfo)(SdkHandle, NetworkInfoStruct^ pNetworkInfo);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_ReadContact)(SdkHandle, short index, ContactInfoStruct^ pContact);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_ReadMultipleContacts)(SdkHandle session, unsigned short start_index, unsigned short num_to_read, ContactInfoStruct^ pContact, unsigned short* pRead);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_WriteContact)(SdkHandle, ContactInfoStruct^ pContact);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetContactSizeDetails)(SdkHandle, ContactSizeInfoStruct^ pContactDetails);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetPowerMode)(SdkHandle session, unsigned short* mode, unsigned char* disableMask);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_SetPowerMode)(SdkHandle session, unsigned short val);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_RadioState)(SdkHandle session, PropertyAction bPropAction, unsigned short* state);

	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_Reset)(SdkHandle session);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_RegisterEventCallback)(SdkHandle session, NvtlEventCallback% cb);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_UnregisterEventCallback)(SdkHandle session, NvtlEventCallback% cb);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_AttachDevice)(SdkHandle session, DeviceDetail^ pDeviceDetail);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_DetachDevice)(SdkHandle session);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_RefreshDeviceInfo)(SdkHandle session);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetAvailableDevices)(SdkHandle session, DeviceDetail^ pDevList, unsigned long* dev_list_size);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_SetDeviceAccessKey)(SdkHandle session, char *accessKey);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_ConfigureLogging)(const char* filename, SdkLogLevelType logLevel, SdkLogOutputType output);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_UnlockDevice)(SdkHandle session, unsigned char lockType, char* lockCode);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_SetAutoLock)(SdkHandle session, unsigned char lockOn, char* lockCode);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetLockStatus)(SdkHandle session, long* lockStatus, unsigned char* isAutoLockOn);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_ChangeLockCode)(SdkHandle session, char* szOldCode, char* szNewCode);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_NetworkPreference)(SdkHandle session, PropertyAction bPropAction, unsigned char* pref);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_NovaSpeedEnabled)(SdkHandle session, PropertyAction bSet, unsigned char *NSEnabled);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetTemperature)(SdkHandle session, unsigned short* temp);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetLifetimeTimer)(SdkHandle session, unsigned long* count);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetDisplaySpeed)(SdkHandle session, unsigned char nTheoretical, double* speed);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_AutoInstallEnabled)(SdkHandle session, PropertyAction bSet, unsigned char* bEnabled);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_InternalMassStorageEnabled)(SdkHandle session, PropertyAction bSet, unsigned char* bEnabled);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_RestoreToFactoryDefaults)(SdkHandle session, char* spcCode);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_RestoreToFactoryDefaultsBasic)(SdkHandle session);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_IsLPMSupported)(SdkHandle session, unsigned char* supported);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetRefurbInfo)(SdkHandle session, unsigned char* status, unsigned long* date, char* provider, unsigned short provider_len);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_SetSystemPreferredHybridMode)(SdkHandle session, PropertyAction bSet, unsigned short newPrefMode, unsigned short newHybridMode, unsigned short* oldPrefMode, unsigned short* oldHybridMode);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_ReadSmsMsg)(SdkHandle hClient, unsigned short index, SmsMessageStruct^ msg);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_SendSmsMsg)(SdkHandle hClient, SmsMessageStruct^ msg);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_DeleteSmsMsg)(SdkHandle hClient, unsigned short index);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetSmsList)(SdkHandle hClient, SmsStateType eSmsType, SmsMessageInfo^ info_array, unsigned short array_size, unsigned short* msg_count);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetDataCounters)(SdkHandle session, unsigned long* dataTx, unsigned long* dataRx);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetBatteryState)(SdkHandle session, unsigned short* state, unsigned short* chargePct);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlCommon_GetManufacturer)(SdkHandle session, char* buffer, unsigned short* buffer_len);

	typedef unsigned short (NOVATEL_CALL *Func_NvtlEvdo_BandPreference)(SdkHandle session, PropertyAction bPropAction, unsigned char nam, BandPreferenceType* pref);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlEvdo_GetDateTime)(SdkHandle session, NvtlTimeStruct^ ts);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlEvdo_GetEriInfo)(SdkHandle session, EriInfoStruct^ eriInfo);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlEvdo_RoamPreference)(SdkHandle session, PropertyAction bPropAction, unsigned char nam, RoamPreferenceType* pref);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlEvdo_IntlRoamPreference)(SdkHandle session, PropertyAction bPropAction, unsigned char* pref);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlEvdo_MicroSDControl)(SdkHandle session, PropertyAction bPropAction, unsigned char* enabled);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlEvdo_LedControl)(SdkHandle session, PropertyAction bPropAction, unsigned char* enabled);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlEvdo_GetMobileId)(SdkHandle session, char* buffer, unsigned short* buffer_len);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlEvdo_GetMeid)(SdkHandle session, char* buffer, unsigned short* buffer_len);
	//typedef unsigned short ( NOVATEL_CALL *Func_NvtlEvdo_GetMIPError)( SdkHandle session, unsigned long* error );
	typedef unsigned short (NOVATEL_CALL *Func_NvtlEvdo_GetEsnAsDecimal)(SdkHandle session, char* decESN, unsigned short* decEsn_len);

	//GSM functions
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_SMSC)(SdkHandle hClient, PropertyAction getOrSet, char* buffer, unsigned short* buffer_len);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_GetImsi)(SdkHandle hClient, char* buffer, unsigned short* buffer_len);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_GetIccid)(SdkHandle hClient, char* buffer, unsigned short* buffer_len);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_GetNetworkMCCMNC)(SdkHandle hClient, char* buffer, unsigned short* buffer_len);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_GetNetworkOperator)(SdkHandle hClient, char* buffer, unsigned short* buffer_len);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_SetNetworkOperator)(SdkHandle hClient, unsigned short mode, unsigned short format, unsigned short accessTech, char* szOper);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_GetNetworkOperatorList)(SdkHandle hClient, char* buffer, unsigned short* buffer_len);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_SendATCommand)(SdkHandle hClient, char* command, char* prompt, char* response, unsigned long response_len);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_Band)(SdkHandle hClient, PropertyAction bPropAction, unsigned long* band);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_SendStoredSms)(SdkHandle hClient, unsigned short index);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_SetSmsStorage)(SdkHandle hClient, const char* name);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_GetContactStorage)(SdkHandle hClient, unsigned short* numRecords, unsigned short* maxRecords, char* buffer, unsigned short* buffer_len);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_SetContactStorage)(SdkHandle hClient, char* szStorageName);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_WriteSmsMsg)(SdkHandle hClient, SmsMessageStruct^ msg, unsigned short* index);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_IsMsgMemoryFull)(SdkHandle hClient, unsigned char* full);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_GetEnsInfo)(SdkHandle hClient, unsigned long* ensMode);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_IsManualNetworkSelected)(SdkHandle session, unsigned char* bManual);
	typedef unsigned short (NOVATEL_CALL *Func_NvtlGsm_DomainAttach)(SdkHandle session, PropertyAction bPropAction, unsigned short* state);


	public ref class SdkWrapper
	{
	public:
		SdkWrapper();
		virtual ~SdkWrapper();

		bool		IsLoaded();

		unsigned short GetSdkVersion(char* buffer, unsigned short buffer_len);
		unsigned short CreateSession();
		bool           HasValidSession();
		unsigned short SetSdkMode(NvtlSdkModeType sdk_mode, const char* szAccessKey);
		unsigned short ReleaseSession();
		unsigned short RefreshDeviceInfo();
		unsigned short AttachDevice(DeviceDetail^ pDeviceDetail);
		unsigned short DetachDevice();
		unsigned short GetAvailableDevices(DeviceDetail^ pDevList, unsigned long* dev_list_size);
		unsigned short SetDeviceAccessKey(char *accessKey);
		unsigned short RegisterEventCallback(NvtlEventCallback cb);
		unsigned short UnregisterEventCallback(NvtlEventCallback cb);
		unsigned short GetNetworkInfo(NetworkInfoStruct^ pNetworkInfo);
		unsigned short GetDeviceInfo(DeviceInfoStruct^ pDeviceInfo);
		unsigned short ReadContact(short index, ContactInfoStruct^ pContact);
		unsigned short ReadMultipleContacts(unsigned short start_index, unsigned short num_to_read, ContactInfoStruct^ pContact, unsigned short* pRead);
		unsigned short WriteContact(ContactInfoStruct^ pContact);
		unsigned short GetContactSizeDetails(ContactSizeInfoStruct^ pContactDetails);
		unsigned short GetPowerMode(unsigned short* mode, unsigned char* disableMask);
		unsigned short SetPowerMode(unsigned short val);
		unsigned short RadioState(PropertyAction bPropAction, unsigned short* state);
		unsigned short Reset();
		unsigned short ConfigureLogging(const char* filename, SdkLogLevelType logLevel, SdkLogOutputType output);
		unsigned short UnlockDevice(unsigned char lockType, char* lockCode);
		unsigned short SetAutoLock(unsigned char lockOn, char* lockCode);
		unsigned short GetLockStatus(long* lockStatus, unsigned char* isAutoLockOn);
		unsigned short ChangeLockCode(char* szOldCode, char* szNewCode);
		unsigned short NetworkPreference(PropertyAction bPropAction, unsigned char* pref);
		unsigned short NovaSpeedEnabled(PropertyAction bSet, unsigned char *NSEnabled);
		unsigned short AutoInstallEnabled(PropertyAction bSet, unsigned char* bEnabled);
		unsigned short InternalMassStorageEnabled(PropertyAction bSet, unsigned char* bEnabled);
		unsigned short RestoreToFactoryDefaults(char* spcCode);
		unsigned short RestoreToFactoryDefaultsBasic();
		unsigned short IsLPMSupported(unsigned char* supported);
		unsigned short GetRefurbInfo(unsigned char* status, unsigned long* date, char* provider, unsigned short provider_len);
		unsigned short SetSystemPreferredHybridMode(PropertyAction bSet, unsigned short newPrefMode, unsigned short newHybridMode, unsigned short* oldPrefMode, unsigned short* oldHybridMode);
		unsigned short BandPreference(PropertyAction bPropAction, unsigned char nam, BandPreferenceType* pref);
		unsigned short GetTemperature(unsigned short* temp);
		unsigned short GetLifetimeTimer(unsigned long* count);
		unsigned short GetDisplaySpeed(unsigned char nTheoretical, double* speed);
		unsigned short GetDataCounters(unsigned long* dataTx, unsigned long* dataRx);
		unsigned short GetBatteryState(unsigned short* state, unsigned short* chargePct);
		unsigned short GetManufacturer(char* buffer, unsigned short* buffer_len);

		unsigned short GetDateTime(NvtlTimeStruct^ ts);
		unsigned short GetEriInfo(EriInfoStruct^ eriInfo);
		unsigned short RoamPreference(PropertyAction bPropAction, unsigned char nam, RoamPreferenceType* pref);
		unsigned short IntlRoamPreference(PropertyAction bPropAction, unsigned char* pref);
		unsigned short MicroSDControl(PropertyAction bPropAction, unsigned char* enabled);
		unsigned short LedControl(PropertyAction bPropAction, unsigned char* enabled);

		unsigned short ReadSmsMsg(unsigned short index, SmsMessageStruct^ msg);
		unsigned short SendSmsMsg(SmsMessageStruct^ msg);
		unsigned short DeleteSmsMsg(unsigned short index);
		unsigned short GetSmsList(SmsStateType eSmsType, SmsMessageInfo^ info_array, unsigned short array_size, unsigned short* msg_count);

		unsigned short SMSC(PropertyAction bPropSet, char* buffer, unsigned short* buffer_len);
		unsigned short GetImsi(char* buffer, unsigned short* buffer_len);
		unsigned short GetIccid(char* buffer, unsigned short* buffer_len);
		unsigned short GetNetworkMCCMNC(char* buffer, unsigned short* buffer_len);
		unsigned short GetNetworkOperator(char* buffer, unsigned short* buffer_len);
		unsigned short SetNetworkOperator(unsigned short mode, unsigned short format, unsigned short accessTech, char* szOper);
		unsigned short GetNetworkOperatorList(char* buffer, unsigned short* buffer_len);
		unsigned short SendATCommand(char* command, char* prompt, char* response, unsigned long response_len);
		unsigned short Band(PropertyAction bPropAction, unsigned long* band);
		unsigned short SendStoredSms(unsigned short index);
		unsigned short SetSmsStorage(const char* name);
		unsigned short GetContactStorage(unsigned short* numRecords, unsigned short* maxRecords, char* buffer, unsigned short* buffer_len);
		unsigned short SetContactStorage(char* szStorageName);
		unsigned short WriteSmsMsg(SmsMessageStruct^ msg, unsigned short* index);
		unsigned short IsMsgMemoryFull(unsigned char* full);
		unsigned short GetEnsInfo(unsigned long* ensMode);
		unsigned short GetMobileId(char* buffer, unsigned short* buffer_len);
		unsigned short GetMeid(char* buffer, unsigned short* buffer_len);
		unsigned short IsManualNetworkSelected(unsigned char* bManual);
		unsigned short DomainAttach(PropertyAction bPropAction, unsigned short* state);

		//unsigned short GetMIPError( unsigned long* error );
		unsigned short GetEsnAsDecimal(char* decESN, unsigned short* decEsn_len);

		SdkHandle	m_session;
	private:
		OBJECT_TYPE	m_hDll;


		void		ClearFunctionPointers();

		Func_NvtlCommon_GetSdkVersion               fpNvtlCommon_GetSdkVersion;
		Func_NvtlCommon_CreateSession				fpNvtlCommon_CreateSession;
		Func_NvtlCommon_SetSdkMode                  fpNvtlCommon_SetSdkMode;
		Func_NvtlCommon_ReleaseSession				fpNvtlCommon_ReleaseSession;
		Func_NvtlCommon_AttachDevice				fpNvtlCommon_AttachDevice;
		Func_NvtlCommon_DetachDevice				fpNvtlCommon_DetachDevice;
		Func_NvtlCommon_GetDeviceInfo				fpNvtlCommon_GetDeviceInfo;
		Func_NvtlCommon_GetNetworkInfo				fpNvtlCommon_GetNetworkInfo;
		Func_NvtlCommon_ReadContact					fpNvtlCommon_ReadContact;
		Func_NvtlCommon_ReadMultipleContacts        fpNvtlCommon_ReadMultipleContacts;
		Func_NvtlCommon_WriteContact				fpNvtlCommon_WriteContact;
		Func_NvtlCommon_GetContactSizeDetails		fpNvtlCommon_GetContactSizeDetails;
		Func_NvtlCommon_GetPowerMode				fpNvtlCommon_GetPowerMode;
		Func_NvtlCommon_SetPowerMode				fpNvtlCommon_SetPowerMode;
		Func_NvtlCommon_RadioState                  fpNvtlCommon_RadioState;
		Func_NvtlCommon_Reset						fpNvtlCommon_Reset;
		Func_NvtlCommon_RegisterEventCallback		fpNvtlCommon_RegisterEventCallback;
		Func_NvtlCommon_UnregisterEventCallback		fpNvtlCommon_UnregisterEventCallback;
		Func_NvtlCommon_GetAvailableDevices			fpNvtlCommon_GetAvailableDevices;
		Func_NvtlCommon_SetDeviceAccessKey			fpNvtlCommon_SetDeviceAccessKey;
		Func_NvtlCommon_RefreshDeviceInfo			fpNvtlCommon_RefreshDeviceInfo;
		Func_NvtlCommon_ConfigureLogging			fpNvtlCommon_ConfigureLogging;
		Func_NvtlCommon_UnlockDevice                fpNvtlCommon_UnlockDevice;
		Func_NvtlCommon_SetAutoLock                 fpNvtlCommon_SetAutoLock;
		Func_NvtlCommon_GetLockStatus               fpNvtlCommon_GetLockStatus;
		Func_NvtlCommon_ChangeLockCode              fpNvtlCommon_ChangeLockCode;
		Func_NvtlCommon_NetworkPreference           fpNvtlCommon_NetworkPreference;
		Func_NvtlCommon_NovaSpeedEnabled            fpNvtlCommon_NovaSpeedEnabled;
		Func_NvtlCommon_AutoInstallEnabled          fpNvtlCommon_AutoInstallEnabled;
		Func_NvtlCommon_InternalMassStorageEnabled  fpNvtlCommon_InternalMassStorageEnabled;
		Func_NvtlCommon_GetTemperature              fpNvtlCommon_GetTemperature;
		Func_NvtlCommon_GetLifetimeTimer            fpNvtlCommon_GetLifetimeTimer;
		Func_NvtlCommon_GetDisplaySpeed				fpNvtlCommon_GetDisplaySpeed;
		Func_NvtlCommon_GetDataCounters             fpNvtlCommon_GetDataCounters;
		Func_NvtlCommon_RestoreToFactoryDefaults    fpNvtlCommon_RestoreToFactoryDefaults;
		Func_NvtlCommon_RestoreToFactoryDefaultsBasic    fpNvtlCommon_RestoreToFactoryDefaultsBasic;
		Func_NvtlCommon_IsLPMSupported				fpNvtlCommon_IsLPMSupported;
		Func_NvtlCommon_GetRefurbInfo               fpNvtlCommon_GetRefurbInfo;
		Func_NvtlCommon_SetSystemPreferredHybridMode	fpNvtlCommon_SetSystemPreferredHybridMode;
		Func_NvtlCommon_ReadSmsMsg                  fpNvtlCommon_ReadSmsMsg;
		Func_NvtlCommon_SendSmsMsg                  fpNvtlCommon_SendSmsMsg;
		Func_NvtlCommon_DeleteSmsMsg                fpNvtlCommon_DeleteSmsMsg;
		Func_NvtlCommon_GetSmsList                  fpNvtlCommon_GetSmsList;
		Func_NvtlCommon_GetBatteryState             fpNvtlCommon_GetBatteryState;
		Func_NvtlCommon_GetManufacturer             fpNvtlCommon_GetManufacturer;

		Func_NvtlEvdo_BandPreference                fpNvtlEvdo_BandPreference;
		Func_NvtlEvdo_GetDateTime                   fpNvtlEvdo_GetDateTime;
		Func_NvtlEvdo_GetEriInfo					fpNvtlEvdo_GetEriInfo;
		Func_NvtlEvdo_RoamPreference                fpNvtlEvdo_RoamPreference;
		Func_NvtlEvdo_IntlRoamPreference            fpNvtlEvdo_IntlRoamPreference;
		Func_NvtlEvdo_MicroSDControl                fpNvtlEvdo_MicroSDControl;
		Func_NvtlEvdo_LedControl                    fpNvtlEvdo_LedControl;
		Func_NvtlEvdo_GetMobileId                   fpNvtlEvdo_GetMobileId;
		Func_NvtlEvdo_GetMeid                       fpNvtlEvdo_GetMeid;
		//Func_NvtlEvdo_GetMIPError                   fpNvtlEvdo_GetMIPError;
		Func_NvtlEvdo_GetEsnAsDecimal               fpNvtlEvdo_GetEsnAsDecimal;

		Func_NvtlGsm_SMSC                           fpNvtlGsm_SMSC;
		Func_NvtlGsm_GetImsi                        fpNvtlGsm_GetImsi;
		Func_NvtlGsm_GetIccid                       fpNvtlGsm_GetIccid;
		Func_NvtlGsm_GetNetworkMCCMNC               fpNvtlGsm_GetNetworkMCCMNC;
		Func_NvtlGsm_GetNetworkOperator             fpNvtlGsm_GetNetworkOperator;
		Func_NvtlGsm_SetNetworkOperator             fpNvtlGsm_SetNetworkOperator;
		Func_NvtlGsm_GetNetworkOperatorList         fpNvtlGsm_GetNetworkOperatorList;
		Func_NvtlGsm_SendATCommand                  fpNvtlGsm_SendATCommand;
		Func_NvtlGsm_Band                           fpNvtlGsm_Band;
		Func_NvtlGsm_SendStoredSms                  fpNvtlGsm_SendStoredSms;
		Func_NvtlGsm_SetSmsStorage                  fpNvtlGsm_SetSmsStorage;
		Func_NvtlGsm_GetContactStorage              fpNvtlGsm_GetContactStorage;
		Func_NvtlGsm_SetContactStorage              fpNvtlGsm_SetContactStorage;
		Func_NvtlGsm_WriteSmsMsg                    fpNvtlGsm_WriteSmsMsg;
		Func_NvtlGsm_IsMsgMemoryFull                fpNvtlGsm_IsMsgMemoryFull;
		Func_NvtlGsm_GetEnsInfo                     fpNvtlGsm_GetEnsInfo;
		Func_NvtlGsm_IsManualNetworkSelected        fpNvtlGsm_IsManualNetworkSelected;
		Func_NvtlGsm_DomainAttach                   fpNvtlGsm_DomainAttach;


	};
}
#endif


//namespace NvtlApiWrapper
//{
//	public enum class DeviceTechType
//	{
//		DEV_NONE = 0,        /*!< Unkown device type */
//		DEV_EVDO = 4,        /*!< Evdo device */
//		DEV_UMTS = 7,	    /*!< UMTS device */
//		DEV_HSDPA = 8,        /*!< HSPA device */
//		DEV_EVDO_REVA = 9,        /*!< Evdo REV-A device */
//	};
//
//	public enum class NvtlEventType
//	{
//		NW_EVENT_SIG_STR = 0,           /*!< The signal strength has changed.  The handler event receives a pointer to a SigStrEvent struct */
//		NW_EVENT_ROAMING,               /*!< The roaming status has changed.   The handler event receives a pointer to a RoamingEvent struct */
//		NW_EVENT_DEVICE_STATE,          /*!< The device state has changed.   The handler event receives a pointer to a DeviceStateEvent struct */
//		NW_EVENT_DORMANT,               /*!< The dormancy status has changed.  The handler event receives a pointer to a DormantEvent struct */
//		NW_EVENT_NETWORK,               /*!< The network status has changed.   The handler event receives a pointer to a NetworkEvent struct */
//		NW_EVENT_SERVER_ERROR,          /*!< The SDK received a device error.  The handler event receives a pointer to a ServerErrorEvent struct */
//		NW_EVENT_POWER_SAVE_NOTIFY,     /*!< The device is entering low power mode.  */
//		NW_EVENT_LOG_PACKET,            /*!< not for general use */
//		NW_EVENT_DIAG_PACKET,           /*!< not for general use */
//		NW_EVENT_UNSOLICITED_AT,        /*!< An unsolicited AT response was received.  The handler event receives a pointer to a UnsolicitedATEvent struct */
//		NW_EVENT_SMS,                   /*!< A new sms message was received.  The handler event receives a pointer to a SmsEvent struct */
//		NW_EVENT_INCOMING_CALL,         /*!< not used */
//		NW_EVENT_DEVICE_ADDED,          /*!< A new device was recognized by the host.  The handler event receives a pointer to a DeviceAddedEvent struct */
//		NW_EVENT_DEVICE_REMOVED,        /*!< A device was removed from the host.  The handler event receives a pointer to a DeviceRemovedEvent struct.
//										This event is fired when ANY device removal is detected and may not pertain to the active device in use if multiple
//										devices are recognized in the system.  To detect the removal of a device currently in use handle the NW_EVENT_DEVICE_ERROR event.*/
//		NW_EVENT_ACTIVATION,            /*!< The SDK received an activation status update.  The handler event receives a pointer to a ActivationEvent struct */
//		NW_EVENT_OMADM,                 /*!< The SDK received an OMA-DM status update. The handler event receives a pointer to a OmaStatusEvent struct */
//		NW_EVENT_SMS_SEND_STATUS,       /*!< The SDK received an Sms send status update. The handler event receives a pointer to a SmsSentEvent struct */
//		NW_EVENT_GPS,	                /*!< The SDK received a GPS event.   The handler event receives a pointer to a GpsEvent struct */
//		NW_EVENT_DEVICE_ERROR,          /*!< Indicates that there was an error with the device and communication with the device has stopped.
//																		For example the deivce was removed while in use.  The handler event receives a pointer to a DeviceErrorEvent struct.
//																Use this event as an indication of a plug-n-play removal of a device that is currently being used by the SDK.*/
//		NW_EVENT_GPS_XTRA_STATUS,		/*!< Reports the status of the XTRA file Download and Injection into the device. The handler event receives a pointer to a XtraStatuEvent struct */
//		NW_EVENT_TIME_SYNC_STATUS,		/*!< Reports the status of the Time sync from NTP server. The handler event receives a pointer to a XtraTimeSyncEvent struct */
//		NW_EVENT_DEVICE_ATTACHED,       /*!< The current session has succesfully attached to a device   */
//		NW_EVENT_DEVICE_DETACHED,       /*!< The current session has succesfully detached from a device */
//		NW_EVENT_MIP_ERROR,             /*!< A Mobile IP error indication has been received from the device */
//		NW_EVENT_GPS_XTRA_DOWNLOAD_REQ, /*!< Requests the XTRA file to be downloaded and injected into the device. The handler event receives a pointer to a XtraStatuEvent struct */
//		NW_EVENT_GPS_XTRA_TIMEINFO_REQ, /*!< Requests the XTRA Time sync from the NTP server to be injected into the device. The handler event receives a pointer to a XtraStatuEvent struct */
//		NW_EVENT_GPS_XTRA_CMD_ERR,      /*!< Indicates that the XTRA download or Time sync command was sent to the GPS engine incorrectly. */
//		NW_EVENT_GPS_XTRA_DOWNLOAD_STATUS, /*!< Indicates that the status of XTRA download or Time sync command as reported by the firmware. */
//		NW_EVENT_GPS_SMS_FILTER,        /*!< Reports a specialized GPS directed SMS was received.  Only for VZW LBS services */
//		NW_EVENT_GPS_SECURITY,          /*!< Reports that gps security is initialized.  Only for VZW LBS services */
//		NW_EVENT_GPS_CMD_ERROR,         /*!< Reports that a gps command failed. Only for VZW LBS services. */
//	};
//
//
//	/// Defines a structure sent to registered event callbacks containing information about the event.
//	public ref class NvtlEventStruct
//	{
//	public:
//		unsigned long	type;       /*!< Contains the type of the event (NvtlEventType) */
//		unsigned long	size;       /*!< Contains the total size of the event buffer */
//		unsigned char*	buffer;     /*!< A buffer containing the data or the pointer to the appropriate structure or type */
//	};
//
//	public ref class StandardEvent{
//	public:
//		unsigned long val;  /*!< The value of the event */
//	};
//
//	/// Defines the strength event received in the event callback when
//	/// the signal strength changes.  The value is the current signal strength of the device
//	public ref class SigStrEvent : StandardEvent{};
//
//	/// Defines the romaing event struct receieved in the event callback when
//	/// the roaming status changes.  The value is the current roaming status of the device as defined by the #DeviceRoamStatusType enum
//	typedef StandardEvent RoamingEvent;
//
//	/// Defines the device state event received in the event callback when
//	/// the device state changes.  The value is the current state of the device as defined by the #DeviceStateType enum
//	typedef StandardEvent DeviceStateEvent;
//
//	/// Defines the dormancy event received in the event callback when
//	/// the dormancy status changes.  The value is the current dormancy status of the device
//	typedef StandardEvent DormantEvent;
//
//	/// Defines the network event received in the event callback when
//	/// the network status changes.  The value is the current network state of the device as defined by the #DeviceServiceType enum
//	typedef StandardEvent NetworkEvent;
//
//	/// Defines the server error event received in the event callback when
//	/// an error is received from the device relating to connections.  The value is an
//	/// error received during a connection or connection attempt.
//	typedef StandardEvent ServerErrorEvent;
//
//	/// Defines the sms event received in the event callback when 
//	/// new sms messages are available.  The value is an indicator that new sms messages are waiting.
//	typedef StandardEvent SmsEvent;
//
//	/// Defines the sms sent event received in the event callback when
//	/// an sms message is either sent or failed during transmission. The value is an indicator of the 
//	/// success or failure of an attempt at sending an sms message
//	typedef StandardEvent SmsSentEvent;
//
//	/// Defines the device added event received in the event callback when
//	/// a new device is added to the system. 
//	typedef StandardEvent DeviceAddedEvent;
//
//	/// Defines the device removed event received in the event callback when
//	/// a device is removed from the system
//	typedef StandardEvent DeviceRemovedEvent;
//
//	/// Defines the activation event received in the event callback when
//	/// the activation status changes.  The value is an indication of the current state of the activation process
//	/// as defined by the #ActivationStateType enum
//	typedef StandardEvent ActivationEvent;
//
//	/// Defines the gps event received in the event callback when
//	/// gps status changes or fixes are available.
//	typedef StandardEvent GpsEvent;
//
//	/// Defines the device erorr event received in the event callback when
//	/// an error occurs with the communication with a device.
//	typedef StandardEvent DeviceErrorEvent;
//
//	/// Defines the xtra status event received in the event callback when
//	/// the xtra status of the gps engine changes.
//	typedef StandardEvent XtraStatuEvent;
//
//	/// Defines the xtra time synce event received in the event callback when
//	/// the gps engine synchronizes time with an internet server.
//	typedef StandardEvent XtraTimeSyncEvent;
//
//	/// Defines the device erorr event received in the event callback when
//	/// a session has succesfully attached to a device.
//	typedef StandardEvent DeviceAttachedEvent;
//
//	/// Defines the device erorr event received in the event callback when
//	/// a session has succesfully detached from a device.
//	typedef StandardEvent DeviceDetachedEvent;
//
//	/// Defines the erorr event received in the event callback when
//	/// a mobile ip error has been received.
//	typedef StandardEvent MipErrorEvent;
//
//	/// Defines the unsolicited event received in the event callback when
//	/// an unsolicited AT repsonse is received.
//	typedef char* UnsolicitedATEvent;
//
//	/// Defines the event received when a specialized GPS routed SMS is received. Select VZW devices only.
//	public ref class GpsSmsFilterEvent{
//		char^  val;
//	};
//
//	/// Defines the erorr event received in the event callback when
//	/// a gps command has failed.
//	typedef StandardEvent GpsCommandErrorEvent;
//
//
//	/// Defines the callback function used to propogate SDK events.
//	typedef void(*NvtlSdkEventFunc)(void* user_data, unsigned long type, unsigned long size, void* ev);
//
//	public ref class NvtlEventCallbackManaged
//	{
//	public:
//		void* user_data;      /*!< A user defined pointer that is returned during the callback */
//		NvtlSdkEventFunc event_func;     /*!< A pointer to the NvtlSdkEventFunc that should be called for events */
//	};
//}