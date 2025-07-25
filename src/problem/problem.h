#pragma once

#include <imgui.h>
#include <libmcc/libmcc.h>

template<typename T>
class i_value {
public:
	virtual const T* get() = 0;
	virtual void update(const T* new_value) = 0;
};

struct s_game_context {
	libmcc::e_module game;
};

struct s_camera_context {
	i_value<libmcc::real_point3d>* position;
	i_value<libmcc::real_euler_angles2d>* rotation;
};

struct s_profile_context {
	libmcc::e_local_player player;
	i_value<libmcc::s_player_profile>* profile;
};

void show_problems();