#include "stdafx.h"
#include "SdkWrapperManaged.h"
#include "SdkWrapper.h"



using namespace System;
using namespace System::Runtime::InteropServices;

NvtlApiWrapper::ApiWrapper::ApiWrapper()
{
	_sdk = new SdkWrapper;
	_devlistSize = new unsigned long[1];
	_device_list = new DeviceDetail[5];

	_cb = new NvtlEventCallback;
	_cb->user_data = 0;
	_eventHandlerDelegate = gcnew EventHandlerDelegate(this, &NvtlApiWrapper::ApiWrapper::NativeEventHandler);
	_pUnmanagedEventHandler = Marshal::GetFunctionPointerForDelegate(_eventHandlerDelegate);
	_cb->event_func = (NvtlSdkEventFunc)(void*)_pUnmanagedEventHandler;

}

NvtlApiWrapper::ApiWrapper::~ApiWrapper()
{
	delete _sdk;
	delete _devlistSize;
	delete _device_list;
	delete _eventHandlerDelegate;
	Marshal::FreeHGlobal(_pUnmanagedEventHandler);
	delete _cb;
}

unsigned short NvtlApiWrapper::ApiWrapper::AttachDevice(DeviceDetailManaged^ deviceDetail)
{
	DeviceDetail* pDevDetail;
	unsigned short result = SHRT_MAX;

	//for (unsigned long i = 0; i < *_devlistSize; i++)
	//{
	//	if (strcmp(_device_list[i].szPort, StringToUnmanaged(deviceDetail->szPort)) == 0)
	//	{
//			result = _sdk->AttachDevice(&_device_list[i]);
//		}
//	}

	result = _sdk->AttachDevice(&_device_list[0]);

	/*pDevDetail->eTechnology = deviceDetail->eTechnology;
	pDevDetail->eFormFactor = deviceDetail->eFormFactor;

	strcpy(pDevDetail->szDescription, StringToUnmanaged(deviceDetail->szDescription));
	strcpy(pDevDetail->szPort, StringToUnmanaged(deviceDetail->szPort));

	strcpy(pDevDetail->szFriendlyName, StringToUnmanaged(deviceDetail->szFriendlyName));*/

	return result;
}

char* NvtlApiWrapper::ApiWrapper::StringToUnmanaged(System::String^ stringManaged)
{
	IntPtr p = Marshal::StringToHGlobalAnsi(stringManaged);
	char *pNewCharStr = static_cast<char*>(p.ToPointer());
	Marshal::FreeHGlobal(p);
	return pNewCharStr;
}

bool NvtlApiWrapper::ApiWrapper::Init()
{	
	//Check to see if SDK loaded okay
	if (!_sdk->IsLoaded())
	{
		return false;
	}

	short rval = _sdk->CreateSession();

	rval = _sdk->RegisterEventCallback(*_cb);

	return true;
}

void NvtlApiWrapper::ApiWrapper::NativeEventHandler(void* user_data, unsigned long type, unsigned long size, void* ev)
{
	//if (_deviceDataReceivedDelegate != nullptr && _deviceDataReceivedDelegate->GetInvocationList()->Length>0)
	//{
	//	try
	//	{
	//		//switch (type)
	//		//{
	//		//	/*case NW_EVENT_SIG_STR:
	//		//	case NW_EVENT_ROAMING:
	//		//	case NW_EVENT_SERVER_ERROR:
	//		//	case NW_EVENT_DEVICE_STATE:
	//		//	case NW_EVENT_NETWORK:
	//		//	case NW_EVENT_DEVICE_ADDED:
	//		//	case NW_EVENT_DEVICE_REMOVED:
	//		//	case NW_EVENT_DEVICE_DETACHED:*/
	//		//	case NW_EVENT_DEVICE_ATTACHED:
	//		//		//_deviceDataReceivedDelegate(nullptr, (NvtlEventTypeManaged)type, size, 0);
	//		//		break;
	//		//}
	//	}
	//	catch (Exception^ e)
	//	{}
	//}
}

array<NvtlApiWrapper::DeviceDetailManaged^>^ NvtlApiWrapper::ApiWrapper::GetAvailableDevices()
{
	//DeviceDetail device_list[5];	
	
	//_device_list = (DeviceDetail*)malloc(5 * sizeof(DeviceDetail));
	//memset(_device_list, 0, *_devlistSize * sizeof(DeviceDetail));
	//unsigned short count = 	
	*_devlistSize = 5;
	_sdk->GetAvailableDevices(_device_list, _devlistSize);

	if (*_devlistSize > 0)
	{
		array<NvtlApiWrapper::DeviceDetailManaged^>^ resultArray = gcnew array<NvtlApiWrapper::DeviceDetailManaged^>(*_devlistSize);
		for (unsigned short i = 0; i < *_devlistSize; i++)
		{
			resultArray[i] = gcnew DeviceDetailManaged();
			resultArray[i]->szFriendlyName = gcnew String(_device_list[i].szFriendlyName);//gcnew String((*(_device_list + i*sizeof(DeviceDetail))).szFriendlyName);
			resultArray[i]->eFormFactor = _device_list[i].eFormFactor;
			resultArray[i]->eTechnology = _device_list[i].eTechnology;
			resultArray[i]->szDescription = gcnew String(_device_list[i].szDescription);
			resultArray[i]->szPort = gcnew String(_device_list[i].szPort);
		}

		//array<NvtlApiWrapper::DeviceDetailManaged^>^ resultArray = gcnew array<NvtlApiWrapper::DeviceDetailManaged^>(1);
		//resultArray[0] = gcnew DeviceDetailManaged();
		
		//resultArray[0]->szFriendlyName = Marshal::PtrToStringAnsi((IntPtr)(*_device_list).szFriendlyName);//gcnew String((*_device_list).szFriendlyName);
		
		return resultArray;
	}
	else
	{
		return nullptr;
	}
	///TODO:
}

void NvtlApiWrapper::ApiWrapper::DetachDevice()
{
	_sdk->DetachDevice();
}

void NvtlApiWrapper::ApiWrapper::ReleaseSession()
{
	_sdk->UnregisterEventCallback(*_cb);
	_sdk->ReleaseSession();
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

