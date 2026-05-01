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
using dpp::cluster;

#define CONFIG_FILE "../config.json"

std::list<cmd::cmd_list> cmds = {
	{ "ping", "pong", cmd::ping }
};


int main() {
	Bot bot;
	bot.load_config(CONFIG_FILE);
	bot.set_commands(cmds);
	bot.set_intents(dpp::i_default_intents | dpp::i_guild_members);
	cout << "iniciando con token: " << bot.config["token"] << endl;
	bot.register_events();
	bot.run(bot.config["token"]);
	return 0;
	/*
	json config = get_config();
	if (config == nullptr) {
		cout << "error: couldn't find config.json" << endl;
		return 1;
	}
	string token = config["token"];
	string greeting = config["greeting_message"];
	ulong greeting_id = config["greeting_channel_id"];

	cluster bot(token, dpp::i_default_intents | dpp::i_guild_members);

	bot.on_log(dpp::utility::cout_logger());
	bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
		execute_command(bot, event);
	});
	bot.on_guild_member_add([&bot, &greeting_id](dpp::guild_member_add_t event) {
			string user = event.added.get_user()->username;
			if (!user.empty()) {
				dpp::message msg(greeting_id, "Bienvenido al servidor, " + user);
				bot.message_create(msg);
			}
	});
	bot.on_ready([&bot](const dpp::ready_t& event) {
		if (dpp::run_once<struct register_bot_commands>()) {
			bot.global_command_create(dpp::slashcommand("ping", "pong", bot.me.id));
		}
	});
	
	bot.start(dpp::st_wait);
	return 0;
	*/
}


json get_config() {
	std::ifstream config_file("../config.json");
	if (config_file.fail()) return nullptr;
	return json::parse(config_file);
}

void execute_command(dpp::cluster& bot, const dpp::slashcommand_t& event) {
	string name = event.command.get_command_name();
		for (auto cmd : cmds) {
			if (name == cmd.name) {
				cmd.fn(bot, event);
				break;
			}
		}
}
