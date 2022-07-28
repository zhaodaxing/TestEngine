#pragma once
#include <string>
namespace Hazel 
{ 
	class Shader
	{
	public:
		Shader(const std::string& vertexSource, const std::string& fragmentSource);
		~Shader();
		void Bind();
		void UnBind();

	private:
		unsigned int m_RendererID;
	};

}