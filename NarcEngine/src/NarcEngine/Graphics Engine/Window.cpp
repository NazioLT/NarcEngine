#include "Window.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>

namespace NarcEngine
{
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;

	Window::Window()
	{
	}

	Window::~Window()
	{
	}

	void Window::Init()
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		m_window = glfwCreateWindow(WIDTH, HEIGHT, "Narcoleptic Engine", nullptr, nullptr);
	}

	void Window::Update()
	{
		m_windowShouldClose = glfwWindowShouldClose(m_window);
		glfwPollEvents();
	}

	void Window::Stop()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	void Window::CreateSurface(VkInstance instance, VkSurfaceKHR* surface)
	{
		if (glfwCreateWindowSurface(instance, m_window, nullptr, surface) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create window surface!");
		}
	}

	void Window::GetFrameBufferSize(int* width, int* height) const
	{
		glfwGetFramebufferSize(m_window, width, height);
	}
}