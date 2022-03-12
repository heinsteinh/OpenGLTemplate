#pragma once

struct GLFWwindow;

class Application
{
public:
	virtual ~Application();

	void Run();
protected:
	Application();

	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Shutdown() = 0;
private:
	GLFWwindow* m_WindowHandle = nullptr;
};
