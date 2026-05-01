#include "commands.hxx"
#include "utils/utils.hxx"
namespace cmd {
	void shaw(dpp::json& config, dpp::cluster& bot, const dpp::slashcommand_t& event) {
		string msg = "SHAW " + emote(config, "guatafak");
		event.reply(msg);
	}
}
