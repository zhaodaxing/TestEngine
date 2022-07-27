#pragma once
#include "Hazel/Core.h"
#include "Layer.h"

namespace Hazel
{
	class HAZEL_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		//!@brief lay代表普通的layer, Overlay代表离屏幕最远的layer
		//! vector模拟栈， 所以需要两个位置， 一个头部栈顶， 一个栈尾, 所以需要PushOverlay, PushLayers
		void PushLayer(Layer* layer); 
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		unsigned int  m_LayerInsertIndex = 0;
	};
}