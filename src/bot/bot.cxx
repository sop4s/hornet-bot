#include "bot.hxx"
#include <dpp/dpp.h>

using dpp::json;
using std::cout;
using std::endl;

Bot::Bot() : client("") {}
void Bot::load_config(const char* file_path) {
	std::ifstream config_file(file_path);
	config = json::parse(config_file);
}
void Bot::run_cmd(const dpp::slashcommand_t& event) {
	for (auto cmd : cmds) {
		if (cmd.name != event.command.get_command_name()) continue;
		cout << "cmd: " << cmd.name << endl;
		cmd.fn(client, event);
	}
}
void Bot::register_events() {
	client.on_log(dpp::utility::cout_logger());
	client.on_slashcommand([this](const dpp::slashcommand_t& event) {
		run_cmd(event);
	});
	client.on_guild_member_add([this](dpp::guild_member_add_t event) {
		on_new_member(event);	
	});
	client.on_ready([this](const dpp::ready_t& event) {
		if (dpp::run_once<struct register_bot_commands>()) {
			client.global_command_create(dpp::slashcommand("ping", "pong", client.me.id));
		}
	});
	
}
void Bot::run(string token) {
	client.token = token;
	client.start(dpp::st_wait);
}
void Bot::set_intents(uint32_t intents) {
	client.intents = intents;
}
void Bot::set_commands(const std::list<cmd::cmd_list>& command_list) {
	cmds = command_list;
}

void Bot::on_new_member(dpp::guild_member_add_t& event) {
	string user = event.added.get_user()->username;
	if (!user.empty()) {
		dpp::message msg(config["greeting_channel_id"], 
				"Bienvenido al servidor, " + user);
		client.message_create(msg);
	}
}

