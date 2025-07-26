#include "problem.h"

/*
	Problem 1: Camera Properties
	- Display and modify camera properties.
*/
int problem1(bool* show, const s_game_context* game, s_camera_context* camera) {
    int status = 0;
    do {
        if (!ImGui::Begin("Problem1", show))
            break;
        // write code here
        // do not use return, use /* status = -1; break; */ instead.

    } while (false);
    ImGui::End();
    return status;
}