
#ifndef BLUETOOTH_SERVICE_NOTIFY_H
#define BLUETOOTH_SERVICE_NOTIFY_H

#include "ble/BLE.h"
#include "Interpreter.h"

extern const uint8_t  BluetoothServiceNotifyUUID[];

/*!
 * @class BluetoothServiceNotify
 */
class BluetoothServiceNotify
{
public:

    /*!
     * Constructor.
     * Create a representation of BluetoothServiceNotify
     * @param interpreter Reference to an Interpreter instance
     */
    BluetoothServiceNotify(Interpreter &interpreter);

    /*!
     * Callback. Invoked when any of our attributes are read via BLE.
     */
    void onDataRead(GattReadAuthCallbackParams *params);

    /*!
     * Send data via BLE.
     * @param address
     * @param value
     */
    void send(uint16_t address, uint16_t value);

private:

    Interpreter &interpreter;
    BLEDevice &ble;

    GattAttribute::Handle_t characteristicsHandle;
    uint8_t characteristicsBuffer[4];
    GattCharacteristic characteristic;
};

#endif // BLUETOOTH_SERVICE_NOTIFY_H