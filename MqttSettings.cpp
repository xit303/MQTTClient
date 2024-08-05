//******************************************************
// Includes
//******************************************************

#include "MqttSettings.h"

//******************************************************
// Protected Methods
//******************************************************

void MqttSettings::OnInit()
{
    bool b = preferences.getBool(enabled.Name(), enabled.DefaultValue());
    enabled.LoadedValue(b);
    settings.push_back(&enabled);

    char s[512];
    if (preferences.getString(server.Name(), s, 512))
        server.LoadedValue(s);
    settings.push_back(&server);

    port.DefaultValue(1883);
    int i = preferences.getInt(port.Name(), port.DefaultValue());
    port.LoadedValue(i);
    settings.push_back(&port);

    if (preferences.getString(username.Name(), s, 512))
        username.LoadedValue(s);
    settings.push_back(&username);

    if (preferences.getString(password.Name(), s, 512))
        password.LoadedValue(s);
    settings.push_back(&password);

    if (preferences.getString(discoPrefix.Name(), s, 512))
        discoPrefix.LoadedValue(s);
    settings.push_back(&discoPrefix);

    if (preferences.getString(topic.Name(), s, 512))
        topic.LoadedValue(s);
    settings.push_back(&topic);

    Print();
}

void MqttSettings::OnSetDefault()
{
    preferences.remove(server.Name());
    preferences.remove(port.Name());
    preferences.remove(username.Name());
    preferences.remove(password.Name());
    preferences.remove(discoPrefix.Name());
    preferences.remove(topic.Name());
}

void MqttSettings::OnSave()
{
    if (enabled.HasChanged())
    {
        preferences.putBool(enabled.Name(), enabled);
    }

    if (server.HasChanged())
    {
        preferences.putString(server.Name(), server);
    }

    if (port.HasChanged())
    {
        preferences.putInt(port.Name(), port);
    }

    if (username.HasChanged())
    {
        preferences.putString(username.Name(), username);
    }

    if (password.HasChanged())
    {
        preferences.putString(password.Name(), password);
    }

    if (discoPrefix.HasChanged())
    {
        preferences.putString(discoPrefix.Name(), discoPrefix);
    }

    if (topic.HasChanged())
    {
        preferences.putString(topic.Name(), topic);
    }

    Print();
}

void MqttSettings::Print()
{
    Serial.print("Enabled: ");
    Serial.println(enabled);

    Serial.print("Server: ");
    Serial.println(server);

    Serial.print("Port: ");
    Serial.println(port);

    Serial.print("Username: ");
    Serial.println(username);

    Serial.print("Password: ");
    Serial.println(password);

    Serial.print("DiscoPrefix: ");
    Serial.println(discoPrefix);

    Serial.print("Topic: ");
    Serial.println(topic);
}

//******************************************************
// Private Methods
//******************************************************
