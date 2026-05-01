#include "commands.hxx"
#include <dpp/dpp.h>
namespace cmd {
	void say(dpp::json& config, dpp::cluster& bot, const dpp::slashcommand_t& event) {
		string txt = std::get<std::string>(event.get_parameter("texto"));
		std::cout << "txt: " << txt << std::endl;
		dpp::message msg((long)config["say_channel_id"], txt);
		bot.message_create(msg);
	}
}
