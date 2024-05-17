#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace NarcEngine
{

	class Window
	{
	public:
		Window();
		~Window();

		void Init();
		void Update();
		void Stop();

		void CreateSurface(VkInstance instance, VkSurfaceKHR* surface);

		const inline bool ShouldClose() const { return m_windowShouldClose; }
		void GetFrameBufferSize(int* width, int* height) const;

	private:
		GLFWwindow* m_window;

		bool m_windowShouldClose = false;
	};
}