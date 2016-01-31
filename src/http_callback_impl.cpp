//
//  http_callback_impl.cpp
//  libdjinnirest
//
//  Created by Christoph Pageler on 30.01.16.
//
//

#include "http_callback_impl.hpp"

namespace djinni_rest {
	HttpCallbackImpl::HttpCallbackImpl(
									   std::function<void(int16_t http_code, const std::string & data)> run_on_success,
									   std::function<void()> run_on_failure
	)
	:
	m_run_on_success { std::move(run_on_success) } ,
	m_run_on_failure { std::move(run_on_failure) }
	{ }
	
	void HttpCallbackImpl::on_success(int16_t http_code, const std::string &data) {
		m_run_on_success(http_code, data);
	}
	
	void HttpCallbackImpl::on_failure() {
		m_run_on_failure();
	}
}