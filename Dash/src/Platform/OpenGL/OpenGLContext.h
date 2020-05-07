#pragma once

#include "Dash/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Dash
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);
		
		void Init() override;
		void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}