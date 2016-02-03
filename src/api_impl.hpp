#pragma once

#include "../generated-src/cpp/api.hpp"

#include "../generated-src/cpp/thread_launcher.hpp"

#include "../generated-src/cpp/http.hpp"
#include "../generated-src/cpp/http_method.hpp"

#include "../generated-src/cpp/post_model.hpp"
#include "../generated-src/cpp/photo_model.hpp"
//#include "../generated-src/cpp/hello_model.hpp"

#include "../generated-src/cpp/api_posts_response.hpp"
#include "../generated-src/cpp/api_photos_response.hpp"

#include "../deps/json11/json11.hpp"

namespace djinni_rest {

	class Api : public djinni_rest_gen::Api {
	public:

		Api(
			const std::shared_ptr<djinni_rest_gen::ThreadLauncher> & launcher,
			const std::shared_ptr<djinni_rest_gen::Http> & http
		);

		virtual void get_posts_index(const std::shared_ptr<djinni_rest_gen::ApiPostsResponse> & api_posts_response);
		virtual void get_posts_show(int64_t post_id, const std::shared_ptr<djinni_rest_gen::ApiPostsResponse> & api_posts_response);

		virtual bool is_post_valid(const djinni_rest_gen::PostModel & post_model);
		virtual djinni_rest_gen::PostModel modify_post(const djinni_rest_gen::PostModel & post_model);

//		virtual djinni_rest_gen::HelloModel say_hello(const std::string & welcome_title);

		virtual void get_photos_index(const std::shared_ptr<djinni_rest_gen::ApiPhotosResponse> & api_photos_response);
    	virtual void get_photos_show(int64_t photo_id, const std::shared_ptr<djinni_rest_gen::ApiPhotosResponse> & api_photos_response);
	private:
		std::shared_ptr<djinni_rest_gen::ThreadLauncher> m_thread_launcher;
		std::shared_ptr<djinni_rest_gen::Http> m_http;

		djinni_rest_gen::PostModel post_model_from_json_object(json11::Json json);
		djinni_rest_gen::PhotoModel photo_model_from_json_object(json11::Json json);
	};

}
