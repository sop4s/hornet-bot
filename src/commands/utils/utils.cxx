#include "utils.hxx"

string emote(dpp::json& config, string key) {
	string s = config[key];
	if (s.empty()) return ":x:";
	return s;
}
bool is_admin(dpp::json& config, long user_id) {
	for (long id : config["admins"]) 
		if (id == user_id) return true;
	return false;
}
