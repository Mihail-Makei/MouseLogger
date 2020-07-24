#include <ntddk.h>

VOID UnloadDriver(PDRIVER_OBJECT); // Unloads driver and destroys all the devices
NTSTATUS

NTSTATUS DriverEntry(
	PDRIVER_OBJECT	DriverObject,
	PUNICODE_STRING	RegistryPath
) {
	NTSTATUS status;
	int i = 0;


	DriverObject->DriverUnload = UnloadDriver;

	DbgPrint("Hello World!\r\n");
	
	return STATUS_SUCCESS;
}

VOID UnloadDriver(PDRIVER_OBJECT DriverObject) {
	DbgPrint("Driver unloaded!\r\n");
}