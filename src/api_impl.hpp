#pragma once
#include "../generated-src/cpp/api.hpp"
#include "../generated-src/cpp/thread_launcher.hpp"
#include "../generated-src/cpp/http.hpp"
#include "../generated-src/cpp/http_method.hpp"
#include "../generated-src/cpp/post_model.hpp"
#include "../generated-src/cpp/api_posts_response.hpp"

namespace djinni_rest {

	class Api : public djinni_rest_gen::Api {
	public:

		Api(
			const std::shared_ptr<djinni_rest_gen::ThreadLauncher> & launcher,
			const std::shared_ptr<djinni_rest_gen::Http> & http
		);

		virtual void get_posts_index(const std::shared_ptr<djinni_rest_gen::ApiPostsResponse> & api_posts_response);
		virtual void get_posts_show(int64_t post_id, const std::shared_ptr<djinni_rest_gen::ApiPostsResponse> & api_posts_response);
	private:
		std::shared_ptr<djinni_rest_gen::ThreadLauncher> m_thread_launcher;
		std::shared_ptr<djinni_rest_gen::Http> m_http;
	};

}
