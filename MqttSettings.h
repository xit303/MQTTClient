#pragma once

//******************************************************
// Includes
//******************************************************

#include "SettingsBase.h"

//******************************************************
// Classes
//******************************************************

class MqttSettings : public SettingsBase
{
private:
    bool enabled;
    bool loadedEnabled;
    bool defaultEnabled;

    String server;
    String loadedServer;

    int port;
    int loadedPort;

    String username;
    String loadedUsername;

    String password;
    String loadedPassword;

    String discoPrefix;
    String loadeddiscoPrefix;

    String topic;
    String loadedTopic;

protected:
    virtual void OnInit() override;
    virtual void OnSetDefault() override;
    virtual void OnReload() override;
    virtual void OnSave() override;

    virtual void Print() override;

public:
    MqttSettings() : SettingsBase("Mqtt") {}

    virtual bool HasChanged() override;

    void Enabled(bool value) { enabled = value; }
    bool Enabled() { return enabled; }

    void Server(String& value) { server = value; }
    String Server() { return server; }

    void Port(int value) { port = value; }
    int Port() { return port; }

    void Username(String& value) { username = value; }
    String Username() { return username; }

    void Password(String& value) { password = value; }
    String Password() { return password; }

    void DiscoPrefix(String& value) { discoPrefix = value; }
    String DiscoPrefix() { return discoPrefix; }

    void Topic(String& value) { topic = value; }
    String Topic() { return topic; }
};