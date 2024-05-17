#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <vector>
#include <map>
#include <optional>
#include <set>
#include <cstdint>
#include <limits>
#include <algorithm> 
#include <fstream>

namespace NarcEngine
{
	struct QueueFamilyIndices;
	struct SwapChainSupportDetails;

	class GraphicsEngine
	{
	public:
		void Start();
		void Update();
		void Stop();

		const inline bool ShouldClose() const { return m_windowShouldClose; }

	private:
		GLFWwindow* m_window;
		VkInstance m_instance;
		VkDebugUtilsMessengerEXT m_debugMessenger;
		VkDevice m_device;
		VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
		VkSurfaceKHR m_surface;

		VkQueue m_presentQueue;
		VkQueue m_graphicsQueue;

		VkSwapchainKHR m_swapChain;
		std::vector<VkImage> m_swapChainImages;
		VkFormat m_swapChainImageFormat;
		VkExtent2D m_swapChainExtent;
		std::vector<VkImageView> m_swapChainImageViews;
		std::vector<VkFramebuffer> m_swapChainFramebuffers;

		VkRenderPass m_renderPass;
		VkPipelineLayout m_pipelineLayout;
		VkPipeline m_graphicsPipeline;
		VkCommandPool m_commandPool;
		VkCommandBuffer m_commandBuffer;

		//Sync objects -> Waiting them to make operation... cf doc vulkan
		VkSemaphore m_imageAvailableSemaphore;
		VkSemaphore m_renderFinishedSemaphore;
		VkFence m_inFlightFence;

		bool m_windowShouldClose = false;

	private:
		void InitWindow();
		void InitVulkan();
		void CleanUp();

		void CreateInstance();
		void SetupDebugMessenger();
		void CreateSurface();
		void PickPhysicalDevice();
		void CreateLogicalDevice();
		void CreateSwapChain();
		void CreateImageViews();
		void CreateRenderPass();
		void CreateGraphicsPipeline();
		void CreateFramebuffers();
		void CreateCommandPool();
		void CreateCommandBuffer();
		void CreateSyncObjects();

		void DrawFrame();

		bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
		int RateDeviceSuitability(VkPhysicalDevice device);
		bool CheckValidationLayerSupport();
		std::vector<const char*> GetRequiredExtensions();
		void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
		QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
		SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);
		VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
		VkShaderModule CreateShaderModule(const std::vector<char>& code);
		void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

		static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
			VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
			VkDebugUtilsMessageTypeFlagsEXT messageType,
			const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
			void* pUserData);
		static std::vector<char> ReadFile(const std::string& filename);
	};
}