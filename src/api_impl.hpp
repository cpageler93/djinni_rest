#pragma once
#include "api.hpp"
#include "thread_launcher.hpp"

namespace djinni_rest {

	class Api final : public djinni_rest_gen::Api {
	public:

		Api(
			const std::shared_ptr<djinni_rest_gen::ThreadLauncher> & launcher
		);

		virtual void do_something();
	private:
		std::shared_ptr<djinni_rest_gen::ThreadLauncher> m_thread_launcher;
	};

}
