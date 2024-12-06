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
    // if (!mqttSettings.Init())
    //     return false;

    if (mqttSettings.GetServer().empty())
    {
        return false;
    }
    if (mqttSettings.GetPort() == 0)
    {
        return false;
    }
    if (mqttSettings.GetUsername().empty())
    {
        return false;
    }
    if (mqttSettings.GetPassword().empty())
    {
        return false;
    }

    if (client.connected())
    {
        client.disconnect();
        isInitialized = false;
    }

    Serial.printf("Setting MQTT server to %s with port %i\n", mqttSettings.GetServer().c_str(), mqttSettings.GetPort());

    client.setServer(mqttSettings.GetServer().c_str(), mqttSettings.GetPort());
    client.setCallback(std::bind(&MQTTClient::MqttCallback, this, _1, _2, _3));

    stateTopic = mqttSettings.GetTopic() + "/tele/stat";
    debugTopic = mqttSettings.GetTopic() + "/debug";
    debugSetTopic = mqttSettings.GetTopic() + "/debug/set";

    isInitialized = true;
    return true;
}

void MQTTClient::Update()
{
    static unsigned long nextConnect = millis();

    if (!isInitialized || !mqttSettings.GetEnabled())
        return;

    /* MQTT */
    if (!client.connected())
    {
        if (millis() >= nextConnect)
        {
            char mqtt_server[40];
            strcpy(mqtt_server, mqttSettings.GetServer().c_str());

            Serial.printf("MQTT Connecting to server [%s:%i] with topic [%s], username [%s], password [%s]\n", mqttSettings.GetServer().c_str(), mqttSettings.GetPort(), mqttSettings.GetTopic().c_str(), mqttSettings.GetUsername().c_str(), mqttSettings.GetPassword().c_str());
            if (client.connect(mqttSettings.GetTopic().c_str(), mqttSettings.GetUsername().c_str(), mqttSettings.GetPassword().c_str()))
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
