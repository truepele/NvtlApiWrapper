#ifndef _SDK_WRAPPERMANAGED_H

#define _SDK_WRAPPERMANAGED_H

#include "platform_inc.h"
#include "NvtlApiDefinitions.h"
#include "SdkWrapper.h"


#if defined(_NVTL_WINDOWS_)
#include <windows.h>
#include <stdio.h>
#include <wtypes.h>
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
	public ref class DeviceDetailManaged
	{
	public:
		DeviceTechType          eTechnology;		         /*!< technology type of the device */
		DeviceFormFactorType    eFormFactor;				 /*!< physical form factor */
		System::String^            szDescription;	 /*!< general name of the device */
		System::String^            szPort;         /*!< name of the modem port */
		System::String^           szFriendlyName; /*!< friendly name of the modem port */
	};

	public ref class NetworkInfoManaged
	{
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
	};

	public enum DeviceStateTypeManaged
	{
		NW_DEVICE_STATE_UNKNOWN = 0,  /*!< The state of device cannot be determined. Usually sent during startup of the SDK. */
		NW_DEVICE_STATE_NOCARD = 1,  /*!< No device has been detected */
		NW_DEVICE_STATE_INITIALIZING = 2,  /*!< The SDK has recognized a device and is currently in the process of connecting to and initializing it for use.
										   * Generally the device is not yet ready for normal operation and clients should wait until the SDK leaves this state before proceeding. */
		NW_DEVICE_STATE_DISABLED = 3,  /*!< Indicates that a valid device is detected but is disabled. This is generally due to a software or hardware control switch being turned off on the host. */
		NW_DEVICE_STATE_LOCKED = 4,  /*!< Indicates that a device is detected but is currently locked and requires a PIN or PUK to be entered before use. */
		NW_DEVICE_STATE_SEARCHING = 5,  /*!< Indicates that the device is available and is currently searching for network service. */
		NW_DEVICE_STATE_IDLE = 6,  /*!< Indicates that the device is available for general use. This state indicates the normal ready state of the device. */
		NW_DEVICE_STATE_CONNECTING = 7,  /*!< A connection attempt has been made and the device is trying to establish a data connection. */
		NW_DEVICE_STATE_AUTHENTICATING = 8,  /*!< A connection attempt has been made and the device is authenticating user credentials for the data connection. */
		NW_DEVICE_STATE_CONNECTED = 9,  /*!< Indicates that the device has an active data connection */
		NW_DEVICE_STATE_RESERVED_2 = 10, /*!< <tt><b>(not used)</b></tt> */
		NW_DEVICE_STATE_ACTIVATION = 11, /*!< <tt><b>(not used)</b></tt> */
		NW_DEVICE_STATE_NULL = 0xFF /*!< <tt><b>(not used)</b></tt> */
	};

	public enum class NvtlEventTypeManaged
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

	public ref class StandardEventManaged
	{
	public:
		ULONG val;  /*!< The value of the event */
	};

	public ref class ApiWrapper
	{

	public:
		ApiWrapper();
		~ApiWrapper();
		delegate void EventHandlerDelegate(void* user_data, unsigned long type, unsigned long size, void* ev);

		delegate void DeviceDataReceivedDelegate(Object^ userData, NvtlEventTypeManaged eventType, ULONG size, ULONG value);

		//event DeviceDataReceivedDelegate^ DeviceDataReceived
		//{
		//	void add(DeviceDataReceivedDelegate^ handler)
		//	{
		//		//just attach user handler to your private event
		//		_deviceDataReceivedDelegate += handler;
		//	}
		//	void remove(DeviceDataReceivedDelegate^ handler)
		//	{
		//		//just detach the user handler from your private handler
		//		_deviceDataReceivedDelegate -= handler;
		//	}
		//	void raise(Object^ userData, NvtlEventTypeManaged eventType, ULONG size, ULONG value)
		//	{
		//		//raise your private event
		//		_deviceDataReceivedDelegate(userData, eventType, size, value);
		//	}
		//};


		void ReleaseSession();
		void DetachDevice();
		//GetDeviceInfo(..);
		//GetNetworkInfo(..);


		bool Init();
		unsigned short AttachDevice(DeviceDetailManaged^ deviceDetail);
		array<DeviceDetailManaged^>^ GetAvailableDevices();
		unsigned long getSignalStrenght();		
		unsigned long getDeviceError();
		bool getIsDeviceAttached();
		bool IsOK();

	private:
		DeviceDataReceivedDelegate^ _deviceDataReceivedDelegate;

		SdkWrapper *_sdk;		
		//DeviceInfoStruct	*_device_info;
		//NetworkInfoStruct	*_network_info;
		DeviceDetail	*_device_list;
		unsigned long *_devlistSize;

	};
}
#endif