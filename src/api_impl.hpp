#pragma once
#include "api.hpp"
#include "thread_launcher.hpp"
#include "http.hpp"
#include "http_method.hpp"
#include "api_response.hpp"
#include "post_model.hpp"
#include "posts_index_response.hpp"

namespace djinni_rest {

	class Api : public djinni_rest_gen::Api {
	public:

		Api(
			const std::shared_ptr<djinni_rest_gen::ThreadLauncher> & launcher,
			const std::shared_ptr<djinni_rest_gen::Http> & http
		);

		virtual void do_something(const std::shared_ptr<djinni_rest_gen::ApiResponse> & api_response);
		virtual void get_posts_index(const std::shared_ptr<djinni_rest_gen::PostsIndexResponse> & posts_index_response);
	private:
		std::shared_ptr<djinni_rest_gen::ThreadLauncher> m_thread_launcher;
		std::shared_ptr<djinni_rest_gen::Http> m_http;
	};

}
