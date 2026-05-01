#ifndef BOT_HXX
#define BOT_HXX

#include <dpp/cluster.h>
#include <string>
#include "../commands/commands.hxx"

class Bot {
	public:
		Bot();
		void load_config(const char* file_path);
		void register_events();
		void run(std::string token);
		void set_intents(uint32_t intents);
		void set_commands(const std::list<cmd::cmd_list>& command_list);
		dpp::json config;
	private:
		dpp::cluster client;
		std::list<cmd::cmd_list> cmds;
		void run_cmd(const dpp::slashcommand_t& event);
		void on_new_member(dpp::guild_member_add_t& event);	
};

#endif
