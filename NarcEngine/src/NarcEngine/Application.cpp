#include "Application.h"

#include "Graphics Engine/GraphicsEngine.h"

namespace NarcEngine
{
	Application::Application()
	{
		m_graphicsEngine = new GraphicsEngine();
	}

	Application::~Application()
	{
		delete m_graphicsEngine;
	}

	void Application::Start()
	{
		m_graphicsEngine->Start();
	}

	void Application::Run()
	{
		while (!m_graphicsEngine->ShouldClose())
		{
			m_graphicsEngine->Update();
		}
	}
	void Application::Stop()
	{
		m_graphicsEngine->Stop();
		std::cin.get();
	}
}