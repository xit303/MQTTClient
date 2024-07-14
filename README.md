# MQTTClient

This is the basic implementation of my MQTT client for ESP8266 and ESP32.

It uses a modified/simplified Version of [knolleary's PubSubClient](https://github.com/knolleary/pubsubclient) which is published under MIT license.

The `MQTTSettings` class allows you to store the MQTT server, port, username, password, discovery prefix and topic in a `Preferences` class which is implemented in my `SettingsBase` class.


The `MQTTClient` class is an abstract class which must be inherited by the final implementation like so

```
class MQTTClientImpl : public MQTTClient
{
protected:
    virtual void MqttCallback(char *topic, byte *payload, unsigned int length) override;
    virtual void AutoDiscovery() override;
    void CreateDevice(String name, const char *valueTemplate, int percision, const char *unitOfMeasurement);

public:
    void OnStatusChanged(float analogValue, float temperature, float humidity, float lux, float adc0, float adc1, float adc2, float adc3);
};
```

The `MQTTClient` uses the `MQTTSettings` for the MQTT initialization.

In the future i will also add a RESTApi HTTP_GET and HTTP_PUT class

To add it to you project (in my case platformio)

```
git submodule add git@github.com:xit303/MQTTClient.git lib/MQTTClient
```

where `lib/MQTTClient` is the destination folder.

Initialize the submodule by typing

```
git submodule update --init
```

