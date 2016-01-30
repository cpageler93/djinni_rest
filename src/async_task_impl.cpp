//
//  async_task_impl.cpp
//  libdjinnirest
//
//  Created by Christoph Pageler on 30.01.16.
//
//

#include "async_task_impl.hpp"

namespace djinni_rest {
	AsyncTaskImpl::AsyncTaskImpl(std::function<void()> run_me)
	:
	m_fn { std::move(run_me) }
	{ }
	
	void AsyncTaskImpl::execute() {
		m_fn();
	}
}