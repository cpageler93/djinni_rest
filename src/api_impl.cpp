#include "api_impl.hpp"
#include "async_task_impl.hpp"
#include <iostream>

std::shared_ptr<djinni_rest_gen::Api> djinni_rest_gen::Api::create_api(
	const std::shared_ptr<djinni_rest_gen::ThreadLauncher> & launcher
) {
	return std::make_shared<djinni_rest::Api>(launcher);
}

djinni_rest::Api::Api(const std::shared_ptr<djinni_rest_gen::ThreadLauncher> & launcher) {
	this->m_thread_launcher = launcher;
}


void djinni_rest::Api::do_something(){
	
	auto task = std::make_shared<AsyncTaskImpl>([this](){
		
		std::cout << "this is from task";
		
	});
	
	this->m_thread_launcher->start_thread("C++ Thread", task);
	
}