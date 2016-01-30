//
//  async_task_impl.hpp
//  libdjinnirest
//
//  Created by Christoph Pageler on 30.01.16.
//
//

#ifndef async_task_impl_hpp
#define async_task_impl_hpp

#include <stdio.h>
#include <functional>
#include "async_task.hpp"

namespace djinni_rest {
	class AsyncTaskImpl final : public djinni_rest_gen::AsyncTask {
	public:
		AsyncTaskImpl(std::function<void()> run_me);
		virtual void execute() override;
	private:
		std::function<void()> m_fn;
	};
}

#endif /* async_task_impl_hpp */
