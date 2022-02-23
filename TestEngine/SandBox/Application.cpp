

namespace TestEngine
{
	__declspec(dllimport) void Print();
}
int main()
{
	TestEngine::Print();
	return 0;
}