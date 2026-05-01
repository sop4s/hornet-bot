#ifndef COMMANDS_HXX
#define COMMANDS_HXX
#include <dpp/dpp.h>

using std::string;

namespace cmd {
	struct cmd_list {
		string name;
		string description;
		std::function<void(dpp::cluster& bot, const dpp::slashcommand_t& event)> fn;
	};
	void ping(dpp::cluster& bot, const dpp::slashcommand_t& event);
}

#endif
