#include "problem.h"

/*
	Problem 2: Player Profile Settings
	- Display and modify player profile settings.
	- Player can choose to save or discard changes.
*/
int problem2(bool* show, const s_game_context* game, s_profile_context* profile) {
    int status = 0;
    do {
        if (!ImGui::Begin("Problem2", show))
            break;
        // write code here
        // do not use return, use /* status = -1; break; */ instead.

        auto _profile = profile->profile->get();

    } while (false);
    ImGui::End();
    return status;
}
