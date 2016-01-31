//
//  http_callback_impl.hpp
//  libdjinnirest
//
//  Created by Christoph Pageler on 30.01.16.
//
//

#ifndef http_callback_impl_hpp
#define http_callback_impl_hpp

#include <stdio.h>
#include <functional>
#include "http_callback.hpp"

namespace djinni_rest {
	class HttpCallbackImpl final : public djinni_rest_gen::HttpCallback {
	public:
		HttpCallbackImpl(
						 std::function<void(int16_t http_code, const std::string & data)> run_on_success,
						 std::function<void()> run_on_failure
						 );
		
		virtual void on_success(int16_t http_code, const std::string & data) override;
		virtual void on_failure() override;

	private:
		std::function<void(int16_t http_code, const std::string & data)> m_run_on_success;
		std::function<void()> m_run_on_failure;
	};
}
#endif /* http_callback_impl_hpp */
