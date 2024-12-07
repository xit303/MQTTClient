#pragma once

//******************************************************
// Includes
//******************************************************

#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <map>
#include <IBaseClass.h>
#include "MqttSettings.h"

//******************************************************
// Types
//******************************************************

typedef std::function<void(byte *payload, unsigned int length)> MqttTopicCallbackFunction;

//******************************************************
// Classes
//******************************************************

class MQTTClient : public IBaseClass
{
private:
    std::map<std::string, MqttTopicCallbackFunction> topicCallbacks;

    MQTTClient() = delete;

protected:
    bool debugMode = true;
    bool isInitialized = false;

    std::string debugTopic;
    std::string debugSetTopic;

    MqttSettings &mqttSettings;
    WiFiClient wifiClient;
    PubSubClient client = PubSubClient(wifiClient);

    virtual void MqttCallback(char *topic, byte *payload, unsigned int length);
    virtual void AutoDiscovery();

public:
    MQTTClient(MqttSettings &mqttSettings);
    virtual bool Init() override;
    virtual void Update() override;

    bool GetInitialized() { return isInitialized; }
    bool GetEnabled() { return mqttSettings.GetEnabled(); }
    bool GetConnected() { return client.connected(); }
    MqttSettings& GetSettings() { return mqttSettings; }

    void SetTopicCallback(const std::string &topic, MqttTopicCallbackFunction func);
};