#include "problem.h"

int problem2(bool* show, const s_game_context* game, s_profile_context* profile) {
    int status = 0;
    do {
        if (!ImGui::Begin("Problem2", show))
            break;
        // write code here
        // do not use return, use /* status = -1; break; */ instead.

    } while (false);
    ImGui::End();
    return status;
}
