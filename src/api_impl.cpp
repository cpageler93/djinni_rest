#include "api_impl.hpp"

#include "async_task_impl.hpp"
#include "http_callback_impl.hpp"

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
	
	// make http request and assign callback
	auto http_callback = std::make_shared<HttpCallbackImpl>(
		[thread_launcher, api_posts_response]
		(int16_t http_code, const std::string & data)
	{
		// create background task to parse json
		auto json_parse_task = std::make_shared<AsyncTaskImpl>([http_code, data, api_posts_response](){
			
			std::cout << "handle " << std::to_string(http_code) << std::endl;
			std::cout << "Parse " << data << std::endl;
			
			auto v = std::vector<djinni_rest_gen::PostModel>();
			api_posts_response->on_index_success(v);
			
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
			
			std::cout << "handle " << std::to_string(http_code) << std::endl;
			std::cout << "Parse " << data << std::endl;
			
			auto post_model = djinni_rest_gen::PostModel(1, "title", "body");
			api_posts_response->on_show_success(post_model);
			
		});
		thread_launcher->start_thread("Parse JSON Task", json_parse_task);
	},
	[this, api_posts_response]
	()
	{
		api_posts_response->on_failure();
	});
	auto url = "http://jsonplaceholder.typicode.com/posts/" + std::to_string(post_id);
	this->m_http->send(djinni_rest_gen::HttpMethod::GET, url, http_callback);
}

