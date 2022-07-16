// Window.h
#pragma once

#include "hzpch.h"

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

namespace Hazel {
	// ����window����
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Aurora Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			:Title(title), Width(width), Height(height)
		{
		}
	};

	// ���崰�ڻ���
	class HAZEL_API Window
	{
	public:
		// �����¼������ţ������ȣ�C++11���﷨
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() {}
		// ��ǰ�����������ǻ���PC������ʵ�֣��������Ǵ��壬����update
		// -> ����update -> ��Ϸ
		virtual void OnUpdate() = 0;

		// virtual + =0 ��ʾ����һ�����鷽�������������ʵ�֣�Ҫ�������޷�ͨ��
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enable) = 0;
		virtual bool IsVSync() const = 0;

		// ���ﶨ��һ����̬��Create����������ΪWindowProps��ȫ��ʹ�õ�Ĭ������
		// ���������WindowsWindow.cpp����ʵ��
		static Window* Create(const WindowProps& prop = WindowProps());
	};
}
