#include <iostream>

#include <imgui.h>
#include <libmcc/libmcc.h>

#include "./rasterizer/rasterizer.h"
#include "./problem/problem.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//define default procedure for window messages
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam);

	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
		// Handle paint messages here
		return 0;
	case WM_SIZE:
		rasterizer()->resize(
			LOWORD(lParam), 
			HIWORD(lParam));
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}

int main() {
	g_win32_parameter = s_win32_parameter{
		.instance_handle = GetModuleHandle(nullptr),
		.window_proc = WindowProc,
		.window_thread = GetCurrentThreadId(),
		.window_width = 1280,
		.window_height = 720,
		.cmd_show = SW_SHOWDEFAULT,
		.class_name = L"QUIZE",
		.window_name = L"quize",
	};

	if (rasterizer()->initialize()) {
		std::cerr << "Failed to initialize rasterizer." << std::endl;
		return 1;
	}

	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (msg.message == WM_QUIT) {
			break;
		}

		rasterizer()->begin_frame();
		show_problems();
		rasterizer()->end_frame();
	}

	rasterizer()->shutdown();

	return 0;
}