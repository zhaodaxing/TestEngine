// Window.h
#pragma once

#include "hzpch.h"

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

namespace Hazel {
	// 定义window属性
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

	// 定义窗口基类
	class HAZEL_API Window
	{
	public:
		// 窗口事件，缩放，拉扯等，C++11新语法
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() {}
		// 当前制作的引擎是基于PC窗口来实现，最外层的是窗体，窗体update
		// -> 内容update -> 游戏
		virtual void OnUpdate() = 0;

		// virtual + =0 表示这是一个纯虚方法，派生类必须实现，要不编译无法通过
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enable) = 0;
		virtual bool IsVSync() const = 0;

		// 这里定义一个静态的Create方法，参数为WindowProps，全部使用的默认数据
		// 这个方法在WindowsWindow.cpp里面实现
		static Window* Create(const WindowProps& prop = WindowProps());
	};
}
