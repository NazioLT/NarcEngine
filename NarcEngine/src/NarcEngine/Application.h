#pragma once

#include "Core.h"


namespace NarcEngine
{
	class GraphicsEngine;

	class NARC_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Start();
		void Run();
		void Stop();

	private:
		GraphicsEngine* m_graphicsEngine;
	};

	Application* CreateApplication();
}