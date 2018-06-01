#pragma once

namespace bl {

class Engine {
public:
	Engine();
	void Run();

private:
	bool m_running = true;
};

} // namespace bl
