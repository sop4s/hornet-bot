#include "commands.hxx"
namespace cmd {
	void ping(dpp::cluster& bot, const dpp::slashcommand_t& event) {
		event.reply("pong");
	}
}
