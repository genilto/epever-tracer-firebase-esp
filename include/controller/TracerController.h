#include <Arduino.h>
#include <Timer.h>        //https://github.com/JChristensen/Timer
#include <ModbusMaster.h> //https://github.com/4-20ma/ModbusMaster
#include "domain/TracerData.h"

#ifndef TracerController_h
#define TracerController_h

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

/**************************************************
* Mantém e gerencia a conexão com Mqtt
**************************************************/
class TracerController
{
private:
    ModbusMaster _node;
    Timer _timer;
    TracerData _data;
    uint8_t _result;
    uint8_t _currentRegistryNumber = 0;

    void AddressRegistry_2000();
    void AddressRegistry_200C();

    void AddressRegistry_3000();
    void AddressRegistry_300E();

    void AddressRegistry_3100();
    void AddressRegistry_310C();
    void AddressRegistry_3110();
    void AddressRegistry_311A();
    void AddressRegistry_311D();

    void AddressRegistry_3200();

    void AddressRegistry_3300();
    void AddressRegistry_3310();
    void AddressRegistry_330A();
    void AddressRegistry_331B();

    // tracer requires no handshaking
    void preTransmission();
    void postTransmission();

    void readManualCoil();
    void readLoadTestAndForceLoadCoil();

    void updateNextRegistryEntry();

public:
    TracerController();
    TracerData* getData();
    void init();
    void update();
};

#endif