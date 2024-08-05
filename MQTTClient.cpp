//******************************************************
// Includes
//******************************************************

//#include <ArduinoJson.h>

#include "MQTTClient.h"
#include "../../src/config.h"
#include "System.h"

//******************************************************
// Usings
//******************************************************

using namespace std::placeholders;

//******************************************************
// Local variables
//******************************************************

//******************************************************
// Public Methods
//******************************************************

bool MQTTClient::Init()
{
    if (!mqttSettings.Init())
        return false;

    if (client.connected())
    {
        client.disconnect();
        isInitialized = false;
    }
    if (mqttSettings.Server().Value() && mqttSettings.Port() && mqttSettings.Username().Value() && mqttSettings.Password().Value())
    {
        Serial.printf("Setting MQTT server to %s with port %i\n", mqttSettings.Server().Value().c_str(), mqttSettings.Port().Value());

        client.setServer(mqttSettings.Server().Value(), mqttSettings.Port());
        client.setCallback(std::bind(&MQTTClient::MqttCallback, this, _1, _2, _3));

        stateTopic = mqttSettings.Topic().Value() + String("/tele/stat");
        debugTopic = mqttSettings.Topic().Value() + String("/debug");
        debugSetTopic = mqttSettings.Topic().Value() + String("/debug/set");

        isInitialized = true;
        return true;
    }
    return false;
}

void MQTTClient::Update()
{
    static unsigned long nextConnect = millis();

    if (!isInitialized || !mqttSettings.Enabled())
        return;

    /* MQTT */
    if (!client.connected())
    {
        if (millis() >= nextConnect)
        {
            char mqtt_server[40];
            strcpy(mqtt_server, mqttSettings.Server().Value().c_str());


            Serial.printf("MQTT Connecting to server with topic %s, username %s, password %s\n", mqttSettings.Topic().Value().c_str(), mqttSettings.Username().Value().c_str(), mqttSettings.Password().Value().c_str());
            if (client.connect(mqttSettings.Topic().Value().c_str(), mqttSettings.Username().Value().c_str(), mqttSettings.Password().Value().c_str()))
            {
                Serial.println("MQTT connected");
                AutoDiscovery();
            }
            else
            {
                Serial.println("MQTT connect failed");
                nextConnect = millis() + 5000;
            }
        }
    }
    else
        client.loop();
}

//******************************************************
// Protected Methods
//******************************************************

//******************************************************
// Private Methods
//******************************************************
