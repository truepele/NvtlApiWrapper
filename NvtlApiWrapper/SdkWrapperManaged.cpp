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
}

NvtlApiWrapper::ApiWrapper::~ApiWrapper()
{
	delete _sdk;
	delete _devlistSize;
	delete _device_list;
	
}

unsigned short NvtlApiWrapper::ApiWrapper::AttachDevice(DeviceDetailManaged^ deviceDetail)
{
	DeviceDetail* pDevDetail;
	unsigned short result = SHRT_MAX;	

	for (unsigned long i = 0; i < *_devlistSize; i++)
	{
		if (System::String::CompareOrdinal(deviceDetail->szPort, Marshal::PtrToStringAnsi((IntPtr)_device_list[i].szPort)) == 0)
		{			
			result = _sdk->AttachDevice(&_device_list[i]);
		}
	}

	return result;
}

bool NvtlApiWrapper::ApiWrapper::Init()
{	
	//Check to see if SDK loaded okay
	if (!_sdk->IsLoaded())
	{
		return false;
	}

	short rval = _sdk->CreateSession();

	rval = _sdk->RegisterEventCallback();

	return true;
}

array<NvtlApiWrapper::DeviceDetailManaged^>^ NvtlApiWrapper::ApiWrapper::GetAvailableDevices()
{
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

		return resultArray;
	}
	else
	{
		return nullptr;
	}	
}

unsigned long NvtlApiWrapper::ApiWrapper::getSignalStrenght()
{
	return _sdk->SignalStrenght;
}
unsigned long NvtlApiWrapper::ApiWrapper::getDeviceError()
{
	return _sdk->DeviceError;
}
bool NvtlApiWrapper::ApiWrapper::getIsDeviceAttached()
{
	return _sdk->IsDeviceAttached;
}

bool NvtlApiWrapper::ApiWrapper::IsOK()
{
	return _sdk->IsDeviceAttached && _sdk->DeviceError == 0;
}

void NvtlApiWrapper::ApiWrapper::DetachDevice()
{
	_sdk->DetachDevice();
}

void NvtlApiWrapper::ApiWrapper::ReleaseSession()
{
	_sdk->UnregisterEventCallback();
	_sdk->ReleaseSession();
}
