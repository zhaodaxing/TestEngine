#pragma once
#include <string>
namespace Hazel 
{ 
	class Shader
	{
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();
		void Bind();
		void UnBind();

	private:
		unsigned int m_RendererID;
	};

}