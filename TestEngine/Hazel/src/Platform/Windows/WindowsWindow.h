// WindowsWindow.h
#pragma once

#include "Hazel/Window.h"
#include <GLFW/glfw3.h>

namespace Hazel {

	// ��Ϸ�Ĵ���
	class WindowsWindow : public Window
	{
	public:
		// const �������治���޸�props������
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		// override ��������Ӹ�����д������Ĭ���¶���ķ���
		void OnUpdate() override;

		// inline �������Ż�������ջ�ڴ濪��������ʱ������滻
		// const �ڷ����ĺ��棬���������������ݲ����޸������������
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		// ��ֱͬ�����ã���ֹ������ʾ˺��
		void SetVSync(bool enable) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		// OpenGL ����һ������
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}


