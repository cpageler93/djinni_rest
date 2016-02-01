#include "api_impl.hpp"

#include "async_task_impl.hpp"
#include "http_callback_impl.hpp"

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

void djinni_rest::Api::get_posts_index(
	const std::shared_ptr<djinni_rest_gen::ApiPostsResponse> & api_posts_response
) {
	// copy local attributes
	auto thread_launcher = this->m_thread_launcher;
	auto api = this;

	// make http request and assign callback
	auto http_callback = std::make_shared<HttpCallbackImpl>(
		[api, thread_launcher, api_posts_response]
		(int16_t http_code, const std::string & data)
	{
		// create background task to parse json
		auto json_parse_task = std::make_shared<AsyncTaskImpl>([api, http_code, data, api_posts_response](){


			std::string error;
			auto json_response = json11::Json::parse(data, error);
			if (!error.empty()) {
				api_posts_response->on_failure();
			} else {
				if (json_response.is_array()) {
					auto v = std::vector<djinni_rest_gen::PostModel>();
					for (const auto& item : json_response.array_items()) {
						auto p = api->post_model_from_json_object(item);
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
	auto api = this;

	// make http request and assign callback
	auto http_callback = std::make_shared<HttpCallbackImpl>(
		[api, thread_launcher, api_posts_response]
		(int16_t http_code, const std::string & data)
	{
		// create background task to parse json
		auto json_parse_task = std::make_shared<AsyncTaskImpl>([api, http_code, data, api_posts_response](){

			std::string error;
			auto json_response = json11::Json::parse(data, error);
			if (!error.empty()) {
				api_posts_response->on_failure();
			} else {
				if (json_response.is_object()) {
					auto p = api->post_model_from_json_object(json_response);
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

djinni_rest_gen::PostModel djinni_rest::Api::post_model_from_json_object(json11::Json json)
{
	return djinni_rest_gen::PostModel(
									  json["id"].number_value(),
									  json["title"].string_value(),
									  json["body"].string_value()
									  );
}

djinni_rest_gen::PhotoModel djinni_rest::Api::photo_model_from_json_object(json11::Json json)
{
	return djinni_rest_gen::PhotoModel(
									   json["id"].number_value(),
									   json["albumId"].number_value(),
									   json["title"].string_value(),
									   json["url"].string_value(),
									   json["thumbnailUrl"].string_value()
									  );
}


void djinni_rest::Api::get_photos_index(
	const std::shared_ptr<djinni_rest_gen::ApiPhotosResponse> & api_photos_response
) {
	// copy local attributes
	auto thread_launcher = this->m_thread_launcher;
	auto api = this;

	// make http request and assign callback
	auto http_callback = std::make_shared<HttpCallbackImpl>(
		[api, thread_launcher, api_photos_response]
		(int16_t http_code, const std::string & data)
	{
		// create background task to parse json
		auto json_parse_task = std::make_shared<AsyncTaskImpl>([api, http_code, data, api_photos_response](){


			std::string error;
			auto json_response = json11::Json::parse(data, error);
			if (!error.empty()) {
				api_photos_response->on_failure();
			} else {
				if (json_response.is_array()) {
					auto v = std::vector<djinni_rest_gen::PhotoModel>();
					for (const auto& item : json_response.array_items()) {
						auto p = api->photo_model_from_json_object(item);
						v.emplace_back(p);
					}
					api_photos_response->on_index_success(v);
				} else {
					api_photos_response->on_failure();
				}
			}

		});
		thread_launcher->start_thread("Parse JSON Task", json_parse_task);
	},
													   [this, api_photos_response]
													   ()
	{
		api_photos_response->on_failure();
	});
	this->m_http->send(djinni_rest_gen::HttpMethod::GET, "http://jsonplaceholder.typicode.com/photos", http_callback);
}

void djinni_rest::Api::get_photos_show(
	int64_t photo_id,
	const std::shared_ptr<djinni_rest_gen::ApiPhotosResponse> & api_photos_response
) {
	// copy local attributes
	auto thread_launcher = this->m_thread_launcher;
	auto api = this;

	// make http request and assign callback
	auto http_callback = std::make_shared<HttpCallbackImpl>(
		[api, thread_launcher, api_photos_response]
		(int16_t http_code, const std::string & data)
	{
		// create background task to parse json
		auto json_parse_task = std::make_shared<AsyncTaskImpl>([api, http_code, data, api_photos_response](){

			std::string error;
			auto json_response = json11::Json::parse(data, error);
			if (!error.empty()) {
				api_photos_response->on_failure();
			} else {
				if (json_response.is_object()) {
					auto p = api->photo_model_from_json_object(json_response);
					api_photos_response->on_show_success(p);
				} else {
					api_photos_response->on_failure();
				}
			}

		});
		thread_launcher->start_thread("Parse JSON Task", json_parse_task);
	},
	[this, api_photos_response]
	()
	{
		api_photos_response->on_failure();
	});
	auto url = "http://jsonplaceholder.typicode.com/photos/" + std_patch::to_string(photo_id);
	this->m_http->send(djinni_rest_gen::HttpMethod::GET, url, http_callback);
}

