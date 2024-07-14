//******************************************************
// Includes
//******************************************************

#include "MqttSettings.h"

//******************************************************
// Public Methods
//******************************************************

bool MqttSettings::HasChanged()
{
    return enabled != loadedEnabled ||
           server != loadedServer ||
           port != loadedPort ||
           username != loadedUsername ||
           password != loadedPassword ||
           discoPrefix != loadeddiscoPrefix ||
           topic != loadedTopic;
}

//******************************************************
// Protected Methods
//******************************************************

void MqttSettings::OnInit()
{
    defaultEnabled = false;
    loadedEnabled = enabled = preferences.getBool("enabled", defaultEnabled);
    loadedServer = server = preferences.getString("server");
    loadedPort = port = preferences.getInt("port", 1883);
    loadedUsername = username = preferences.getString("username");
    loadedPassword = password = preferences.getString("password");
    loadeddiscoPrefix = discoPrefix = preferences.getString("discoPrefix");
    loadedTopic = topic = preferences.getString("topic");

    Print();
}

void MqttSettings::OnSetDefault()
{
    enabled = loadedEnabled = defaultEnabled;

    server = String();
    loadedServer = String();

    port = loadedPort = 1883;

    username = String();
    loadedUsername = String();

    password = String();
    loadedPassword = String();

    discoPrefix = String();
    loadeddiscoPrefix = String();

    topic = String();
    loadedTopic = String();

    preferences.remove("server");
    preferences.remove("port");
    preferences.remove("username");
    preferences.remove("password");
    preferences.remove("discoPrefix");
    preferences.remove("clientId");
    preferences.remove("topic");
}

void MqttSettings::OnReload()
{
    enabled = loadedEnabled;
    server = loadedServer;
    port = loadedPort;
    username = loadedUsername;
    password = loadedPassword;
    discoPrefix = loadeddiscoPrefix;
    topic = loadedTopic;
}

void MqttSettings::OnSave()
{
    if (enabled != loadedEnabled)
    {
        loadedEnabled = enabled;
        preferences.putBool("enabled", enabled);
    }

    if (server != loadedServer)
    {
        loadedServer = server;
        preferences.putString("server", server);
    }

    if (port != loadedPort)
    {
        loadedPort = port;
        preferences.putInt("port", port);
    }

    if (username != loadedUsername)
    {
        loadedUsername = username;
        preferences.putString("username", username);
    }

    if (password != loadedPassword)
    {
        loadedPassword = password;
        preferences.putString("password", password);
    }

    if (discoPrefix != loadeddiscoPrefix)
    {
        loadeddiscoPrefix = discoPrefix;
        preferences.putString("discoPrefix", discoPrefix);
    }

    if (topic != loadedTopic)
    {
        loadedTopic = topic;
        preferences.putString("topic", topic);
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
