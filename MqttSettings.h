#pragma once

//******************************************************
// Includes
//******************************************************

#include <SettingsGroup.h>

//******************************************************
// Classes
//******************************************************

class MqttSettings : public SettingsGroup
{
private:
    Setting<bool> enabled = Setting<bool>("enabled");
    Setting<String> server = Setting<String>("server");
    Setting<int> port = Setting<int>("port");
    //Setting<int> port2 = Setting<int>("");
    //Setting<int> fixedAngle = Setting<int>("fixedAngle");
    Setting<String> username = Setting<String>("username");
    Setting<String> password = Setting<String>("password");
    Setting<String> discoPrefix = Setting<String>("discoPrefix");
    Setting<String> topic = Setting<String>("topic");

protected:
    virtual void OnInit() override;
    virtual void OnSetDefault() override;
    virtual void OnSave() override;

    virtual void Print() override;

public:
    MqttSettings() : SettingsGroup("Mqtt") {}

    Setting<bool>& Enabled() { return enabled; }
    Setting<String>& Server() { return server; }
    Setting<int>& Port() { return port; }
    Setting<String>& Username() { return username; }
    Setting<String>& Password() { return password; }
    Setting<String>& DiscoPrefix() { return discoPrefix; }
    Setting<String>& Topic() { return topic; }
};