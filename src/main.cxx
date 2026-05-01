#include <cstdlib>
#include <dpp/intents.h>
#include <iostream>
#include <dpp/dpp.h>
#include <string>
#include "bot/bot.hxx"
#include "commands/commands.hxx"

using std::cout;
using std::endl;
using std::string;
using dpp::json;

#define CONFIG_FILE "../config.json"

std::list<cmd::cmd_list> cmds = {
	{ "ping", "pong", cmd::ping },
	{ "say", "di algo", cmd::say, {{ "texto", "escribe algo papu", dpp::co_string }} },
	{ "shaw", "shaw", cmd::shaw },
	{ "stop", "parar bot", cmd::stop }
};

string censor(string token, int start) {
	string o = token;
	if (o.length() < start) return nullptr;
	for (int i = start; i < o.length(); i++)
		o[i] = '*';
	return o;
}

int main() {
	Bot bot;
	bot.load_config(CONFIG_FILE);
	bot.set_commands(cmds);
	bot.set_intents(dpp::i_default_intents | dpp::i_guild_members);
	bot.register_events();
	
	cout << "TOKEN: " << censor(bot.config["token"], 10) << endl;

	bot.run(bot.config["token"]);
	return 0;
}
