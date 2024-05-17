#pragma once

#ifdef NARC_ENGINE_PLATFORM_WINDOWS

#include <iostream>

extern NarcEngine::Application* NarcEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto engine = NarcEngine::CreateApplication();

	try
	{
		engine->Start();
		engine->Run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cin.get();

		engine->Stop();
		delete engine;
		return EXIT_FAILURE;
	}

	engine->Stop();
	delete engine;
	return EXIT_SUCCESS;
}

#endif