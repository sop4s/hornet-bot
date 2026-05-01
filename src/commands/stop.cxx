#include "commands.hxx"
#include "utils/utils.hxx"
namespace cmd {
	void stop(dpp::json& config, dpp::cluster& bot, const dpp::slashcommand_t& event) {
		if (!is_admin(config, event.command.member.user_id)) {
			event.reply("no eres admin wuajaja");
			return;
		}
		exit(0);
	}
}
