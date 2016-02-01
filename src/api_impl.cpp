#include "api_impl.hpp"

#include "async_task_impl.hpp"
#include "http_callback_impl.hpp"
#include <json11/json11.hpp>

#include "std_util.hpp"

#include <iostream>
#include <chrono>
#include <thread>

std::shared_ptr<djinni_rest_gen::Api> djinni_rest_gen::Api::create_api(
	const std::shared_ptr<djinni_rest_gen::ThreadLauncher> & launcher,
	const std::shared_ptr<djinni_rest_gen::Http> & http
) {
	return std::make_shared<djinni_rest::Api>(launcher, http);
}

djinni_rest::Api::Api(
	const std::shared_ptr<djinni_rest_gen::ThreadLauncher> & launcher,
	const std::shared_ptr<djinni_rest_gen::Http> & http
) {
	this->m_thread_launcher = launcher;
	this->m_http = http;
}

std::shared_ptr<djinni_rest_gen::Api> djinni_rest_gen::Api::create() {
  return std::make_shared<djinni_rest::Api>(nullptr, nullptr);
}

void djinni_rest::Api::get_posts_index(
	const std::shared_ptr<djinni_rest_gen::ApiPostsResponse> & api_posts_response
) {
	// copy local attributes
	auto thread_launcher = this->m_thread_launcher;

	// make http request and assign callback
	auto http_callback = std::make_shared<HttpCallbackImpl>(
		[thread_launcher, api_posts_response]
		(int16_t http_code, const std::string & data)
	{
		// create background task to parse json
		auto json_parse_task = std::make_shared<AsyncTaskImpl>([http_code, data, api_posts_response](){


			std::string error;
			auto json_response = json11::Json::parse(data, error);
			if (!error.empty()) {
				api_posts_response->on_failure();
			} else {
				if (json_response.is_array()) {
					auto v = std::vector<djinni_rest_gen::PostModel>();
					for (const auto& item : json_response.array_items()) {
						auto p = djinni_rest_gen::PostModel(
															item["id"].number_value(),
															item["title"].string_value(),
															item["body"].string_value()
															);
						v.emplace_back(p);
					}
					api_posts_response->on_index_success(v);
				} else {
					api_posts_response->on_failure();
				}
			}

		});
		thread_launcher->start_thread("Parse JSON Task", json_parse_task);
	},
													   [this, api_posts_response]
													   ()
	{
		api_posts_response->on_failure();
	});
	this->m_http->send(djinni_rest_gen::HttpMethod::GET, "http://jsonplaceholder.typicode.com/posts", http_callback);
}

void djinni_rest::Api::get_posts_show(
	int64_t post_id,
	const std::shared_ptr<djinni_rest_gen::ApiPostsResponse> & api_posts_response
) {
	// copy local attributes
	auto thread_launcher = this->m_thread_launcher;

	// make http request and assign callback
	auto http_callback = std::make_shared<HttpCallbackImpl>(
		[thread_launcher, api_posts_response]
		(int16_t http_code, const std::string & data)
	{
		// create background task to parse json
		auto json_parse_task = std::make_shared<AsyncTaskImpl>([http_code, data, api_posts_response](){

			std::string error;
			auto json_response = json11::Json::parse(data, error);
			if (!error.empty()) {
				api_posts_response->on_failure();
			} else {
				if (json_response.is_object()) {
					auto p = djinni_rest_gen::PostModel(
														json_response["id"].number_value(),
														json_response["title"].string_value(),
														json_response["body"].string_value()
														);
					api_posts_response->on_show_success(p);
				} else {
					api_posts_response->on_failure();
				}
			}

		});
		thread_launcher->start_thread("Parse JSON Task", json_parse_task);
	},
	[this, api_posts_response]
	()
	{
		api_posts_response->on_failure();
	});
	auto url = "http://jsonplaceholder.typicode.com/posts/" + std_patch::to_string(post_id);
	this->m_http->send(djinni_rest_gen::HttpMethod::GET, url, http_callback);
}

