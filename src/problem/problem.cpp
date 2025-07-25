#include "problem.h"

#include <string>

using namespace libmcc;

constexpr int k_problem_count = 2;

extern "C++" {
	int problem1(bool* show, const s_game_context* game, s_camera_context* camera);
	int problem2(bool* show, const s_game_context* game, s_profile_context* profile);
}

static bool g_show_problems[k_problem_count];

template<typename T>
class c_default_value : public i_value<T> {
public:
	c_default_value() : m_value{} {}

	template<typename... Args>
	c_default_value(Args&&... args) : m_value{ std::forward<Args>(args)... } {}

	const T* get() override {
		return &m_value;
	}

	void update(const T* new_value) override {
		m_value = *new_value;
	}
	T m_value;
};

void show_problems() {
	static s_game_context game_context {
		.game = libmcc::_module_halo3
	};

	if (ImGui::Begin("Problems")) {
		for (int i = 0; i < k_problem_count; ++i) {
			auto show = g_show_problems + i;

			ImGui::Checkbox(("Problem " + std::to_string(i + 1)).c_str(), show);

			if (*show) {
				switch (i) {
				case 0: {
					static c_default_value<real_point3d> position_value(1.0f, 2.0f, 4.0f);
					static c_default_value<real_euler_angles2d> rotation_value(0.0f, 0.0f);

					static s_camera_context camera_context{
						.position = &position_value,
						.rotation = &rotation_value,
					};

					problem1(show, &game_context, &camera_context);
				}
					  break;
				case 1: {
					static c_default_value<s_player_profile> profile;

					static s_profile_context profile_value{
						.player = _local_player_0,
						.profile = &profile
					};

					problem2(show, &game_context, &profile_value);
				}
					  break;
				default:
					break;
				}
			}
		}
	}
	ImGui::End();
}
