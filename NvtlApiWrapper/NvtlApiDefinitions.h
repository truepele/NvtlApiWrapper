/**
*
* Copyright 2008 Novatel Wireless Inc.
*
*/

#if !defined (_NVTL_API_DEFS_H_)
#define _NVTL_API_DEFS_H_


/** \file
SDK header file that contains most commonly used definitions and enumerations.
*/

//////////////////////////////////////////////////////////////////////////////////////////
//Error Code Definitions
//////////////////////////////////////////////////////////////////////////////////////////
/// \def LR_ERROR_SUCCESS
/// Indicates an operation was successful
#define	LR_ERROR_SUCCESS					0x0000

/// \def LR_ERROR_UNKNOWN
/// Indicates an operation failed for an unknown reason
#define	LR_ERROR_UNKNOWN					0x0001

/// \def LR_ERROR_BAD_CMD
/// Indicates an operation failed because device did not recognize it
#define	LR_ERROR_BAD_CMD					0x0002

/// \def LR_ERROR_BAD_PARAM
/// Indicates an operation failed because a parameter was missing or invalid
#define LR_ERROR_BAD_PARAM					0x0003

/// \def LR_ERROR_BAD_LEN
/// Reserved. Indicates an error in communication with device
#define LR_ERROR_BAD_LEN					0x0004

/// \def LR_ERROR_BAD_SEC_MODE
/// Reserved. Indicates an error in communication with device
#define	LR_ERROR_BAD_SEC_MODE				0x0005

/// \def LR_ERROR_PORT_NOT_OPEN
/// Indicates an operation failed because the COM port was not open or valid
#define LR_ERROR_PORT_NOT_OPEN				0x0006

/// \def LR_ERROR_TIMED_OUT
/// Indicates an operation failed due to a timeout
#define	LR_ERROR_TIMED_OUT					0x0007

/// \def LR_ERROR_INVALID_PARAM
/// Indicates an operation failed because a parameter was missing or invalid
#define LR_ERROR_INVALID_PARAM				0x0008

/// \def LR_ERROR_WRITE_FAILED
/// Indicates an operation failed because a write to the COM port failed
#define LR_ERROR_WRITE_FAILED				0x0009

/// \def LR_ERROR_DATA_CORRUPT
/// Indicates that a response from FW could not be decoded
#define LR_ERROR_DATA_CORRUPT				0x000B

/// \def LR_ERROR_MODE_CHANGE_FAILED
/// Indicates an error changing the current mode of the device.
#define LR_ERROR_MODE_CHANGE_FAILED			0x000C

/// \def LR_ERROR_BUFFER_TOO_SMALL
/// Indicates an operation failed because a supplied buffer was too small to receive the response
#define LR_ERROR_BUFFER_TOO_SMALL			0x000D

/// \def LR_ERROR_PORT_OPEN_FAILED
/// Indicates that the COM port to the deivce could not be opened
#define LR_ERROR_PORT_OPEN_FAILED			0x000F

/// \def LR_ERROR_PORT_ALREADY_OPEN
/// Indicates that the desired COM port is already in use
#define LR_ERROR_PORT_ALREADY_OPEN			0x0011

/// \def LR_ERROR_INTERNAL_ERROR
/// Indicates an internal error trying to issue a command to FW
#define LR_ERROR_INTERNAL_ERROR				0x0013

/// \def LR_ERROR_API_NOT_SUPPORTED
/// Indicates an operation was not supported for the given device.
/// Usually due to an operation not being supported for the technology type of the device in use
#define LR_ERROR_API_NOT_SUPPORTED			0x0014

/// \def LR_ERROR_BAD_SPC_MODE
/// Reserved. Indicates an error in communication with device
#define LR_ERROR_BAD_SPC_MODE				0x0015

/// \def LR_ERROR_DEVICE_NOT_AVAILABLE			
/// Inidicates that no device is available to perform the operation on
#define LR_ERROR_DEVICE_NOT_AVAILABLE		0x001B

/// \def LR_ERROR_ACTIVATION_FAILED			
/// Inidicates an failure during activation
#define LR_ERROR_ACTIVATION_FAILED		    0x001D

/// \def LR_ERROR_AT_CMD_ERROR_RESPONSE			
/// Indicates an AT command resulted in an 'ERROR' response
#define LR_ERROR_AT_CMD_ERROR_RESPONSE		0x0030

/// \def LR_ERROR_DEVICE_ALREADY_LOCKED			
/// Indicates that the device was already locked when attempting to lock it.
#define LR_ERROR_DEVICE_ALREADY_LOCKED		0x0031

/// \def LR_ERROR_DEVICE_ALREADY_UNLOCKED		
/// Indicates that the device was already unlocked when attempting to unlock it.
#define LR_ERROR_DEVICE_ALREADY_UNLOCKED	0x0032

/// \def LR_ERROR_INVALID_LOCK_CODE			
/// Indicates that the supplied lock code was invalid.
#define LR_ERROR_INVALID_LOCK_CODE			0x0033

/// \def LR_ERROR_INVALID_ACTIVATION_CODE			
/// Indicates that the supplied activation code was invalid.
#define LR_ERROR_INVALID_ACTIVATION_CODE	0x0034

/// \def LR_ERROR_OPERATION_NOT_ALLOWED			
/// Indicates that the operation was not permitted, most likely due to the current
/// state of the device.
#define LR_ERROR_OPERATION_NOT_ALLOWED		0x0035

/// \def LR_ERROR_AT_CMD_ERROR_SIM_BUSY	
/// Indicates that an AT command resulted in a 'SIM BUSY' response
#define LR_ERROR_AT_CMD_ERROR_SIM_BUSY		0x0036

/// \def LR_ERROR_INVALID_RESPONSE			
/// Reserved. Indicates an error in communication with device
#define LR_ERROR_INVALID_RESPONSE			0x0037

/// \def LR_ERROR_SMS_SENDING		
/// Indicates a failure to send an sms message
#define LR_ERROR_SMS_SENDING				0x0038

/// \def LR_ERROR_BAD_MODE			
/// Reserved. Indicates an error in communication with device
#define LR_ERROR_BAD_MODE					0x0040

/// \def LR_ERROR_NO_MEMORY				
/// Indicates an error due to insufficient memory
#define LR_ERROR_NO_MEMORY					0x0042

/// \def LR_ERROR_FILE_OPEN
/// Indicates an error opening a file on EFS
#define LR_ERROR_FILE_OPEN                  0x0044

/// \def LR_ERROR_FILE_WRITE
/// Indicates an error writing a file to EFS
#define LR_ERROR_FILE_WRITE                 0x0045

/// \def LR_ERROR_FILE_READ
/// Indicates an error reading a file from EFS
#define LR_ERROR_FILE_READ                  0x0046

/// \def LR_ERROR_FILE_STAT
/// Indicates an error reading a stat information from EFS
#define LR_ERROR_FILE_STAT                  0x0047

/// \def LR_ERROR_SERVER_NOT_AVAILABLE
/// Indicates that the SDK Server component was unavailable.
#define LR_ERROR_SERVER_NOT_AVAILABLE       0x0048

/// \def LR_ERROR_PARAM_TOO_LARGE
/// Indicates that a supplied parameter exceeded the allowed size.
#define LR_ERROR_PARAM_TOO_LARGE            0x0049

/// \def LR_ERROR_MISSING_BUNDLE_ID
/// Mac OS X only, indicates an application bundle identifier could not be found.
/// This can be due to a missing Info.plist file or a missing entry for CFBundlerIdentifier in the Info.plist file.
/// This application is setting is required to establish application priviledges for creating and modifying 3G network services
#define LR_ERROR_MISSING_BUNDLE_ID          0x0050

/// \def LR_ERROR_OEM_SWITCH
/// Indicates that the power mode is being controlled by a hardware switch
#define LR_ERROR_OEM_SWITCH                 0x0051

/// \def LR_ERROR_UNKNOWN_HOST
/// Indicates that an internet host name could not be resolved.
#define LR_ERROR_UNKNOWN_HOST				0x1007		//server host name can not be resolved

/// \def LR_ERROR_HOST_UNREACHABLE
/// Indicates that a connection to an internet host could not be created.
#define LR_ERROR_HOST_UNREACHABLE			0x1008		//server host not available

/// \def LR_ERROR_GPS_XTRA_FILE_DOWNLOAD
/// Indicates a filure to download the XTRA data file for GPS.
#define LR_ERROR_GPS_XTRA_FILE_DOWNLOAD		0x1009		//XTRA File Download Error

/// \def LR_ERROR_GPS_XTRA_FILE_WRITE
/// Indicates a failure to write the XTRA data file to the device.
#define LR_ERROR_GPS_XTRA_FILE_WRITE		0x100A		//XTRA File Write Error

/// \def LR_ERROR_GPS_TIME_SYNC_PENDING
/// Indicates that the GPS engine is waiting for a time synchronization when using XTRA mode gps.
#define LR_ERROR_GPS_TIME_SYNC_PENDING		0x100B		//Time Sync is pending. Used for Internet-Assisted GPS

//Error Codes - End

//size definitinos
/// \def NW_SIZE_NAME
/// Defines the basic size in characters of name fields
#define NW_SIZE_NAME				64

/// \def NW_SIZE_NUMBER
/// Defines the basic size in characters of number fields
#define NW_SIZE_NUMBER				22

/// \def NW_ACTIVATION_CODE_SIZE
/// Defines the basic size in characters of spc code fields
#define	NW_ACTIVATION_CODE_SIZE		7

/// \def MAX_PDU_LENGTH
/// Defines the max size in bytes of encoded PDU values
#define MAX_PDU_LENGTH				200

/// \def STRING_LEN
/// Defines the basic size in characters of string fields
#define STRING_LEN                  260

/// \def NW_MAX_PATH
/// Defines the basic size in characters of string fields
#define NW_MAX_PATH                 260

/// \def SdkHandle
/// Defines the handle type used to reference sdk sessions
#define SdkHandle	void*



#pragma pack(push, 1)

namespace NvtlApiWrapper
{
/*******************************************************************
Physical Device Types
Types related to physicaal device technology and platform attributes
********************************************************************/

/// \enum DeviceTechType
/// This enum defines the available device technology types
public enum class DeviceTechType
{
	DEV_NONE		= 0,        /*!< Unkown device type */
	DEV_EVDO		= 4,        /*!< Evdo device */
	DEV_UMTS		= 7,	    /*!< UMTS device */
	DEV_HSDPA		= 8,        /*!< HSPA device */    
	DEV_EVDO_REVA	= 9,        /*!< Evdo REV-A device */
};

/// \enum SourceBuildBaseType 
/// This enum defines the base hardware platform
public enum class SourceBuildBaseType
{
	SRC_BUILD_BASE_UNKNOWN	 = 0,   /*!< Place Holder */
	SRC_BUILD_BASE_BLACKBIRD = 1,   /*!< Place Holder */
	SRC_BUILD_BASE_RAPTOR	 = 2,   /*!< Place Holder */
	SRC_BUILD_BASE_HSDPA	 = 3,   /*!< Place Holder */
	SRC_BUILD_BASE_HSDPA_7_2 = 4,   /*!< Place Holder */
    SRC_BUILD_BASE_HSDPA_3_6 = 5,   /*!< Place Holder */
};

/// \enum DeviceMobModelType
/// This enum defines the chipset model of the device
public enum class DeviceMobModelType
{
	DEV_MOB_MODEL_6500		    = 153,  /*!< Place Holder */
	DEV_MOB_MODEL_6800		    = 238,  /*!< Place Holder */
	DEV_MOB_MODEL_6800_65NM	    = 172,  /*!< Place Holder */
	DEV_MOB_MODEL_6085			= 119,  /*!< BLUE Device  */
	DEV_MOB_MODEL_HSDPA_XU870	= 209,  /*!< Place Holder */
	DEV_MOB_MODEL_HSDPA_U730	= 226,  /*!< Place Holder */
};


/// \enum DeviceFormFactorType
/// This enum defines the physical form factor of the device
public enum class DeviceFormFactorType
{
	DEV_TYPE_PC_CARD			= 0,    /*!< Place Holder */
	DEV_TYPE_MINI_PCI			= 1,    /*!< Place Holder */
	DEV_TYPE_EXPRESS_CARD		= 2,    /*!< Place Holder */
	DEV_TYPE_SM_BUS_MINI_PCI	= 3,    /*!< Place Holder */
	DEV_TYPE_GOBI_MINI_PCI		= 4,    /*!< Place Holder */
    DEV_TYPE_USB                = 5,    /*!< Place Holder */
    DEV_TYPE_MIFI               = 6,    /*!< Place Holder */
	DEV_TYPE_GOBI2_MINI_PCI		= 7,    /*!< Place Holder */
    DEV_TYPE_VIA_USB            = 8,    /*!< Place Holder */
};

#define IsGobi(ffactor)  ( (ffactor) == DEV_TYPE_GOBI_MINI_PCI || (ffactor) == DEV_TYPE_GOBI2_MINI_PCI )
#define IsGobi1(ffactor) ( (ffactor) == DEV_TYPE_GOBI_MINI_PCI ) 
#define IsGobi2(ffactor) ( (ffactor) == DEV_TYPE_GOBI2_MINI_PCI )
#define IsVia(ffactor) ( (ffactor) == DEV_TYPE_VIA_USB )

/// \enum ServiceProviderType
/// For CDMA device this enum defines the carrier this device was originally provisioned for.
public enum class ServiceProviderType
{
	SRV_PROVIDER_UNKNOWN	= 0,        /*!< Unknown provider */
	SRV_PROVIDER_SPRINT		= 1,        /*!< Sprint */
	SRV_PROVIDER_VERIZON	= 2,        /*!< Verizon */
	SRV_PROVIDER_TELUS		= 3,        /*!< Telus */
	SRV_PROVIDER_BELL_MOBILITY = 4,     /*!< Bell Mobility */
	SRV_PROVIDER_RADIO_FREE = 5,        /*!< Radio Free */
	SRV_PROVIDER_MAX,                   /*!< Place Holder */
};
/*******************************************************************
End Physical Device Types
********************************************************************/


/*******************************************************************
State and Network related types
Types related to device and network state
********************************************************************/

//power mode of the device

/// \enum DeviceModeType
/// This enum defines values for the power mode of the device.


public enum class DeviceModeType
{
	DEV_MODE_MIN = 0,    /*!< Place holder */
	DEV_MODE_POWER_OFF = 0,    /*!< <tt><b>(not used)</b></tt> */
	DEV_MODE_FTM = 1,    /*!< Offline Factory Test Mode */
	DEV_MODE_OFFLINE = 2,    /*!< <tt><b>(not used)</b></tt> */
	DEV_MODE_OFFLINE_A = 3,    /*!< <tt><b>(not used)</b></tt> Offline Analog Mode for legacy networks */
	DEV_MODE_OFFLINE_D = 4,	/*!< Offline Digital mode */
	DEV_MODE_ONLINE = 5,   	/*!< Online mode; in this mode, the mobile can acquire the system and make calls */
	DEV_MODE_LPM = 6,    /*!< Low Power mode; in this mode, the device is disabled and will be in least power consumption and will neither attempt any acquisitions nor be on a system */
	DEV_MODE_MAX,               /*!< Place Holder */
	DEV_MODE_UNKNOWN = 99,   /*!< Unknown mode */
	DEV_MODE_RESET = 100,  /*!< Resets the device if currently in offline mode */
};

/// \enum DeviceLockStatusType
/// This enum defines values for current lock status of the device
public enum class DeviceLockStatusType
{
	DEV_UNLOCKED = 0,	/*!< Device is not locked */
	DEV_LOCKED = 1,	/*!< <tt><b>\<CDMA/EVDO devices only\></b></tt> The device is locked */
	DEV_NETWORK_LOCKED = 2,	/*!< <tt><b>\<UMTS and HSDPA devices only\></b></tt> The device is network locked. This means that the device disallows use of the particular SIM that is inserted.*/
	DEV_PIN1_LOCKED = 3,	/*!< <tt><b>\<UMTS and HSDPA devices only\></b></tt> The SIM is PIN locked. PIN number is required to unlock the SIM. */
	DEV_PIN2_LOCKED = 4,	/*!< <tt><b>\<UMTS and HSDPA devices only\></b></tt> The SIM is PIN2 locked. PIN2 number is required to unlock the SIM. */
	DEV_PUK1_LOCKED = 5,	/*!< <tt><b>\<UMTS and HSDPA devices only\></b></tt> The SIM is PUK locked. PUK code is required to unlock the SIM */
	DEV_PUK2_LOCKED = 6,	/*!< <tt><b>\<UMTS and HSDPA devices only\></b></tt> The SIM is PUK2 locked. PUK2 code is required to unlock the SIM */
	DEV_SIM_FAILURE = 7,	/*!< <tt><b>\<UMTS and HSDPA devices only\></b></tt> Failure in communicating with the SIM */
	DEV_AUTOLOCKED = 0x80 	/*!< <tt><b>\<not used\></b></tt> */
};

/// \enum DeviceLockType
/// This enum defines values for the type of lock currently applied on the device
public enum class DeviceLockType
{
	DEV_LOCK		= 0,	/*!< <tt><b>\<CDMA/EVDO devices only\></b></tt> Unlock the device */
	DEV_NET_LOCK	= 1,	/*!< <tt><b>\<UMTS and HSDPA devices only\></b></tt> Unlock Network Lock */
	DEV_PIN1_LOCK	= 2,	/*!< <tt><b>\<UMTS and HSDPA devices only\></b></tt> Unlock PIN1 Lock */
	DEV_PIN2_LOCK	= 3,	/*!< <tt><b>\<UMTS and HSDPA devices only\></b></tt> Unlock PIN2 Lock */
	DEV_PUK1_LOCK	= 4,	/*!< <tt><b>\<UMTS and HSDPA devices only\></b></tt> Unlock PUK Lock */
	DEV_PUK2_LOCK	= 5,	/*!< <tt><b>\<UMTS and HSDPA devices only\></b></tt> Unlock PUK2 Lock */
	DEV_AUTOLOCK	= 6		/*!< <tt><b>\<UMTS and HSDPA devices only\></b></tt> Unlock Auto-Lock */
} ;

/// \enum DeviceStateType
/// This enum defines values for the current working state of the device
public enum class DeviceStateType
{
    NW_DEVICE_STATE_UNKNOWN         = 0,  /*!< The state of device cannot be determined. Usually sent during startup of the SDK. */
    NW_DEVICE_STATE_NOCARD          = 1,  /*!< No device has been detected */
    NW_DEVICE_STATE_INITIALIZING    = 2,  /*!< The SDK has recognized a device and is currently in the process of connecting to and initializing it for use. 
    									   * Generally the device is not yet ready for normal operation and clients should wait until the SDK leaves this state before proceeding. */
    NW_DEVICE_STATE_DISABLED        = 3,  /*!< Indicates that a valid device is detected but is disabled. This is generally due to a software or hardware control switch being turned off on the host. */
    NW_DEVICE_STATE_LOCKED          = 4,  /*!< Indicates that a device is detected but is currently locked and requires a PIN or PUK to be entered before use. */
    NW_DEVICE_STATE_SEARCHING       = 5,  /*!< Indicates that the device is available and is currently searching for network service. */
    NW_DEVICE_STATE_IDLE            = 6,  /*!< Indicates that the device is available for general use. This state indicates the normal ready state of the device. */
    NW_DEVICE_STATE_CONNECTING      = 7,  /*!< A connection attempt has been made and the device is trying to establish a data connection. */
    NW_DEVICE_STATE_AUTHENTICATING  = 8,  /*!< A connection attempt has been made and the device is authenticating user credentials for the data connection. */
    NW_DEVICE_STATE_CONNECTED       = 9,  /*!< Indicates that the device has an active data connection */
    NW_DEVICE_STATE_RESERVED_2      = 10, /*!< <tt><b>(not used)</b></tt> */
    NW_DEVICE_STATE_ACTIVATION      = 11, /*!< <tt><b>(not used)</b></tt> */
    NW_DEVICE_STATE_NULL            = 0xFF /*!< <tt><b>(not used)</b></tt> */
};

/// \enum DeviceRoamStatusType
/// This enum define svalues for the Roaming Stauts of the device.
public enum class DeviceRoamStatusType
{
	DEVICE_STATUS_HOME		 = 0,	/*!< The device is currently on the home network */
	DEVICE_STATUS_ROAM		 = 1,	/*!< The device is currently roaming away from the home network */
	DEVICE_STATUS_ROAM_FLASH = 2,	/*!< The device is currently roaming away from the home network and the connection manager should flash the roaming indication icon */
	DEVICE_STATUS_ERI		 = 3	/*!< The device is currently roaming away from the home network and the connection manager should follow the appropriate rules based
										* on the ERI (Extended Roaming Indicator) information. */
};

/// \enum RoamIndicatorType
/// <tt><b>\<CDMA/EVDO devices only\></b></tt>
/// \n This enum defines values for roaming indication icon's index
public enum class RoamIndicatorType
{
	ROAM_INDICATOR_OFF					= 0,    /*!< Roaming indicator should be off */
	ROAM_INDICATOR_ON					= 1,    /*!< Roaming indicator shoudd be on */
	ROAM_INDICATOR_FLASH				= 2,    /*!< Roaming indicator should be flashing */    
	ROAM_INDICATOR_CUSTOM_IMAGE_ON		= 3,    /*!< Custom roaming indicator image should be on*/
	ROAM_INDICATOR_CUSTOM_IMAGE_FLASH	= 4     /*!< Custom roaming indicator image should be flashing */
};

/// \enum DeviceServiceType
/// This enum defines the type of Network Service that the device is attached to.
public enum class DeviceServiceType
{
	NW_SERVICE_NONE = 0,	/*!< No network */
	NW_SERVICE_AMPS,		/*!< Network Service type AMPS (Advanced Mobile Phone Service) */
	NW_SERVICE_IS95A,		/*!< Network Service type IS95A (Interim Standard A) */
	NW_SERVICE_IS95B,		/*!< Network Service type IS95B (Interim Standard B) */
	NW_SERVICE_GPRS,		/*!< Network Service type GPRS (General Packet Radio Service) */
	NW_SERVICE_1XRTT,		/*!< Network Service type 1XRTT */
	NW_SERVICE_EVDO,		/*!< Network Service type EV-DO (Evolution Data Optimized) */
	NW_SERVICE_UMTS,		/*!< Network Service type UMTS (Universal Mobile Telecommunications System) */
	NW_SERVICE_HSDPA,		/*!< Network Service type HSDPA (High Speed Downlink Packet Access) */
	NW_SERVICE_EDGE,		/*!< Network Service type EDGE (Enhanced Data rates for Global Evolution) */
	NW_SERVICE_EVDO_REVA,	/*!< Network Service type EV-DO REV A */
	NW_SERVICE_HSUPA,		/*!< Network Service type HSUPA (High Speed Uplink Packet Access) */
	NW_SERVICE_HSPA_PLUS,	/*!< Network Service type HSPA+ (Evovled High Speed Packet Access) */
};

/// \enum DeviceDisableActionType
/// This enum defines values that identify the cause for why a device is disabled or in Low Power Mode. 
public enum class DeviceDisableActionType
{
    NW_WD_ACTION_HW_DISABLE			= 0,    /*!< Place hodler */
    NW_WD_ACTION_SW_DISABLE			= 1,    /*!< Place hodler */
    NW_WD_ACTION_TEMPRATURE_DISABLE = 2,    /*!< Place hodler */
};

/// \enum DeviceDisableMaskType
/// This enum defines values that identify the cause for why a device is disabled or in Low Power Mode.
public enum class DeviceDisableMaskType
{
    NW_WD_MASK_HW_DISABLE		  = 0x0001,	/*!< The hardware control switch is turned off */
    NW_WD_MASK_SW_DISABLE		  = 0x0002,	/*!< The device is software disabled */
    NW_WD_MASK_TEMPRATURE_DISABLE = 0x0004,	/*!< The device is disabled because it has reached unsafe temperature levels */
};

/// \enum RoamPreferenceType
/// This enum defines values for the roam preferences for the device.
public enum class RoamPreferenceType
{
    NW_ROAM_PREF_HOME	= 1,	/*!< Home only */
	NW_ROAM_PREF_AFFIL	= 3,	/*!< Affilated networks only */
	NW_ROAM_PREF_ROAM	= 6,	/*!< Roam Only */
	NW_ROAM_PREF_ANY	= 255	/*!< Automatic */
};

/// \enum NetworkModePreference
/// <tt><b>\<CDMA/EVDO devices only\></b></tt>
/// \n This enum defines values for the preferred network mode
public enum class NetworkModePreference
{ 
    NW_MODE_DIGITAL_PREF          = 0,  /*!< CDMA then Analog */
    NW_MODE_DIGITAL_ONLY          = 1,  /*!< CDMA only */
    NW_MODE_ANALOG_PREF           = 2,  /*!< Analog then CDMA */
    NW_MODE_ANALOG_ONLY           = 3,  /*!< Analog only */
    NW_MODE_AUTOMATIC             = 4,  /*!< Mode is determined automatically */
    NW_MODE_E911                  = 5,  /*!< Emergency mode */
    NW_MODE_HOME_ONLY             = 6,  /*!< Restrict to home only */
    NW_MODE_PCS_CDMA_ONLY         = 7,  /*!< Restrict to PCS home only */
    NW_MODE_CELL_CDMA_ONLY        = 8,  /*!< Restrict to cellular home only */
    NW_MODE_CDMA_ONLY             = 9,  /*!< Place hodler */
    NW_MODE_HDR_ONLY              = 10, /*!< Place hodler */
    NW_MODE_CDMA_AMPS_ONLY        = 11, /*!< Place hodler */
    NW_MODE_GPS_ONLY              = 12, /*!< Place hodler */
    NW_MODE_GSM_ONLY              = 13, /*!< Restrict to GSM only */
    NW_MODE_WCDMA_ONLY            = 14, /*!< Restrict to WCDMA only */
};

/// \enum RatModePreference
/// <tt><b>\<UMTS/HSPA devices only\></b></tt>
/// \n This enum defines values for the preferred radio access technology (RAT) mode
public enum class RatModePreference
{
    NW_RAT_MODE_AUTO    = 0,
    NW_RAT_MODE_GSM     = 1,
    NW_RAT_MODE_WCDMA  = 2,
};

/// \enum DisableEventSigType
/// This enum is used internally
public enum class DisableEventSigType
{
	W_DISABLE_SIG_LPM			 = 0,   /*!< Place hodler */
	W_DISABLE_SIG_ONLINE_ATTEMPT = 1    /*!< Place hodler */
} ;
/*******************************************************************
END State and Network related types
********************************************************************/

/*******************************************************************
EVDO configuration and setting related types
Types related to EVDO settings 
********************************************************************/

/// \enum SysPrevType
/// <tt><b>\<CDMA/EVDO devices only\></b></tt> \n
/// This enum defines values for the Protocol Revision (PREV) preference.
public enum class SysPrevType
{
	PREV_CDMA_JSTD008		= 1,	/*!< PREV JSTD008 */
	PREV_CDMA_95A			= 2,	/*!< <tt><b>(not used)</b></tt> */
	PREV_CDMA_95A_TSB74		= 3,	/*!< PREV TSB74 */
	PREV_CDMA_95B_PHASE1	= 4,	/*!< <tt><b>(not used)</b></tt> */
	PREV_CDMA_95B_PHASE2	= 5,	/*!< <tt><b>(not used)</b></tt> */
	PREV_CDMA_2000_REL0		= 6,	/*!< PREV REL0 */
	PREV_CDMA_2000_RELA		= 7		/*!< <tt><b>(not used)</b></tt> */
} ;

/// \enum PreferredModeType
/// <tt><b>\<CDMA/EVDO devices only\></b></tt> \n
/// This enum defines values for the preferred network mode.
public enum class PreferredModeType
{
	NV_PREF_MODE_DIGITAL_PREF	= 0,	/*!< CDMA then Analog */
	NV_PREF_MODE_DIGITAL_ONLY	= 1,	/*!< CDMA only */
	NV_PREF_MODE_ANALOG_PREF	= 2,	/*!< Analog then CDMA */
	NV_PREF_MODE_ANALOG_ONLY	= 3,	/*!< Analog only */
	NV_PREF_MODE_AUTOMATIC		= 4,	/*!< Mode is determined automatically */
	NV_PREF_MODE_E911			= 5,	/*!< Emergency mode */
	NV_PREF_MODE_HOME_ONLY		= 6,	/*!< Restrict to home only */
	NV_PREF_MODE_PCS_CDMA_ONLY	= 7,    /*!< Place hodler */
	NV_PREF_MODE_CELL_CDMA_ONLY	= 8,    /*!< Place hodler */
	NV_PREF_MODE_CDMA_ONLY		= 9,    /*!< Place hodler */
	NV_PREF_MODE_HDR_ONLY		= 10,   /*!< Place hodler */
	NV_PREF_MODE_CDMA_AMPS_ONLY	= 11,   /*!< Place hodler */
	NV_PREF_MODE_GPS_ONLY		= 12,   /*!< Place hodler */
	NV_PREF_MODE_GSM_ONLY		= 13,   /*!< Place hodler */
	NV_PREF_MODE_WCDMA_ONLY		= 14    /*!< Place hodler */
};

/// \enum SystemPreferenceType
/// This enum defines values for system preference
public enum class SystemPreferenceType
{
	NV_SYS_PREF_A_ONLY		= 0,	/*!< System A only */
	NV_SYS_PREF_B_ONLY		= 1,	/*!< System B only */
    NV_SYS_PREF_HOME_ONLY	= 2,	/*!< Home only */
    NV_SYS_PREF_STANDARD	= 3		/*!< Home preferred */    
};

/// \enum HdrProtocolType
/// <tt><b>\<CDMA/EVDO devices only\></b></tt> \n
/// This enum defines values for the type of HDR protocol. 
public enum class HdrProtocolType
{
	CFG_HDR_PROTOCOL_UNKNOWN = 0,	/*!< Current HDR protocol could not be defined */
	CFG_HDR_PROTOCOL_REV0	 = 1,	/*!< REV 0 protocol */
	CFG_HDR_PROTOCOL_REVA	 = 2,	/*!< REV A protocol */
} ;

/// \enum BandPreferenceType
/// <tt><b>\<CDMA/EVDO devices only\></b></tt> \n
/// This enum defines values for the band class preference
public enum class BandPreferenceType
{
	NV_BAND_PREF_CELL		= 3,	/*!< Band class CELL */
	NV_BAND_PREF_PCS		= 4,	/*!< Band class PCS */
	NV_BAND_PREF_AUTOMATIC  = 65535	/*!< Determine band class automatically */
} ;

/// \enum MipQcmipType
/// <tt><b>\<CDMA/EVDO devices only\></b></tt> \n
/// This enum defines modes for Mobile IP (MIP) behaviour.
public enum class MipQcmipType
{
	NV_MIP_QCMIP_MIP_DISABLED	= 0,	/*!< Device uses Simple IP only */
	NV_MIP_QCMIP_MIP_PREFERRED  = 1,	/*!< Device uses Mobile IP with fallback to Simple IP */
	NV_MIP_QCMIP_MIP_ONLY		= 2		/*!< Device uses Mobile IP only */
} ;

/// \enum BATTERY_STATE
///This enum defines values that describe the state of the device's battery.  These values are used with SDK method Phoenix::IPhoenix::GetBatteryInfo.
public enum class BATTERY_STATE 
{
	BATTERY_POWERED = 0,	/*!< Battery is present; Powered by battery. */
	BATTERY_EXTERNAL_POWER = 1,	/*!< Battery is present; Powered by external source. */
	BATTERY_UNAVAILABLE = 2,	/*!< Battery is absent. */
} ;

/*******************************************************************
END EVDO configuration and setting related types
********************************************************************/

/*******************************************************************
EVDO activation related types
Types related to EVDO activation
********************************************************************/

/// \enum OmaType
/// This enum defnes the type of OMA-DM sessions available for use with OMA-DM methods.
public enum class OmaType
{
	OMA_TYPE_DM             = 0, /*!< OMA-DM session for device activation */
	OMA_TYPE_PRL            = 1, /*!< OMA-DM session for PRL updates */
    OMA_TYPE_HFA            = 2, /*!< Hands Free Activation sesson */
    OMA_TYPE_FUMO_QUERY		= 3, /*!< Query for firmware update */
	OMA_TYPE_FUMO_UPDATE	= 4, /*!< FUMO session for firmware update */
    OMADI_TYPE_HFA          = 5, /*!< GOBI Only. Device Initiated Hands Free Activation sesson */
    OMANI_TYPE_PRL          = 6, /*!< GOBI Only. Network Initiated session for PRL updates */
    OMANI_TYPE_DM           = 7, /*!< GOBI Only. Network Initiated session for device activation */
    OMA_TYPE_FUMO_UPDATE_NOW = 8, /*!< Bell Mobility. Update now */
    OMA_TYPE_FUMO_UPDATE_LATER = 9, /*!< Bell Mobility. Update later, within 24 hours */
    OMA_TYPE_FUMO_UPDATE_OK = 10, /*!< Bell Mobility. Update is okay to happen now */
};

/// \enum OmaState
/// This enum defines values for the state of OMADM subsystem.
public enum class OmaState
{
	OMA_DM_DISABLED 				= 0x00, /*!< OMA-DM based device activation is disabled */
	OMA_PRL_DISABLED				= 0x01, /*!< OMA-DM based PRL update is disabled */
	OMA_PRL_DM_DISABLED 			= 0x02, /*!< <tt><b>(not used)</b></tt> */
	OMA_IDLE						= 0x03, /*!< OMA-DM subsystem is waiting for command from the network or client application */
	HFA_IN_PROGRESS 				= 0x04,	/*!< HFA has been started and is in progress */
	HFA_IN_RETRY					= 0x05,	/*!< <tt><b>(not used)</b></tt> */
	HFA_IDLE						= 0x06,	/*!< <tt><b>(not used)</b></tt> */
	CIDC_IN_PROGRESS				= 0x07,	/*!< OMA-DM based Device Activation session is in progress- \e Client Initiated */
	NIDC_IN_PROGRESS				= 0x08, /*!< OMA-DM based Device Activation session is in progress- \e Network Initiated */
	CIPRL_IN_PROGRESS				= 0x09, /*!< OMA-DM based PRL update session is in progress- \e Client Initiated */
	NIPRL_IN_PROGRESS				= 0x0A,	/*!< OMA-DM based PRL update session is in progress- \e Network Initiated */
	ABORT_IN_PROGRESS				= 0x0B,	/*!< Current OMA-DM session is being aborted */
	
	OMA_NULL_STATE					= 0x0C,	/*!< Place holder */
	OMA_FUMO_DISABLED				= 0x0D,	/*!< OMA-DM based firmware update is disabled */ 
	FUMO_IN_PROGRESS				= 0x0E, /*!< OMA-DM based firmware update session is in progress*/
	FUMO_IDLE                       = 0x0F, /*!< FUMO session is complete. */
	
	OMA_STATE_ENUM_MAX				= 0x0F,
};

/// \enum OmaStatus
///This enum defines values for OMA-DM specific error codes. 
public enum class OmaStatus
{
	OMA_SUCCESS 					= 0x00, /*!< Operation succeeded */
	OMA_ERR_NO_REASON				= 0x01, /*!< Unknown error code */
	OMA_ERR_PROFILE_UNAVAILABLE 	= 0x02, /*!< There is no data available in Profile 0 */
	OMA_ERR_INVALID_CREDENTIALS 	= 0x03,	/*!< The server rejected the user credentials for this OMA-DM session */
	OMA_ERR_SERVER_UNREACHABLE		= 0x04,	/*!< The device cannot find the server */
	OMA_ERR_NETWORK_UNAVAILABLE 	= 0x05,	/*!< No network is available */
	OMA_ERR_DM_DISABLED 			= 0x06,	/*!< OMA-DM based device activation is disabled */
	OMA_ERR_PRL_DISABLED			= 0x07,	/*!< OMA-DM based PRL update is disabled */
	OMA_ERR_PRL_DM_DISABLED 		= 0x08, /*!< <tt><b>(not used)</b></tt> */
	OMA_ERR_FEATURE_DM_DISABLED 	= 0x09,	/*!< The device is not capable of OMA-DM based activation */
	OMA_ERR_FEATURE_PRL_DISABLED	= 0x0A,	/*!< The device is not capable of OMA-DM based PRL update */
	
	OMA_NULL_STATUS 				= 0x0B,	/*!< Place holder */
	OMA_ERR_FEATURE_FUMO_DISABLED	= 0x0C,	/*!< OMA-DM based firmware update is disabled */
	OMA_ERR_FUMO_UPDATE_FAILED		= 0x0D,	/*!< OMA-DM based firmware update failed */
	OMA_ERR_FUMO_UPDATE_PACKAGE		= 0x0E,	/*!< OMA-DM based firmware update package is corrupt */
	
	OMA_STATUS_ENUM_MAX 			= 0x0E,
};

/// \enum OmaExtStatus
///This enum defines values for OMA-DM specific extended status codes
public enum class OmaExtStatus
{
	OMA_ERR_EXT_PLACE_HOLDER		= 0x0000,	/*!< Place Holder */
	HFA_HEARTBEAT					= 0x0001,	/*!< HFA (Hands Free Activation) is in progress and is in-between retires */
	HFA_RETRIES_LEFT				= 0x0002,	/*!< HFA (Hands Free Activation) session has failed but there are retries left */
	HFA_NOT_ALLOWED 				= 0x0003,	/*!< HFA (Hands Free Activation) session has failed and there are no retries left */
	OMA_EVENT_CB_FUNCTION			= 0x0004,	/*!< <tt><b>(reserved internal use)</b></tt> */
	OMA_EVENT_NI_REQUESTED			= 0x0005,	/*!< A network-initiated OMA-DM event has occured */
	OMA_FUMO_UPDL_IN_PROGRESS		= 0x0006,	/*!< Downloading firmware update package from OMADM server */
	OMA_FUMO_UPDL_TOTAL_SIZE		= 0x0007,	/*!< Firmware update package size to be downloaded */
	OMA_FUMO_UPDATE_PACKAGE_AVAILABLE		= 0x0008,	/*!< New firmware update package is available */
	OMA_FUMO_UPDATE_PACKAGE_NOT_AVAILABLE	= 0x0009,	/*!< Firmware update package is not available */
	FUMO_RESET_AFTER_GET_UDP		= 0x000A,	/*!< Resetting modem after firmware update package download complete */
	FUMO_RESET_AFTER_PROGRAMMING	= 0x000B,	/*!< Resetting modem after programming the update package to flash successfully */
	FUMO_NIFUMO_WAP_PUSH			= 0x000C,	/*!< Received NIFUMO ( network initiated FUMO) wap push from server*/
	FUMO_REPORT_UPDATE_STATUS		= 0x000D,	/*!< Reporting firmware update status to server */
	
	OMA_ERR_EXT_NULL				= 0xFFFF,	/*!< Place holder */
};

/// \enum OmaEvent
/// This enum defines events returned by OMA-DM subsystem during an activation or PRL update session. 
public enum class OmaEvent
{
	OMAEVENT_PRLMaxPRLSizeGetFunc,					/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_PRLMaxPRLSizeReplaceFunc,				/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_PRLPrefRoamListGetFunc,				/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_PRLPrefRoamListReplaceFunc,			/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_PRLPRLIDGetFunc,						/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_PRLPRLIDReplaceFunc,					/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_NAMCdmaNamGetFunc,						/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_NAMCdmaNamReplaceFunc,					/*!< The NAM has been replaced and the device shall need a reset once the OMA-DM session is complete */
	OMAEVENT_NAMMobDirNumGetFunc,					/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_NAMMobDirNumReplaceFunc,				/*!< The mobile directory number has been replaced and the device shall need a reset once the OMA-DM session is complete */
	OMAEVENT_Profile1AuthAlgoAAAGetFunc,			/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1AuthAlgoAAAReplaceFunc,		/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1AuthAlgoHAGetFunc,				/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1AuthAlgoHAReplaceFunc,			/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1MobileIpAddressGetFunc,		/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1MobileIpAddressReplaceFunc,	/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1NAIGetFunc,					/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1NAIReplaceFunc,				/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1PasswordAAAGetFunc,			/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1PasswordAAAReplaceFunc,		/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1PasswordHAGetFunc,				/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1PasswordHAReplaceFunc,			/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1PriHAIpGetFunc,				/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1PriHAIpReplaceFunc,			/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1ReverseTunnelingGetFunc,		/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1ReverseTunnelingReplaceFunc, 	/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1SecHAIpGetFunc,				/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1SecHAIpReplaceFunc,			/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1SpiAAAGetFunc,					/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1SpiAAAReplaceFunc,				/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1SpiHAGetFunc,					/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_Profile1SpiHAReplaceFunc,				/*!< <tt><b>(reserved for internal use)</b></tt> */
	OMAEVENT_CBFuntion_MAX							/*!< Place holder */
};

/// Defines an API structure used to convey OMA-DM status information.
public ref class OmaStatusEvent
{
public: 
    unsigned char    state;     /*!< TODO oma state  */
    unsigned char    status;    /*!< TODO oma status */
    unsigned short   extended;  /*!< TODO oma exteneded value */
    unsigned long    data;      /*!< TODO oma data */
};


/// Defines an API structure used when querying the OMA capabilities of a device.
public ref class OmaCapabilityStruct
{ 
public: 

    unsigned char    dm_capable;        /*!< oma dm capable flag  */
    unsigned char    dm_enabled;        /*!< oma dm enabled flag  */
    unsigned char    prl_capable;       /*!< oma prl capable flag */
    unsigned char    prl_enabled;       /*!< oma prl enabled flag */
};

/// \enum ActivationType
/// <tt><b>\<CDMA/EVDO devices only\></b></tt> \n
/// This enum defines the possible activation types that can be performed.
public enum class ActivationType
{
	NW_ACTIVATE_AUTOMATIC		= 0,    /*!< Activation type Automatic. Attempts to determine the appropriate activation type*/
	NW_ACTIVATE_MANUAL			= 1,    /*!< Activation type manual. Device is reset upon successfull activation */
	NW_ACTIVATE_MANUAL_NORESET	= 2,    /*!< Activation type manual, but device is not reset. This is useful when just a single use activation code needs to be validated 
											    or when other methods need to be called before the device is reset. */
	NW_ACTIVATE_MANUAL_NOACTIVATION_CODE = 3, /*!< Just activation information is being provided without the activation code. The activation code was provided earlier in the process. */
	NW_ACTIVATE_OVERRIDE_IOTA	= 4,	/*!< Activation overridden to perform an IOTA activation. Used to force an IOTA activation. No other activation-type checks will be executed. */
	NW_ACTIVATE_OVERRIDE_OTASP	= 5,	/*!< Activation overridden to perform an OTASP activation. Used to force an OTASP activation. No other activation-type checks will be executed. */
} ;


/// \enum ActivationStateType
/// THis enum defines values for the status of the activation process.
public enum class ActivationStateType
{
	NW_ACT_STATUS_UNKNOWN				= 0,	/*!< Status unknown */
	NW_ACT_STATUS_PRGMING_IN_PROGRESS	= 1,	/*!< Activation has begun and device programming is in progress */
	NW_ACT_STATUS_SPL_UNLOCK_OK			= 2,	/*!< <tt><b>(reserved)</b></tt> */
	NW_ACT_STATUS_SPL_UNLOCK_FAILED		= 3,	/*!< <tt><b>(reserved)</b></tt> */
	NW_ACT_STATUS_DLOAD_NAM_OK			= 4,	/*!< <tt><b>(reserved)</b></tt> */
	NW_ACT_STATUS_DLOAD_NAM_FAILED		= 5,	/*!< <tt><b>(reserved)</b></tt> */
	NW_ACT_STATUS_DLOAD_MDN_OK			= 6,	/*!< <tt><b>(reserved)</b></tt> */
	NW_ACT_STATUS_DLOAD_MDN_FAILED		= 7,	/*!< <tt><b>(reserved)</b></tt> */
	NW_ACT_STATUS_DLOAD_IMSI_OK			= 8,	/*!< <tt><b>(reserved)</b></tt> */
	NW_ACT_STATUS_DLOAD_IMSI_FAILED		= 9,	/*!< <tt><b>(reserved)</b></tt> */
	NW_ACT_STATUS_DLOAD_PRL_OK			= 10,	/*!< <tt><b>(reserved)</b></tt> */
	NW_ACT_STATUS_DLOAD_PRL_FAILED		= 11,	/*!< <tt><b>(reserved)</b></tt> */
	NW_ACT_STATUS_COMMIT_SUCCESSFUL		= 12,	/*!< <tt><b>(reserved)</b></tt> */
	NW_ACT_STATUS_COMMIT_FAILED			= 13,	/*!< <tt><b>(reserved)</b></tt> */
	NW_ACT_STATUS_ACTIVATION_SUCCESSFUL	= 14,	/*!< Activation was successfull */
	NW_ACT_STATUS_ACTIVATION_FAILED		= 15,	/*!< Activation Failed */
	NW_ACT_STATUS_WAP_PUSH_IN_PROGRESS	= 16,	/*!< <tt><b>(reserved)</b></tt> */
	NW_ACT_STATUS_RETRY_ATTEMPT			= 17,	/*!< <tt><b>(reserved)</b></tt> */
	NW_ACT_STATUS_COUNT							/*!< Place Holder */
} ;

/// Defines a structure used to provice activation information
public ref class ActivationInfoStruct
{ 
public: 
    unsigned long           dwSize;                     /*!< size of the ActivationInfoStruct */
    ActivationType          eType;                      /*!< Type of activation to perform */
    unsigned char           bAsynchronousActivation;    /*!< Asynchronous flag */
    char^                    szMDN;      /*!< The MDN to activate with (manual only) */	
    char^                    szMIN;      /*!< The MIN to activate with (manual only) */	
    char^                    szActivationCode; /*!< The service programming code for activation */
    unsigned short          dwHomeSID;                  /*!< The Home SID to set (manual only) */
    unsigned long           dwPRLDataSize;              /*!< The size of the PRL data being provided (manual only)*/
    unsigned char           *pPRLData;                  /*!< Pointer to a buffer containing the PRL data to apply */
} ;
/*******************************************************************
END EVDO activation related types
********************************************************************/

/*******************************************************************
GSM related types
********************************************************************/
/// \enum CopsModeType
///<tt><b><UMTS and HSDPA devices only\></b></tt>\n
///This enum defines values for the mode parameter as used with #NvtlGsm_SetNetworkOperator method.
///It denotes the mode for the command AT+COPS that is used internally.
public enum class CopsModeType
{
	COPS_MODE_AUTOMATIC	= 0,	/*!< Automatically select network operator */
	COPS_MODE_MANUAL	= 1,	/*!< Manually select network operator */
	COPS_MODE_DEREGISTER = 2,	/*!< Deregistration from the network */
	COPS_MODE_SET_FORMAT = 3,	/*!< Set \ref _at_cops_format_e_type "format" for read command */
};

/// \enum CopsFormatType
///<tt><b><UMTS and HSDPA devices only\></b></tt>\n
///This enum defines values for the format parameter as used with #NvtlGsm_SetNetworkOperator method.
///It denotes the format for the command AT+COPS that is used internally.
public enum class CopsFormatType
{
	COPS_FORMAT_LONG_ALPHANUMERIC	= 0, /*!< Long alphanumeric format. For e.g. "Orange F" */
	COPS_FORMAT_SHORT_ALPHANUMERIC	= 1, /*!< Short alphanumeric format. For e.g. "Cingular" */
	COPS_FORMAT_NUMERIC				= 2, /*!< Numeric format. For e.g. "310380", for Cingular */
};

/// \enum AccessTechType
///<tt><b><UMTS and HSDPA devices only\></b></tt>\n
///This enum defines values for the access technology parameter as used with the NvtlGsm_SetNetworkOperator method.
///It is used internally with AT+COPS command.
public enum class AccessTechType
{
	ACCESS_TECH_GSM			= 0,	/*!< GSM */
	ACCESS_TECH_GSM_COMPACT	= 1,	/*!< GSM Compact */
	ACCESS_TECH_UTRAN		= 2,	/*!< UMTS Terrestrial Radio Access Network */
	ACCESS_TECH_AUTOMATIC	= 3,	/*!< Automatic selection */
	ACCESS_TECH_NA			= 4,	/*!< Place Holder */
};

/// \enum CopsNetworkStatusType
///<tt><b><UMTS and HSDPA devices only\></b></tt>\n
///This enum defines values for the network status types as returned from the AT+COPS data returned from the GetNetworkOperatorList method.
public enum class CopsNetworkStatusType
{
	COPS_NETWORK_STATUS_UNKNOWN		= 0,
	COPS_NETWORK_STATUS_AVAIAILABLE	= 1,
	COPS_NETWORK_STATUS_CURRENT		= 2,
	COPS_NETWORK_STATUS_FORBIDDEN	= 3
} ;
/*******************************************************************
END GSM related types
*******************************************************************/
/*******************************************************************
Address Book related types
********************************************************************/

/// Defines an API structure used when setting or retrieving a contact from the address book.
public ref class ContactInfoStruct
{ 
public:    
	unsigned long   dwIndex;                            /*!< Index of the contact in the address book */
	char^	        szContactName;   /*!< Name of the contact */
	char^            szContactDetails;   /*!< Phone number of the contact */
} ;

/// Defines an API structure used when querying statistics about the address book.
public ref class ContactSizeInfoStruct
{ 
public: 
	unsigned long	dwMinIndex;             /*!< The mininum valid index in the address book */
	unsigned long	dwMaxIndex;             /*!< The maximum valid index in the address book */
	unsigned long	dwContactNameMax;       /*!< The maximum allowed characters for the name of a contact */
	unsigned long	dwContactDetailsMax;    /*!< The maximum allowed characters for the detail of a contact */
} ;
/*******************************************************************
END Address Book related types
********************************************************************/


/*******************************************************************
SMS related types
********************************************************************/
/// \enum SMSMessageState
/// defines general sms message states
public enum class SMSMessageState
{	
    SMS_STATE_EMPTY	= 60000,        /*!< NULL sms state */
	SMS_STATE_UNREAD,               /*!< sms is unread */
	SMS_STATE_UNREAD_PRIORITY,      /*!< sms is an unread urgent message */
	SMS_STATE_READ,                 /*!< sms is read */
	SMS_STATE_FORWARDED,            /*!< sms is forwarded */
	SMS_STATE_REPLIED,              /*!< sms is replied */
	SMS_STATE_SENDING,              /*!< sms is sending */
	SMS_STATE_SENT,                 /*!< sms is sent */
	SMS_STATE_DELIVERED,            /*!< sms is delivered */    
	SMS_STATE_FAILED_SEND           /*!< sms failed to send*/
};

/// \enum SMSBoxEnum
/// Not Used.
public enum class SMSBoxEnum
{
    SMSInbox	= 0,        /*!< sms inbox   */
	SMSOutbox,              /*!< sms outbox  */
	SMSSentbox              /*!< sms sentbox */
};

/// \enum SmsStorageType
/// Not used
public enum class SmsStorageType
{
    SmsStorageHOST	= 0,    /*!< sms messages are stored on the host */
	SmsStorageSM,           /*!< sms messages are stored on the SIM (HSPA only) */
};

/// \enum SmsStateType
/// This enum defines values for the possible states of an sms message.  Used when querying for a list of sms messages
public enum class SmsStateType
{	
	NW_SMS_RECEIVED_UNREAD		= 0,  /*!< New unread message */
	NW_SMS_RECEIVED_READ		= 1,  /*!< Previously read message */
	NW_SMS_SENT_NOT_DELIVERED	= 2,  /*!< Sent but unconfirmed message */
	NW_SMS_SENT					= 3,  /*!< Set messsage */
	NW_SMS_ALL					= 4,  /*!< ANY message stat*/ 
	NW_SMS_STATUS_UNKNOWN		= 5   /*!< Unknown sms message state*/
};

/// \enum SmsSendStatusType
/// This enum defines the possible status values that can be received when sending an sms mesage.=
public enum class SmsSendStatusType
{
    NW_SMS_SEND_SUCCESS     = 0,    /*!< Sms sent okay */
    NW_SMS_SEND_NO_SERVICE,         /*!< Sms send failed due to lack of service */
    NW_SMS_SEND_INTERNAL_ERROR,     /*!< Sms send failed due to some other error */
};

/// Provides information about the voice mail indicator
public ref class VoiceMailInfoStruct
{ 
public: 
	unsigned char   bVoiceMailActive;   /*!< Voicemail indicator is active */
	unsigned long   dwVoiceMailIndex;   /*!< sms index of voicemail indicator */
} ;

/// \enum SmsMessageType 
/// Indicates the type of message that is encoded/present in the sms message struct.
public enum class SmsMessageType
{
	NW_SMS_TYPE_UNKNOWN		= 0,    /*!< Unknown encoding */
	NW_SMS_TYPE_WMS			= 1,    /*!< WMS encoding */
	NW_SMS_TYPE_IS683		= 2,    /*!< IS683 encoding */
	NW_SMS_TYPE_PDU			= 3,    /*!< GSM PDU encoding */
} ;

/// Defines a structure used when retrieving or sending an Sms message
public ref class SmsMessageStruct
{ 
public: 
	unsigned short      eSMSType;   /*!< The Sms encoding type*/
	unsigned short      eState;     /*!< The state of the sms message */
	unsigned short      index;      /*!< The index of the sms message in the sms list*/
	unsigned short      data_len;   /*!< The length of the encoded data*/
	unsigned char^       data;  /*!< A pointer to a buffer that contains/receives the encoded data */
} ;

/// Defines the state of an sms msg at the corresponding index of the list of sms messages
public ref class SmsMessageInfo
{ 
public: 
	unsigned short	index;    /*!< The index of the sms message in the sms list */
	unsigned short	eState;   /*!< The state of the sms message at the index */
} ;

/*******************************************************************
END SMS related types
********************************************************************/


/*******************************************************************
GPS related types
********************************************************************/

/// \enum GpsModeType
/// This enum defines the possible modes of the GPS engine
public enum class GpsModeType
{
	NW_GPS_NOGPS				= 0x00,		/*!< No GPS Support */
	NW_GPS_STANDALONE			= 0x01,	    /*!< Standalone */
	NW_GPS_MS_BASED				= 0x02,	    /*!< MS Based */
	NW_GPS_MS_ASSISTED			= 0x04,	    /*!< MS Assisted */
	NW_GPS_INTERNET_ASSISTED	= 0x08,		/*!< Standalone mode with internet assistance for retrieving satellite info quickly*/
} ;

/// \enum GpsSessionType
/// This enum defines the types of sessions that can be used when receiving fixes.
public enum class GpsSessionType
{
	NW_GPS_LAST_FIX                 = 0,    /*!< Last fix */
	NW_GPS_NEW_FIX                  = 1,    /*!< 1 new fix */
	NW_CGPS_TRACK_INDEPENDENT_FIX	= 2,		
	NW_GPS_CONTINUOUS_FIX           = 3,    /*!< Continuous fix */
	NW_GPS_CONSTANT_CONTINUOUS_FIX  = 4,    /*!< Continuous fix*/
} ;

/// \enum GpsEventType
/// This enum defines the possible types of GPS Event
public enum class GpsEventType
{
    NW_GPS_INVALID_FIX          = 0x00,     /*!< Too many invalid fixes received consecutively */
	NW_GPS_FIX_RECEIVED         = 0x01,     /*!< GPS Fix Received */ 
    NW_GPS_STARTED				= 0x02,		/*!< GPS Engine Started */
	NW_GPS_STOPPED				= 0x03,	    /*!< GPS Engine Stopped */
	NW_GPS_MSBASED_FAILURE		= 0x04,		/*!< MS-Based GPS Failed. May fallback to Standalone mode (available only in smart mode)*/
	NW_GPS_SUBSCRIPTION_FAILED	= 0x05,		/*!< 30 day subscription requirement failed. Valid only for Standalone mode */
	NW_GPS_STANDALONE_FALLBACK	= 0x06,		/*!< Fallback to Standalone mode (available only in smart mode)*/
    NW_GPS_SESSION_END          = 0x07,     /*!< A Gps pd session ended */
} ;

/// Defines an API structure used to obtain information about a single GPS fix
public ref class GpsFixInfoStruct
{ 
public: 
	double	        latitude;                           /*!< latitude */
	double	        longitude;                          /*!< longitude */
	long            altitude;                           /*!< altitude */
	double	        horizontal_velocity;                /*!< horizontal velocity */
	double	        vertical_velocity;                  /*!< vertical velocity */
	double	        heading;                            /*!< heading */
	double	        angle_uncertainty;                  /*!< angle_uncertainty */
	double	        std_dev_uncertainty;                /*!< standard deviation uncertainty */
	double	        perpendicular_std_dev_uncertainty;  /*!< perpendicular standard deviation uncertainty */
	double	        vertical_std_dev_uncertainty;       /*!< vertical standard deviation uncertainty */
	long            fix_type;                           /*!< type of fix */
	unsigned long   timestamp;                          /*!< timestamp of fix */
} ;

/// Defines an API structure that contains information about a single GPS satellite
public ref class GpsSatelliteInfoStruct
{ 
public: 
	unsigned char prn;              /*!< Pseudo Random Noise (PRN) number. This is used to identify the satellite */  
	unsigned char elevation;        /*!< satellite elevation */  
	unsigned short azimuth;         /*!< satellite azimuth*/    
	unsigned short snr;             /*!< satellite signal to noise ratio (SNR) */
	unsigned char location_valid;   /*!< satellite location is valid */
	unsigned char snr_valid;        /*!< SNR value is valid */
};

/// \def MAX_PRN
/// Defines the maximum number of satellite
#define MAX_PRN 37

/// Defines an API structure that contains information about the GPS satellites
public ref class GpsSatelliteConstellationStruct
{ 
public: 
	long num_svs;								/*!< Number of SVs (space vehicles) used to calculate position */
	long num_svs_detected;						/*!< Total number of SVs detected */
	GpsSatelliteInfoStruct^ sv_info;	/*!< Information about each SV.  Indexed by Pseudo Random Noise (PRN) number */
};

/// \enum GpsSmartModeType
/// This enum defines the modes of GPS smart mode
public enum class GpsSmartModeType
{
	NW_GPS_SMARTMODE_OFF			= 0,	/*!< No Smart Mode */
	NW_GPS_SMARTMODE_MSBASED		= 1,	/*!< MS-based smart mode (falls back to standalone if MS-Based fails) */
	NW_GPS_SMARTMODE_STANDALONE		= 2,	/*!< Standalone smart mode (falls back to MS-based if Standalone fails) */
};

/// \enum NMEAOutputType
/// This enum defines the possible Formats of NMEA Output string
public enum class NMEAOutputType
{
	NW_NMEA_OUTPUT_GPGGA	=	0x0001,     /*!< NMEA OUTPUT TYPE GPGGA */
	NW_NMEA_OUTPUT_GPGSA	=	0x0002,     /*!< NMEA OUTPUT TYPE GPGSA */
	NW_NMEA_OUTPUT_GPGSV	=	0x0004,     /*!< NMEA OUTPUT TYPE GPGSV */
	NW_NMEA_OUTPUT_GPVTG	=	0x0008,     /*!< NMEA OUTPUT TYPE GPVTG */
	NW_NMEA_OUTPUT_GPRMC	=	0x0010,     /*!< NMEA OUTPUT TYPE GPRMC */
} ;

/// \enum PDSMSessionType
/// This enum defines the possible session types for the GPS engine
public enum class PDSMSessionType
{
    NW_PDSM_SESSION_OPERATION_MIN = 0,         /*!< <tt><b>(reserved for internal use)</b><tt>*/
    NW_PDSM_SESSION_OPERATION_STANDALONE_ONLY, /*!< Standalone only mode */
    NW_PDSM_SESSION_OPERATION_MSBASED,         /*!< MS-based mode */
    NW_PDSM_SESSION_OPERATION_MSASSISTED,      /*!< MS-assisted mode */
    NW_PDSM_SESSION_OPERATION_OPTIMAL_SPEED,   /*!< Assisted optimal speed mode */
    NW_PDSM_SESSION_OPERATION_OPTIMAL_ACCURACY,/*!< Assisted optimal accuracy mode */
    NW_PDSM_SESSION_OPERATION_OPTIMAL_DATA,    /*!< Assisted optimal data mode */
    NW_PDSM_SESSION_OPERATION_REF_POSITION,    /*!< Assisted reference position mode */
};

/// Defines an API structure that contains information about the current GPS session
public ref class PDSMSessionInfo
{ 
public: 
    PDSMSessionType mode;                      /*!< Operating Mode (set to 0xff if there is no ongoing GPS session or the session has been completed) */
    unsigned char   qosSessionTimeout;         /*!< Qos Session Timeout (set to 1 if there is no ongoing GPS session or the session has been completed) */
    unsigned int    qosAccuracyThreshold;      /*!< Qos Accuracy Threshold (set to 0xffffffff if there is no ongoing GPS session or the session has been completed) */
} ;

/*******************************************************************
END GPS related types
********************************************************************/

/// Defines an API structure that contains basic information about an available WWAN device
public ref class DeviceDetail
{ 
public: 
	DeviceTechType          eTechnology;		         /*!< technology type of the device */
	DeviceFormFactorType    eFormFactor;				 /*!< physical form factor */
	char^                    szDescription;	 /*!< general name of the device */
	char^                    szPort;         /*!< name of the modem port */
    char^                    szFriendlyName; /*!< friendly name of the modem port */
};

public ref class OSDeviceDetail
{ 
public: 
    DeviceTechType          eTechnology;	    		//technology type of the device
	DeviceFormFactorType    eFormFactor;
    unsigned short          vid;
    unsigned short          pid;
    unsigned long long      sessionId;					// Session ID

    char^                    szDescription;
	char^                    szModemPort;
	char^                    szStatusPort;
	char^                    szDiagPort;
	char^                    szGpsPort;

#if defined(_NVTL_WINDOWS_)
    char^                   szModemPortFriendlyName;
	char^                    szStatusPortFriendlyName;
	char^                    szDiagPortFriendlyName;
	char^                    szGpsPortFriendlyName;
    
    long                    iNdisIndex;
	char^                    szPriHardwareId;
	char^                    szSecHardwareId;
	char^                    szNdisHardwareId;
	char^                    szDriverVersion;
	char^                    szStatusPortInstanceId;

#elif DEFINED_MAC
    
    char                    szModemDialIn[NW_MAX_PATH];
    char                    szStatusDialIn[NW_MAX_PATH];
    char                    szDiagDialIn[NW_MAX_PATH];
    char                    szGpsDialIn[NW_MAX_PATH];
    unsigned char           bRestricted;

#elif DEFINED_LINUX
	unsigned short			bus_num;
	unsigned short			dev_num;
    unsigned char           bRestricted;
#endif

};
/*******************************************************************
Basic SDK API related types
********************************************************************/

/// \enum NvtlSdkModeType
/// This enum defines the mode in which the SDK is being used
public enum class NvtlSdkModeType
{
	SdkModeLocal = 0,   /*!< The SDK is accessing the device COM port directlly */
	SdkModeShared,      /*!< The SDK is accessing the device through the SDK server to allow concurrent access */
};

/// \enum PropertyAction
/// This enum defines the action types used when accessing and SDK property
public enum class PropertyAction
{
	PropGet = 0,    /*!< The property is being read */
	PropSet = 1,    /*!< The property is being set */
    PROP_GET = 0,   /*!< The property is being read */
    PROP_SET = 1,   /*!< The property is being set */
};

//Enumerates the possible events that can be fired by the SDK
/// \enum NvtlEventType
/// This enum defines the types of SDK events that can be received in an SDK callback handler
public enum class NvtlEventType
{
	NW_EVENT_SIG_STR = 0,           /*!< The signal strength has changed.  The handler event receives a pointer to a SigStrEvent struct */
	NW_EVENT_ROAMING,               /*!< The roaming status has changed.   The handler event receives a pointer to a RoamingEvent struct */
	NW_EVENT_DEVICE_STATE,          /*!< The device state has changed.   The handler event receives a pointer to a DeviceStateEvent struct */
    NW_EVENT_DORMANT,               /*!< The dormancy status has changed.  The handler event receives a pointer to a DormantEvent struct */
	NW_EVENT_NETWORK,               /*!< The network status has changed.   The handler event receives a pointer to a NetworkEvent struct */
	NW_EVENT_SERVER_ERROR,          /*!< The SDK received a device error.  The handler event receives a pointer to a ServerErrorEvent struct */
	NW_EVENT_POWER_SAVE_NOTIFY,     /*!< The device is entering low power mode.  */
	NW_EVENT_LOG_PACKET,            /*!< not for general use */
	NW_EVENT_DIAG_PACKET,           /*!< not for general use */
	NW_EVENT_UNSOLICITED_AT,        /*!< An unsolicited AT response was received.  The handler event receives a pointer to a UnsolicitedATEvent struct */
	NW_EVENT_SMS,                   /*!< A new sms message was received.  The handler event receives a pointer to a SmsEvent struct */
	NW_EVENT_INCOMING_CALL,         /*!< not used */
	NW_EVENT_DEVICE_ADDED,          /*!< A new device was recognized by the host.  The handler event receives a pointer to a DeviceAddedEvent struct */
	NW_EVENT_DEVICE_REMOVED,        /*!< A device was removed from the host.  The handler event receives a pointer to a DeviceRemovedEvent struct.
                                        This event is fired when ANY device removal is detected and may not pertain to the active device in use if multiple
                                        devices are recognized in the system.  To detect the removal of a device currently in use handle the NW_EVENT_DEVICE_ERROR event.*/
	NW_EVENT_ACTIVATION,            /*!< The SDK received an activation status update.  The handler event receives a pointer to a ActivationEvent struct */
    NW_EVENT_OMADM,                 /*!< The SDK received an OMA-DM status update. The handler event receives a pointer to a OmaStatusEvent struct */
    NW_EVENT_SMS_SEND_STATUS,       /*!< The SDK received an Sms send status update. The handler event receives a pointer to a SmsSentEvent struct */
    NW_EVENT_GPS,	                /*!< The SDK received a GPS event.   The handler event receives a pointer to a GpsEvent struct */
    NW_EVENT_DEVICE_ERROR,          /*!< Indicates that there was an error with the device and communication with the device has stopped. 
                                        For example the deivce was removed while in use.  The handler event receives a pointer to a DeviceErrorEvent struct.
                                        Use this event as an indication of a plug-n-play removal of a device that is currently being used by the SDK.*/ 
	NW_EVENT_GPS_XTRA_STATUS,		/*!< Reports the status of the XTRA file Download and Injection into the device. The handler event receives a pointer to a XtraStatuEvent struct */
	NW_EVENT_TIME_SYNC_STATUS,		/*!< Reports the status of the Time sync from NTP server. The handler event receives a pointer to a XtraTimeSyncEvent struct */
    NW_EVENT_DEVICE_ATTACHED,       /*!< The current session has succesfully attached to a device   */
    NW_EVENT_DEVICE_DETACHED,       /*!< The current session has succesfully detached from a device */
    NW_EVENT_MIP_ERROR,             /*!< A Mobile IP error indication has been received from the device */
    NW_EVENT_GPS_XTRA_DOWNLOAD_REQ, /*!< Requests the XTRA file to be downloaded and injected into the device. The handler event receives a pointer to a XtraStatuEvent struct */
    NW_EVENT_GPS_XTRA_TIMEINFO_REQ, /*!< Requests the XTRA Time sync from the NTP server to be injected into the device. The handler event receives a pointer to a XtraStatuEvent struct */
    NW_EVENT_GPS_XTRA_CMD_ERR,      /*!< Indicates that the XTRA download or Time sync command was sent to the GPS engine incorrectly. */
    NW_EVENT_GPS_XTRA_DOWNLOAD_STATUS, /*!< Indicates that the status of XTRA download or Time sync command as reported by the firmware. */
    NW_EVENT_GPS_SMS_FILTER,        /*!< Reports a specialized GPS directed SMS was received.  Only for VZW LBS services */
    NW_EVENT_GPS_SECURITY,          /*!< Reports that gps security is initialized.  Only for VZW LBS services */
    NW_EVENT_GPS_CMD_ERROR,         /*!< Reports that a gps command failed. Only for VZW LBS services. */
};

/// Defines a structure sent to registered event callbacks containing information about the event.
public ref class NvtlEventStruct
{ 
public: 
	unsigned long	type;       /*!< Contains the type of the event (NvtlEventType) */
	unsigned long	size;       /*!< Contains the total size of the event buffer */
	unsigned char*	buffer;     /*!< A buffer containing the data or the pointer to the appropriate structure or type */
};

public ref class StandardEvent
{
public:
    unsigned long val;  /*!< The value of the event */
};

/// Defines the strength event received in the event callback when
/// the signal strength changes.  The value is the current signal strength of the device
public ref class SigStrEvent : StandardEvent{};

/// Defines the romaing event struct receieved in the event callback when
/// the roaming status changes.  The value is the current roaming status of the device as defined by the #DeviceRoamStatusType enum
public ref class RoamingEvent : StandardEvent{};

/// Defines the device state event received in the event callback when
/// the device state changes.  The value is the current state of the device as defined by the #DeviceStateType enum
public ref class DeviceStateEvent : StandardEvent{};

/// Defines the dormancy event received in the event callback when
/// the dormancy status changes.  The value is the current dormancy status of the device
public ref class DormantEvent : StandardEvent{};

/// Defines the network event received in the event callback when
/// the network status changes.  The value is the current network state of the device as defined by the #DeviceServiceType enum
public ref class NetworkEvent : StandardEvent{};

/// Defines the server error event received in the event callback when
/// an error is received from the device relating to connections.  The value is an
/// error received during a connection or connection attempt.
public ref class ServerErrorEvent : StandardEvent{};

/// Defines the sms event received in the event callback when 
/// new sms messages are available.  The value is an indicator that new sms messages are waiting.
public ref class SmsEvent : StandardEvent{};

/// Defines the sms sent event received in the event callback when
/// an sms message is either sent or failed during transmission. The value is an indicator of the 
/// success or failure of an attempt at sending an sms message
public ref class SmsSentEvent : StandardEvent{};

/// Defines the device added event received in the event callback when
/// a new device is added to the system. 
public ref class DeviceAddedEvent : StandardEvent{};

/// Defines the device removed event received in the event callback when
/// a device is removed from the system
public ref class DeviceRemovedEvent : StandardEvent{};

/// Defines the activation event received in the event callback when
/// the activation status changes.  The value is an indication of the current state of the activation process
/// as defined by the #ActivationStateType enum
public ref class ActivationEvent : StandardEvent{};

/// Defines the gps event received in the event callback when
/// gps status changes or fixes are available.
public ref class GpsEvent : StandardEvent{};

/// Defines the device erorr event received in the event callback when
/// an error occurs with the communication with a device.
public ref class DeviceErrorEvent : StandardEvent{};

/// Defines the xtra status event received in the event callback when
/// the xtra status of the gps engine changes.
public ref class XtraStatuEvent : StandardEvent{};

/// Defines the xtra time synce event received in the event callback when
/// the gps engine synchronizes time with an internet server.
public ref class XtraTimeSyncEvent : StandardEvent{};

/// Defines the device erorr event received in the event callback when
/// a session has succesfully attached to a device.
public ref class DeviceAttachedEvent : StandardEvent{};

/// Defines the device erorr event received in the event callback when
/// a session has succesfully detached from a device.
public ref class DeviceDetachedEvent : StandardEvent{};

/// Defines the erorr event received in the event callback when
/// a mobile ip error has been received.
public ref class MipErrorEvent : StandardEvent{};

/// Defines the unsolicited event received in the event callback when
/// an unsolicited AT repsonse is received.
typedef char* UnsolicitedATEvent;

/// Defines the event received when a specialized GPS routed SMS is received. Select VZW devices only.
public ref class GpsSmsFilterEvent{
public:
    char^  val;
};

/// Defines the erorr event received in the event callback when
/// a gps command has failed.
public ref class GpsCommandErrorEvent : StandardEvent{};


/// Defines the callback function used to propogate SDK events.
public delegate void NvtlSdkEventFunc(char^ user_data, NvtlEventType type, unsigned long size, StandardEvent ev);

public ref class GPSEventXTRADownloadStruct
{
public:
	unsigned int                flags;
	unsigned int                status;
	unsigned short              command;
	unsigned short              startGpsWeek;
	unsigned short              startGpsMinutes;
	unsigned short              validDurationHours;
	char^                       xtra_server_primary;
	char^                       xtra_server_secondary;
	char^                       xtra_server_tertiary;
	unsigned int                maxFilePartSize;
	unsigned int                maxFileSize;
};

public ref class GPSEventXTRATimeinfoStruct
{ 
public:
    unsigned int                command;
    unsigned int                oneway_delay_failover_thresh;
	char^                       xtra_server_primary;
	char^                       xtra_server_secondary;
	char^                       xtra_server_tertiary;
};


/// Callback structure used to receive events from the SDK
public ref class NvtlEventCallback
{ 
public: 
	INT_PTR              user_data;      /*!< A user defined pointer that is returned during the callback */
	NvtlSdkEventFunc^    event_func;     /*!< A pointer to the NvtlSdkEventFunc that should be called for events */
};

///Contains information about a file in the EFS of the device
public ref class EfsFileInfoStruct
{ 
public: 
	unsigned long	type;       /*!< File type */
	unsigned long	mode;       /*!< file mode */
	unsigned long	size;       /*!< file size */
	unsigned long	nLink;      /*!< number of links */
	unsigned long	aTime;      /*!< access time */
	unsigned long   mTime;      /*!< modified time */
	unsigned long	cTime;      /*!< creation time */
	char^ name;     /*!< filename */
};

public enum class RouterConfigItemIdType
{
    ROUTER_CONFIG_ID_SSID_CURRENT       = 1,    /*!< The current SSID in use */
    ROUTER_CONFIG_ID_SSID_OPEN          = 2,    /*!< The SSID for the open profile */
    ROUTER_CONFIG_ID_SSID_SECURE        = 3,    /*!< The SSID for the secure profile */
    ROUTER_CONFIG_ID_SSID_TEMPORARY     = 4,    /*!< The SSID for the temporary profie */
    ROUTER_CONFIG_ID_PROFILE_CURRENT    = 5,    /*!< The current wireless profile in use as defined by 0 = Open, 1 = Secure, 2 = Temporary */
    ROUTER_CONFIG_ID_KEY_CURRENT     = 6,       /*!< Returns the current active key in use according to the current wireless profile in use */
};

/// \enum CallStatusType
/// Defines the possible values of the current call state of the device
public enum class CallStatusType
{
	CALL_STATUS_IDLE,            /*!< The device is idle */
	CALL_STATUS_CONNECTING,      /*!< The device is establishing a call */
	CALL_STATUS_AUTHENTICATING,  /*!< The device is authenticating a call */
	CALL_STATUS_CONNECTED,       /*!< The device in in a call */
	CALL_STATUS_DORMANT,         /*!< The device is in a call but dormant */
	CALL_STATUS_DISCONNECTING,   /*!< The device is terminating a call */
};

/// Defines a structure containing generally relevant device information
public ref class DeviceInfoStruct
{ 
public: 
	unsigned long           dwSize;			/*!< Reserved. The size of the struct. */
    unsigned long           dwCurFWVersion;	/*!< Reserved */
	SourceBuildBaseType     eBuildBase;		/*!< base chipset if known */
	ServiceProviderType     eSrvProvider;	/*!< The intended service provider, if known */
	DeviceTechType          eTech;			/*!< The device technology of the device */
	DeviceFormFactorType    eFormFactor;	/*!< The form factor of the device */
	DeviceStateType	        eState;         /*!< A general state of the device taking into account various pieces of volatile info.
                                             * This state is a primary indication of the readiness or current actions of the device */
    DeviceModeType          modeDevice;		/*!< The Current power mode of the device */
	CallStatusType          connStatus;		/*!< Indicates the current call state of the device */
	
    unsigned char           bDeviceLocked;  /*!< Indicates if the device is currently locked and requires a PIN or PUK */
	unsigned char           maskWDisable;   /*!< Indicates if the device is currently disabled */
	unsigned char           subsysID;		/*!< reserved */

	//module related static info
	char^                    szSoftwareVersion;	/*!< Firmware version string */
	char^                    szDeviceModel;			/*!< Device model string */
	char^                    szHardwareVersion;		/*!< Hardware version string */
	char^                    szDriverVersion;		/*!< Driver version string */
	char^                    szMDN;				/*!< Mobile Number */
	char^                    szFID;					/*!< Factory ID */

    //UMTS/HSPA specific values
	char^                    szIMEI;		/*!< UMTS/HSPA. IMEI string */
	char^                    szSMSC;			/*!< UMTS/HSPA. SMSC string */
	char^                    szIMSI;		/*!< UMTS/HSPA. IMSI string */
	char^                    szICCID;		/*!< UMTS/HSPA. ICCID string */

    //EVDO specific values
	char^                    szMIN;		/*!< EVDO. Mobile Identification Number (MIN) */
    unsigned long           dwESN;							/*!< EVDO. Electronic Serial Number (ESN) */
	unsigned long           dwPRLVersion;					/*!< EVDO. PRL verison */
	unsigned long           dwERIVersion;                   /*!< EVDO.  ERI version */
	unsigned long           dwHomeSID;						/*!< EVDO. HOME SID */

};

/// Defines a structure that contains relevant information about the current network state of the device
public ref class NetworkInfoStruct
{ 
public: 
    unsigned long           dwSize;         /*!< reserved. the size of the stuct */
	unsigned long           dwSigStr;       /*!< The current signal strength of the device in range 0 - 5 */
	unsigned long           dwRSSI;	        /*!< The current rssi of the device */
	unsigned long	        dwEnsStatus;    /*!< HSPA ENS Status */    
    float                   fdBmSignal;     /*!< The dbm signal of the device */
    DeviceServiceType       eService;       /*!< The current network service type of the device */
	DeviceRoamStatusType    eRoam;          /*!< The current roaming status of the device */
    RoamIndicatorType	    eIndID;         /*!< EVDO. ERI Roaming indicator type */
    unsigned char           bDormant;       /*!< The current dormancy state of the device */
	unsigned char           bNewSMS;        /*!< A flag indicating new sms status */ //should remove?
} ;

/// \enum SdkLogLevelType
/// This enum defines the possible log levels
public enum class SdkLogLevelType
{
	SdkLogLevelNone	= 0,    /*!< No logging */
	SdkLogLevelError,       /*!< Log only error statements */
	SdkLogLevelWarning,     /*!< Log any warning or more serious statement */
	SdkLogLevelInfo,        /*!< Log general usage or more serious statements */
	SdkLogLevelDebug,       /*!< Log more detailed debugging statement */
	SdkLogLevelAll          /*!< Enable all possible statement */
};

/// \enum SdkLogOutputType
/// This enum defines the output method used for logging statement
public enum class SdkLogOutputType
{
	SdkOutputNone	= 0x00,     /*!< No logging output */
	SdkOutputStdOut	= 0x01,     /*!< Log to stdout */
	SdkOutputFile	= 0x02,     /*!< Log to a file */
    SdkOutputBoth   = 0x03,     /*!< Log to both a file and std out */
    SdkOutputTrace  = 0x04,     /*!< Log to Windows Debug Log using OutputDebugString */
};

/// \enum MipDetailMask
/// Defines mask values related to the MIP settings
public enum class MipDetailMask
{
	MIP_DETAIL_HOME_ADDRESS	    = 0x0001,	/*!< \e MIP_Home_Addr value is being specified */
	MIP_DETAIL_PRI_HA_ADDRESS	= 0x0002,	/*!< \e MIP_PRI_HA_Addr value is being specified */
	MIP_DETAIL_SEC_HA_ADDRESS	= 0x0004,	/*!< \e MIP_SEC_HA_Addr value is being specified */
	MIP_DETAIL_HA_SPI			= 0x0008,	/*!< \e MIP_HA_SPI value is being specified */
	MIP_DETAIL_AAA_SPI			= 0x0010,	/*!< \e MIP_AAA_SPI value is being specified */
	MIP_DETAIL_REV_TUNNEL		= 0x0020,	/*!< \e MIP_REV_TUN value is being specified */
    MIP_DETAIL_HA_KEY           = 0x0040,	/*!< \e ha_key value is being specified */
    MIP_DETAIL_AAA_KEY          = 0x0080,	/*!< \e aaa_key value is being specified */
    MIP_DETAIL_NAI              = 0x0100,   /*!< \e NAI value is being specified */
    MIP_DETAIL_ENABLED          = 0x0200,   /*!< \e Enabled value is being specified */
} ;

/// Defines a structure representing a date and time.
public ref class NvtlTimeStruct
{ 
public: 
	unsigned short		wYear;      /*!< year */
	unsigned short		wMonth;     /*!< month */
	unsigned short		wDay;       /*!< day */
	unsigned short		wHour;      /*!< hour */
	unsigned short		wMinute;    /*!< minute */
	unsigned short		wSeconds;   /*!< seconds */
	unsigned short		wMilSecs;   /*!< milliseconds */
	unsigned short		wUTCDiff;   /*!< utc offset */
} ;

/// Defines a structure used for setting MIP detail information.
public ref class MipDetailsStruct
{ 
public: 
	unsigned char		index;                  /*!< TODO mip detail index */
	unsigned char		mn_ha_spi_set;          /*!< TODO flag indicating ha spi is set*/
	unsigned long		mn_ha_spi;              /*!< TODO ha spi value*/
	unsigned char		mn_aaa_spi_set;         /*!< TODO flag indicating aaa spi is set */
	unsigned long		mn_aaa_spi;             /*!< TODO aaa spi value */
	unsigned char		rev_tun_pref;           /*!< TODO rev tun pref */
	unsigned long		home_addr;              /*!< TODO home address */
	unsigned long		primary_ha_addr;        /*!< TODO primary ha address */
	unsigned long		secondary_ha_addr;      /*!< TODO secondary ha addrress */
} ;

/// Defines a structure used for setting MIP detail information.  Supported only on select devices
public ref class MipDetailsStructEx
{ 
public: 
    unsigned int        mask;                   /*!< When setting, specifies which of the fields contain data to be written */
	unsigned char		index;                  /*!< mip detail index */
	unsigned long		mn_ha_spi;              /*!< ha spi value*/
	unsigned long		mn_aaa_spi;             /*!< aaa spi value */
	unsigned char		rev_tun_pref;           /*!< rev tun pref */
	unsigned long		home_addr;              /*!< home address */
	unsigned long		primary_ha_addr;        /*!< primary ha address */
	unsigned long		secondary_ha_addr;      /*!< secondary ha addrress */
    unsigned char       enabled;                /*!< enabled state */
    char^                ha_key;             /*!< ha_key */
	char^                aaa_key;            /*!< aaa_key */
	char^                nai;                /*!< nai    */
} ;


/// \enum MipParametersMask
/// Defines mask values related to the fields in the MipParametersStruct
public enum class MipParametersMask
{
	MIP_PARAM_MODE              = 0x0001,	/*!< \e mode value is being specified */
	MIP_PARAM_RETRY_LIMIT       = 0x0002,	/*!< \e retry limit value is being specified */
	MIP_PARAM_RETRY_INTERVAL    = 0x0004,	/*!< \e retry interval value is being specified */
	MIP_PARAM_RE_REG_PERIOD     = 0x0008,	/*!< \e re-registration period value is being specified */
	MIP_PARAM_RE_REG_TRAFFIC    = 0x0010,	/*!< \e re-registration traffic value is being specified */
	MIP_PARAM_HA_AUTHENTICATOR  = 0x0020,	/*!< \e HA Authenticator value is being specified */
    MIP_PARAM_HA2002BIS         = 0x0040,	/*!< \e HA2002BIS value is being specified */
} ;

/// Defines a structure used for setting or retreiving MIP parameter information.  Supported only on select devices
public ref class MipParametersStruct
{ 
public: 
    unsigned int    mask;                   /*!< When setting, specifies which of the fields contain data to be written */
    unsigned char   mode;                   /*!< MIP mode 0-off 1-preferred 2-MIP only */
    unsigned char   retryLimit;             /*!< Registration retry attempt limit */
    unsigned char   retryInterval;          /*!< Registration retry attempt interval */
    unsigned char   reRegPeriod;            /*!< Period to attempt re-registration before current registration expires (in minutes) */
    unsigned char   reRegTraffic;           /*!< Re-registration only if traffic since the last attempt? */     
    unsigned char   HAAuthenticator;        /*!< MH-HA authenticator calculator? */ 
    unsigned char   HA2002bis;              /*!< MH-HA RFC 2002bis authentication instead of RFC2002 */
};

/// Defines a structure used for setting MIP key information
public ref class MipKeysStruct
{ 
public:
    unsigned char      index;                           /*!< TODO mip keys index */
    unsigned char^      mn_ha_shared_secret_length;      /*!< TODO length of ha key */
	unsigned char^      mn_ha_shared_secret;       /*!< TODO ha key*/
	unsigned char^      mn_aaa_shared_secret_length;     /*!< TODO aaa key length */
	unsigned char^      mn_aaa_shared_secret;        /*!< TODO aaa key */
} ;

/** \enum MipKeyStatusType
<tt><b>\<CDMA/EVDO devices only\></b></tt>\n
This enum defines values for the status of shared secret keys. 
*/
public enum class MipKeyStatusType
{
	MIP_KEY_STATUS_SET          = 0,	/*!< 0 - Both HA and AAA are set */
	MIP_KEY_STATUS_NOT_SET      = 3,    /*!< 3 - Either HA or AAA or both are not set */
	MIP_KEY_STATUS_MASS_NOT_SET = 4,	/*!< 4 - When only HA is set */
	MIP_KEY_STATUS_MHSS_NOT_SET = 5		/*!< 5 - When only AAA is set */
};


/// Defines a structure for obtaining ERI information.
public ref class EriInfoStruct
{ 
public: 
    long     roam;          /*!< TODO ERI roaming value */
	long     indicatorId;   /*!< TODO ERI indicator id*/
	long     iconId;        /*!< ERI icon id*/
	long     alertId;       /*!< ERI alert id*/
	char^     version;   /*!< ERI version string */
	char^     data;      /*!< ERI data */
};

/// Defines a structure for accessing Sid an Nid information
public ref class SidNidInfoStruct
{ 
public: 
    unsigned short sid_count;   /*!< TODO the number of SIDs in the sids array */
    unsigned short nid_count;   /*!< TODO the number of NIDs in the nids array */
    unsigned short sid;    /*!< TODO the array of SID values */
	unsigned short nids;    /*!< TODO the array of NID valus*/
};

/// Defines a structure for accessing channel information
public ref class ChannelParametersStruct
{ 
public: 
    unsigned short primary_a;       /*!< TODO Primay channel a*/
    unsigned short primary_b;       /*!< TODO Primary channel b*/
    unsigned short secondary_a;     /*!< TODO Secondary channel a*/
    unsigned short secondary_b;     /*!< TODO Secondary channel b*/
};

/*******************************************************************
END Basic SDK API related types
********************************************************************/

/*******************************************************************
Diagnostics and Field Test related types
********************************************************************/
/** \enum field_test_field_evdo_e_type
This enum defines values that can be used to parse data obtained from method GetFieldTestInfo for a CDMA/EVDO device.
*/
public enum class field_test_field_evdo_e_type
{
	FT_MIN_EVDO					= 0,	/*!< Place Holder */
	FT_WARRANTY_DATE			= 0,	/*!< Warranty Date */
	FT_SLOT_CYCLE_INDEX			= 1,	/*!< Slot Cycle Index */
	FT_CURRENT_NAM				= 2,	/*!< Current NAM */
	FT_AUTO_NAM					= 3,	/*!< Auto NAM */
	FT_SPC_CHANGE_ENABLED		= 4,	/*!< SPC Change Enabled */
	FT_NAM_NAME					= 5,	/*!< NAM Name */
	FT_DIRECTORY_NUMBER			= 6,	/*!< Directory # */
	FT_ACCOLC					= 7,	/*!< Access Overload Class */
	FT_MCC						= 8,	/*!< MCC */
	FT_MNC						= 9,	/*!< MNC */
	FT_CHANNEL_PRI_A			= 10,	/*!< Channel Primary A */
	FT_CHANNEL_PRI_B			= 11,	/*!< Channel Primary B */
	FT_CHANNEL_SEC_A			= 12,	/*!< Channel Secondary A */
	FT_CHANNEL_SEC_B			= 13,	/*!< Channel Secondary B */
	FT_HOME_SID_TABLE			= 14,	/*!< Home SID Table */
	FT_TERM_REG_HOME_SID		= 15,	/*!< Terminated Reg Home SID */
	FT_TERM_REG_FOREIGN_SID		= 16,	/*!< Terminated Reg Foreign SID */
	FT_TERM_REG_FOREIGN_NID		= 17,	/*!< Terminated Reg Foreign NID */
	FT_SYS_PREF_MODE			= 18,	/*!< System Preffered Mode */
	FT_PRL_VER					= 19,	/*!< PRL Version Number */
	FT_DNS_PRI					= 20,	/*!< DNS Primary */
	FT_DNS_SEC					= 21,	/*!< DNS Secondary */
	FT_PACKET_DIAL_STR			= 22,	/*!< Packet Dial String */
	FT_MDR_MODE					= 23,	/*!< MDR Mode */
	FT_DATA_SCRM				= 24,	/*!< Data SCRM */
	FT_MIP_HA_SPI				= 25,	/*!< MIP HA SPI Value */
	FT_MIP_REV_TUN				= 26,	/*!< MIP Reverse Tunneling */
	FT_MIP_HOME					= 27,	/*!< MIP Home */
	FT_MIP_PRI_HA				= 28,	/*!< MIP Primary HA Address */
	FT_MIP_SEC_HA				= 29,	/*!< MIP Secondary HA Address */
	FT_MIP_BEHAVIOR				= 30,	/*!< MIP Behavior */
	FT_MIP_PRE_REG_TIMEOUT		= 31,	/*!< MIP Pre-Registration Timeout */
	FT_MIP_REG_RETRIES			= 32,	/*!< MIP Registration Retries */
	FT_DMU_KEY_EXHG_INDICATOR	= 33,	/*!< DMU Key Exchange Indicator */
	FT_NID						= 34,	/*!< NID */
	FT_FER						= 35,	/*!< FER */
	FT_RSSI						= 36,	/*!< RSSI */
	FT_ECIO						= 37,	/*!< EC/IO */
	FT_CHANNEL					= 38,	/*!< Channel */
	FT_LATITUDE					= 39,	/*!< Latitude */
	FT_LONGITUDE				= 40,	/*!< Longitude */
	FT_TX_POWER					= 41,	/*!< Tx Power */
	FT_RX_POWER					= 42,	/*!< Rx Power */
	FT_BAND_CLASS				= 43,	/*!< Band Class */
	FT_PREV						= 44,	/*!< P Rev */
	FT_PKT_ZONE_ID				= 45,	/*!< Packet Zone ID */
	FT_LAST_CALL_ERR			= 46,	/*!< Last Call Error */
	FT_SO_IN_USE				= 47,	/*!< Service Option in Use */
	FT_CALL_STATE				= 48,	/*!< Call State. Possible values are:
												- 0 Idle (or no air link)
												- 1 Connecting
												- 2 Authenticating
												- 3 Connected and NOT DORMANT
												- 4 Connected and DORMANT
												- 5 Disconnecting
												.
												*/
	FT_DORMANT_STATE			= 49,	/*!< Dormant State */
	FT_MAC_INDEX				= 50,	/*!< MAC Index */
	FT_SUBNET_MASK				= 51,	/*!< Subnet Mask */
	FT_COL_CODE					= 52,	/*!< Color Code */
	FT_UATI024					= 53,	/*!< UATI024 */
	FT_1X_FIN_INFO_PN_OFFSET	= 54,	/*!< 1X Finger Info PN Offsets */
	FT_1X_FIN_INFO_WALSH_CODES	= 55,	/*!< 1X Finger Info Walsh Codes */
	FT_1X_FIN_INFO_RSSI			= 56,	/*!< 1X Finger Info RSSI */
	FT_1X_ACT_SET_COUNT			= 57,	/*!< Number of pilots in 1X Active Set */
	FT_1X_ACT_SET_PN_OFFSET		= 58,	/*!< 1X Active Set PN Offsets */
	FT_1X_ACT_SET_ECIO			= 59,	/*!< 1X Active Set Ec/Io (dBm). These are floating point values. */
	FT_1X_NEB_SET_COUNT			= 60,	/*!< Number of pilots in 1X Neighbor Set */
	FT_1X_NEB_SET_PN_OFFSET		= 61,	/*!< 1X Neighbor Set PN Offsets */
	FT_1X_NEB_SET_ECIO			= 62,	/*!< 1X Neighbor Set Ec/Io (dBm). These are floating point values. */
	FT_1X_CAND_SET_COUNT		= 63,	/*!< Number of pilots in 1X Candidate Set */
	FT_1X_CAND_SET_PN_OFFSET	= 64,	/*!< 1X Candidate Set PN Offsets */
	FT_1X_CAND_SET_ECIO			= 65,	/*!< 1X Candidate Set Ec/Io (dBm). These are floating point values. */
	FT_HDR_FIN_INFO_PN_OFFSET	= 66,	/*!< HDR Finger Info PN Offsets */
	FT_HDR_FIN_INFO_WALSH_CODES	= 67,	/*!< HDR Finger Info Walsh Codes */
	FT_HDR_FIN_INFO_RSSI		= 68,	/*!< HDR Finger Info RSSI */
	FT_HDR_ACT_SET_COUNT		= 69,	/*!< Number of pilots in EVDO Active Set */
	FT_HDR_ACT_SET_PN_OFFSET	= 70,	/*!< HDR Active Set PN Offsets */
	FT_HDR_ACT_SET_ECIO			= 71,	/*!< HDR Active Set Ec/Io (dBm). These are floating point values. */
	FT_HDR_ACT_SET_CHANNEL		= 72,	/*!< HDR Active Set Channel */
	FT_HDR_ACT_SET_BAND_CLASS	= 73,	/*!< HDR Active Set Band Class */
	FT_HDR_NEB_SET_COUNT		= 74,	/*!< Number of pilots in EVDO Neighbor Set */
	FT_HDR_NEB_SET_PN_OFFSET	= 75,	/*!< HDR Neighbor Set PN Offsets */
	FT_HDR_NEB_SET_ECIO			= 76,	/*!< HDR Neighbor Set Ec/Io (dBm). These are floating point values. */
	FT_HDR_NEB_SET_CHANNEL		= 77,	/*!< HDR Neighbor Set Channel */
	FT_HDR_NEB_SET_BAND_CLASS	= 78,	/*!< HDR Neighbor Set Band Class */
	FT_HDR_CAND_SET_COUNT		= 79,	/*!< Number of pilots in EVDO Candidate Set */
	FT_HDR_CAND_SET_PN_OFFSET	= 80,	/*!< HDR Candidate Set PN Offsets */
	FT_HDR_CAND_SET_ECIO		= 81,	/*!< HDR Candidate Set Ec/Io (dBm). These are floating point values. */
	FT_HDR_CAND_SET_CHANNEL		= 82,	/*!< HDR Candidate Set Channel */
	FT_HDR_CAND_SET_BAND_CLASS	= 83,	/*!< HDR Candidate Set Band Class */
	FT_SECTOR_ID				= 84,	/*!< Sector ID */
	FT_EVDO_TEMPERATURE			= 85,	/*!< Temperature */
	FT_EVDO_PRI_INFO			= 86,	/*!< PRI Info */
	FT_EVDO_AN_AAA_STATUS		= 87,	/*!< AN-AAA Status. Possible values are:
											- 0 Not Authenticated
											- 1 Authenticated
											.
											*/
	FT_HDR_SESSION_STATE		= 88,	/*!< HDR Session State. Possible values are:
											- 0 Inactive State
											- 1 AMP Setup State
											- 2 AT initiated State
											- 3 AN initiated State
											- 4 Open state
											.
											*/
	FT_MIP_AAA_SPI				= 89,	/*!< MIP AAA SPI Value */
	FT_ACQ_SID					= 90,	/*!< Acquired SID. SID of system in use.*/
	FT_MAX_EVDO	
} ;

/** \enum field_test_field_umts_e_type
This enum defines values that can be used to parse data obtained from method GetFieldTestInfo for a UMTS/HSDPA device.
*/
public enum class field_test_field_umts_e_type
{
	FT_MIN_UMTS					= 0,	/*!< Place Holder */
	FT_CALL_MANAGER_STATE		= 0,	/*!< Call Manager State */		
	FT_SYSTEM_MODE				= 1,	/*!< System Mode */
	FT_NAS_GMM_STATE			= 2,	/*!< NAS GMM State */
	FT_NAS_GMM_SUBSTATE			= 3,	/*!< NAS GMM Sub State */
	FT_NAS_MM_STATE				= 4,	/*!< NAS MM State */
	FT_NAS_MM_SUBSTATE			= 5,	/*!< NAS MM SubState */
	FT_NAS_MM_UPDATE			= 6,	/*!< NAS MM Update */
	FT_NAS_REGISTRATION_STATE	= 7,	/*!< NAS Registration State */
	FT_PLMN_SELECT_MODE			= 8,	/*!< PLMN Select Mode */
	FT_UE_OPERATION_MODE		= 9,	/*!< UE Operation Mode */
	FT_PS_CALL_ID				= 10,	/*!< PS Call ID */				
	FT_NSAPI_VALUE				= 11,	/*!< NSAPI Value */
	FT_NETWORK_OPERATION_MODE	= 12,	/*!< Network Operation Mode */
	FT_SERVICE_TYPE				= 13,	/*!< Service Type */
	FT_SERVING_CELL_PLMN		= 14,	/*!< Serving Cell PLMN */
	FT_SERVING_CELL_LAI			= 15,	/*!< Serving Cell LAI */
	FT_SERVING_CELL_RAI			= 16,	/*!< Serving Cell RAI */
	FT_NUM_OF_AVAILABLE_PLMN	= 17,	/*!< Number of Available PLMN */
	FT_PLMN_1_TO_10 			= 18,	/*!< PLMN 1..10 */
	FT_P_TMSI					= 19,	/*!< P_TMSI */
	FT_IMSI						= 20,	/*!< IMSI */						
	FT_IMEI						= 21,	/*!< IMEI */
	FT_IMEI_SOFTWARE_VERSION	= 22,	/*!< IMEI Software Version */
	FT_QOS_CONNECTION_ID		= 23,	/*!< QoS Connection ID */
	FT_DELAY_CLASS				= 24,	/*!< Delay Class */
	FT_RELIABILITY_CLASS		= 25,	/*!< Reliability Class */
	FT_PEAK_THROUGHPUT			= 26,	/*!< Peak Throughput */
	FT_PRECEDENCE_CLASS			= 27,	/*!< Precedence Class */
	FT_MEAN_THROUGHPUT			= 28,	/*!< Mean Throughput */
	FT_TRAFFIC_CLASS			= 29,	/*!< Traffic Class */
	FT_DELIVERY_ORDER			= 30,	/*!< Delivery Order */			
	FT_DELIVERY_ERROR_SDU		= 31,	/*!< Delivery of Error SDU */	
	FT_MAX_SDU_SIZE				= 32,	/*!< Max SDU Size */
	FT_MIN_BIT_RATE_UL			= 33,	/*!< Min Bit Rate UL */
	FT_MIN_BIT_RATE_DL			= 34,	/*!< Min Bit Rate DL */
	FT_RESIDUAL_ERROR_RATIO		= 35,	/*!< Residual Error Ratio */
	FT_TRANSFER_DELAY			= 36,	/*!< Transfer Delay */
	FT_TRAFFIC_HANDLING_PRIORITY= 37,	/*!< Traffic Handling Priority */
	FT_MAX_BIT_RATE_UL			= 38,	/*!< Max Bit Rate for UL */
	FT_MAX_BIT_RATE_DL			= 39,	/*!< Max Bit Rate for DL */
	FT_FDD_ACTIVE_SET_CELLS		= 40,	/*!< FDD Active Set Cells */		
	FT_FDD_ACTIVE_SET_FREQ		= 41,	/*!< FDD Active Set Frequency */
	FT_FDD_NEIGHBOR_SET_FREQ	= 42,	/*!< FDD Neighbor Set Frequency */
	FT_DOWNLINK_FREQ_1_TO_3		= 43,	/*!< Downlink Frequency 1..3 */
	FT_NEIGHBORS_PER_FREQ_1_TO_3= 44,	/*!< Neighbors per Freq 1..3 */
	FT_RRC_STATE				= 45,	/*!< RRC State */				
	FT_CURRENT_RRC_PROCEDURE	= 46,	/*!< Current RRC Procedure */
	FT_RRC_FAILURE_CAUSE		= 47,	/*!< RRC Failure Cause */
	FT_PROTOCOL_ERROR_CAUSE		= 48,	/*!< Protocol Error Cause */		
	FT_HSDPA_TEMPERATURE        = 49,	/*!< Temperature */
    FT_SERVING_CELL_ID          = 50,   /*!< Serving cell id */
    FT_CELL_LAC                 = 51,   /*!< Cell LAC */
	FT_RLC_BYTES_RX				= 52,   /*!< RLC Data Bearer Channel */
	FT_MAX_UMTS	
} ;

public ref class StringStruct{
    char^    str;    /*!< The string value*/
};

public ref class FieldTestInfoStruct
{
    StringStruct^    labels;    /*!< Array of field test info names */
    StringStruct^    values;    /*!< Array of field test info values */
	unsigned long	size;                   /*!< Number of entries inthe labels and values field */
};
/*******************************************************************
End Diagnostics and Field Test related types
********************************************************************/


/*******************************************************************
Connectivity related types
********************************************************************/
// Defines an API structure used to hold the Quality of Service settings to use for GSM data connections.
/// \n /// <tt><b>\<UMTS and HSDPA devices only\></b></tt>
public ref class QosSettingsStruct
{ 
public: 
    long    MaxSduSize;             /*!< A numeric parameter (1,2,3,etc) that indicates the maximum allowed SDU size in octets. 
                                        \n If the parameter is set to '0' the subscribed value will be requested. */

    long    DeliveryOfSDUError;     /*!< A numeric parameter that indicates whether SDUs detected as erroneous shall be delivered or not. 
                                        \n Possible values are as follows:
		                                \n \b 0 - no
		                                \n \b 1 - yes
		                                \n \b 2 - no detect
		                                \n \b 3 - subscribed value */

    long    DeliveryOrder;          /*!< A numeric parameter that indicates whether the UMTS bearer shall provide in-sequence SDU delivery or not.
		                                \n Possible values are as follows:
		                                \n \b 0 - no
		                                \n \b 1 - yes
		                                \n \b 2 - subscribed value */

    long    GuarBitDL;              /*!< A numeric parameter that indicates the guaranteed number of kbits/s delivered by UMTS  (down-link traffic) at a SAP (provided that there is data to deliver).
		                                \n If the parameter is set to '0' the subscribed value will be requested.
		                                \n This parameter should be provided if the Traffic class is specified as conversational or streaming. */

    long    GuarBitUL;              /*!< A numeric parameter that indicates the guaranteed number of kbits/s delivered to UMTS (up-link traffic) at a SAP (provided that there is data to deliver).
		                                \n If the parameter is set to '0' the subscribed value will be requested.
		                                \n This parameter should be provided if the Traffic class is specified as conversational or streaming. */

    long    MaxBitDL;               /*!< A numeric parameter that indicates the maximum number of kbits/s delivered by UMTS (down-link traffic) at a SAP.
		                                \n This parameter should be provided if the Traffic class is specified as conversational or streaming.
                                        \n If the parameter is set to '0' the subscribed value will be requested. */

    long    MaxBitUL;               /*!< A numeric parameter that indicates the maximum number of kbits/s delivered to UMTS (up-link traffic) at a SAP.
		                                \n This parameter should be provided if the Traffic class is specified as conversational or streaming.
                                        \n 0 means default subscribed value */

    long    TrafficClass;           /*!< A numeric parameter that indicates the type of application for which the UMTS bearer service is optimised.
		                                \n 0 - conversational
		                                \n 1 - streaming
		                                \n 2 - interactive
		                                \n 3 - background
		                                \n 4 - subscribed value */

    long    TransferDelay;          /*!< A numeric parameter (0,1,2,...) that indicates the targeted time between request to transfer an SDU at one SAP to its delivery at the other SAP, in milliseconds.
		                                \n If the parameter is set to '0' the subscribed value will be requested. */

    long    TrafficHandling;        /*!< A numeric parameter (1,2,3,etc) that specifies the relative importance for handling of all SDUs belonging to the UMTS bearer compared to the SDUs of other bearers.
		                                \n If the parameter is set to '0' the subscribed value will be requested. */

    char^    ResErrorRatio;       /*!< A string parameter that indicates the target value for the undetected bit error ratio in the delivered SDUs.
                                         \n If no error detection is requested, Residual bit error ratio indicates the bit error ratio in the delivered SDUs.
		                                 \n The value is specified as 'mEe'. As an example a target residual bit error ratio of 5\b .10<sup>-3 </sup> would be specified as '5E3'. 
                                         \n '0E0' means subscribed value. */

    char^    SDUErrorRatio;       /*!< A string parameter that indicates the target value for the fraction of SDUs lost or detected as erroneous. 
                                        \n SDU error ratio is defined only for conforming traffic.
                                		\n  The value is specified as 'mEe'. As an example a target SDU error ratio of 5\b .10<sup>-3 </sup> would be specified as "5E3". 
                                        \n "0E0" means subscribed value. */
};

/// Defines an API structure used to hold the APN settings for GSM data connections.
/// \n /// <tt><b>\<UMTS and HSDPA devices only\></b></tt>
public ref class ApnSettingsStruct
{ 
public: 
    char^    APN;      /*!< The APN string to use for the connecton */
    long    PDPAddress;         /*!< The PDP address to use for the connection. 0 means dynamic address */
    long    PDPType;            /*!< The PDPType to use for the connection. 0 means PPP, 1 means IP */
};

/// Defines a structure used to hold the general data connection settings.
public ref class ConnectionSettingsStruct
{ 
public: 
	char^    ConnectionName;   /*!< The name of the connection interface (Ras or Ndis name)*/
	char^    Username;         /*!< The user name to use for the connection */
	char^    Password;         /*!< The password to use for the connection */
	char^    DialString;       /*!< The dial string to use for the connection */
	char^    VpnProfile;       /*!< A VPN profile to launch when a connection is created.  (RAS connections on Windows only)*/
    long    UseVpn;                     /*!< Flag specifying that a VPN should be used. (RAS connections on Windows only)*/
    long    IPAddress;                  /*!< Specifies a fixed IP address that should be used for the connection */
    long    PrimaryDNSAddress;          /*!< Specifies a primary DNS that should be used for the connection (Windows only)*/
    long    SecondaryDNSAddress;        /*!< Specifies a secondary DNS that should be used for the connection (Windows only)*/
    long    PrimaryWINSAddress;         /*!< Specifies a primary WINS that should be used for the connection (Windows only)*/
    long    SecondaryWINSAddress;       /*!< Specifies a secondary WINS that should be used for the connection (Windows only)*/
    long    AuthenticationType;         /*!< The authentication type that should be used for the connection.  0 = Automatic, 1 = Password Authentication, 2 = Challenge and Response (Windows Only) */
};

/** \struct ConnectionStatusStruct
This structure is used to hold data connection information.
It is used with method GetConnectionStatus().
*/
public ref class ConnectionStatusStruct
{ 
public: 
    long    status;             /*!< The status of the connection as defined by the ConnectionState enum */
    long    bytesIn;            /*!< The number of bytes received during a connection */
    long    bytesOut;           /*!< The number of bytes sent during a connection */
    long    duration;           /*!< The elapsed time in seconds of a connection */
    long    error;              /*!< A connection related error code, IE a RAS error code on Windows */
    char^   ipAddress;      /*!< The IP Address of a connection */
};

/// \enum ConnectionModeType
/// This enum defines the possible connection mode values.
public enum class ConnectionModeType
{
    CONNECTION_MODE_ETHERNET_MANUAL  = 0x00,     /*!< Manual ethernet mode. Connection is seen as a standard NIC and connection is controlled manually by the user (NDIS on Windows ) */   
    CONNECTION_MODE_ETHERNET_AUTO    = 0x01,     /*!< Automatic ethernet mode. Connection is seen as a standard NIC and connection is started automatically
                                                    whenever a device is inserted. (NDIS on Windows ) */
    CONNECTION_MODE_DIAL_UP          = 0x02,     /*!< Dial up networking mode (For example...RAS on Windows )*/    
    CONNECTION_MODE_MAX              = 0x03,     /*!< Dial up networking mode (For example...RAS on Windows )*/    
};

/// \enum ConnectionState
/// This enum defines values for the state of the connection owned by the device.
public enum class ConnectionState
{
	CONN_STATE_DISCONNECTED    = 0,	/*!< The device is disconnected */
	CONN_STATE_CONNECTING      = 1,	/*!< A connection attempt has been made and the device is trying to connect   */
	CONN_STATE_AUTHENTICATING  = 2,	/*!< A connection attempt has been made and the device is authenticating user credentials */
	CONN_STATE_CONNECTED       = 3,	/*!< The device is connected   */
	CONN_STATE_DISABLED        = 4,	/*!< The device is disabled   */
} ;

/*******************************************************************
END Connectivity related types
********************************************************************/


#if !defined (_NVTL_GOBI_FW_DEFS_)
#define _NVTL_GOBI_FW_DEFS_
/*******************************************************************
Firmware related types
********************************************************************/
public ref class FirmwareImageInfoStruct
{ 
public: 
    char			*path; 
    unsigned long	firmwareID;
    unsigned long	technology;
    unsigned long	carrier;
    unsigned long	region;
    unsigned long	GPSCapability;
} ;
/*******************************************************************
END Firmware related types
********************************************************************/
}
#endif //_NVTL_GOBI_FW_DEFS_

#pragma pack(pop)


#endif //_NVTL_API_DEFS_H_
