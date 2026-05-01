#include "commands.hxx"
namespace cmd {
	void ping(dpp::json& config, dpp::cluster& bot, const dpp::slashcommand_t& event) {
		event.reply("pong");
	}
}
