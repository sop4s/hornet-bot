#ifndef COMMANDS_HXX
#define COMMANDS_HXX

#include <dpp/appcommand.h>
#include <functional>
#include <string>
#include <dpp/dpp.h>

using std::string;
using std::function;

struct cmd_parameter {
	string name;
	string description;
	dpp::command_option_type type;
};
namespace cmd {
	struct cmd_list {
		string name;
		string description;
		function<void(dpp::json&, dpp::cluster&, const dpp::slashcommand_t&)> fn;
		std::list<cmd_parameter> parameters;
	};
	void ping(dpp::json& config, dpp::cluster& bot, const dpp::slashcommand_t& event);
	void shaw(dpp::json& config, dpp::cluster& bot, const dpp::slashcommand_t& event);
	void say(dpp::json& config, dpp::cluster& bot, const dpp::slashcommand_t& event);
	void stop(dpp::json& config, dpp::cluster& bot, const dpp::slashcommand_t& event);
}
#endif
