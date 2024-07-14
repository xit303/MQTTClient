#pragma once

//******************************************************
// Includes
//******************************************************

#include <PubSubClient.h>
#include <ESP8266WiFi.h>

#include "IBaseClass.h"
#include "MqttSettings.h"

//******************************************************
// Classes
//******************************************************

class MQTTClient : public IBaseClass
{
protected:
    bool debugMode = true;
    bool isInitialized = false;

    String stateTopic;
    String debugTopic;
    String debugSetTopic;

    MqttSettings mqttSettings;
    WiFiClient wifiClient;
    PubSubClient client = PubSubClient(wifiClient);

    virtual void MqttCallback(char *topic, byte *payload, unsigned int length) = 0;
    virtual void AutoDiscovery() = 0;

public:
    virtual bool Init() override;
    virtual void Update() override;

    bool Initialized() { return isInitialized; }
    bool Enabled() { return mqttSettings.Enabled(); }
    MqttSettings& GetSettings() { return mqttSettings; }
};