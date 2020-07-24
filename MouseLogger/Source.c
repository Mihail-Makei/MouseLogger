#include <ntddk.h>

VOID UnloadDriver(PDRIVER_OBJECT);								// Unloads driver and destroys all the devices
NTSTATUS DispatchPass(PDRIVER_OBJECT, PIRP);

NTSTATUS DriverEntry(
	PDRIVER_OBJECT	DriverObject,
	PUNICODE_STRING	RegistryPath
) {
	DriverObject->DriverUnload = UnloadDriver;					// Unload driver

	for (int i = 0; i <= IRP_MJ_MAXIMUM_FUNCTION; ++i)			// Just do nothing with IRP
		DriverObject->MajorFunction[i] = DispatchPass;

	DriverObject->MajorFunction[IRP_MJ_READ] = DispatchRead;	// Handle the request

	DbgPrint("Hello World!\r\n");								// Just hello world
	
	return STATUS_SUCCESS;
}

VOID UnloadDriver(PDRIVER_OBJECT DriverObject) {
	DbgPrint("Driver unloaded!\r\n");
}