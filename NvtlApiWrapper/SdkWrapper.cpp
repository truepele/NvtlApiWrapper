/**
*
* Copyright 2008 Novatel Wireless Inc.
*
*/


#include "stdafx.h"
#include "SdkWrapper.h"

using namespace System;
using namespace System::Runtime::InteropServices;

SdkWrapper::SdkWrapper()
{
	m_session = 0;
	m_hDll = 0;

	ClearFunctionPointers();

	m_hDll = LOAD_OBJECT( BASESDK_OBJECT_NAME  );
}
void SdkWrapper::ClearFunctionPointers()
{
    fpNvtlCommon_GetSdkVersion = 0;
	fpNvtlCommon_CreateSession = 0;
	fpNvtlCommon_ReleaseSession = 0;
	fpNvtlCommon_AttachDevice= 0;
	fpNvtlCommon_DetachDevice= 0;
	fpNvtlCommon_GetDeviceInfo = 0;
	fpNvtlCommon_GetNetworkInfo = 0;
	fpNvtlCommon_ReadContact= 0;
    fpNvtlCommon_ReadMultipleContacts = 0;
	fpNvtlCommon_WriteContact = 0;
	fpNvtlCommon_GetContactSizeDetails = 0;
	fpNvtlCommon_GetPowerMode = 0;
	fpNvtlCommon_SetPowerMode = 0;
    fpNvtlCommon_RadioState = 0;
	fpNvtlCommon_Reset = 0;
	fpNvtlCommon_RegisterEventCallback = 0;
	fpNvtlCommon_UnregisterEventCallback = 0;	
	fpNvtlCommon_GetAvailableDevices = 0;
	fpNvtlCommon_RefreshDeviceInfo = 0;
	fpNvtlCommon_ConfigureLogging = 0;
    fpNvtlCommon_SetSdkMode = 0;
    fpNvtlCommon_UnlockDevice = 0;
    fpNvtlCommon_SetAutoLock = 0;
    fpNvtlCommon_GetLockStatus = 0;
    fpNvtlCommon_ChangeLockCode = 0;
    fpNvtlCommon_NetworkPreference = 0;
	fpNvtlCommon_NovaSpeedEnabled = 0;
    fpNvtlCommon_GetTemperature = 0;
    fpNvtlCommon_GetLifetimeTimer = 0;
	fpNvtlCommon_GetDisplaySpeed = 0;
    fpNvtlCommon_GetDataCounters = 0;
    fpNvtlCommon_AutoInstallEnabled = 0;
    fpNvtlCommon_InternalMassStorageEnabled = 0;
    fpNvtlCommon_RestoreToFactoryDefaults = 0;
    fpNvtlCommon_RestoreToFactoryDefaultsBasic = 0;
	fpNvtlCommon_IsLPMSupported = 0;
    fpNvtlCommon_GetRefurbInfo = 0;
	fpNvtlCommon_SetSystemPreferredHybridMode = 0;
    fpNvtlCommon_ReadSmsMsg = 0;
    fpNvtlCommon_SendSmsMsg = 0;
    fpNvtlCommon_DeleteSmsMsg = 0;
    fpNvtlCommon_GetSmsList = 0;
    fpNvtlCommon_GetBatteryState = 0;
	fpNvtlCommon_GetManufacturer = 0;
	fpNvtlCommon_SetDeviceAccessKey = 0;

    fpNvtlEvdo_BandPreference = 0;
    fpNvtlEvdo_GetDateTime = 0;
	fpNvtlEvdo_GetEriInfo = 0;
    fpNvtlEvdo_RoamPreference = 0;
    fpNvtlEvdo_IntlRoamPreference = 0;
    fpNvtlEvdo_MicroSDControl = 0;
    fpNvtlEvdo_LedControl = 0;
    fpNvtlEvdo_GetMobileId = 0;
    fpNvtlEvdo_GetMeid = 0;
    //fpNvtlEvdo_GetMIPError = 0;
    fpNvtlEvdo_GetEsnAsDecimal = 0;

    fpNvtlGsm_SMSC = 0;
    fpNvtlGsm_GetImsi = 0;
    fpNvtlGsm_GetIccid = 0;
    fpNvtlGsm_GetNetworkMCCMNC = 0;
    fpNvtlGsm_GetNetworkOperator = 0;
    fpNvtlGsm_SetNetworkOperator = 0;
    fpNvtlGsm_GetNetworkOperatorList = 0;
    fpNvtlGsm_SendATCommand = 0;
    fpNvtlGsm_Band = 0;
    fpNvtlGsm_SendStoredSms = 0;
    fpNvtlGsm_SetSmsStorage = 0;
    fpNvtlGsm_GetContactStorage = 0;
    fpNvtlGsm_SetContactStorage = 0;
    fpNvtlGsm_WriteSmsMsg = 0;
    fpNvtlGsm_IsMsgMemoryFull = 0;
    fpNvtlGsm_GetEnsInfo = 0;
    fpNvtlGsm_IsManualNetworkSelected = 0;
    fpNvtlGsm_DomainAttach = 0;

}
SdkWrapper::~SdkWrapper()
{
	if( m_hDll != NULL )
	{
		ReleaseSession();
		UNLOAD_OBJECT(m_hDll);
	}
}

bool SdkWrapper::IsLoaded()
{
	return (m_hDll != NULL);
}

unsigned short SdkWrapper::CreateSession()
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_CreateSession, Func_NvtlCommon_CreateSession, "NvtlCommon_CreateSession", m_hDll );

	if( ! m_session )
		m_session = fpNvtlCommon_CreateSession();
    if( !m_session )
        return LR_ERROR_SERVER_NOT_AVAILABLE;

	return 0;
}
bool SdkWrapper::HasValidSession()
{
    return ( m_session != 0 );
}

unsigned short SdkWrapper::GetSdkVersion( char* buffer, unsigned short buffer_len )
{
    LOAD_FUNCTION_PTR(fpNvtlCommon_GetSdkVersion, Func_NvtlCommon_GetSdkVersion, "NvtlCommon_GetSdkVersion", m_hDll );
	
	return fpNvtlCommon_GetSdkVersion( buffer, buffer_len );
}

unsigned short SdkWrapper::SetSdkMode(NvtlSdkModeType sdk_mode, const char* szAccessKey )
{
    LOAD_FUNCTION_PTR(fpNvtlCommon_SetSdkMode , Func_NvtlCommon_SetSdkMode, "NvtlCommon_SetSdkMode", m_hDll );
	
	return fpNvtlCommon_SetSdkMode(sdk_mode, szAccessKey );
}
unsigned short SdkWrapper::ReleaseSession()
{
    unsigned short wRet = 1;

    LOAD_FUNCTION_PTR( fpNvtlCommon_ReleaseSession, Func_NvtlCommon_ReleaseSession, "NvtlCommon_ReleaseSession", m_hDll );
		
	if( m_session != 0)
	{
		wRet = fpNvtlCommon_ReleaseSession( m_session );
		m_session = 0;
	}
	return wRet;
}
unsigned short SdkWrapper::RefreshDeviceInfo()
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_RefreshDeviceInfo, Func_NvtlCommon_RefreshDeviceInfo, "NvtlCommon_RefreshDeviceInfo", m_hDll );

    return fpNvtlCommon_RefreshDeviceInfo( m_session );
}

unsigned short SdkWrapper::AttachDevice( DeviceDetail* pDeviceDetail )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_AttachDevice, Func_NvtlCommon_AttachDevice, "NvtlCommon_AttachDevice", m_hDll );
	
	return fpNvtlCommon_AttachDevice(m_session, pDeviceDetail);
}

unsigned short SdkWrapper::DetachDevice()
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_DetachDevice, Func_NvtlCommon_DetachDevice, "NvtlCommon_DetachDevice", m_hDll );
	
	return fpNvtlCommon_DetachDevice(m_session);
}

unsigned short SdkWrapper::ConfigureLogging( const char* filename, SdkLogLevelType logLevel, SdkLogOutputType output )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_ConfigureLogging, Func_NvtlCommon_ConfigureLogging, "NvtlCommon_ConfigureLogging", m_hDll );
	
	return fpNvtlCommon_ConfigureLogging(filename, logLevel, output);
}

unsigned short SdkWrapper::UnlockDevice( unsigned char lockType, char* lockCode )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_UnlockDevice, Func_NvtlCommon_UnlockDevice, "NvtlCommon_UnlockDevice", m_hDll );
	
	return fpNvtlCommon_UnlockDevice(m_session, lockType, lockCode);
}

unsigned short SdkWrapper::SetAutoLock( unsigned char nAutoOn, char* lockCode )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_SetAutoLock, Func_NvtlCommon_SetAutoLock, "NvtlCommon_SetAutoLock", m_hDll );
	
	return fpNvtlCommon_SetAutoLock(m_session, nAutoOn, lockCode);
}

unsigned short SdkWrapper::GetLockStatus( long* lockStatus, unsigned char* isAutoLockOn )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_GetLockStatus, Func_NvtlCommon_GetLockStatus, "NvtlCommon_GetLockStatus", m_hDll );
	
	return fpNvtlCommon_GetLockStatus(m_session, lockStatus, isAutoLockOn);
}

unsigned short SdkWrapper::ChangeLockCode( char* szOldCode, char* szNewCode )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_ChangeLockCode, Func_NvtlCommon_ChangeLockCode, "NvtlCommon_ChangeLockCode", m_hDll );
	
	return fpNvtlCommon_ChangeLockCode(m_session, szOldCode, szNewCode);
}

unsigned short SdkWrapper::NetworkPreference( PropertyAction bPropAction, unsigned char* pref )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_NetworkPreference, Func_NvtlCommon_NetworkPreference, "NvtlCommon_NetworkPreference", m_hDll );
	
	return fpNvtlCommon_NetworkPreference(m_session, bPropAction, pref);
}

unsigned short SdkWrapper::NovaSpeedEnabled( PropertyAction bSet, unsigned char *NSEnabled )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_NovaSpeedEnabled, Func_NvtlCommon_NovaSpeedEnabled, "NvtlCommon_NovaSpeedEnabled", m_hDll );
	
	return fpNvtlCommon_NovaSpeedEnabled( m_session, bSet, NSEnabled );
}

unsigned short SdkWrapper::GetTemperature( unsigned short* temp )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_GetTemperature, Func_NvtlCommon_GetTemperature, "NvtlCommon_GetTemperature", m_hDll );
	
	return fpNvtlCommon_GetTemperature(m_session, temp);
}

unsigned short SdkWrapper::GetLifetimeTimer( unsigned long* count )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_GetLifetimeTimer, Func_NvtlCommon_GetLifetimeTimer, "NvtlCommon_GetLifetimeTimer", m_hDll );
	
	return fpNvtlCommon_GetLifetimeTimer(m_session, count );
}

unsigned short SdkWrapper::GetDisplaySpeed( unsigned char nTheoretical, double* speed )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_GetDisplaySpeed, Func_NvtlCommon_GetDisplaySpeed, "NvtlCommon_GetDisplaySpeed", m_hDll );
	
	return fpNvtlCommon_GetDisplaySpeed( m_session, nTheoretical, speed );	
}

unsigned short SdkWrapper::GetDataCounters( unsigned long* dataTx, unsigned long* dataRx )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_GetDataCounters, Func_NvtlCommon_GetDataCounters, "NvtlCommon_GetDataCounters", m_hDll );
	
	return fpNvtlCommon_GetDataCounters(m_session, dataTx, dataRx );
}

unsigned short SdkWrapper::AutoInstallEnabled( PropertyAction bSet, unsigned char* bEnabled )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_AutoInstallEnabled, Func_NvtlCommon_AutoInstallEnabled, "NvtlCommon_AutoInstallEnabled", m_hDll );
	
	return fpNvtlCommon_AutoInstallEnabled(m_session, bSet, bEnabled);
}

unsigned short SdkWrapper::InternalMassStorageEnabled( PropertyAction bSet, unsigned char* bEnabled )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_InternalMassStorageEnabled, Func_NvtlCommon_InternalMassStorageEnabled, "NvtlCommon_InternalMassStorageEnabled", m_hDll );
	
	return fpNvtlCommon_InternalMassStorageEnabled(m_session, bSet, bEnabled);
}

unsigned short SdkWrapper::RestoreToFactoryDefaults( char* spcCode )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_RestoreToFactoryDefaults, Func_NvtlCommon_RestoreToFactoryDefaults, "NvtlCommon_RestoreToFactoryDefaults", m_hDll );
	
	return fpNvtlCommon_RestoreToFactoryDefaults(m_session, spcCode);
}
unsigned short SdkWrapper::RestoreToFactoryDefaultsBasic()
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_RestoreToFactoryDefaultsBasic, Func_NvtlCommon_RestoreToFactoryDefaultsBasic, "NvtlCommon_RestoreToFactoryDefaultsBasic", m_hDll );
	
	return fpNvtlCommon_RestoreToFactoryDefaultsBasic(m_session);
}

unsigned short SdkWrapper::IsLPMSupported( unsigned char* supported )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_IsLPMSupported, Func_NvtlCommon_IsLPMSupported, "NvtlCommon_IsLPMSupported", m_hDll );
	
	return fpNvtlCommon_IsLPMSupported( m_session, supported );	
}

unsigned short SdkWrapper::GetRefurbInfo( unsigned char* status, unsigned long* date, char* provider, unsigned short provider_len)
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_GetRefurbInfo, Func_NvtlCommon_GetRefurbInfo, "NvtlCommon_GetRefurbInfo", m_hDll );
	
	return fpNvtlCommon_GetRefurbInfo(m_session, status, date, provider, provider_len);
}

unsigned short SdkWrapper::SetSystemPreferredHybridMode( PropertyAction bSet, unsigned short newPrefMode, unsigned short newHybridMode, unsigned short* oldPrefMode, unsigned short* oldHybridMode )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_SetSystemPreferredHybridMode, Func_NvtlCommon_SetSystemPreferredHybridMode, "NvtlCommon_SetSystemPreferredHybridMode", m_hDll );
	
	return fpNvtlCommon_SetSystemPreferredHybridMode( m_session, bSet, newPrefMode, newHybridMode, oldPrefMode, oldHybridMode );
}

unsigned short SdkWrapper::BandPreference( PropertyAction bPropAction, unsigned char nam, BandPreferenceType* pref )
{
    LOAD_FUNCTION_PTR( fpNvtlEvdo_BandPreference, Func_NvtlEvdo_BandPreference, "NvtlEvdo_BandPreference", m_hDll );
	
	return fpNvtlEvdo_BandPreference(m_session, bPropAction, nam, pref);
}

unsigned short SdkWrapper::GetDateTime( NvtlTimeStruct* ts )
{
    LOAD_FUNCTION_PTR( fpNvtlEvdo_GetDateTime, Func_NvtlEvdo_GetDateTime, "NvtlEvdo_GetDateTime", m_hDll );
	
	return fpNvtlEvdo_GetDateTime(m_session, ts );
}

unsigned short SdkWrapper::GetEriInfo( EriInfoStruct* eriInfo )
{
    LOAD_FUNCTION_PTR( fpNvtlEvdo_GetEriInfo, Func_NvtlEvdo_GetEriInfo, "NvtlEvdo_GetEriInfo", m_hDll );
	
	return fpNvtlEvdo_GetEriInfo( m_session, eriInfo );	
}

unsigned short SdkWrapper::RoamPreference( PropertyAction bPropAction, unsigned char nam, RoamPreferenceType* pref )
{
    LOAD_FUNCTION_PTR( fpNvtlEvdo_RoamPreference, Func_NvtlEvdo_RoamPreference, "NvtlEvdo_RoamPreference", m_hDll );
	
	return fpNvtlEvdo_RoamPreference(m_session, bPropAction, nam, pref );
}
unsigned short SdkWrapper::IntlRoamPreference( PropertyAction bPropAction, unsigned char* pref )
{
    LOAD_FUNCTION_PTR( fpNvtlEvdo_IntlRoamPreference, Func_NvtlEvdo_IntlRoamPreference, "NvtlEvdo_IntlRoamPreference", m_hDll );
	
	return fpNvtlEvdo_IntlRoamPreference(m_session, bPropAction, pref );
}
unsigned short SdkWrapper::MicroSDControl( PropertyAction bPropAction, unsigned char* enabled )
{
    LOAD_FUNCTION_PTR( fpNvtlEvdo_MicroSDControl, Func_NvtlEvdo_MicroSDControl, "NvtlEvdo_MicroSDControl", m_hDll );
	
	return fpNvtlEvdo_MicroSDControl(m_session, bPropAction, enabled );
}
unsigned short SdkWrapper::LedControl( PropertyAction bPropAction, unsigned char* enabled )
{
    LOAD_FUNCTION_PTR( fpNvtlEvdo_LedControl, Func_NvtlEvdo_LedControl, "NvtlEvdo_LedControl", m_hDll );
	
	return fpNvtlEvdo_LedControl(m_session, bPropAction, enabled );
}

unsigned short SdkWrapper::GetAvailableDevices( DeviceDetail* pDevList, unsigned long* dev_list_size )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_GetAvailableDevices, Func_NvtlCommon_GetAvailableDevices, "NvtlCommon_GetAvailableDevices", m_hDll );
	
	return fpNvtlCommon_GetAvailableDevices(m_session, pDevList, dev_list_size);
}
unsigned short SdkWrapper::SetDeviceAccessKey( char *szAccessKey )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_SetDeviceAccessKey, Func_NvtlCommon_SetDeviceAccessKey, "NvtlCommon_SetDeviceAccessKey", m_hDll );
	
	return fpNvtlCommon_SetDeviceAccessKey(m_session, szAccessKey);
}
unsigned short SdkWrapper::RegisterEventCallback( NvtlEventCallback& cb)
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_RegisterEventCallback, Func_NvtlCommon_RegisterEventCallback, "NvtlCommon_RegisterEventCallback", m_hDll );
	
	return fpNvtlCommon_RegisterEventCallback(m_session, cb);
}
unsigned short SdkWrapper::UnregisterEventCallback( NvtlEventCallback& cb)
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_UnregisterEventCallback, Func_NvtlCommon_UnregisterEventCallback, "NvtlCommon_UnregisterEventCallback", m_hDll );
	
	return fpNvtlCommon_UnregisterEventCallback(m_session, cb);
}
unsigned short SdkWrapper::GetDeviceInfo( DeviceInfoStruct* pDevInfo )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_GetDeviceInfo, Func_NvtlCommon_GetDeviceInfo, "NvtlCommon_GetDeviceInfo", m_hDll );
	
	return fpNvtlCommon_GetDeviceInfo (m_session, pDevInfo );
}

unsigned short SdkWrapper::GetNetworkInfo( NetworkInfoStruct* pNetInfo )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_GetNetworkInfo, Func_NvtlCommon_GetNetworkInfo, "NvtlCommon_GetNetworkInfo", m_hDll );
	
	return fpNvtlCommon_GetNetworkInfo(m_session, pNetInfo );
}
unsigned short SdkWrapper::ReadContact( short index, ContactInfoStruct* pContact)
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_ReadContact, Func_NvtlCommon_ReadContact, "NvtlCommon_ReadContact", m_hDll );
	
	return fpNvtlCommon_ReadContact(m_session, index, pContact);
}
unsigned short SdkWrapper::ReadMultipleContacts( unsigned short start_index, unsigned short num_to_read, ContactInfoStruct* pContact, unsigned short* pRead )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_ReadMultipleContacts, Func_NvtlCommon_ReadMultipleContacts, "NvtlCommon_ReadMultipleContacts", m_hDll );
	
	return fpNvtlCommon_ReadMultipleContacts(m_session, start_index, num_to_read, pContact, pRead);
}
unsigned short SdkWrapper::WriteContact( ContactInfoStruct* pContact)
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_WriteContact, Func_NvtlCommon_WriteContact, "NvtlCommon_WriteContact", m_hDll );
	
	return fpNvtlCommon_WriteContact(m_session, pContact);
}
unsigned short SdkWrapper::GetContactSizeDetails( ContactSizeInfoStruct* pContactDetails )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_GetContactSizeDetails, Func_NvtlCommon_GetContactSizeDetails, "NvtlCommon_GetContactSizeDetails", m_hDll );
	
	return fpNvtlCommon_GetContactSizeDetails(m_session, pContactDetails);
}
unsigned short SdkWrapper::GetPowerMode(unsigned short* mode, unsigned char* disableMask)
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_GetPowerMode, Func_NvtlCommon_GetPowerMode, "NvtlCommon_GetPowerMode", m_hDll );
	
	return fpNvtlCommon_GetPowerMode(m_session, mode, disableMask);
}
unsigned short SdkWrapper::SetPowerMode(unsigned short val)
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_SetPowerMode, Func_NvtlCommon_SetPowerMode, "NvtlCommon_SetPowerMode", m_hDll );
	
	return fpNvtlCommon_SetPowerMode(m_session, val);
}
unsigned short SdkWrapper::RadioState( PropertyAction bPropAction, unsigned short* val)
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_RadioState, Func_NvtlCommon_RadioState, "NvtlCommon_RadioState", m_hDll );
	
	return fpNvtlCommon_RadioState(m_session, bPropAction, val);
}

unsigned short SdkWrapper::Reset()
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_Reset, Func_NvtlCommon_Reset, "NvtlCommon_Reset", m_hDll );
	
	return fpNvtlCommon_Reset(m_session);
}

unsigned short SdkWrapper::ReadSmsMsg( unsigned short index, SmsMessageStruct* msg )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_ReadSmsMsg, Func_NvtlCommon_ReadSmsMsg, "NvtlCommon_ReadSmsMsg", m_hDll );
	
	return fpNvtlCommon_ReadSmsMsg(m_session, index, msg);
}
unsigned short SdkWrapper::SendSmsMsg( SmsMessageStruct* msg )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_SendSmsMsg, Func_NvtlCommon_SendSmsMsg, "NvtlCommon_SendSmsMsg", m_hDll );
	
    return fpNvtlCommon_SendSmsMsg(m_session, msg);
}
unsigned short SdkWrapper::DeleteSmsMsg( unsigned short index )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_DeleteSmsMsg, Func_NvtlCommon_DeleteSmsMsg, "NvtlCommon_DeleteSmsMsg", m_hDll );
	
	return fpNvtlCommon_DeleteSmsMsg(m_session, index);
}
unsigned short SdkWrapper::GetSmsList( SmsStateType eSmsType, SmsMessageInfo* info_array, unsigned short array_size, unsigned short* msg_count)
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_GetSmsList, Func_NvtlCommon_GetSmsList, "NvtlCommon_GetSmsList", m_hDll );
	
	return fpNvtlCommon_GetSmsList(m_session, eSmsType, info_array, array_size, msg_count);
}

unsigned short SdkWrapper::GetBatteryState( unsigned short* state , unsigned short* chargePct )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_GetBatteryState, Func_NvtlCommon_GetBatteryState, "NvtlCommon_GetBatteryState", m_hDll );
	
	return fpNvtlCommon_GetBatteryState(m_session, state, chargePct );
}

unsigned short SdkWrapper::GetManufacturer( char* buffer, unsigned short* buffer_len )
{
    LOAD_FUNCTION_PTR( fpNvtlCommon_GetManufacturer, Func_NvtlCommon_GetManufacturer, "NvtlCommon_GetManufacturer", m_hDll );
	
	return fpNvtlCommon_GetManufacturer(m_session, buffer, buffer_len );
}

unsigned short SdkWrapper::SMSC( PropertyAction propAct, char* buffer, unsigned short* buffer_len )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_SMSC, Func_NvtlGsm_SMSC, "NvtlGsm_SMSC", m_hDll );
	
	return fpNvtlGsm_SMSC(m_session, propAct, buffer, buffer_len );
}
unsigned short SdkWrapper::GetImsi( char* buffer, unsigned short* buffer_len )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_GetImsi, Func_NvtlGsm_GetImsi, "NvtlGsm_GetImsi", m_hDll );
	
	return fpNvtlGsm_GetImsi(m_session, buffer, buffer_len );
}
unsigned short SdkWrapper::GetIccid( char* buffer, unsigned short* buffer_len )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_GetIccid, Func_NvtlGsm_GetIccid, "NvtlGsm_GetIccid", m_hDll );
	
    return fpNvtlGsm_GetIccid(m_session, buffer, buffer_len );
}
unsigned short SdkWrapper::GetNetworkMCCMNC( char* buffer, unsigned short* buffer_len )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_GetNetworkMCCMNC, Func_NvtlGsm_GetNetworkMCCMNC, "NvtlGsm_GetNetworkMCCMNC", m_hDll );
	
	return fpNvtlGsm_GetNetworkMCCMNC(m_session, buffer, buffer_len );
}
unsigned short SdkWrapper::GetNetworkOperator( char* buffer, unsigned short* buffer_len )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_GetNetworkOperator, Func_NvtlGsm_GetNetworkOperator, "NvtlGsm_GetNetworkOperator", m_hDll );
	
	return fpNvtlGsm_GetNetworkOperator(m_session, buffer, buffer_len );
}
unsigned short SdkWrapper::SetNetworkOperator( unsigned short mode, unsigned short format, unsigned short accessTech, char* szOper)
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_SetNetworkOperator, Func_NvtlGsm_SetNetworkOperator, "NvtlGsm_SetNetworkOperator", m_hDll );
	
	return fpNvtlGsm_SetNetworkOperator(m_session, mode, format, accessTech, szOper );
}
unsigned short SdkWrapper::GetNetworkOperatorList( char* buffer, unsigned short* buffer_len )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_GetNetworkOperatorList, Func_NvtlGsm_GetNetworkOperatorList, "NvtlGsm_GetNetworkOperatorList", m_hDll );

	return fpNvtlGsm_GetNetworkOperatorList(m_session, buffer, buffer_len );
}
unsigned short SdkWrapper::SendATCommand( char* command, char* prompt, char* response, unsigned long response_len )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_SendATCommand, Func_NvtlGsm_SendATCommand, "NvtlGsm_SendATCommand", m_hDll );
	
	return fpNvtlGsm_SendATCommand(m_session, command, prompt, response, response_len );
}
unsigned short SdkWrapper::Band( PropertyAction bPropAction, unsigned long* band )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_Band, Func_NvtlGsm_Band, "NvtlGsm_Band", m_hDll );
	
    return fpNvtlGsm_Band(m_session, bPropAction, band );
}
unsigned short SdkWrapper::SendStoredSms( unsigned short index )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_SendStoredSms, Func_NvtlGsm_SendStoredSms, "NvtlGsm_SendStoredSms", m_hDll );
	
	return fpNvtlGsm_SendStoredSms(m_session, index );
}
unsigned short SdkWrapper::SetSmsStorage( const char* name )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_SetSmsStorage, Func_NvtlGsm_SetSmsStorage, "NvtlGsm_SetSmsStorage", m_hDll );
	
	return fpNvtlGsm_SetSmsStorage(m_session, name );
}
unsigned short SdkWrapper::GetContactStorage( unsigned short* numRecords, unsigned short* maxRecords, char* buffer, unsigned short* buffer_len )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_GetContactStorage, Func_NvtlGsm_GetContactStorage, "NvtlGsm_GetContactStorage", m_hDll );
	
    return fpNvtlGsm_GetContactStorage(m_session, numRecords, maxRecords, buffer, buffer_len );
}
unsigned short SdkWrapper::SetContactStorage( char* szStorageName )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_SetContactStorage , Func_NvtlGsm_SetContactStorage, "NvtlGsm_SetContactStorage", m_hDll );

	return fpNvtlGsm_SetContactStorage(m_session, szStorageName );
}
unsigned short SdkWrapper::WriteSmsMsg( SmsMessageStruct* msg, unsigned short* index)
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_WriteSmsMsg, Func_NvtlGsm_WriteSmsMsg, "NvtlGsm_WriteSmsMsg", m_hDll );

	return fpNvtlGsm_WriteSmsMsg(m_session, msg, index );
}
unsigned short SdkWrapper::IsMsgMemoryFull( unsigned char* full )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_IsMsgMemoryFull, Func_NvtlGsm_IsMsgMemoryFull, "NvtlGsm_IsMsgMemoryFull", m_hDll );
	
    return fpNvtlGsm_IsMsgMemoryFull(m_session, full );
}
unsigned short SdkWrapper::GetEnsInfo( unsigned long* ensMode )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_GetEnsInfo, Func_NvtlGsm_GetEnsInfo, "NvtlGsm_GetEnsInfo", m_hDll );

    return fpNvtlGsm_GetEnsInfo( m_session, ensMode );
}
unsigned short SdkWrapper::GetMobileId( char* buffer, unsigned short* buffer_len )
{
    LOAD_FUNCTION_PTR( fpNvtlEvdo_GetMobileId, Func_NvtlEvdo_GetMobileId, "NvtlEvdo_GetMobileId", m_hDll );

    return fpNvtlEvdo_GetMobileId( m_session, buffer, buffer_len );
}
unsigned short SdkWrapper::GetMeid( char* buffer, unsigned short* buffer_len )
{
    LOAD_FUNCTION_PTR( fpNvtlEvdo_GetMeid, Func_NvtlEvdo_GetMeid, "NvtlEvdo_GetMeid", m_hDll );

    return fpNvtlEvdo_GetMeid( m_session, buffer, buffer_len );
}
/*
unsigned short SdkWrapper::GetMIPError( unsigned long* error )
{
    LOAD_FUNCTION_PTR( fpNvtlEvdo_GetMIPError, Func_NvtlEvdo_GetMIPError, "NvtlEvdo_GetMIPError", m_hDll );

    return fpNvtlEvdo_GetMIPError( m_session, error );
}
*/
unsigned short SdkWrapper::GetEsnAsDecimal( char* decEsn, unsigned short* decEsn_len )
{
    LOAD_FUNCTION_PTR( fpNvtlEvdo_GetEsnAsDecimal, Func_NvtlEvdo_GetEsnAsDecimal, "NvtlEvdo_GetEsnAsDecimal", m_hDll );

    return fpNvtlEvdo_GetEsnAsDecimal( m_session, decEsn, decEsn_len );
}

unsigned short SdkWrapper::IsManualNetworkSelected( unsigned char* bManual )
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_IsManualNetworkSelected, Func_NvtlGsm_IsManualNetworkSelected, "NvtlGsm_IsManualNetworkSelected", m_hDll );

    return fpNvtlGsm_IsManualNetworkSelected( m_session, bManual );
}
unsigned short SdkWrapper::DomainAttach( PropertyAction bPropAction, unsigned short* val)
{
    LOAD_FUNCTION_PTR( fpNvtlGsm_DomainAttach, Func_NvtlGsm_DomainAttach, "NvtlGsm_DomainAttach", m_hDll );
	
	return fpNvtlGsm_DomainAttach(m_session, bPropAction, val);
}

short NvtlApiWrapper::ApiWrapper::AttachDevice(DeviceDetail pDeviceDetail)
{
	return 0;
}

bool NvtlApiWrapper::ApiWrapper::Init()
{
	_sdk = new SdkWrapper;
	//Check to see if SDK loaded okay
	if (!_sdk->IsLoaded())
	{		
		return false;
	}
		
	short rval = _sdk->CreateSession();

	_cb = new NvtlEventCallback;

	_cb->user_data = 0;
	EventHandlerDelegate^ delegate = gcnew EventHandlerDelegate(this, &NvtlApiWrapper::ApiWrapper::EventHandler);
	System::IntPtr unmanaged = Marshal::GetFunctionPointerForDelegate(delegate);
	_cb->event_func = (NvtlSdkEventFunc)(void*)unmanaged;
	rval = _sdk->RegisterEventCallback(*_cb);	
}

void NvtlApiWrapper::ApiWrapper::EventHandler(void* user_data, unsigned long type, unsigned long size, void* ev)
{
	switch (type)
	{
	case NW_EVENT_SIG_STR:
		printf("Signal Strength Received = %ld\n", ((SigStrEvent*)ev)->val);
		break;

	case NW_EVENT_ROAMING:
		printf("Roaming Status Received = %ld\n", ((RoamingEvent*)ev)->val);
		break;

	case NW_EVENT_SERVER_ERROR:
		printf("EVENT SERVER ERROR = %ld\n", ((ServerErrorEvent*)ev)->val);
		break;

	case NW_EVENT_DEVICE_STATE:
	{
		printf("Device State Recevied = %ld\n", ((DeviceStateEvent*)ev)->val);
		//gDeviceState = ((DeviceStateEvent*)ev)->val;
	}
		break;

	case NW_EVENT_NETWORK:
		printf("EVENT NETWORK = %ld\n", ((NetworkEvent*)ev)->val);
		break;

	case NW_EVENT_DEVICE_ADDED:
	{
		printf("A new device was detected\n");
		//gDeviceAvailable = 1;
	}
		break;

	case NW_EVENT_DEVICE_REMOVED:
		printf("A device was removed\n");
		break;
	}
}


array<NvtlApiWrapper::DeviceDetailManaged^>^ NvtlApiWrapper::ApiWrapper::GetAvailableDevices()
{
	unsigned long devlistSize = 5;
	memset(_device_list, 0, 5 * sizeof(DeviceDetail));
	_sdk->GetAvailableDevices(_device_list, &devlistSize);
	return nullptr;
	///TODO:
}
/*   //Check to see if SDK loaded okay
if( !sdk.IsLoaded() )
{
printf("SDK unavailable, aborting\n");
return 0;
}

//create a session with the dll so we can access devices
printf("Creating an SDK session\n");
rval = sdk.CreateSession();

//Setup an event callback handler to receive events
printf("Registering SDK callback\n");
cb.user_data = 0;
cb.event_func = EventHandler;
rval = sdk.RegisterEventCallback( cb );*/

	