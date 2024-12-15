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

    if (preferences.getString(discoTopic.Name(), s, 512))
        discoTopic.LoadedValue(s);
    settings.push_back(&discoTopic);

    if (preferences.getString(topicPrefix.Name(), s, 512))
        topicPrefix.LoadedValue(s);
    settings.push_back(&topicPrefix);

    Print();
}

void MqttSettings::OnSetDefault()
{
    preferences.remove(server.Name());
    preferences.remove(port.Name());
    preferences.remove(username.Name());
    preferences.remove(password.Name());
    preferences.remove(discoTopic.Name());
    preferences.remove(topicPrefix.Name());
}

void MqttSettings::OnSave()
{
    if (enabled.HasChanged())
    {
        preferences.putBool(enabled.Name(), enabled.Value());
    }

    if (server.HasChanged())
    {
        preferences.putString(server.Name(), server.Value().c_str());
    }

    if (port.HasChanged())
    {
        preferences.putInt(port.Name(), port);
    }

    if (username.HasChanged())
    {
        preferences.putString(username.Name(), username.Value().c_str());
    }

    if (password.HasChanged())
    {
        preferences.putString(password.Name(), password.Value().c_str());
    }

    if (discoTopic.HasChanged())
    {
        preferences.putString(discoTopic.Name(), discoTopic.Value().c_str());
    }

    if (topicPrefix.HasChanged())
    {
        preferences.putString(topicPrefix.Name(), topicPrefix.Value().c_str());
    }

    Print();
}

void MqttSettings::Print()
{
    Serial.print("Enabled: ");
    Serial.println(enabled.Value());

    Serial.print("Server: ");
    Serial.println(server.Value().c_str());

    Serial.print("Port: ");
    Serial.println(port.Value());

    Serial.print("Username: ");
    Serial.println(username.Value().c_str());

    Serial.print("Password: ");
    Serial.println(password.Value().c_str());

    Serial.print("Disco topic: ");
    Serial.println(discoTopic.Value().c_str());

    Serial.print("TopicPrefix: ");
    Serial.println(topicPrefix.Value().c_str());
}

//******************************************************
// Private Methods
//******************************************************
