#pragma once

//******************************************************
// Includes
//******************************************************

#include <SettingsGroup.h>
#include <string>

//******************************************************
// Classes
//******************************************************

class MqttSettings : public SettingsGroup
{
private:
    Setting<bool> enabled = Setting<bool>("enabled");
    Setting<std::string> server = Setting<std::string>("server");
    Setting<int> port = Setting<int>("port");
    Setting<std::string> username = Setting<std::string>("username");
    Setting<std::string> password = Setting<std::string>("password");
    Setting<std::string> discoTopic = Setting<std::string>("discoTopic");
    Setting<std::string> topicPrefix = Setting<std::string>("topic");

protected:
    virtual void OnInit() override;
    virtual void OnSetDefault() override;
    virtual void OnSave() override;

    virtual void Print() override;

public:
    MqttSettings() : SettingsGroup("Mqtt") {}

    __always_inline bool GetEnabled() const { return enabled.Value(); }
    __always_inline void SetEnabled(bool value) { enabled.Value(value); }

    __always_inline const std::string &GetServer() { return server.Value(); }
    __always_inline void SetServer(const std::string &value) { server.Value(value); }

    __always_inline int GetPort() const { return port.Value(); }
    __always_inline void SetPort(int value) { port.Value(value); }

    __always_inline const std::string &GetUsername() const { return username.Value(); }
    __always_inline void SetUsername(const std::string &value) { username.Value(value); }

    __always_inline const std::string &GetPassword() const { return password.Value(); }
    __always_inline void SetPassword(const std::string &value) { password.Value(value); }

    __always_inline const std::string &GetDiscoTopic() const { return discoTopic.Value(); }
    __always_inline void SetDiscoTopic(const std::string &value) { discoTopic.Value(value); }

    __always_inline const std::string &GetTopicPrefix() const { return topicPrefix.Value(); }
    __always_inline void SetTopicPrefix(const std::string &value) { topicPrefix.Value(value); }
};