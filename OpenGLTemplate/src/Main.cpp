#include "pch.h"

#include "Application.h"

#include <glad/glad.h>

class OpenGLApplication : public Application
{
protected:
	void Init() override
	{
	}

	void Update(float dt) override
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glColor3f(1.0f, 0.0f, 1.0f);

		glBegin(GL_TRIANGLES);
		glVertex2f( 0.0f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glVertex2f(-0.5f, -0.5f);
		glEnd();
	}

	void Shutdown() override
	{
	}
private:
};

int main()
{
	OpenGLApplication* app = new OpenGLApplication();
	app->Run();
	delete app;
}
