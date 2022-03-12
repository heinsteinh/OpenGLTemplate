#include "pch.h"
#include "Application.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

Application::Application()
{
}

Application::~Application()
{
}

void Application::Run()
{
	Log::Init();
	if (!glfwInit())
		Log::Fatal("Unable to initalize GLFW!");
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	m_WindowHandle = glfwCreateWindow(800, 600, "OpenGLRandomTesting", nullptr, nullptr);
	glfwMakeContextCurrent(m_WindowHandle);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		Log::Fatal("Unable to initalize GLAD!");

	Log::CoreInfo("OpenGL Renderer: {0}, {1}", glGetString(GL_VENDOR), glGetString(GL_RENDERER));
	Log::CoreInfo("OpenGL Version: {0}", glGetString(GL_VERSION));

	Init();

	float delta = 0.0f, lastFrame = (float)glfwGetTime(), time = 0.0f;
	while (!glfwWindowShouldClose(m_WindowHandle))
	{
		time = (float)glfwGetTime();
		delta = time - lastFrame;
		lastFrame = time;

		glfwPollEvents();
		Update(delta);
		glfwSwapBuffers(m_WindowHandle);
	}

	Shutdown();
}
