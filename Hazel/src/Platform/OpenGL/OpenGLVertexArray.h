﻿#pragma once

#include "Hazel/Renderer/VertexArray.h"

namespace Hazel
{ 
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		void Bind() const override;


		void UnBind() const override;


		void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;


		void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;


		const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const override { return m_VertexBuffers; }

		const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const override { return m_IndexBuffer; }

	private:
		uint32_t m_RendererID;
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;

	};
}

