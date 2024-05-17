#include "Application.h"

#include "GraphicsEngine.h"

namespace NarcEngine
{
	Application::Application()
	{
		m_engine = new GraphicsEngine();
	}

	Application::~Application()
	{
		delete m_engine;
	}

	void Application::Start()
	{
		m_engine->Start();
	}

	void Application::Run()
	{
		while (!m_engine->ShouldClose())
		{
			m_engine->Update();
		}
	}
	void Application::Stop()
	{
		m_engine->Stop();
	}
}