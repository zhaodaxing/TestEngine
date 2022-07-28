﻿#include "hzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

Hazel::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
:m_WindowHandle(windowHandle)
{
	HZ_CORE_ASSERT(windowHandle, "window handle is null!");
}

void Hazel::OpenGLContext::Init()
{
	glfwMakeContextCurrent(m_WindowHandle);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	HZ_CORE_ASSERT(status, "Failed to initialize Glad!");
}

void Hazel::OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_WindowHandle);
}
