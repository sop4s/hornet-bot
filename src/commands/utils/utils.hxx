#ifndef UTILS_HXX
#define UTILS_HXX

#include <string>
#include <dpp/dpp.h>

using std::string;

string emote(dpp::json& config, string key);
bool is_admin(dpp::json& config, long user_id);

#endif
